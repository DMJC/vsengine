# Microsoft Developer Studio Generated NMAKE File, Based on AsterGet.dsp
!IF "$(CFG)" == ""
CFG=AsterGet - Win32 Debug
!MESSAGE No configuration specified. Defaulting to AsterGet - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "AsterGet - Win32 Release" && "$(CFG)" != "AsterGet - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "AsterGet.mak" CFG="AsterGet - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "AsterGet - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "AsterGet - Win32 Debug" (based on "Win32 (x86) Console Application")
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

!IF  "$(CFG)" == "AsterGet - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release

ALL : "..\..\data\AsterGen.exe"


CLEAN :
	-@erase "$(INTDIR)\asteroidgen.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "..\..\data\AsterGen.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\AsterGet.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\AsterGet.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\AsterGen.pdb" /machine:I386 /out:"..\..\data\AsterGen.exe" 
LINK32_OBJS= \
	"$(INTDIR)\asteroidgen.obj"

"..\..\data\AsterGen.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "AsterGet - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug

ALL : "..\..\data\AsterGen.exe"


CLEAN :
	-@erase "$(INTDIR)\asteroidgen.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\AsterGen.pdb"
	-@erase "..\..\data\AsterGen.exe"
	-@erase "..\..\data\AsterGen.ilk"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\AsterGet.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\AsterGet.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\AsterGen.pdb" /debug /machine:I386 /out:"..\..\data\AsterGen.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\asteroidgen.obj"

"..\..\data\AsterGen.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("AsterGet.dep")
!INCLUDE "AsterGet.dep"
!ELSE 
!MESSAGE Warning: cannot find "AsterGet.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "AsterGet - Win32 Release" || "$(CFG)" == "AsterGet - Win32 Debug"
SOURCE=..\..\vegastrike\objconv\asteroidgen.cpp

"$(INTDIR)\asteroidgen.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)



!ENDIF 

