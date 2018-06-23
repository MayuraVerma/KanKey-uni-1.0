// Bugrpt1.cpp : implementation file
//

#include "stdafx.h"
#include "FinalGUI.h"
#include "Bugrpt1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Bugrpt1 dialog


Bugrpt1::Bugrpt1(CWnd* pParent /*=NULL*/)
	: CDialog(Bugrpt1::IDD, pParent)
{
	//{{AFX_DATA_INIT(Bugrpt1)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Bugrpt1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Bugrpt1)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Bugrpt1, CDialog)
	//{{AFX_MSG_MAP(Bugrpt1)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Bugrpt1 message handlers
