# Microsoft Developer Studio Project File - Name="texturizer" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=texturizer - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "texturizer.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "texturizer.mak" CFG="texturizer - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "texturizer - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "texturizer - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "texturizer - Win32 Release"

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
# ADD CPP /nologo /W3 /GX /O2 /I "..\..\vegastrike\src\\" /I "..\..\vegastrike\vc98\\" /I "..\include\\" /I ".\\" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib glut32.lib expat.lib libpng2.lib /nologo /subsystem:console /machine:I386 /out:"..\..\data\Texturizer.exe" /libpath:"..\..\vegastrike\vc98\\" /libpath:"..\lib\\"

!ELSEIF  "$(CFG)" == "texturizer - Win32 Debug"

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
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /I "..\..\vegastrike\src\\" /I "..\..\vegastrike\vc98\\" /I "..\include\\" /I ".\\" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib glut32.lib expat.lib libpng2.lib /nologo /subsystem:console /debug /machine:I386 /out:"..\..\data\Texturizer.exe" /pdbtype:sept /libpath:"..\..\vegastrike\vc98\\" /libpath:"..\lib\\"

!ENDIF 

# Begin Target

# Name "texturizer - Win32 Release"
# Name "texturizer - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\..\texturizer\src\cmd_gun.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\cmd_input_dfa.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\cmd_order.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\cmd_physics.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\cmd_unit.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\cmd_unit_xml.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\EnvironmentMapGenerator.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx_animation.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx_aux_logo.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx_aux_palette.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx_aux_texture.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx_background.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx_bounding_box.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx_box.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx_bsp.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx_camera.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx_click_list.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx_coordinate_select.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx_hud.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx_lerp.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx_location_select.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx_mesh.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx_mesh_xml.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx_primitive.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx_sphere.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx_sprite.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx_transform_matrix.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx_transform_vector.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gl_globals.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gl_init.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gl_light.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gl_material.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gl_matrix.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gl_misc.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gl_pick.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gl_state.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gl_texture.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gl_vertex_list.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\hashtable.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\in_handler.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\in_kb.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\in_main.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\in_mouse.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\lin_time.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\main.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\main_loop.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\physics.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\planet.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\png_texture.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\png_write.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\quaternion.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\star_system.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\texturizer.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\UnitCollection.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\wrapgfx.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\xml_end.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\xml_support.cpp
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\xmlassist.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\..\texturizer\src\cmd.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\cmd_ai.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\cmd_gun.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\cmd_input_dfa.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\cmd_navigation_orders.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\cmd_node.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\cmd_order.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\cmd_unit.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\cmd_unitenum.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\config.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\endianness.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\file.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\file_main.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx_animation.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx_aux.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx_aux_logo.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx_aux_palette.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx_aux_texture.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx_background.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx_bounding_box.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx_box.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx_bsp.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx_camera.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx_click_list.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx_coordinate_select.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx_hud.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx_lerp.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx_location_select.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx_mesh.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx_primitive.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx_sphere.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx_sprite.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx_transform.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx_transform_matrix.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx_transform_vector.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfx_vertex.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfxlib.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gfxlib_struct.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gl_globals.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gl_init.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\gl_matrix.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\hashtable.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\in.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\in_handler.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\in_kb.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\in_main.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\in_mouse.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\iterator.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\lin_time.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\main_loop.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\physics.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\planet.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\png_texture.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\profile.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\quaternion.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\star_system.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\texturizer.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\UnitCollection.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\vegastrike.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\vs_globals.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\vs_types.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\wrapgfx.h
# End Source File
# Begin Source File

SOURCE=..\..\texturizer\src\xml_support.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
