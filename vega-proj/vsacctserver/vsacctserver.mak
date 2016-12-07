# Microsoft Developer Studio Generated NMAKE File, Based on vsacctserver.dsp
!IF "$(CFG)" == ""
CFG=vsacctserver - Win32 Debug
!MESSAGE No configuration specified. Defaulting to vsacctserver - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "vsacctserver - Win32 Release" && "$(CFG)" != "vsacctserver - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "vsacctserver.mak" CFG="vsacctserver - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "vsacctserver - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "vsacctserver - Win32 Debug" (based on "Win32 (x86) Console Application")
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

!IF  "$(CFG)" == "vsacctserver - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release

ALL : "..\..\data\accountserver.exe"


CLEAN :
	-@erase "$(INTDIR)\accountserver.obj"
	-@erase "$(INTDIR)\accountsxml.obj"
	-@erase "$(INTDIR)\acctserver.obj"
	-@erase "$(INTDIR)\configxml.obj"
	-@erase "$(INTDIR)\easydom.obj"
	-@erase "$(INTDIR)\endianness.obj"
	-@erase "$(INTDIR)\hashtable.obj"
	-@erase "$(INTDIR)\lin_time.obj"
	-@erase "$(INTDIR)\packet.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\xml_support.obj"
	-@erase "..\..\data\accountserver.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /GX /O2 /I "..\..\vegastrike\src" /I "..\Include" /I "..\..\vegastrike\src\boost" /I "..\\" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /D "_UDP_PROTO" /D "YY_NEVER_INTERACTIVE" /D "HAVE_AL" /D "HAVE_SDL" /D "YY_ALWAYS_INTERACTIVE" /D "SDL_WINDOWING" /D "HAVE_BOOST" /D "HAVE_PYTHON" /D "BOOST_DEBUG_PYTHON" /Fp"$(INTDIR)\vsacctserver.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\vsacctserver.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib expat.lib wsock32.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\accountserver.pdb" /machine:I386 /out:"..\..\data\accountserver.exe" /libpath:"..\..\vegastrike\vc98\\" /libpath:"..\include" /libpath:"..\lib" 
LINK32_OBJS= \
	"$(INTDIR)\accountserver.obj" \
	"$(INTDIR)\configxml.obj" \
	"$(INTDIR)\easydom.obj" \
	"$(INTDIR)\endianness.obj" \
	"$(INTDIR)\hashtable.obj" \
	"$(INTDIR)\lin_time.obj" \
	"$(INTDIR)\xml_support.obj" \
	"$(INTDIR)\accountsxml.obj" \
	"$(INTDIR)\acctserver.obj" \
	"$(INTDIR)\packet.obj"

"..\..\data\accountserver.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "vsacctserver - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug

ALL : "..\..\data\accountserver.exe"


CLEAN :
	-@erase "$(INTDIR)\accountserver.obj"
	-@erase "$(INTDIR)\accountsxml.obj"
	-@erase "$(INTDIR)\acctserver.obj"
	-@erase "$(INTDIR)\configxml.obj"
	-@erase "$(INTDIR)\easydom.obj"
	-@erase "$(INTDIR)\endianness.obj"
	-@erase "$(INTDIR)\hashtable.obj"
	-@erase "$(INTDIR)\lin_time.obj"
	-@erase "$(INTDIR)\packet.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\xml_support.obj"
	-@erase "$(OUTDIR)\accountserver.pdb"
	-@erase "..\..\data\accountserver.exe"
	-@erase "..\..\data\accountserver.ilk"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /w /W0 /Gm /GX /ZI /Od /I "..\..\vegastrike\src" /I "..\Include" /I "..\..\vegastrike\src\boost" /I "..\\" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "_UDP_PROTO" /D "YY_NEVER_INTERACTIVE" /D "HAVE_AL" /D "HAVE_SDL" /D "YY_ALWAYS_INTERACTIVE" /D "SDL_WINDOWING" /D "HAVE_BOOST" /D "HAVE_PYTHON" /D "BOOST_DEBUG_PYTHON" /Fp"$(INTDIR)\vsacctserver.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\vsacctserver.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib expat.lib wsock32.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\accountserver.pdb" /debug /machine:I386 /out:"..\..\data\accountserver.exe" /pdbtype:sept /libpath:"..\..\vegastrike\vc98\\" /libpath:"..\include" /libpath:"..\lib" 
LINK32_OBJS= \
	"$(INTDIR)\accountserver.obj" \
	"$(INTDIR)\configxml.obj" \
	"$(INTDIR)\easydom.obj" \
	"$(INTDIR)\endianness.obj" \
	"$(INTDIR)\hashtable.obj" \
	"$(INTDIR)\lin_time.obj" \
	"$(INTDIR)\xml_support.obj" \
	"$(INTDIR)\accountsxml.obj" \
	"$(INTDIR)\acctserver.obj" \
	"$(INTDIR)\packet.obj"

"..\..\data\accountserver.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("vsacctserver.dep")
!INCLUDE "vsacctserver.dep"
!ELSE 
!MESSAGE Warning: cannot find "vsacctserver.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "vsacctserver - Win32 Release" || "$(CFG)" == "vsacctserver - Win32 Debug"
SOURCE=..\..\vegastrike\src\accountserver.cpp

"$(INTDIR)\accountserver.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\configxml.cpp

"$(INTDIR)\configxml.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\easydom.cpp

"$(INTDIR)\easydom.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\endianness.cpp

"$(INTDIR)\endianness.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\hashtable.cpp

"$(INTDIR)\hashtable.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\lin_time.cpp

"$(INTDIR)\lin_time.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\xml_support.cpp

"$(INTDIR)\xml_support.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\networking\accountsxml.cpp

"$(INTDIR)\accountsxml.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\networking\acctserver.cpp

"$(INTDIR)\acctserver.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\networking\packet.cpp

"$(INTDIR)\packet.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)



!ENDIF 

