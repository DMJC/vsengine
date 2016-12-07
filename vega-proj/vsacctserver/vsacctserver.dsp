# Microsoft Developer Studio Project File - Name="vsacctserver" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=vsacctserver - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "vsacctserver.mak".
!MESSAGE 
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

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "vsacctserver - Win32 Release"

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
# ADD CPP /nologo /GX /O2 /I "..\..\vegastrike\src" /I "..\Include" /I "..\..\vegastrike\src\boost" /I "..\\" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /D "_UDP_PROTO" /D "YY_NEVER_INTERACTIVE" /D "HAVE_AL" /D "HAVE_SDL" /D "YY_ALWAYS_INTERACTIVE" /D "SDL_WINDOWING" /D "HAVE_BOOST" /D "HAVE_PYTHON" /D "BOOST_DEBUG_PYTHON" /YX /FD /c
# ADD BASE RSC /l 0x40c /d "NDEBUG"
# ADD RSC /l 0x40c /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib expat.lib wsock32.lib zlib.lib /nologo /subsystem:console /machine:I386 /out:"..\..\data4.x\bin\accountserver.exe" /libpath:"..\..\vegastrike\vc98\\" /libpath:"..\include" /libpath:"..\lib"

!ELSEIF  "$(CFG)" == "vsacctserver - Win32 Debug"

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
# ADD CPP /nologo /w /W0 /Gm /GX /ZI /Od /I "..\..\vegastrike\src" /I "..\Include" /I "..\..\vegastrike\src\boost" /I "..\\" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "_UDP_PROTO" /D "YY_NEVER_INTERACTIVE" /D "HAVE_AL" /D "HAVE_SDL" /D "YY_ALWAYS_INTERACTIVE" /D "SDL_WINDOWING" /D "HAVE_BOOST" /D "HAVE_PYTHON" /D "BOOST_DEBUG_PYTHON" /YX /FD /GZ /c
# ADD BASE RSC /l 0x40c /d "_DEBUG"
# ADD RSC /l 0x40c /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib expat.lib wsock32.lib zlib.lib /nologo /subsystem:console /debug /machine:I386 /out:"..\..\data4.x\bin\accountserverd.exe" /pdbtype:sept /libpath:"..\..\vegastrike\vc98\\" /libpath:"..\include" /libpath:"..\lib"
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "vsacctserver - Win32 Release"
# Name "vsacctserver - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\..\vegastrike\src\accountserver.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\configxml.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\easydom.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\endianness.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\hashtable.cpp
# End Source File
# Begin Source File

SOURCE=..\src\libserver.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\lin_time.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\pk3.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\posh.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\SharedPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\vsfilesystem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\xml_support.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\..\vegastrike\src\easydom.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\endianness.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\hashtable.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\lin_time.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\xml_support.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=..\cursor1.cur
# End Source File
# Begin Source File

SOURCE=..\icon2.ico
# End Source File
# Begin Source File

SOURCE=..\icon3.ico
# End Source File
# Begin Source File

SOURCE=..\vega.ico
# End Source File
# End Group
# Begin Group "networking"

# PROP Default_Filter ""
# Begin Group "lowlevel"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\lowlevel\GCPtr.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\lowlevel\netbuffer.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\lowlevel\netbuffer.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\lowlevel\netui.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\lowlevel\packet.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\lowlevel\packet.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\lowlevel\packetmem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\lowlevel\vsnet_address.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\lowlevel\vsnet_clientstate.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\lowlevel\vsnet_clientstate.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\lowlevel\vsnet_cmd.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\lowlevel\vsnet_debug.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\lowlevel\vsnet_dloadenum.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\lowlevel\vsnet_dloadmgr.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\lowlevel\vsnet_notify.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\lowlevel\vsnet_notify.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\lowlevel\vsnet_oss.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\lowlevel\vsnet_parsecmd.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\lowlevel\vsnet_parsecmd.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\lowlevel\vsnet_pipe.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\lowlevel\vsnet_queue.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\lowlevel\vsnet_serversocket.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\lowlevel\vsnet_serversocket.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\lowlevel\vsnet_socket.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\lowlevel\vsnet_socketbase.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\lowlevel\vsnet_socketflags.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\lowlevel\vsnet_sockethttp.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\lowlevel\vsnet_sockethttp.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\lowlevel\vsnet_socketset.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\lowlevel\vsnet_sockettcp.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\lowlevel\vsnet_socketudp.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\lowlevel\vsnet_thread_non.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\lowlevel\vsnet_thread_p.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\lowlevel\vsnet_thread_sdl.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\accountsxml.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\accountsxml.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\acctserver.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\acctserver.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\client.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\const.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\fileutil.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\fileutil.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\netui.h
# End Source File
# End Group
# End Target
# End Project
