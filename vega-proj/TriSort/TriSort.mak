# Microsoft Developer Studio Generated NMAKE File, Based on TriSort.dsp
!IF "$(CFG)" == ""
CFG=TriSort - Win32 Debug
!MESSAGE No configuration specified. Defaulting to TriSort - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "TriSort - Win32 Release" && "$(CFG)" != "TriSort - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "TriSort.mak" CFG="TriSort - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "TriSort - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "TriSort - Win32 Debug" (based on "Win32 (x86) Console Application")
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

!IF  "$(CFG)" == "TriSort - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release

ALL : "..\..\data\TriSort.exe"


CLEAN :
	-@erase "$(INTDIR)\trisort.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "..\..\data\TriSort.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\TriSort.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\TriSort.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\TriSort.pdb" /machine:I386 /out:"..\..\data\TriSort.exe" 
LINK32_OBJS= \
	"$(INTDIR)\trisort.obj"

"..\..\data\TriSort.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "TriSort - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug

ALL : "..\..\data\TriSort.exe"


CLEAN :
	-@erase "$(INTDIR)\trisort.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\TriSort.pdb"
	-@erase "..\..\data\TriSort.exe"
	-@erase "..\..\data\TriSort.ilk"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\TriSort.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\TriSort.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\TriSort.pdb" /debug /machine:I386 /out:"..\..\data\TriSort.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\trisort.obj"

"..\..\data\TriSort.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("TriSort.dep")
!INCLUDE "TriSort.dep"
!ELSE 
!MESSAGE Warning: cannot find "TriSort.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "TriSort - Win32 Release" || "$(CFG)" == "TriSort - Win32 Debug"
SOURCE=..\..\vegastrike\objconv\trisort.cpp

"$(INTDIR)\trisort.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)



!ENDIF 

