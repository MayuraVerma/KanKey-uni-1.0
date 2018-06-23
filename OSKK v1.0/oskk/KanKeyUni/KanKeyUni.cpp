// KanKeyUni.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "KanKeyUni.h"
#include "..\headers\KeyFuncts.h"
#include <vector>
#include <wchar.h>
#include <memory.h>
#include <windows.h>

#define WM_MYCUSTOMMESSAGE WM_USER+1
//#define FONT_FILE _T("ABC Sans Serif")

#define KAN_KEYBOARD_LAYOUT _T("0000044B")
#define US_KEYBOARD_LAYOUT _T("00000409")

#define ANUSWARA 0
#define VOWELS 1
#define CONSONANTS 2

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

long IsReleased = 0x80000000;
UINT VK_PAUSE_SCAN;


#pragma data_seg(".SHARDAT")
static HWND ghWndMain = 0 ;
static HHOOK ghKeyHook = NULL ;
#pragma data_seg()


static HHOOK ghCallWndProcRetHook = NULL;
static HHOOK ghCallWndProcHook= NULL;
static int processMenu = 0;
static int prKan = 1;

HINSTANCE ghInstance=0;
HOOKPROC glpfnHookProc=0;
    SHORT scanCode;
	WPARAM lParam1;
HWND      myWnd;

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
}consonants[36] = { 'k' , {0xC95,-1} ,
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
					'X' , {0x0200D,-1} ,

};  

BEGIN_MESSAGE_MAP(CKanKeyUniApp, CWinApp)
	//{{AFX_MSG_MAP(CKanKeyUniApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



std::vector<unsigned int> g_keystoadd1;

LRESULT EXPORTED_DLL_FUNCTION RunKeyboardKanKeyUni(int nCode,WPARAM wParam,LPARAM lParam)
{
	//if (!pShMem->Initialized) return 0;

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
			



	if(wParam == VK_APPS){
		if(lParam == WM_KEYDOWN || lParam == 22872065){
			prKan = 0;
		    processMenu = 1;
		}
		else{
			prKan = 1;
		}
	}
	
	if(wParam==WM_CONTEXTMENU){
		processMenu = 1;
	}
 

	if( (GetKeyState(VK_MENU) & 0x8000)  && wParam == VK_SHIFT && ((DWORD)lParam & 0x80000000)==0x000000000){
	 	if(prKan == 1){
			prKan = 0;
			SendMessage(FindWindow(NULL,"KanKey Kannada Keyboard"),WM_MYCUSTOMMESSAGE,0x0EE,1);
		}
		else{
			SendMessage(FindWindow(NULL,"KanKey Kannada Keyboard"),WM_MYCUSTOMMESSAGE,0x0F,1);
			prKan  = 1;
		}
	}
	if(prKan == 1 && !(wParam == VK_MENU) && !(wParam == VK_CONTROL) )
	{
		if(wParam == VK_SPACE)
		{
			clearAllFlags();
			kFlag.s_bit = TRUE;
		}
		else{
			kFlag.s_bit = FALSE;
		}
			
			HWND hWnd = getActiveWindowHandle();
			//::PostMessage(hWnd,WM_INPUTLANGCHANGEREQUEST,(WPARAM)0,(LPARAM)0x040B040B);

			 if(!(GetKeyState(VK_SHIFT) & 0x8000) && ((DWORD)lParam & 0x80000000)==0x000000000 && wParam >= 0x30 && wParam <=0x39)
	 {
		 switch (wParam)
		 {
	         case 0x30:
				addKey(3302);
											pushKeys();
							return 1;
			 break;
	         case 0x31:
				addKey(3303);
											pushKeys();
							return 1;
			 break;
	         case 0x32:
				addKey(3304);
											pushKeys();
							return 1;
			 break;
	         case 0x33:
				addKey(3305);
											pushKeys();
							return 1;
			 break;
	         case 0x34:
				addKey(3306);
											pushKeys();
							return 1;
			 break;
	         case 0x35:
				addKey(3307);
											pushKeys();
							return 1;
			 break;
	         case 0x36:
				addKey(3308);
											pushKeys();
							return 1;
			 break;
	         case 0x37:
				addKey(3309);
											pushKeys();
							return 1;
			 break;
	         case 0x38:
				addKey(3310);
											pushKeys();
							return 1;
			 break;
	         case 0x39:
				addKey(3311);
											pushKeys();
							return 1;
			 break; 
		 }
	 }

    		if (((DWORD)lParam & 0x80000000)==0x000000000)   //---If key is pressed and is not a control key---//
			{
				
				
				if (((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z')))
				{
	 				successs = findKannadaCharacters(ch);									//---Find the glyph code--//
 					pushBackspaces();
				}

			}
			else
			{
							pushKeys();
							//::PostMessage(hWnd,WM_INPUTLANGCHANGEREQUEST,(WPARAM)0,(LPARAM)0x04090409);
							return 1;

			}
			//::PostMessage(hWnd,WM_INPUTLANGCHANGEREQUEST,(WPARAM)0,(LPARAM)0x04090409);
			if (! (((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z'))) )
			return 0;
	}else
	{
		return CallNextHookEx (ghKeyHook,nCode,wParam,lParam); 
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
			pushKeys();
		}
	}
		LRESULT ret=CallNextHookEx(ghCallWndProcRetHook,nCode,wParam,lParam);
	return ret;
}

//---------------Insatalls-the-Hook---//---This-is -called-by-the-.exe---//
BOOL EXPORTED_DLL_FUNCTION  InitKeyboardKanKeyUni(HWND hWnd) 
{
    BOOL bSuccess = FALSE;
    HANDLE hMapObject = NULL;   /* handle to file mapping */
    if( !ghKeyHook) 
	{
#if 0
		pShMem = (SharedMem *) MapViewOfFile( 
			hMapObject,     /* object to map view of    */ 
			FILE_MAP_WRITE, /* read/write access        */ 
			0,              /* high offset:   map from  */ 
			0,              /* low offset:    beginning */ 
			0);             /* default: map entire file */ 
		//if (pShMem == NULL) 
		//  return FALSE;   
#endif // 0


		ghWndMain = hWnd;
		glpfnHookProc = (HOOKPROC) RunKeyboardKanKeyUni;
        bSuccess = (NULL != ( ghKeyHook = ::SetWindowsHookEx (WH_KEYBOARD, glpfnHookProc,ghInstance, NULL)));
		bSuccess = TRUE;
		ghCallWndProcRetHook = ::SetWindowsHookEx (WH_CALLWNDPROCRET, (HOOKPROC)callWndRetProc,ghInstance, NULL);
	
	}
	return bSuccess;
}


//---------------Un-Insatalls-the-Hook---//---This-is -called-by-the-.exe---//
BOOL EXPORTED_DLL_FUNCTION StopKeyboardKanKeyUni()
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



CKanKeyUniApp::CKanKeyUniApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CKanKeyUniApp object

CKanKeyUniApp theApp;



BOOL CKanKeyUniApp::InitInstance() 
{
	// TODO: Add your specialized code here and/or call the base class
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	ghInstance = AfxGetInstanceHandle();
	return TRUE;
}

int CKanKeyUniApp::ExitInstance() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	StopKeyboardKanKeyUni();

	return CWinApp::ExitInstance();
}

BOOL CKanKeyUniApp::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
		return CWinApp::PreTranslateMessage(pMsg);

}
 
int findKannadaCharacters(char ch) 
{       
//	HWND  myWnd;  //---------Window Handel---//
    int	v_bit = 0;
	int no_bs = 0;//-------number of back spae--------//
	int glp_pos = 0; //---Glyph position ----//
	int i;
	BOOL bHandledKeystroke = FALSE;
	kFlag.found= 0;
	no_bs = kFlag.o_count;
	int ret_val = FALSE;

	if(ch == 'F')
	{
		addKey(8);
		addKey(0xCB0);
		addKey(0x0ccD);
		ch = kFlag.previous_0;
	}
	if(ch == 'f' && kFlag.previous_0 == 'f')
	{
		::PostMessageW(getActiveWindowHandle(),WM_CHAR,0x200C,1);
				copyPrevious(ch);
 		return 1;
	}
	if(kFlag.previous_0  == 'f' && kFlag.previous_1 == 'r')
	{ 
	 	addKey(8);
		addKey(0x200D);
 		addKey(0x0ccD);
		kFlag.c_bit = 0;
	}
	if(ch == 'f' && kFlag.c_bit == 1)
	{
		kFlag.c_bit = 0; 
		::PostMessageW(getActiveWindowHandle(),WM_CHAR,0x0ccD,1);
				copyPrevious(ch);
 		return 1;
	}
	kFlag.previous_0 = '\0';
	for(i=0;i<3;i++)
		{
			if(kFlag.found== 0)
			if(ch == anuswaranvisarga[i].key)
			{
				if(kFlag.c_bit == 1)
				{
					kFlag.c_bit = 0;
				}
				kFlag.found= 1;
				ret_val = TRUE;
				displayCharacters(i,ANUSWARA,0);
			}

		}
	if(kFlag.found== 0)
			for(i=0;i<15;i++)
			{
				if(ch == vowels[i].key)
					{
						kFlag.found = 1;
						ret_val = TRUE;
						if(kFlag.c_bit == 1)
						{
							kFlag.c_bit = 0;
						if(ch != 'a')
						displayCharacters(i,VOWELS,2);
						}
						else
						displayCharacters(i,VOWELS,0);
					}
				
			}
	if(kFlag.found== 0)
		for(i=0;i<36;i++)
		{
			if(kFlag.found== 0)
			{
				if(ch == consonants[i].key)
				{
					kFlag.found = 1;
					ret_val = TRUE;
					kFlag.c_bit = 1;
					displayCharacters(i,CONSONANTS,0);
				}
			}
		}
	copyPrevious(ch);
	return ret_val;
}

 
void displayCharacters(int nval,int indicator,int j)   //indictor value is 0 for anuswara ,1 for vowels , 2 for consonants
{    
			int k = j ;   // --------index for glyph codes---// 
			 HWND myWnd;
	         myWnd =  getActiveWindowHandle();


		if(indicator==0)	
			{
	 		addKey(anuswaranvisarga[nval].k_val[0]);
			}
		else
		   if(indicator==1)	
			{
			while(vowels[nval].k_val[k]!=-1)
				{
	 			addKey(vowels[nval].k_val[k]);
						k++;
				}
			}
		else
		    if(indicator == 2)
			{
				while(consonants[nval].k_val[k]!=-1)
				{
	 				addKey(consonants[nval].k_val[k]);
					k++;
				}
			}
}



void clearAllFlags()
{
				              kFlag.q_bit  = 0;
                              kFlag.f_bit = 0;
                              kFlag.s_bit = 0;
                              kFlag.p_bit = 0;
                              kFlag.g_bit = 0;
                              kFlag.c_bit = 0;
                              kFlag.o_bit = 0;
                              kFlag.x_bit = 0;
                              kFlag.so_bit = 0;
                              kFlag.b_bit = 0;
                              kFlag.u_bit  = 0;
                              kFlag.ei_bit = 0;
                              kFlag.ipressed = 0;
                              kFlag.space_bit = 0;
                              kFlag.j_bit = 0;
                              kFlag.first_o = 0;
                              kFlag.spec_kgun = 0;
                              kFlag.spec_kgun_val;
                              kFlag.slash_bit = 0;
							  kFlag.f_pressed_Once = 0;
	 
}

void copyPrevious(char ch)
{
	kFlag.previous_3 = kFlag.previous_2;
	kFlag.previous_2 = kFlag.previous_1;
	kFlag.previous_1 = kFlag.previous_0;
	kFlag.previous_0 = ch;
}


  