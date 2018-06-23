#if !defined(AFX_LAYOUT_H__002EAF3C_601C_420F_8A9B_EF7F7448ED13__INCLUDED_)
#define AFX_LAYOUT_H__002EAF3C_601C_420F_8A9B_EF7F7448ED13__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Layout.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Layout dialog

class Layout : public CDialog
{
// Construction
public:
	Layout(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Layout)
	enum { IDD = IDD_DIALOG2 };
	int		m_iOption;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Layout)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Layout)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LAYOUT_H__002EAF3C_601C_420F_8A9B_EF7F7448ED13__INCLUDED_)
