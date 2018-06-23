//Tunga.cpp implemaentation file

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////AUTHOR : Sudheer HS	sudheer316@gmail.com////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////DATE : 						////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////COMPANY : Maruthi Software Developers.,HASSAN - 573201 ,KARANATAKA, INDIA     ////////////////////////////////////////////////////////////////
////////////////Description : This processes key inputs and emulates kannada characters for the key pressed		////////////////////////////////////////////////////////////////
////////////////			 this reads the key pressed and then produces the required characters for kannada languagge		////////////////////////////////////////////////////////////////
////////////////Compiler Used : Microsoft Visual C++ 6.0////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	////////////////////////////////////////////////////////////////	
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////  This has been done as a project for Hampi University ,Hampi,INDIA ////////////////////////////////////////////////////////////////
////////////////  this is part of the free software Kuvempu Kannada Thantramsha,launched by Hampi University ////////////////////////////////////////////////////////////////
////////////////  This code as is with out any kind of warranty ,Using or modifing the code or the library without ////////////////////////////////////////////////////////////////
////////////////  the written permission by the university is prohibited,Any such illegal activities is punishable offence as per ////////////////////////////////////////////////////////////////
////////////////  the copy rights ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "Tunga.h"
#include "..\headers\keyfuncts.h"
//#include "..\headers\flags.h"
#include <ctype.h>
#include <windows.h>

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

BEGIN_MESSAGE_MAP(CTungaApp, CWinApp)
	//{{AFX_MSG_MAP(CTungaApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



std::vector<unsigned int> g_keystoadd1;

//------------This-function-is-repeatedly-called-this-executes-when-a-key-is-pressed-on-the-keyboard---/

LRESULT EXPORTED_DLL_FUNCTION SetKeyBoardTunga(int nCode,WPARAM wParam,LPARAM lParam)
{
          
		  if(nCode<0)												//---Do not process further if a system key is pressed---//
          { 
                    return CallNextHookEx (ghKeyHook,nCode,wParam,lParam);   //---Call the next hook procedure in the hook chain---//
          }
          
		  if(nCode==HC_NOREMOVE)
          {
                    return CallNextHookEx (ghKeyHook,nCode,wParam,lParam); 
          }
          
		char ch;
		BYTE ks[256];                                //---a byte for getting the keyboard ststus---//
		WORD w;										 //---a word for holding the character value of the key---// 
         						 //pressed used by the ToAsccii where the value is set into this---//	
          UINT scan=0; 
		 
          ::GetKeyboardState(ks);         
          ::ToAscii(wParam,scan,ks,&w,0);

          ch = char(w);
        
	

		  if(wParam == VK_SCROLL)
		  {
			  hWnd  = GetFocus ();
			 if(hWnd != NULL)
			 {
			  GetWindowText(hWnd,buffer,MAX_BUFFER);
			  if(0 == strncmp(buffer,"Microsoft Word Document",strlen(buffer)));
			  {
//				  if (((DWORD)lParam & 0x80000000)==0x000000000) 
				  if((GetKeyState(VK_SCROLL ) & 0x0001))
				  {
					 // if (((DWORD)lParam & 0x80000000)==0x000000000) 
					//	{
				
					  // Simulate a key press
							 keybd_event( VK_LCONTROL,0x1D,                      KEYEVENTF_EXTENDEDKEY | 0,                      0 );

							 keybd_event( VK_LSHIFT,
										  0x2A,
										  KEYEVENTF_EXTENDEDKEY | 0,

										  0 );

										  keybd_event( 0x46,
										  0x21,
										  KEYEVENTF_EXTENDEDKEY | 0,
										  0 );

										  
						  // Simulate a key release
							 keybd_event( 0x46,
										  0x21,
										  KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
										  0);

							 keybd_event( VK_LSHIFT,
										  0x2A,
										  KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
										  0);

							  // Simulate a key release```````````
							 keybd_event( VK_LCONTROL,
										  0x1D,
										  KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
										  0);

								  
				//  }else
				//  {
					  Sleep(50);
					//	AfxMessageBox("Scroll Off",1);
					TCHAR tc[1000];
					_stprintf(tc, TEXT("Kuvempu_Eng_0001"));

					if (((DWORD)lParam & 0x80000000)!=0x000000000) 
					{
					PostMessage(getActiveWindowHandle(), WM_CHAR, (WPARAM)'K', 0); // for Win32 windows
					PostMessage(getActiveWindowHandle(), WM_CHAR, (WPARAM)'u', 0); // for Win32 windows
					PostMessage(getActiveWindowHandle(), WM_CHAR, (WPARAM)'v', 0); // for Win32 windows
					PostMessage(getActiveWindowHandle(), WM_CHAR, (WPARAM)'e', 0); // for Win32 windows
					PostMessage(getActiveWindowHandle(), WM_CHAR, (WPARAM)'m', 0); // for Win32 windows
					PostMessage(getActiveWindowHandle(), WM_CHAR, (WPARAM)'p', 0); // for Win32 windows
					PostMessage(getActiveWindowHandle(), WM_CHAR, (WPARAM)'u', 0); // for Win32 windows
					PostMessage(getActiveWindowHandle(), WM_CHAR, (WPARAM)'_', 0); // for Win32 windows
					PostMessage(getActiveWindowHandle(), WM_CHAR, (WPARAM)'E', 0); // for Win32 windows
					PostMessage(getActiveWindowHandle(), WM_CHAR, (WPARAM)'n', 0); // for Win32 windows
					PostMessage(getActiveWindowHandle(), WM_CHAR, (WPARAM)'g', 0); // for Win32 windows
					PostMessage(getActiveWindowHandle(), WM_CHAR, (WPARAM)'_', 0); // for Win32 windows
					PostMessage(getActiveWindowHandle(), WM_CHAR, (WPARAM)'0', 0); // for Win32 windows
					PostMessage(getActiveWindowHandle(), WM_CHAR, (WPARAM)'0', 0); // for Win32 windows
					PostMessage(getActiveWindowHandle(), WM_CHAR, (WPARAM)'0', 0); // for Win32 windows
					PostMessage(getActiveWindowHandle(), WM_CHAR, (WPARAM)'1', 0); // for Win32 windows
					}
			
					Sleep(250);

					      keybd_event( VK_RETURN,
                      0x1C,
                      KEYEVENTF_EXTENDEDKEY | 0,
                      0 );

				// Simulate a key release
					keybd_event( VK_RETURN,
                      0x1C,
                      KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
                      0);

						 keybd_event( VK_LCONTROL,0x1D,                      KEYEVENTF_EXTENDEDKEY | 0,                      0 );

							 keybd_event( VK_LSHIFT,
										  0x2A,
										  KEYEVENTF_EXTENDEDKEY | 0,

										  0 );

										  keybd_event( 0xBE,
										  0x34,
										  KEYEVENTF_EXTENDEDKEY | 0,
										  0 );

										  
						  // Simulate a key release
							 keybd_event( 0xBE,
										  0x34,
										  KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
										  0);

							 keybd_event( VK_LSHIFT,
										  0x2A,
										  KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
										  0);

							  // Simulate a key release```````````
							 keybd_event( VK_LCONTROL,
										  0x1D,
										  KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
										  0);

						  // Simulate a key release


				// }
				}else
				  {
						  

				keybd_event( VK_LCONTROL,0x1D,                      KEYEVENTF_EXTENDEDKEY | 0,                      0 );

					keybd_event( VK_SPACE,0x39,                      KEYEVENTF_EXTENDEDKEY | 0,                      0 );

				 keybd_event( VK_SPACE,
                      0x39,
                      KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
                      0);

				 keybd_event( VK_LCONTROL,
                      0x1D,
                      KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
                      0);

				 }
			  }
			  
			 }

		  }
		  //ch = getPrakKeys(ch);
		  if( (ch = getPrakKeys(ch))!=-1)
		  if((GetKeyState(VK_SCROLL ) & 0x0001))
          {
			   
                if( !__isAlpha(ch) && (ispunct(ch) || isdigit(ch) || (wParam == VK_SPACE) || (wParam == VK_BACK )))
                {
					clearAllFlags();
	      		}
                 
			    if( __isAlpha(ch)||wParam == VK_SPACE)   //---If key is pressed and is not a control key---//
					{                        
							if (((DWORD)lParam & 0x80000000)==0x000000000)  //---If key is pressed and is not a control key---//
							{
								if(ch == '&')
								{
									successs = findKannadaCharacters('k');
									successs = findKannadaCharacters('\\');
									successs = findKannadaCharacters('x');
								}
								else if(ch == '%')
								{
									successs = findKannadaCharacters('j');
									successs = findKannadaCharacters('\\');
									successs = findKannadaCharacters('z');
								}
								else
								{
										findKannadaCharacters(ch);									//---Find the glyph code--//
								}
								ActivateKeyboardLayout(hkl,0);
								//successs = findKannadaCharacters(ch);	
										if(success == 1)                                      
									  pushBackspaces();
							}
							else 
							{
								pushKeys();
								PostMessage(getActiveWindowHandle(),WM_INPUTLANGCHANGEREQUEST,(WPARAM)0,(LPARAM)0x04090409);
							            pushKeys();
                                      	if(isWinNTServer())
										{
											return CallNextHookEx(ghKeyHook,nCode,wParam,lParam); 
										}
										else
										{
											return TRUE;
										}
							}
					}
                else
                    {
							  if(wParam != VK_SHIFT)
							  clearAllFlags();
                              return CallNextHookEx(ghKeyHook,nCode,wParam,lParam); 
					}
                    
			 	if((__isAlpha(ch)||wParam == VK_SPACE)&&!(GetKeyState(VK_MENU) & 0x80))    //---If the key pressed is a alpha key and when not
				{                                                  //---- Alt is down posts only the the promted message--//
                              return TRUE;
                }
				else
                return CallNextHookEx(ghKeyHook,nCode,wParam,lParam); 
                              //---Call the next hook procedure in the hook chain---//
		
		  }	
		  else
          return CallNextHookEx(ghKeyHook,nCode,wParam,lParam); 
}


/*

LRESULT EXPORTED_DLL_FUNCTION SetKeyBoardTunga(int nCode,WPARAM wParam,LPARAM lParam){
	
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

	if( (ch = getPrakKeys(ch))!=-1)			 
	if((GetKeyState(VK_SCROLL ) & 0x0001))
	{
		if(wParam == VK_SPACE)
		{
			clearAllFlags();
			kFlag.s_bit = TRUE;
		}
		else
			kFlag.s_bit = FALSE;

		

	//successs = 0;
				HKL hkl = LoadKeyboardLayout(KAN_KEYBOARD_LAYOUT, KLF_REPLACELANG | KLF_SUBSTITUTE_OK);
			//if(toascii(ch) >= 65 && toascii(ch) <= 65+26 )
			
    		if (((DWORD)lParam & 0x80000000)==0x000000000)   //---If key is pressed and is not a control key---//
			{
				if (__isAlpha(ch))//((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z')))
				{
				ActivateKeyboardLayout(hkl,0);
				successs = findKannadaCharacters(ch);									//---Find the glyph code--//
					if(successs == 1)
					{
						pushBackspaces();
					}
				}
				else
				{
					clearAllFlags();
				}
			}
			else
			{
		//Commented-----	return CallNextHookEx(ghKeyHook,nCode,wParam,lParam);
							pushKeys();
							PostMessage(getActiveWindowHandle(),WM_INPUTLANGCHANGEREQUEST,(WPARAM)0,(LPARAM)0x04090409);
							return 1;

				}
			//}
			if (!__isAlpha(ch))// (((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z'))) )
			return 0;
		//}
	}

}
*/
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
BOOL EXPORTED_DLL_FUNCTION InstallKeyboardHookTunga(HWND hWnd) 
{
          BOOL bSuccess = FALSE;
          if( !ghKeyHook) 
          {
                    ghWndMain = hWnd;
                    glpfnHookProc = (HOOKPROC) SetKeyBoardTunga;
                    bSuccess = (NULL != ( ghKeyHook = ::SetWindowsHookEx (WH_KEYBOARD, glpfnHookProc,ghInstance, NULL)));
                    bSuccess = TRUE;
                    ghCallWndProcRetHook = ::SetWindowsHookEx (WH_CALLWNDPROCRET, (HOOKPROC)callWndRetProc,ghInstance, NULL);
          }
          return bSuccess;
}

long __stdcall InstallKeyboardHookTungaDEF() 
{
          //InstallKeyboardHookTunga(hwnd);
	       glpfnHookProc = (HOOKPROC) SetKeyBoardTunga;
           ghKeyHook = ::SetWindowsHookEx (WH_KEYBOARD, glpfnHookProc,ghInstance, NULL);
		   ghCallWndProcRetHook = ::SetWindowsHookEx (WH_CALLWNDPROCRET, (HOOKPROC)callWndRetProc,ghInstance, NULL);
          return TRUE;
}

long __stdcall DeInstallKeyboardHookTungaDEF() 
{
          DeInstallKeyboardHookTunga();
          return TRUE;
}

//---------------Un-Insatalls-the-Hook---//---This-is -called-by-the-.exe---//
BOOL EXPORTED_DLL_FUNCTION DeInstallKeyboardHookTunga()
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


CTungaApp::CTungaApp()
{
          // TODO: add construction code here,
          // Place all significant initialization in InitInstance
}


/////////////////////////////////////////////////////////////////////////////
// The one and only CTungaApp object

CTungaApp theApp;

BOOL CTungaApp::InitInstance() 
{
          // TODO: Add your specialized code here and/or call the base class
          AFX_MANAGE_STATE(AfxGetStaticModuleState());
          ghInstance = AfxGetInstanceHandle();
          return TRUE;
}

int CTungaApp::ExitInstance() 
{
          // TODO: Add your specialized code here and/or call the base class
                    DeInstallKeyboardHookTunga();
                    return CWinApp::ExitInstance();
}


BOOL CTungaApp::PreTranslateMessage(MSG* pMsg) 
{
          // TODO: Add your specialized code here and/or call the base class
          return CWinApp::PreTranslateMessage(pMsg);
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////  This Function Finds The Character in The Tables in Found Calls     /////////////////////////////
/////////////////////////////  The Display Functions With Position (i),and The Starting Position  /////////////////////////////
/////////////////////////////  Of The Of The Message To Be Posted The Argument 					  /////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


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

	if(ch == 'f' && kFlag.c_bit == 1)
	{
		kFlag.c_bit = 0;
		//addKey(0x0C4D);
		HKL hkl = LoadKeyboardLayout(KAN_KEYBOARD_LAYOUT, KLF_REPLACELANG | KLF_SUBSTITUTE_OK);
		ActivateKeyboardLayout(hkl,0);
		PostMessageW(getActiveWindowHandle(),WM_CHAR,0x0ccD,1);
		//addKey(0xccd);
	   // ::MessageBox(NULL,"fvfdv","vfvd",1);
		PostMessage(getActiveWindowHandle(),WM_INPUTLANGCHANGEREQUEST,(WPARAM)0,(LPARAM)0x04090409);
		return 1;
	}
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
		for(i=0;i<35;i++)
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
	return ret_val;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////  This Function Finds The Character in The Tables in Found Calls     /////////////////////////////
/////////////////////////////  The Display Functions With Position (i),and The Starting Position  /////////////////////////////
/////////////////////////////  Of The Of The Message To Be Posted The Argument 					  /////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void displayCharacters(int nval,int indicator,int j)   //indictor value is 0 for anuswara ,1 for vowels , 2 for consonants
{    
			int k = j ;   // --------index for glyph codes---// 
			 HWND myWnd;
	         myWnd =  getActiveWindowHandle();


			if(indicator==0)	
			{
			//::PostMessage(myWnd,WM_CHAR,(WPARAM)anuswaranvisarga[nval].k_val[0],(LPARAM)1);
			addKey(anuswaranvisarga[nval].k_val[0]);
			}
		else
		   if(indicator==1)	
			{
			while(vowels[nval].k_val[k]!=-1)
				{
					 //   ::PostMessage(myWnd,WM_CHAR,(WPARAM)vowels[nval].k_val[k],(LPARAM)1);
				addKey(vowels[nval].k_val[k]);
						k++;
				}
			}
		else
		    if(indicator == 2)
			{
				while(consonants[nval].k_val[k]!=-1)
				{
				//		::PostMessage(myWnd,WM_CHAR,(WPARAM)consonants[nval].k_val[k],(LPARAM)1);
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
//                            kFlag.derg_bit = 1;
//                            kFlag.derg_count ;
                              kFlag.spec_kgun = 0;
                              kFlag.spec_kgun_val;
                              kFlag.slash_bit = 0;
							  kFlag.f_pressed_Once = 0;
	                          //clearQueue();
}
int __isAlpha(char ch)


{
				if (((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z')) || ch == '+' || ch == '\\' || ch == '&' || ch == '%' || ch == '`' || ch == '~'  || ch == '`'  || ch == '=' )						{
					return TRUE;
				}
				else
					return FALSE;
}


struct PrakKeys
{
	char orgKey;
	char subKey;
}prakKey[67] = {
				'x',					'M'		,
				'_',					'H'		,
				'd',					'a'		,
			//	'D'						'a'		,
				'e',					'A'		,
				'E',					'A'		,
				'f',					'i'		,
				'F',					'i'		,
				'r',					'I'		,
				'g',					'u'		,
				'G',					'u'		,
				't',					'U'		,
				'T',					'U'		,
				's',					'e'		,
				'S',					'E'		,
				'w',					'Y'		,
				'W',					'Y'		,
				'z',					'o'		,
				'Z',					'o'		,
				'a',					'O'		,
				'A',					'O'		,
				'q',					'V'		,
				'Q',					'V'		,
				'=',					'R'		,
				'+',					'+'		,
				'k',					'k'		,
				'K',					'K'		,
				'i',					'g'		,
				'I',					'G'		,
				'U',					'Z'		,
				';',					'c'		,
				':',					'C'		,
				'p',					'j'		,
				'P',					'J'		,
				']',					'z'		,
				'\'',					'q'		,
				'"',					'Q'		,
				'[',					'w'		,
				'{',					'W'		,
				'C',					'N'		,
				'l',					't'		,
				'L',					'T'		,
				'o',					'd'		,
				'O',					'D'		,
				'v',					'n'		,
				'h',					'p'		,
				'H',					'P'		,
				'y',					'b'		,
				'Y',					'B'		,
				'c',					'm'		,
				'/',			    	'y'		,
				'j',					'r'		,
				'J',					'`'		,
				'n',					'l'		,
				'b',					'v'		,
				'M',					'S'		,	
				'v',					'M'		,
				'<',					'x'		,
				'm',					's'		,
				'u',					'h'		,
				'N',					'L'		,
				'B',					'='		,
				'&',					'&'		,
				'%',					'%'		,
				'\\'	,				'\\'	,
				'X'		,				'f'		,
				'`'		,				'F'		,
				'~'		,				'~'		,

};


char getPrakKeys(char ch)
{
	int i;

	for(i=0;i<67;i++)
	{
		if(prakKey[i].orgKey == ch)
		{
			return prakKey[i].subKey;
		}
	}

	return ch;
}

