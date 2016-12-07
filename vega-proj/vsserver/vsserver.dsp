# Microsoft Developer Studio Project File - Name="vsserver" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=vsserver - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "vsserver.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "vsserver.mak" CFG="vsserver - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "vsserver - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "vsserver - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "vsserver - Win32 Release"

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
# ADD CPP /nologo /GX /O2 /I "..\..\vegastrike\src\\" /I "..\include\\" /I "..\include\python\\" /I "..\..\vegastrike\boost\1_28\\" /I "..\\" /I "..\..\vegastrike\src\cmd\collide2\\" /D "NDEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /D "_UDP_PROTO" /D "YY_NEVER_INTERACTIVE" /D "YY_ALWAYS_INTERACTIVE" /D "HAVE_BOOST" /D "HAVE_PYTHON" /D "BOOST_DEBUG_PYTHON" /D "USE_BOOST_128" /D "MSVCBITES" /D "BOOST_PYTHON_STATIC_LIB" /D "OPCODE_COLLIDER" /D "NO_GFX" /YX /FD /c
# ADD BASE RSC /l 0x40c /d "NDEBUG"
# ADD RSC /l 0x40c /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib expat.lib wsock32.lib zlib.lib python25.lib /nologo /subsystem:console /machine:I386 /out:"..\..\data4.x\bin\vegaserver.exe" /libpath:"..\lib"

!ELSEIF  "$(CFG)" == "vsserver - Win32 Debug"

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
# ADD CPP /nologo /w /W0 /Gm /GX /Zi /Od /I "..\..\vegastrike\src\\" /I "..\include\\" /I "..\include\python\\" /I "..\..\vegastrike\boost\1_28\\" /I "..\\" /I "..\..\vegastrike\src\cmd\collide2\\" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /D "_UDP_PROTO" /D "YY_NEVER_INTERACTIVE" /D "YY_ALWAYS_INTERACTIVE" /D "HAVE_BOOST" /D "HAVE_PYTHON" /D "BOOST_DEBUG_PYTHON" /D "USE_BOOST_128" /D "MSVCBITES" /D "BOOST_PYTHON_STATIC_LIB" /D "OPCODE_COLLIDER" /D "NO_GFX" /YX /FD /Zm500 /GZ /c
# ADD BASE RSC /l 0x40c /d "_DEBUG"
# ADD RSC /l 0x40c /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib expat.lib wsock32.lib zlib.lib python25_d.lib /nologo /subsystem:console /debug /machine:I386 /out:"..\..\data4.x\bin\vegaserverd.exe" /pdbtype:sept /libpath:"..\lib"
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "vsserver - Win32 Release"
# Name "vsserver - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
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

SOURCE=..\..\vegastrike\src\faction_generic.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\faction_util_generic.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\faction_util_server.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\force_feedback_server.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\galaxy.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\galaxy_gen.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\galaxy_xml.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\gfxlib_struct_server.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\hashtable.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\libaudioserver.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\libserver.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\lin_time.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\load_mission.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\macosx_math.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\physics.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\pk3.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\posh.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\savegame.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\star_system_generic.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\star_system_xml.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\stardate.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\universe_generic.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\universe_util_generic.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\universe_util_server.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\vegaserver.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\vs_globals.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\vsfilesystem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\xml_serializer.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\xml_support.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\config.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\configxml.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\easydom.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\endianness.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\faction_generic.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\functors.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\galaxy_gen.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\galaxy_xml.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\hashtable.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\lin_time.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\main_loop.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\md5.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\physics.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\SharedPool.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\star_system_generic.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\script\c_alike\unistd.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\universe_generic.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\vegastrike.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\vs_globals.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\vs_random.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\xml_serializer.h
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
# Begin Group "cmd"

# PROP Default_Filter ""
# Begin Group "script"

# PROP Default_Filter ""
# Begin Group "c_alike"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\script\c_alike\c_alike.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\script\c_alike\c_alike.tab.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\script\c_alike\c_alike.tab.cpp.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\script\c_alike\lex.yy.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\script\director_generic.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\script\director_server.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\script\flightgroup_server.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\script\mission.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\script\mission.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\script\mission_script.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\script\msgcenter.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\script\pythonmission.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\script\pythonmission.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\script\script_call_olist.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\script\script_call_omap.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\script\script_call_order.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\script\script_call_string.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\script\script_call_unit_generic.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\script\script_call_unit_server.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\script\script_callbacks.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\script\script_expression.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\script\script_generic.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\script\script_statement.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\script\script_util.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\script\script_variables.cpp
# End Source File
# End Group
# Begin Group "ai"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\ai\aggressive.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\ai\aggressive.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\ai\comm_ai.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\ai\comm_ai.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\ai\communication.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\ai\communication.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\ai\communication_xml.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\ai\docking.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\ai\docking.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\ai\event_xml.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\ai\fire.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\ai\fire.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\ai\fireall.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\ai\flybywire.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\ai\hard_coded_scripts.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\ai\ikarus.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\ai\ikarus.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\ai\missionscript.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\ai\navigation.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\ai\navigation.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\ai\order.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\ai\order.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\ai\order_comm.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\ai\script.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\ai\script.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\ai\tactics.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\ai\turretai.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\ai\turretai.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\ai\warpto.cpp
# End Source File
# End Group
# Begin Group "collide"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\collide\box.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\collide\garray.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\collide\matrix3.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\collide\pbuild.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\collide\peigen.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\collide\prapid.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\collide\prapid.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\collide\qint.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\collide\qsqrt.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\collide\vector3.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\asteroid.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\asteroid_generic.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\atmosphere_server.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\beam_generic.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\beam_server.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\bolt_generic.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\bolt_server.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\building.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\building_generic.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\building_generic.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\collection.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\collection.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\collide.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\collide.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\collide_map.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\collide_map.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\container.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\container.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\csv.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\faction_xml.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\images.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\iterator.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\key_mutable_set.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\missile_generic.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\mount.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\nebula_generic.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\pilot.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\planet_generic.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\role_bitmask.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\unit_armorshield.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\unit_bsp.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\unit_collide.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\unit_const_cache.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\unit_csv.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\unit_csv.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\unit_factory_generic.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\unit_factory_server.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\unit_find.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\unit_functions_generic.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\unit_functions_server.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\unit_generic.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\unit_generic.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\unit_template.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\unit_util.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\unit_util_generic.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\unit_util_server.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\unit_xml.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\unit_xml.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\cmd\weapon_xml.cpp
# End Source File
# End Group
# Begin Group "python"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\vegastrike\src\python\init.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\python\init.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\python\python_class.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\python\python_compile.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\python\python_compile.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\python\python_unit_wrap.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\python\unit_exports.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\python\unit_exports.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\python\unit_exports1.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\python\unit_exports2.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\python\unit_exports3.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\python\unit_method_defs.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\python\unit_wrapper.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\python\universe_util_export.cpp
# End Source File
# End Group
# Begin Group "gfx"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\vegastrike\src\gfx\background_server.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\gfx\bounding_box.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\gfx\bounding_box.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\gfx\bsp.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\gfx\bsp.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\gfx\cockpit_generic.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\gfx\cockpit_generic.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\gfx\lerp.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\gfx\lerp.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\gfx\masks.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\gfx\matrix.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\gfx\mesh.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\gfx\mesh_bin.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\gfx\mesh_bxm.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\gfx\mesh_bxm.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\gfx\mesh_io.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\gfx\mesh_poly.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\gfx\mesh_server.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\gfx\mesh_xml.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\gfx\mesh_xml.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\gfx\quaternion.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\gfx\quaternion.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\gfx\screenshot.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\gfx\sphere_generic.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\gfx\sphere_server.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\gfx\vec.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\gfx\vec.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\gfx\vertex.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\gfx\vsbox.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\gfx\vsbox_server.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\gfx\xvector.h
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

SOURCE=..\..\vegastrike\src\networking\lowlevel\vsnet_cmd.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\lowlevel\vsnet_debug.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\lowlevel\vsnet_dloadenum.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\lowlevel\vsnet_dloadenum.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\lowlevel\vsnet_dloadmgr.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\lowlevel\vsnet_dloadmgr.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\lowlevel\vsnet_err.h
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

SOURCE=..\..\vegastrike\src\networking\lowlevel\vsnet_oss.h
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

SOURCE=..\..\vegastrike\src\networking\lowlevel\vsnet_socketbase.h
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

SOURCE=..\..\vegastrike\src\networking\lowlevel\vsnet_sockettcp.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\lowlevel\vsnet_socketudp.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\lowlevel\vsnet_socketudp.h
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

SOURCE=..\..\vegastrike\src\networking\client.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\client.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\clientptr.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\const.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\cubicsplines.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\cubicsplines.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\fileutil.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\mangle.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\mangle.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\netclass.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\netclient.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\netclient_clients.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\netclient_devices.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\netclient_login.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\netserver.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\netserver.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\netserver_acct.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\netserver_clients.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\netserver_devices.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\netserver_login.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\netserver_net.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\netui.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\networkcomm.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\networkcomm_server.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\prediction.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\prediction.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\savenet_util.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\savenet_util.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\webcam_support.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\webcam_support.h
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\zonemgr.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\networking\zonemgr.h
# End Source File
# End Group
# Begin Group "boost131"

# PROP Default_Filter ""
# Begin Group "object"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\vegastrike\boost\1_31\src\object\class.cpp
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\boost\1_31\src\object\enum.cpp
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\boost\1_31\src\object\function.cpp
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\boost\1_31\src\object\inheritance.cpp
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\boost\1_31\src\object\iterator.cpp
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\boost\1_31\src\object\life_support.cpp
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\boost\1_31\src\object\pickle_support.cpp
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Group "converter"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\vegastrike\boost\1_31\src\converter\arg_to_python_base.cpp
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\boost\1_31\src\converter\builtin_converters.cpp
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\boost\1_31\src\converter\from_python.cpp
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\boost\1_31\src\converter\registry.cpp
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\boost\1_31\src\converter\type_id.cpp
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\vegastrike\boost\1_31\src\aix_init_module.cpp
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\boost\1_31\src\dict.cpp
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\boost\1_31\src\errors.cpp
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\boost\1_31\src\list.cpp
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\boost\1_31\src\long.cpp
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\boost\1_31\src\module.cpp
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\boost\1_31\src\numeric.cpp
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\boost\1_31\src\object_operators.cpp
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\boost\1_31\src\object_protocol.cpp
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\boost\1_31\src\str.cpp
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\boost\1_31\src\tuple.cpp
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Group "gldrv"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\vegastrike\src\gldrv\gl_sphere_list_server.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\gldrv\gl_vertex_list.cpp
# End Source File
# End Group
# Begin Group "common"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\vegastrike\src\common\common.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\src\common\common.h
# End Source File
# End Group
# Begin Group "boost"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\vegastrike\boost\1_28\src\converter\callback.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\boost\1_28\src\classes.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\boost\1_28\src\conversions.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\boost\1_28\src\cross_module.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\boost\1_28\src\errors.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\boost\1_28\src\extension_class.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\boost\1_28\src\object\function.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\boost\1_28\src\functions.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\boost\1_28\src\init_function.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\boost\1_28\src\object\life_support.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\boost\1_28\src\module.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\boost\1_28\src\module_builder.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\boost\1_28\src\objects.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vegastrike\boost\1_28\src\types.cpp
# End Source File
# End Group
# End Target
# End Project
