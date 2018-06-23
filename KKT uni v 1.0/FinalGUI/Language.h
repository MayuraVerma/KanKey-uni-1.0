#if !defined(AFX_LANGUAGE_H__2C3A6F68_B0D9_4B8E_8FDE_9FED37362CCE__INCLUDED_)
#define AFX_LANGUAGE_H__2C3A6F68_B0D9_4B8E_8FDE_9FED37362CCE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Language.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Language dialog

class Language : public CDialog
{
// Construction
public:
	Language(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Language)
	enum { IDD = IDD_DIALOG1 };
	int		m_Opt;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Language)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Language)
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LANGUAGE_H__2C3A6F68_B0D9_4B8E_8FDE_9FED37362CCE__INCLUDED_)
