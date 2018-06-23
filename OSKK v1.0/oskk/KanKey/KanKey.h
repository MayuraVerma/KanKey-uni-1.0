// KanKey.h : main header file for the KANKEY application
//

#if !defined(AFX_KANKEY_H__49283F41_E239_4685_AADE_6AD650C01B2C__INCLUDED_)
#define AFX_KANKEY_H__49283F41_E239_4685_AADE_6AD650C01B2C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CKanKeyApp:
// See KanKey.cpp for the implementation of this class
//

class CKanKeyApp : public CWinApp
{
public:
	CKanKeyApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKanKeyApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CKanKeyApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KANKEY_H__49283F41_E239_4685_AADE_6AD650C01B2C__INCLUDED_)
