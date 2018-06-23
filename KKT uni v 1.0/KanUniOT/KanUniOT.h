// KanUniOT.h : main header file for the KanUniOT DLL
//

#if !defined(AFX_KanUniOT_H__DF869228_FFA7_11D9_B107_0050BA32743E__INCLUDED_)
#define AFX_KanUniOT_H__DF869228_FFA7_11D9_B107_0050BA32743E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CKanUniOTApp
// See KanUniOT.cpp for the implementation of this class
//

#define EXPORTED_DLL_FUNCTION \
	__declspec(dllexport)__stdcall

LRESULT EXPORTED_DLL_FUNCTION kbdHookProc(int nCode,WPARAM wParam, LPARAM lParam);

BOOL EXPORTED_DLL_FUNCTION InstallKeyboardHook_KanUniOT ( HWND hWnd);

BOOL EXPORTED_DLL_FUNCTION DeInstallKeyboardHook_KanUniOT();

int FindCharacters(char ch);
void DisplayCharacters(int nval,int indicator,int j);
HWND GetActiveWindowHandel();

class CKanUniOTApp : public CWinApp
{
public:
	CKanUniOTApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKanUniOTApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CKanUniOTApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KanUniOT_H__DF869228_FFA7_11D9_B107_0050BA32743E__INCLUDED_)