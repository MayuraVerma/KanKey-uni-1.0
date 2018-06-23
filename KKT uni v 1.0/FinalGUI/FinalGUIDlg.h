// FinalGUIDlg.h : header file
//

#if !defined(AFX_FINALGUIDLG_H__8401EA40_C68D_4943_8504_6C0A57452AE1__INCLUDED_)
#define AFX_FINALGUIDLG_H__8401EA40_C68D_4943_8504_6C0A57452AE1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFinalGUIDlg dialog
#define WM_TRAY_ICON_NOTIFY_MESSAGE (WM_USER + 1)


class CFinalGUIDlg : public CDialog
{
	private:
	BOOL m_bMinimizeToTray;

	BOOL			m_bTrayIconVisible;
	NOTIFYICONDATA	m_nidIconData;
	CMenu			m_mnuTrayMenu;
	UINT			m_nDefaultMenuItem;
// Construction
	public:
	void TraySetMinimizeToTray(BOOL bMinimizeToTray = TRUE);
	BOOL TraySetMenu(UINT nResourceID,UINT nDefaultPos=0);	
	BOOL TraySetMenu(HMENU hMenu,UINT nDefaultPos=0);	
	BOOL TraySetMenu(LPCTSTR lpszMenuName,UINT nDefaultPos=0);	
	BOOL TrayUpdate();
	BOOL TrayShow();
	BOOL TrayHide();
	void TraySetToolTip(LPCTSTR lpszToolTip);
	void TraySetIcon(HICON hIcon);
	void TraySetIcon(UINT nResourceID);
	void TraySetIcon(LPCTSTR lpszResourceName);

	BOOL TrayIsVisible();
	CFinalGUIDlg(UINT uIDD,CWnd* pParent = NULL);   // standard constructor
	
	 void OnTrayLButtonDown(CPoint pt);
	 void OnTrayLButtonDblClk(CPoint pt);
	 void OnTrayRButtonDown(CPoint pt);
	 void OnTrayRButtonDblClk(CPoint pt);
	 void OnTrayMouseMove(CPoint pt);

	CFinalGUIDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFinalGUIDlg)
	enum { IDD = IDD_FINALGUI_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFinalGUIDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFinalGUIDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnTraymenuItem1();
	afx_msg void OnTraymenuItem2();
	afx_msg void OnTraymenuItem3();
	private:
	afx_msg void OnTrayNotify(WPARAM wParam, LPARAM lParam);
	//}}AFX_MSG
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FINALGUIDLG_H__8401EA40_C68D_4943_8504_6C0A57452AE1__INCLUDED_)
