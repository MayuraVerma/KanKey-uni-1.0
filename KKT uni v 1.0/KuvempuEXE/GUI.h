// GUI.h : main header file for the GUI application
//

#if !defined(AFX_GUI_H__6CEF5E45_10E6_11DA_AC4B_000B6AC20131__INCLUDED_)
#define AFX_GUI_H__6CEF5E45_10E6_11DA_AC4B_000B6AC20131__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGUIApp:
// See GUI.cpp for the implementation of this class
//

class CGUIApp : public CWinApp
{
public:
	CGUIApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGUIApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGUIApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GUI_H__6CEF5E45_10E6_11DA_AC4B_000B6AC20131__INCLUDED_)
