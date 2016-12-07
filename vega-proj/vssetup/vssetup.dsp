# Microsoft Developer Studio Project File - Name="vssetup" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=vssetup - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "vssetup.mak".
!MESSAGE 
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

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "vssetup - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /I "..\vssetup\libs\\" /I "..\vssetup\libs\gdk\\" /D "NDEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /D "_G_ALL" /D "GTK" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib glib-1.3.lib gdk-1.3.lib gtk-1.3.lib gspawn-win32-helper.lib expat.lib /nologo /subsystem:console /machine:I386 /out:"..\..\data4.x\bin\Setup.exe" /libpath:"libs\\" /libpath:"..\lib\\" /libpath:"..\..\vegastrike\vc98"

!ELSEIF  "$(CFG)" == "vssetup - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /I "..\vssetup\libs\gdk\\" /I "..\vssetup\libs\\" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /D "_G_ALL" /D "GTK" /FR /YX /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib glib-1.3.lib gdk-1.3.lib gtk-1.3.lib gspawn-win32-helper.lib glib-1.3.lib /nologo /subsystem:console /debug /machine:I386 /out:"..\..\data4.x\bin\Setup.exe" /pdbtype:sept /libpath:"libs\\" /libpath:"..\lib\\" /libpath:"..\..\vegastrike\vc98"

!ENDIF 

# Begin Target

# Name "vssetup - Win32 Release"
# Name "vssetup - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\..\vegastrike\setup\src\include\central.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\setup\src\include\display_gtk.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\setup\src\include\file.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\setup\src\include\general.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\setup\src\c\setup.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\setup\vega.rc
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\..\vegastrike\setup\src\include\central.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\setup\src\include\display_gtk.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\setup\src\include\file.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\setup\src\include\general.h
# End Source File
# Begin Source File

SOURCE=.\resource.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\icon1.ico
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\setup\icon1.ico
# End Source File
# End Group
# End Target
# End Project
