// About.cpp : implementation file
//

#include "stdafx.h"
#include "FinalGUI.h"
#include "About.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// About dialog


About::About(CWnd* pParent /*=NULL*/)
	: CDialog(About::IDD, pParent)
{
	//{{AFX_DATA_INIT(About)
	//}}AFX_DATA_INIT

   


}


void About::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(About)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(About, CDialog)
	//{{AFX_MSG_MAP(About)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// About message handlers
