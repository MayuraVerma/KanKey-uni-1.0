// KanKeyDlg.h : header file
//

#if !defined(AFX_KANKEYDLG_H__36D5D73B_7F5E_4EB7_8B40_F3FD305031C6__INCLUDED_)
#define AFX_KANKEYDLG_H__36D5D73B_7F5E_4EB7_8B40_F3FD305031C6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "systemtray.h"

/////////////////////////////////////////////////////////////////////////////
// CKanKeyDlg dialog

class CKanKeyDlg : public CDialog
{
// Construction
public:
	CKanKeyDlg(CWnd* pParent = NULL);	// standard constructor
	LRESULT MyCustomCallback(WPARAM wParam, LPARAM lParam);
// Dialog Data
	//{{AFX_DATA(CKanKeyDlg)
	enum { IDD = IDD_KANKEY_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKanKeyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CKanKeyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnSetToTray();
	afx_msg void SetToTray();
	afx_msg void OnOpen() ;
		afx_msg void SetToolTip(CString);
		afx_msg LRESULT OnTrayNotify(WPARAM wParam, LPARAM lParam);
	unsigned long    static animateTrayIcon(void *d);
	
	//}}AFX_MSG
	public :
    CString		m_strStatus;
	CString ToolTip ;
	int isTraySet;
	int isEnabled;
	
	HANDLE trayIconThreadHandle;
	DWORD dwID[3];
	DWORD dwRetVal;
	
private :
	HICON		m_Icon;
	CFont fnt;
	afx_msg void OnUpdateCheck(CCmdUI*);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk3();
	afx_msg void OnEnableDisable();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KANKEYDLG_H__36D5D73B_7F5E_4EB7_8B40_F3FD305031C6__INCLUDED_)
