// Menu_Cust.cpp : implementation file
//

#include "stdafx.h"
#include "FinalGUI.h"
#include "Menu_Cust.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Menu_Cust dialog


Menu_Cust::Menu_Cust(CWnd* pParent /*=NULL*/)
	: CDialog(Menu_Cust::IDD, pParent)
{
	//{{AFX_DATA_INIT(Menu_Cust)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Menu_Cust::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Menu_Cust)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Menu_Cust, CDialog)
	//{{AFX_MSG_MAP(Menu_Cust)
	ON_CBN_EDITCHANGE(IDC_COMBO1, OnEditchangeCombo1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Menu_Cust message handlers

void Menu_Cust::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}

void Menu_Cust::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}


void Menu_Cust::OnEditchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	
}
