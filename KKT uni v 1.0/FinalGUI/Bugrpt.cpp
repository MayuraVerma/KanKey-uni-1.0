// Bugrpt.cpp : implementation file
//

#include "stdafx.h"
#include "FinalGUI.h"
#include "Bugrpt.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Bugrpt dialog


Bugrpt::Bugrpt(CWnd* pParent /*=NULL*/)
	: CDialog(Bugrpt::IDD, pParent)
{
	//{{AFX_DATA_INIT(Bugrpt)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Bugrpt::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Bugrpt)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Bugrpt, CDialog)
	//{{AFX_MSG_MAP(Bugrpt)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Bugrpt message handlers
