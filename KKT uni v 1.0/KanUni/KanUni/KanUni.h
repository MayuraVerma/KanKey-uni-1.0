// KanUni.h : main header file for the KanUni DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


#define EXPORTED_DLL_FUNCTION \
	__declspec(dllexport)__stdcall

LRESULT EXPORTED_DLL_FUNCTION kbdHookProc(int nCode,WPARAM wParam, LPARAM lParam);

BOOL EXPORTED_DLL_FUNCTION InstallKeyboardHook_KanUni (HWND hWnd);

BOOL EXPORTED_DLL_FUNCTION DeInstallKeyboardHook_KanUni();


// CKanUniApp
// See KanUni.cpp for the implementation of this class
//

void DisplayQueue();
void SendSpace(int);
void ClearQueue();
HWND GetActiveWindowHandel();

void DisplayCharacters(int nval,int v_bit,int j) ;

int  FindCharacters (char ch) ;


void ClearOne();

class CKanUniApp : public CWinApp
{
public:
	CKanUniApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
