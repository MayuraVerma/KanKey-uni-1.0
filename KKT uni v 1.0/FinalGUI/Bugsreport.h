#if !defined(AFX_BUGSREPORT_H__A6DFFF0E_FD8A_488D_8449_52183B4C00D3__INCLUDED_)
#define AFX_BUGSREPORT_H__A6DFFF0E_FD8A_488D_8449_52183B4C00D3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Bugsreport.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Bugsreport dialog

class Bugsreport : public CDialog
{
// Construction
public:
	Bugsreport(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Bugsreport)
	enum { IDD = IDD_DIALOG5 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Bugsreport)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Bugsreport)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BUGSREPORT_H__A6DFFF0E_FD8A_488D_8449_52183B4C00D3__INCLUDED_)
