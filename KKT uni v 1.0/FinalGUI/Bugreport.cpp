// Bugreport.cpp : implementation file
//

#include "stdafx.h"
#include "FinalGUI.h"
#include "Bugreport.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Bugreport dialog


Bugreport::Bugreport(CWnd* pParent /*=NULL*/)
	: CDialog(Bugreport::IDD, pParent)
{
	EnableAutomation();

	//{{AFX_DATA_INIT(Bugreport)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Bugreport::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CDialog::OnFinalRelease();
}

void Bugreport::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Bugreport)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Bugreport, CDialog)
	//{{AFX_MSG_MAP(Bugreport)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(Bugreport, CDialog)
	//{{AFX_DISPATCH_MAP(Bugreport)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IBugreport to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {0A879198-62C6-4040-BC31-0443A0705860}
static const IID IID_IBugreport =
{ 0xa879198, 0x62c6, 0x4040, { 0xbc, 0x31, 0x4, 0x43, 0xa0, 0x70, 0x58, 0x60 } };

BEGIN_INTERFACE_MAP(Bugreport, CDialog)
	INTERFACE_PART(Bugreport, IID_IBugreport, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Bugreport message handlers
