////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////AUTHOR : Sudheer HS	sudheer316@gmail.com////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////DATE : 6-apr-2006							////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////Description : This processes key inputs and emulates kannada characters for the key pressed		////////////////////////////////////////////////////////////////
////////////////			 this reads the key pressed and then produces the required characters for kannada languagge		////////////////////////////////////////////////////////////////
////////////////Compiler Used : Microsoft Visual C++////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	////////////////////////////////////////////////////////////////	
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <vector>
#include <windows.h>
#include <memory.h>
#include "..\headers\flags.h"

std::vector<int> g_keystoadd;

#define MACRO_MEM_SIZE (1024*64) //64 KB
#define MAX_MACRO_ITEMS 1024

#define KAN_KEYBOARD_LAYOUT _T("0000044B")
#define US_KEYBOARD_LAYOUT _T("00000409")


void displayQueue();
void sendSpace(int);
void clearQueue();
void sendBackSpace(int back);
void displayCharacterPHI(char ch,int i);
void displayCharactersjPwX(char ch,int i);
void displayChar(char ch);
void setForFBit(char ch,int i);
void setGlyphsFoeJMY(char ch,int i);
void setGlyphsNyaInya(char ch,int i);
void setGlyphsBaCa(char ch,int i);
void setGlyphs(char ch , int gval);
void displayCharacters(int nval,int v_bit,int j) ;
void displayCharactersF(char ch) ;
void displayGunisu(char ch) ;
void displayCharactersA(int nval,int v_bit,int j) ;
void copyLastChar0(char ch);
void copyLastChar1(char ch);
void setGlyphsForKXHA_GYNA(char ch,int i);
void setGlyphsForJMY(char ch,int i);
void setGlyphsKaJaBa(char ch , int gval,int i);
int findKannadaCharacters(char ch) ;
void displayGunitakshara(char ch);
void displayCharactersF(char ch);
void displayChar(char ch);
void clearAllFlags();
int isPreviousF(char ch);

void addKey(unsigned int ch);
BOOL CALLBACK MyEnumProc(HWND hWnd, LPARAM lParam);

HWND getActiveWindowHandle();

char f1,f2;

UINT scan=0; 

struct KeyboardOptions
{
	int freeMarking;
	int toneNextToVowel;
	int modernStyle;
	int macroEnabled;
	int useUnicodeClipboard;
	int alwaysMacro;
	int useIME;
};

struct HookMacroDef
{
	int keyOffset;
	int textOffset;
};


struct CodeInfo {
	DWORD DT[256];
	unsigned char BD[12][6];
	unsigned char BK[8];
	unsigned char BW[6];
	unsigned char BT[6];
	WORD ToUniH[256];
	WORD ToUniL[256];
	int multiBytes; // 2 bytes charset (Unicode, VNI, ....)
	int encoding; //UCS-2, UTF-8, Reference
	int singleBackspace;
//	unsigned char remapLayout[256]; //used to remap Vietnamese layout to US layout

};

struct SharedMem {
	//states
	int Initialized;
	int vietKey;
	int iconShown;
	int switchKey;

	KeyboardOptions options;

	WORD keyMode;
	int inMethod;
	CodeInfo codeTable;

	// system
	HHOOK keyHook,mouseHook;
	HWND hMainDlg;
	UINT iconMsgId;
	HICON hVietIcon,hEnIcon;
	int unicodePlatform;
	DWORD winMajorVersion, winMinorVersion;

	// macro table
//	MacroDef macroTable[MAX_MACRO_ITEMS];
	HookMacroDef macroTable[MAX_MACRO_ITEMS];
	char macroMem[MACRO_MEM_SIZE];
	int macroCount;
};


SharedMem * pShMem = NULL ;
HINSTANCE MyInstance = NULL;


void displaySingleCharacter(int fval) 
{
addKey(fval);
}


void displayDoubleCharacter(int fval,int sval) 
{
addKey(fval);
addKey(sval);
}


void displayTripleCharacter(int fval,int sval,int tval) 
{
addKey(fval);
addKey(sval);
addKey(tval);
}


void displayFourCharacter(int fval,int sval,int tval,int fhval) 
{
addKey(fval);
addKey(sval);
addKey(tval);
addKey(fhval);
}



void sendBackSpace(int back)
{
		while(back>=1)
		{
          addKey(VK_BACK);
          back--;
		}
}

 
  
BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam)
{
   TCHAR buff[256];
   ::GetWindowText(hwnd,(LPSTR)buff, 255);
   int nCtrlID = ::GetDlgCtrlID(hwnd);

   return TRUE;
}

static HWND getActiveWindowHandle()
{  
	HWND hWnd;
	hWnd  = GetFocus();
 	return hWnd;
}

void sendSpace(int s)
{
while(s-->=1)
	{
          addKey((WPARAM)246);
    }
}

int isNumPad(WPARAM wParam)
{
	if(wParam == VK_SUBTRACT  ||
	   wParam == VK_DIVIDE    ||
	   wParam == VK_ADD       ||
	   wParam == VK_MULTIPLY  ||
	   wParam == VK_DECIMAL   )
	{
		
		return 1;
	}
	else
		return 0;
}


void addKey(unsigned int ch)
{
	g_keystoadd.push_back(ch);
}

void pushBackspaces()
{
	HWND myWnd;
	myWnd =  getActiveWindowHandle();
 	do
	{
		if((g_keystoadd.size()>0) && (g_keystoadd[0]==8))
		{
			::PostMessage(myWnd,WM_KEYDOWN,(WPARAM)VK_BACK,(LPARAM)((0x0e<<16)|1));
			::PostMessage(myWnd,WM_KEYUP,(WPARAM)VK_BACK,(LPARAM)((0x0e<<16)|1|(1<<31)));
			g_keystoadd.erase(g_keystoadd.begin());
		}
		else
			break;
	} while (g_keystoadd.size()>0);

}

void pushKeys()
{
	SHORT scanCode;
	WPARAM lParam;

	if(g_keystoadd.size()==0)
		return;

	HWND myWnd;
	myWnd =  getActiveWindowHandle();

	LPCWSTR lpcstr = (LPCWSTR)"0x044b";
  
	//PostMessage(getActiveWindowHandle(),WM_INPUTLANGCHANGEREQUEST,(WPARAM)0,(LPARAM)0x040B040B);
	while(g_keystoadd.size()>0)
	{
		   scanCode = VkKeyScanW((WCHAR)g_keystoadd[0]);
			lParam = (scanCode << 16)+1;
  			PostMessageW(myWnd,WM_CHAR,(WPARAM)g_keystoadd[0],lParam);
		g_keystoadd.erase(g_keystoadd.begin());
 
	}
	
	 lpcstr = (LPCWSTR)"0x0409";

	 //PostMessage(myWnd,WM_INPUTLANGCHANGEREQUEST,(WPARAM)0,(LPARAM)0x04090409);
 }

 