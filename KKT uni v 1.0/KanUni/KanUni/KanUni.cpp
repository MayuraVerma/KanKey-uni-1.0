// KanUni.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "KanUni.h"
#include <vector>
#include <windows.h>
#include "..\flags.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;
//
//TODO: If this DLL is dynamically linked against the MFC DLLs,
//		any functions exported from this DLL which call into
//		MFC must have the AFX_MANAGE_STATE macro added at the
//		very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

#define KAN_KEYBOARD_LAYOUT _T("0000044B")
#define US_KEYBOARD_LAYOUT _T("00000409")

#define ANUSWARA 0
#define VOWELS 1
#define CONSONANTS 2


#pragma data_seg(".SHARDAT")
static HWND ghWndMain = 0 ;
static HHOOK ghKeyHook = NULL ;
#pragma data_seg()

static HHOOK ghCallWndProcRetHook = NULL;


HINSTANCE ghInstance=0;
HOOKPROC glpfnHookProc=0;
    SHORT scanCode;
	WPARAM lParam1;
HWND      myWnd;

// CKanUniApp

BEGIN_MESSAGE_MAP(CKanUniApp, CWinApp)
END_MESSAGE_MAP()


// CKanUniApp construction

CKanUniApp::CKanUniApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CKanUniApp object

CKanUniApp theApp;


// CKanUniApp initialization

BOOL CKanUniApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

//---Structure of anuswara and visarga----//
struct anv_tab
{
	char key;								//----holds the character 
	int k_val[2];							//---holds the glyph codes of the corresponding above character eg; 
											//---for a 67 (first 3 values)for vowel and 192 for consonants (last value)
}anuswaranvisarga[3] = { 
	                     'M' , {0xC82,-1} ,
						 'H' , {0xC83,-1} ,
						 'F',  {0xD0F,-1}
};

//---Structure of vowles ----//
struct val_tab
{
	char key;								//----holds the character 
	int k_val[4];							//---holds the glyph codes of the corresponding above character eg;  
											//---for a 67 (first 3 values)for vowel and 192 for consonants (last value)
}vowels[16] =   {		'a' , {0xC85,-1} ,
						'A' , {0xC86,-1,0xCBE,-1} ,
						'i' , {0xC87,-1,0xCBF,-1} ,
						'I' , {0xC88,-1,0xCC0,-1} ,
						'u' , {0xC89,-1,3265,-1} ,
						'U' , {0xC8A,-1,0xCC2,-1} ,
						'R' , {0xC8B,-1,0xCC3,-1} ,
						'e' , {0xC8E,-1,0xCC6,-1} ,
						'E' , {0xC8F,-1,0xCC7,-1} ,
						'Y' , {0xC90,-1,0xCC8,-1} ,
						'o' , {0xC92,-1,0xCCA,-1} ,
						'O' , {0xC93,-1,0xCCB,-1} ,
						'V' , {0xC94,-1,0xCCC,-1} ,

				
				
};


//---Structure of consonants ----//
struct con_tab
{
	char key;								//----holds the character 
	int k_val[2];							//---holds the glyph codes of the corresponding above character eg; 
										   //---- for a 67 (first 3 values)for vowel and 192 for consonants (last value)
}consonants[35] = { 'k' , {0xC95,-1} ,
					'K' , {0xC96,-1} ,
					'g' , {0xC97,-1} ,
					'G' , {0xC98,-1} ,
					'z' , {0xC99,-1} ,
					'c' , {0xC9A,-1} ,
					'C' , {0xC9B,-1} ,
					'j' , {0xC9C,-1} ,
					'J' , {0xC9D,-1} ,
					'Z' , {0xC9E,-1} ,
					'q' , {0xC9F,-1} ,
					'Q' , {0xCA0,-1} ,
					'w' , {0xCA1,-1} ,
					'W' , {0xCA2,-1} ,
					'N' , {0xCA3,-1} ,
					't' , {0xCA4,-1} ,
					'T' , {0xCA5,-1} ,
					'd' , {0xCA6,-1} ,
					'D' , {0xCA7,-1} ,
					'n' , {0xCA8,-1} ,
					'p' , {0xCAA,-1} ,
					'P' , {0xCAB,-1} ,
					'b' , {0xCAC,-1} ,
					'B' , {0xCAD,-1} ,
					'm' , {0xCAE,-1} ,
					'y' , {0xCAF,-1} ,
					'r' , {0xCB0,-1} ,
					'l' , {0xCB2,-1} ,
					'L' , {0xCB3,-1} ,
					'v' , {0xCB5,-1} ,
					'S' , {0xCB6,-1} ,
					'x' , {0xCB7,-1} ,
					's' , {0xCB8,-1} ,
					'h' , {0xCB9,-1} ,

};  


std::vector<unsigned int> g_keystoadd1;

void AddKey(unsigned int ch)
{
	g_keystoadd1.push_back(ch);
}

void PushBackspaces()
{
	HWND myWnd;
	 myWnd =  GetActiveWindowHandel();

	 //CWnd cwnd;
	 
	// myWnd

	do
	{
		if((g_keystoadd1.size()>0) && (g_keystoadd1[0]==8))
		{
			::PostMessage(myWnd,WM_KEYDOWN,(WPARAM)VK_BACK,(LPARAM)((0x0e<<16)|1));
			::PostMessage(myWnd,WM_KEYUP,(WPARAM)VK_BACK,(LPARAM)((0x0e<<16)|1|(1<<31)));
			g_keystoadd1.erase(g_keystoadd1.begin());
		}
		else
			break;
	} while (g_keystoadd1.size()>0);

}

void PushKeys()
{
	SHORT scanCode;
	WPARAM lParam;

	if(g_keystoadd1.size()==0)
		return;

	HWND myWnd;
	 myWnd =  GetActiveWindowHandel();


	while(g_keystoadd1.size()>0)
	{
		   scanCode = VkKeyScanW((WCHAR)g_keystoadd1[0]);
			lParam = (scanCode << 16)+1;
				PostMessageW(myWnd,WM_CHAR,(WPARAM)g_keystoadd1[0],lParam);
		g_keystoadd1.erase(g_keystoadd1.begin());
	}
}

//------------This-function-is-repeatedly-called-this-executes-when-a-key-is-pressed-on-the-keyboard---/
LRESULT EXPORTED_DLL_FUNCTION kbdHookProc(int nCode,WPARAM wParam,LPARAM lParam)
{
	MessageBox(NULL,_T("hook proc"),_T("vf"),1);
	if(nCode<0)												//---Do not process further if a system key is pressed---//
	{ 
		return CallNextHookEx (ghKeyHook,nCode,wParam,lParam);   //---Call the next hook procedure in the hook chain---//
	}
	if(nCode==HC_NOREMOVE)
	{
			return CallNextHookEx (ghKeyHook,nCode,wParam,lParam); 
	}

  			TCHAR ch;
			int c_bit = 0;
			BYTE ks[256];                                //---a byte for getting the keyboard ststus---//
		    WORD w;										 //---a word for holding the character value of the key---// 
			int r_bit  = 0;											 //pressed used by the ToAsccii where the value is set into this---//	
			UINT scan=0; int f=0;						
		         GetKeyboardState(ks);         
				 ToAscii(wParam,scan,ks,&w,0);
                  ch = char(w);
				 static int successs = 0;
				 		SHORT scanCode;
				WPARAM lParam1 ;

				 
	if((GetKeyState(VK_SCROLL ) & 0x0001))
	{
		if(wParam == VK_SPACE)
		{
			s_bit = TRUE;
		}

	//successs = 0;
				HKL hkl = LoadKeyboardLayout(KAN_KEYBOARD_LAYOUT, KLF_REPLACELANG | KLF_SUBSTITUTE_OK);
			//if(toascii(ch) >= 65 && toascii(ch) <= 65+26 )
			
    		if (((DWORD)lParam & 0x80000000)==0x000000000)   //---If key is pressed and is not a control key---//
			{
				if (((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z')))
				{
					//MessageBoxA(NULL,"char","gbg",1);
				ActivateKeyboardLayout(hkl,0);
				successs = FindCharacters(ch);									//---Find the glyph code--//
					if(successs == 1)
					{
						PushBackspaces();
					}
				}
			}
			else
			{
						 PushKeys();
						 PostMessage(GetActiveWindowHandel(),WM_INPUTLANGCHANGEREQUEST,(WPARAM)0,(LPARAM)0x04090409);
						return 1;

			}

			if(ch == 32 || (ch >= 48 && ch <= 57))
			{
				c_bit = 0;
			}
			
			if (! (((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z'))) )
			{
				MessageBoxA(NULL,"bgb","gbg",1);
			}
			return 0;
	}

}

LRESULT EXPORTED_DLL_FUNCTION callWndRetProc(int nCode,WPARAM wParam,LPARAM lParam)
{
	if(nCode<0)
	{
		return CallNextHookEx(ghCallWndProcRetHook,nCode,wParam,lParam);
	}

	CWPRETSTRUCT *p=(CWPRETSTRUCT*)lParam;
	if(p->message==WM_KEYDOWN)
	{
		if(p->wParam==VK_BACK)
		{
			PushKeys();
		}
	}
		LRESULT ret=CallNextHookEx(ghCallWndProcRetHook,nCode,wParam,lParam);
	return ret;
}


//---------------Insatalls-the-Hook---//---This-is -called-by-the-.exe---//
BOOL EXPORTED_DLL_FUNCTION InstallKeyboardHook_KanUni (HWND hWnd) 
{
	//MessageBox(NULL,_T("Hooked"),_T("1"),1);
   BOOL bSuccess = FALSE;
    if( !ghKeyHook) 
	{
		ghWndMain = hWnd;
		glpfnHookProc = (HOOKPROC) kbdHookProc;
		bSuccess = (NULL != ( ghKeyHook = ::SetWindowsHookEx (WH_KEYBOARD, glpfnHookProc,ghInstance, NULL)));
		bSuccess = TRUE;
		ghCallWndProcRetHook = ::SetWindowsHookEx (WH_CALLWNDPROCRET, (HOOKPROC)callWndRetProc,ghInstance, NULL);
	}
	return bSuccess;
}


//---------------Un-Insatalls-the-Hook---//---This-is -called-by-the-.exe---//
BOOL EXPORTED_DLL_FUNCTION DeInstallKeyboardHook_KanUni()
{
	if(ghKeyHook) 
	{
		if( TRUE == (0 != ::UnhookWindowsHookEx (ghKeyHook)))
		{
			ghKeyHook = NULL;
		}
	}
	if(ghCallWndProcRetHook) 
	{
		if( TRUE == (0 != ::UnhookWindowsHookEx (ghCallWndProcRetHook)))
		{
			ghCallWndProcRetHook = NULL;
		}
		
	}
   return (NULL == ghKeyHook);
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////  This Function Finds The Character in The Tables in Found Calls     /////////////////////////////
/////////////////////////////  The Display Functions With Position (i),and The Starting Position  /////////////////////////////
/////////////////////////////  Of The Of The Message To Be Posted The Argument 					  /////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int FindCharacters(char ch) 
{       
//	HWND  myWnd;  //---------Window Handel---//
    int	v_bit = 0;
	int no_bs = 0;//-------number of back spae--------//
	int glp_pos = 0; //---Glyph position ----//
	int i;
	BOOL bHandledKeystroke = FALSE;
	found = 0;
	no_bs = o_count;
	int ret_val = FALSE;

	if(ch == 'f' && c_bit == 1)
	{
		c_bit = 0;
		//AddKey(0x0C4D);
		HKL hkl = LoadKeyboardLayout(KAN_KEYBOARD_LAYOUT, KLF_REPLACELANG | KLF_SUBSTITUTE_OK);
		ActivateKeyboardLayout(hkl,0);
		PostMessageW(GetActiveWindowHandel(),WM_CHAR,0x0ccD,1);
		//AddKey(0xccd);
	   // ::MessageBox(NULL,"fvfdv","vfvd",1);
		PostMessage(GetActiveWindowHandel(),WM_INPUTLANGCHANGEREQUEST,(WPARAM)0,(LPARAM)0x04090409);
		return 1;
	}
	for(i=0;i<3;i++)
		{
			if(found == 0)
			if(ch == anuswaranvisarga[i].key)
			{
				if(c_bit == 1)
				{
					c_bit = 0;
				}
				found = 1;
				ret_val = TRUE;
				DisplayCharacters(i,ANUSWARA,0);
			}

		}
	if(found == 0)
			for(i=0;i<15;i++)
			{
				if(ch == vowels[i].key)
					{
						found  = 1;
						ret_val = TRUE;
						if(c_bit == 1)
						{
						c_bit = 0;
						if(ch != 'a')
						DisplayCharacters(i,VOWELS,2);
						}
						else
						DisplayCharacters(i,VOWELS,0);
					}
				
			}
	if(found == 0)
		for(i=0;i<35;i++)
		{
			if(found == 0)
			{
				if(ch == consonants[i].key)
				{
					found  = 1;
					ret_val = TRUE;
					c_bit = 1;
					DisplayCharacters(i,CONSONANTS,0);
				}
			}
		}
	return ret_val;
}

HWND GetActiveWindowHandel()
{
    			HWND  myWnd;  //---------Window Handel---//
                myWnd  = GetFocus();
                if (myWnd == NULL)
                myWnd = GetForegroundWindow();

				
                if (myWnd == NULL)
				{
					//MessageBox(myWnd,(LPCWSTR)_T("Error"),_T(" "), 0);
					return NULL;
			}
				return myWnd;
}

void DisplayCharacters(int nval,int indicator,int j)   //indictor value is 0 for anuswara ,1 for vowels , 2 for consonants
{    
			int k = j ;   // --------index for glyph codes---// 
			 HWND myWnd;
	         myWnd =  GetActiveWindowHandel();


			if(indicator==0)	
			{
			//::PostMessage(myWnd,WM_CHAR,(WPARAM)anuswaranvisarga[nval].k_val[0],(LPARAM)1);
			AddKey(anuswaranvisarga[nval].k_val[0]);
			}
		else
		   if(indicator==1)	
			{
			while(vowels[nval].k_val[k]!=-1)
				{
					 //   ::PostMessage(myWnd,WM_CHAR,(WPARAM)vowels[nval].k_val[k],(LPARAM)1);
				AddKey(vowels[nval].k_val[k]);
						k++;
				}
			}
		else
		    if(indicator == 2)
			{
				while(consonants[nval].k_val[k]!=-1)
				{
				//		::PostMessage(myWnd,WM_CHAR,(WPARAM)consonants[nval].k_val[k],(LPARAM)1);
					AddKey(consonants[nval].k_val[k]);
					k++;
				}
			}
}


