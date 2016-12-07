# Microsoft Developer Studio Generated NMAKE File, Based on vssetup.dsp
!IF "$(CFG)" == ""
CFG=vssetup - Win32 Debug
!MESSAGE No configuration specified. Defaulting to vssetup - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "vssetup - Win32 Release" && "$(CFG)" != "vssetup - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "vssetup.mak" CFG="vssetup - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "vssetup - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "vssetup - Win32 Debug" (based on "Win32 (x86) Console Application")
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

!IF  "$(CFG)" == "vssetup - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release

ALL : "..\..\data\Setup.exe"


CLEAN :
	-@erase "$(INTDIR)\central.obj"
	-@erase "$(INTDIR)\display_gtk.obj"
	-@erase "$(INTDIR)\file.obj"
	-@erase "$(INTDIR)\general.obj"
	-@erase "$(INTDIR)\setup.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vega.res"
	-@erase "..\..\data\Setup.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /GX /O2 /I "..\vssetup\libs\\" /I "..\vssetup\libs\gdk\\" /D "NDEBUG" /D "_G_ALL" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\vssetup.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\vega.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\vssetup.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib glib-1.3.lib gdk-1.3.lib gtk-1.3.lib gspawn-win32-helper.lib expat.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\Setup.pdb" /machine:I386 /out:"..\..\data\Setup.exe" /libpath:"libs\\" /libpath:"..\lib\\" /libpath:"..\..\vegastrike\vc98" 
LINK32_OBJS= \
	"$(INTDIR)\central.obj" \
	"$(INTDIR)\display_gtk.obj" \
	"$(INTDIR)\file.obj" \
	"$(INTDIR)\general.obj" \
	"$(INTDIR)\setup.obj" \
	"$(INTDIR)\vega.res"

"..\..\data\Setup.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "vssetup - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "..\..\data\Setup.exe" "$(OUTDIR)\vssetup.bsc"


CLEAN :
	-@erase "$(INTDIR)\central.obj"
	-@erase "$(INTDIR)\central.sbr"
	-@erase "$(INTDIR)\display_gtk.obj"
	-@erase "$(INTDIR)\display_gtk.sbr"
	-@erase "$(INTDIR)\file.obj"
	-@erase "$(INTDIR)\file.sbr"
	-@erase "$(INTDIR)\general.obj"
	-@erase "$(INTDIR)\general.sbr"
	-@erase "$(INTDIR)\setup.obj"
	-@erase "$(INTDIR)\setup.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\vega.res"
	-@erase "$(OUTDIR)\Setup.pdb"
	-@erase "$(OUTDIR)\vssetup.bsc"
	-@erase "..\..\data\Setup.exe"
	-@erase "..\..\data\Setup.ilk"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /I "..\vssetup\libs\gdk\\" /I "..\vssetup\libs\\" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /D "_G_ALL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\vssetup.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\vega.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\vssetup.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\central.sbr" \
	"$(INTDIR)\display_gtk.sbr" \
	"$(INTDIR)\file.sbr" \
	"$(INTDIR)\general.sbr" \
	"$(INTDIR)\setup.sbr"

"$(OUTDIR)\vssetup.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib glib-1.3.lib gdk-1.3.lib gtk-1.3.lib gspawn-win32-helper.lib glib-1.3.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\Setup.pdb" /debug /machine:I386 /out:"..\..\data\Setup.exe" /pdbtype:sept /libpath:"libs\\" /libpath:"..\lib\\" /libpath:"..\..\vegastrike\vc98" 
LINK32_OBJS= \
	"$(INTDIR)\central.obj" \
	"$(INTDIR)\display_gtk.obj" \
	"$(INTDIR)\file.obj" \
	"$(INTDIR)\general.obj" \
	"$(INTDIR)\setup.obj" \
	"$(INTDIR)\vega.res"

"..\..\data\Setup.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("vssetup.dep")
!INCLUDE "vssetup.dep"
!ELSE 
!MESSAGE Warning: cannot find "vssetup.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "vssetup - Win32 Release" || "$(CFG)" == "vssetup - Win32 Debug"
SOURCE=..\..\vssetup\src\include\central.cpp

!IF  "$(CFG)" == "vssetup - Win32 Release"


"$(INTDIR)\central.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "vssetup - Win32 Debug"


"$(INTDIR)\central.obj"	"$(INTDIR)\central.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\vssetup\src\include\display_gtk.cpp

!IF  "$(CFG)" == "vssetup - Win32 Release"


"$(INTDIR)\display_gtk.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "vssetup - Win32 Debug"


"$(INTDIR)\display_gtk.obj"	"$(INTDIR)\display_gtk.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\vssetup\src\include\file.cpp

!IF  "$(CFG)" == "vssetup - Win32 Release"


"$(INTDIR)\file.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "vssetup - Win32 Debug"


"$(INTDIR)\file.obj"	"$(INTDIR)\file.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\vssetup\src\include\general.c

!IF  "$(CFG)" == "vssetup - Win32 Release"


"$(INTDIR)\general.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "vssetup - Win32 Debug"


"$(INTDIR)\general.obj"	"$(INTDIR)\general.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\vssetup\src\c\setup.cpp

!IF  "$(CFG)" == "vssetup - Win32 Release"


"$(INTDIR)\setup.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "vssetup - Win32 Debug"


"$(INTDIR)\setup.obj"	"$(INTDIR)\setup.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\vssetup\vega.rc

!IF  "$(CFG)" == "vssetup - Win32 Release"


"$(INTDIR)\vega.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x409 /fo"$(INTDIR)\vega.res" /i "\Programming\Vegastrike\vssetup" /d "NDEBUG" $(SOURCE)


!ELSEIF  "$(CFG)" == "vssetup - Win32 Debug"


"$(INTDIR)\vega.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x409 /fo"$(INTDIR)\vega.res" /i "\Programming\Vegastrike\vssetup" /d "_DEBUG" $(SOURCE)


!ENDIF 


!ENDIF 

