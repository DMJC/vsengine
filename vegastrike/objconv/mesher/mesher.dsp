# Microsoft Developer Studio Project File - Name="mesher" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=mesher - Win32 Debug OGRE
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "mesher.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "mesher.mak" CFG="mesher - Win32 Debug OGRE"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "mesher - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "mesher - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE "mesher - Win32 Release OGRE" (based on "Win32 (x86) Console Application")
!MESSAGE "mesher - Win32 Debug OGRE" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "mesher - Win32 Release"

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
# ADD CPP /nologo /MD /W3 /GX /O2 /I "..\..\src" /I "..\.." /I "..\..\..\vega-proj" /I "..\..\..\vega-proj\include" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# SUBTRACT CPP /WX
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib expat.lib /nologo /subsystem:console /machine:I386 /out:"..\..\..\data4.x\bin\mesher.exe"
# SUBTRACT LINK32 /debug

!ELSEIF  "$(CFG)" == "mesher - Win32 Debug"

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
# ADD CPP /nologo /MDd /w /W0 /Gm /GX /ZI /Od /I "..\..\src" /I "..\.." /I "..\..\..\vega-proj" /I "..\..\..\vega-proj\include" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /Zm500 /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib expat.lib /nologo /subsystem:console /debug /machine:I386 /out:"..\..\..\data4.x\bin\mesher_d.exe" /pdbtype:sept

!ELSEIF  "$(CFG)" == "mesher - Win32 Release OGRE"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "mesher___Win32_Release_OGRE"
# PROP BASE Intermediate_Dir "mesher___Win32_Release_OGRE"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "mesher___Win32_Release_OGRE"
# PROP Intermediate_Dir "mesher___Win32_Release_OGRE"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /I "..\..\src" /I "..\.." /I "..\..\..\vega-proj" /I "..\..\..\vega-proj\include" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# SUBTRACT BASE CPP /WX
# ADD CPP /nologo /MD /W3 /GX /O2 /I "..\..\src" /I "..\.." /I "..\..\..\vega-proj" /I "..\..\..\vega-proj\include" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /D "HAVE_OGRE" /YX /FD /c
# SUBTRACT CPP /WX
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib OgreMain.lib /nologo /subsystem:console /machine:I386 /out:"..\..\..\data4.x\bin\mesher.exe" /libpath:"$(OGRE_HOME)\lib" /libpath:"$(STLPORT_LIBS)"
# SUBTRACT BASE LINK32 /debug
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib expat.lib OgreMain.lib /nologo /subsystem:console /machine:I386 /out:"..\..\..\data4.x\bin\mesher.exe" /libpath:"$(OGRE_HOME)\lib" /libpath:"$(STLPORT_LIBS)"
# SUBTRACT LINK32 /debug

!ELSEIF  "$(CFG)" == "mesher - Win32 Debug OGRE"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "mesher___Win32_Debug_OGRE"
# PROP BASE Intermediate_Dir "mesher___Win32_Debug_OGRE"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "mesher___Win32_Debug_OGRE"
# PROP Intermediate_Dir "mesher___Win32_Debug_OGRE"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /w /W0 /Gm /GX /ZI /Od /I "$(OGRE_HOME)\include" /I "$(STLPORT_INCLUDE)" /I "..\..\src" /I "..\.." /I "..\..\..\vega-proj" /I "..\..\..\vega-proj\include" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /Zm500 /c
# ADD CPP /nologo /MDd /w /W0 /Gm /GX /ZI /Od /I "$(OGRE_HOME)\include" /I "$(STLPORT_INCLUDE)" /I "..\..\src" /I "..\.." /I "..\..\..\vega-proj" /I "..\..\..\vega-proj\include" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "HAVE_OGRE" /YX /FD /GZ /Zm500 /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib expat.lib OgreMain_d.lib /nologo /subsystem:console /debug /machine:I386 /out:"..\..\..\data4.x\bin\mesher_d.exe" /pdbtype:sept /libpath:"$(OGRE_HOME)\lib" /libpath:"$(STLPORT_LIBS)"
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib expat.lib OgreMain_d.lib /nologo /subsystem:console /debug /machine:I386 /out:"..\..\..\data4.x\bin\mesher_d.exe" /pdbtype:sept /libpath:"$(OGRE_HOME)\lib" /libpath:"$(STLPORT_LIBS)"

!ENDIF 

# Begin Target

# Name "mesher - Win32 Release"
# Name "mesher - Win32 Debug"
# Name "mesher - Win32 Release OGRE"
# Name "mesher - Win32 Debug OGRE"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\converter.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\endianness.cpp
# End Source File
# Begin Source File

SOURCE=.\from_BFXM.cpp
# End Source File
# Begin Source File

SOURCE=.\from_obj.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\hashtable.cpp
# End Source File
# Begin Source File

SOURCE=.\to_BFXM.cpp
# End Source File
# Begin Source File

SOURCE=.\to_obj.cpp
# End Source File
# Begin Source File

SOURCE=.\to_OgreMesh.cpp

!IF  "$(CFG)" == "mesher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "mesher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "mesher - Win32 Release OGRE"

!ELSEIF  "$(CFG)" == "mesher - Win32 Debug OGRE"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\src\xml_support.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\endianness.h
# End Source File
# Begin Source File

SOURCE=.\expat.h
# End Source File
# Begin Source File

SOURCE=.\from_BFXM.h
# End Source File
# Begin Source File

SOURCE=.\from_obj.h
# End Source File
# Begin Source File

SOURCE=.\hashtable.h
# End Source File
# Begin Source File

SOURCE=.\mesh_io.h
# End Source File
# Begin Source File

SOURCE=.\to_BFXM.h
# End Source File
# Begin Source File

SOURCE=.\to_obj.h
# End Source File
# Begin Source File

SOURCE=.\to_OgreMesh.h

!IF  "$(CFG)" == "mesher - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "mesher - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "mesher - Win32 Release OGRE"

!ELSEIF  "$(CFG)" == "mesher - Win32 Debug OGRE"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\xml_support.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# Begin Source File

SOURCE=.\expat.lib
# End Source File
# End Target
# End Project
