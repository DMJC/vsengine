# Microsoft Developer Studio Generated NMAKE File, Based on texturizer.dsp
!IF "$(CFG)" == ""
CFG=texturizer - Win32 Debug
!MESSAGE No configuration specified. Defaulting to texturizer - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "texturizer - Win32 Release" && "$(CFG)" != "texturizer - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
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
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "texturizer - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release

ALL : "..\..\data\Texturizer.exe"


CLEAN :
	-@erase "$(INTDIR)\cmd_gun.obj"
	-@erase "$(INTDIR)\cmd_input_dfa.obj"
	-@erase "$(INTDIR)\cmd_order.obj"
	-@erase "$(INTDIR)\cmd_physics.obj"
	-@erase "$(INTDIR)\cmd_unit.obj"
	-@erase "$(INTDIR)\cmd_unit_xml.obj"
	-@erase "$(INTDIR)\EnvironmentMapGenerator.obj"
	-@erase "$(INTDIR)\gfx_animation.obj"
	-@erase "$(INTDIR)\gfx_aux_logo.obj"
	-@erase "$(INTDIR)\gfx_aux_palette.obj"
	-@erase "$(INTDIR)\gfx_aux_texture.obj"
	-@erase "$(INTDIR)\gfx_background.obj"
	-@erase "$(INTDIR)\gfx_bounding_box.obj"
	-@erase "$(INTDIR)\gfx_box.obj"
	-@erase "$(INTDIR)\gfx_bsp.obj"
	-@erase "$(INTDIR)\gfx_camera.obj"
	-@erase "$(INTDIR)\gfx_click_list.obj"
	-@erase "$(INTDIR)\gfx_coordinate_select.obj"
	-@erase "$(INTDIR)\gfx_hud.obj"
	-@erase "$(INTDIR)\gfx_lerp.obj"
	-@erase "$(INTDIR)\gfx_location_select.obj"
	-@erase "$(INTDIR)\gfx_mesh.obj"
	-@erase "$(INTDIR)\gfx_mesh_xml.obj"
	-@erase "$(INTDIR)\gfx_primitive.obj"
	-@erase "$(INTDIR)\gfx_sphere.obj"
	-@erase "$(INTDIR)\gfx_sprite.obj"
	-@erase "$(INTDIR)\gfx_transform_matrix.obj"
	-@erase "$(INTDIR)\gfx_transform_vector.obj"
	-@erase "$(INTDIR)\gl_globals.obj"
	-@erase "$(INTDIR)\gl_init.obj"
	-@erase "$(INTDIR)\gl_light.obj"
	-@erase "$(INTDIR)\gl_material.obj"
	-@erase "$(INTDIR)\gl_matrix.obj"
	-@erase "$(INTDIR)\gl_misc.obj"
	-@erase "$(INTDIR)\gl_pick.obj"
	-@erase "$(INTDIR)\gl_state.obj"
	-@erase "$(INTDIR)\gl_texture.obj"
	-@erase "$(INTDIR)\gl_vertex_list.obj"
	-@erase "$(INTDIR)\hashtable.obj"
	-@erase "$(INTDIR)\in_handler.obj"
	-@erase "$(INTDIR)\in_kb.obj"
	-@erase "$(INTDIR)\in_main.obj"
	-@erase "$(INTDIR)\in_mouse.obj"
	-@erase "$(INTDIR)\lin_time.obj"
	-@erase "$(INTDIR)\main.obj"
	-@erase "$(INTDIR)\main_loop.obj"
	-@erase "$(INTDIR)\physics.obj"
	-@erase "$(INTDIR)\planet.obj"
	-@erase "$(INTDIR)\png_texture.obj"
	-@erase "$(INTDIR)\png_write.obj"
	-@erase "$(INTDIR)\quaternion.obj"
	-@erase "$(INTDIR)\star_system.obj"
	-@erase "$(INTDIR)\texturizer.obj"
	-@erase "$(INTDIR)\UnitCollection.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\wrapgfx.obj"
	-@erase "$(INTDIR)\xml_end.obj"
	-@erase "$(INTDIR)\xml_support.obj"
	-@erase "$(INTDIR)\xmlassist.obj"
	-@erase "..\..\data\Texturizer.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /GX /O2 /I "..\..\vegastrike\src\\" /I "..\..\vegastrike\vc98\\" /I "..\include\\" /I ".\\" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\texturizer.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\texturizer.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib glut32.lib expat.lib libpng2.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\Texturizer.pdb" /machine:I386 /out:"..\..\data\Texturizer.exe" /libpath:"..\..\vegastrike\vc98\\" /libpath:"..\lib\\" 
LINK32_OBJS= \
	"$(INTDIR)\cmd_gun.obj" \
	"$(INTDIR)\cmd_input_dfa.obj" \
	"$(INTDIR)\cmd_order.obj" \
	"$(INTDIR)\cmd_physics.obj" \
	"$(INTDIR)\cmd_unit.obj" \
	"$(INTDIR)\cmd_unit_xml.obj" \
	"$(INTDIR)\EnvironmentMapGenerator.obj" \
	"$(INTDIR)\gfx_animation.obj" \
	"$(INTDIR)\gfx_aux_logo.obj" \
	"$(INTDIR)\gfx_aux_palette.obj" \
	"$(INTDIR)\gfx_aux_texture.obj" \
	"$(INTDIR)\gfx_background.obj" \
	"$(INTDIR)\gfx_bounding_box.obj" \
	"$(INTDIR)\gfx_box.obj" \
	"$(INTDIR)\gfx_bsp.obj" \
	"$(INTDIR)\gfx_camera.obj" \
	"$(INTDIR)\gfx_click_list.obj" \
	"$(INTDIR)\gfx_coordinate_select.obj" \
	"$(INTDIR)\gfx_hud.obj" \
	"$(INTDIR)\gfx_lerp.obj" \
	"$(INTDIR)\gfx_location_select.obj" \
	"$(INTDIR)\gfx_mesh.obj" \
	"$(INTDIR)\gfx_mesh_xml.obj" \
	"$(INTDIR)\gfx_primitive.obj" \
	"$(INTDIR)\gfx_sphere.obj" \
	"$(INTDIR)\gfx_sprite.obj" \
	"$(INTDIR)\gfx_transform_matrix.obj" \
	"$(INTDIR)\gfx_transform_vector.obj" \
	"$(INTDIR)\gl_globals.obj" \
	"$(INTDIR)\gl_init.obj" \
	"$(INTDIR)\gl_light.obj" \
	"$(INTDIR)\gl_material.obj" \
	"$(INTDIR)\gl_matrix.obj" \
	"$(INTDIR)\gl_misc.obj" \
	"$(INTDIR)\gl_pick.obj" \
	"$(INTDIR)\gl_state.obj" \
	"$(INTDIR)\gl_texture.obj" \
	"$(INTDIR)\gl_vertex_list.obj" \
	"$(INTDIR)\hashtable.obj" \
	"$(INTDIR)\in_handler.obj" \
	"$(INTDIR)\in_kb.obj" \
	"$(INTDIR)\in_main.obj" \
	"$(INTDIR)\in_mouse.obj" \
	"$(INTDIR)\lin_time.obj" \
	"$(INTDIR)\main.obj" \
	"$(INTDIR)\main_loop.obj" \
	"$(INTDIR)\physics.obj" \
	"$(INTDIR)\planet.obj" \
	"$(INTDIR)\png_texture.obj" \
	"$(INTDIR)\png_write.obj" \
	"$(INTDIR)\quaternion.obj" \
	"$(INTDIR)\star_system.obj" \
	"$(INTDIR)\texturizer.obj" \
	"$(INTDIR)\UnitCollection.obj" \
	"$(INTDIR)\wrapgfx.obj" \
	"$(INTDIR)\xml_end.obj" \
	"$(INTDIR)\xml_support.obj" \
	"$(INTDIR)\xmlassist.obj"

"..\..\data\Texturizer.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "texturizer - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug

ALL : "..\..\data\Texturizer.exe"


CLEAN :
	-@erase "$(INTDIR)\cmd_gun.obj"
	-@erase "$(INTDIR)\cmd_input_dfa.obj"
	-@erase "$(INTDIR)\cmd_order.obj"
	-@erase "$(INTDIR)\cmd_physics.obj"
	-@erase "$(INTDIR)\cmd_unit.obj"
	-@erase "$(INTDIR)\cmd_unit_xml.obj"
	-@erase "$(INTDIR)\EnvironmentMapGenerator.obj"
	-@erase "$(INTDIR)\gfx_animation.obj"
	-@erase "$(INTDIR)\gfx_aux_logo.obj"
	-@erase "$(INTDIR)\gfx_aux_palette.obj"
	-@erase "$(INTDIR)\gfx_aux_texture.obj"
	-@erase "$(INTDIR)\gfx_background.obj"
	-@erase "$(INTDIR)\gfx_bounding_box.obj"
	-@erase "$(INTDIR)\gfx_box.obj"
	-@erase "$(INTDIR)\gfx_bsp.obj"
	-@erase "$(INTDIR)\gfx_camera.obj"
	-@erase "$(INTDIR)\gfx_click_list.obj"
	-@erase "$(INTDIR)\gfx_coordinate_select.obj"
	-@erase "$(INTDIR)\gfx_hud.obj"
	-@erase "$(INTDIR)\gfx_lerp.obj"
	-@erase "$(INTDIR)\gfx_location_select.obj"
	-@erase "$(INTDIR)\gfx_mesh.obj"
	-@erase "$(INTDIR)\gfx_mesh_xml.obj"
	-@erase "$(INTDIR)\gfx_primitive.obj"
	-@erase "$(INTDIR)\gfx_sphere.obj"
	-@erase "$(INTDIR)\gfx_sprite.obj"
	-@erase "$(INTDIR)\gfx_transform_matrix.obj"
	-@erase "$(INTDIR)\gfx_transform_vector.obj"
	-@erase "$(INTDIR)\gl_globals.obj"
	-@erase "$(INTDIR)\gl_init.obj"
	-@erase "$(INTDIR)\gl_light.obj"
	-@erase "$(INTDIR)\gl_material.obj"
	-@erase "$(INTDIR)\gl_matrix.obj"
	-@erase "$(INTDIR)\gl_misc.obj"
	-@erase "$(INTDIR)\gl_pick.obj"
	-@erase "$(INTDIR)\gl_state.obj"
	-@erase "$(INTDIR)\gl_texture.obj"
	-@erase "$(INTDIR)\gl_vertex_list.obj"
	-@erase "$(INTDIR)\hashtable.obj"
	-@erase "$(INTDIR)\in_handler.obj"
	-@erase "$(INTDIR)\in_kb.obj"
	-@erase "$(INTDIR)\in_main.obj"
	-@erase "$(INTDIR)\in_mouse.obj"
	-@erase "$(INTDIR)\lin_time.obj"
	-@erase "$(INTDIR)\main.obj"
	-@erase "$(INTDIR)\main_loop.obj"
	-@erase "$(INTDIR)\physics.obj"
	-@erase "$(INTDIR)\planet.obj"
	-@erase "$(INTDIR)\png_texture.obj"
	-@erase "$(INTDIR)\png_write.obj"
	-@erase "$(INTDIR)\quaternion.obj"
	-@erase "$(INTDIR)\star_system.obj"
	-@erase "$(INTDIR)\texturizer.obj"
	-@erase "$(INTDIR)\UnitCollection.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\wrapgfx.obj"
	-@erase "$(INTDIR)\xml_end.obj"
	-@erase "$(INTDIR)\xml_support.obj"
	-@erase "$(INTDIR)\xmlassist.obj"
	-@erase "$(OUTDIR)\Texturizer.pdb"
	-@erase "..\..\data\Texturizer.exe"
	-@erase "..\..\data\Texturizer.ilk"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /I "..\..\vegastrike\src\\" /I "..\..\vegastrike\vc98\\" /I "..\include\\" /I ".\\" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\texturizer.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\texturizer.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib glut32.lib expat.lib libpng2.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\Texturizer.pdb" /debug /machine:I386 /out:"..\..\data\Texturizer.exe" /pdbtype:sept /libpath:"..\..\vegastrike\vc98\\" /libpath:"..\lib\\" 
LINK32_OBJS= \
	"$(INTDIR)\cmd_gun.obj" \
	"$(INTDIR)\cmd_input_dfa.obj" \
	"$(INTDIR)\cmd_order.obj" \
	"$(INTDIR)\cmd_physics.obj" \
	"$(INTDIR)\cmd_unit.obj" \
	"$(INTDIR)\cmd_unit_xml.obj" \
	"$(INTDIR)\EnvironmentMapGenerator.obj" \
	"$(INTDIR)\gfx_animation.obj" \
	"$(INTDIR)\gfx_aux_logo.obj" \
	"$(INTDIR)\gfx_aux_palette.obj" \
	"$(INTDIR)\gfx_aux_texture.obj" \
	"$(INTDIR)\gfx_background.obj" \
	"$(INTDIR)\gfx_bounding_box.obj" \
	"$(INTDIR)\gfx_box.obj" \
	"$(INTDIR)\gfx_bsp.obj" \
	"$(INTDIR)\gfx_camera.obj" \
	"$(INTDIR)\gfx_click_list.obj" \
	"$(INTDIR)\gfx_coordinate_select.obj" \
	"$(INTDIR)\gfx_hud.obj" \
	"$(INTDIR)\gfx_lerp.obj" \
	"$(INTDIR)\gfx_location_select.obj" \
	"$(INTDIR)\gfx_mesh.obj" \
	"$(INTDIR)\gfx_mesh_xml.obj" \
	"$(INTDIR)\gfx_primitive.obj" \
	"$(INTDIR)\gfx_sphere.obj" \
	"$(INTDIR)\gfx_sprite.obj" \
	"$(INTDIR)\gfx_transform_matrix.obj" \
	"$(INTDIR)\gfx_transform_vector.obj" \
	"$(INTDIR)\gl_globals.obj" \
	"$(INTDIR)\gl_init.obj" \
	"$(INTDIR)\gl_light.obj" \
	"$(INTDIR)\gl_material.obj" \
	"$(INTDIR)\gl_matrix.obj" \
	"$(INTDIR)\gl_misc.obj" \
	"$(INTDIR)\gl_pick.obj" \
	"$(INTDIR)\gl_state.obj" \
	"$(INTDIR)\gl_texture.obj" \
	"$(INTDIR)\gl_vertex_list.obj" \
	"$(INTDIR)\hashtable.obj" \
	"$(INTDIR)\in_handler.obj" \
	"$(INTDIR)\in_kb.obj" \
	"$(INTDIR)\in_main.obj" \
	"$(INTDIR)\in_mouse.obj" \
	"$(INTDIR)\lin_time.obj" \
	"$(INTDIR)\main.obj" \
	"$(INTDIR)\main_loop.obj" \
	"$(INTDIR)\physics.obj" \
	"$(INTDIR)\planet.obj" \
	"$(INTDIR)\png_texture.obj" \
	"$(INTDIR)\png_write.obj" \
	"$(INTDIR)\quaternion.obj" \
	"$(INTDIR)\star_system.obj" \
	"$(INTDIR)\texturizer.obj" \
	"$(INTDIR)\UnitCollection.obj" \
	"$(INTDIR)\wrapgfx.obj" \
	"$(INTDIR)\xml_end.obj" \
	"$(INTDIR)\xml_support.obj" \
	"$(INTDIR)\xmlassist.obj"

"..\..\data\Texturizer.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("texturizer.dep")
!INCLUDE "texturizer.dep"
!ELSE 
!MESSAGE Warning: cannot find "texturizer.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "texturizer - Win32 Release" || "$(CFG)" == "texturizer - Win32 Debug"
SOURCE=..\..\texturizer\src\cmd_gun.cpp

"$(INTDIR)\cmd_gun.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\cmd_input_dfa.cpp

"$(INTDIR)\cmd_input_dfa.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\cmd_order.cpp

"$(INTDIR)\cmd_order.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\cmd_physics.cpp

"$(INTDIR)\cmd_physics.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\cmd_unit.cpp

"$(INTDIR)\cmd_unit.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\cmd_unit_xml.cpp

"$(INTDIR)\cmd_unit_xml.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\EnvironmentMapGenerator.cpp

"$(INTDIR)\EnvironmentMapGenerator.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\gfx_animation.cpp

"$(INTDIR)\gfx_animation.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\gfx_aux_logo.cpp

"$(INTDIR)\gfx_aux_logo.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\gfx_aux_palette.cpp

"$(INTDIR)\gfx_aux_palette.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\gfx_aux_texture.cpp

"$(INTDIR)\gfx_aux_texture.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\gfx_background.cpp

"$(INTDIR)\gfx_background.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\gfx_bounding_box.cpp

"$(INTDIR)\gfx_bounding_box.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\gfx_box.cpp

"$(INTDIR)\gfx_box.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\gfx_bsp.cpp

"$(INTDIR)\gfx_bsp.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\gfx_camera.cpp

"$(INTDIR)\gfx_camera.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\gfx_click_list.cpp

"$(INTDIR)\gfx_click_list.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\gfx_coordinate_select.cpp

"$(INTDIR)\gfx_coordinate_select.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\gfx_hud.cpp

"$(INTDIR)\gfx_hud.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\gfx_lerp.cpp

"$(INTDIR)\gfx_lerp.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\gfx_location_select.cpp

"$(INTDIR)\gfx_location_select.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\gfx_mesh.cpp

"$(INTDIR)\gfx_mesh.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\gfx_mesh_xml.cpp

"$(INTDIR)\gfx_mesh_xml.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\gfx_primitive.cpp

"$(INTDIR)\gfx_primitive.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\gfx_sphere.cpp

"$(INTDIR)\gfx_sphere.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\gfx_sprite.cpp

"$(INTDIR)\gfx_sprite.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\gfx_transform_matrix.cpp

"$(INTDIR)\gfx_transform_matrix.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\gfx_transform_vector.cpp

"$(INTDIR)\gfx_transform_vector.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\gl_globals.cpp

"$(INTDIR)\gl_globals.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\gl_init.cpp

"$(INTDIR)\gl_init.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\gl_light.cpp

"$(INTDIR)\gl_light.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\gl_material.cpp

"$(INTDIR)\gl_material.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\gl_matrix.cpp

"$(INTDIR)\gl_matrix.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\gl_misc.cpp

"$(INTDIR)\gl_misc.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\gl_pick.cpp

"$(INTDIR)\gl_pick.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\gl_state.cpp

"$(INTDIR)\gl_state.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\gl_texture.cpp

"$(INTDIR)\gl_texture.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\gl_vertex_list.cpp

"$(INTDIR)\gl_vertex_list.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\hashtable.cpp

"$(INTDIR)\hashtable.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\in_handler.cpp

"$(INTDIR)\in_handler.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\in_kb.cpp

"$(INTDIR)\in_kb.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\in_main.cpp

"$(INTDIR)\in_main.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\in_mouse.cpp

"$(INTDIR)\in_mouse.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\lin_time.cpp

"$(INTDIR)\lin_time.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\main.cpp

"$(INTDIR)\main.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\main_loop.cpp

"$(INTDIR)\main_loop.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\physics.cpp

"$(INTDIR)\physics.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\planet.cpp

"$(INTDIR)\planet.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\png_texture.cpp

"$(INTDIR)\png_texture.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\png_write.cpp

"$(INTDIR)\png_write.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\quaternion.cpp

"$(INTDIR)\quaternion.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\star_system.cpp

"$(INTDIR)\star_system.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\texturizer.cpp

"$(INTDIR)\texturizer.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\UnitCollection.cpp

"$(INTDIR)\UnitCollection.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\wrapgfx.cpp

"$(INTDIR)\wrapgfx.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\xml_end.cpp

"$(INTDIR)\xml_end.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\xml_support.cpp

"$(INTDIR)\xml_support.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\texturizer\src\xmlassist.cpp

"$(INTDIR)\xmlassist.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)



!ENDIF 

