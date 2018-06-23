#if !defined(AFX_BUGRPT1_H__D74B33D1_3614_4CA8_866B_0921221EE77D__INCLUDED_)
#define AFX_BUGRPT1_H__D74B33D1_3614_4CA8_866B_0921221EE77D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Bugrpt1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Bugrpt1 dialog

class Bugrpt1 : public CDialog
{
// Construction
public:
	Bugrpt1(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Bugrpt1)
	enum { IDD = _UNKNOWN_RESOURCE_ID_ };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Bugrpt1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Bugrpt1)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BUGRPT1_H__D74B33D1_3614_4CA8_866B_0921221EE77D__INCLUDED_)
