#pragma once

class CConvPrefs : public IConverterPreferences
{
protected:
	ULONG m_cRef;

public:
	CConvPrefs(void);
	~CConvPrefs(void);

	// IUnknown
	STDMETHOD(QueryInterface)(const IID &riid, void **ppv);
	STDMETHOD_(ULONG, AddRef)(void);
	STDMETHOD_(ULONG, Release)(void);
	
	// IConverterPreferences
	STDMETHOD(HrGetMacroEnabled)(int *pfMacroEnabled);
	STDMETHOD(HrCheckFormat)(int *pformat);
	STDMETHOD(HrGetLossySave)(int *pfLossySave);
};

