// Bugsreport.cpp : implementation file
//

#include "stdafx.h"
#include "FinalGUI.h"
#include "Bugsreport.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Bugsreport dialog


Bugsreport::Bugsreport(CWnd* pParent /*=NULL*/)
	: CDialog(Bugsreport::IDD, pParent)
{
	//{{AFX_DATA_INIT(Bugsreport)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Bugsreport::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Bugsreport)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Bugsreport, CDialog)
	//{{AFX_MSG_MAP(Bugsreport)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Bugsreport message handlers
