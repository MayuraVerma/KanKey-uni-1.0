# Microsoft Developer Studio Generated NMAKE File, Based on FinalGUI.dsp
!IF "$(CFG)" == ""
CFG=FinalGUI - Win32 Debug
!MESSAGE No configuration specified. Defaulting to FinalGUI - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "FinalGUI - Win32 Release" && "$(CFG)" != "FinalGUI - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "FinalGUI.mak" CFG="FinalGUI - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "FinalGUI - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "FinalGUI - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "FinalGUI - Win32 Release"

OUTDIR=.\..\output
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\..\output
# End Custom Macros

ALL : "$(OUTDIR)\Kuvempu.exe"


CLEAN :
	-@erase "$(INTDIR)\About.obj"
	-@erase "$(INTDIR)\FinalGUI.obj"
	-@erase "$(INTDIR)\FinalGUI.pch"
	-@erase "$(INTDIR)\FinalGUI.res"
	-@erase "$(INTDIR)\FinalGUIDlg.obj"
	-@erase "$(INTDIR)\Help.obj"
	-@erase "$(INTDIR)\image.obj"
	-@erase "$(INTDIR)\Language.obj"
	-@erase "$(INTDIR)\Layout.obj"
	-@erase "$(INTDIR)\Menu_Cust.obj"
	-@erase "$(INTDIR)\picture.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\Kuvempu.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\FinalGUI.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\FinalGUI.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\FinalGUI.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=..\output\*.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\Kuvempu.pdb" /machine:I386 /out:"$(OUTDIR)\Kuvempu.exe" 
LINK32_OBJS= \
	"$(INTDIR)\About.obj" \
	"$(INTDIR)\FinalGUI.obj" \
	"$(INTDIR)\FinalGUIDlg.obj" \
	"$(INTDIR)\Help.obj" \
	"$(INTDIR)\image.obj" \
	"$(INTDIR)\Language.obj" \
	"$(INTDIR)\Layout.obj" \
	"$(INTDIR)\Menu_Cust.obj" \
	"$(INTDIR)\picture.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\FinalGUI.res"

"$(OUTDIR)\Kuvempu.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "FinalGUI - Win32 Debug"

OUTDIR=.\..\output
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\..\output
# End Custom Macros

ALL : "$(OUTDIR)\Sample.exe" "$(OUTDIR)\FinalGUI.bsc"


CLEAN :
	-@erase "$(INTDIR)\About.obj"
	-@erase "$(INTDIR)\About.sbr"
	-@erase "$(INTDIR)\FinalGUI.obj"
	-@erase "$(INTDIR)\FinalGUI.pch"
	-@erase "$(INTDIR)\FinalGUI.res"
	-@erase "$(INTDIR)\FinalGUI.sbr"
	-@erase "$(INTDIR)\FinalGUIDlg.obj"
	-@erase "$(INTDIR)\FinalGUIDlg.sbr"
	-@erase "$(INTDIR)\Help.obj"
	-@erase "$(INTDIR)\Help.sbr"
	-@erase "$(INTDIR)\image.obj"
	-@erase "$(INTDIR)\image.sbr"
	-@erase "$(INTDIR)\Language.obj"
	-@erase "$(INTDIR)\Language.sbr"
	-@erase "$(INTDIR)\Layout.obj"
	-@erase "$(INTDIR)\Layout.sbr"
	-@erase "$(INTDIR)\Menu_Cust.obj"
	-@erase "$(INTDIR)\Menu_Cust.sbr"
	-@erase "$(INTDIR)\picture.obj"
	-@erase "$(INTDIR)\picture.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\FinalGUI.bsc"
	-@erase "$(OUTDIR)\Sample.exe"
	-@erase "$(OUTDIR)\Sample.ilk"
	-@erase "$(OUTDIR)\Sample.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\FinalGUI.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\FinalGUI.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\FinalGUI.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\About.sbr" \
	"$(INTDIR)\FinalGUI.sbr" \
	"$(INTDIR)\FinalGUIDlg.sbr" \
	"$(INTDIR)\Help.sbr" \
	"$(INTDIR)\image.sbr" \
	"$(INTDIR)\Language.sbr" \
	"$(INTDIR)\Layout.sbr" \
	"$(INTDIR)\Menu_Cust.sbr" \
	"$(INTDIR)\picture.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\FinalGUI.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=..\output\*.lib /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\Sample.pdb" /debug /machine:I386 /out:"$(OUTDIR)\Sample.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\About.obj" \
	"$(INTDIR)\FinalGUI.obj" \
	"$(INTDIR)\FinalGUIDlg.obj" \
	"$(INTDIR)\Help.obj" \
	"$(INTDIR)\image.obj" \
	"$(INTDIR)\Language.obj" \
	"$(INTDIR)\Layout.obj" \
	"$(INTDIR)\Menu_Cust.obj" \
	"$(INTDIR)\picture.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\FinalGUI.res"

"$(OUTDIR)\Sample.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("FinalGUI.dep")
!INCLUDE "FinalGUI.dep"
!ELSE 
!MESSAGE Warning: cannot find "FinalGUI.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "FinalGUI - Win32 Release" || "$(CFG)" == "FinalGUI - Win32 Debug"
SOURCE=.\About.cpp

!IF  "$(CFG)" == "FinalGUI - Win32 Release"


"$(INTDIR)\About.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\FinalGUI.pch"


!ELSEIF  "$(CFG)" == "FinalGUI - Win32 Debug"


"$(INTDIR)\About.obj"	"$(INTDIR)\About.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\FinalGUI.pch"


!ENDIF 

SOURCE=.\FinalGUI.cpp

!IF  "$(CFG)" == "FinalGUI - Win32 Release"


"$(INTDIR)\FinalGUI.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\FinalGUI.pch"


!ELSEIF  "$(CFG)" == "FinalGUI - Win32 Debug"


"$(INTDIR)\FinalGUI.obj"	"$(INTDIR)\FinalGUI.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\FinalGUI.pch"


!ENDIF 

SOURCE=.\FinalGUI.rc

"$(INTDIR)\FinalGUI.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\FinalGUIDlg.cpp

!IF  "$(CFG)" == "FinalGUI - Win32 Release"


"$(INTDIR)\FinalGUIDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\FinalGUI.pch"


!ELSEIF  "$(CFG)" == "FinalGUI - Win32 Debug"


"$(INTDIR)\FinalGUIDlg.obj"	"$(INTDIR)\FinalGUIDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\FinalGUI.pch"


!ENDIF 

SOURCE=.\Help.cpp

!IF  "$(CFG)" == "FinalGUI - Win32 Release"


"$(INTDIR)\Help.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\FinalGUI.pch"


!ELSEIF  "$(CFG)" == "FinalGUI - Win32 Debug"


"$(INTDIR)\Help.obj"	"$(INTDIR)\Help.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\FinalGUI.pch"


!ENDIF 

SOURCE=.\image.cpp

!IF  "$(CFG)" == "FinalGUI - Win32 Release"


"$(INTDIR)\image.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\FinalGUI.pch"


!ELSEIF  "$(CFG)" == "FinalGUI - Win32 Debug"


"$(INTDIR)\image.obj"	"$(INTDIR)\image.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\FinalGUI.pch"


!ENDIF 

SOURCE=.\Language.cpp

!IF  "$(CFG)" == "FinalGUI - Win32 Release"


"$(INTDIR)\Language.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\FinalGUI.pch"


!ELSEIF  "$(CFG)" == "FinalGUI - Win32 Debug"


"$(INTDIR)\Language.obj"	"$(INTDIR)\Language.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\FinalGUI.pch"


!ENDIF 

SOURCE=.\Layout.cpp

!IF  "$(CFG)" == "FinalGUI - Win32 Release"


"$(INTDIR)\Layout.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\FinalGUI.pch"


!ELSEIF  "$(CFG)" == "FinalGUI - Win32 Debug"


"$(INTDIR)\Layout.obj"	"$(INTDIR)\Layout.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\FinalGUI.pch"


!ENDIF 

SOURCE=.\Menu_Cust.cpp

!IF  "$(CFG)" == "FinalGUI - Win32 Release"


"$(INTDIR)\Menu_Cust.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\FinalGUI.pch"


!ELSEIF  "$(CFG)" == "FinalGUI - Win32 Debug"


"$(INTDIR)\Menu_Cust.obj"	"$(INTDIR)\Menu_Cust.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\FinalGUI.pch"


!ENDIF 

SOURCE=.\picture.cpp

!IF  "$(CFG)" == "FinalGUI - Win32 Release"


"$(INTDIR)\picture.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\FinalGUI.pch"


!ELSEIF  "$(CFG)" == "FinalGUI - Win32 Debug"


"$(INTDIR)\picture.obj"	"$(INTDIR)\picture.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\FinalGUI.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "FinalGUI - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\FinalGUI.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\FinalGUI.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "FinalGUI - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\FinalGUI.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\FinalGUI.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

