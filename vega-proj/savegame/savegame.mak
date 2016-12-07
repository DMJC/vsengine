# Microsoft Developer Studio Generated NMAKE File, Based on savegame.dsp
!IF "$(CFG)" == ""
CFG=savegame - Win32 Debug
!MESSAGE No configuration specified. Defaulting to savegame - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "savegame - Win32 Release" && "$(CFG)" != "savegame - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "savegame.mak" CFG="savegame - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "savegame - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "savegame - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "savegame - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release

ALL : "..\..\data\Launcher.exe"


CLEAN :
	-@erase "$(INTDIR)\console.obj"
	-@erase "$(INTDIR)\general.obj"
	-@erase "$(INTDIR)\launcher.res"
	-@erase "$(INTDIR)\saveinterface.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "..\..\data\Launcher.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /GX /O2 /I "..\vssetup\libs\\" /I "..\vssetup\libs\gdk\\" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\savegame.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\launcher.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\savegame.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib glib-1.3.lib gdk-1.3.lib gtk-1.3.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\Launcher.pdb" /machine:I386 /out:"..\..\data\Launcher.exe" /libpath:"..\..\vegastrike\vc98\\" /libpath:"..\lib" /libpath:"..\vssetup\libs\\" 
LINK32_OBJS= \
	"$(INTDIR)\console.obj" \
	"$(INTDIR)\general.obj" \
	"$(INTDIR)\saveinterface.obj" \
	"$(INTDIR)\launcher.res"

"..\..\data\Launcher.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "savegame - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "..\..\data\Launcher.exe" "$(OUTDIR)\savegame.bsc"


CLEAN :
	-@erase "$(INTDIR)\console.obj"
	-@erase "$(INTDIR)\console.sbr"
	-@erase "$(INTDIR)\general.obj"
	-@erase "$(INTDIR)\general.sbr"
	-@erase "$(INTDIR)\launcher.res"
	-@erase "$(INTDIR)\saveinterface.obj"
	-@erase "$(INTDIR)\saveinterface.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\Launcher.pdb"
	-@erase "$(OUTDIR)\savegame.bsc"
	-@erase "..\..\data\Launcher.exe"
	-@erase "..\..\data\Launcher.ilk"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /I "..\vssetup\libs\\" /I "..\vssetup\libs\gdk\\" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\savegame.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\launcher.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\savegame.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\console.sbr" \
	"$(INTDIR)\general.sbr" \
	"$(INTDIR)\saveinterface.sbr"

"$(OUTDIR)\savegame.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib glib-1.3.lib gdk-1.3.lib gtk-1.3.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\Launcher.pdb" /debug /machine:I386 /out:"..\..\data\Launcher.exe" /pdbtype:sept /libpath:"..\..\vegastrike\vc98\\" /libpath:"..\lib" /libpath:"..\vssetup\libs\\" 
LINK32_OBJS= \
	"$(INTDIR)\console.obj" \
	"$(INTDIR)\general.obj" \
	"$(INTDIR)\saveinterface.obj" \
	"$(INTDIR)\launcher.res"

"..\..\data\Launcher.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("savegame.dep")
!INCLUDE "savegame.dep"
!ELSE 
!MESSAGE Warning: cannot find "savegame.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "savegame - Win32 Release" || "$(CFG)" == "savegame - Win32 Debug"
SOURCE=.\console.cpp

!IF  "$(CFG)" == "savegame - Win32 Release"


"$(INTDIR)\console.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "savegame - Win32 Debug"


"$(INTDIR)\console.obj"	"$(INTDIR)\console.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=..\saveinterface\general.cpp

!IF  "$(CFG)" == "savegame - Win32 Release"


"$(INTDIR)\general.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "savegame - Win32 Debug"


"$(INTDIR)\general.obj"	"$(INTDIR)\general.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\vegastrike\launcher\launcher.rc

!IF  "$(CFG)" == "savegame - Win32 Release"


"$(INTDIR)\launcher.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x409 /fo"$(INTDIR)\launcher.res" /i "\Programming\Vegastrike\vegastrike\launcher" /d "NDEBUG" $(SOURCE)


!ELSEIF  "$(CFG)" == "savegame - Win32 Debug"


"$(INTDIR)\launcher.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x409 /fo"$(INTDIR)\launcher.res" /i "\Programming\Vegastrike\vegastrike\launcher" /d "_DEBUG" $(SOURCE)


!ENDIF 

SOURCE=..\..\vegastrike\launcher\saveinterface.cpp

!IF  "$(CFG)" == "savegame - Win32 Release"


"$(INTDIR)\saveinterface.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "savegame - Win32 Debug"


"$(INTDIR)\saveinterface.obj"	"$(INTDIR)\saveinterface.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 


!ENDIF 

