// Layout.cpp : implementation file
//

#include "stdafx.h"
#include "FinalGUI.h"
#include "Layout.h"





#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Layout dialog

static int hook = 0;
int hook_id ;
Layout::Layout(CWnd* pParent /*=NULL*/)
	: CDialog(Layout::IDD, pParent)
{
	//{{AFX_DATA_INIT(Layout)
	m_iOption = -1;
	//}}AFX_DATA_INIT
}


void Layout::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Layout)
	DDX_Radio(pDX, IDC_RADIO1, m_iOption);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Layout, CDialog)
	//{{AFX_MSG_MAP(Layout)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Layout message handlers

void Layout::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);



			   
	UpdateData(FALSE);
	
	this->ShowWindow(2);

	CDialog::OnOK();
}
