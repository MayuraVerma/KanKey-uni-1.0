// Language.cpp : implementation file
//

#include "stdafx.h"
#include "FinalGUI.h"
#include "Language.h"
#include "Menu_Cust.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Language dialog


Language::Language(CWnd* pParent /*=NULL*/)
	: CDialog(Language::IDD, pParent)
{
	//{{AFX_DATA_INIT(Language)
	m_Opt = -1;
	//}}AFX_DATA_INIT
}


void Language::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Language)
	DDX_Radio(pDX, IDC_RADIO1, m_Opt);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Language, CDialog)
	//{{AFX_MSG_MAP(Language)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Language message handlers

void Language::OnRadio1() 
{

	
    BYTE byKeybState[256];
	UINT nVirtKey=0;
    ::GetKeyboardState(byKeybState);         
    byKeybState[nVirtKey] = !(BOOL)::GetKeyState(VK_SCROLL);
    ::SetKeyboardState(byKeybState);
//

	/*
	BYTE CKeyBuf[256];
 
	GetKeyboardState(CKeyBuf);
	  if((CKeyBuf[VK_SCROLL] & 0x01) == 1)
	  {
		   
	  }
	  else
	  {
		 CKeyBuf[VK_SCROLL]=0x81;
		 SetKeyboardState(CKeyBuf);
	  }
 */
	// TODO: Add your control notification handler code here
	
}

void Language::OnRadio2() 
{
	// TODO: Add your control notification handler code here

 //BYTE byKeybState[256];
 //UINT nVirtKey=0;

    //::GetKeyboardState(byKeybState);         
    //byKeybState[nVirtKey] = !(BOOL)::GetKeyState(VK_SCROLL);
   // ::SetKeyboardState(byKeybState);
	Menu_Cust CustMenu;
	CustMenu.DoModal();


/*
		BYTE CKeyBuf[256];
 
	GetKeyboardState(CKeyBuf);
	  if((CKeyBuf[VK_SCROLL] & 0x01) ==0 )
	  {
			CKeyBuf[VK_SCROLL]=0x80;
			SetKeyboardState(CKeyBuf);
	  }
	  else
	  {

	  }
*/
	
}

void Language::OnOK() 
{
	// TODO: Add extra validation here
	
	UpdateData(TRUE);
	if(m_Opt == 0) 
	{
	
	   

	}
	if(m_Opt == 1) 
	{
	
	   

	}

	UpdateData(FALSE);

	CDialog::OnOK();
}
