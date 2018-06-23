# Microsoft Developer Studio Generated NMAKE File, Based on GUI.dsp
!IF "$(CFG)" == ""
CFG=GUI - Win32 Debug
!MESSAGE No configuration specified. Defaulting to GUI - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "GUI - Win32 Release" && "$(CFG)" != "GUI - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "GUI.mak" CFG="GUI - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "GUI - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "GUI - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "GUI - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\GUI.exe"


CLEAN :
	-@erase "$(INTDIR)\GUI.obj"
	-@erase "$(INTDIR)\GUI.pch"
	-@erase "$(INTDIR)\GUI.res"
	-@erase "$(INTDIR)\GUIDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\GUI.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\GUI.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\GUI.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\GUI.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\GUI.pdb" /machine:I386 /out:"$(OUTDIR)\GUI.exe" 
LINK32_OBJS= \
	"$(INTDIR)\GUI.obj" \
	"$(INTDIR)\GUIDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\GUI.res"

"$(OUTDIR)\GUI.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "GUI - Win32 Debug"

OUTDIR=.\..\output
INTDIR=.\..\output
# Begin Custom Macros
OutDir=.\..\output
# End Custom Macros

ALL : "$(OUTDIR)\Kuvempu.exe" "$(OUTDIR)\GUI.bsc"


CLEAN :
	-@erase "$(INTDIR)\GUI.obj"
	-@erase "$(INTDIR)\GUI.pch"
	-@erase "$(INTDIR)\GUI.res"
	-@erase "$(INTDIR)\GUI.sbr"
	-@erase "$(INTDIR)\GUIDlg.obj"
	-@erase "$(INTDIR)\GUIDlg.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\GUI.bsc"
	-@erase "$(OUTDIR)\Kuvempu.exe"
	-@erase "$(OUTDIR)\Kuvempu.ilk"
	-@erase "$(OUTDIR)\Kuvempu.map"
	-@erase "$(OUTDIR)\Kuvempu.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\GUI.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\GUI.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\GUI.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\GUI.sbr" \
	"$(INTDIR)\GUIDlg.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\GUI.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=..\output\Netravathi.lib /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\Kuvempu.pdb" /map:"$(INTDIR)\Kuvempu.map" /debug /machine:I386 /out:"$(OUTDIR)\Kuvempu.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\GUI.obj" \
	"$(INTDIR)\GUIDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\GUI.res"

"$(OUTDIR)\Kuvempu.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("GUI.dep")
!INCLUDE "GUI.dep"
!ELSE 
!MESSAGE Warning: cannot find "GUI.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "GUI - Win32 Release" || "$(CFG)" == "GUI - Win32 Debug"
SOURCE=.\GUI.cpp

!IF  "$(CFG)" == "GUI - Win32 Release"


"$(INTDIR)\GUI.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\GUI.pch"


!ELSEIF  "$(CFG)" == "GUI - Win32 Debug"


"$(INTDIR)\GUI.obj"	"$(INTDIR)\GUI.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\GUI.pch"


!ENDIF 

SOURCE=.\GUI.rc

"$(INTDIR)\GUI.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\GUIDlg.cpp

!IF  "$(CFG)" == "GUI - Win32 Release"


"$(INTDIR)\GUIDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\GUI.pch"


!ELSEIF  "$(CFG)" == "GUI - Win32 Debug"


"$(INTDIR)\GUIDlg.obj"	"$(INTDIR)\GUIDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\GUI.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "GUI - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\GUI.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\GUI.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "GUI - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\GUI.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\GUI.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

