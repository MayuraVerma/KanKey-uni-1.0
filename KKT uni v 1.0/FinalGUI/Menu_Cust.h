#if !defined(AFX_MENU_CUST_H__91B9B802_E521_11DA_851F_D1449EDE0016__INCLUDED_)
#define AFX_MENU_CUST_H__91B9B802_E521_11DA_851F_D1449EDE0016__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Menu_Cust.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Menu_Cust dialog

class Menu_Cust : public CDialog
{
// Construction
public:
	Menu_Cust(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Menu_Cust)
	enum { IDD = IDD_CUST_MENU };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Menu_Cust)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Menu_Cust)
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnEditchangeCombo1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MENU_CUST_H__91B9B802_E521_11DA_851F_D1449EDE0016__INCLUDED_)
