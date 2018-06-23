// KanKeyUni.h : main header file for the KanKeyUni DLL
//

#if !defined(AFX_KanKeyUni_H__DF869228_FFA7_11D9_B107_0050SUDHEER316__INCLUDED_)
#define AFX_KanKeyUni_H__DF869228_FFA7_11D9_B107_0050SUDHEER316__INCLUDED_



#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CKanKeyUniApp
// See KanKeyUni.cpp for the implementation of this class
//

#define EXPORTED_DLL_FUNCTION \
	__declspec(dllexport)__stdcall

LRESULT EXPORTED_DLL_FUNCTION RunKeyboardKanKeyUni(int nCode,WPARAM wParam, LPARAM lParam);

BOOL EXPORTED_DLL_FUNCTION InitKeyboardKanKeyUni(HWND hWnd);

BOOL EXPORTED_DLL_FUNCTION StopKeyboardKanKeyUni();

HMODULE LoadUnicowsProc(void);

class CKanKeyUniApp : public CWinApp
{
public:
	CKanKeyUniApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKanKeyUniApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CKanKeyUniApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

void copyPrevious(char ch);
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KanKeyUni_H__DF869228_FFA7_11D9_B107_0050BA32743E__INCLUDED_)