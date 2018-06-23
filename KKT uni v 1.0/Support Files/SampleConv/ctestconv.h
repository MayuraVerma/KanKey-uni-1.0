#pragma once

#define MSODLLNAME "mso.dll"

// Need typelib for IConverter, IConverterPreferences, etc.
#import MSODLLNAME raw_interfaces_only, raw_native_types, no_namespace, named_guids, auto_rename

//Define HrCheckFormat FileFormat types
const int WORDPROCESSINGML_ECMA376_MACROFREE = 1;
const int WORDPROCESSINGML_ECMA376_MACRO = 2;
const int WORDPROCESSINGML_ISO_TRANSITIONAL_MACROFREE = 3;
const int WORDPROCESSINGML_ISO_TRANSITIONAL_MACRO = 4;
const int WORDPROCESSINGML_ISO_STRICT_MACROFREE = 5;
const int WORDPROCESSINGML_ISO_STRICT_MACRO = 6;
const int SPREADSHEETML_ECMA376_MACROFREE = 7;
const int SPREADSHEETML_ECMA376_MACRO = 8;
const int SPREADSHEETML_ISO_TRANSITIONAL_MACROFREE = 9;
const int SPREADSHEETML_ISO_TRANSITIONAL_MACRO = 10;
const int SPREADSHEETML_ISO_STRICT_MACROFREE = 11;
const int SPREADSHEETML_ISO_STRICT_MACRO = 12;
const int PRESENTATIONML_ECMA376_MACROFREE = 13;
const int PRESENTATIONML_ECMA376_MACRO = 14;
const int PRESENTATIONML_ISO_TRANSITIONAL_MACROFREE = 15;
const int PRESENTATIONML_ISO_TRANSITIONAL_MACRO = 16;
const int PRESENTATIONML_ISO_STRICT_MACROFREE = 17;
const int PRESENTATIONML_ISO_STRICT_MACRO = 18;

class CTestConv : public IConverter, public IClassFactory
{
protected:
	ULONG m_cRef;
	ULONG m_cLockServer;
	DWORD m_dwRegister;

public:
	CTestConv(void);
	~CTestConv(void);

	// IUnknown
	STDMETHOD(QueryInterface)(const IID &riid, void **ppv);
	STDMETHOD_(ULONG, AddRef)(void);
	STDMETHOD_(ULONG, Release)(void);

	// IClassFactory members
	STDMETHOD(CreateInstance)(IUnknown *punk, REFIID iid, void **ppv);
	STDMETHOD(LockServer)(BOOL fLock);

	// IConverter
	STDMETHOD(HrInitConverter)(IConverterApplicationPreferences *pcap, 
							IConverterPreferences **ppcp, 
							IConverterUICallback *pcuic);
	STDMETHOD(HrUninitConverter)(IConverterUICallback *pcuic);
	STDMETHOD(HrImport)(BSTR bstrSourcePath, 
								BSTR bstrDestPath, 
								IConverterApplicationPreferences *pcap, 
								IConverterPreferences **ppcp, 
								IConverterUICallback *pcuic);
	STDMETHOD(HrExport)(BSTR bstrSourcePath, 
								BSTR bstrDestPath, 
								BSTR bstrClass,
								IConverterApplicationPreferences *pcap, 
								IConverterPreferences **ppcp, 
								IConverterUICallback *pcuic);
	STDMETHOD(HrGetFormat)(BSTR bstrPath,
						BSTR *bstrClass,
						IConverterApplicationPreferences *pcap, 
						IConverterPreferences **ppcp, 
						IConverterUICallback *pcuic);
	STDMETHOD(HrGetErrorString)(long hrErr, 
							BSTR *pbstrErrorMsg,
							IConverterApplicationPreferences *pcap);
	
	void SetDwRegister(DWORD dwRegister);
};

HRESULT HrRegisterConverterComponent(CTestConv **pptestconv, DWORD *pdwRegister);
void UnregisterConverterComponent(CTestConv *ptestconv, DWORD dwRegister);


