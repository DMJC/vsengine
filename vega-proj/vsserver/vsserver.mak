# Microsoft Developer Studio Generated NMAKE File, Based on vsserver.dsp
!IF "$(CFG)" == ""
CFG=vsserver - Win32 Debug
!MESSAGE No configuration specified. Defaulting to vsserver - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "vsserver - Win32 Release" && "$(CFG)" != "vsserver - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
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
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "vsserver - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release

ALL : "..\..\data\vegaserver.exe"


CLEAN :
	-@erase "$(INTDIR)\accountsxml.obj"
	-@erase "$(INTDIR)\aggressive.obj"
	-@erase "$(INTDIR)\asteroid_generic.obj"
	-@erase "$(INTDIR)\c_alike.tab.obj"
	-@erase "$(INTDIR)\classes.obj"
	-@erase "$(INTDIR)\clientstructs.obj"
	-@erase "$(INTDIR)\cockpit_generic.obj"
	-@erase "$(INTDIR)\collection.obj"
	-@erase "$(INTDIR)\comm_ai.obj"
	-@erase "$(INTDIR)\common.obj"
	-@erase "$(INTDIR)\communication.obj"
	-@erase "$(INTDIR)\communication_xml.obj"
	-@erase "$(INTDIR)\configxml.obj"
	-@erase "$(INTDIR)\container.obj"
	-@erase "$(INTDIR)\conversions.obj"
	-@erase "$(INTDIR)\cross_module.obj"
	-@erase "$(INTDIR)\cubicsplines.obj"
	-@erase "$(INTDIR)\director_generic.obj"
	-@erase "$(INTDIR)\director_server.obj"
	-@erase "$(INTDIR)\easydom.obj"
	-@erase "$(INTDIR)\endianness.obj"
	-@erase "$(INTDIR)\errors.obj"
	-@erase "$(INTDIR)\event_xml.obj"
	-@erase "$(INTDIR)\extension_class.obj"
	-@erase "$(INTDIR)\faction_generic.obj"
	-@erase "$(INTDIR)\faction_util.obj"
	-@erase "$(INTDIR)\faction_util_server.obj"
	-@erase "$(INTDIR)\fire.obj"
	-@erase "$(INTDIR)\flightgroup_server.obj"
	-@erase "$(INTDIR)\flybywire.obj"
	-@erase "$(INTDIR)\function.obj"
	-@erase "$(INTDIR)\functions.obj"
	-@erase "$(INTDIR)\galaxy.obj"
	-@erase "$(INTDIR)\galaxy_gen.obj"
	-@erase "$(INTDIR)\galaxy_xml.obj"
	-@erase "$(INTDIR)\hard_coded_scripts.obj"
	-@erase "$(INTDIR)\hashtable.obj"
	-@erase "$(INTDIR)\ikarus.obj"
	-@erase "$(INTDIR)\init.obj"
	-@erase "$(INTDIR)\init_function.obj"
	-@erase "$(INTDIR)\lex.yy.obj"
	-@erase "$(INTDIR)\libserver.obj"
	-@erase "$(INTDIR)\life_support.obj"
	-@erase "$(INTDIR)\lin_time.obj"
	-@erase "$(INTDIR)\load_mission.obj"
	-@erase "$(INTDIR)\missile_generic.obj"
	-@erase "$(INTDIR)\mission.obj"
	-@erase "$(INTDIR)\mission_script.obj"
	-@erase "$(INTDIR)\missionscript.obj"
	-@erase "$(INTDIR)\module.obj"
	-@erase "$(INTDIR)\module_builder.obj"
	-@erase "$(INTDIR)\msgcenter.obj"
	-@erase "$(INTDIR)\navigation.obj"
	-@erase "$(INTDIR)\nebula_generic.obj"
	-@erase "$(INTDIR)\netserver.obj"
	-@erase "$(INTDIR)\objects.obj"
	-@erase "$(INTDIR)\order.obj"
	-@erase "$(INTDIR)\order_comm.obj"
	-@erase "$(INTDIR)\packet.obj"
	-@erase "$(INTDIR)\planet_generic.obj"
	-@erase "$(INTDIR)\python_compile.obj"
	-@erase "$(INTDIR)\pythonmission.obj"
	-@erase "$(INTDIR)\quaternion.obj"
	-@erase "$(INTDIR)\savegame.obj"
	-@erase "$(INTDIR)\script.obj"
	-@erase "$(INTDIR)\script_call_olist.obj"
	-@erase "$(INTDIR)\script_call_omap.obj"
	-@erase "$(INTDIR)\script_call_order.obj"
	-@erase "$(INTDIR)\script_call_string.obj"
	-@erase "$(INTDIR)\script_call_unit.obj"
	-@erase "$(INTDIR)\script_call_unit_server.obj"
	-@erase "$(INTDIR)\script_callbacks.obj"
	-@erase "$(INTDIR)\script_expression.obj"
	-@erase "$(INTDIR)\script_generic.obj"
	-@erase "$(INTDIR)\script_statement.obj"
	-@erase "$(INTDIR)\script_util.obj"
	-@erase "$(INTDIR)\script_variables.obj"
	-@erase "$(INTDIR)\star_system_generic.obj"
	-@erase "$(INTDIR)\tactics.obj"
	-@erase "$(INTDIR)\turretai.obj"
	-@erase "$(INTDIR)\types.obj"
	-@erase "$(INTDIR)\unit_factory_generic.obj"
	-@erase "$(INTDIR)\unit_factory_server.obj"
	-@erase "$(INTDIR)\unit_functions_generic.obj"
	-@erase "$(INTDIR)\unit_functions_server.obj"
	-@erase "$(INTDIR)\unit_generic.obj"
	-@erase "$(INTDIR)\unit_util_generic.obj"
	-@erase "$(INTDIR)\unit_util_server.obj"
	-@erase "$(INTDIR)\unit_wrapper.obj"
	-@erase "$(INTDIR)\unit_xml.obj"
	-@erase "$(INTDIR)\universe_generic.obj"
	-@erase "$(INTDIR)\universe_util_generic.obj"
	-@erase "$(INTDIR)\universe_util_server.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vec.obj"
	-@erase "$(INTDIR)\vegaserver.obj"
	-@erase "$(INTDIR)\vs_globals.obj"
	-@erase "$(INTDIR)\vs_path.obj"
	-@erase "$(INTDIR)\vsnet_sockettcp.obj"
	-@erase "$(INTDIR)\vsnet_socketudp.obj"
	-@erase "$(INTDIR)\vsnet_thread_non.obj"
	-@erase "$(INTDIR)\vsnet_thread_p.obj"
	-@erase "$(INTDIR)\vsnet_thread_sdl.obj"
	-@erase "$(INTDIR)\xml_serializer.obj"
	-@erase "$(INTDIR)\xml_support.obj"
	-@erase "$(INTDIR)\zonemgr.obj"
	-@erase "..\..\data\vegaserver.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /GX /O2 /I "..\..\vegastrike\src" /I "..\Include" /I "..\..\vegastrike\src\boost" /I "..\\" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /D "_UDP_PROTO" /D "YY_NEVER_INTERACTIVE" /D "HAVE_AL" /D "HAVE_SDL" /D "YY_ALWAYS_INTERACTIVE" /D "SDL_WINDOWING" /D "HAVE_BOOST" /D "HAVE_PYTHON" /D "BOOST_DEBUG_PYTHON" /Fp"$(INTDIR)\vsserver.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\vsserver.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib expat.lib wsock32.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\vegaserver.pdb" /machine:I386 /out:"..\..\data\vegaserver.exe" /libpath:"..\lib" 
LINK32_OBJS= \
	"$(INTDIR)\configxml.obj" \
	"$(INTDIR)\easydom.obj" \
	"$(INTDIR)\endianness.obj" \
	"$(INTDIR)\faction_generic.obj" \
	"$(INTDIR)\faction_util.obj" \
	"$(INTDIR)\faction_util_server.obj" \
	"$(INTDIR)\galaxy.obj" \
	"$(INTDIR)\galaxy_gen.obj" \
	"$(INTDIR)\galaxy_xml.obj" \
	"$(INTDIR)\hashtable.obj" \
	"$(INTDIR)\libserver.obj" \
	"$(INTDIR)\lin_time.obj" \
	"$(INTDIR)\load_mission.obj" \
	"$(INTDIR)\savegame.obj" \
	"$(INTDIR)\star_system_generic.obj" \
	"$(INTDIR)\universe_generic.obj" \
	"$(INTDIR)\universe_util_generic.obj" \
	"$(INTDIR)\universe_util_server.obj" \
	"$(INTDIR)\vegaserver.obj" \
	"$(INTDIR)\vs_globals.obj" \
	"$(INTDIR)\vs_path.obj" \
	"$(INTDIR)\xml_serializer.obj" \
	"$(INTDIR)\xml_support.obj" \
	"$(INTDIR)\c_alike.tab.obj" \
	"$(INTDIR)\lex.yy.obj" \
	"$(INTDIR)\director_generic.obj" \
	"$(INTDIR)\director_server.obj" \
	"$(INTDIR)\flightgroup_server.obj" \
	"$(INTDIR)\mission.obj" \
	"$(INTDIR)\mission_script.obj" \
	"$(INTDIR)\msgcenter.obj" \
	"$(INTDIR)\pythonmission.obj" \
	"$(INTDIR)\script_call_olist.obj" \
	"$(INTDIR)\script_call_omap.obj" \
	"$(INTDIR)\script_call_order.obj" \
	"$(INTDIR)\script_call_string.obj" \
	"$(INTDIR)\script_call_unit_server.obj" \
	"$(INTDIR)\script_callbacks.obj" \
	"$(INTDIR)\script_expression.obj" \
	"$(INTDIR)\script_generic.obj" \
	"$(INTDIR)\script_statement.obj" \
	"$(INTDIR)\script_util.obj" \
	"$(INTDIR)\script_variables.obj" \
	"$(INTDIR)\aggressive.obj" \
	"$(INTDIR)\comm_ai.obj" \
	"$(INTDIR)\communication.obj" \
	"$(INTDIR)\communication_xml.obj" \
	"$(INTDIR)\event_xml.obj" \
	"$(INTDIR)\fire.obj" \
	"$(INTDIR)\flybywire.obj" \
	"$(INTDIR)\hard_coded_scripts.obj" \
	"$(INTDIR)\ikarus.obj" \
	"$(INTDIR)\missionscript.obj" \
	"$(INTDIR)\navigation.obj" \
	"$(INTDIR)\order.obj" \
	"$(INTDIR)\order_comm.obj" \
	"$(INTDIR)\script.obj" \
	"$(INTDIR)\tactics.obj" \
	"$(INTDIR)\turretai.obj" \
	"$(INTDIR)\asteroid_generic.obj" \
	"$(INTDIR)\collection.obj" \
	"$(INTDIR)\container.obj" \
	"$(INTDIR)\missile_generic.obj" \
	"$(INTDIR)\nebula_generic.obj" \
	"$(INTDIR)\planet_generic.obj" \
	"$(INTDIR)\unit_factory_generic.obj" \
	"$(INTDIR)\unit_factory_server.obj" \
	"$(INTDIR)\unit_functions_generic.obj" \
	"$(INTDIR)\unit_functions_server.obj" \
	"$(INTDIR)\unit_generic.obj" \
	"$(INTDIR)\unit_util_generic.obj" \
	"$(INTDIR)\unit_util_server.obj" \
	"$(INTDIR)\unit_xml.obj" \
	"$(INTDIR)\init.obj" \
	"$(INTDIR)\python_compile.obj" \
	"$(INTDIR)\unit_wrapper.obj" \
	"$(INTDIR)\cockpit_generic.obj" \
	"$(INTDIR)\quaternion.obj" \
	"$(INTDIR)\vec.obj" \
	"$(INTDIR)\accountsxml.obj" \
	"$(INTDIR)\clientstructs.obj" \
	"$(INTDIR)\cubicsplines.obj" \
	"$(INTDIR)\netserver.obj" \
	"$(INTDIR)\packet.obj" \
	"$(INTDIR)\zonemgr.obj" \
	"$(INTDIR)\function.obj" \
	"$(INTDIR)\life_support.obj" \
	"$(INTDIR)\classes.obj" \
	"$(INTDIR)\conversions.obj" \
	"$(INTDIR)\cross_module.obj" \
	"$(INTDIR)\errors.obj" \
	"$(INTDIR)\extension_class.obj" \
	"$(INTDIR)\functions.obj" \
	"$(INTDIR)\init_function.obj" \
	"$(INTDIR)\module.obj" \
	"$(INTDIR)\module_builder.obj" \
	"$(INTDIR)\objects.obj" \
	"$(INTDIR)\types.obj" \
	"$(INTDIR)\common.obj" \
	"$(INTDIR)\script_call_unit.obj" \
	"$(INTDIR)\vsnet_sockettcp.obj" \
	"$(INTDIR)\vsnet_socketudp.obj" \
	"$(INTDIR)\vsnet_thread_non.obj" \
	"$(INTDIR)\vsnet_thread_p.obj" \
	"$(INTDIR)\vsnet_thread_sdl.obj"

"..\..\data\vegaserver.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "vsserver - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug

ALL : "..\..\data\vegaserver.exe"


CLEAN :
	-@erase "$(INTDIR)\accountsxml.obj"
	-@erase "$(INTDIR)\aggressive.obj"
	-@erase "$(INTDIR)\asteroid_generic.obj"
	-@erase "$(INTDIR)\c_alike.tab.obj"
	-@erase "$(INTDIR)\classes.obj"
	-@erase "$(INTDIR)\clientstructs.obj"
	-@erase "$(INTDIR)\cockpit_generic.obj"
	-@erase "$(INTDIR)\collection.obj"
	-@erase "$(INTDIR)\comm_ai.obj"
	-@erase "$(INTDIR)\common.obj"
	-@erase "$(INTDIR)\communication.obj"
	-@erase "$(INTDIR)\communication_xml.obj"
	-@erase "$(INTDIR)\configxml.obj"
	-@erase "$(INTDIR)\container.obj"
	-@erase "$(INTDIR)\conversions.obj"
	-@erase "$(INTDIR)\cross_module.obj"
	-@erase "$(INTDIR)\cubicsplines.obj"
	-@erase "$(INTDIR)\director_generic.obj"
	-@erase "$(INTDIR)\director_server.obj"
	-@erase "$(INTDIR)\easydom.obj"
	-@erase "$(INTDIR)\endianness.obj"
	-@erase "$(INTDIR)\errors.obj"
	-@erase "$(INTDIR)\event_xml.obj"
	-@erase "$(INTDIR)\extension_class.obj"
	-@erase "$(INTDIR)\faction_generic.obj"
	-@erase "$(INTDIR)\faction_util.obj"
	-@erase "$(INTDIR)\faction_util_server.obj"
	-@erase "$(INTDIR)\fire.obj"
	-@erase "$(INTDIR)\flightgroup_server.obj"
	-@erase "$(INTDIR)\flybywire.obj"
	-@erase "$(INTDIR)\function.obj"
	-@erase "$(INTDIR)\functions.obj"
	-@erase "$(INTDIR)\galaxy.obj"
	-@erase "$(INTDIR)\galaxy_gen.obj"
	-@erase "$(INTDIR)\galaxy_xml.obj"
	-@erase "$(INTDIR)\hard_coded_scripts.obj"
	-@erase "$(INTDIR)\hashtable.obj"
	-@erase "$(INTDIR)\ikarus.obj"
	-@erase "$(INTDIR)\init.obj"
	-@erase "$(INTDIR)\init_function.obj"
	-@erase "$(INTDIR)\lex.yy.obj"
	-@erase "$(INTDIR)\libserver.obj"
	-@erase "$(INTDIR)\life_support.obj"
	-@erase "$(INTDIR)\lin_time.obj"
	-@erase "$(INTDIR)\load_mission.obj"
	-@erase "$(INTDIR)\missile_generic.obj"
	-@erase "$(INTDIR)\mission.obj"
	-@erase "$(INTDIR)\mission_script.obj"
	-@erase "$(INTDIR)\missionscript.obj"
	-@erase "$(INTDIR)\module.obj"
	-@erase "$(INTDIR)\module_builder.obj"
	-@erase "$(INTDIR)\msgcenter.obj"
	-@erase "$(INTDIR)\navigation.obj"
	-@erase "$(INTDIR)\nebula_generic.obj"
	-@erase "$(INTDIR)\netserver.obj"
	-@erase "$(INTDIR)\objects.obj"
	-@erase "$(INTDIR)\order.obj"
	-@erase "$(INTDIR)\order_comm.obj"
	-@erase "$(INTDIR)\packet.obj"
	-@erase "$(INTDIR)\planet_generic.obj"
	-@erase "$(INTDIR)\python_compile.obj"
	-@erase "$(INTDIR)\pythonmission.obj"
	-@erase "$(INTDIR)\quaternion.obj"
	-@erase "$(INTDIR)\savegame.obj"
	-@erase "$(INTDIR)\script.obj"
	-@erase "$(INTDIR)\script_call_olist.obj"
	-@erase "$(INTDIR)\script_call_omap.obj"
	-@erase "$(INTDIR)\script_call_order.obj"
	-@erase "$(INTDIR)\script_call_string.obj"
	-@erase "$(INTDIR)\script_call_unit.obj"
	-@erase "$(INTDIR)\script_call_unit_server.obj"
	-@erase "$(INTDIR)\script_callbacks.obj"
	-@erase "$(INTDIR)\script_expression.obj"
	-@erase "$(INTDIR)\script_generic.obj"
	-@erase "$(INTDIR)\script_statement.obj"
	-@erase "$(INTDIR)\script_util.obj"
	-@erase "$(INTDIR)\script_variables.obj"
	-@erase "$(INTDIR)\star_system_generic.obj"
	-@erase "$(INTDIR)\tactics.obj"
	-@erase "$(INTDIR)\turretai.obj"
	-@erase "$(INTDIR)\types.obj"
	-@erase "$(INTDIR)\unit_factory_generic.obj"
	-@erase "$(INTDIR)\unit_factory_server.obj"
	-@erase "$(INTDIR)\unit_functions_generic.obj"
	-@erase "$(INTDIR)\unit_functions_server.obj"
	-@erase "$(INTDIR)\unit_generic.obj"
	-@erase "$(INTDIR)\unit_util_generic.obj"
	-@erase "$(INTDIR)\unit_util_server.obj"
	-@erase "$(INTDIR)\unit_wrapper.obj"
	-@erase "$(INTDIR)\unit_xml.obj"
	-@erase "$(INTDIR)\universe_generic.obj"
	-@erase "$(INTDIR)\universe_util_generic.obj"
	-@erase "$(INTDIR)\universe_util_server.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\vec.obj"
	-@erase "$(INTDIR)\vegaserver.obj"
	-@erase "$(INTDIR)\vs_globals.obj"
	-@erase "$(INTDIR)\vs_path.obj"
	-@erase "$(INTDIR)\vsnet_sockettcp.obj"
	-@erase "$(INTDIR)\vsnet_socketudp.obj"
	-@erase "$(INTDIR)\vsnet_thread_non.obj"
	-@erase "$(INTDIR)\vsnet_thread_p.obj"
	-@erase "$(INTDIR)\vsnet_thread_sdl.obj"
	-@erase "$(INTDIR)\xml_serializer.obj"
	-@erase "$(INTDIR)\xml_support.obj"
	-@erase "$(INTDIR)\zonemgr.obj"
	-@erase "$(OUTDIR)\vegaserver.pdb"
	-@erase "..\..\data\vegaserver.exe"
	-@erase "..\..\data\vegaserver.ilk"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /w /W0 /Gm /GX /ZI /Od /I "..\..\vegastrike\src" /I "..\Include" /I "..\..\vegastrike\src\boost" /I "..\\" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "_UDP_PROTO" /D "YY_NEVER_INTERACTIVE" /D "HAVE_AL" /D "HAVE_SDL" /D "YY_ALWAYS_INTERACTIVE" /D "SDL_WINDOWING" /D "HAVE_BOOST" /D "HAVE_PYTHON" /D "BOOST_DEBUG_PYTHON" /Fp"$(INTDIR)\vsserver.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\vsserver.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib expat.lib wsock32.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\vegaserver.pdb" /debug /machine:I386 /out:"..\..\data\vegaserver.exe" /pdbtype:sept /libpath:"..\lib" 
LINK32_OBJS= \
	"$(INTDIR)\configxml.obj" \
	"$(INTDIR)\easydom.obj" \
	"$(INTDIR)\endianness.obj" \
	"$(INTDIR)\faction_generic.obj" \
	"$(INTDIR)\faction_util.obj" \
	"$(INTDIR)\faction_util_server.obj" \
	"$(INTDIR)\galaxy.obj" \
	"$(INTDIR)\galaxy_gen.obj" \
	"$(INTDIR)\galaxy_xml.obj" \
	"$(INTDIR)\hashtable.obj" \
	"$(INTDIR)\libserver.obj" \
	"$(INTDIR)\lin_time.obj" \
	"$(INTDIR)\load_mission.obj" \
	"$(INTDIR)\savegame.obj" \
	"$(INTDIR)\star_system_generic.obj" \
	"$(INTDIR)\universe_generic.obj" \
	"$(INTDIR)\universe_util_generic.obj" \
	"$(INTDIR)\universe_util_server.obj" \
	"$(INTDIR)\vegaserver.obj" \
	"$(INTDIR)\vs_globals.obj" \
	"$(INTDIR)\vs_path.obj" \
	"$(INTDIR)\xml_serializer.obj" \
	"$(INTDIR)\xml_support.obj" \
	"$(INTDIR)\c_alike.tab.obj" \
	"$(INTDIR)\lex.yy.obj" \
	"$(INTDIR)\director_generic.obj" \
	"$(INTDIR)\director_server.obj" \
	"$(INTDIR)\flightgroup_server.obj" \
	"$(INTDIR)\mission.obj" \
	"$(INTDIR)\mission_script.obj" \
	"$(INTDIR)\msgcenter.obj" \
	"$(INTDIR)\pythonmission.obj" \
	"$(INTDIR)\script_call_olist.obj" \
	"$(INTDIR)\script_call_omap.obj" \
	"$(INTDIR)\script_call_order.obj" \
	"$(INTDIR)\script_call_string.obj" \
	"$(INTDIR)\script_call_unit_server.obj" \
	"$(INTDIR)\script_callbacks.obj" \
	"$(INTDIR)\script_expression.obj" \
	"$(INTDIR)\script_generic.obj" \
	"$(INTDIR)\script_statement.obj" \
	"$(INTDIR)\script_util.obj" \
	"$(INTDIR)\script_variables.obj" \
	"$(INTDIR)\aggressive.obj" \
	"$(INTDIR)\comm_ai.obj" \
	"$(INTDIR)\communication.obj" \
	"$(INTDIR)\communication_xml.obj" \
	"$(INTDIR)\event_xml.obj" \
	"$(INTDIR)\fire.obj" \
	"$(INTDIR)\flybywire.obj" \
	"$(INTDIR)\hard_coded_scripts.obj" \
	"$(INTDIR)\ikarus.obj" \
	"$(INTDIR)\missionscript.obj" \
	"$(INTDIR)\navigation.obj" \
	"$(INTDIR)\order.obj" \
	"$(INTDIR)\order_comm.obj" \
	"$(INTDIR)\script.obj" \
	"$(INTDIR)\tactics.obj" \
	"$(INTDIR)\turretai.obj" \
	"$(INTDIR)\asteroid_generic.obj" \
	"$(INTDIR)\collection.obj" \
	"$(INTDIR)\container.obj" \
	"$(INTDIR)\missile_generic.obj" \
	"$(INTDIR)\nebula_generic.obj" \
	"$(INTDIR)\planet_generic.obj" \
	"$(INTDIR)\unit_factory_generic.obj" \
	"$(INTDIR)\unit_factory_server.obj" \
	"$(INTDIR)\unit_functions_generic.obj" \
	"$(INTDIR)\unit_functions_server.obj" \
	"$(INTDIR)\unit_generic.obj" \
	"$(INTDIR)\unit_util_generic.obj" \
	"$(INTDIR)\unit_util_server.obj" \
	"$(INTDIR)\unit_xml.obj" \
	"$(INTDIR)\init.obj" \
	"$(INTDIR)\python_compile.obj" \
	"$(INTDIR)\unit_wrapper.obj" \
	"$(INTDIR)\cockpit_generic.obj" \
	"$(INTDIR)\quaternion.obj" \
	"$(INTDIR)\vec.obj" \
	"$(INTDIR)\accountsxml.obj" \
	"$(INTDIR)\clientstructs.obj" \
	"$(INTDIR)\cubicsplines.obj" \
	"$(INTDIR)\netserver.obj" \
	"$(INTDIR)\packet.obj" \
	"$(INTDIR)\zonemgr.obj" \
	"$(INTDIR)\function.obj" \
	"$(INTDIR)\life_support.obj" \
	"$(INTDIR)\classes.obj" \
	"$(INTDIR)\conversions.obj" \
	"$(INTDIR)\cross_module.obj" \
	"$(INTDIR)\errors.obj" \
	"$(INTDIR)\extension_class.obj" \
	"$(INTDIR)\functions.obj" \
	"$(INTDIR)\init_function.obj" \
	"$(INTDIR)\module.obj" \
	"$(INTDIR)\module_builder.obj" \
	"$(INTDIR)\objects.obj" \
	"$(INTDIR)\types.obj" \
	"$(INTDIR)\common.obj" \
	"$(INTDIR)\script_call_unit.obj" \
	"$(INTDIR)\vsnet_sockettcp.obj" \
	"$(INTDIR)\vsnet_socketudp.obj" \
	"$(INTDIR)\vsnet_thread_non.obj" \
	"$(INTDIR)\vsnet_thread_p.obj" \
	"$(INTDIR)\vsnet_thread_sdl.obj"

"..\..\data\vegaserver.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("vsserver.dep")
!INCLUDE "vsserver.dep"
!ELSE 
!MESSAGE Warning: cannot find "vsserver.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "vsserver - Win32 Release" || "$(CFG)" == "vsserver - Win32 Debug"
SOURCE=..\..\vegastrike\src\configxml.cpp

"$(INTDIR)\configxml.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\easydom.cpp

"$(INTDIR)\easydom.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\endianness.cpp

"$(INTDIR)\endianness.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\faction_generic.cpp

"$(INTDIR)\faction_generic.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\faction_util.cpp

"$(INTDIR)\faction_util.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\faction_util_server.cpp

"$(INTDIR)\faction_util_server.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\galaxy.cpp

"$(INTDIR)\galaxy.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\galaxy_gen.cpp

"$(INTDIR)\galaxy_gen.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\galaxy_xml.cpp

"$(INTDIR)\galaxy_xml.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\hashtable.cpp

"$(INTDIR)\hashtable.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\libserver.cpp

"$(INTDIR)\libserver.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\lin_time.cpp

"$(INTDIR)\lin_time.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\load_mission.cpp

"$(INTDIR)\load_mission.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\savegame.cpp

"$(INTDIR)\savegame.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\star_system_generic.cpp

"$(INTDIR)\star_system_generic.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\universe_generic.cpp

"$(INTDIR)\universe_generic.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\universe_util_generic.cpp

"$(INTDIR)\universe_util_generic.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\universe_util_server.cpp

"$(INTDIR)\universe_util_server.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\vegaserver.cpp

"$(INTDIR)\vegaserver.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\vs_globals.cpp

"$(INTDIR)\vs_globals.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\vs_path.cpp

"$(INTDIR)\vs_path.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\xml_serializer.cpp

"$(INTDIR)\xml_serializer.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\xml_support.cpp

"$(INTDIR)\xml_support.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\script\c_alike\c_alike.tab.cpp

"$(INTDIR)\c_alike.tab.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\script\c_alike\lex.yy.cpp

"$(INTDIR)\lex.yy.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\script\director_generic.cpp

"$(INTDIR)\director_generic.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\script\director_server.cpp

"$(INTDIR)\director_server.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\script\flightgroup_server.cpp

"$(INTDIR)\flightgroup_server.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\script\mission.cpp

"$(INTDIR)\mission.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\script\mission_script.cpp

"$(INTDIR)\mission_script.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\script\msgcenter.cpp

"$(INTDIR)\msgcenter.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\script\pythonmission.cpp

"$(INTDIR)\pythonmission.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\script\script_call_olist.cpp

"$(INTDIR)\script_call_olist.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\script\script_call_omap.cpp

"$(INTDIR)\script_call_omap.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\script\script_call_order.cpp

"$(INTDIR)\script_call_order.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\script\script_call_string.cpp

"$(INTDIR)\script_call_string.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\script\script_call_unit.cpp

"$(INTDIR)\script_call_unit.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\script\script_call_unit_server.cpp

"$(INTDIR)\script_call_unit_server.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\script\script_callbacks.cpp

"$(INTDIR)\script_callbacks.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\script\script_expression.cpp

"$(INTDIR)\script_expression.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\script\script_generic.cpp

"$(INTDIR)\script_generic.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\script\script_statement.cpp

"$(INTDIR)\script_statement.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\script\script_util.cpp

"$(INTDIR)\script_util.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\script\script_variables.cpp

"$(INTDIR)\script_variables.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\ai\aggressive.cpp

"$(INTDIR)\aggressive.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\ai\comm_ai.cpp

"$(INTDIR)\comm_ai.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\ai\communication.cpp

"$(INTDIR)\communication.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\ai\communication_xml.cpp

"$(INTDIR)\communication_xml.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\ai\event_xml.cpp

"$(INTDIR)\event_xml.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\ai\fire.cpp

"$(INTDIR)\fire.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\ai\flybywire.cpp

"$(INTDIR)\flybywire.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\ai\hard_coded_scripts.cpp

"$(INTDIR)\hard_coded_scripts.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\ai\ikarus.cpp

"$(INTDIR)\ikarus.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\ai\missionscript.cpp

"$(INTDIR)\missionscript.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\ai\navigation.cpp

"$(INTDIR)\navigation.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\ai\order.cpp

"$(INTDIR)\order.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\ai\order_comm.cpp

"$(INTDIR)\order_comm.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\ai\script.cpp

"$(INTDIR)\script.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\ai\tactics.cpp

"$(INTDIR)\tactics.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\ai\turretai.cpp

"$(INTDIR)\turretai.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\asteroid_generic.cpp

"$(INTDIR)\asteroid_generic.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\collection.cpp

"$(INTDIR)\collection.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\container.cpp

"$(INTDIR)\container.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\missile_generic.cpp

"$(INTDIR)\missile_generic.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\nebula_generic.cpp

"$(INTDIR)\nebula_generic.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\planet_generic.cpp

"$(INTDIR)\planet_generic.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\unit_factory_generic.cpp

"$(INTDIR)\unit_factory_generic.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\unit_factory_server.cpp

"$(INTDIR)\unit_factory_server.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\unit_functions_generic.cpp

"$(INTDIR)\unit_functions_generic.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\unit_functions_server.cpp

"$(INTDIR)\unit_functions_server.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\unit_generic.cpp

"$(INTDIR)\unit_generic.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\unit_util_generic.cpp

"$(INTDIR)\unit_util_generic.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\unit_util_server.cpp

"$(INTDIR)\unit_util_server.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\cmd\unit_xml.cpp

"$(INTDIR)\unit_xml.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\python\init.cpp

"$(INTDIR)\init.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\python\python_compile.cpp

"$(INTDIR)\python_compile.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\python\unit_wrapper.cpp

"$(INTDIR)\unit_wrapper.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\gfx\cockpit_generic.cpp

"$(INTDIR)\cockpit_generic.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\gfx\quaternion.cpp

"$(INTDIR)\quaternion.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\gfx\vec.cpp

"$(INTDIR)\vec.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\networking\accountsxml.cpp

"$(INTDIR)\accountsxml.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\networking\clientstructs.cpp

"$(INTDIR)\clientstructs.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\networking\cubicsplines.cpp

"$(INTDIR)\cubicsplines.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\networking\netserver.cpp

"$(INTDIR)\netserver.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\networking\packet.cpp

"$(INTDIR)\packet.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\networking\vsnet_sockettcp.cpp

"$(INTDIR)\vsnet_sockettcp.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\networking\vsnet_socketudp.cpp

"$(INTDIR)\vsnet_socketudp.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\networking\vsnet_thread_non.cpp

"$(INTDIR)\vsnet_thread_non.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\networking\vsnet_thread_p.cpp

"$(INTDIR)\vsnet_thread_p.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\networking\vsnet_thread_sdl.cpp

"$(INTDIR)\vsnet_thread_sdl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\networking\zonemgr.cpp

"$(INTDIR)\zonemgr.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\boost\object\function.cpp

"$(INTDIR)\function.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\boost\object\life_support.cpp

"$(INTDIR)\life_support.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\boost\classes.cpp

"$(INTDIR)\classes.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\boost\conversions.cpp

"$(INTDIR)\conversions.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\boost\cross_module.cpp

"$(INTDIR)\cross_module.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\boost\errors.cpp

"$(INTDIR)\errors.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\boost\extension_class.cpp

"$(INTDIR)\extension_class.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\boost\functions.cpp

"$(INTDIR)\functions.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\boost\init_function.cpp

"$(INTDIR)\init_function.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\boost\module.cpp

"$(INTDIR)\module.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\boost\module_builder.cpp

"$(INTDIR)\module_builder.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\boost\objects.cpp

"$(INTDIR)\objects.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\boost\types.cpp

"$(INTDIR)\types.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\vegastrike\src\common\common.cpp

"$(INTDIR)\common.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)



!ENDIF 

