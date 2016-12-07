# Microsoft Developer Studio Project File - Name="vegastrike" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=vegastrike - Win32 Debug Boost 129
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "vegastrike.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "vegastrike.mak" CFG="vegastrike - Win32 Debug Boost 129"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "vegastrike - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "vegastrike - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "vegastrike - Win32 Debug GLUT" (based on "Win32 (x86) Application")
!MESSAGE "vegastrike - Win32 Release GLUT" (based on "Win32 (x86) Application")
!MESSAGE "vegastrike - Win32 Debug Boost 129" (based on "Win32 (x86) Application")
!MESSAGE "vegastrike - Win32 Release Boost 129" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "vegastrike - Win32 Release"

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
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /MD /w /W0 /GR /GX /Zi /O2 /I "..\vegastrike\boost\1_31\\" /I "..\vegastrike\src\\" /I "..\vegastrike\vc98\\" /I "include\\" /I "include\python\\" /I ".\\" /I "..\vegastrike\src\cmd\collide2\\" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "HAVE_AL" /D "HAVE_SDL" /D "YY_ALWAYS_INTERACTIVE" /D "SDL_WINDOWING" /D "HAVE_BOOST" /D "HAVE_PYTHON" /D "JPEG_SUPPORT" /D "USE_BOOST_131" /D "MSVCBITES" /D "BOOST_PYTHON_STATIC_LIB" /D "OPCODE_COLLIDER" /FR /YX /FD /Zm500 /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 sdl.lib sdlmain.lib python25.lib libjpeg.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib openal32.lib glut32.lib expat.lib libpng3.lib glib-1.3.lib alut.lib wsock32.lib /nologo /subsystem:windows /debug /machine:I386 /out:"..\data4.x\bin\vegastrikevc6R.exe" /libpath:"..\vegastrike\vc98\\" /libpath:"lib\\" /libpath:"vssetup\libs\\"
# SUBTRACT LINK32 /profile

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

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
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /w /W0 /Gm /GR /GX /Zi /Od /I "..\vegastrike\boost\1_31\\" /I "..\vegastrike\src\\" /I "..\vegastrike\vc98\\" /I "include\\" /I "include\python\\" /I ".\\" /I "..\vegastrike\src\cmd\collide2\\" /D "_DEBUG" /D "YY_NEVER_INTERACTIVE" /D "BOOST_DEBUG_PYTHON" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "HAVE_AL" /D "HAVE_SDL" /D "YY_ALWAYS_INTERACTIVE" /D "SDL_WINDOWING" /D "HAVE_BOOST" /D "HAVE_PYTHON" /D "JPEG_SUPPORT" /D "USE_BOOST_131" /D "MSVCBITES" /D "BOOST_PYTHON_STATIC_LIB" /D "OPCODE_COLLIDER" /FR /YX /FD /GZ /Zm500 /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 sdl.lib sdlmain.lib libjpegd.lib python25_d.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib openal32.lib glut32.lib expat.lib libpng3d.lib glib-1.3.lib alut.lib wsock32.lib Vfw32.lib /nologo /subsystem:windows /debug /machine:I386 /out:"..\data4.x\bin\vegastriked.exe" /pdbtype:sept /libpath:"..\vegastrike\vc98\\" /libpath:"lib\\" /libpath:"vssetup\libs\\"
# SUBTRACT LINK32 /profile /incremental:no

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "vegastrike___Win32_Debug_GLUT"
# PROP BASE Intermediate_Dir "vegastrike___Win32_Debug_GLUT"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "vegastrike___Win32_Debug_GLUT"
# PROP Intermediate_Dir "vegastrike___Win32_Debug_GLUT"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /w /W0 /Gm /GR /GX /ZI /Od /I "..\vegastrike\vc98" /I "..\vegastrike\src\\" /I "..\vegastrike\src\boost" /I "..\vegastrike\src\cmd\collide2\\" /D "_DEBUG" /D "YY_NEVER_INTERACTIVE" /D "BOOST_DEBUG_PYTHON" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "HAVE_AL" /D "HAVE_SDL" /D "YY_ALWAYS_INTERACTIVE" /D "SDL_WINDOWING" /D "HAVE_BOOST" /D "HAVE_PYTHON" /D "JPEG_SUPPORT" /D "USE_BOOST_128" /D "OPCODE_COLLIDER" /FR /YX /FD /GZ /Zm500 /c
# ADD CPP /nologo /MDd /w /W0 /Gm /GR /GX /ZI /Od /I "..\vegastrike\boost\1_31\\" /I "..\vegastrike\src\\" /I "..\vegastrike\vc98\\" /I "include\\" /I "include\python\\" /I ".\\" /I "..\vegastrike\src\cmd\collide2\\" /D "_DEBUG" /D "YY_NEVER_INTERACTIVE" /D "BOOST_DEBUG_PYTHON" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "HAVE_AL" /D "YY_ALWAYS_INTERACTIVE" /D "HAVE_BOOST" /D "HAVE_PYTHON" /D "JPEG_SUPPORT" /D "USE_BOOST_131" /D "BOOST_PYTHON_STATIC_LIB" /D "OPCODE_COLLIDER" /FR /YX /FD /GZ /Zm500 /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib glib-1.3.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib openal32.lib glut32.lib sdl.lib sdlmain.lib expat.lib alut.lib libpng2.lib SDL_mixer.lib wsock32.lib libjpegd.lib /nologo /subsystem:windows /debug /machine:I386 /out:"C:\temp\data\vegastrike.exe" /pdbtype:sept /libpath:"..\vegastrike\vc98"
# ADD LINK32 python25_d.lib libjpegd.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib openal32.lib glut32.lib expat.lib libpng3d.lib glib-1.3.lib alut.lib wsock32.lib /nologo /subsystem:console /debug /machine:I386 /out:"..\data4.x\bin\vegastrikeG.exe" /pdbtype:sept /libpath:"..\vegastrike\vc98\\" /libpath:"lib\\" /libpath:"vssetup\libs\\"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "vegastrike___Win32_Release_GLUT"
# PROP BASE Intermediate_Dir "vegastrike___Win32_Release_GLUT"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "vegastrike___Win32_Release_GLUT"
# PROP Intermediate_Dir "vegastrike___Win32_Release_GLUT"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /w /W0 /GR /GX /Zi /O2 /I "..\vegastrike\src\\" /I "..\vegastrike\src\boost\\" /I "..\vegastrike\src\cmd\collide2\\" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "HAVE_AL" /D "HAVE_SDL" /D "YY_ALWAYS_INTERACTIVE" /D "SDL_WINDOWING" /D "HAVE_BOOST" /D "HAVE_PYTHON" /D "JPEG_SUPPORT" /D "USE_BOOST_128" /D "MSVCBITES" /D "BOOST_PYTHON_STATIC_LIB" /D "OPCODE_COLLIDER" /FR /YX /FD /Zm500 /c
# ADD CPP /nologo /MD /w /W0 /GR /GX /Zi /O2 /I "..\vegastrike\boost\1_31\\" /I "..\vegastrike\src\\" /I "..\vegastrike\vc98\\" /I "include\\" /I "include\python\\" /I ".\\" /I "..\vegastrike\src\cmd\collide2\\" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "HAVE_AL" /D "YY_ALWAYS_INTERACTIVE" /D "HAVE_BOOST" /D "HAVE_PYTHON" /D "JPEG_SUPPORT" /D "USE_BOOST_131" /D "MSVCBITES" /D "BOOST_PYTHON_STATIC_LIB" /D "OPCODE_COLLIDER" /FR /YX /FD /Zm500 /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib openal32.lib glut32.lib sdl.lib sdlmain.lib expat.lib libpng2.lib glib-1.3.lib alut.lib SDL_mixer.lib python22.lib wsock32.lib libjpeg.lib /nologo /subsystem:windows /debug /machine:I386 /out:"C:\temp\data\vegastrike.exe" /libpath:"..\vegastrike\vc98"
# SUBTRACT BASE LINK32 /incremental:yes
# ADD LINK32 python25.lib libjpeg.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib openal32.lib glut32.lib expat.lib libpng3.lib glib-1.3.lib alut.lib wsock32.lib /nologo /subsystem:console /debug /machine:I386 /out:"..\data4.x\bin\vegastrikeGR.exe" /libpath:"..\vegastrike\vc98\\" /libpath:"lib\\" /libpath:"vssetup\libs\\"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "vegastrike___Win32_Debug_Boost_129"
# PROP BASE Intermediate_Dir "vegastrike___Win32_Debug_Boost_129"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "vegastrike___Win32_Debug_Boost_129"
# PROP Intermediate_Dir "vegastrike___Win32_Debug_Boost_129"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /w /W0 /Gm /GR /GX /ZI /Od /I "..\vegastrike\vc98" /I "..\vegastrike\src\\" /I "..\vegastrike\src\boost" /I "..\vegastrike\src\cmd\collide2\\" /D "_DEBUG" /D "YY_NEVER_INTERACTIVE" /D "BOOST_DEBUG_PYTHON" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "HAVE_AL" /D "HAVE_SDL" /D "YY_ALWAYS_INTERACTIVE" /D "SDL_WINDOWING" /D "HAVE_BOOST" /D "HAVE_PYTHON" /D "JPEG_SUPPORT" /D "USE_BOOST_128" /D "OPCODE_COLLIDER" /FR /YX /FD /GZ /Zm500 /c
# ADD CPP /nologo /MDd /w /W0 /Gm /GR /GX /ZI /Od /I "..\vegastrike\boost\1_28\\" /I "..\vegastrike\src\\" /I "..\vegastrike\vc98\\" /I "include\\" /I "include\python\\" /I ".\\" /I "..\vegastrike\src\cmd\collide2\\" /D "_DEBUG" /D "NDEBUG" /D "YY_NEVER_INTERACTIVE" /D "BOOST_DEBUG_PYTHON" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "HAVE_AL" /D "HAVE_SDL" /D "YY_ALWAYS_INTERACTIVE" /D "SDL_WINDOWING" /D "HAVE_BOOST" /D "HAVE_PYTHON" /D "JPEG_SUPPORT" /D "USE_BOOST_128" /D "BOOST_PYTHON_STATIC_LIB" /D "OPCODE_COLLIDER" /FR /YX /FD /GZ /Zm500 /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib glib-1.3.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib openal32.lib glut32.lib sdl.lib sdlmain.lib expat.lib alut.lib libpng2.lib SDL_mixer.lib wsock32.lib libjpegd.lib /nologo /subsystem:windows /debug /machine:I386 /out:"C:\temp\data\vegastrike.exe" /pdbtype:sept /libpath:"..\vegastrike\vc98"
# ADD LINK32 sdl.lib sdlmain.lib libjpegd.lib python25_d.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib openal32.lib glut32.lib expat.lib libpng3d.lib glib-1.3.lib alut.lib wsock32.lib /nologo /subsystem:windows /debug /machine:I386 /out:"..\data4.x\bin\vegastrikevc6.exe" /pdbtype:sept /libpath:"..\vegastrike\vc98\\" /libpath:"lib\\" /libpath:"vssetup\libs\\"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "vegastrike___Win32_Release_Boost_129"
# PROP BASE Intermediate_Dir "vegastrike___Win32_Release_Boost_129"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "vegastrike___Win32_Release_Boost_129"
# PROP Intermediate_Dir "vegastrike___Win32_Release_Boost_129"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /w /W0 /GR /GX /Zi /O2 /I "..\vegastrike\src\\" /I "..\vegastrike\src\boost\\" /I "..\vegastrike\src\cmd\collide2\\" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "HAVE_AL" /D "HAVE_SDL" /D "YY_ALWAYS_INTERACTIVE" /D "SDL_WINDOWING" /D "HAVE_BOOST" /D "HAVE_PYTHON" /D "JPEG_SUPPORT" /D "USE_BOOST_128" /D "MSVCBITES" /D "BOOST_PYTHON_STATIC_LIB" /D "OPCODE_COLLIDER" /FR /YX /FD /Zm500 /c
# ADD CPP /nologo /MD /w /W0 /GR /GX /Zi /O2 /I "..\vegastrike\boost\1_28\\" /I "..\vegastrike\src\\" /I "..\vegastrike\vc98\\" /I "include\\" /I "include\python\\" /I ".\\" /I "..\vegastrike\src\cmd\collide2\\" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "HAVE_AL" /D "HAVE_SDL" /D "YY_ALWAYS_INTERACTIVE" /D "SDL_WINDOWING" /D "HAVE_BOOST" /D "HAVE_PYTHON" /D "JPEG_SUPPORT" /D "USE_BOOST_128" /D "MSVCBITES" /D "BOOST_PYTHON_STATIC_LIB" /D "OPCODE_COLLIDER" /FR /YX /FD /Zm500 /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib openal32.lib glut32.lib sdl.lib sdlmain.lib expat.lib libpng2.lib glib-1.3.lib alut.lib SDL_mixer.lib python22.lib wsock32.lib libjpeg.lib /nologo /subsystem:windows /debug /machine:I386 /out:"C:\temp\data\vegastrike.exe" /libpath:"..\vegastrike\vc98"
# SUBTRACT BASE LINK32 /incremental:yes
# ADD LINK32 sdl.lib sdlmain.lib python25.lib libjpeg.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib openal32.lib glut32.lib expat.lib libpng3.lib glib-1.3.lib alut.lib wsock32.lib /nologo /subsystem:windows /debug /machine:I386 /out:"..\data4.x\bin\vegastrikevc6R.exe" /libpath:"..\vegastrike\vc98\\" /libpath:"lib\\" /libpath:"vssetup\libs\\"
# SUBTRACT LINK32 /incremental:yes

!ENDIF 

# Begin Target

# Name "vegastrike - Win32 Release"
# Name "vegastrike - Win32 Debug"
# Name "vegastrike - Win32 Debug GLUT"
# Name "vegastrike - Win32 Release GLUT"
# Name "vegastrike - Win32 Debug Boost 129"
# Name "vegastrike - Win32 Release Boost 129"
# Begin Group "boost131"

# PROP Default_Filter "*.hpp"
# Begin Source File

SOURCE=..\vegastrike\boost\1_31\src\aix_init_module.cpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

# PROP Intermediate_Dir "Release\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

# PROP Intermediate_Dir "Debug\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

# PROP Intermediate_Dir "vegastrike___Win32_Debug_GLUT\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

# PROP Intermediate_Dir "vegastrike___Win32_Release_GLUT\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Intermediate_Dir "vegastrike___Win32_Debug_Boost_129\boost129"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Intermediate_Dir "vegastrike___Win32_Release_Boost_129\boost129"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_31\src\converter\arg_to_python_base.cpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

# PROP Intermediate_Dir "Release\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

# PROP Intermediate_Dir "Debug\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

# PROP Intermediate_Dir "vegastrike___Win32_Debug_GLUT\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

# PROP Intermediate_Dir "vegastrike___Win32_Release_GLUT\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Intermediate_Dir "vegastrike___Win32_Debug_Boost_129\boost129"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Intermediate_Dir "vegastrike___Win32_Release_Boost_129\boost129"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_31\src\converter\builtin_converters.cpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

# PROP Intermediate_Dir "Release\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

# PROP Intermediate_Dir "Debug\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

# PROP Intermediate_Dir "vegastrike___Win32_Debug_GLUT\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

# PROP Intermediate_Dir "vegastrike___Win32_Release_GLUT\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Intermediate_Dir "vegastrike___Win32_Debug_Boost_129\boost129"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Intermediate_Dir "vegastrike___Win32_Release_Boost_129\boost129"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_31\src\object\class.cpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

# PROP Intermediate_Dir "Release\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

# PROP Intermediate_Dir "Debug\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

# PROP Intermediate_Dir "vegastrike___Win32_Debug_GLUT\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

# PROP Intermediate_Dir "vegastrike___Win32_Release_GLUT\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Intermediate_Dir "vegastrike___Win32_Debug_Boost_129\boost129"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Intermediate_Dir "vegastrike___Win32_Release_Boost_129\boost129"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_31\src\dict.cpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

# PROP Intermediate_Dir "Release\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

# PROP Intermediate_Dir "Debug\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

# PROP Intermediate_Dir "vegastrike___Win32_Debug_GLUT\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

# PROP Intermediate_Dir "vegastrike___Win32_Release_GLUT\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Intermediate_Dir "vegastrike___Win32_Debug_Boost_129\boost129"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Intermediate_Dir "vegastrike___Win32_Release_Boost_129\boost129"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_31\src\object\enum.cpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

# PROP Intermediate_Dir "Release\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

# PROP Intermediate_Dir "Debug\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

# PROP Intermediate_Dir "vegastrike___Win32_Debug_GLUT\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

# PROP Intermediate_Dir "vegastrike___Win32_Release_GLUT\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Intermediate_Dir "vegastrike___Win32_Debug_Boost_129\boost129"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Intermediate_Dir "vegastrike___Win32_Release_Boost_129\boost129"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_31\src\errors.cpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

# PROP Intermediate_Dir "Release\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

# PROP Intermediate_Dir "Debug\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

# PROP Intermediate_Dir "vegastrike___Win32_Debug_GLUT\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

# PROP Intermediate_Dir "vegastrike___Win32_Release_GLUT\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Intermediate_Dir "vegastrike___Win32_Debug_Boost_129\boost129"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Intermediate_Dir "vegastrike___Win32_Release_Boost_129\boost129"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_31\src\converter\from_python.cpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

# PROP Intermediate_Dir "Release\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

# PROP Intermediate_Dir "Debug\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

# PROP Intermediate_Dir "vegastrike___Win32_Debug_GLUT\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

# PROP Intermediate_Dir "vegastrike___Win32_Release_GLUT\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Intermediate_Dir "vegastrike___Win32_Debug_Boost_129\boost129"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Intermediate_Dir "vegastrike___Win32_Release_Boost_129\boost129"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_31\src\object\function.cpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

# PROP Intermediate_Dir "Release\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

# PROP Intermediate_Dir "Debug\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

# PROP Intermediate_Dir "vegastrike___Win32_Debug_GLUT\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

# PROP Intermediate_Dir "vegastrike___Win32_Release_GLUT\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Intermediate_Dir "vegastrike___Win32_Debug_Boost_129\boost129"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Intermediate_Dir "vegastrike___Win32_Release_Boost_129\boost129"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_31\src\object\inheritance.cpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_31\src\object\iterator.cpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

# PROP Intermediate_Dir "Release\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

# PROP Intermediate_Dir "Debug\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

# PROP Intermediate_Dir "vegastrike___Win32_Debug_GLUT\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

# PROP Intermediate_Dir "vegastrike___Win32_Release_GLUT\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Intermediate_Dir "vegastrike___Win32_Debug_Boost_129\boost129"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Intermediate_Dir "vegastrike___Win32_Release_Boost_129\boost129"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_31\src\object\life_support.cpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

# PROP Intermediate_Dir "Release\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

# PROP Intermediate_Dir "Debug\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

# PROP Intermediate_Dir "vegastrike___Win32_Debug_GLUT\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

# PROP Intermediate_Dir "vegastrike___Win32_Release_GLUT\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Intermediate_Dir "vegastrike___Win32_Debug_Boost_129\boost129"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Intermediate_Dir "vegastrike___Win32_Release_Boost_129\boost129"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_31\src\list.cpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

# PROP Intermediate_Dir "Release\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

# PROP Intermediate_Dir "Debug\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

# PROP Intermediate_Dir "vegastrike___Win32_Debug_GLUT\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

# PROP Intermediate_Dir "vegastrike___Win32_Release_GLUT\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Intermediate_Dir "vegastrike___Win32_Debug_Boost_129\boost129"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Intermediate_Dir "vegastrike___Win32_Release_Boost_129\boost129"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_31\src\long.cpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

# PROP Intermediate_Dir "Release\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

# PROP Intermediate_Dir "Debug\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

# PROP Intermediate_Dir "vegastrike___Win32_Debug_GLUT\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

# PROP Intermediate_Dir "vegastrike___Win32_Release_GLUT\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Intermediate_Dir "vegastrike___Win32_Debug_Boost_129\boost129"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Intermediate_Dir "vegastrike___Win32_Release_Boost_129\boost129"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_31\src\module.cpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

# PROP Intermediate_Dir "Release\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

# PROP Intermediate_Dir "Debug\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

# PROP Intermediate_Dir "vegastrike___Win32_Debug_GLUT\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

# PROP Intermediate_Dir "vegastrike___Win32_Release_GLUT\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Intermediate_Dir "vegastrike___Win32_Debug_Boost_129\boost129"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Intermediate_Dir "vegastrike___Win32_Release_Boost_129\boost129"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_31\src\numeric.cpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

# PROP Intermediate_Dir "Release\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

# PROP Intermediate_Dir "Debug\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

# PROP Intermediate_Dir "vegastrike___Win32_Debug_GLUT\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

# PROP Intermediate_Dir "vegastrike___Win32_Release_GLUT\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Intermediate_Dir "vegastrike___Win32_Debug_Boost_129\boost129"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Intermediate_Dir "vegastrike___Win32_Release_Boost_129\boost129"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_31\src\object_operators.cpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

# PROP Intermediate_Dir "Release\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

# PROP Intermediate_Dir "Debug\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

# PROP Intermediate_Dir "vegastrike___Win32_Debug_GLUT\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

# PROP Intermediate_Dir "vegastrike___Win32_Release_GLUT\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Intermediate_Dir "vegastrike___Win32_Debug_Boost_129\boost129"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Intermediate_Dir "vegastrike___Win32_Release_Boost_129\boost129"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_31\src\object_protocol.cpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

# PROP Intermediate_Dir "Release\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

# PROP Intermediate_Dir "Debug\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

# PROP Intermediate_Dir "vegastrike___Win32_Debug_GLUT\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

# PROP Intermediate_Dir "vegastrike___Win32_Release_GLUT\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Intermediate_Dir "vegastrike___Win32_Debug_Boost_129\boost129"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Intermediate_Dir "vegastrike___Win32_Release_Boost_129\boost129"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_31\src\object\pickle_support.cpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

# PROP Intermediate_Dir "Release\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

# PROP Intermediate_Dir "Debug\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

# PROP Intermediate_Dir "vegastrike___Win32_Debug_GLUT\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

# PROP Intermediate_Dir "vegastrike___Win32_Release_GLUT\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Intermediate_Dir "vegastrike___Win32_Debug_Boost_129\boost129"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Intermediate_Dir "vegastrike___Win32_Release_Boost_129\boost129"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_31\src\converter\registry.cpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

# PROP Intermediate_Dir "Release\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

# PROP Intermediate_Dir "Debug\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

# PROP Intermediate_Dir "vegastrike___Win32_Debug_GLUT\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

# PROP Intermediate_Dir "vegastrike___Win32_Release_GLUT\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Intermediate_Dir "vegastrike___Win32_Debug_Boost_129\boost129"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Intermediate_Dir "vegastrike___Win32_Release_Boost_129\boost129"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_31\src\str.cpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

# PROP Intermediate_Dir "Release\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

# PROP Intermediate_Dir "Debug\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

# PROP Intermediate_Dir "vegastrike___Win32_Debug_GLUT\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

# PROP Intermediate_Dir "vegastrike___Win32_Release_GLUT\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Intermediate_Dir "vegastrike___Win32_Debug_Boost_129\boost129"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Intermediate_Dir "vegastrike___Win32_Release_Boost_129\boost129"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_31\src\tuple.cpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

# PROP Intermediate_Dir "Release\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

# PROP Intermediate_Dir "Debug\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

# PROP Intermediate_Dir "vegastrike___Win32_Debug_GLUT\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

# PROP Intermediate_Dir "vegastrike___Win32_Release_GLUT\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Intermediate_Dir "vegastrike___Win32_Debug_Boost_129\boost129"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Intermediate_Dir "vegastrike___Win32_Release_Boost_129\boost129"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_31\src\converter\type_id.cpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

# PROP Intermediate_Dir "Release\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

# PROP Intermediate_Dir "Debug\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

# PROP Intermediate_Dir "vegastrike___Win32_Debug_GLUT\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

# PROP Intermediate_Dir "vegastrike___Win32_Release_GLUT\boost129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Intermediate_Dir "vegastrike___Win32_Debug_Boost_129\boost129"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Intermediate_Dir "vegastrike___Win32_Release_Boost_129\boost129"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Group "Source Files"

# PROP Default_Filter "*.cpp"
# Begin Source File

SOURCE=..\vegastrike\src\command.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\config_xml.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\configxml.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\debug_vs.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\easydom.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\endianness.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\faction_generic.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\faction_util.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\faction_util_generic.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\fastmath.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\force_feedback.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\galaxy.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\galaxy_gen.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\galaxy_xml.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gamemenu.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfxlib_struct.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\hashtable.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\in_joystick.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\in_kb.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\in_main.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\in_mouse.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\in_sdl.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\lin_time.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\load_mission.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\macosx_math.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\main.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\main_loop.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\physics.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\pk3.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\posh.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\rendertext.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\Resources.rc
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\savegame.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\ship_commands.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\star_system.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\star_system_generic.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\star_system_jump.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\star_system_xml.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\stardate.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\universe.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\universe_generic.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\universe_util.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\universe_util_generic.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\vs_globals.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\vsfilesystem.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\xml_serializer.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\xml_support.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\vegastrike\src\audiolib.h
# End Source File
# Begin Source File

SOURCE=..\veagstrike\src\command.h
# End Source File
# Begin Source File

SOURCE=.\config.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\config.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\config_xml.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\debug_vs.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\easydom.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\endianness.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\faction.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\faction_generic.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\file_main.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\force_feedback.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\galaxy_gen.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\galaxy_xml.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfxlib.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfxlib_struct.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\hashtable.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\in.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\in_handler.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\in_joystick.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\in_kb.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\in_main.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\in_mouse.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\lin_time.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\linecollide.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\macosx_math.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\main_loop.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\mission.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\ai\missionscript.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\physics.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\pk3.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\posh.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\profile.h
# End Source File
# Begin Source File

SOURCE=..\veagstrike\src\rendertext.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\resizable.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\resource.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\save_util.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\savegame.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\SharedPool.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\star_system.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\star_system_generic.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\stardate.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\script\c_alike\unistd.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\universe.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\universe_generic.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\universe_util.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\vegastrike.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\vs_globals.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\vs_path.h
# End Source File
# Begin Source File

SOURCE=..\veagstrike\src\vs_random.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\vsfilesystem.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\xml_serializer.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\xml_support.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\vegastrike\cursor1.cur
# End Source File
# Begin Source File

SOURCE=..\vegastrike\icon2.ico
# End Source File
# Begin Source File

SOURCE=..\vegastrike\icon3.ico
# End Source File
# Begin Source File

SOURCE=..\vegastrike\vega.ico
# End Source File
# End Group
# Begin Group "cmd"

# PROP Default_Filter ""
# Begin Group "ai"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\vegastrike\src\cmd\ai\aggressive.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\ai\aggressive.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\ai\comm_ai.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\ai\comm_ai.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\ai\communication.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\ai\communication.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\ai\communication_xml.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\ai\docking.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\ai\docking.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\ai\event_xml.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\ai\event_xml.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\ai\fire.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\ai\fire.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\ai\fireall.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\ai\fireall.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\ai\firekeyboard.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\ai\firekeyboard.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\ai\flybywire.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\ai\flybywire.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\ai\flyjoystick.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\ai\flyjoystick.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\ai\flykeyboard.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\ai\flykeyboard.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\ai\hard_coded_scripts.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\ai\hard_coded_scripts.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\ai\ikarus.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\ai\ikarus.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\ai\input_dfa.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\ai\input_dfa.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\ai\missionscript.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\ai\navigation.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\ai\navigation.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\ai\order.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\ai\order.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\ai\order_comm.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\ai\script.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\ai\script.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\ai\tactics.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\ai\tactics.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\ai\turretai.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\ai\turretai.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\ai\warpto.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\ai\warpto.h
# End Source File
# End Group
# Begin Group "script"

# PROP Default_Filter ""
# Begin Group "c_alike"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\vegastrike\src\cmd\script\c_alike\c_alike.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\script\c_alike\c_alike.tab.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\script\c_alike\c_alike.tab.cpp.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\script\c_alike\c_alike.yacc
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\script\c_alike\lex.yy.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=..\vegastrike\src\cmd\script\director.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\script\director_generic.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\script\flightgroup.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\script\flightgroup.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\script\mission.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\script\mission.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\script\mission_script.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\script\mission_types.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\script\msgcenter.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\script\msgcenter.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\script\pythonmission.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\script\pythonmission.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\script\script_call_briefing.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\script\script_call_olist.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\script\script_call_omap.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\script\script_call_order.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\script\script_call_string.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\script\script_call_unit.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\script\script_call_unit_generic.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\script\script_callbacks.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\script\script_expression.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\script\script_generic.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\script\script_statement.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\script\script_util.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\script\script_variables.cpp
# End Source File
# End Group
# Begin Group "collide"

# PROP Default_Filter ""
# Begin Group "csgeom"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\vegastrike\src\cmd\collide\csgeom\box.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\collide\csgeom\matrix3.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\collide\csgeom\transfrm.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\collide\csgeom\vector3.h
# End Source File
# End Group
# Begin Source File

SOURCE=..\vegastrike\src\cmd\collide\box.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\collide\collider.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\collide\cs_compat.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\collide\csrapid.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\collide\garray.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\collide\matrix3.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\collide\pbuild.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\collide\peigen.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\collide\prapid.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\collide\prapid.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\collide\qint.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\collide\qsqrt.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\collide\rapcol.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\collide\vector3.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=..\vegastrike\src\cmd\alphacurve.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\alphacurve.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\asteroid.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\asteroid.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\asteroid_generic.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\asteroid_generic.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\atmosphere.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\atmosphere.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\base.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\base_init.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\base_interface.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\base_util.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\base_util.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\base_write_python.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\base_xml.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\basecomputer.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\basecomputer.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\beam.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\beam.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\beam_generic.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\bolt.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\bolt.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\bolt_generic.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\briefing.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\briefing.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\building.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\building.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\building_generic.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\building_generic.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\click_list.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\click_list.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\collection.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\collection.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\collide.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\collide.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\collide_map.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\cont_terrain.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\cont_terrain.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\container.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\container.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\csv.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\csv.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\enhancement.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\enhancement_generic.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\faction_xml.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\images.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\iterator.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\missile.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\missile_generic.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\missile_generic.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\mount.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\music.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\music.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\nebula.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\nebula.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\nebula_generic.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\nebula_generic.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\pilot.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\planet.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\planet.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\planet_generic.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\planet_generic.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\role_bitmask.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\role_bitmask.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\terrain.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\terrain.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\unit.cpp
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\unit.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\unit_bsp.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\unit_bsp.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\unit_collide.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\unit_collide.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\unit_collide_debug.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\unit_const_cache.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\unit_const_cache.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\unit_csv.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\unit_factory.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\unit_factory.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\unit_factory_generic.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\unit_factory_generic.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\unit_functions.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\unit_functions_generic.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\unit_generic.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\unit_generic.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\unit_interface.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\unit_interface.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\unit_util.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\unit_util.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\unit_util_generic.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\unit_xml.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\unit_xml.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\weapon_xml.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\cmd\weapon_xml.h
# End Source File
# End Group
# Begin Group "aldrv"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\vegastrike\src\aldrv\al_globals.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\aldrv\al_globals.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\aldrv\al_init.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\aldrv\al_listen.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\aldrv\al_sound.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\aldrv\wave.cpp
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Group "python"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\vegastrike\src\python\briefing_wrapper.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\python\init.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\python\init.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\python\python_class.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\python\python_compile.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\python\python_compile.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\python\python_unit_wrap.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\python\star_system_exports.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\python\unit_exports.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\python\unit_exports.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\python\unit_exports1.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\python\unit_exports2.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\python\unit_exports3.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\python\unit_from_to_python.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\python\unit_method_defs.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\python\unit_wrapper.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\python\unit_wrapper_class.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\python\universe_util_export.cpp
# End Source File
# End Group
# Begin Group "gldrv"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\vegastrike\src\gldrv\gl_clip.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gldrv\gl_fog.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gldrv\gl_globals.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gldrv\gl_globals.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gldrv\gl_include.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gldrv\gl_init.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gldrv\gl_init.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gldrv\gl_light.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gldrv\gl_light.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gldrv\gl_light_pick.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gldrv\gl_light_state.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gldrv\gl_material.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gldrv\gl_matrix.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gldrv\gl_matrix.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gldrv\gl_misc.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gldrv\gl_pick.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gldrv\gl_quad_list.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gldrv\gl_sphere_list.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gldrv\gl_state.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gldrv\gl_texture.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gldrv\gl_vertex_list.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gldrv\hashtable_3d.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gldrv\winsys.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gldrv\winsys.h
# End Source File
# End Group
# Begin Group "gfx"

# PROP Default_Filter ""
# Begin Group "nav"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\vegastrike\src\gfx\nav\criteria.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\nav\criteria.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\nav\criteria_xml.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\nav\drawgalaxy.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\nav\drawlist.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\nav\drawlist.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\nav\drawsystem.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\nav\navcomputer.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\nav\navcomputer.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\nav\navgetxmldata.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\nav\navgetxmldata.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\nav\navitemstodraw.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\nav\navitemtypes.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\nav\navparse.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\nav\navpath.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\nav\navpath.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\nav\navscreen.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\nav\navscreen.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\nav\navscreenoccupied.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\nav\navscreenoccupied.h
# End Source File
# End Group
# Begin Source File

SOURCE=..\vegastrike\src\gfx\ani_texture.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\ani_texture.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\animation.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\animation.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\aux_logo.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\aux_logo.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\aux_palette.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\aux_palette.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\aux_texture.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\aux_texture.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\background.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\background.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\bounding_box.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\bounding_box.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\box.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\bsp.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\bsp.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\camera.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\camera.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\car_assist.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\cockpit.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\cockpit.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\cockpit_generic.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\cockpit_generic.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\cockpit_xml.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\coord_select.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\coord_select.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\decalqueue.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\env_map_gent.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\env_map_gent.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\gauge.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\gauge.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\halo.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\halo.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\halo_system.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\halo_system.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\hud.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\hud.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\jpeg_memory.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\jpeg_memory.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\lerp.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\lerp.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\loc_select.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\loc_select.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\masks.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\masks.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\matrix.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\matrix.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\mesh.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\mesh.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\mesh_bin.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\mesh_bxm.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\mesh_fx.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\mesh_gfx.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\mesh_poly.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\mesh_xml.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\nonlinear_transform.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\particle.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\particle.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\pipelined_texture.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\pipelined_texture.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\planetary_transform.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\point_to_cam.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\quadsquare.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\quadsquare.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\quadsquare_cull.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\quadsquare_render.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\quadsquare_update.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\quadtree.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\quadtree.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\quadtree_xml.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\quaternion.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\quaternion.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\ring.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\ring.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\screenshot.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\screenshot.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\sphere.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\sphere.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\sphere_generic.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\sprite.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\sprite.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\star.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\star.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\tex_transform.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\vdu.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\vdu.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\vec.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\vec.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\vertex.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\vid_file.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\vid_file.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\vsbox.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\vsbox.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\vsimage.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\vsimage.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\warptrail.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\warptrail.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gfx\xvector.h
# End Source File
# End Group
# Begin Group "gui"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\vegastrike\src\gui\button.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gui\button.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gui\control.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gui\control.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gui\eventmanager.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gui\eventmanager.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gui\eventresponder.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gui\eventresponder.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gui\font.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gui\font.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gui\general.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gui\general.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gui\glut_support.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gui\glut_support.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gui\groupcontrol.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gui\groupcontrol.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gui\guidefs.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gui\guidefs.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gui\guitexture.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gui\guitexture.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gui\modaldialog.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gui\modaldialog.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gui\newbutton.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gui\newbutton.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gui\painttext.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gui\painttext.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gui\picker.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gui\picker.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gui\scroller.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gui\scroller.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gui\simplepicker.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gui\simplepicker.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gui\slider.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gui\slider.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gui\staticdisplay.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gui\staticdisplay.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gui\text_area.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gui\text_area.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gui\textinputdisplay.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gui\textinputdisplay.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gui\window.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gui\window.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gui\windowcontroller.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\gui\windowcontroller.h
# End Source File
# End Group
# Begin Group "networking"

# PROP Default_Filter ""
# Begin Group "lowlevel"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\GCPtr.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\netbuffer.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\netbuffer.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\netclass.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\netui.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\netui.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\packet.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\packet.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\packetmem.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\packetmem.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\vsnet_address.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\vsnet_address.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\vsnet_clientstate.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\vsnet_clientstate.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\vsnet_cmd.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\vsnet_cmd.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\vsnet_debug.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\vsnet_debug.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\vsnet_dloadenum.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\vsnet_dloadenum.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\vsnet_dloadmgr.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\vsnet_dloadmgr.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\vsnet_err.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\vsnet_headers.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\vsnet_notify.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\vsnet_notify.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\vsnet_oss.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\vsnet_oss.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\vsnet_parsecmd.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\vsnet_parsecmd.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\vsnet_pipe.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\vsnet_pipe.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\vsnet_queue.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\vsnet_serversocket.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\vsnet_serversocket.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\vsnet_socket.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\vsnet_socket.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\vsnet_socketbase.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\vsnet_socketbase.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\vsnet_socketflags.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\vsnet_socketflags.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\vsnet_sockethttp.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\vsnet_sockethttp.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\vsnet_socketset.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\vsnet_socketset.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\vsnet_sockettcp.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\vsnet_sockettcp.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\vsnet_socketudp.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\vsnet_socketudp.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\vsnet_thread.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\vsnet_thread_non.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\vsnet_thread_p.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\lowlevel\vsnet_thread_sdl.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=..\vegastrike\src\networking\accountsxml.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\accountsxml.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\acctserver.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\client.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\client.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\const.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\cubicsplines.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\cubicsplines.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\fileutil.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\fileutil.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\inet.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\inet.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\inet_file.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\inet_file.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\mangle.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\mangle.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\netclient.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\netclient.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\netclient_clients.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\netclient_devices.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\netclient_login.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\netserver.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\netserver.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\netserver_acct.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\netserver_clients.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\netserver_devices.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\netserver_login.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\netserver_net.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\networkcomm.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\networkcomm.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\prediction.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\prediction.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\savenet_util.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\savenet_util.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\webcam_support.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\webcam_support.h
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\zonemgr.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\networking\zonemgr.h
# End Source File
# End Group
# Begin Group "boost"

# PROP Default_Filter ""
# Begin Group "boost.python"

# PROP Default_Filter ""
# Begin Group "converter"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\converter\builtin_converters.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\converter\callback.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\converter\callback_from_python_base.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\converter\callback_to_python_base.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\converter\find_from_python.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\converter\from_python.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\converter\from_python_data.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\converter\from_python_function.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\converter\from_python_stage1_data.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\converter\implicit.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\converter\lvalue_from_python_chain.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\converter\pointee_to_python_function.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\converter\pointer_type_id.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\converter\registrations.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\converter\registry.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\converter\rvalue_from_python_chain.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\converter\smart_ptr.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\converter\to_python_function.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\converter\to_python_function_type.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\converter\type_id.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Group "detail"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\detail\arg_tuple_size.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\detail\base_object.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\detail\call_object.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\detail\caller.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\detail\cast.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\detail\char_array.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\detail\config.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\detail\cv_category.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\detail\destroy.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\detail\extension_class.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\detail\functions.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\detail\if_else.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\detail\indirect_traits.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\detail\init_function.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\detail\map_entry.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\detail\member_function_cast.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\detail\module_base.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\detail\msvc_typeinfo.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\detail\none.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\detail\not_specified.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\detail\pointee.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\detail\preprocessor.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\detail\returning.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\detail\signatures.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\detail\singleton.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\detail\type_list.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\detail\types.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\detail\unwind_type.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\detail\void_adaptor.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\detail\void_ptr.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\detail\wrap_function.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\detail\wrap_python.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Group "object"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\object\auto_ptr_generator.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\object\class.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\object\class_converters.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\object\class_object.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\object\class_wrapper.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\object\construct.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\object\find_instance.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\object\forward.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\object\function.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\object\inheritance.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\object\life_support.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\object\make_holder.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\object\pointer_holder.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\object\select_holder.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\object\value_holder.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\object\value_holder_fwd.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Group "preprocessed"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\preprocessed\arg_tuple_size.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\preprocessed\args.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\preprocessed\call.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\preprocessed\call_method.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\preprocessed\caller.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\preprocessed\make_holder.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\preprocessed\member_function_cast.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\preprocessed\pointer_holder.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\preprocessed\ptr_holder_back_reference.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\preprocessed\returning_non_void.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\preprocessed\returning_void.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\preprocessed\value_holder.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\boost\python\preprocessed\value_holder_back_reference.hpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# End Group
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\src\converter\callback.cpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\src\classes.cpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\src\conversions.cpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\src\cross_module.cpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\src\errors.cpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\src\extension_class.cpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\src\object\function.cpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\src\functions.cpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\src\init_function.cpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\src\object\life_support.cpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\src\module.cpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\src\module_builder.cpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\src\objects.cpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\vegastrike\boost\1_28\src\types.cpp

!IF  "$(CFG)" == "vegastrike - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug GLUT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release GLUT"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Debug Boost 129"

!ELSEIF  "$(CFG)" == "vegastrike - Win32 Release Boost 129"

!ENDIF 

# End Source File
# End Group
# Begin Group "common"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\vegastrike\src\common\common.cpp
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\common\common.h
# End Source File
# End Group
# Begin Source File

SOURCE=..\vegastrike\icon4.ico
# End Source File
# Begin Source File

SOURCE=..\vegastrike\src\ship_commands.h
# End Source File
# End Target
# End Project
