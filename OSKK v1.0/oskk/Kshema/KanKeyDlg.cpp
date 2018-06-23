// KanKeyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "KanKey.h"
#include "KanKeyDlg.h"
#include "sinstance.h"
#include "..\KanKeyUni\KanKeyUni.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define WM_MYCUSTOMMESSAGE WM_USER+1

CSystemTray	m_TrayIcon;

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKshemaClose();
	afx_msg void OnKshemaAbout();
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_KSHEMA_CLOSE, &CAboutDlg::OnKshemaClose)
	ON_COMMAND(ID_KSHEMA_ABOUT, &CAboutDlg::OnKshemaAbout)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKanKeyDlg dialog

CKanKeyDlg::CKanKeyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CKanKeyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CKanKeyDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CKanKeyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CKanKeyDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CKanKeyDlg, CDialog)
	//{{AFX_MSG_MAP(CKanKeyDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CKanKeyDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CKanKeyDlg::OnBnClickedCancel)
	ON_MESSAGE(WM_TRAYNOTIFY, OnTrayNotify)
	ON_COMMAND(ID_KSHEMA_CLOSE, OnBnClickedCancel)
	ON_COMMAND(ID_KSHEMA_ABOUT, &CAboutDlg::OnKshemaAbout)
	ON_COMMAND(ID_MENU_ENABLE_DISABLE, OnEnableDisable)
	ON_MESSAGE(WM_MYCUSTOMMESSAGE, MyCustomCallback)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKanKeyDlg message handlers

void CKanKeyDlg::OnOpen() 
{
	::MessageBox(NULL,(LPCSTR)"Kshema is running",(LPCSTR)"Kshema is running",MB_OK);
//	isTraySet = FALSE;
		ShowWindow(SW_SHOW);
}

BOOL CKanKeyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	  CInstanceChecker instanceChecker;
  if (instanceChecker.PreviousInstanceRunning())
  {
//	AfxMessageBox(_T("Already running ,will be restored"), MB_OK);
	//  AlreadyExist Alreist;
	//  Alreist.DoModal();
    instanceChecker.ActivatePreviousInstance();

	ShowWindow(SW_SHOW);
		::MessageBox(NULL,(LPCSTR)"Kshema is running",(LPCSTR)"Kshema is running",MB_OK);
	if(isTraySet == TRUE)
		OnOpen();
	 _exit(1);
  }

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	//AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	if (!instanceChecker.PreviousInstanceRunning()){
    	
		instanceChecker.TrackFirstInstanceRunning();
	}
	isEnabled = TRUE;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CKanKeyDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CKanKeyDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CKanKeyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CKanKeyDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}

int isWinNTServer()
{
   OSVERSIONINFO osvi;
   SYSTEM_INFO si;
//   PGNSI pGNSI;
//   PGPI pGPI;
   BOOL bOsVersionInfoEx;
   DWORD dwType;

    BOOL bIsWindowsNTServer;

   ZeroMemory(&si, sizeof(SYSTEM_INFO));
   ZeroMemory(&osvi, sizeof(OSVERSIONINFO));

    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

    //GetVersionEx(&osvi);
	GetVersionEx ((OSVERSIONINFO *) &osvi);
	  // pGNSI = (PGNSI) GetProcAddress(
    //  GetModuleHandle(TEXT("kernel32.dll")), 
    //  "GetNativeSystemInfo");
   
   //if(NULL != pGNSI)
   //   pGNSI(&si);
   //else 
	   //GetSystemInfo(&si);


  //  bIsWindowsNTServer  = \
       ( (osvi.dwMajorVersion == 4) );

	switch(osvi.dwMajorVersion)
	{
		case 4:
			switch (osvi.dwMinorVersion)
			{
				case 0:
					if( osvi.dwBuildNumber == 1381)
						bIsWindowsNTServer = TRUE;
					else
						bIsWindowsNTServer = FALSE;
				break;
				case 1:
					bIsWindowsNTServer = FALSE;
				break;
				case 2:
					bIsWindowsNTServer = FALSE;
				break;
				default:
				bIsWindowsNTServer = FALSE;
			}
		break;

		case 5:
			switch (osvi.dwMinorVersion)
			{
				case 1:
					bIsWindowsNTServer = FALSE;
				break;
				case 2:
				//	if(  //(OSVERSIONINFOEX.wSuiteMask & VER_SUITE_WH_SERVER) || 
						// ( (OSVERSIONINFOEX.wProductType == VER_NT_WORKSTATION) && (SYSTEM_INFO.wProcessorArchitecture==PROCESSOR_ARCHITECTURE_AMD64)
//						 )
				//	  )
				//		  bIsWindowsNTServer = FALSE;
				//	else
				//		  bIsWindowsNTServer = TRUE;
					if( osvi.dwBuildNumber == 3790)
						bIsWindowsNTServer = TRUE;
					else
						bIsWindowsNTServer = FALSE;
				break;
				default:
					bIsWindowsNTServer = FALSE;
			}
		break;
	    case 6:
//			if(OSVERSIONINFOEX.wProductType == 5) //(OSVERSIONINFOEX.wProductType != VER_NT_WORKSTATION)
		//	{
		//		bIsWindowsNTServer = TRUE;
		//	}
		 //   else
		//	{
				bIsWindowsNTServer = FALSE;
		//	}
		default:
			bIsWindowsNTServer = FALSE;
		break;

	}
	//	AfxMessageBox("ffdvdfvv2",1);


    if(bIsWindowsNTServer)
	{
	//	ALLOWDUPLICATE = FALSE;
        return TRUE;
	}

	return FALSE;

}

void CKanKeyDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	isTraySet = FALSE;
	InitKeyboardKanKeyUni(GetSafeHwnd());
	//OnOK();
		if(!isWinNTServer())
				{
					this->ShowWindow(SW_HIDE);
					SetToTray();
					SetToolTip("KanKey Kannada Unicode Keyboard - Enabled");
				}
}

void CKanKeyDlg::SetToTray()
{
	if(isTraySet == FALSE)
	if(m_TrayIcon.Create(this,                             // Parent window
                           WM_TRAYNOTIFY,                   // Icon notify message to use
                           m_strStatus,						// tooltip
                           m_Icon,							// Icon to use
                           IDR_MENU1))                 // ID of tray icon
	{
		isTraySet = TRUE;
	}
//	else
//		isTraySet = TRUE;

	m_TrayIcon.SetIcon(IDR_MAINFRAME);//m_TrayIcon.SetIcon(IDI_ICON2);
	SetToolTip("KanKey Kannada Unicode Keyboard - Enabled");
}

void CKanKeyDlg::SetToolTip(CString toolTip)
{
		m_TrayIcon.SetTooltipText(toolTip);
}

void CAboutDlg::OnKshemaClose()
{
	// TODO: Add your command handler code here
		CDialog::OnCancel();

}


void CKanKeyDlg::OnBnClickedCancel()
{
	if(!isWinNTServer())
		CloseHandle(trayIconThreadHandle);
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}


void CAboutDlg::OnKshemaAbout()
{
	 CAboutDlg AbtDlg;
	 AbtDlg.DoModal(); 
	// TODO: Add your command handler code here
}
void CKanKeyDlg::OnEnableDisable()
{
	if(isEnabled == TRUE)
	{
		isEnabled = FALSE;
		StopKeyboardKanKeyUni();
		SetToolTip("Kshema Kannada Unicode Keyboard - Disabled");
	}else{
				isEnabled = TRUE;
		InitKeyboardKanKeyUni(GetSafeHwnd());
		SetToolTip("Kshema Kannada Unicode Keyboard - Enabled");
	}
}
LRESULT CKanKeyDlg :: OnTrayNotify(WPARAM wParam, LPARAM lParam)
{
	return m_TrayIcon.OnTrayNotification(wParam, lParam);
	
}

LRESULT CKanKeyDlg::MyCustomCallback(WPARAM wParam, LPARAM lParam)
{
	if(wParam == 0x0EE)
	{
		SetToolTip("Kshema Kannada Unicode Keyboard - Disabled");
	}else if(wParam == 0x0EF){
		SetToolTip("Kshema Kannada Unicode Keyboard - Enabled");
	}

    // Do something clever here
    return 0; // Make sure to return some value
}
