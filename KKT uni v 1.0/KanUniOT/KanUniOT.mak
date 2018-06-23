# Microsoft Developer Studio Generated NMAKE File, Based on KanUniOT.dsp
!IF "$(CFG)" == ""
CFG=KanUniOT - Win32 Debug
!MESSAGE No configuration specified. Defaulting to KanUniOT - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "KanUniOT - Win32 Release" && "$(CFG)" != "KanUniOT - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "KanUniOT.mak" CFG="KanUniOT - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "KanUniOT - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "KanUniOT - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "KanUniOT - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\KanUniOT.dll"


CLEAN :
	-@erase "$(INTDIR)\KanUniOT.obj"
	-@erase "$(INTDIR)\KanUniOT.pch"
	-@erase "$(INTDIR)\KanUniOT.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\KanUniOT.dll"
	-@erase "$(OUTDIR)\KanUniOT.exp"
	-@erase "$(OUTDIR)\KanUniOT.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\KanUniOT.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\KanUniOT.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\KanUniOT.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\KanUniOT.pdb" /machine:I386 /def:".\KanUniOT.def" /out:"$(OUTDIR)\KanUniOT.dll" /implib:"$(OUTDIR)\KanUniOT.lib" 
DEF_FILE= \
	".\KanUniOT.def"
LINK32_OBJS= \
	"$(INTDIR)\KanUniOT.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\KanUniOT.res"

"$(OUTDIR)\KanUniOT.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "KanUniOT - Win32 Debug"

OUTDIR=.\..\output
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\..\output
# End Custom Macros

ALL : "$(OUTDIR)\KanUniOT.dll" "$(OUTDIR)\KanUniOT.bsc"


CLEAN :
	-@erase "$(INTDIR)\KanBrail.pch"
	-@erase "$(INTDIR)\KanUniOT.obj"
	-@erase "$(INTDIR)\KanUniOT.res"
	-@erase "$(INTDIR)\KanUniOT.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\KanUniOT.bsc"
	-@erase "$(OUTDIR)\KanUniOT.dll"
	-@erase "$(OUTDIR)\KanUniOT.exp"
	-@erase "$(OUTDIR)\KanUniOT.ilk"
	-@erase "$(OUTDIR)\KanUniOT.lib"
	-@erase "$(OUTDIR)\KanUniOT.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_WINDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\KanBrail.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\KanUniOT.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\KanUniOT.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\KanUniOT.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\KanUniOT.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\KanUniOT.pdb" /debug /machine:I386 /def:".\KanUniOT.def" /out:"$(OUTDIR)\KanUniOT.dll" /implib:"$(OUTDIR)\KanUniOT.lib" /pdbtype:sept 
DEF_FILE= \
	".\KanUniOT.def"
LINK32_OBJS= \
	"$(INTDIR)\KanUniOT.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\KanUniOT.res"

"$(OUTDIR)\KanUniOT.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("KanUniOT.dep")
!INCLUDE "KanUniOT.dep"
!ELSE 
!MESSAGE Warning: cannot find "KanUniOT.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "KanUniOT - Win32 Release" || "$(CFG)" == "KanUniOT - Win32 Debug"
SOURCE=.\KanUniOT.cpp

!IF  "$(CFG)" == "KanUniOT - Win32 Release"


"$(INTDIR)\KanUniOT.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\KanUniOT.pch"


!ELSEIF  "$(CFG)" == "KanUniOT - Win32 Debug"


"$(INTDIR)\KanUniOT.obj"	"$(INTDIR)\KanUniOT.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\KanBrail.pch"


!ENDIF 

SOURCE=.\KanUniOT.rc

"$(INTDIR)\KanUniOT.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "KanUniOT - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\KanUniOT.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\KanUniOT.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "KanUniOT - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_WINDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\KanBrail.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\KanBrail.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

