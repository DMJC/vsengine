# Microsoft Developer Studio Generated NMAKE File, Based on mission.dsp
!IF "$(CFG)" == ""
CFG=mission - Win32 Debug
!MESSAGE No configuration specified. Defaulting to mission - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "mission - Win32 Release" && "$(CFG)" != "mission - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "mission.mak" CFG="mission - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "mission - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "mission - Win32 Debug" (based on "Win32 (x86) Console Application")
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

!IF  "$(CFG)" == "mission - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release

ALL : "..\..\data\Mission Selector.exe"


CLEAN :
	-@erase "$(INTDIR)\central.obj"
	-@erase "$(INTDIR)\display_gtk.obj"
	-@erase "$(INTDIR)\easydom.obj"
	-@erase "$(INTDIR)\file.obj"
	-@erase "$(INTDIR)\general.obj"
	-@erase "$(INTDIR)\hashtable.obj"
	-@erase "$(INTDIR)\select.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\xml_support.obj"
	-@erase "..\..\data\Mission Selector.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /GX /O2 /I "..\vssetup\libs\gdk\\" /I "..\vssetup\libs\\" /I "..\include\\" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\mission.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mission.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib libpng2.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib glib-1.3.lib gdk-1.3.lib gtk-1.3.lib gspawn-win32-helper.lib expat.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\Mission Selector.pdb" /machine:I386 /out:"..\..\data\Mission Selector.exe" /libpath:"libs\\" /libpath:"..\lib\\" /libpath:"..\..\vegastrike\vc98" 
LINK32_OBJS= \
	"$(INTDIR)\central.obj" \
	"$(INTDIR)\display_gtk.obj" \
	"$(INTDIR)\easydom.obj" \
	"$(INTDIR)\file.obj" \
	"$(INTDIR)\general.obj" \
	"$(INTDIR)\hashtable.obj" \
	"$(INTDIR)\select.obj" \
	"$(INTDIR)\xml_support.obj"

"..\..\data\Mission Selector.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "mission - Win32 Debug"

OUTDIR=.\mission___Win32_Debug
INTDIR=.\mission___Win32_Debug

ALL : "..\..\data\Mission Selector.exe"


CLEAN :
	-@erase "$(INTDIR)\central.obj"
	-@erase "$(INTDIR)\display_gtk.obj"
	-@erase "$(INTDIR)\easydom.obj"
	-@erase "$(INTDIR)\file.obj"
	-@erase "$(INTDIR)\general.obj"
	-@erase "$(INTDIR)\hashtable.obj"
	-@erase "$(INTDIR)\select.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\xml_support.obj"
	-@erase "$(OUTDIR)\Mission Selector.pdb"
	-@erase "..\..\data\Mission Selector.exe"
	-@erase "..\..\data\Mission Selector.ilk"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /Gm /GX /ZI /Od /I "..\vssetup\libs\gdk\\" /I "..\vssetup\libs\\" /I "..\include\\" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\mission.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mission.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib libpng2.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib glib-1.3.lib gdk-1.3.lib gtk-1.3.lib gspawn-win32-helper.lib expat.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\Mission Selector.pdb" /debug /machine:I386 /out:"..\..\data\Mission Selector.exe" /pdbtype:sept /libpath:"libs\\" /libpath:"..\lib\\" /libpath:"..\..\vegastrike\vc98" 
LINK32_OBJS= \
	"$(INTDIR)\central.obj" \
	"$(INTDIR)\display_gtk.obj" \
	"$(INTDIR)\easydom.obj" \
	"$(INTDIR)\file.obj" \
	"$(INTDIR)\general.obj" \
	"$(INTDIR)\hashtable.obj" \
	"$(INTDIR)\select.obj" \
	"$(INTDIR)\xml_support.obj"

"..\..\data\Mission Selector.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("mission.dep")
!INCLUDE "mission.dep"
!ELSE 
!MESSAGE Warning: cannot find "mission.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "mission - Win32 Release" || "$(CFG)" == "mission - Win32 Debug"
SOURCE=..\..\vegastrike\src\mission\include\central.cpp

"$(INTDIR)\central.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\mission\include\display_gtk.cpp

"$(INTDIR)\display_gtk.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\mission\include\easydom.cpp

"$(INTDIR)\easydom.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\mission\include\file.cpp

"$(INTDIR)\file.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\mission\include\general.cpp

"$(INTDIR)\general.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\mission\include\hashtable.cpp

"$(INTDIR)\hashtable.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\mission\c\select.cpp

"$(INTDIR)\select.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\mission\include\xml_support.cpp

"$(INTDIR)\xml_support.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)



!ENDIF 

