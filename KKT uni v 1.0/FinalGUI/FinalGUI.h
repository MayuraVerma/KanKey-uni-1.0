// FinalGUI.h : main header file for the FINALGUI application
//

#if !defined(AFX_FINALGUI_H__8162FF69_07B5_430C_8E69_4747AD92A4A9__INCLUDED_)
#define AFX_FINALGUI_H__8162FF69_07B5_430C_8E69_4747AD92A4A9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFinalGUIApp:
// See FinalGUI.cpp for the implementation of this class
//

class CFinalGUIApp : public CWinApp
{
public:
	CFinalGUIApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFinalGUIApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFinalGUIApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FINALGUI_H__8162FF69_07B5_430C_8E69_4747AD92A4A9__INCLUDED_)
