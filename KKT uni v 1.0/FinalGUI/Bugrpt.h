#if !defined(AFX_BUGRPT_H__B8473F21_424B_4BD1_931A_3D7670F7B19B__INCLUDED_)
#define AFX_BUGRPT_H__B8473F21_424B_4BD1_931A_3D7670F7B19B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Bugrpt.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Bugrpt dialog

class Bugrpt : public CDialog
{
// Construction
public:
	Bugrpt(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Bugrpt)
	enum { IDD = _UNKNOWN_RESOURCE_ID_ };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Bugrpt)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Bugrpt)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BUGRPT_H__B8473F21_424B_4BD1_931A_3D7670F7B19B__INCLUDED_)
