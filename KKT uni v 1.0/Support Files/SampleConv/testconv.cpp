#include "CTestConv.h"
#include "CConvPrefs.h"
#include "_string.h"
#include "initguid.h"

int cInstances = 0;
WCHAR wzTalkingTo[1024];

const WCHAR *wzConverterClass = L"TestConv";
// {FB9502AC-5DA4-4756-BF67-1C4086B70C62}
DEFINE_GUID(CLSID_CTestConv,   0xFB9502AC, 0x5DA4, 0x4756, 0xBF, 0x67, 0x1C, 0x40, 0x86, 0xB7, 0x0C, 0x62);


CTestConv::CTestConv(void)
{
	m_cRef = 1;
	m_cLockServer = 0;
}


CTestConv::~CTestConv(void)
{
}


STDMETHODIMP CTestConv::QueryInterface(const IID &riid, void **ppv)
{
	HRESULT hr = E_NOINTERFACE;
	
	*ppv = NULL;

	if (riid == IID_IUnknown)
		*ppv = static_cast<IUnknown *>(static_cast<IConverter *>(this));
	else if ((riid == IID_IClassFactory))
		*ppv = static_cast<IClassFactory *>(this);
	else if ((riid == IID_IConverter))
		*ppv = static_cast<IConverter *>(this);

	if (*ppv != NULL)
		{
		this->AddRef();
		hr = NOERROR;
		}

	return hr;
}


STDMETHODIMP_(ULONG) CTestConv::AddRef(void)
{
	m_cRef++;

	return m_cRef;
}


STDMETHODIMP_(ULONG) CTestConv::Release(void)
{
	ULONG cRef;
	
	cRef = --m_cRef;
	if (cRef == 0)
		{
		if (m_cLockServer == 0 && (--cInstances < 1))
			{
			// Our server is designed to never allow more than one interface
			// pointer at a time.
			PostQuitMessage(0);
			}

		delete this;
		}
	
	return cRef;
}


STDMETHODIMP CTestConv::CreateInstance(IUnknown *punk, REFIID iid, void **ppv)
{
	HRESULT hr;
	CTestConv *ptestconv;

	if (++cInstances > 1)
		return E_FAIL;

	hr = E_OUTOFMEMORY;
	ptestconv = new CTestConv();
	if (ptestconv != NULL)
		{
		hr = ptestconv->QueryInterface(iid, ppv);
		ptestconv->Release();
		}

	return hr;
}


STDMETHODIMP CTestConv::LockServer(BOOL fLock)
{
	if (fLock)
		m_cLockServer++;
	else
		m_cLockServer--;
	
	return(NOERROR);
}


void CTestConv::SetDwRegister(DWORD dwRegister)
{
	m_dwRegister = dwRegister;
}


STDMETHODIMP CTestConv::HrInitConverter(IConverterApplicationPreferences *pcap, 
								IConverterPreferences **ppcp, 
								IConverterUICallback *pcuic)
{
	BSTR bstrApplication = NULL;

	pcap->HrGetApplication(&bstrApplication);
	CopyBstrToWz(bstrApplication, wzTalkingTo, cElements(wzTalkingTo));

	*ppcp = new CConvPrefs();
			
	return S_OK;
}


STDMETHODIMP CTestConv::HrUninitConverter(IConverterUICallback *pcuic)
{
	return S_OK;
}


/*----------------------------------------------------------------------------
	Function: HrImport
		This function will copy the file recieved from the application into the destination location
		so the Open operation can continue.
		
	Parameters:
	[in]   BSTR bstrSourcePath - Location of file on the disk 
	[in]   BSTR bstrDestPath - Location where the application would like the translated file 
	[in]   IConverterApplicationPreferences *pcap - Preferences from the host application 
	[out] IConverterPreferences **ppcp - Pointer to Converter Preference to be set by function
 	[in]   IConverterUICallback *pcuic - Pointer to all UI callback functions

 	RETURN:
 	S_OK - For Success
 	E_FAIL (or Custom Failure) - For Failures
----------------------------------------------------------------------------*/
STDMETHODIMP CTestConv::HrImport(BSTR bstrSourcePath, 
									BSTR bstrDestPath, 
									IConverterApplicationPreferences *pcap, 
									IConverterPreferences **ppcp, 
									IConverterUICallback *pcuic)
{
	WCHAR wzSourcePath[1024];
	WCHAR wzDestPath[1024];

	*ppcp = new CConvPrefs();

	CopyBstrToWz(bstrSourcePath, wzSourcePath, cElements(wzSourcePath));
	CopyBstrToWz(bstrDestPath, wzDestPath, cElements(wzDestPath));

	return CopyFileW(wzSourcePath, wzDestPath, false) ? S_OK : E_FAIL;
}


/*----------------------------------------------------------------------------
	Function: HrExport
		This function will copy the file recieved from the application into the destination location
		so the Save operation can continue.

	Parameters:
	[in]   BSTR bstrSourcePath - Location of file from the application to be translated 
	[in]   BSTR bstrDestPath - Location where the application would like the translated file so it can save to the disk 
	[in]   IConverterApplicationPreferences *pcap - Preferences from the host application 
	[out] IConverterPreferences **ppcp - Pointer to Converter Preference to be set by function
 	[in]   IConverterUICallback *pcuic - Pointer to all UI callback functions

 	RETURN:
 	S_OK - For Success
 	E_FAIL (or Custom Failure) - For Failures	
----------------------------------------------------------------------------*/
STDMETHODIMP CTestConv::HrExport(BSTR bstrSourcePath, 
									BSTR bstrDestPath, 
									BSTR bstrClass,
									IConverterApplicationPreferences *pcap, 
									IConverterPreferences **ppcp, 
									IConverterUICallback *pcuic)
{
	WCHAR wzSourcePath[1024];
	WCHAR wzDestPath[1024];
	WCHAR wzClass[1024];

	*ppcp = new CConvPrefs();

	CopyBstrToWz(bstrClass, wzClass, cElements(wzClass));
	if (!FEqWz(wzClass, wzConverterClass))
		return E_FAIL;

	CopyBstrToWz(bstrSourcePath, wzSourcePath, cElements(wzSourcePath));
	CopyBstrToWz(bstrDestPath, wzDestPath, cElements(wzDestPath));

	return CopyFileW(wzSourcePath, wzDestPath, false) ? S_OK : E_FAIL;
}


/*----------------------------------------------------------------------------
	Function: HrGetFormat
		This function allows the converter to tell the application whether or not it can open the 
		incoming file
		
	Parameters:
	[in]   BSTR bstrPath - Location of file from the application to be translated 
	[out] BSTR pbstrClass - Pointer to the Class name of the converter that this function can set
	[in]   IConverterApplicationPreferences *pcap - Preferences from the host application 
	[out] IConverterPreferences **ppcp - Pointer to Converter Preference to be set by function
 	[in]   IConverterUICallback *pcuic - Pointer to all UI callback functions

 	RETURN:
 	S_OK - For Success
 	E_FAIL (or Custom Failure) - For Failures	
----------------------------------------------------------------------------*/
STDMETHODIMP CTestConv::HrGetFormat(BSTR bstrPath,
								BSTR *pbstrClass,
								IConverterApplicationPreferences *pcap, 
								IConverterPreferences **ppcp, 
								IConverterUICallback *pcuic)
{
	*ppcp = new CConvPrefs();

	*pbstrClass = SysAllocString(wzConverterClass);
	
	return S_OK;
}


/*----------------------------------------------------------------------------
	Function: HrGetErrorString

	Parameters:
	[in]   long hrErr - Is the error code that incurred while accessing the converter
	[out] BSTR pbstrErrorMsg - Pointer to the custom error message that can be set by the converter
	[in]   IConverterApplicationPreferences *pcap - Preferences from the host application 

 	RETURN:
 	S_OK - For Success
 	E_FAIL (or Custom Failure) - For Failures	
----------------------------------------------------------------------------*/
STDMETHODIMP CTestConv::HrGetErrorString(long hrErr, 
									BSTR *pbstrErrorMsg,
									IConverterApplicationPreferences *pcap)
{
	DWORD lcid;
	WCHAR wzErrorMsg[1024];

	if (SUCCEEDED(hrErr))
		return E_FAIL;
	
	if (pcap == NULL || FAILED(pcap->HrGetLcid(&lcid)))
		lcid = 0;
	IToW(lcid, wzErrorMsg, cElements(wzErrorMsg));
	
	switch (hrErr)
		{
	case E_HANDLE:
		AppendWz(L": E_HANDLE", wzErrorMsg, cElements(wzErrorMsg));
		break;
	case E_ACCESSDENIED:
		AppendWz(L": E_ACCESSDENIED", wzErrorMsg, cElements(wzErrorMsg));
		break;
	case E_INVALIDARG:
		AppendWz(L": E_INVALIDARG", wzErrorMsg, cElements(wzErrorMsg));
		break;
	default:
		return E_NOTIMPL;
		}

	*pbstrErrorMsg = SysAllocString(wzErrorMsg);
	if (*pbstrErrorMsg == NULL)
		return E_OUTOFMEMORY;

	return S_OK;
}


CConvPrefs::CConvPrefs(void)
{
	m_cRef = 1;
}


CConvPrefs::~CConvPrefs(void)
{
}


STDMETHODIMP CConvPrefs::QueryInterface(const IID &riid, void **ppv)
{
	HRESULT hr = E_NOINTERFACE;
	
	*ppv = NULL;

	if ((riid == IID_IConverterPreferences) || (riid == IID_IUnknown))
		*ppv = static_cast<IConverterPreferences *>(this);

	if (*ppv != NULL)
		{
		this->AddRef();
		hr = NOERROR;
		}

	return(hr);
}


STDMETHODIMP_(ULONG) CConvPrefs::AddRef(void)
{
	m_cRef++;

	return(m_cRef);
}


STDMETHODIMP_(ULONG) CConvPrefs::Release(void)
{
	ULONG cRef;
	
	cRef = --m_cRef;
	if (cRef == 0)
		delete this;
	
	return(cRef);
}


STDMETHODIMP CConvPrefs::HrGetMacroEnabled(int *pfMacroEnabled)
{
	// Set to 1 for MacroEnabled
	*pfMacroEnabled = 0;
	
	return S_OK;
}

/*----------------------------------------------------------------------------
	Function: HrCheckFormat

	Parameters:
	[out] int *pformat - The Format of the incoming document
----------------------------------------------------------------------------*/
STDMETHODIMP CConvPrefs::HrCheckFormat(int *pformat)
{
	int fMacroEnabled = 0;
	HrGetMacroEnabled(&fMacroEnabled);

	if (!fMacroEnabled)
		{
		if (FEqWz(wzTalkingTo, L"Microsoft Office Word"))
			*pformat = WORDPROCESSINGML_ECMA376_MACROFREE;
		else if (FEqWz(wzTalkingTo, L"Microsoft Office Excel"))
			*pformat = SPREADSHEETML_ECMA376_MACROFREE;
		else if (FEqWz(wzTalkingTo, L"Microsoft Office PowerPoint"))
			*pformat = PRESENTATIONML_ECMA376_MACROFREE;
		}
	else
		{
		if (FEqWz(wzTalkingTo, L"Microsoft Office Word"))
			*pformat = WORDPROCESSINGML_ECMA376_MACRO;
		else if (FEqWz(wzTalkingTo, L"Microsoft Office Excel"))
			*pformat = SPREADSHEETML_ECMA376_MACRO;
		else if (FEqWz(wzTalkingTo, L"Microsoft Office PowerPoint"))
			*pformat = PRESENTATIONML_ECMA376_MACRO;
		}
	
	return S_OK;
}


STDMETHODIMP CConvPrefs::HrGetLossySave(int *pfLossySave)
{
	*pfLossySave = 0;

	return S_OK;
}


HRESULT HrRegisterConverterComponent(CTestConv **pptestconv, DWORD *pdwRegister)
{
	HRESULT hr;
	CTestConv *ptestconv;
	IUnknown *punk;
	DWORD dwRegister;

	hr = CoInitialize(NULL);
	ptestconv = NULL;
	dwRegister = 0;

	if (SUCCEEDED(hr))
		{
		hr = E_OUTOFMEMORY;
		ptestconv = new CTestConv();
		if (ptestconv != NULL)
			{
			hr = ptestconv->QueryInterface(IID_IUnknown, (void **)&punk);
			if (SUCCEEDED(hr))
				{
				hr = CoRegisterClassObject(CLSID_CTestConv, punk, CLSCTX_LOCAL_SERVER, REGCLS_SINGLEUSE, &dwRegister);
				if (FAILED(hr))
					{
					ptestconv->Release();
					ptestconv = NULL;
					dwRegister = 0;
					}
				else
					{
					ptestconv->SetDwRegister(dwRegister);
					}
				}
			else
				{
				delete ptestconv;
				ptestconv = NULL;
				}
			}
		}

	*pptestconv = ptestconv;
	*pdwRegister = dwRegister;

	return hr;
}


void UnregisterConverterComponent(CTestConv *ptestconv, DWORD dwRegister)
{
	if (dwRegister != 0)
		CoRevokeClassObject(dwRegister);

	if (ptestconv != NULL)
		ptestconv->Release();

	CoUninitialize();
}


bool ConvMainLoop(int fEmbedding)
{
	HRESULT hr = E_FAIL;
	MSG msg;
	BOOL fRes;

	// The converter is only operational when run through COM (i.e. Application calls CoCreateInstance).
	// The converter is useless if the user double-clicks on the converter exe in Windows Explorer.
	// The "-embedding" command line argument should be present when the converter is invoked via COM.
	if (fEmbedding)
		{
		CTestConv *ptestconv = NULL;
		DWORD dwRegister = 0;

		// Register the Converter interface with the system.
		hr = HrRegisterConverterComponent(&ptestconv, &dwRegister);

		if (SUCCEEDED(hr))
			{
			while((fRes = GetMessage(&msg, NULL, 0, 0)) != 0)
				{ 
				if (fRes != -1)
					{
					TranslateMessage(&msg); 
					DispatchMessage(&msg); 
					}
				}
			}

		UnregisterConverterComponent(ptestconv, dwRegister);
		}

	return SUCCEEDED(hr) ? 0 : 1;
}


bool FEmbeddingCommandLine(const WCHAR *wzCommandLine)
{
	WCHAR *pwch = wzCommandLine;

	while (*pwch)
		{
		if (*pwch == '-' || *pwch == '/')
			{
			switch (*++pwch)
				{
			default:
				break;

			case 'e':
			case 'E':
				// Catch arguments such as "embed" or "EMBEDDING".
				return true;
				}
			}
		else
			{
			pwch++;
			}
		}
}


int CALLBACK WinMain(HINSTANCE hInstance,
					HINSTANCE hPrevInstance,
					LPSTR lpszCommandLine,
					int cmdShow)
{
	return ConvMainLoop(FEmbeddingCommandLine((WCHAR *)GetCommandLineW()));
}
