#ifndef TOOLS_EDIT_H
#define TOOLS_EDIT_H
#include "../include/tools_edit.h"

class tools_edit
{
	public:
	void create_object();
};

void create_object();
#endif // TOOLS_EDIT_H
/*
 * 
Name: Perspective
Command: D3DView.SwitchEyeCameraType('', '0');WindowsManager.Activate()
RClick: 



Name: Left
Command: D3DView.SwitchEyeCameraType('', '3');WindowsManager.Activate()
RClick: 



Name: Left
Command: D3DView.SwitchEyeCameraType('', '3');WindowsManager.Activate()
RClick: 



Name: Right
Command: D3DView.SwitchEyeCameraType('', '4');WindowsManager.Activate()
RClick: 



Name: Front
Command: D3DView.SwitchEyeCameraType('', '6');WindowsManager.Activate()
RClick: 



Name: Front
Command: D3DView.SwitchEyeCameraType('', '6');WindowsManager.Activate()
RClick: 



Name: Back
Command: D3DView.SwitchEyeCameraType('', '5');WindowsManager.Activate()
RClick: 



Name: Top
Command: D3DView.SwitchEyeCameraType('', '2');WindowsManager.Activate()
RClick: 



Name: Top
Command: D3DView.SwitchEyeCameraType('', '2');WindowsManager.Activate()
RClick: 



Name: Bottom
Command: D3DView.SwitchEyeCameraType('', '1');WindowsManager.Activate()
RClick: 



Name: Set Camera
Command: D3DView.SetActiveCamera('', '');WindowsManager.Activate()
RClick: 



Name: Set Camera
Command: D3DView.SetActiveCamera('', '');WindowsManager.Activate()
RClick: 



Name: Isometric 
Command: D3DView.SwitchEyeCameraType('', '7');WindowsManager.Activate()
RClick: 



Name: Perspective
Command: D3DView.SwitchEyeCameraType('', '0');WindowsManager.Activate()
RClick: 



Name: Perspective
Command: D3DView.SwitchEyeCameraType('', '0');WindowsManager.Activate()
RClick: 



Name: Nearest ortho
Command: RsTool.SetNearestOrthoView('');;WindowsManager.Activate()
RClick: 



Name: FP navigation
Command: Avatar.ActivateFpnToView('');WindowsManager.Activate();
RClick: RsTool.ShowFpnProperties();



Name: FP navigation
Command: Avatar.ActivateFpnToView('');WindowsManager.Activate();
RClick: RsTool.ShowFpnProperties();



Name: Reset View
Command: RsTool.ResetView('');WindowsManager.Activate()
RClick: 



Name: Reset View
Command: RsTool.ResetView('');WindowsManager.Activate()
RClick: 



Name: Look at Selection
Command: RsTool.LookAtSelection('');WindowsManager.Activate()
RClick: 



Name: Rect zoom
Command: Widgets.ActivateViewToolWidget('/Widgets/Tools/View tools/Rect zoom','Default');WindowsManager.Activate()
RClick: 



Name: X lock
Command: RsTool.ToggleValue('/Preferences/Snapping/Enable X');WindowsManager.Activate()
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Snapping',5,1,1);



Name: Y lock
Command: RsTool.ToggleValue('/Preferences/Snapping/Enable Y');WindowsManager.Activate()
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Snapping',5,1,1);



Name: Z lock
Command: RsTool.ToggleValue('/Preferences/Snapping/Enable Z');WindowsManager.Activate()
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Snapping',5,1,1);



Name: Opaque
Command: D3DView.LoadRAPreset('', 1.0, 0.0, '', '');WindowsManager.Activate()
RClick: 



Name: Opaque
Command: D3DView.LoadRAPreset('', 1.0, 0.0, '', '');WindowsManager.Activate()
RClick: 



Name: Opaque
Command: D3DView.LoadRAPreset('', 1.0, 0.0, '', '');WindowsManager.Activate()
RClick: 



Name: OpaqueWires
Command: D3DView.LoadRAPreset('', 1.0, 1.0, '', '');WindowsManager.Activate()
RClick: 



Name: Transp
Command: D3DView.LoadRAPreset('', 0.5, 0.0, '', '');WindowsManager.Activate()
RClick: 



Name: TranspWires
Command: D3DView.LoadRAPreset('', 0.6, 1.0, '', '');WindowsManager.Activate()
RClick: 



Name: Wires
Command: D3DView.LoadRAPreset('', 0.0, 1.0, '', '');WindowsManager.Activate()
RClick: 



Name: WireframeGrid
Command: D3DView.LoadRAPreset('', -1.0, -1.0, 'Wire', '');WindowsManager.Activate()
RClick: 



Name: Wireframe Grid
Command: D3DView.LoadRAPreset('', -1.0, -1.0, 'Wire', '');WindowsManager.Activate()
RClick: 



Name: Opaque Grid
Command: D3DView.LoadRAPreset('', -1.0, -1.0, 'Solid','');WindowsManager.Activate()
RClick: 



Name: No Grid
Command: D3DView.LoadRAPreset('', -1.0, -1.0, 'None', '');WindowsManager.Activate()
RClick: 



Name: Hide
Command: Activity.Run("/Scripts/Commands/Hide");WindowsManager.Activate()
RClick: if(Node.Exists(Node.FirstSelected() + "/Object Render Attributes")){UserInterface.OpenToolPanelViewEx2("" , "" , Node.FirstSelected() + "/Object Render Attributes", 3,1,0);};



Name: Hide
Command: Activity.Run("/Scripts/Commands/Hide");WindowsManager.Activate()
RClick: if(Node.Exists(Node.FirstSelected() + "/Object Render Attributes")){UserInterface.OpenToolPanelViewEx2("" , "" , Node.FirstSelected() + "/Object Render Attributes", 3,1,0);};



Name: Show
Command: Activity.Run("/Scripts/Commands/Show");WindowsManager.Activate()
RClick: if(Node.Exists(Node.FirstSelected() + "/Object Render Attributes")){UserInterface.OpenToolPanelViewEx2("" , "" , Node.FirstSelected() + "/Object Render Attributes", 3,1,0);};



Name: HideAll
Command: Activity.Run("/Scripts/Commands/HideAll");WindowsManager.Activate()
RClick: 



Name: HideAll
Command: Activity.Run("/Scripts/Commands/HideAll");WindowsManager.Activate()
RClick: 



Name: ShowAll
Command: Activity.Run("/Scripts/Commands/ShowAll");WindowsManager.Activate()
RClick: 



Name: World
Command: Node.Value('/Preferences/Modeling preferences','Coordinate system') = 'World';WindowsManager.Activate()
RClick: 



Name: World
Command: Node.Value('/Preferences/Modeling preferences','Coordinate system') = 'World';WindowsManager.Activate()
RClick: 



Name: Object
Command: Node.Value('/Preferences/Modeling preferences','Coordinate system') = 'Local';WindowsManager.Activate()
RClick: 



Name: Tangent
Command: Node.Value('/Preferences/Modeling preferences','Coordinate system') = 'Tangent';WindowsManager.Activate()
RClick: 



Name: Screen
Command: Node.Value('/Preferences/Modeling preferences','Coordinate system') = 'Screen';WindowsManager.Activate()
RClick: 



Name: DynaPose
Command: CharacterEditor.ActivateCharacterTool('/Widgets/Tools/Character editor/Dynamic pose'); UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Character editor/Dynamic pose/Character Posing',3,1,0);WindowsManager.Activate();
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Character editor/Dynamic pose/Character Posing',3,1,0);



Name: DynaPose
Command: CharacterEditor.ActivateCharacterTool('/Widgets/Tools/Character editor/Dynamic pose'); UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Character editor/Dynamic pose/Character Posing',3,1,0);WindowsManager.Activate();
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Character editor/Dynamic pose/Character Posing',3,1,0);



Name: PhysMove
Command: Physics.ActivatePhysWidget('PhysMoveWidget');WindowsManager.Activate();
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Phys Move Preferences',3,1,0);



Name: Look At
Command: ToolMng.ActivateTool('{17D544A3-3F58-436B-83E7-F8B4D7D4E7C5}','{4E203C6C-A20D-4e32-82B4-FC482F5A0D06}' );WindowsManager.Activate();
RClick: 



Name: NewView
Command: Activity.Run("/Scripts/Commands/NewWindowViewBar");WindowsManager.Activate()
RClick: 



Name: Move
Command: Widgets.ActivateViewToolWidget('/Widgets/Tools/Move selection','Default');
RClick: 

Name: Rotate
Command: Widgets.ActivateViewToolWidget('/Widgets/Tools/Rotate selection','Default');WindowsManager.Activate()
RClick: 

Name: Scale
Command: Widgets.ActivateViewToolWidget('/Widgets/Tools/Scale selection','Default');WindowsManager.Activate()
RClick: 

Name: Move Cam
Command: Widgets.ActivateViewToolWidget('/Widgets/Tools/View tools/Camera move','Default');WindowsManager.Activate()
RClick: 

Name: Rotate Cam
Command: Widgets.ActivateViewToolWidget('/Widgets/Tools/View tools/Camera rotate','Default');WindowsManager.Activate()
RClick: 

Name: Fov Cam
Command: Widgets.ActivateViewToolWidget('/Widgets/Tools/View tools/Camera fov','Default');WindowsManager.Activate()
RClick: 



Name: Help
Command: 
RClick: 



Name: Tool tips
Command: tSBridge.XorTypeTSStateByAlias("SV_TOOLTIPS_256")
RClick: 



Name: About
Command: tSBridge.SuggestTSStateByAlias("SV_GETINFOGROUP_INFOGROUP_ABOUT")
RClick: 



Name: Help
Command: var WshShell = new ActiveXObject("WScript.Shell");WshShell.Run (System.GetMainDir() + "\\PDFMan\\tS65Help.chm")
RClick: 



Name: tS6 File
Command: 
RClick: 



Name: New
Command: 
RClick: 



Name: Scene
Command: tSBridge.SuggestTSStateByAlias("CreateNewSceneFile")
RClick: 



Name: Library
Command: tSBridge.SuggestTSStateByAlias("SV_FILE2_FILE2_LIBRARY_NEW")
RClick: 



Name: Project
Command: tSBridge.SuggestTSStateByAlias("SV_FILE2_FILE2_PROJECT_NEW")
RClick: 



Name: Load
Command: 
RClick: 



Name: Scene
Command: tSBridge.SuggestTSStateByAlias("SV_FILE_FILE_SCENE_LOAD")
RClick: 



Name: Object
Command: tSBridge.SuggestTSStateByAlias("SV_FILE_FILE_LOAD")
RClick: 



Name: Library
Command: tSBridge.SuggestTSStateByAlias("SV_FILE2_FILE2_LIBRARY_SHARE")
RClick: 



Name: Radiosity
Command: tSBridge.SuggestTSStateByAlias("SV_RADIO_STEP_RADIO_STEP_LOAD_SOLUTION")
RClick: 



Name: Save
Command: 
RClick: 



Name: Scene
Command: tSBridge.SuggestTSStateByAlias("SV_FILE_FILE_SCENE_SAVE")
RClick: 



Name: Object
Command: tSBridge.SuggestTSStateByAlias("SV_FILE_FILE_SAVE")
RClick: 



Name: Preferences
Command: tSBridge.SuggestTSStateByAlias("SV_FILE_FILE_PREFERENCES")
RClick: 



Name: Hot Keys
Command: tSBridge.SuggestTSStateByAlias("SV_FILE_FILE_HOTKEYS")
RClick: 



Name: Save As...
Command: 
RClick: 



Name: Scene
Command: tSBridge.SuggestTSStateByAlias("SV_FILE_FILE_SCENE_SAVE_AS")
RClick: 



Name: Object
Command: tSBridge.SuggestTSStateByAlias("SV_FILE_FILE_SAVE_AS")
RClick: 



Name: Radiosity
Command: tSBridge.SuggestTSStateByAlias("SV_RADIO_STEP_RADIO_STEP_SAVE_SOLUTION")
RClick: 



Name: Texture from illumination
Command: tSBridge.SuggestTSStateByAlias("SV_FILE_FILE_SCENE_TEXTUREBAKED")
RClick: 



Name: Archive
Command: tSBridge.SuggestTSStateByAlias("SV_FILE_FILE_SCENE_ARCHIVE")
RClick: 



Name: Exit
Command: tSBridge.SuggestTSStateByAlias("SV_FILE_FILE_EXIT")
RClick: 



Name: Preferences
Command: tSBridge.SuggestTSStateByAlias("SV_GETGROUP_GROUP_SETTINGS")
RClick: 



Name: Display options...
Command: tSBridge.SuggestTSStateByAlias("Reality1Panel")
RClick: 



Name: Recent Files
Command: 
RClick: 



Name: finalTigerTest.cob
Command: tSBridge.SuggestTSState(859, 1);
RClick: 



Name: fullOnTest.cob
Command: tSBridge.SuggestTSState(859, 2);
RClick: 



Name: helloFromWorkspace.cob
Command: tSBridge.SuggestTSState(859, 3);
RClick: 



Name: wundergnd.cob
Command: tSBridge.SuggestTSState(859, 4);
RClick: 



Name: testexport.cob
Command: tSBridge.SuggestTSState(859, 5);
RClick: 



Name: curveGroupFromModelSide1.cob
Command: tSBridge.SuggestTSState(859, 6);
RClick: 



Name: curveGroupFromModelSide0.cob
Command: tSBridge.SuggestTSState(859, 7);
RClick: 



Name: testexportTiger.cob
Command: tSBridge.SuggestTSState(859, 8);
RClick: 



Name: Rec
Command: RsAnim.SetKeyFrame('', RsTime.CurrentTime())
RClick: RsAnimKeying.OpenView()



Name: Start frame
Command: RsTime.StartFrame()
RClick: 



Name: Prev keyframe
Command: RsTime.PrevKeyFrame()
RClick: 



Name: Prev keyframe
Command: RsTime.PrevKeyFrame()
RClick: 



Name: Prev frame
Command: RsTime.PrevFrame()
RClick: 



Name: Stop
Command: RsTime.Stop()
RClick: 



Name: Play
Command: RsTime.Play('')
RClick: 



Name: Next keyframe
Command: RsTime.NextKeyFrame()
RClick: 



Name: Next keyframe
Command: RsTime.NextKeyFrame()
RClick: 



Name: Next frame
Command: RsTime.NextFrame()
RClick: 



Name: End frame
Command: RsTime.EndFrame()
RClick: 



Name: Scene
Command: LE.OpenLocation(Space.CurrentScene)
RClick: 



Name: Organize
Command: LE.MinimizePanels('');LE.ArrangePanels('')
RClick: LE.ExpandPanels('');LE.ArrangePanels('');



Name: Unselect
Command: Space.Unselect();RsTool.Arrow();
RClick: 



Name: Project
Command: LE.OpenLocation("/Project")
RClick: 



Name:  Windows Manager Space
Command: LE.OpenLocation("/Project/Windows Manager Space")
RClick: 



Name: Default
Command: LE.OpenLocation("/Project/Windows Manager Space/Frame Window/Border Docking Place/Frame Window, 1/Split Docking Place/Frame Window, 1/Split Docking Place/Frame Window, 1/Split Docking Place/Frame Window, 2");
RClick: 



Name: System
Command: LE.OpenLocation("/System")
RClick: 



Name: Network
Command: LE.OpenLocation("/Network")
RClick: 



Name: Widgets
Command: LE.OpenLocation("/Widgets")
RClick: 



Name: Obj Widget
Command: LE.OpenLocation("/Widgets/Select/Default object navigation widget")
RClick: 



Name: PE Widget
Command: LE.OpenLocation("/Widgets/Edit/Point edit widget")
RClick: 



Name: Bkgrd Widget
Command: LE.OpenLocation("/Widgets/Tools/Background")
RClick: 



Name: Preferences
Command: LE.OpenLocation("/Preferences")
RClick: 



Name: Toolbar Prototypes Encapsulator
Command: LE.OpenLocation("/Toolbar Prototypes Encapsulator")
RClick: 



Name: X lock
Command: RsTool.ToggleValue('/Preferences/Snapping/Enable X');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Snapping',5,1,1);



Name: Y lock
Command: RsTool.ToggleValue('/Preferences/Snapping/Enable Y');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Snapping',5,1,1);



Name: Z lock
Command: RsTool.ToggleValue('/Preferences/Snapping/Enable Z');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Snapping',5,1,1);



Name: Undo
Command: RsApp.Undo()
RClick: 



Name: Undo
Command: RsApp.Undo()
RClick: 



Name: Redo
Command: RsApp.Redo()
RClick: 



Name: PointEdit
Command: RsTool.ToggleValue('/Preferences/Snapping/Vertex snapping');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Snapping/Point edit snapping',3,1,0)



Name: SnapToGrid
Command: RsTool.ToggleValue('/Preferences/Snapping/Grid snapping');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Snapping',4,1,1);



Name: DistFb
Command: RsTool.ToggleValue('/Preferences/Snapping/Distances');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Snapping',6,1,1);



Name: PointEdit
Command: RsTool.ToggleValue('/Preferences/Snapping/Vertex snapping');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Snapping/Point edit snapping',3,1,0)



Name: Unencaps
Command: LE.Unencapsulate('')
RClick: 



Name: 3D Encapsulate
Command: LE.RectEncapsulationDialog('{5B3DD4D4-BD80-480A-BFD8-0B3A19DF1558}', true)
RClick: 



Name: Encapsulate
Command: LE.RectEncapsulationDialog('{5B3DD4D4-BD80-480A-BFD8-0B3A19DF1558}', false)
RClick: 



Name: Flatten
Command: MeshModifiers.FlattenNodes('')
RClick: 



Name: Unencaps
Command: LE.Unencapsulate('')
RClick: 



Name: 3D Encapsulate
Command: LE.RectEncapsulationDialog('{5B3DD4D4-BD80-480A-BFD8-0B3A19DF1558}', true)
RClick: 



Name: 3D Encapsulate
Command: Activity.Run("/Scripts/Commands/Unglue");
RClick: 



Name: 3D Encapsulate
Command: LE.RectEncapsulationDialog('{5B3DD4D4-BD80-480A-BFD8-0B3A19DF1558}', true)
RClick: 



Name: Physical simulation
Command: Physics.init_PhysSim()
RClick: Physics.OpenPanel()



Name: Set Camera
Command: D3DView.SetActiveCamera('', '')
RClick: 



Name: Set Camera
Command: D3DView.SetActiveCamera('', '')
RClick: 



Name: Set Camera
Command: D3DView.SetActiveCamera('', '')
RClick: 



Name: Isometric 
Command: D3DView.SwitchEyeCameraType('', '7')
RClick: 



Name: Perspective
Command: D3DView.SwitchEyeCameraType('', '0')
RClick: 



Name: Perspective
Command: D3DView.SwitchEyeCameraType('', '0')
RClick: 



Name: Nearest ortho
Command: RsTool.SetNearestOrthoView('');
RClick: 



Name: Top
Command: D3DView.SwitchEyeCameraType('', '2')
RClick: 



Name: Top
Command: D3DView.SwitchEyeCameraType('', '2')
RClick: 



Name: Bottom
Command: D3DView.SwitchEyeCameraType('', '1')
RClick: 



Name: Front
Command: D3DView.SwitchEyeCameraType('', '6')
RClick: 



Name: Front
Command: D3DView.SwitchEyeCameraType('', '6')
RClick: 



Name: Back
Command: D3DView.SwitchEyeCameraType('', '5')
RClick: 



Name: Left
Command: D3DView.SwitchEyeCameraType('', '3')
RClick: 



Name: Left
Command: D3DView.SwitchEyeCameraType('', '3')
RClick: 



Name: Right
Command: D3DView.SwitchEyeCameraType('', '4')
RClick: 



Name: Opaque
Command: D3DView.LoadRAPreset('', 1.0, 0.0, '', '')
RClick: 



Name: Opaque
Command: D3DView.LoadRAPreset('', 1.0, 0.0, '', '')
RClick: 



Name: Opaque
Command: D3DView.LoadRAPreset('', 1.0, 0.0, '', '')
RClick: 



Name: OpaqueWires
Command: D3DView.LoadRAPreset('', 1.0, 1.0, '', '')
RClick: 



Name: Transp
Command: D3DView.LoadRAPreset('', 0.5, 0.0, '', '')
RClick: 



Name: TranspWires
Command: D3DView.LoadRAPreset('', 0.6, 1.0, '', '')
RClick: 



Name: Wires
Command: D3DView.LoadRAPreset('', 0.0, 1.0, '', '')
RClick: 



Name: Wireframe Grid
Command: D3DView.LoadRAPreset('', -1.0, -1.0, 'Wire', '')
RClick: 



Name: Wireframe Grid
Command: D3DView.LoadRAPreset('', -1.0, -1.0, 'Wire', '')
RClick: 



Name: Opaque Grid
Command: D3DView.LoadRAPreset('', -1.0, -1.0, 'Solid','')
RClick: 



Name: No Grid
Command: D3DView.LoadRAPreset('', -1.0, -1.0, 'None', '')
RClick: 



Name: HideAll
Command: Activity.Run("/Scripts/Commands/HideAll");
RClick: 



Name: HideAll
Command: Activity.Run("/Scripts/Commands/HideAll");
RClick: 



Name: ShowAll
Command: Activity.Run("/Scripts/Commands/ShowAll");
RClick: 



Name: Hide
Command: Activity.Run("/Scripts/Commands/Hide");
RClick: if(Node.Exists(Node.FirstSelected() + "/Object Render Attributes")){UserInterface.OpenToolPanelViewEx2("" , "" , Node.FirstSelected() + "/Object Render Attributes", 3,1,0);};



Name: Hide
Command: Activity.Run("/Scripts/Commands/Hide");
RClick: if(Node.Exists(Node.FirstSelected() + "/Object Render Attributes")){UserInterface.OpenToolPanelViewEx2("" , "" , Node.FirstSelected() + "/Object Render Attributes", 3,1,0);};



Name: Show
Command: Activity.Run("/Scripts/Commands/Show");
RClick: if(Node.Exists(Node.FirstSelected() + "/Object Render Attributes")){UserInterface.OpenToolPanelViewEx2("" , "" , Node.FirstSelected() + "/Object Render Attributes", 3,1,0);};



Name: New scene
Command: Space.NewScene()
RClick: LE.OpenLocation(Space.CurrentScene())



Name: New scene
Command: Space.NewScene()
RClick: LE.OpenLocation(Space.CurrentScene())



Name: Reset Default
Command: var Yes = System.Question("Would you like to Reset the Default Context?");if (Yes){RsApp.Reset();}else;
RClick: 



Name: Default context backup
Command: RsFileIO.SaveSystem('', '', 'Manually saved system', 0)
RClick: 



Name: Reset Default
Command: var Yes = System.Question("Would you like to Reset the Default Context?");if (Yes){RsApp.Reset();}else;
RClick: 



Name: World
Command: Node.Value('/Preferences/Modeling preferences','Coordinate system') = 'World';
RClick: 



Name: World
Command: Node.Value('/Preferences/Modeling preferences','Coordinate system') = 'World';
RClick: 



Name: Object
Command: Node.Value('/Preferences/Modeling preferences','Coordinate system') = 'Local';
RClick: 



Name: Tangent
Command: Node.Value('/Preferences/Modeling preferences','Coordinate system') = 'Tangent';
RClick: 



Name: Screen
Command: Node.Value('/Preferences/Modeling preferences','Coordinate system') = 'Screen';
RClick: 



Name: Plane
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Primitive tool','{1ABE09E8-F22F-46b3-9F8A-7F08B0FFF297}(/Preferences/Primitives/Matrix manager){C89E0C6B-3F82-4fe2-A232-FB1A7B7F6190}(/Preferences/Primitives/Factory preferences){/Preferences/Primitives/Preferences}','/Preferences/Primitives/Plane');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Primitives',12,1,1);



Name: Cube
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Primitive tool','{EEC8FEE8-EB12-4e12-8ED0-D71CAA2886FD}(/Preferences/Primitives/Matrix manager){C89E0C6B-3F82-4fe2-A232-FB1A7B7F6190}(/Preferences/Primitives/Factory preferences){/Preferences/Primitives/Preferences}','/Preferences/Primitives/Cube');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Primitives',10,1,1);



Name: Sphere
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Primitive tool','{5DB1D6C0-877C-4a84-8FF1-B5AB4E34519D}(/Preferences/Primitives/Rotation manager){C89E0C6B-3F82-4fe2-A232-FB1A7B7F6190}(/Preferences/Primitives/Factory preferences){/Preferences/Primitives/Preferences}','/Preferences/Primitives/Sphere');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Primitives',8,1,1);



Name: Cylinder
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Primitive tool','{A955CABA-CA6F-40c0-AE78-010D283ED1C5}(/Preferences/Primitives/Rotation manager){C89E0C6B-3F82-4fe2-A232-FB1A7B7F6190}(/Preferences/Primitives/Factory preferences){/Preferences/Primitives/Preferences}','/Preferences/Primitives/Cylinder');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Primitives',6,1,1);



Name: Torus
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Primitive tool','{A955CABA-CA6F-40c0-AE78-010D283ED1C5}(/Preferences/Primitives/Rotation manager){C89E0C6B-3F82-4fe2-A232-FB1A7B7F6190}(/Preferences/Primitives/Factory preferences){/Preferences/Primitives/Preferences}','/Preferences/Primitives/Torus');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Primitives',9,1,1);



Name: Plane
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Primitive tool','{1ABE09E8-F22F-46b3-9F8A-7F08B0FFF297}(/Preferences/Primitives/Matrix manager){C89E0C6B-3F82-4fe2-A232-FB1A7B7F6190}(/Preferences/Primitives/Factory preferences){/Preferences/Primitives/Preferences}','/Preferences/Primitives/Plane');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Primitives',12,1,1);



Name: Cone
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Primitive tool','{A955CABA-CA6F-40c0-AE78-010D283ED1C5}(/Preferences/Primitives/Rotation manager){C89E0C6B-3F82-4fe2-A232-FB1A7B7F6190}(/Preferences/Primitives/Factory preferences){/Preferences/Primitives/Preferences}','/Preferences/Primitives/Cone');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Primitives',11,1,1);



Name: Text
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Primitive tool','{0422ED97-497D-4623-A209-ABC4335F0380}{C89E0C6B-3F82-4fe2-A232-FB1A7B7F6190}(/Preferences/Primitives/Factory preferences){/Preferences/Primitives/Preferences}','/Preferences/Primitives/Text');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Primitives',4,1,1);



Name: Camera
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Primitive tool','{B1D12AD1-47D4-4e6c-8227-DC80FF55D7BB}{A46795D3-0DE2-4ed8-9FB6-91D84FB9F1EB}(/Preferences/Cameras/Factory preferences){/Preferences/Lights/Preferences}','/Preferences/Cameras/Camera');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Cameras',3,1,1);



Name: EntryPoint
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Primitive tool','{B1D12AD1-47D4-4e6c-8227-DC80FF55D7BB}{A46795D3-0DE2-4ed8-9FB6-91D84FB9F1EB}(/Preferences/Cameras/Factory preferences){/Preferences/Lights/Preferences}','/Preferences/Cameras/EntryPoint');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Cameras',3,1,1);



Name: Ambient
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Light tool','{B1D12AD1-47D4-4e6c-8227-DC80FF55D7BB}{A46795D3-0DE2-4ed8-9FB6-91D84FB9F1EB}(/Preferences/Lights/Factory preferences){/Preferences/Lights/Preferences}','/Preferences/Lights/Ambient');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Lights',3,1,1);



Name: Omni
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Light tool','{B1D12AD1-47D4-4e6c-8227-DC80FF55D7BB}{A46795D3-0DE2-4ed8-9FB6-91D84FB9F1EB}(/Preferences/Lights/Factory preferences){/Preferences/Lights/Preferences}','/Preferences/Lights/Omni');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Lights',3,1,1);



Name: Infinite
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Light tool','{B1D12AD1-47D4-4e6c-8227-DC80FF55D7BB}{A46795D3-0DE2-4ed8-9FB6-91D84FB9F1EB}(/Preferences/Lights/Factory preferences){/Preferences/Lights/Preferences}','/Preferences/Lights/Infinite');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Lights',3,1,1);



Name: Projector
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Light tool','{B1D12AD1-47D4-4e6c-8227-DC80FF55D7BB}{A46795D3-0DE2-4ed8-9FB6-91D84FB9F1EB}(/Preferences/Lights/Factory preferences){/Preferences/Lights/Preferences}','/Preferences/Lights/Projector');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Lights',3,1,1);



Name: Sky
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Light tool','{B1D12AD1-47D4-4e6c-8227-DC80FF55D7BB}{A46795D3-0DE2-4ed8-9FB6-91D84FB9F1EB}(/Preferences/Lights/Factory preferences){/Preferences/Lights/Preferences}','/Preferences/Lights/Sky');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Lights',3,1,1);



Name: Directional
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Light tool','{B1D12AD1-47D4-4e6c-8227-DC80FF55D7BB}{A46795D3-0DE2-4ed8-9FB6-91D84FB9F1EB}(/Preferences/Lights/Factory preferences){/Preferences/Lights/Preferences}','/Preferences/Lights/Directional');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Lights',3,1,1);



Name: Ambient
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Light tool','{B1D12AD1-47D4-4e6c-8227-DC80FF55D7BB}{A46795D3-0DE2-4ed8-9FB6-91D84FB9F1EB}(/Preferences/Lights/Factory preferences){/Preferences/Lights/Preferences}','/Preferences/Lights/Ambient');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Lights',3,1,1);



Name: Area
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Light tool','{B1D12AD1-47D4-4e6c-8227-DC80FF55D7BB}{A46795D3-0DE2-4ed8-9FB6-91D84FB9F1EB}(/Preferences/Lights/Factory preferences){/Preferences/Lights/Preferences}','/Preferences/Lights/Area');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Lights',3,1,1);



Name: Spot
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Light tool','{B1D12AD1-47D4-4e6c-8227-DC80FF55D7BB}{A46795D3-0DE2-4ed8-9FB6-91D84FB9F1EB}(/Preferences/Lights/Factory preferences){/Preferences/Lights/Preferences}','/Preferences/Lights/Spot');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Lights',3,1,1);



Name: Render Scene
Command: OfflineRender.OpenView('',0,0);OfflineRender.RenderScene('')
RClick: OfflineRender.OpenPreferencesPanel()



Name: Render Scene
Command: OfflineRender.OpenView('',0,0);OfflineRender.RenderScene('')
RClick: OfflineRender.OpenPreferencesPanel()



Name: Render Area
Command: Widgets.ReplaceWidget('{88839603-7F98-41f0-96AC-BE94E801CFF3}','/Widgets/Tools/Offline render/Area scene render','Default','','dummy')
RClick: OfflineRender.OpenPreferencesPanel()



Name: Render Object
Command: OfflineRender.OpenView('',0,0);OfflineRender.RenderObject('')
RClick: OfflineRender.OpenPreferencesPanel()



Name: Render Animation
Command: OfflineRender.OpenView('',0,0);OfflineRender.RenderAnimation('')
RClick: OfflineRender.OpenPreferencesPanel()



Name: FP navigation
Command: Avatar.ActivateFpnToView('');
RClick: Avatar.ShowFpnProperties();



Name: FP navigation
Command: Avatar.ActivateFpnToView('');
RClick: Avatar.ShowFpnProperties();



Name: Move Cam
Command: Widgets.ActivateViewToolWidget('/Widgets/Tools/View tools/Camera move','Default');
RClick: 



Name: Rotate Cam
Command: Widgets.ActivateViewToolWidget('/Widgets/Tools/View tools/Camera rotate','Default');
RClick: 



Name: Fov Cam
Command: Widgets.ActivateViewToolWidget('/Widgets/Tools/View tools/Camera fov','Default');
RClick: 



Name: Rect zoom
Command: Widgets.ActivateViewToolWidget('/Widgets/Tools/View tools/Rect zoom','Default')
RClick: 



Name: Reset
Command: RsTool.ResetView('');
RClick: 



Name: Reset
Command: RsTool.ResetView('');
RClick: 



Name: Look at Selection
Command: RsTool.LookAtSelection('');
RClick: 



Name: DynaPose
Command: CharacterEditor.ActivateCharacterTool('/Widgets/Tools/Character editor/Dynamic pose'); UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Character editor/Dynamic pose/Character Posing',3,1,0);
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Character editor/Dynamic pose/Character Posing',3,1,0);



Name: DynaPose
Command: CharacterEditor.ActivateCharacterTool('/Widgets/Tools/Character editor/Dynamic pose'); UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Character editor/Dynamic pose/Character Posing',3,1,0);
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Character editor/Dynamic pose/Character Posing',3,1,0);



Name: PhysMove
Command: Physics.ActivatePhysWidget('PhysMoveWidget')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Phys Move Preferences',3,1,0);



Name: Move
Command: Widgets.ActivateViewToolWidget('/Widgets/Tools/Move selection','Default');
RClick: 



Name: Rotate
Command: Widgets.ActivateViewToolWidget('/Widgets/Tools/Rotate selection','Default');
RClick: 



Name: Scale
Command: Widgets.ActivateViewToolWidget('/Widgets/Tools/Scale selection','Default');
RClick: 



Name: Look At
Command: ToolMng.ActivateTool('{17D544A3-3F58-436B-83E7-F8B4D7D4E7C5}','{4E203C6C-A20D-4e32-82B4-FC482F5A0D06}' )
RClick: 



Name: UnLook At
Command: Activity.Run("/Scripts/Commands/UnLookAt");
RClick: 



Name: Look At
Command: ToolMng.ActivateTool('{17D544A3-3F58-436B-83E7-F8B4D7D4E7C5}','{4E203C6C-A20D-4e32-82B4-FC482F5A0D06}' )
RClick: 



Name: Library browser
Command: Library2.ShowLibraryBrowserWindow()
RClick: 



Name: Output Console
Command: CmdPrompt.DebugView('Windows Manager Space', 0)
RClick: 



Name: Copy Window
Command: WindowsManager.CopyWindow('')
RClick: 



Name: LE Window
Command: WindowsManager.CreateWindowFromCLSIDEx('default', 'default', 'default', '[Scene]', 1, '2D')
RClick: 



Name: Command Prompt
Command: CmdPrompt.OpenWindow('Windows Manager Space', 0)
RClick: 



Name: Output Console
Command: CmdPrompt.DebugView('Windows Manager Space', 0)
RClick: 



Name: Command history
Command: CmdPrompt.StackView('Windows Manager Space', 0)
RClick: 



Name: Status view
Command: RsTool.OpenStatusBar();
RClick: 



Name: Stack View
Command: WindowsManager.OpenHistoryWindow()
RClick: 



Name: Anim View
Command: WindowsManager.CreateWindowFromCLSIDEx('default', 'default', 'default', '[Scene]', 1, '4D')
RClick: 



Name: Package Manager
Command: WindowsManager.CreateWindowFromCLSID('{3011C160-2294-48d9-AE95-BD144574FB99}', '', '', '', 1)
RClick: 



Name: Scene View
Command: CmdPrompt.SceneViewCreate();
RClick: 



Name: 3D Window
Command: WindowsManager.CreateWindowFromCLSIDEx('default', 'default', 'default', '[Scene]', 1, '3D')
RClick: 



Name: jScript Macro Record Toolbar
Command: WindowsManager.OpenToolbarFromPrototype('MacroRecordjS', 290, 408,-1,-1)
RClick: RsFileIO.LoadObject(System.GetMainDir() + '\\Rs Main Libraries\\System - Scripts\\jScript command.RsObj', Space.CurrentScene());



Name: Record Toolbar
Command: WindowsManager.OpenToolbarFromPrototype('Record3D', 290, 440,-1,-1)
RClick: RsRec.OpenRecPreferences()



Name: jScript Macro Record Toolbar
Command: WindowsManager.OpenToolbarFromPrototype('MacroRecordjS', 290, 408,-1,-1)
RClick: RsFileIO.LoadObject(System.GetMainDir() + '\\Rs Main Libraries\\System - Scripts\\jScript command.RsObj', Space.CurrentScene());



Name: VBScript Macro Record Toolbar
Command: WindowsManager.OpenToolbarFromPrototype('MacroRecordVB', 430, 408,-1,-1)
RClick: RsFileIO.LoadObject(System.GetMainDir() + '\\Rs Main Libraries\\System - Scripts\\VBScript command.RsObj', Space.CurrentScene());



Name: Shared Space
Command: Net.NtOpenView
RClick: 



Name: File Render
Command: D3DView.RenderToFile('', '')
RClick: 



Name: HW settings
Command: D3DView.ShowSettingsDialog()
RClick: 



Name: Manual
Command: tSBridge.SuggestTSStateByAlias("SV_HELP_HELP_PDF_MANUAL")
RClick: 



Name: Export to VE 
Command: RsImport.OpenVECollectionPanel();
RClick: 



Name: File Render
Command: D3DView.RenderToFile('', '')
RClick: 



Name: Copy
Command: Node.Copy('', '')
RClick: Activity.Run('/Scripts/Commands/Copy')



Name: Copy
Command: Node.Copy('', '')
RClick: Activity.Run('/Scripts/Commands/Copy')



Name: Delete
Command: Node.Delete('')
RClick: 



Name: File
Command: 
RClick: 



Name: New scene
Command: Space.NewScene()
RClick: 



Name: Load
Command: Library2.DlgGenericLoad('', '', 15); 
RClick: 



Name: Save
Command: Library2.DlgGenericSave('', '', 3);
RClick: 



Name: Recent Files
Command: 
RClick: 



Name: Actor1.dae
Command: RsFileIO.GenericLoad('E:\\ue4Tests\\Actor1.dae', '', 15);
RClick: 



Name: Actor1plusanim.dae
Command: RsFileIO.GenericLoad('E:\\ue4Tests\\Actor1plusanim.dae', '', 15);
RClick: 



Name: install fbx2 import export.RsObj
Command: RsFileIO.GenericLoad('C:\\Users\\ClintonReese\\Desktop\\Clintons3DFBX2015\\install fbx2 import export.RsObj', '', 15);
RClick: 



Name: CurveToolsAutoload.RsObj
Command: RsFileIO.GenericLoad('C:\\Users\\ClintonReese\\Desktop\\CurveToolsAutoload.RsObj', '', 15);
RClick: 



Name: SVG Import Autoload.RsObj
Command: RsFileIO.GenericLoad('C:\\Users\\ClintonReese\\Desktop\\SVG Import Autoload.RsObj', '', 15);
RClick: 



Name: SVG Import Autoload.RsObj
Command: RsFileIO.GenericLoad('E:\\NewServer\\workingtemp\\SVG Import Autoload.RsObj', '', 15);
RClick: 



Name: SVGimporterF.RsObj
Command: RsFileIO.GenericLoad('E:\\NewServer\\workingtemp\\SVGimporterF.RsObj', '', 15);
RClick: 



Name: SVGimporterE.RsObj
Command: RsFileIO.GenericLoad('E:\\NewServer\\workingtemp\\SVGimporterE.RsObj', '', 15);
RClick: 



Name: Exit
Command: RsApp.ShutDown()
RClick: 



Name: HW settings
Command: D3DView.ShowSettingsDialog()
RClick: 



Name: Save As RsRcd
Command: RsRec.Start(Space.CurrentScene());RsRec.Stop();RsRec.Save('');
RClick: 



Name: Help
Command: 
RClick: 



Name: About
Command: WindowsManager.OpenAboutBox();
RClick: 



Name: Manual
Command: tSBridge.SuggestTSStateByAlias("SV_HELP_HELP_PDF_MANUAL")
RClick: 



Name: United 3D Artist  
Command: RsTool.OpenWebPage("www.united3dartists.com");
RClick: 



Name: Updates
Command: RsTool.OpenWebPage("www.united3dartists.com/forum/viewforum.php?f=55");
RClick: 



Name: Eye Cam
Command: Cam = Node.SubObject("/D3DView", 0);D3DView.SetActiveCamera('/D3DView/' + Cam, '%WIN_ID%');
RClick: Cam = Node.SubObject("/D3DView", 0);UserInterface.OpenToolPanelViewEx2("" , "" ,"/D3DView/" + Cam, 3, 0, 1);



Name: Cam 0
Command: D3DView.SetActiveCamera(Space.CurrentScene() + '/Camera', '%WIN_ID%');
RClick: UserInterface.OpenToolPanelViewEx2("" , "" ,Space.CurrentScene() + '/Camera/Camera', 3, 1, 1);Node.Select(Space.CurrentScene() + '/Camera');



Name: Cam 1
Command: D3DView.SetActiveCamera(Space.CurrentScene() + '/Camera, 1', '%WIN_ID%');D3DView.SetActiveCamera(Space.CurrentScene() + '/Camera,1', '%WIN_ID%');
RClick: UserInterface.OpenToolPanelViewEx2("" , "" ,Space.CurrentScene() + '/Camera, 1/Camera', 3, 1, 1);Node.Select(Space.CurrentScene() + '/Camera, 1');



Name: Cam 2
Command: D3DView.SetActiveCamera(Space.CurrentScene() + '/Camera, 2', '%WIN_ID%');D3DView.SetActiveCamera(Space.CurrentScene() + '/Camera,2', '%WIN_ID%');
RClick: UserInterface.OpenToolPanelViewEx2("" , "" ,Space.CurrentScene() + '/Camera, 2/Camera', 3, 1, 1);Node.Select(Space.CurrentScene() + '/Camera, 2');



Name: Cam 3
Command: D3DView.SetActiveCamera(Space.CurrentScene() + '/Camera, 3', '%WIN_ID%');D3DView.SetActiveCamera(Space.CurrentScene() + '/Camera,3', '%WIN_ID%');
RClick: UserInterface.OpenToolPanelViewEx2("" , "" ,Space.CurrentScene() + '/Camera, 3/Camera', 3, 1, 1);Node.Select(Space.CurrentScene() + '/Camera, 3');



Name: Cam 4
Command: D3DView.SetActiveCamera(Space.CurrentScene() + '/Camera, 4', '%WIN_ID%');D3DView.SetActiveCamera(Space.CurrentScene() + '/Camera,4', '%WIN_ID%');
RClick: UserInterface.OpenToolPanelViewEx2("" , "" ,Space.CurrentScene() + '/Camera, 4/Camera', 3, 1, 1);Node.Select(Space.CurrentScene() + '/Camera, 4');



Name: Cam 5
Command: D3DView.SetActiveCamera(Space.CurrentScene() + '/Camera, 5', '%WIN_ID%');D3DView.SetActiveCamera(Space.CurrentScene() + '/Camera,5', '%WIN_ID%');
RClick: UserInterface.OpenToolPanelViewEx2("" , "" ,Space.CurrentScene() + '/Camera, 5/Camera', 3, 1, 1);Node.Select(Space.CurrentScene() + '/Camera, 5');



Name: Cam 6
Command: D3DView.SetActiveCamera(Space.CurrentScene() + '/Camera, 6', '%WIN_ID%');D3DView.SetActiveCamera(Space.CurrentScene() + '/Camera,6', '%WIN_ID%');
RClick: UserInterface.OpenToolPanelViewEx2("" , "" ,Space.CurrentScene() + '/Camera, 6/Camera', 3, 1, 1);Node.Select(Space.CurrentScene() + '/Camera, 6');



Name: Eye2Cam
Command: Activity.Run("/Scripts/Commands/Eye2Cam");
RClick: Activity.Run("/Scripts/Commands/Position2Eye");



Name: Eye Cam
Command: Cam = Node.SubObject("/D3DView", 0);D3DView.SetActiveCamera('/D3DView/' + Cam, '%WIN_ID%');
RClick: Cam = Node.SubObject("/D3DView", 0);UserInterface.OpenToolPanelViewEx2("" , "" ,"/D3DView/" + Cam, 3, 0, 1);



Name: Copy
Command: Activity.Run("/Scripts/Commands/Copy");
RClick: 



Name: Copy
Command: Activity.Run("/Scripts/Commands/Copy");
RClick: 



Name: Cut
Command: Activity.Run("/Scripts/Commands/Cut");
RClick: 



Name: Paste
Command: Activity.Run("/Scripts/Commands/Paste");
RClick: 



Name: cubeWidget
Command: Node.Delete("/Widgets/Active Widgets Layer2/CubeWidget");Node.Copy("/Widgets/Tools/CubeWidget","/Widgets/Active Widgets Layer2");UserInterface.OpenToolPanelViewEx2("" , "" ,"/Widgets/Active Widgets Layer2/CubeWidget/Cube View Widget", 3,1,0);
RClick: if(Node.Exists("/Widgets/Active Widgets Layer2/CubeWidget")) UserInterface.OpenToolPanelViewEx2("" , "" ,"/Widgets/Active Widgets Layer2/CubeWidget/Cube View Widget", 3,1,0);



Name: load curve
Command: UserInterface.OpenToolPanelViewEx2("" , "" ,"Scripts/CustomCommands/loadCurveScript", 3,1,0)
RClick: 



Name: polygon2curve
Command: Activity.Run("Scripts/CustomCommands/polygon2curveScript/selectVertexMode")
RClick: UserInterface.OpenToolPanelViewEx2("" , "" ,"Scripts/CustomCommands/polygon2curveScript", 4,1,0)



Name: points2curve
Command: MeshModifiers.TogglePeTool('Widgets/Tools/Mesh editor/PE MakeCurve','');
RClick: 



Name: sweepPath
Command: Activity.Run("Scripts/CustomCommands/sweepPathScript/savefacesel");
RClick: 



Name: extendcurve
Command: Activity.Run("Scripts/CustomCommands/extendCurveScript/appendCP")
RClick: 



Name: insertcp
Command: Activity.Run("Scripts/CustomCommands/insertControlPointScript/refreshCurve")
RClick: 



Name: deletecp
Command: Activity.Run("Scripts/CustomCommands/deleteControlPointScript/deleteCP")
RClick: 



Name: PSKPSAT3DimportexportPanel
Command: UserInterface.OpenToolPanelViewEx2("" , "" ,"Scripts/CustomCommands/unreal import export", 3, 1, 0);
RClick: 



Name: SVGimportCOBexportPanel
Command: UserInterface.OpenToolPanelViewEx2("" , "" ,"Scripts/CustomCommands/SVGimporter", 3, 1, 0);
RClick: 



Name: fbxImportExportScripts2
Command: UserInterface.OpenToolPanelViewEx2("" , "" ,"/Scripts/CustomCommands/fbxgroup2", 8, 1, 0)
RClick: UserInterface.OpenToolPanelViewEx2("" , "" ,"/Scripts/CustomCommands/fbxgroup2", 9, 1, 0)



Name: Spline Polygon
Command: tSBridge.SuggestTSState(48 , 4096);
RClick: 



Name: Create Clip
Command: RsAnimPlugin.CreateProcClip('')
RClick: 



Name: Rec
Command: RsAnim.SetKeyFrame('', RsTime.CurrentTime())
RClick: RsAnimKeying.OpenView()



Name: Start frame
Command: RsTime.StartFrame()
RClick: 



Name: Prev keyframe
Command: RsTime.PrevKeyFrame()
RClick: 



Name: Prev frame
Command: RsTime.PrevFrame()
RClick: 



Name: Stop
Command: RsTime.Stop()
RClick: 



Name: Play
Command: RsTime.Play('')
RClick: 



Name: Next frame
Command: RsTime.NextFrame()
RClick: 



Name: Next keyframe
Command: RsTime.NextKeyFrame()
RClick: 



Name: End frame
Command: RsTime.EndFrame()
RClick: 



Name: Object
Command: RsTool.Arrow();Space.Unselect();
RClick: RsTool.OpenInfoPanel();



Name: Object
Command: RsTool.Arrow();Space.Unselect();
RClick: RsTool.OpenInfoPanel();



Name: Location
Command: RsTool.NormalizeLocation('');
RClick: 



Name: Scale
Command: RsTool.NormalizeSize('');
RClick: 



Name: Rotation
Command: RsTool.NormalizeRotation('');
RClick: 



Name: Reset
Command: RsTool.ResetAxes('');
RClick: 



Name: Axis
Command: RsTool.ShowAxes('');
RClick: RsTool.ToggleValue("/Widgets/Tools/Axes widget/Default/In front");



Name: Flatten
Command: MeshModifiers.FlattenAxes('');
RClick: 



Name: Lasso
Command: MeshModifiers.ActivatePointEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Mesh editor/PE lasso select','Default'); Node.Value('/Preferences/Mesh Editor Settings','PE selection tool') = '/Widgets/Tools/Mesh editor/PE lasso select';UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE lasso select/Lasso select',3,1,0,2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE lasso select/Lasso select',3,1,0,2);



Name: Lasso
Command: MeshModifiers.ActivatePointEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Mesh editor/PE lasso select','Default'); Node.Value('/Preferences/Mesh Editor Settings','PE selection tool') = '/Widgets/Tools/Mesh editor/PE lasso select';UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE lasso select/Lasso select',3,1,0,2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE lasso select/Lasso select',3,1,0,2);



Name: Paint
Command: MeshModifiers.ActivatePointEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Mesh editor/PE basic select','Default'); Node.Value('/Preferences/Mesh Editor Settings','PE selection tool') = '/Widgets/Tools/Mesh editor/PE basic select';
RClick: 



Name: Rectangle
Command: MeshModifiers.ActivatePointEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Mesh editor/PE rect select','Default'); Node.Value('/Preferences/Mesh Editor Settings','PE selection tool') = '/Widgets/Tools/Mesh editor/PE rect select';UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE rect select/Rect select',3,1,0,2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE rect select/Rect select',3,1,0,2);



Name: Lasso
Command: MeshModifiers.ActivatePointEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Mesh editor/PE lasso select','Default'); Node.Value('/Preferences/Mesh Editor Settings','PE selection tool') = '/Widgets/Tools/Mesh editor/PE lasso select';UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE lasso select/Lasso select',3,1,0,2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE lasso select/Lasso select',3,1,0,2);



Name: DynaPick
Command: MeshModifiers.ActivatePointEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Mesh editor/PE dynapick','Default'); Node.Value('/Preferences/Mesh Editor Settings','PE selection tool') = '/Widgets/Tools/Mesh editor/PE dynapick';
RClick: 



Name: Soft
Command: MeshModifiers.ActivatePointEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Mesh editor/PE soft select','Default'); Node.Value('/Preferences/Mesh Editor Settings','PE selection tool') = '/Widgets/Tools/Mesh editor/PE soft select';UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE soft select/Soft select',3,1,0,2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE soft select/Soft select',3,1,0,2);



Name: Invert
Command: MeshModifiers.InvertSelection('');
RClick: 



Name: Invert
Command: MeshModifiers.InvertSelection('');
RClick: 



Name: Connected
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Select tool','apply_cmd:{0502CC2A-7F8C-4d29-BBB4-9F1F2ECDC84C}');
RClick: 



Name: Unselect
Command: MeshModifiers.PeDeselect('');
RClick: 



Name: Materials
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Select tool','apply_cmd:{7BFCBE4C-E2C4-46d6-9A2D-4498053527EC}');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Mesh Editor Settings',9,0,0);



Name: Path
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Select tool','apply_cmd:{7DBD4078-6AC7-48f4-A52D-C4A65CAB0C51};select_invselect');
RClick: 



Name: Grow
Command: MeshModifiers.GrowPointEditSelection('');MeshModifiers.ConvertSelection('','');
RClick: 



Name: Grow
Command: MeshModifiers.GrowPointEditSelection('');MeshModifiers.ConvertSelection('','');
RClick: 



Name: Shrink
Command: MeshModifiers.ShrinkPointEditSelection('');MeshModifiers.ConvertSelection('','');
RClick: 



Name: Convert
Command: MeshModifiers.ConvertSelection('','');
RClick: 



Name: Smooth
Command: MeshModifiers.SmoothPointEditSelection('');
RClick: 



Name: Outline
Command: MeshModifiers.OutlinePointEditSelection('');
RClick: 



Name: Selected
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Rect tool','apply_cmd:{908A59AA-0921-4e53-82EA-0F427904F48E}');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/PE Rect tool/Rect select tool',3,0,0);



Name: Selected
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Rect tool','apply_cmd:{908A59AA-0921-4e53-82EA-0F427904F48E}');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/PE Rect tool/Rect select tool',3,0,0);



Name: Hide
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Rect tool','apply_cmd:{70902786-9BA6-4233-975B-342BA6A274E7}');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/PE Rect tool/Rect select tool',3,0,0);



Name: Unhide
Command: MeshModifiers.ShowHiddenPeGeometry('');
RClick: 



Name: EdgeLoops
Command: Node.Value('/Preferences/Mesh Editor Settings','PE selection mode') = 'edge loop'; MeshModifiers.ActivatePointEditWidget('','','Default');
RClick: 



Name: Context
Command: Node.Value('/Preferences/Mesh Editor Settings','PE selection mode') = 'context'; MeshModifiers.ActivatePointEditWidget('','','Default');
RClick: 



Name: Vertices
Command: Node.Value('/Preferences/Mesh Editor Settings','PE selection mode') = 'vertex'; MeshModifiers.ActivatePointEditWidget('','','Default');
RClick: 



Name: Edges
Command: Node.Value('/Preferences/Mesh Editor Settings','PE selection mode') = 'face edge'; MeshModifiers.ActivatePointEditWidget('','','Default');
RClick: 



Name: Edges
Command: Node.Value('/Preferences/Mesh Editor Settings','PE selection mode') = 'face edge'; MeshModifiers.ActivatePointEditWidget('','','Default');
RClick: 



Name: TriEdges
Command: Node.Value('/Preferences/Mesh Editor Settings','PE selection mode') = 'triangle edge'; MeshModifiers.ActivatePointEditWidget('','','Default');
RClick: 



Name: Faces
Command: Node.Value('/Preferences/Mesh Editor Settings','PE selection mode') = 'face'; MeshModifiers.ActivatePointEditWidget('','','Default');
RClick: 



Name: Faces
Command: Node.Value('/Preferences/Mesh Editor Settings','PE selection mode') = 'face'; MeshModifiers.ActivatePointEditWidget('','','Default');
RClick: 



Name: TriFaces
Command: Node.Value('/Preferences/Mesh Editor Settings','PE selection mode') = 'triangle'; MeshModifiers.ActivatePointEditWidget('','','Default');
RClick: 



Name: EdgeLoops
Command: Node.Value('/Preferences/Mesh Editor Settings','PE selection mode') = 'edge loop'; MeshModifiers.ActivatePointEditWidget('','','Default');
RClick: 



Name: EdgeLoops
Command: Node.Value('/Preferences/Mesh Editor Settings','PE selection mode') = 'edge loop'; MeshModifiers.ActivatePointEditWidget('','','Default');
RClick: 



Name: FaceLoops
Command: Node.Value('/Preferences/Mesh Editor Settings','PE selection mode') = 'face loop'; MeshModifiers.ActivatePointEditWidget('','','Default');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Modeling preferences',4,1,1);



Name: AddVertices
Command: MeshModifiers.ActivatePointEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Mesh editor/PE Vertex draw','Default')
RClick: 



Name: DynaSweep
Command: MeshModifiers.TogglePeTool('/Widgets/Tools/Mesh editor/PE Sweep',''); UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE Sweep/Dynamic Sweep',3,1, 0, 2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE Sweep/Dynamic Sweep',3,1,0,2);



Name: DynaSweep
Command: MeshModifiers.TogglePeTool('/Widgets/Tools/Mesh editor/PE Sweep',''); UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE Sweep/Dynamic Sweep',3,1, 0, 2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE Sweep/Dynamic Sweep',3,1,0,2);



Name: Bevel
Command: MeshModifiers.TogglePeTool('/Widgets/Tools/Mesh editor/PE Bevel',''); UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE Bevel/Bevel tool',3,1,0, 2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE Bevel/Bevel tool',3,1,0, 2);



Name: Sweep
Command: MeshModifiers.ExtrudeSelection('')
RClick: 



Name: Tip
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Select tool','apply_cmd:{D836AAE0-6E0C-48d9-95DC-8FDA120A29DF}');
RClick: 



Name: Modeler
Command: MeshModifiers.AddMirrorModeler('');
RClick: MeshModifiers.ShowMirrorProperties('');



Name: Modeler
Command: MeshModifiers.AddMirrorModeler('');
RClick: MeshModifiers.ShowMirrorProperties('');



Name: Mirror
Command: MeshModifiers.MirrorSelection('');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Mesh Editor Settings',7,0,0);



Name: Copy
Command: MeshModifiers.DuplicateSelection('');
RClick: 



Name: Separate
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Select tool','apply_cmd:{6D90C46D-A984-47fa-8C14-C7ADF45DD882}');
RClick: 



Name: Flip
Command: MeshModifiers.FlipFacesNormals('');
RClick: 



Name: Flip
Command: MeshModifiers.FlipFacesNormals('');
RClick: 



Name: Delete
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Select tool','apply_cmd:{8982C2F3-3070-40e5-9967-E44CFFD1763E}');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Mesh Editor Settings',8,0,0);



Name: FormFace
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Select tool','apply_cmd:{7032EC04-4E22-4e94-8E88-1F0143DCEE33};select_mode:hole');
RClick: 



Name: Vertex Snap
Command: Node.Delete("/Widgets/Active Widgets Layer2/Vertex Snap");Node.Copy("/Widgets/Tools/Vertex Snap","/Widgets/Active Widgets Layer2");UserInterface.OpenToolPanelViewEx2("", "", "Widgets/Active Widgets Layer2/Vertex Snap/Vertex Snap", 4, 0, 0);
RClick: UserInterface.OpenToolPanelViewEx2("", "", "Widgets/Active Widgets Layer2/Vertex Snap/Vertex Snap", 4, 0, 0);



Name: Face Snap
Command: Activity.Run("/Widgets/Tools/Face Snap/save obj ref");
RClick: Activity.Run("/Widgets/Tools/Face Snap/setCopyFlag");



Name: Quadrify
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Select tool','apply_cmd:{3C2CB50B-42E0-47ef-B9A8-A75E6CBCA9F0};select_mode:face');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Mesh Editor Settings',8,0,0);



Name: Split
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Select tool','apply_cmd:{0A28658A-C334-4199-9C30-EB833B77A908}');
RClick: 



Name: Merge
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Select tool','apply_cmd:{3E45513F-2866-457f-82EA-EE9FAC8BD84E}');
RClick: 



Name: SwapEdge
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Select tool','apply_cmd:{09B80301-7C86-4100-824A-C4148A696F1B};select_mode:triangle edge');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Mesh Editor Settings',8,0,0);



Name: Optimize
Command: MeshModifiers.OptimizeTriangulation('');
RClick: 



Name: Quadrify
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Select tool','apply_cmd:{3C2CB50B-42E0-47ef-B9A8-A75E6CBCA9F0};select_mode:face');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Mesh Editor Settings',8,0,0);



Name: AddLoop
Command: MeshModifiers.TogglePeTool('/Widgets/Tools/Mesh editor/PE Add loop',''); UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE Add loop/Add loop',3,1, 0, 2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE Add loop/Add loop',3,1, 0, 2);



Name: AddLoop
Command: MeshModifiers.TogglePeTool('/Widgets/Tools/Mesh editor/PE Add loop',''); UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE Add loop/Add loop',3,1, 0, 2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE Add loop/Add loop',3,1, 0, 2);



Name: Collapse
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Select tool','apply_cmd:{E80D376F-7073-4186-88D1-3DA687A13E79}');
RClick: 



Name: Quad
Command: MeshModifiers.Subdivide('');
RClick: 



Name: Smooth
Command: MeshModifiers.Smoothdivide('');
RClick: 



Name: AddVertices
Command: MeshModifiers.ActivatePointEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Mesh editor/PE Vertex draw','Default')
RClick: 



Name: Polydraw
Command: MeshModifiers.ActivatePointEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Mesh editor/PE Poly draw','Default')
RClick: 



Name: AddEdges
Command: MeshModifiers.ActivatePointEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Mesh editor/PE Edge draw','Default')
RClick: 



Name: AddVertices
Command: MeshModifiers.ActivatePointEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Mesh editor/PE Vertex draw','Default')
RClick: 



Name: Bridge
Command: MeshModifiers.ActivatePointEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Mesh editor/PE bridge tool','Default'); UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/PE bridge tool/Bridge tool',3,1,1);
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/PE bridge tool/Bridge tool',3,1,1);



Name: Bridge
Command: MeshModifiers.ActivatePointEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Mesh editor/PE bridge tool','Default'); UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/PE bridge tool/Bridge tool',3,1,1);
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/PE bridge tool/Bridge tool',3,1,1);



Name: Weld
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Rect tool','apply_cmd:{87B113FD-B879-4b63-9C9A-28A38AED253B}');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/PE Rect tool/Rect select tool',3,0,0);



Name: Heal
Command: MeshModifiers.HealVertices('',-1);
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Mesh Editor Settings',6,0,0);



Name: Scissors
Command: MeshModifiers.Scissors('');
RClick: 



Name: fixBadGeometrytPanel
Command: WindowsManager.CloseWindow("/Project/Windows Manager Space/FBG_PanelFrame");Node.Copy("/Widgets/Tools/Fix Bad Geometry/FBG_PanelFrame", "/Project/Windows Manager Space");WindowsManager.Activate();WindowsManager.UpdateWindowsStructure();
RClick: 



Name: SelectAll
Command: Node.Value('/Preferences/Mesh Editor Settings','PE selection style') = 0;
RClick: 



Name: Visible
Command: Node.Value('/Preferences/Mesh Editor Settings','PE selection style') = 1;
RClick: 



Name: SelectAll
Command: Node.Value('/Preferences/Mesh Editor Settings','PE selection style') = 0;
RClick: 



Name: - SDS
Command: MeshModifiers.ChangeSSLevel(-1)
RClick: 



Name: Soft paint
Command: MeshModifiers.TogglePeTool('/Widgets/Tools/Mesh editor/PE soft paint','');UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/PE soft paint/Soft paint',3,1,0);
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/PE soft paint/Soft paint',3,1,0);



Name: - SDS
Command: MeshModifiers.ChangeSSLevel(-1)
RClick: 



Name: + SDS
Command: MeshModifiers.ChangeSSLevel(1)
RClick: 



Name: - SDS
Command: MeshModifiers.ChangeSSLevel(-1)
RClick: 



Name: ResetSDS
Command: MeshModifiers.ResetSds('',-1,-1,-1)
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Mesh Editor Settings',10,0,0);



Name: SDSVertex
Command: Widgets.ReplaceWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Mesh editor/PE vertex weight','Default','','')
RClick: 



Name: SDSEdge
Command: Widgets.ReplaceWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Mesh editor/PE edge weight','Default','','')
RClick: 



Name: Normalmap
Command: MeshModifiers.BuildNormalmap('')
RClick: 



Name: Normalmap
Command: MeshModifiers.BuildNormalmap('')
RClick: 



Name: Simplify
Command: MeshModifiers.SimplifyMesh('')
RClick: 



Name: Union
Command: MeshModifiers.ActivateBooleansTool('Union','')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/Booleans tool/Booleans',3,1,0);



Name: Union
Command: MeshModifiers.ActivateBooleansTool('Union','')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/Booleans tool/Booleans',3,1,0);



Name: Intersection
Command: MeshModifiers.ActivateBooleansTool('Intersection','')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/Booleans tool/Booleans',3,1,0);



Name: Subtract
Command: MeshModifiers.ActivateBooleansTool('Subtraction','')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/Booleans tool/Booleans',3,1,0);



Name: Cut
Command: MeshModifiers.ActivateBooleansTool('Cut','')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/Booleans tool/Booleans',3,1,0);



Name: Merge
Command: MeshModifiers.ActivateBooleansTool('Merge','')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/Booleans tool/Booleans',3,1,0);



Name: Merge
Command: MeshModifiers.ActivateBooleansTool('Merge','')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/Booleans tool/Booleans',3,1,0);



Name: Add
Command: MeshModifiers.ActivateBooleansTool('Add','')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/Booleans tool/Booleans',3,1,0);



Name: DisBrush
Command: MeshModifiers.EnableDisplacementBrush();UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/DM Brush/Displacement Brush',4,1,0,2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/DM Brush/Displacement Brush',4,1,0,2);



Name: DisBrush
Command: MeshModifiers.EnableDisplacementBrush();UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/DM Brush/Displacement Brush',4,1,0,2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/DM Brush/Displacement Brush',4,1,0,2);



Name: DisMap
Command: MeshModifiers.DisplacementMapping('');
RClick: 



Name: Length
Command: MeshModifiers.EnableHairBrush('{A7782DD7-DD86-4cbe-A562-E345805E59AB}');UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Hair/Hair Length Brush/Hair Length',3,1,0,2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Hair/Hair Length Brush/Hair Length',3,1,0,2);



Name: Length
Command: MeshModifiers.EnableHairBrush('{A7782DD7-DD86-4cbe-A562-E345805E59AB}');UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Hair/Hair Length Brush/Hair Length',3,1,0,2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Hair/Hair Length Brush/Hair Length',3,1,0,2);



Name: Blowdryer
Command: MeshModifiers.EnableHairBrush('{24C5D7C9-0A06-40f5-95F3-7BE7DC4177F8}');UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Hair/Hair Blowdryer/Hair Blowdryer',3,1,0,2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Hair/Hair Blowdryer/Hair Blowdryer',3,1,0,2);



Name: Softness
Command: MeshModifiers.EnableHairBrush('{A8A8F8B0-993C-4cd0-82AE-18B39BDA000F}');UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Hair/Hair Softness Brush/Hair Softness',3,1,0,2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Hair/Hair Softness Brush/Hair Softness',3,1,0,2);



Name: Direction
Command: MeshModifiers.EnableHairBrush('{CA36494D-CC50-436b-B5B3-4F16FB8422C9}');UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Hair/Hair Direction Brush/Hair Direction',3,1,0,2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Hair/Hair Direction Brush/Hair Direction',3,1,0,2);



Name: Density
Command: MeshModifiers.EnableHairBrush('{7DB4D6AE-8BFA-41dc-A9F7-4BB7916FD6D7}');UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Hair/Hair Density Brush/Hair Density',3,1,0,2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Hair/Hair Density Brush/Hair Density',3,1,0,2);



Name: M.Editor
Command: MeshModifiers.OpenMaterialEditor()
RClick: 



Name: M.Editor
Command: MeshModifiers.OpenMaterialEditor()
RClick: 



Name: Inspect
Command: MeshModifiers.OpenMaterialEditor();MeshModifiers.ToggleTool('/Widgets/Tools/Material editor/Inspect')
RClick: MeshModifiers.OpenMaterialEditor()



Name: Inspect
Command: MeshModifiers.OpenMaterialEditor();MeshModifiers.ToggleTool('/Widgets/Tools/Material editor/Inspect')
RClick: MeshModifiers.OpenMaterialEditor()



Name: Objects
Command: MeshModifiers.OpenMaterialEditor();MeshModifiers.SetMaterial('')
RClick: MeshModifiers.OpenMaterialEditor()



Name: Faces
Command: MeshModifiers.OpenMaterialEditor();MeshModifiers.StartPaintFaceTool()
RClick: MeshModifiers.OpenMaterialEditor()



Name: Repaint
Command: MeshModifiers.OpenMaterialEditor();MeshModifiers.ToggleTool('/Widgets/Tools/Material editor/Repaint')
RClick: MeshModifiers.OpenMaterialEditor()



Name: UV Editor 
Command: UVEditor.Open('%THIS_BUTTON_ITEM%')
RClick: UserInterface.OpenToolPanelViewEx2('', '','Preferences/UV Editor Preferences',3, 1, 0)



Name: Cubic
Command: UVEditor.ToggleUvProjection('Cubic','')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/UV mapping/Projection tool/UV Projection tool',3,0,0);



Name: Spherical
Command: UVEditor.ToggleUvProjection('Spherical','')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/UV mapping/Projection tool/UV Projection tool',3,0,0);



Name: Planar
Command: UVEditor.ToggleUvProjection('Planar','')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/UV mapping/Projection tool/UV Projection tool',3,0,0);



Name: Cylindrical
Command: UVEditor.ToggleUvProjection('Cylindrical','')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/UV mapping/Projection tool/UV Projection tool',3,0,0);



Name: Cubic
Command: UVEditor.ToggleUvProjection('Cubic','')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/UV mapping/Projection tool/UV Projection tool',3,0,0);



Name: ShrinkUV
Command: MeshModifiers.ShrinkWrap('')
RClick: UserInterface.OpenToolPanelViewEx2('', '','Preferences/Shrink Wrap preferences',3, 1, 0);



Name: Smooth
Command: MeshModifiers.SmoothNormals('')
RClick: 



Name: Smooth
Command: MeshModifiers.SmoothNormals('')
RClick: 



Name: AutoFacet
Command: MeshModifiers.AutofacetNormals('',-1)
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Mesh Editor Settings',5,0,0);



Name: Facet
Command: MeshModifiers.FacetedNormals('')
RClick: 



Name: +PhysAttr
Command: Physics.AddPhysAttr('');Physics.OpenNodePanel('phys', 3)
RClick: Physics.OpenNodePanel('phys', 3)



Name: +PhysAttr
Command: Physics.AddPhysAttr('');Physics.OpenNodePanel('phys', 3)
RClick: Physics.OpenNodePanel('phys', 3)



Name: +PhysAttr
Command: Physics.AddPhysAttr('');Physics.OpenNodePanel('phys', 3)
RClick: Physics.OpenNodePanel('phys', 3)



Name: +LocalEnv
Command: Physics.AddEnvAttr('');Physics.OpenNodePanel('phys', 3)
RClick: Physics.OpenNodePanel('env', 3)



Name: +ClothAttr
Command: Physics.AddClothAttr('');Physics.OpenNodePanel('phys', 3)
RClick: Physics.OpenNodePanel('cloth', 3)



Name: -PhysAttr
Command: Physics.RemovePhysAttr('')
RClick: 



Name: -LocalEnv
Command: Physics.RemoveEnvAttr('')
RClick: 



Name: -ClothAttr
Command: Physics.RemoveClothAttr('')
RClick: 



Name: Speed
Command: Physics.ActivatePhysWidget('SpeedWidget')
RClick: Physics.OpenNodePanel('phys', 4)



Name: Speed
Command: Physics.ActivatePhysWidget('SpeedWidget')
RClick: Physics.OpenNodePanel('phys', 4)



Name: Rotation
Command: Physics.ActivatePhysWidget('RotationWidget')
RClick: Physics.OpenNodePanel('phys', 4)



Name: A.Speed
Command: Physics.ActivatePhysWidget('AccWidget')
RClick: Physics.OpenNodePanel('phys', 5)



Name: A.Rotation
Command: Physics.ActivatePhysWidget('RotAccWidget')
RClick: Physics.OpenNodePanel('phys', 5)



Name: COG
Command: Physics.ActivatePhysWidget('CogWidget')
RClick: Physics.OpenNodePanel('phys', 7)



Name: COG
Command: Physics.ActivatePhysWidget('CogWidget')
RClick: Physics.OpenNodePanel('phys', 7)



Name: FixPoint1
Command: Physics.ActivatePhysWidget('Fix1Widget')
RClick: Physics.OpenNodePanel('phys', 7)



Name: FixPoint2
Command: Physics.ActivatePhysWidget('Fix2Widget')
RClick: Physics.OpenNodePanel('phys', 7)



Name: ClothFix
Command: Physics.ActivatePhysWidget('ClothFixWidget')
RClick: Physics.ActivatePhysWidget('ClothFixWidget');Physics.ResetClothFixation('')



Name: WindLocal
Command: Physics.AddWind('', true)
RClick: 



Name: WindLocal
Command: Physics.AddWind('', true)
RClick: 



Name: WindGlobal
Command: Physics.AddWind('', false)
RClick: 



Name: EnviLocal
Command: Physics.ActivatePhysWidget('LocEnvWidget')
RClick: Physics.OpenNodePanel('env', 3)



Name: Gravity
Command: Physics.ActivatePhysWidget('GravityWidget')
RClick: Physics.OpenNodePanel('space', 3)



Name: HealSkin
Command: CharacterEditor.HealSkin('');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Character editor preferences',7,1,1);



Name: Skeleton
Command: CharacterEditor.ActivateCharacterToolEx('/Widgets/Tools/Character editor/Skeleton tool','Default','{62E8596C-448F-4967-A317-516B044E80FB}{70F07F89-0410-41c4-803C-64C712261727}{/Preferences/Character editor preferences}','/Preferences/Character editor preferences/Joint marker');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Character editor preferences',6,1,1);



Name: Skeleton
Command: CharacterEditor.ActivateCharacterToolEx('/Widgets/Tools/Character editor/Skeleton tool','Default','{62E8596C-448F-4967-A317-516B044E80FB}{70F07F89-0410-41c4-803C-64C712261727}{/Preferences/Character editor preferences}','/Preferences/Character editor preferences/Joint marker');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Character editor preferences',6,1,1);



Name: DelJoint
Command: CharacterEditor.RemoveJoint('');
RClick: 



Name: ShapeSkel
Command: CharacterEditor.ActivateCharacterTool('/Widgets/Edit/Character editor widget');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Character editor preferences',3, 1, 1);



Name: -Limb
Command: CharacterEditor.RemoveLimb('');
RClick: 



Name: ResetPose
Command: CharacterEditor.ResetPose('');
RClick: 



Name: Limits
Command: CharacterEditor.ActivateCharacterTool('/Widgets/Edit/Joint limits');
RClick: CharacterEditor.EditJointsDirectly('');



Name: SetPose
Command: CharacterEditor.SetDefaultPose('');
RClick: 



Name: ResetPose
Command: CharacterEditor.ResetPose('');
RClick: 



Name: Envelope
Command: CharacterEditor.ActivateCharacterTool('/Widgets/Tools/Character editor/CE bone envelope tool');
RClick: 



Name: Envelope
Command: CharacterEditor.ActivateCharacterTool('/Widgets/Tools/Character editor/CE bone envelope tool');
RClick: 



Name: Skin2Bone
Command: CharacterEditor.ActivateCharacterTool('/Widgets/Tools/Character editor/Attach objects as a skin');
RClick: 



Name: Skin2Skeleton
Command: CharacterEditor.ActivateCharacterTool('/Widgets/Tools/Character editor/Attach skin to skeleton'); UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Character editor/Attach skin to skeleton/Attach skin to skeleton',3,1,1, 2); 
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Character editor/Attach skin to skeleton/Attach skin to skeleton',3,1,1, 2);



Name: Object2Bone
Command: CharacterEditor.ActivateCharacterTool('/Widgets/Tools/Character editor/Attach objects to bone');
RClick: 



Name: HealSkin
Command: CharacterEditor.HealSkin('');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Character editor preferences',7,1,1);



Name: Weight
Command: CharacterEditor.ActivateEditModeTool('/Widgets/Edit/Helpers/CE Weight paint','/Widgets/Tools/Character editor/CE Weight paint tool','&pref:/Widgets/Tools/Character editor/CE Weight paint tool/Weight paint&tag:brush');
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Character editor/CE Weight paint tool/Weight paint',3,1,1, 2);



Name: HealSkin
Command: CharacterEditor.HealSkin('');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Character editor preferences',7,1,1);



Name: Skin2Sel
Command: CharacterEditor.SkinToSelection('');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Mesh Editor Settings',3,1,1);



Name: Sel2Skin
Command: CharacterEditor.SelectionToSkin('');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Character editor preferences',8,1,1);



Name: Transfer
Command: CharacterEditor.ActivateEditModeTool('/Widgets/Edit/Helpers/CE Weight paint','/Widgets/Tools/Character editor/Skin transfer','&pref:/Widgets/Tools/Character editor/Skin transfer/Skin transfer&tag:transfer'); 
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Character editor/Skin transfer/Skin transfer',3,1,1, 2); 



Name: Pos.Lock
Command: CharacterEditor.ActivateCharacterToolEx('/Widgets/Tools/Character editor/Edit IK lock','Default','iklockpos.rsobj','%SKELETON%');
RClick: 



Name: Pos.Lock
Command: CharacterEditor.ActivateCharacterToolEx('/Widgets/Tools/Character editor/Edit IK lock','Default','iklockpos.rsobj','%SKELETON%');
RClick: 



Name: Rot.Lock
Command: CharacterEditor.ActivateCharacterToolEx('/Widgets/Tools/Character editor/Edit IK lock','Default','iklockrot.rsobj','%SKELETON%');
RClick: 



Name: FullLock
Command: CharacterEditor.ActivateCharacterToolEx('/Widgets/Tools/Character editor/Edit IK lock','Default','iklockfull.rsobj','%SKELETON%');
RClick: 



Name: ModIkHndl
Command: CharacterEditor.ActivateCharacterToolEx('/Widgets/Tools/Character editor/Edit Ik Motion Ctrl','Default','ikmchandle.rsobj','%SKELETON%');
RClick: 



Name: AlignHndl
Command: CharacterEditor.ActivateCharacterTool('/Widgets/Tools/Character editor/IK handle align');
RClick: 



Name: +Morph
Command: CharacterEditor.AddMorph('');
RClick: CharacterEditor.ShowMorphPanel('');



Name: C. Toolbar
Command: WindowsManager.CloseWindow("/Project/Windows Manager Space/Custom Toolbar Frame");RsFileIO.LoadObject(System.GetMainDir() + '\\Scripts\\preobjects\\Custom Toolbar Frame.RsObj', "/Project/Windows Manager Space/");Node.Value("/Project/Windows Manager Space/Custom Toolbar Frame", "SnappedTo") = WindowsManager.GetWorkWindow();Node.Value("/Project/Windows Manager Space/Custom Toolbar Frame", "OwnedBy") = WindowsManager.GetWorkWindow();WindowsManager.Activate();WindowsManager.UpdateWindowsStructure();
RClick: WindowsManager.CloseWindow("/Project/Windows Manager Space/Custom_Toolbar_Pref_Panel_Frame");Node.Copy("/Widgets/Tools/Custom Toolbar Preferences/Custom_Toolbar_Pref_Panel_Frame", "/Project/Windows Manager Space");WindowsManager.Activate();WindowsManager.UpdateWindowsStructure();



Name: Import
Command: ScriptObject.EditorTBCmd('{497C0AE3-1607-4838-87B6-0AF9FA39D057}', 57601)
RClick: 



Name: Export
Command: ScriptObject.EditorTBCmd('{497C0AE3-1607-4838-87B6-0AF9FA39D057}', 57602)
RClick: 



Name: Commit
Command: ScriptObject.EditorTBCmd('{497C0AE3-1607-4838-87B6-0AF9FA39D057}', 57614)
RClick: 



Name: Cut
Command: ScriptObject.EditorTBCmd('{497C0AE3-1607-4838-87B6-0AF9FA39D057}', 57603)
RClick: 



Name: Copy
Command: ScriptObject.EditorTBCmd('{497C0AE3-1607-4838-87B6-0AF9FA39D057}', 57604)
RClick: 



Name: Paste
Command: ScriptObject.EditorTBCmd('{497C0AE3-1607-4838-87B6-0AF9FA39D057}', 57605)
RClick: 



Name: Undo
Command: ScriptObject.EditorTBCmd('{497C0AE3-1607-4838-87B6-0AF9FA39D057}', 57606)
RClick: 



Name: Redo
Command: ScriptObject.EditorTBCmd('{497C0AE3-1607-4838-87B6-0AF9FA39D057}', 57607)
RClick: 



Name: Find
Command: ScriptObject.EditorTBCmd('{497C0AE3-1607-4838-87B6-0AF9FA39D057}', 57608)
RClick: 



Name: Advanced
Command: ScriptObject.EditorTBCmd('{497C0AE3-1607-4838-87B6-0AF9FA39D057}', 57620)
RClick: 



Name: Set Camera
Command: D3DView.SetActiveCamera('', '{1C55A5CC-992E-40AF-B7DC-118092E5D997}')
RClick: 



Name: Set Camera
Command: D3DView.SetActiveCamera('', '{1C55A5CC-992E-40AF-B7DC-118092E5D997}')
RClick: 



Name: Orthogonal
Command: D3DView.SwitchEyeCameraType('{1C55A5CC-992E-40AF-B7DC-118092E5D997}', '7')
RClick: 



Name: Set Camera
Command: D3DView.SetActiveCamera('', '{1C55A5CC-992E-40AF-B7DC-118092E5D997}')
RClick: 



Name: Perspective
Command: D3DView.SwitchEyeCameraType('{1C55A5CC-992E-40AF-B7DC-118092E5D997}', '0')
RClick: 



Name: Nearest ortho
Command: RsTool.SetNearestOrthoView('{1C55A5CC-992E-40AF-B7DC-118092E5D997}');
RClick: 



Name: Perspective
Command: D3DView.SwitchEyeCameraType('{1C55A5CC-992E-40AF-B7DC-118092E5D997}', '0')
RClick: 



Name: Top
Command: D3DView.SwitchEyeCameraType('{1C55A5CC-992E-40AF-B7DC-118092E5D997}', '2')
RClick: 



Name: Bottom
Command: D3DView.SwitchEyeCameraType('{1C55A5CC-992E-40AF-B7DC-118092E5D997}', '1')
RClick: 



Name: Top
Command: D3DView.SwitchEyeCameraType('{1C55A5CC-992E-40AF-B7DC-118092E5D997}', '2')
RClick: 



Name: Front
Command: D3DView.SwitchEyeCameraType('{1C55A5CC-992E-40AF-B7DC-118092E5D997}', '4')
RClick: 



Name: Back
Command: D3DView.SwitchEyeCameraType('{1C55A5CC-992E-40AF-B7DC-118092E5D997}', '3')
RClick: 



Name: Front
Command: D3DView.SwitchEyeCameraType('{1C55A5CC-992E-40AF-B7DC-118092E5D997}', '4')
RClick: 



Name: Left
Command: D3DView.SwitchEyeCameraType('{1C55A5CC-992E-40AF-B7DC-118092E5D997}', '6')
RClick: 



Name: Right
Command: D3DView.SwitchEyeCameraType('{1C55A5CC-992E-40AF-B7DC-118092E5D997}', '5')
RClick: 



Name: Left
Command: D3DView.SwitchEyeCameraType('{1C55A5CC-992E-40AF-B7DC-118092E5D997}', '6')
RClick: 



Name: Opaque
Command: D3DView.LoadRAPreset('', 1.0, 0.0, '', '{1C55A5CC-992E-40AF-B7DC-118092E5D997}')
RClick: 



Name: Opaque
Command: D3DView.LoadRAPreset('', 1.0, 0.0, '', '{1C55A5CC-992E-40AF-B7DC-118092E5D997}')
RClick: 



Name: OpaqueWires
Command: D3DView.LoadRAPreset('', 1.0, 1.0, '', '{1C55A5CC-992E-40AF-B7DC-118092E5D997}')
RClick: 



Name: Transparent
Command: D3DView.LoadRAPreset('', 0.5, 0.0, '', '{1C55A5CC-992E-40AF-B7DC-118092E5D997}')
RClick: 



Name: TranspWires
Command: D3DView.LoadRAPreset('', 0.5, 1.0, '', '{1C55A5CC-992E-40AF-B7DC-118092E5D997}')
RClick: 



Name: Wireframe
Command: D3DView.LoadRAPreset('', 0.0, 1.0, '', '{1C55A5CC-992E-40AF-B7DC-118092E5D997}')
RClick: 



Name: Wireframe Grid
Command: D3DView.LoadRAPreset('', 'Wire', '{1C55A5CC-992E-40AF-B7DC-118092E5D997}')
RClick: 



Name: WireframeGrid
Command: D3DView.LoadRAPreset('', 'Wire', '{1C55A5CC-992E-40AF-B7DC-118092E5D997}')
RClick: 



Name: OpaqueGrid
Command: D3DView.LoadRAPreset('', 'Solid', '{1C55A5CC-992E-40AF-B7DC-118092E5D997}')
RClick: 



Name: NoGrid
Command: D3DView.LoadRAPreset('', 'None', '{1C55A5CC-992E-40AF-B7DC-118092E5D997}')
RClick: 



Name: Move
Command: Widgets.ReplaceWidget('{1ED6A591-1DF7-4e2c-9333-41216D589C27}','/Widgets/Tools/Move selection','Default','','')
RClick: 



Name: DynaPose
Command: CharacterEditor.ActivateCharacterDualTool('/Widgets/Tools/Dynamic pose');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Dynamic pose/Dynamic pose tool',3,1,0);



Name: PhysMove
Command: Physics.ActivateWidget('PhysMoveWidget')
RClick: 



Name: Move
Command: Widgets.ReplaceWidget('{1ED6A591-1DF7-4e2c-9333-41216D589C27}','/Widgets/Tools/Move selection','Default','','')
RClick: 



Name: Rotate
Command: Widgets.ReplaceWidget('{1ED6A591-1DF7-4e2c-9333-41216D589C27}','/Widgets/Tools/Rotate selection','Default','','')
RClick: 



Name: Scale
Command: Widgets.ReplaceWidget('{1ED6A591-1DF7-4e2c-9333-41216D589C27}','/Widgets/Tools/Scale selection','Default','','')
RClick: 



Name: FP navigation
Command: RsTool.ActivateFpnToView('{1C55A5CC-992E-40AF-B7DC-118092E5D997}');
RClick: RsTool.ShowFpnProperties();



Name: FP navigation
Command: RsTool.ActivateFpnToView('{1C55A5CC-992E-40AF-B7DC-118092E5D997}');
RClick: RsTool.ShowFpnProperties();



Name: Move Cam
Command: ToolMng.ActivateTool('{17D544A3-3F58-436B-83E7-F8B4D7D4E7C5}','{8C391B6C-47E9-4AC4-BE8C-EC611B15178C}' )
RClick: 



Name: Rotate Cam
Command: ToolMng.ActivateTool('{17D544A3-3F58-436B-83E7-F8B4D7D4E7C5}','{8F7BE0C3-7239-47B3-9F16-63910CEFA571}' )
RClick: 



Name: Fov Cam
Command: ToolMng.ActivateTool('{17D544A3-3F58-436B-83E7-F8B4D7D4E7C5}','{3308E440-3D3A-4C81-BA70-C120D680B225}' )
RClick: 



Name: Rect zoom
Command: Widgets.ActivateToolWidget('/Widgets/Tools/Rect zoom','Default')
RClick: 



Name: Look At
Command: ToolMng.ActivateTool('{17D544A3-3F58-436B-83E7-F8B4D7D4E7C5}','{4E203C6C-A20D-4e32-82B4-FC482F5A0D06}' )
RClick: 



Name: Stop Recording
Command: RsRec.Stop()
RClick: 



Name: Play Record
Command: RsRec.Play(10)
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/RecPref',3,1,1);



Name: Reverse Play
Command: RsRec.PlayBack(10)
RClick: 



Name: Play Record
Command: RsRec.Play(10)
RClick: 



Name: Open Media View 
Command: RsRec.CreateRecPreview()
RClick: 



Name: Import Record
Command: RsRec.Load('')
RClick: 



Name: Open Media View 
Command: RsRec.CreateRecPreview()
RClick: 



Name: Export Record
Command: RsRec.Save('')
RClick: 



Name: Pause Replaying
Command: RsRec.Pause()
RClick: 



Name: Clear Record
Command: RsRec.Clear()
RClick: 



Name: Start Record
Command: RsRec.Start(Space.CurrentScene())
RClick: 



Name: Stop Macro Recording
Command: ScriptObject.StopMacroRecording('<common_jScript_macro>')
RClick: 



Name: Play Latest Macro Record
Command: ScriptObject.RunLastMacroRecord('<common_jScript_macro>')
RClick: 



Name: Start Macro Record
Command: ScriptObject.StartMacroRecording('<common_jScript_macro>')
RClick: 



Name: Stop activities
Command: Activity.KillAll()
RClick: 



Name: Stop Macro Recording
Command: ScriptObject.StopMacroRecording('<common_VB_macro>')
RClick: 



Name: Play Latest Macro Record
Command: ScriptObject.RunLastMacroRecord('<common_VB_macro>')
RClick: 



Name: Start Macro Record
Command: ScriptObject.StartMacroRecording('<common_VB_macro>')
RClick: 



Name: Stop activities
Command: Activity.KillAll()
RClick: 



Name: Rectangle selection
Command: UVEditor.SetTool('%THIS_BUTTON_ITEM%','Rectangle');
RClick: 



Name: Paint selection
Command: UVEditor.SetTool('%THIS_BUTTON_ITEM%','Paint');
RClick: 



Name: Rectangle selection
Command: UVEditor.SetTool('%THIS_BUTTON_ITEM%','Rectangle');
RClick: 



Name: Lasso selection
Command: UVEditor.SetTool('%THIS_BUTTON_ITEM%','Lasso');
RClick: 



Name: Pick/move selected element
Command: UVEditor.SetTool('%THIS_BUTTON_ITEM%','Dynapick');
RClick: 



Name: Vertex mode
Command: UVEditor.SetSelectionElement('%THIS_BUTTON_ITEM%','Vertex');
RClick: 



Name: Vertex mode
Command: UVEditor.SetSelectionElement('%THIS_BUTTON_ITEM%','Vertex');
RClick: 



Name: Edge mode
Command: UVEditor.SetSelectionElement('%THIS_BUTTON_ITEM%','Edge');
RClick: 



Name: Select nearest
Command: UVEditor.SetSelectionElement('%THIS_BUTTON_ITEM%','Nearest');
RClick: 



Name: Triangle mode
Command: UVEditor.SetSelectionElement('%THIS_BUTTON_ITEM%','Triangle');
RClick: 

Name: Face mode
Command: UVEditor.SetSelectionElement('%THIS_BUTTON_ITEM%','FaceTriangle');
RClick: 

Name: Patch mode
Command: UVEditor.SetSelectionElement('%THIS_BUTTON_ITEM%','Patch');
RClick: 

Name: Rotate selection
Command: UVEditor.SetTool('%THIS_BUTTON_ITEM%','Rotate');
RClick: 

Name: Move selection
Command: UVEditor.SetTool('%THIS_BUTTON_ITEM%','Move');
RClick: 

Name: Scale selection
Command: UVEditor.SetTool('%THIS_BUTTON_ITEM%','Scale');
RClick: 

Name: Rotate selection
Command: UVEditor.SetTool('%THIS_BUTTON_ITEM%','Rotate');
RClick: 

Name: Paint brush
Command: UVEditor.SetTool('%THIS_BUTTON_ITEM%','Brush');
RClick: 

Name: Paint brush
Command: UVEditor.SetTool('%THIS_BUTTON_ITEM%','Brush');
RClick: 

Name: Draw line
Command: UVEditor.SetTool('%THIS_BUTTON_ITEM%','Line');
RClick: 

Name: Slice selection
Command: UVEditor.SliceSelection('%THIS_BUTTON_ITEM%');
RClick: 

Name: Weld vertices
Command: UVEditor.WeldSelection('%THIS_BUTTON_ITEM%');
RClick: 

Name: Slice selection
Command: UVEditor.SliceSelection('%THIS_BUTTON_ITEM%');
RClick: 

Name: Heal vertices
Command: UVEditor.Heal('');
RClick: UVEditor.ShowPreferencesPanel('Preferences/UV Editor Preferences/UV Heal Preferences');

Name: Flatten vertices
Command: UVEditor.Flatten('');
RClick: UVEditor.ShowPreferencesPanel('Preferences/UV Editor Preferences/UV Flatten Preferences');

Name: Export texture
Command: UVEditor.ExportTexture('%THIS_BUTTON_ITEM%','',false);
RClick: 

Name: Export texture
Command: UVEditor.ExportTexture('%THIS_BUTTON_ITEM%','',false);
RClick: 

Name: Edit texture
Command: UVEditor.EditTexture('%THIS_BUTTON_ITEM%','');
RClick: 

Name: Synchronize UV
Command: UVEditor.SyncUV('',-1,-1)
RClick: 

Name: Synchronize UV
Command: UVEditor.SyncUV('',-1,-1)
RClick: 

Name: Flip horizontally
Command: UVEditor.FlipSelection('','Horizontal');
RClick: 

Name: Flip vertically
Command: UVEditor.FlipSelection('','Vertical');
RClick: 



Name: CE
Command: CharacterEditor.ActivateCharacterEditor('');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Character editor preferences',3, 1, 1);

Name: CE
Command: CharacterEditor.ActivateCharacterEditor('');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Character editor preferences',3, 1, 1);

Name: Build skeleton
Command: CharacterEditor.ActivateCharacterDualToolEx('/Widgets/Tools/Skeleton tool','Default','{62E8596C-448F-4967-A317-516B044E80FB}{70F07F89-0410-41c4-803C-64C712261727}{/Preferences/Character editor preferences/Preferences}','/Preferences/Character editor preferences/Joint marker');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Character editor preferences',3,1,1);



Name: AttachSkin
Command: CharacterEditor.ActivateCharacterEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Attach objects as a skin','Default','','');
RClick: 

Name: AttachSkin
Command: CharacterEditor.ActivateCharacterEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Attach objects as a skin','Default','','');
RClick: 

Name: AttachObj
Command: CharacterEditor.ActivateCharacterEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Attach objects to bone','Default','','');
RClick: 



Name: Ik1DHandle
Command: CharacterEditor.ActivateCharacterEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Edit Ik Motion Ctrl','Default','ikmcmove1D.rsobj','dummy');
RClick: 

Name: Ik1DHandle
Command: CharacterEditor.ActivateCharacterEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Edit Ik Motion Ctrl','Default','ikmcmove1D.rsobj','dummy');
RClick: 

Name: Ik2DHandle
Command: CharacterEditor.ActivateCharacterEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Edit Ik Motion Ctrl','Default','ikmcmove2D.rsobj','dummy');
RClick: 



Name: IkHandleAlign
Command: CharacterEditor.ActivateCharacterDualTool('/Widgets/Tools/IK handle align');
RClick: 



Name: ResetIkAlign
Command: CharacterEditor.AlignHandleWithSkeleton('');
RClick: 



Name: EditIkHandle
Command: CharacterEditor.ActivateCharacterDualTool('/Widgets/Edit/Ik Motion Ctrl handle edit');
RClick: 



Name: PosLock
Command: CharacterEditor.ActivateCharacterEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Edit IK lock','Default','iklockpos.rsobj','dummy');
RClick: 



Name: PosLock
Command: CharacterEditor.ActivateCharacterEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Edit IK lock','Default','iklockpos.rsobj','dummy');
RClick: 



Name: RotLock
Command: CharacterEditor.ActivateCharacterEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Edit IK lock','Default','iklockrot.rsobj','dummy');
RClick: 



Name: FullLock
Command: CharacterEditor.ActivateCharacterEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Edit IK lock','Default','iklockfull.rsobj','dummy');
RClick: 



Name: Solid
Command: Physics.AddPhysAttr('')
RClick: 



Name: Speed
Command: Physics.ActivatePhysWidget('SpeedWidget')
RClick: 



Name: Speed
Command: Physics.ActivatePhysWidget('SpeedWidget')
RClick: 



Name: Rotation
Command: Physics.ActivatePhysWidget('RotationWidget')
RClick: 



Name: Acc Speed
Command: Physics.ActivatePhysWidget('AccWidget')
RClick: 



Name: Acc Rotation
Command: Physics.ActivatePhysWidget('RotAccWidget')
RClick: 



Name: Cog
Command: Physics.ActivatePhysWidget('CogWidget')
RClick: 



Name: Cog
Command: Physics.ActivatePhysWidget('CogWidget')
RClick: 



Name: Fix1
Command: Physics.ActivatePhysWidget('Fix1Widget')
RClick: 



Name: Fix2
Command: Physics.ActivatePhysWidget('Fix2Widget')
RClick: 



Name: Global Wind
Command: Physics.AddWind('', false)
RClick: 



Name: Global Wind
Command: Physics.AddWind('', false)
RClick: 



Name: Local Wind
Command: Physics.AddWind('', true)
RClick: 



Name: Local Environment
Command: Physics.ActivatePhysWidget('LocEnvWidget')
RClick: 



Name: Gravity
Command: Physics.ActivatePhysWidget('GravityWidget')
RClick: 



Name: Solid
Command: Physics.AddPhysAttr('')
RClick: 



Name: Solid
Command: Physics.AddPhysAttr('')
RClick: 



Name: Liquid/Gas
Command: Physics.AddEnvAttr('')
RClick: 



Name: RemovePhysAttr
Command: Physics.RemovePhysAttr('')
RClick: 



Name: RemoveLocalEnv
Command: Physics.RemoveEnvAttr('')
RClick: 



Name: UV Editor  
Command: UVEditor.Open('%THIS_BUTTON_ITEM%')
RClick: UserInterface.OpenToolPanelViewEx2('', '','Preferences/UV Editor Preferences',3, 1, 0)



Name: UV Editor  
Command: UVEditor.Open('%THIS_BUTTON_ITEM%')
RClick: UserInterface.OpenToolPanelViewEx2('', '','Preferences/UV Editor Preferences',3, 1, 0)



Name: Spherical
Command: MeshModifiers.UVMapping('','Spherical')
RClick: 



Name: Spherical
Command: MeshModifiers.UVMapping('','Spherical')
RClick: 



Name: Planar
Command: MeshModifiers.UVMapping('','Planar')
RClick: 



Name: Cylindrical
Command: MeshModifiers.UVMapping('','Cylindrical')
RClick: 



Name: Cubic
Command: MeshModifiers.UVMapping('','Cubic')
RClick: 



Name: Shrink wrap
Command: MeshModifiers.ShrinkWrap('')
RClick: UserInterface.OpenToolPanelViewEx2('', '','Preferences/Shrink Wrap preferences',3, 1, 0);



Name: Create hair
Command: MeshModifiers.CreateHair('');
RClick: 



Name: Create hair
Command: MeshModifiers.CreateHair('');
RClick: 



Name: Length brush
Command: MeshModifiers.EnableHairBrush('{A7782DD7-DD86-4cbe-A562-E345805E59AB}');
RClick: 



Name: Density brush
Command: MeshModifiers.EnableHairBrush('{7DB4D6AE-8BFA-41dc-A9F7-4BB7916FD6D7}');
RClick: 



Name: Material Editor
Command: PhotoMaterialEditor.OpenMaterialEditor()
RClick: 



Name: ME Paint Object
Command: PhotoMaterialEditor.OpenMaterialEditor();PhotoMaterialEditor.PaintObject()
RClick: 



Name: ME Paint Face
Command: PhotoMaterialEditor.OpenMaterialEditor();PhotoMaterialEditor.StartPaintFaceTool()
RClick: 



Name: ME RePaint
Command: PhotoMaterialEditor.OpenMaterialEditor();PhotoMaterialEditor.StartPaintOverTool()
RClick: 



Name: ME Inspect
Command: PhotoMaterialEditor.OpenMaterialEditor();PhotoMaterialEditor.StartInspectTool()
RClick: 



Name: Displacement brush
Command: MeshModifiers.EnableDisplacementBrush();
RClick: 



Name: Displacement brush
Command: MeshModifiers.EnableDisplacementBrush();
RClick: 



Name: Displacement mapping
Command: MeshModifiers.DisplacementMapping('');
RClick: 



Name: Object tool
Command: Widgets.ActivateDefaultWidget();
RClick: RsTool.OpenInfoPanel();



Name: Pick/Paint selection
Command: Widgets.ReplaceWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/PE basic select','Default','',''); Node.Value('/Preferences/Modeling preferences','PE selection tool') = '/Widgets/Tools/PE basic select';
RClick: 



Name: Object tool
Command: Widgets.ActivateDefaultWidget();
RClick: RsTool.OpenInfoPanel();



Name: Pick/move selected element
Command: Widgets.ReplaceWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/PE dynapick','Default','',''); Node.Value('/Preferences/Modeling preferences','PE selection tool') = '/Widgets/Tools/PE dynapick';
RClick: 



Name: Select connected
Command: MeshModifiers.SelectConnected('');
RClick: 



Name: Invert selection
Command: MeshModifiers.InvertSelection('');
RClick: 



Name: Convert
Command: MeshModifiers.ConvertSelection('','');
RClick: 



Name: Shrink
Command: MeshModifiers.ShrinkPointEditSelection('');
RClick: 



Name: Grow
Command: MeshModifiers.GrowPointEditSelection('');
RClick: 



Name: Select connected
Command: MeshModifiers.SelectConnected('');
RClick: 



Name: Lasso selection
Command: Widgets.ReplaceWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/PE lasso select','Default','',''); Node.Value('/Preferences/Modeling preferences','PE selection tool') = '/Widgets/Tools/PE lasso select';
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/PE lasso select/Lasso select',3,1,0);



Name: Rectangle selection
Command: Widgets.ReplaceWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/PE rect select','Default','',''); Node.Value('/Preferences/Modeling preferences','PE selection tool') = '/Widgets/Tools/PE rect select';
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/PE rect select/Rect select',3,1,0);



Name: Create soft selection using painting
Command: Widgets.ReplaceWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/PE soft select','Default','',''); Node.Value('/Preferences/Modeling preferences','PE selection tool') = '/Widgets/Tools/PE soft select';
RClick: 



Name: Point edit: context
Command: Node.Value('/Preferences/Modeling preferences','PE selection mode') = 'context'; MeshModifiers.ActivatePointEditWidget('','','Default');
RClick: 



Name: Point edit: context
Command: Node.Value('/Preferences/Modeling preferences','PE selection mode') = 'context'; MeshModifiers.ActivatePointEditWidget('','','Default');
RClick: 



Name: Edge mode
Command: Node.Value('/Preferences/Modeling preferences','PE selection mode') = 'face edge'
RClick: 



Name: Triangle edge mode
Command: Node.Value('/Preferences/Modeling preferences','PE selection mode') = 'triangle edge'
RClick: 



Name: Point edit: edges
Command: Node.Value('/Preferences/Modeling preferences','PE selection mode') = 'face edge'; MeshModifiers.ActivatePointEditWidget('','','Default');
RClick: 



Name: Point edit: vertex
Command: Node.Value('/Preferences/Modeling preferences','PE selection mode') = 'vertex'; MeshModifiers.ActivatePointEditWidget('','','Default');
RClick: 



Name: Edge loop mode
Command: Node.Value('/Preferences/Modeling preferences','PE selection mode') = 'edge loop'
RClick: 



Name: Face loop mode
Command: Node.Value('/Preferences/Modeling preferences','PE selection mode') = 'face loop'
RClick: 



Name: Edge loop mode
Command: Node.Value('/Preferences/Modeling preferences','PE selection mode') = 'edge loop'
RClick: 



Name: Face mode
Command: Node.Value('/Preferences/Modeling preferences','PE selection mode') = 'face'
RClick: 



Name: Triangle mode
Command: Node.Value('/Preferences/Modeling preferences','PE selection mode') = 'triangle'
RClick: 



Name: Face mode
Command: Node.Value('/Preferences/Modeling preferences','PE selection mode') = 'face'
RClick: 



Name: Normal sweep 
Command: MeshModifiers.TogglePeTool('/Widgets/Tools/PE Sweep','');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/PE Sweep/Sweep',3,1,0);



Name: Polygon bridge/blend
Command: Widgets.ReplaceWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/PE bridge tool','Default','','');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/PE bridge tool/Bridge tool',3,1,0);



Name: Weld
Command: MeshModifiers.WeldSelection('');
RClick: 



Name: Polygon bridge/blend
Command: Widgets.ReplaceWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/PE bridge tool','Default','','');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/PE bridge tool/Bridge tool',3,1,0);



Name: Add loop
Command: MeshModifiers.TogglePeTool('/Widgets/Tools/PE Add loop','');
RClick: 



Name: Smooth subdivide
Command: MeshModifiers.Smoothdivide('');
RClick: 



Name: Subdivide
Command: MeshModifiers.Subdivide('');
RClick: 



Name: Add loop
Command: MeshModifiers.TogglePeTool('/Widgets/Tools/PE Add loop','');
RClick: 



Name: Normal sweep 
Command: MeshModifiers.TogglePeTool('/Widgets/Tools/PE Sweep','');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/PE Sweep/Sweep',3,1,0);



Name: Normal sweep 
Command: MeshModifiers.TogglePeTool('/Widgets/Tools/PE Sweep','');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/PE Sweep/Sweep',3,1,0);



Name: Sweep
Command: MeshModifiers.ExtrudeSelection('')
RClick: 



Name: Tip selection
Command: MeshModifiers.TipSelection('');
RClick: 



Name: Bevel tool
Command: MeshModifiers.TogglePeTool('/Widgets/Tools/PE Bevel','');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/PE Bevel/Bevel tool',3,1,0);



Name: Polydraw
Command: MeshModifiers.ActivatePointEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/PE Poly draw','Default')
RClick: 



Name: Polydraw
Command: MeshModifiers.ActivatePointEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/PE Poly draw','Default')
RClick: 



Name: Add edges
Command: MeshModifiers.ActivatePointEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/PE Edge draw','Default')
RClick: 



Name: Add vertices
Command: MeshModifiers.ActivatePointEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/PE Vertex draw','Default')
RClick: 



Name: MirrorModeler
Command: MeshModifiers.AddMirrorModeler('');
RClick: MeshModifiers.ShowMirrorProperties('');



Name: MirrorModeler
Command: MeshModifiers.AddMirrorModeler('');
RClick: MeshModifiers.ShowMirrorProperties('');



Name: Copy 
Command: MeshModifiers.DuplicateSelection('');
RClick: 



Name: Mirror
Command: MeshModifiers.MirrorSelection('');
RClick: 



Name: MirrorModeler
Command: MeshModifiers.AddMirrorModeler('');
RClick: MeshModifiers.ShowMirrorProperties('');



Name: Raycast Selection
Command: Node.Value('/Preferences/Modeling preferences','PE selection style') = 'visible'
RClick: 



Name: Raycast Selection
Command: Node.Value('/Preferences/Modeling preferences','PE selection style') = 'visible'
RClick: 



Name: All selection
Command: Node.Value('/Preferences/Modeling preferences','PE selection style') = 'all'
RClick: 



Name: Flip
Command: MeshModifiers.FlipFacesNormals('');
RClick: 



Name: Flip
Command: MeshModifiers.FlipFacesNormals('');
RClick: 



Name: Delete
Command: MeshModifiers.DeleteElements('');
RClick: 



Name: Form face
Command: MeshModifiers.AddFace('');
RClick: 



Name: Split polygons
Command: MeshModifiers.SplitPolygons('');
RClick: 



Name: Merge polygons
Command: MeshModifiers.MergePolygons('');
RClick: 



Name: Scissors
Command: MeshModifiers.Scissors('');
RClick: 



Name: Split polygons
Command: MeshModifiers.SplitPolygons('');
RClick: 



Name: Add SS
Command: MeshModifiers.ChangeSSLevel(1)
RClick: 



Name: Normalmap
Command: MeshModifiers.BuildNormalmap('')
RClick: 



Name: Normalmap
Command: MeshModifiers.BuildNormalmap('')
RClick: 



Name: Lod
Command: MeshModifiers.SimplifyMesh('')
RClick: 



Name: Location
Command: RsTool.NormalizeLocation('');
RClick: 



Name: Location
Command: RsTool.NormalizeLocation('');
RClick: 



Name: Scale
Command: RsTool.NormalizeSize('');
RClick: 



Name: Rotation
Command: RsTool.NormalizeRotation('');
RClick: 



Name: ResetAxes
Command: RsTool.ResetAxes('');
RClick: 



Name: ShowAxes
Command: RsTool.ShowAxes('');
RClick: 



Name: Look At
Command: ToolMng.ActivateTool('{17D544A3-3F58-436B-83E7-F8B4D7D4E7C5}','{4E203C6C-A20D-4e32-82B4-FC482F5A0D06}' )
RClick: 



Name: Add SS
Command: MeshModifiers.ChangeSSLevel(1)
RClick: 



Name: Edge weights
Command: Widgets.ReplaceWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/PE edge weight','Default','','')
RClick: 



Name: Vertex weight
Command: Widgets.ReplaceWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/PE vertex weight','Default','','')
RClick: 



Name: Remove SS
Command: MeshModifiers.ChangeSSLevel(-1)
RClick: 



Name: Add SS
Command: MeshModifiers.ChangeSSLevel(1)
RClick: 



Name: Shut Down
Command: RsApp.ShutDown()
RClick: 



Name: Shut Down
Command: RsApp.ShutDown()
RClick: 



Name: Stop activities
Command: Activity.KillAll()
RClick: 



Name: Default context backup
Command: RsFileIO.SaveSystem('', '', 'Manually saved system', 0)
RClick: 



Name: Material Editor
Command: PhotoMaterialEditor.OpenMaterialEditor()
RClick: 



Name: Pick Mat
Command: D3DView.ToggleMaterialPick(-1)
RClick: 



Name: File Render
Command: D3DView.RenderToFile('', '')
RClick: 



Name: HW settings
Command: D3DView.ShowSettingsDialog()
RClick: 



Name: Manual
Command: tSBridge.SuggestTSStateByAlias("SV_HELP_HELP_PDF_MANUAL")
RClick: 



Name: Export to VE 
Command: RsImport.OpenVECollectionPanel();
RClick: 



Name: File Render
Command: D3DView.RenderToFile('', '')
RClick: 



Name: Record Toolbar
Command: WindowsManager.OpenToolbarFromPrototype('Record3D', 100, 300,-1,-1)
RClick: RsRec.OpenRecPreferences()



Name: Record Toolbar
Command: WindowsManager.OpenToolbarFromPrototype('Record3D', 100, 300,-1,-1)
RClick: RsRec.OpenRecPreferences()



Name: jScript Macro Record Toolbar
Command: WindowsManager.OpenToolbarFromPrototype('MacroRecordjS', 100, 360,-1,-1)
RClick: 



Name: VBScript Macro Record Toolbar
Command: WindowsManager.OpenToolbarFromPrototype('MacroRecordVB', 100, 360,-1,-1)
RClick: 



Name: Library browser
Command: Library2.ShowLibraryBrowserWindow()
RClick: 



Name: Shared Space
Command: Net.NtOpenView
RClick: 



Name: 3D Window
Command: WindowsManager.CreateWindowFromCLSIDEx('default', 'default', 'default', '[Scene]', 1, '3D')
RClick: 



Name: Copy Window
Command: WindowsManager.CopyWindow('')
RClick: 



Name: LE Window
Command: WindowsManager.CreateWindowFromCLSIDEx('default', 'default', 'default', '[Scene]', 1, '2D')
RClick: 



Name: Command Prompt
Command: CmdPrompt.OpenWindow('Windows Manager Space', 0)
RClick: 



Name: Output Console
Command: CmdPrompt.DebugView('Windows Manager Space', 0)
RClick: 



Name: Command history
Command: CmdPrompt.StackView('Windows Manager Space', 0)
RClick: 



Name: Status view
Command: RsTool.OpenStatusBar();
RClick: 



Name: Stack View
Command: WindowsManager.OpenHistoryWindow()
RClick: 



Name: Anim View
Command: WindowsManager.CreateWindowFromCLSIDEx('default', 'default', 'default', '[Scene]', 1, '4D')
RClick: 



Name: Package Manager
Command: WindowsManager.CreateWindowFromCLSID('{3011C160-2294-48d9-AE95-BD144574FB99}', '', '', '', 1)
RClick: 



Name: Scene View
Command: CmdPrompt.SceneViewCreate();
RClick: 



Name: 3D Window
Command: WindowsManager.CreateWindowFromCLSIDEx('default', 'default', 'default', '[Scene]', 1, '3D')
RClick: 



Name: Smooth
Command: MeshModifiers.SmoothPointEditSelection('');
RClick: 



Name: FaceLoops
Command: Node.Value('/Preferences/Mesh Editor Settings','PE selection mode') = 'face loop'; MeshModifiers.ActivatePointEditWidget('','','Default');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Modeling preferences',4,1,1);



Name: SelectAll
Command: Node.Value('/Preferences/Mesh Editor Settings','PE selection style') = 0;
RClick: 



Name: Outline
Command: MeshModifiers.OutlinePointEditSelection('');
RClick: 



Name: Unselect
Command: MeshModifiers.PeDeselect('');
RClick: 



Name: Paint
Command: MeshModifiers.ActivatePointEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Mesh editor/PE basic select','Default'); Node.Value('/Preferences/Mesh Editor Settings','PE selection tool') = '/Widgets/Tools/Mesh editor/PE basic select';
RClick: 



Name: Rectangle
Command: MeshModifiers.ActivatePointEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Mesh editor/PE rect select','Default'); Node.Value('/Preferences/Mesh Editor Settings','PE selection tool') = '/Widgets/Tools/Mesh editor/PE rect select';UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE rect select/Rect select',3,1,0,2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE rect select/Rect select',3,1,0,2);



Name: Lasso
Command: MeshModifiers.ActivatePointEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Mesh editor/PE lasso select','Default'); Node.Value('/Preferences/Mesh Editor Settings','PE selection tool') = '/Widgets/Tools/Mesh editor/PE lasso select';UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE lasso select/Lasso select',3,1,0,2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE lasso select/Lasso select',3,1,0,2);



Name: Context
Command: Node.Value('/Preferences/Mesh Editor Settings','PE selection mode') = 'context'; MeshModifiers.ActivatePointEditWidget('','','Default');
RClick: 



Name: DynaPick
Command: MeshModifiers.ActivatePointEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Mesh editor/PE dynapick','Default'); Node.Value('/Preferences/Mesh Editor Settings','PE selection tool') = '/Widgets/Tools/Mesh editor/PE dynapick';
RClick: 



Name: Shrink
Command: MeshModifiers.ShrinkPointEditSelection('');MeshModifiers.ConvertSelection('','');
RClick: 



Name: Soft
Command: MeshModifiers.ActivatePointEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Mesh editor/PE soft select','Default'); Node.Value('/Preferences/Mesh Editor Settings','PE selection tool') = '/Widgets/Tools/Mesh editor/PE soft select';UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE soft select/Soft select',3,1,0,2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE soft select/Soft select',3,1,0,2);



Name: Edges
Command: Node.Value('/Preferences/Mesh Editor Settings','PE selection mode') = 'face edge'; MeshModifiers.ActivatePointEditWidget('','','Default');
RClick: 



Name: TriEdges
Command: Node.Value('/Preferences/Mesh Editor Settings','PE selection mode') = 'triangle edge'; MeshModifiers.ActivatePointEditWidget('','','Default');
RClick: 



Name: Faces
Command: Node.Value('/Preferences/Mesh Editor Settings','PE selection mode') = 'face'; MeshModifiers.ActivatePointEditWidget('','','Default');
RClick: 



Name: Materials
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Select tool','apply_cmd:{7BFCBE4C-E2C4-46d6-9A2D-4498053527EC}');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Mesh Editor Settings',9,0,0);



Name: Path
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Select tool','apply_cmd:{7DBD4078-6AC7-48f4-A52D-C4A65CAB0C51};select_invselect');
RClick: 



Name: EdgeLoops
Command: Node.Value('/Preferences/Mesh Editor Settings','PE selection mode') = 'edge loop'; MeshModifiers.ActivatePointEditWidget('','','Default');
RClick: 



Name: Selected
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Rect tool','apply_cmd:{908A59AA-0921-4e53-82EA-0F427904F48E}');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/PE Rect tool/Rect select tool',3,0,0);



Name: Visible
Command: Node.Value('/Preferences/Mesh Editor Settings','PE selection style') = 1;
RClick: 



Name: UV Editor 
Command: UVEditor.Open('%THIS_BUTTON_ITEM%')
RClick: UserInterface.OpenToolPanelViewEx2('', '','Preferences/UV Editor Preferences',3, 1, 0)



Name: Hide
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Rect tool','apply_cmd:{70902786-9BA6-4233-975B-342BA6A274E7}');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/PE Rect tool/Rect select tool',3,0,0);



Name: Vertices
Command: Node.Value('/Preferences/Mesh Editor Settings','PE selection mode') = 'vertex'; MeshModifiers.ActivatePointEditWidget('','','Default');
RClick: 



Name: TriFaces
Command: Node.Value('/Preferences/Mesh Editor Settings','PE selection mode') = 'triangle'; MeshModifiers.ActivatePointEditWidget('','','Default');
RClick: 



Name: Connected
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Select tool','apply_cmd:{0502CC2A-7F8C-4d29-BBB4-9F1F2ECDC84C}');
RClick: 



Name: Unhide
Command: MeshModifiers.ShowHiddenPeGeometry('');
RClick: 



Name: Invert
Command: MeshModifiers.InvertSelection('');
RClick: 



Name: Grow
Command: MeshModifiers.GrowPointEditSelection('');MeshModifiers.ConvertSelection('','');
RClick: 



Name: Convert
Command: MeshModifiers.ConvertSelection('','');
RClick: 



Name: Spherical
Command: UVEditor.ToggleUvProjection('Spherical','')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/UV mapping/Projection tool/UV Projection tool',3,0,0);



Name: Spherical
Command: UVEditor.ToggleUvProjection('Spherical','')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/UV mapping/Projection tool/UV Projection tool',3,0,0);



Name: Planar
Command: UVEditor.ToggleUvProjection('Planar','')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/UV mapping/Projection tool/UV Projection tool',3,0,0);



Name: Cylindrical
Command: UVEditor.ToggleUvProjection('Cylindrical','')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/UV mapping/Projection tool/UV Projection tool',3,0,0);



Name: Cubic
Command: UVEditor.ToggleUvProjection('Cubic','')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/UV mapping/Projection tool/UV Projection tool',3,0,0);



Name: ShrinkUV
Command: MeshModifiers.ShrinkWrap('')
RClick: UserInterface.OpenToolPanelViewEx2('', '','Preferences/Shrink Wrap preferences',3, 1, 0);



Name: DynaSweep
Command: MeshModifiers.TogglePeTool('/Widgets/Tools/Mesh editor/PE Sweep',''); UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE Sweep/Dynamic Sweep',3,1, 0, 2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE Sweep/Dynamic Sweep',3,1,0,2);



Name: AddLoop
Command: MeshModifiers.TogglePeTool('/Widgets/Tools/Mesh editor/PE Add loop',''); UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE Add loop/Add loop',3,1, 0, 2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE Add loop/Add loop',3,1, 0, 2);



Name: Tip
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Select tool','apply_cmd:{D836AAE0-6E0C-48d9-95DC-8FDA120A29DF}');
RClick: 



Name: Flip
Command: MeshModifiers.FlipFacesNormals('');
RClick: 



Name: Length
Command: MeshModifiers.EnableHairBrush('{A7782DD7-DD86-4cbe-A562-E345805E59AB}');UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Hair/Hair Length Brush/Hair Length',3,1,0,2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Hair/Hair Length Brush/Hair Length',3,1,0,2);



Name: Length
Command: MeshModifiers.EnableHairBrush('{A7782DD7-DD86-4cbe-A562-E345805E59AB}');UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Hair/Hair Length Brush/Hair Length',3,1,0,2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Hair/Hair Length Brush/Hair Length',3,1,0,2);



Name: Blowdryer
Command: MeshModifiers.EnableHairBrush('{24C5D7C9-0A06-40f5-95F3-7BE7DC4177F8}');UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Hair/Hair Blowdryer/Hair Blowdryer',3,1,0,2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Hair/Hair Blowdryer/Hair Blowdryer',3,1,0,2);



Name: Softness
Command: MeshModifiers.EnableHairBrush('{A8A8F8B0-993C-4cd0-82AE-18B39BDA000F}');UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Hair/Hair Softness Brush/Hair Softness',3,1,0,2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Hair/Hair Softness Brush/Hair Softness',3,1,0,2);



Name: Direction
Command: MeshModifiers.EnableHairBrush('{CA36494D-CC50-436b-B5B3-4F16FB8422C9}');UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Hair/Hair Direction Brush/Hair Direction',3,1,0,2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Hair/Hair Direction Brush/Hair Direction',3,1,0,2);



Name: Density
Command: MeshModifiers.EnableHairBrush('{7DB4D6AE-8BFA-41dc-A9F7-4BB7916FD6D7}');UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Hair/Hair Density Brush/Hair Density',3,1,0,2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Hair/Hair Density Brush/Hair Density',3,1,0,2);



Name: Normalmap
Command: MeshModifiers.BuildNormalmap('')
RClick: 



Name: Normalmap
Command: MeshModifiers.BuildNormalmap('')
RClick: 



Name: Simplify
Command: MeshModifiers.SimplifyMesh('')
RClick: 



Name: Scissors
Command: MeshModifiers.Scissors('');
RClick: 



Name: FormFace
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Select tool','apply_cmd:{7032EC04-4E22-4e94-8E88-1F0143DCEE33};select_mode:hole');
RClick: 



Name: Split
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Select tool','apply_cmd:{0A28658A-C334-4199-9C30-EB833B77A908}');
RClick: 



Name: Merge
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Select tool','apply_cmd:{3E45513F-2866-457f-82EA-EE9FAC8BD84E}');
RClick: 



Name: Bridge
Command: MeshModifiers.ActivatePointEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Mesh editor/PE bridge tool','Default'); UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/PE bridge tool/Bridge tool',3,1,1);
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/PE bridge tool/Bridge tool',3,1,1);



Name: Delete
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Select tool','apply_cmd:{8982C2F3-3070-40e5-9967-E44CFFD1763E}');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Mesh Editor Settings',8,0,0);



Name: Bevel
Command: MeshModifiers.TogglePeTool('/Widgets/Tools/Mesh editor/PE Bevel',''); UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE Bevel/Bevel tool',3,1,0, 2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE Bevel/Bevel tool',3,1,0, 2);



Name: Quad
Command: MeshModifiers.Subdivide('');
RClick: 



Name: Collapse
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Select tool','apply_cmd:{E80D376F-7073-4186-88D1-3DA687A13E79}');
RClick: 



Name: Weld
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Rect tool','apply_cmd:{87B113FD-B879-4b63-9C9A-28A38AED253B}');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/PE Rect tool/Rect select tool',3,0,0);



Name: SwapEdge
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Select tool','apply_cmd:{09B80301-7C86-4100-824A-C4148A696F1B};select_mode:triangle edge');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Mesh Editor Settings',8,0,0);



Name: Smooth
Command: MeshModifiers.Smoothdivide('');
RClick: 



Name: Quadrify
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Select tool','apply_cmd:{3C2CB50B-42E0-47ef-B9A8-A75E6CBCA9F0};select_mode:face');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Mesh Editor Settings',8,0,0);



Name: Optimize
Command: MeshModifiers.OptimizeTriangulation('');
RClick: 



Name: Heal
Command: MeshModifiers.HealVertices('',-1);
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Mesh Editor Settings',6,0,0);



Name: Modeler
Command: MeshModifiers.AddMirrorModeler('');
RClick: MeshModifiers.ShowMirrorProperties('');



Name: Modeler
Command: MeshModifiers.AddMirrorModeler('');
RClick: MeshModifiers.ShowMirrorProperties('');



Name: Mirror
Command: MeshModifiers.MirrorSelection('');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Mesh Editor Settings',7,0,0);



Name: Copy
Command: MeshModifiers.DuplicateSelection('');
RClick: 



Name: Separate
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Select tool','apply_cmd:{6D90C46D-A984-47fa-8C14-C7ADF45DD882}');
RClick: 



Name: Polydraw
Command: MeshModifiers.ActivatePointEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Mesh editor/PE Poly draw','Default')
RClick: 



Name: Polydraw
Command: MeshModifiers.ActivatePointEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Mesh editor/PE Poly draw','Default')
RClick: 



Name: AddEdges
Command: MeshModifiers.ActivatePointEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Mesh editor/PE Edge draw','Default')
RClick: 



Name: AddVertices
Command: MeshModifiers.ActivatePointEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Mesh editor/PE Vertex draw','Default')
RClick: 



Name: Union
Command: MeshModifiers.ActivateBooleansTool('Union','')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/Booleans tool/Booleans',3,1,0);



Name: Union
Command: MeshModifiers.ActivateBooleansTool('Union','')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/Booleans tool/Booleans',3,1,0);



Name: Intersection
Command: MeshModifiers.ActivateBooleansTool('Intersection','')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/Booleans tool/Booleans',3,1,0);



Name: Subtract
Command: MeshModifiers.ActivateBooleansTool('Subtraction','')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/Booleans tool/Booleans',3,1,0);



Name: Cut
Command: MeshModifiers.ActivateBooleansTool('Cut','')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/Booleans tool/Booleans',3,1,0);



Name: Merge
Command: MeshModifiers.ActivateBooleansTool('Merge','')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/Booleans tool/Booleans',3,1,0);



Name: Merge
Command: MeshModifiers.ActivateBooleansTool('Merge','')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/Booleans tool/Booleans',3,1,0);



Name: Add
Command: MeshModifiers.ActivateBooleansTool('Add','')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/Booleans tool/Booleans',3,1,0);



Name: Soft paint
Command: MeshModifiers.TogglePeTool('/Widgets/Tools/Mesh editor/PE soft paint','');UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/PE soft paint/Soft paint',3,1,0);
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/PE soft paint/Soft paint',3,1,0);



Name: Soft paint
Command: MeshModifiers.TogglePeTool('/Widgets/Tools/Mesh editor/PE soft paint','');UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/PE soft paint/Soft paint',3,1,0);
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/PE soft paint/Soft paint',3,1,0);



Name: DisMap
Command: MeshModifiers.DisplacementMapping('');
RClick: 



Name: DisBrush
Command: MeshModifiers.EnableDisplacementBrush();UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/DM Brush/Displacement Brush',4,1,0,2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/DM Brush/Displacement Brush',4,1,0,2);



Name: + SDS
Command: MeshModifiers.ChangeSSLevel(1)
RClick: 



Name: + SDS
Command: MeshModifiers.ChangeSSLevel(1)
RClick: 



Name: - SDS
Command: MeshModifiers.ChangeSSLevel(-1)
RClick: 



Name: ResetSDS
Command: MeshModifiers.ResetSds('',-1,-1,-1)
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Mesh Editor Settings',10,0,0);



Name: SDSVertex
Command: Widgets.ReplaceWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Mesh editor/PE vertex weight','Default','','')
RClick: 



Name: SDSEdge
Command: Widgets.ReplaceWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Mesh editor/PE edge weight','Default','','')
RClick: 



Name: Sweep
Command: MeshModifiers.ExtrudeSelection('')
RClick: 



Name: Skeleton
Command: CharacterEditor.ActivateCharacterToolEx('/Widgets/Tools/Character editor/Skeleton tool','Default','{62E8596C-448F-4967-A317-516B044E80FB}{70F07F89-0410-41c4-803C-64C712261727}{/Preferences/Character editor preferences}','/Preferences/Character editor preferences/Joint marker');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Character editor preferences',6,1,1);



Name: Limits
Command: CharacterEditor.ActivateCharacterTool('/Widgets/Edit/Joint limits');
RClick: CharacterEditor.EditJointsDirectly('');



Name: Envelope
Command: CharacterEditor.ActivateCharacterTool('/Widgets/Tools/Character editor/CE bone envelope tool');
RClick: 



Name: DelJoint
Command: CharacterEditor.RemoveJoint('');
RClick: 



Name: -Limb
Command: CharacterEditor.RemoveLimb('');
RClick: 



Name: Skin2Bone
Command: CharacterEditor.ActivateCharacterTool('/Widgets/Tools/Character editor/Attach objects as a skin');
RClick: 



Name: Object2Bone
Command: CharacterEditor.ActivateCharacterTool('/Widgets/Tools/Character editor/Attach objects to bone');
RClick: 



Name: SetPose
Command: SK = Node.SubObject(Node.FirstSelected(), 0);if (Node.ConExists(Node.FirstSelected() + "/" + SK, "Default pose")){Yes = System.Question("Default Pose is already Set for your Character!   Are you sure you want to Set it again?");if(Yes==1){CharacterEditor.SetDefaultPose('');CharacterEditor.SetDefaultPose('');}}else {if (Node.ConExists(Node.FirstSelected(), "Default pose")){Yes = System.Question("Default Pose is already Set for your Skeleton!   Are you sure you want to Set it again?");if(Yes==1){CharacterEditor.SetDefaultPose('');CharacterEditor.SetDefaultPose('');}}else if (!Node.ConExists(Node.FirstSelected() + "/" + SK, "Default pose"))CharacterEditor.SetDefaultPose('');else if (!Node.ConExists(Node.FirstSelected(), "Default pose"))CharacterEditor.SetDefaultPose('');}
RClick: 



Name: ResetPose
Command: CharacterEditor.ResetPose('');
RClick: 



Name: Rot.Lock
Command: CharacterEditor.ActivateCharacterToolEx('/Widgets/Tools/Character editor/Edit IK lock','Default','iklockrot.rsobj','%SKELETON%');
RClick: 



Name: Skin2Skeleton
Command: CharacterEditor.ActivateCharacterTool('/Widgets/Tools/Character editor/Attach skin to skeleton'); UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Character editor/Attach skin to skeleton/Attach skin to skeleton',3,1,1, 2); 
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Character editor/Attach skin to skeleton/Attach skin to skeleton',3,1,1, 2);



Name: Weight
Command: CharacterEditor.ActivateEditModeTool('/Widgets/Edit/Helpers/CE Weight paint','/Widgets/Tools/Character editor/CE Weight paint tool','&pref:/Widgets/Tools/Character editor/CE Weight paint tool/Weight paint&tag:brush');
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Character editor/CE Weight paint tool/Weight paint',3,1,1, 2);



Name: HealSkin
Command: CharacterEditor.HealSkin('');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Character editor preferences',7,1,1);



Name: Pos.Lock
Command: CharacterEditor.ActivateCharacterToolEx('/Widgets/Tools/Character editor/Edit IK lock','Default','iklockpos.rsobj','%SKELETON%');
RClick: 



Name: ShapeSkel
Command: CharacterEditor.ActivateCharacterTool('/Widgets/Edit/Character editor widget');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Character editor preferences',3, 1, 1);



Name: Sel2Skin
Command: CharacterEditor.SelectionToSkin('');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Character editor preferences',8,1,1);



Name: Transfer
Command: CharacterEditor.ActivateEditModeTool('/Widgets/Edit/Helpers/CE Weight paint','/Widgets/Tools/Character editor/Skin transfer','&pref:/Widgets/Tools/Character editor/Skin transfer/Skin transfer&tag:transfer'); 
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Character editor/Skin transfer/Skin transfer',3,1,1, 2); 



Name: Sel2Skin
Command: CharacterEditor.SelectionToSkin('');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Character editor preferences',8,1,1);



Name: +Morph
Command: CharacterEditor.AddMorph('');
RClick: CharacterEditor.ShowMorphPanel('');



Name: ModIkHndl
Command: CharacterEditor.ActivateCharacterToolEx('/Widgets/Tools/Character editor/Edit Ik Motion Ctrl','Default','ikmchandle.rsobj','%SKELETON%');
RClick: 



Name: Skin2Sel
Command: CharacterEditor.SkinToSelection('');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Mesh Editor Settings',3,1,1);



Name: AlignHndl
Command: CharacterEditor.ActivateCharacterTool('/Widgets/Tools/Character editor/IK handle align');
RClick: 



Name: FullLock
Command: CharacterEditor.ActivateCharacterToolEx('/Widgets/Tools/Character editor/Edit IK lock','Default','iklockfull.rsobj','%SKELETON%');
RClick: 



Name: +PhysAttr
Command: Physics.AddPhysAttr('');Physics.OpenNodePanel('phys', 3)
RClick: Physics.OpenNodePanel('phys', 3)



Name: Rotation
Command: Physics.ActivatePhysWidget('RotationWidget')
RClick: Physics.OpenNodePanel('phys', 4)



Name: COG
Command: Physics.ActivatePhysWidget('CogWidget')
RClick: Physics.OpenNodePanel('phys', 7)



Name: FixPoint1
Command: Physics.ActivatePhysWidget('Fix1Widget')
RClick: Physics.OpenNodePanel('phys', 7)



Name: ClothFix
Command: Physics.ActivatePhysWidget('ClothFixWidget')
RClick: Physics.ActivatePhysWidget('ClothFixWidget');Physics.ResetClothFixation('')



Name: WindLocal
Command: Physics.AddWind('', true)
RClick: 



Name: WindGlobal
Command: Physics.AddWind('', false)
RClick: 



Name: EnviLocal
Command: Physics.ActivatePhysWidget('LocEnvWidget')
RClick: Physics.OpenNodePanel('env', 3)



Name: Gravity
Command: Physics.ActivatePhysWidget('GravityWidget')
RClick: Physics.OpenNodePanel('space', 3)



Name: -PhysAttr
Command: Physics.RemovePhysAttr('')
RClick: 



Name: Speed
Command: Physics.ActivatePhysWidget('SpeedWidget')
RClick: Physics.OpenNodePanel('phys', 4)



Name: +LocalEnv
Command: Physics.AddEnvAttr('');Physics.OpenNodePanel('phys', 3)
RClick: Physics.OpenNodePanel('env', 3)



Name: -LocalEnv
Command: Physics.RemoveEnvAttr('')
RClick: 



Name: -ClothAttr
Command: Physics.RemoveClothAttr('')
RClick: 



Name: +ClothAttr
Command: Physics.AddClothAttr('');Physics.OpenNodePanel('phys', 3)
RClick: Physics.OpenNodePanel('cloth', 3)



Name: A.Rotation
Command: Physics.ActivatePhysWidget('RotAccWidget')
RClick: Physics.OpenNodePanel('phys', 5)



Name: A.Speed
Command: Physics.ActivatePhysWidget('AccWidget')
RClick: Physics.OpenNodePanel('phys', 5)



Name: FixPoint2
Command: Physics.ActivatePhysWidget('Fix2Widget')
RClick: Physics.OpenNodePanel('phys', 7)



Name: New scene
Command: Space.NewScene()
RClick: LE.OpenLocation(Space.CurrentScene())



Name: New scene
Command: Space.NewScene()
RClick: LE.OpenLocation(Space.CurrentScene())



Name: Reset Default
Command: var Yes = System.Question("Would you like to Reset the Default Context?");if (Yes){RsApp.Reset();}else;
RClick: 



Name: Default context backup
Command: RsFileIO.SaveSystem('', '', 'Manually saved system', 0)
RClick: 



Name: Reset Default
Command: var Yes = System.Question("Would you like to Reset the Default Context?");if (Yes){RsApp.Reset();}else;
RClick: 



Name: Object
Command: RsTool.Arrow();Space.Unselect()
RClick: RsTool.OpenInfoPanel();



Name: Object
Command: RsTool.Arrow();Space.Unselect()
RClick: RsTool.OpenInfoPanel();



Name: Location
Command: RsTool.NormalizeLocation('');
RClick: 



Name: Scale
Command: RsTool.NormalizeSize('');
RClick: 



Name: Rotation
Command: RsTool.NormalizeRotation('');
RClick: 



Name: Reset
Command: RsTool.ResetAxes('');
RClick: 



Name: Axis
Command: RsTool.ShowAxes('');
RClick: RsTool.ToggleValue("/Widgets/Tools/Axes widget/Default/In front");



Name: Flatten
Command: MeshModifiers.FlattenAxes('');
RClick: 



Name: Cube
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Primitive tool','{EEC8FEE8-EB12-4e12-8ED0-D71CAA2886FD}(/Preferences/Primitives/Matrix manager){C89E0C6B-3F82-4fe2-A232-FB1A7B7F6190}(/Preferences/Primitives/Factory preferences){/Preferences/Primitives/Preferences}','/Preferences/Primitives/Cube');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Primitives',10,1,1);



Name: Cube
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Primitive tool','{EEC8FEE8-EB12-4e12-8ED0-D71CAA2886FD}(/Preferences/Primitives/Matrix manager){C89E0C6B-3F82-4fe2-A232-FB1A7B7F6190}(/Preferences/Primitives/Factory preferences){/Preferences/Primitives/Preferences}','/Preferences/Primitives/Cube');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Primitives',10,1,1);



Name: Sphere
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Primitive tool','{5DB1D6C0-877C-4a84-8FF1-B5AB4E34519D}(/Preferences/Primitives/Rotation manager){C89E0C6B-3F82-4fe2-A232-FB1A7B7F6190}(/Preferences/Primitives/Factory preferences){/Preferences/Primitives/Preferences}','/Preferences/Primitives/Sphere');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Primitives',8,1,1);



Name: Cylinder
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Primitive tool','{A955CABA-CA6F-40c0-AE78-010D283ED1C5}(/Preferences/Primitives/Rotation manager){C89E0C6B-3F82-4fe2-A232-FB1A7B7F6190}(/Preferences/Primitives/Factory preferences){/Preferences/Primitives/Preferences}','/Preferences/Primitives/Cylinder');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Primitives',6,1,1);



Name: Torus
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Primitive tool','{A955CABA-CA6F-40c0-AE78-010D283ED1C5}(/Preferences/Primitives/Rotation manager){C89E0C6B-3F82-4fe2-A232-FB1A7B7F6190}(/Preferences/Primitives/Factory preferences){/Preferences/Primitives/Preferences}','/Preferences/Primitives/Torus');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Primitives',9,1,1);



Name: Plane
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Primitive tool','{1ABE09E8-F22F-46b3-9F8A-7F08B0FFF297}(/Preferences/Primitives/Matrix manager){C89E0C6B-3F82-4fe2-A232-FB1A7B7F6190}(/Preferences/Primitives/Factory preferences){/Preferences/Primitives/Preferences}','/Preferences/Primitives/Plane');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Primitives',12,1,1);



Name: Cone
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Primitive tool','{A955CABA-CA6F-40c0-AE78-010D283ED1C5}(/Preferences/Primitives/Rotation manager){C89E0C6B-3F82-4fe2-A232-FB1A7B7F6190}(/Preferences/Primitives/Factory preferences){/Preferences/Primitives/Preferences}','/Preferences/Primitives/Cone');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Primitives',11,1,1);



Name: Text
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Primitive tool','{0422ED97-497D-4623-A209-ABC4335F0380}{C89E0C6B-3F82-4fe2-A232-FB1A7B7F6190}(/Preferences/Primitives/Factory preferences){/Preferences/Primitives/Preferences}','/Preferences/Primitives/Text');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Primitives',4,1,1);



Name: Camera
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Primitive tool','{B1D12AD1-47D4-4e6c-8227-DC80FF55D7BB}{A46795D3-0DE2-4ed8-9FB6-91D84FB9F1EB}(/Preferences/Cameras/Factory preferences){/Preferences/Lights/Preferences}','/Preferences/Cameras/Camera');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Cameras',3,1,1);



Name: EntryPoint
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Primitive tool','{B1D12AD1-47D4-4e6c-8227-DC80FF55D7BB}{A46795D3-0DE2-4ed8-9FB6-91D84FB9F1EB}(/Preferences/Cameras/Factory preferences){/Preferences/Lights/Preferences}','/Preferences/Cameras/EntryPoint');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Cameras',3,1,1);



Name: Spot
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Light tool','{B1D12AD1-47D4-4e6c-8227-DC80FF55D7BB}{A46795D3-0DE2-4ed8-9FB6-91D84FB9F1EB}(/Preferences/Lights/Factory preferences){/Preferences/Lights/Preferences}','/Preferences/Lights/Spot');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Lights',3,1,1);



Name: Omni
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Light tool','{B1D12AD1-47D4-4e6c-8227-DC80FF55D7BB}{A46795D3-0DE2-4ed8-9FB6-91D84FB9F1EB}(/Preferences/Lights/Factory preferences){/Preferences/Lights/Preferences}','/Preferences/Lights/Omni');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Lights',3,1,1);



Name: Infinite
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Light tool','{B1D12AD1-47D4-4e6c-8227-DC80FF55D7BB}{A46795D3-0DE2-4ed8-9FB6-91D84FB9F1EB}(/Preferences/Lights/Factory preferences){/Preferences/Lights/Preferences}','/Preferences/Lights/Infinite');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Lights',3,1,1);



Name: Projector
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Light tool','{B1D12AD1-47D4-4e6c-8227-DC80FF55D7BB}{A46795D3-0DE2-4ed8-9FB6-91D84FB9F1EB}(/Preferences/Lights/Factory preferences){/Preferences/Lights/Preferences}','/Preferences/Lights/Projector');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Lights',3,1,1);



Name: Sky
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Light tool','{B1D12AD1-47D4-4e6c-8227-DC80FF55D7BB}{A46795D3-0DE2-4ed8-9FB6-91D84FB9F1EB}(/Preferences/Lights/Factory preferences){/Preferences/Lights/Preferences}','/Preferences/Lights/Sky');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Lights',3,1,1);



Name: Directional
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Light tool','{B1D12AD1-47D4-4e6c-8227-DC80FF55D7BB}{A46795D3-0DE2-4ed8-9FB6-91D84FB9F1EB}(/Preferences/Lights/Factory preferences){/Preferences/Lights/Preferences}','/Preferences/Lights/Directional');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Lights',3,1,1);



Name: Ambient
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Light tool','{B1D12AD1-47D4-4e6c-8227-DC80FF55D7BB}{A46795D3-0DE2-4ed8-9FB6-91D84FB9F1EB}(/Preferences/Lights/Factory preferences){/Preferences/Lights/Preferences}','/Preferences/Lights/Ambient');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Lights',3,1,1);



Name: Area
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Light tool','{B1D12AD1-47D4-4e6c-8227-DC80FF55D7BB}{A46795D3-0DE2-4ed8-9FB6-91D84FB9F1EB}(/Preferences/Lights/Factory preferences){/Preferences/Lights/Preferences}','/Preferences/Lights/Area');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Lights',3,1,1);



Name: Spot
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Light tool','{B1D12AD1-47D4-4e6c-8227-DC80FF55D7BB}{A46795D3-0DE2-4ed8-9FB6-91D84FB9F1EB}(/Preferences/Lights/Factory preferences){/Preferences/Lights/Preferences}','/Preferences/Lights/Spot');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Lights',3,1,1);



Name: 3D Encapsulate
Command: LE.RectEncapsulationDialog('{5B3DD4D4-BD80-480A-BFD8-0B3A19DF1558}', true)
RClick: 



Name: 3D Encapsulate
Command: LE.RectEncapsulationDialog('{5B3DD4D4-BD80-480A-BFD8-0B3A19DF1558}', true)
RClick: 



Name: Encapsulate
Command: LE.RectEncapsulationDialog('{5B3DD4D4-BD80-480A-BFD8-0B3A19DF1558}', false)
RClick: 



Name: Flatten
Command: MeshModifiers.FlattenNodes('')
RClick: 



Name: 3D Encapsulate
Command: LE.RectEncapsulationDialog('{5B3DD4D4-BD80-480A-BFD8-0B3A19DF1558}', true)
RClick: 



Name: 3D Encapsulate
Command: Activity.Run("/Scripts/Commands/Unglue");
RClick: 



Name: 3D Encapsulate
Command: LE.RectEncapsulationDialog('{5B3DD4D4-BD80-480A-BFD8-0B3A19DF1558}', true)
RClick: 



Name: Unencaps
Command: LE.Unencapsulate('')
RClick: 



Name: Undo
Command: RsApp.Undo()
RClick: 



Name: Undo
Command: RsApp.Undo()
RClick: 



Name: Redo
Command: RsApp.Redo()
RClick: 



Name: World
Command: Node.Value('/Preferences/Modeling preferences','Coordinate system') = 'World';
RClick: 



Name: Object
Command: Node.Value('/Preferences/Modeling preferences','Coordinate system') = 'Local';
RClick: 



Name: Tangent
Command: Node.Value('/Preferences/Modeling preferences','Coordinate system') = 'Tangent';
RClick: 



Name: Screen
Command: Node.Value('/Preferences/Modeling preferences','Coordinate system') = 'Screen';
RClick: 



Name: X lock
Command: RsTool.ToggleValue('/Preferences/Snapping/Enable X');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Snapping',5,1,1);



Name: Y lock
Command: RsTool.ToggleValue('/Preferences/Snapping/Enable Y');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Snapping',5,1,1);



Name: Z lock
Command: RsTool.ToggleValue('/Preferences/Snapping/Enable Z');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Snapping',5,1,1);



Name: Move
Command: Widgets.ActivateViewToolWidget('/Widgets/Tools/Move selection','Default');
RClick: 



Name: Rotate
Command: Widgets.ActivateViewToolWidget('/Widgets/Tools/Rotate selection','Default');
RClick: 



Name: Scale
Command: Widgets.ActivateViewToolWidget('/Widgets/Tools/Scale selection','Default');
RClick: 



Name: Move Cam
Command: Widgets.ActivateViewToolWidget('/Widgets/Tools/View tools/Camera move','Default');
RClick: 



Name: Rotate Cam
Command: Widgets.ActivateViewToolWidget('/Widgets/Tools/View tools/Camera rotate','Default');
RClick: 



Name: Fov Cam
Command: Widgets.ActivateViewToolWidget('/Widgets/Tools/View tools/Camera fov','Default');
RClick: 



Name: Rect zoom
Command: Widgets.ActivateViewToolWidget('/Widgets/Tools/View tools/Rect zoom','Default')
RClick: 



Name: Look at Selection
Command: RsTool.LookAtSelection('');
RClick: 



Name: Perspective
Command: D3DView.SwitchEyeCameraType('', '0')
RClick: 



Name: Front
Command: D3DView.SwitchEyeCameraType('', '6')
RClick: 



Name: Back
Command: D3DView.SwitchEyeCameraType('', '5')
RClick: 



Name: Left
Command: D3DView.SwitchEyeCameraType('', '3')
RClick: 



Name: Right
Command: D3DView.SwitchEyeCameraType('', '4')
RClick: 



Name: Top
Command: D3DView.SwitchEyeCameraType('', '2')
RClick: 



Name: Bottom
Command: D3DView.SwitchEyeCameraType('', '1')
RClick: 



Name: Reset
Command: RsTool.ResetView('');
RClick: 



Name: 3D Window
Command: WindowsManager.CreateWindowFromCLSIDEx('default', 'default', 'default', '[Scene]', 1, '3D')
RClick: 



Name: Copy Window
Command: WindowsManager.CopyWindow('')
RClick: 



Name: LE Window
Command: WindowsManager.CreateWindowFromCLSIDEx('default', 'default', 'default', '[Scene]', 1, '2D')
RClick: 



Name: Command Prompt
Command: CmdPrompt.OpenWindow('Windows Manager Space', 0)
RClick: 



Name: Output Console
Command: CmdPrompt.DebugView('Windows Manager Space', 0)
RClick: 



Name: Command history
Command: CmdPrompt.StackView('Windows Manager Space', 0)
RClick: 



Name: Status view
Command: RsTool.OpenStatusBar();
RClick: 



Name: Stack View
Command: WindowsManager.OpenHistoryWindow()
RClick: 



Name: Anim View
Command: WindowsManager.CreateWindowFromCLSIDEx('default', 'default', 'default', '[Scene]', 1, '4D')
RClick: 



Name: Package Manager
Command: WindowsManager.CreateWindowFromCLSID('{3011C160-2294-48d9-AE95-BD144574FB99}', '', '', '', 1)
RClick: 



Name: Scene View
Command: CmdPrompt.SceneViewCreate();
RClick: 



Name: 3D Window
Command: WindowsManager.CreateWindowFromCLSIDEx('default', 'default', 'default', '[Scene]', 1, '3D')
RClick: 



Name: Opaque Grid
Command: D3DView.LoadRAPreset('', -1.0, -1.0, 'Solid','')
RClick: 



Name: Opaque Grid
Command: D3DView.LoadRAPreset('', -1.0, -1.0, 'Solid','')
RClick: 



Name: No Grid
Command: D3DView.LoadRAPreset('', -1.0, -1.0, 'None', '')
RClick: 



Name: Wireframe Grid
Command: D3DView.LoadRAPreset('', -1.0, -1.0, 'Wire', '')
RClick: 



Name: Opaque
Command: D3DView.LoadRAPreset('', 1.0, 0.0, '', '')
RClick: 



Name: Opaque
Command: D3DView.LoadRAPreset('', 1.0, 0.0, '', '')
RClick: 



Name: OpaqueWires
Command: D3DView.LoadRAPreset('', 1.0, 1.0, '', '')
RClick: 



Name: Transp
Command: D3DView.LoadRAPreset('', 0.5, 0.0, '', '')
RClick: 



Name: TranspWires
Command: D3DView.LoadRAPreset('', 0.6, 1.0, '', '')
RClick: 



Name: Wires
Command: D3DView.LoadRAPreset('', 0.0, 1.0, '', '')
RClick: 



Name: SnapToGrid
Command: RsTool.ToggleValue('/Preferences/Snapping/Grid snapping');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Snapping',4,1,1);



Name: DistFb
Command: RsTool.ToggleValue('/Preferences/Snapping/Distances');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Snapping',6,1,1);



Name: PointEdit
Command: RsTool.ToggleValue('/Preferences/Snapping/Vertex snapping');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Snapping/Point edit snapping',3,1,0)



Name: M.Editor
Command: MeshModifiers.OpenMaterialEditor()
RClick: 



Name: M.Editor
Command: MeshModifiers.OpenMaterialEditor()
RClick: 



Name: Inspect
Command: MeshModifiers.OpenMaterialEditor();MeshModifiers.ToggleTool('/Widgets/Tools/Material editor/Inspect')
RClick: MeshModifiers.OpenMaterialEditor()



Name: Inspect
Command: MeshModifiers.OpenMaterialEditor();MeshModifiers.ToggleTool('/Widgets/Tools/Material editor/Inspect')
RClick: MeshModifiers.OpenMaterialEditor()



Name: Objects
Command: MeshModifiers.OpenMaterialEditor();MeshModifiers.SetMaterial('')
RClick: MeshModifiers.OpenMaterialEditor()



Name: Faces
Command: MeshModifiers.OpenMaterialEditor();MeshModifiers.StartPaintFaceTool()
RClick: MeshModifiers.OpenMaterialEditor()



Name: Repaint
Command: MeshModifiers.OpenMaterialEditor();MeshModifiers.ToggleTool('/Widgets/Tools/Material editor/Repaint')
RClick: MeshModifiers.OpenMaterialEditor()



Name: UV Editor 
Command: UVEditor.Open('%THIS_BUTTON_ITEM%')
RClick: UserInterface.OpenToolPanelViewEx2('', '','Preferences/UV Editor Preferences',3, 1, 0)



Name: Spherical
Command: UVEditor.ToggleUvProjection('Spherical','')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/UV mapping/Projection tool/UV Projection tool',3,0,0);



Name: Spherical
Command: UVEditor.ToggleUvProjection('Spherical','')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/UV mapping/Projection tool/UV Projection tool',3,0,0);



Name: Planar
Command: UVEditor.ToggleUvProjection('Planar','')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/UV mapping/Projection tool/UV Projection tool',3,0,0);



Name: Cylindrical
Command: UVEditor.ToggleUvProjection('Cylindrical','')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/UV mapping/Projection tool/UV Projection tool',3,0,0);



Name: Cubic
Command: UVEditor.ToggleUvProjection('Cubic','')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/UV mapping/Projection tool/UV Projection tool',3,0,0);



Name: ShrinkUV
Command: MeshModifiers.ShrinkWrap('')
RClick: UserInterface.OpenToolPanelViewEx2('', '','Preferences/Shrink Wrap preferences',3, 1, 0);



Name: Smooth
Command: MeshModifiers.SmoothNormals('')
RClick: 



Name: Smooth
Command: MeshModifiers.SmoothNormals('')
RClick: 



Name: AutoFacet
Command: MeshModifiers.AutofacetNormals('',-1)
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Mesh Editor Settings',5,0,0);



Name: Facet
Command: MeshModifiers.FacetedNormals('')
RClick: 



Name: Library browser
Command: Library2.ShowLibraryBrowserWindow()
RClick: 



Name: Look At
Command: ToolMng.ActivateTool('{17D544A3-3F58-436B-83E7-F8B4D7D4E7C5}','{4E203C6C-A20D-4e32-82B4-FC482F5A0D06}' )
RClick: 



Name: UnLook At
Command: Activity.Run("/Scripts/Commands/UnLookAt");
RClick: 



Name: Look At
Command: ToolMng.ActivateTool('{17D544A3-3F58-436B-83E7-F8B4D7D4E7C5}','{4E203C6C-A20D-4e32-82B4-FC482F5A0D06}' )
RClick: 



Name: Set Camera
Command: D3DView.SetActiveCamera('', '')
RClick: 



Name: Isometric 
Command: D3DView.SwitchEyeCameraType('', '7')
RClick: 



Name: Nearest ortho
Command: RsTool.SetNearestOrthoView('');
RClick: 



Name: Isometric 
Command: D3DView.SwitchEyeCameraType('', '7')
RClick: 



Name: FP navigation
Command: RsTool.ActivateFpnToView('');
RClick: RsTool.ShowFpnProperties();



Name: DynaPose
Command: CharacterEditor.ActivateCharacterTool('/Widgets/Tools/Character editor/Dynamic pose'); UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Character editor/Dynamic pose/Character Posing',3,1,0);
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Character editor/Dynamic pose/Character Posing',3,1,0);



Name: FP navigation
Command: RsTool.ActivateFpnToView('');
RClick: RsTool.ShowFpnProperties();



Name: PhysMove
Command: Physics.ActivatePhysWidget('PhysMoveWidget')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Phys Move Preferences',3,1,0);



Name: +PhysAttr
Command: Physics.AddPhysAttr('');Physics.OpenNodePanel('phys', 3)
RClick: Physics.OpenNodePanel('phys', 3)



Name: +PhysAttr
Command: Physics.AddPhysAttr('');Physics.OpenNodePanel('phys', 3)
RClick: Physics.OpenNodePanel('phys', 3)



Name: +PhysAttr
Command: Physics.AddPhysAttr('');Physics.OpenNodePanel('phys', 3)
RClick: Physics.OpenNodePanel('phys', 3)



Name: +LocalEnv
Command: Physics.AddEnvAttr('');Physics.OpenNodePanel('phys', 3)
RClick: Physics.OpenNodePanel('env', 3)



Name: +ClothAttr
Command: Physics.AddClothAttr('');Physics.OpenNodePanel('phys', 3)
RClick: Physics.OpenNodePanel('cloth', 3)



Name: -PhysAttr
Command: Physics.RemovePhysAttr('')
RClick: 



Name: -LocalEnv
Command: Physics.RemoveEnvAttr('')
RClick: 



Name: -ClothAttr
Command: Physics.RemoveClothAttr('')
RClick: 



Name: Speed
Command: Physics.ActivatePhysWidget('SpeedWidget')
RClick: Physics.OpenNodePanel('phys', 4)



Name: Speed
Command: Physics.ActivatePhysWidget('SpeedWidget')
RClick: Physics.OpenNodePanel('phys', 4)



Name: Rotation
Command: Physics.ActivatePhysWidget('RotationWidget')
RClick: Physics.OpenNodePanel('phys', 4)



Name: A.Speed
Command: Physics.ActivatePhysWidget('AccWidget')
RClick: Physics.OpenNodePanel('phys', 5)



Name: A.Rotation
Command: Physics.ActivatePhysWidget('RotAccWidget')
RClick: Physics.OpenNodePanel('phys', 5)



Name: COG
Command: Physics.ActivatePhysWidget('CogWidget')
RClick: Physics.OpenNodePanel('phys', 7)



Name: COG
Command: Physics.ActivatePhysWidget('CogWidget')
RClick: Physics.OpenNodePanel('phys', 7)



Name: FixPoint1
Command: Physics.ActivatePhysWidget('Fix1Widget')
RClick: Physics.OpenNodePanel('phys', 7)



Name: FixPoint2
Command: Physics.ActivatePhysWidget('Fix2Widget')
RClick: Physics.OpenNodePanel('phys', 7)



Name: ClothFix
Command: Physics.ActivatePhysWidget('ClothFixWidget')
RClick: Physics.ActivatePhysWidget('ClothFixWidget');Physics.ResetClothFixation('')



Name: WindLocal
Command: Physics.AddWind('', true)
RClick: 



Name: WindLocal
Command: Physics.AddWind('', true)
RClick: 



Name: WindGlobal
Command: Physics.AddWind('', false)
RClick: 



Name: EnviLocal
Command: Physics.ActivatePhysWidget('LocEnvWidget')
RClick: Physics.OpenNodePanel('env', 3)



Name: Gravity
Command: Physics.ActivatePhysWidget('GravityWidget')
RClick: Physics.OpenNodePanel('space', 3)



Name: Physical simulation
Command: Physics.init_PhysSim()
RClick: Physics.OpenPanel()



Name: Record Toolbar
Command: WindowsManager.OpenToolbarFromPrototype('Record3D', 290, 440,-1,-1)
RClick: RsRec.OpenRecPreferences()



Name: Record Toolbar
Command: WindowsManager.OpenToolbarFromPrototype('Record3D', 290, 440,-1,-1)
RClick: RsRec.OpenRecPreferences()



Name: jScript Macro Record Toolbar
Command: WindowsManager.OpenToolbarFromPrototype('MacroRecordjS', 290, 408,-1,-1)
RClick: RsFileIO.LoadObject(System.GetMainDir() + '\\Rs Main Libraries\\System - Scripts\\jScript command.RsObj', Space.CurrentScene());



Name: VBScript Macro Record Toolbar
Command: WindowsManager.OpenToolbarFromPrototype('MacroRecordVB', 430, 408,-1,-1)
RClick: RsFileIO.LoadObject(System.GetMainDir() + '\\Rs Main Libraries\\System - Scripts\\VBScript command.RsObj', Space.CurrentScene());



Name: Shared Space
Command: Net.NtOpenView
RClick: 



Name: Render Scene
Command: OfflineRender.OpenView('',0,0);OfflineRender.RenderScene('')
RClick: OfflineRender.OpenPreferencesPanel()



Name: HW settings
Command: D3DView.ShowSettingsDialog()
RClick: 



Name: Manual
Command: tSBridge.SuggestTSStateByAlias("SV_HELP_HELP_PDF_MANUAL")
RClick: 



Name: Export to VE 
Command: RsImport.OpenVECollectionPanel();
RClick: 



Name: File Render
Command: D3DView.RenderToFile('', '')
RClick: 



Name: Render Scene
Command: OfflineRender.OpenView('',0,0);OfflineRender.RenderScene('')
RClick: OfflineRender.OpenPreferencesPanel()

Name: Render Scene
Command: OfflineRender.OpenView('',0,0);OfflineRender.RenderScene('')
RClick: OfflineRender.OpenPreferencesPanel()

Name: Render Area
Command: Widgets.ReplaceWidget('{88839603-7F98-41f0-96AC-BE94E801CFF3}','/Widgets/Tools/Offline render/Area scene render','Default','','dummy')
RClick: OfflineRender.OpenPreferencesPanel()

Name: Render Object
Command: OfflineRender.OpenView('',0,0);OfflineRender.RenderObject('')
RClick: OfflineRender.OpenPreferencesPanel()

Name: Render Animation
Command: OfflineRender.OpenView('',0,0);OfflineRender.RenderAnimation('')
RClick: OfflineRender.OpenPreferencesPanel()


Name: Show
Command: Activity.Run("/Scripts/Commands/Show");
RClick: if(Node.Exists(Node.FirstSelected() + "/Object Render Attributes")){UserInterface.OpenToolPanelViewEx2("" , "" , Node.FirstSelected() + "/Object Render Attributes", 3,1,0);};

Name: Hide
Command: Activity.Run("/Scripts/Commands/Hide");
RClick: if(Node.Exists(Node.FirstSelected() + "/Object Render Attributes")){UserInterface.OpenToolPanelViewEx2("" , "" , Node.FirstSelected() + "/Object Render Attributes", 3,1,0);};

Name: ShowAll
Command: Activity.Run("/Scripts/Commands/ShowAll");
RClick: 

Name: HideAll
Command: Activity.Run("/Scripts/Commands/HideAll");
RClick: 

Name: ShowAll
Command: Activity.Run("/Scripts/Commands/ShowAll");
RClick: 



Name: Show
Command: Activity.Run("/Scripts/Commands/Show");
RClick: if(Node.Exists(Node.FirstSelected() + "/Object Render Attributes")){UserInterface.OpenToolPanelViewEx2("" , "" , Node.FirstSelected() + "/Object Render Attributes", 3,1,0);};



Name: Delete
Command: Node.Delete('')
RClick: 



Name: Copy
Command: Node.Copy('', '')
RClick: Activity.Run('/Scripts/Commands/Copy')



Name: Delete
Command: Node.Delete('')
RClick: 



Name: Rec
Command: RsAnim.SetKeyFrame('', RsTime.CurrentTime())
RClick: RsAnimKeying.OpenView()


Name: Start frame
Command: RsTime.StartFrame()
RClick: 

Name: Prev keyframe
Command: RsTime.PrevKeyFrame()
RClick: 

Name: Prev keyframe
Command: RsTime.PrevKeyFrame()
RClick: 

Name: Prev frame
Command: RsTime.PrevFrame()
RClick: 

Name: Stop
Command: RsTime.Stop()
RClick: 

Name: Play
Command: RsTime.Play('')
RClick: 



Name: Next keyframe
Command: RsTime.NextKeyFrame()
RClick: 

Name: Next keyframe
Command: RsTime.NextKeyFrame()
RClick: 

Name: Next frame
Command: RsTime.NextFrame()
RClick: 

Name: End frame
Command: RsTime.EndFrame()
RClick: 



Name: Rec
Command: RsAnim.SetKeyFrame('', RsTime.CurrentTime())
RClick: RsAnimKeying.OpenView()



Name: Start frame
Command: RsTime.StartFrame()
RClick: 

Name: Prev keyframe
Command: RsTime.PrevKeyFrame()
RClick: 

Name: Prev keyframe
Command: RsTime.PrevKeyFrame()
RClick: 

Name: Prev frame
Command: RsTime.PrevFrame()
RClick: 

Name: Stop
Command: RsTime.Stop()
RClick: 

Name: Play
Command: RsTime.Play('')
RClick: 

Name: Next keyframe
Command: RsTime.NextKeyFrame()
RClick: 

Name: Next keyframe
Command: RsTime.NextKeyFrame()
RClick: 

Name: Next frame
Command: RsTime.NextFrame()
RClick: 

Name: End frame
Command: RsTime.EndFrame()
RClick: 



Name: Scene
Command: LE.OpenLocation(Space.CurrentScene)
RClick: 



Name: Organize
Command: LE.MinimizePanels('');LE.ArrangePanels('')
RClick: LE.ExpandPanels('');LE.ArrangePanels('');



Name: Unselect
Command: Space.Unselect();RsTool.Arrow();
RClick: 



Name: Project
Command: LE.OpenLocation("/Project")
RClick: 



Name:  Windows Manager Space
Command: LE.OpenLocation("/Project/Windows Manager Space")
RClick: 



Name: Default
Command: LE.OpenLocation("/Project/Windows Manager Space/Frame Window/Border Docking Place/Frame Window, 1/Split Docking Place/Frame Window, 1/Split Docking Place/Frame Window, 1/Split Docking Place/Frame Window, 2");
RClick: 



Name: System
Command: LE.OpenLocation("/System")
RClick: 

Name: Network
Command: LE.OpenLocation("/Network")
RClick: 

Name: Widgets
Command: LE.OpenLocation("/Widgets")
RClick: 


Name: Obj Widget
Command: LE.OpenLocation("/Widgets/Select/Default object navigation widget")
RClick: 



Name: PE Widget
Command: LE.OpenLocation("/Widgets/Edit/Point edit widget")
RClick: 



Name: Bkgrd Widget
Command: LE.OpenLocation("/Widgets/Tools/Background")
RClick: 



Name: Preferences
Command: LE.OpenLocation("/Preferences")
RClick: 



Name: Toolbar Prototypes Encapsulator
Command: LE.OpenLocation("/Toolbar Prototypes Encapsulator")
RClick: 



Name: Rec
Command: RsAnim.SetKeyFrame('', RsTime.CurrentTime())
RClick: RsAnimKeying.OpenView()



Name: Start frame
Command: RsTime.StartFrame()
RClick: 



Name: Prev keyframe
Command: RsTime.PrevKeyFrame()
RClick: 



Name: Prev keyframe
Command: RsTime.PrevKeyFrame()
RClick: 



Name: Prev frame
Command: RsTime.PrevFrame()
RClick: 



Name: Stop
Command: RsTime.Stop()
RClick: 



Name: Play
Command: RsTime.Play('')
RClick: 



Name: Next keyframe
Command: RsTime.NextKeyFrame()
RClick: 



Name: Next keyframe
Command: RsTime.NextKeyFrame()
RClick: 



Name: Next frame
Command: RsTime.NextFrame()
RClick: 



Name: End frame
Command: RsTime.EndFrame()
RClick: 



Name: Help
Command: 
RClick: 



Name: Tool tips
Command: tSBridge.XorTypeTSStateByAlias("SV_TOOLTIPS_256")
RClick: 



Name: About
Command: tSBridge.SuggestTSStateByAlias("SV_GETINFOGROUP_INFOGROUP_ABOUT")
RClick: 



Name: Help
Command: var WshShell = new ActiveXObject("WScript.Shell");WshShell.Run (System.GetMainDir() + "\\PDFMan\\tS65Help.chm")
RClick: 



Name: tS6 File
Command: 
RClick: 



Name: New
Command: 
RClick: 



Name: Scene
Command: tSBridge.SuggestTSStateByAlias("CreateNewSceneFile")
RClick: 



Name: Library
Command: tSBridge.SuggestTSStateByAlias("SV_FILE2_FILE2_LIBRARY_NEW")
RClick: 



Name: Project
Command: tSBridge.SuggestTSStateByAlias("SV_FILE2_FILE2_PROJECT_NEW")
RClick: 



Name: Load
Command: 
RClick: 



Name: Scene
Command: tSBridge.SuggestTSStateByAlias("SV_FILE_FILE_SCENE_LOAD")
RClick: 



Name: Object
Command: tSBridge.SuggestTSStateByAlias("SV_FILE_FILE_LOAD")
RClick: 



Name: Library
Command: tSBridge.SuggestTSStateByAlias("SV_FILE2_FILE2_LIBRARY_SHARE")
RClick: 



Name: Radiosity
Command: tSBridge.SuggestTSStateByAlias("SV_RADIO_STEP_RADIO_STEP_LOAD_SOLUTION")
RClick: 



Name: Save
Command: 
RClick: 



Name: Scene
Command: tSBridge.SuggestTSStateByAlias("SV_FILE_FILE_SCENE_SAVE")
RClick: 



Name: Object
Command: tSBridge.SuggestTSStateByAlias("SV_FILE_FILE_SAVE")
RClick: 



Name: Preferences
Command: tSBridge.SuggestTSStateByAlias("SV_FILE_FILE_PREFERENCES")
RClick: 



Name: Hot Keys
Command: tSBridge.SuggestTSStateByAlias("SV_FILE_FILE_HOTKEYS")
RClick: 



Name: Save As...
Command: 
RClick: 



Name: Scene
Command: tSBridge.SuggestTSStateByAlias("SV_FILE_FILE_SCENE_SAVE_AS")
RClick: 



Name: Object
Command: tSBridge.SuggestTSStateByAlias("SV_FILE_FILE_SAVE_AS")
RClick: 



Name: Radiosity
Command: tSBridge.SuggestTSStateByAlias("SV_RADIO_STEP_RADIO_STEP_SAVE_SOLUTION")
RClick: 



Name: Texture from illumination
Command: tSBridge.SuggestTSStateByAlias("SV_FILE_FILE_SCENE_TEXTUREBAKED")
RClick: 



Name: Archive
Command: tSBridge.SuggestTSStateByAlias("SV_FILE_FILE_SCENE_ARCHIVE")
RClick: 



Name: Exit
Command: tSBridge.SuggestTSStateByAlias("SV_FILE_FILE_EXIT")
RClick: 



Name: Preferences
Command: tSBridge.SuggestTSStateByAlias("SV_GETGROUP_GROUP_SETTINGS")
RClick: 



Name: Display options...
Command: tSBridge.SuggestTSStateByAlias("Reality1Panel")
RClick: 



Name: Recent Files
Command: 
RClick: 



Name: finalTigerTest.cob
Command: tSBridge.SuggestTSState(859, 1);
RClick: 



Name: fullOnTest.cob
Command: tSBridge.SuggestTSState(859, 2);
RClick: 



Name: helloFromWorkspace.cob
Command: tSBridge.SuggestTSState(859, 3);
RClick: 



Name: wundergnd.cob
Command: tSBridge.SuggestTSState(859, 4);
RClick: 



Name: testexport.cob
Command: tSBridge.SuggestTSState(859, 5);
RClick: 



Name: curveGroupFromModelSide1.cob
Command: tSBridge.SuggestTSState(859, 6);
RClick: 



Name: curveGroupFromModelSide0.cob
Command: tSBridge.SuggestTSState(859, 7);
RClick: 



Name: testexportTiger.cob
Command: tSBridge.SuggestTSState(859, 8);
RClick: 



Name: Perspective
Command: D3DView.SwitchEyeCameraType('', '0');WindowsManager.Activate()
RClick: 



Name: Left
Command: D3DView.SwitchEyeCameraType('', '3');WindowsManager.Activate()
RClick: 



Name: Left
Command: D3DView.SwitchEyeCameraType('', '3');WindowsManager.Activate()
RClick: 



Name: Right
Command: D3DView.SwitchEyeCameraType('', '4');WindowsManager.Activate()
RClick: 



Name: Front
Command: D3DView.SwitchEyeCameraType('', '6');WindowsManager.Activate()
RClick: 



Name: Front
Command: D3DView.SwitchEyeCameraType('', '6');WindowsManager.Activate()
RClick: 



Name: Back
Command: D3DView.SwitchEyeCameraType('', '5');WindowsManager.Activate()
RClick: 



Name: Top
Command: D3DView.SwitchEyeCameraType('', '2');WindowsManager.Activate()
RClick: 



Name: Top
Command: D3DView.SwitchEyeCameraType('', '2');WindowsManager.Activate()
RClick: 



Name: Bottom
Command: D3DView.SwitchEyeCameraType('', '1');WindowsManager.Activate()
RClick: 



Name: Set Camera
Command: D3DView.SetActiveCamera('', '');WindowsManager.Activate()
RClick: 



Name: Set Camera
Command: D3DView.SetActiveCamera('', '');WindowsManager.Activate()
RClick: 



Name: Isometric 
Command: D3DView.SwitchEyeCameraType('', '7');WindowsManager.Activate()
RClick: 



Name: Perspective
Command: D3DView.SwitchEyeCameraType('', '0');WindowsManager.Activate()
RClick: 



Name: Perspective
Command: D3DView.SwitchEyeCameraType('', '0');WindowsManager.Activate()
RClick: 



Name: Nearest ortho
Command: RsTool.SetNearestOrthoView('');;WindowsManager.Activate()
RClick: 



Name: FP navigation
Command: Avatar.ActivateFpnToView('');WindowsManager.Activate();
RClick: RsTool.ShowFpnProperties();



Name: FP navigation
Command: Avatar.ActivateFpnToView('');WindowsManager.Activate();
RClick: RsTool.ShowFpnProperties();



Name: Reset View
Command: RsTool.ResetView('');WindowsManager.Activate()
RClick: 



Name: Reset View
Command: RsTool.ResetView('');WindowsManager.Activate()
RClick: 



Name: Look at Selection
Command: RsTool.LookAtSelection('');WindowsManager.Activate()
RClick: 



Name: Rect zoom
Command: Widgets.ActivateViewToolWidget('/Widgets/Tools/View tools/Rect zoom','Default');WindowsManager.Activate()
RClick: 



Name: X lock
Command: RsTool.ToggleValue('/Preferences/Snapping/Enable X');WindowsManager.Activate()
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Snapping',5,1,1);



Name: Y lock
Command: RsTool.ToggleValue('/Preferences/Snapping/Enable Y');WindowsManager.Activate()
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Snapping',5,1,1);



Name: Z lock
Command: RsTool.ToggleValue('/Preferences/Snapping/Enable Z');WindowsManager.Activate()
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Snapping',5,1,1);



Name: Opaque
Command: D3DView.LoadRAPreset('', 1.0, 0.0, '', '');WindowsManager.Activate()
RClick: 



Name: Opaque
Command: D3DView.LoadRAPreset('', 1.0, 0.0, '', '');WindowsManager.Activate()
RClick: 



Name: Opaque
Command: D3DView.LoadRAPreset('', 1.0, 0.0, '', '');WindowsManager.Activate()
RClick: 



Name: OpaqueWires
Command: D3DView.LoadRAPreset('', 1.0, 1.0, '', '');WindowsManager.Activate()
RClick: 



Name: Transp
Command: D3DView.LoadRAPreset('', 0.5, 0.0, '', '');WindowsManager.Activate()
RClick: 



Name: TranspWires
Command: D3DView.LoadRAPreset('', 0.6, 1.0, '', '');WindowsManager.Activate()
RClick: 



Name: Wires
Command: D3DView.LoadRAPreset('', 0.0, 1.0, '', '');WindowsManager.Activate()
RClick: 



Name: WireframeGrid
Command: D3DView.LoadRAPreset('', -1.0, -1.0, 'Wire', '');WindowsManager.Activate()
RClick: 



Name: Wireframe Grid
Command: D3DView.LoadRAPreset('', -1.0, -1.0, 'Wire', '');WindowsManager.Activate()
RClick: 



Name: Opaque Grid
Command: D3DView.LoadRAPreset('', -1.0, -1.0, 'Solid','');WindowsManager.Activate()
RClick: 



Name: No Grid
Command: D3DView.LoadRAPreset('', -1.0, -1.0, 'None', '');WindowsManager.Activate()
RClick: 



Name: Hide
Command: Activity.Run("/Scripts/Commands/Hide");WindowsManager.Activate()
RClick: if(Node.Exists(Node.FirstSelected() + "/Object Render Attributes")){UserInterface.OpenToolPanelViewEx2("" , "" , Node.FirstSelected() + "/Object Render Attributes", 3,1,0);};



Name: Hide
Command: Activity.Run("/Scripts/Commands/Hide");WindowsManager.Activate()
RClick: if(Node.Exists(Node.FirstSelected() + "/Object Render Attributes")){UserInterface.OpenToolPanelViewEx2("" , "" , Node.FirstSelected() + "/Object Render Attributes", 3,1,0);};



Name: Show
Command: Activity.Run("/Scripts/Commands/Show");WindowsManager.Activate()
RClick: if(Node.Exists(Node.FirstSelected() + "/Object Render Attributes")){UserInterface.OpenToolPanelViewEx2("" , "" , Node.FirstSelected() + "/Object Render Attributes", 3,1,0);};



Name: HideAll
Command: Activity.Run("/Scripts/Commands/HideAll");WindowsManager.Activate()
RClick: 



Name: HideAll
Command: Activity.Run("/Scripts/Commands/HideAll");WindowsManager.Activate()
RClick: 



Name: ShowAll
Command: Activity.Run("/Scripts/Commands/ShowAll");WindowsManager.Activate()
RClick: 



Name: World
Command: Node.Value('/Preferences/Modeling preferences','Coordinate system') = 'World';WindowsManager.Activate()
RClick: 



Name: World
Command: Node.Value('/Preferences/Modeling preferences','Coordinate system') = 'World';WindowsManager.Activate()
RClick: 



Name: Object
Command: Node.Value('/Preferences/Modeling preferences','Coordinate system') = 'Local';WindowsManager.Activate()
RClick: 



Name: Tangent
Command: Node.Value('/Preferences/Modeling preferences','Coordinate system') = 'Tangent';WindowsManager.Activate()
RClick: 



Name: Screen
Command: Node.Value('/Preferences/Modeling preferences','Coordinate system') = 'Screen';WindowsManager.Activate()
RClick: 



Name: DynaPose
Command: CharacterEditor.ActivateCharacterTool('/Widgets/Tools/Character editor/Dynamic pose'); UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Character editor/Dynamic pose/Character Posing',3,1,0);WindowsManager.Activate();
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Character editor/Dynamic pose/Character Posing',3,1,0);



Name: DynaPose
Command: CharacterEditor.ActivateCharacterTool('/Widgets/Tools/Character editor/Dynamic pose'); UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Character editor/Dynamic pose/Character Posing',3,1,0);WindowsManager.Activate();
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Character editor/Dynamic pose/Character Posing',3,1,0);



Name: PhysMove
Command: Physics.ActivatePhysWidget('PhysMoveWidget');WindowsManager.Activate();
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Phys Move Preferences',3,1,0);



Name: Look At
Command: ToolMng.ActivateTool('{17D544A3-3F58-436B-83E7-F8B4D7D4E7C5}','{4E203C6C-A20D-4e32-82B4-FC482F5A0D06}' );WindowsManager.Activate();
RClick: 



Name: NewView
Command: Activity.Run("/Scripts/Commands/NewWindowViewBar");WindowsManager.Activate()
RClick: 



Name: Move
Command: Widgets.ActivateViewToolWidget('/Widgets/Tools/Move selection','Default');
RClick: 



Name: Rotate
Command: Widgets.ActivateViewToolWidget('/Widgets/Tools/Rotate selection','Default');WindowsManager.Activate()
RClick: 



Name: Scale
Command: Widgets.ActivateViewToolWidget('/Widgets/Tools/Scale selection','Default');WindowsManager.Activate()
RClick: 



Name: Move Cam
Command: Widgets.ActivateViewToolWidget('/Widgets/Tools/View tools/Camera move','Default');WindowsManager.Activate()
RClick: 



Name: Rotate Cam
Command: Widgets.ActivateViewToolWidget('/Widgets/Tools/View tools/Camera rotate','Default');WindowsManager.Activate()
RClick: 



Name: Fov Cam
Command: Widgets.ActivateViewToolWidget('/Widgets/Tools/View tools/Camera fov','Default');WindowsManager.Activate()
RClick: 



Name: File
Command: 
RClick: 



Name: New scene
Command: Space.NewScene()
RClick: 



Name: Load
Command: Library2.DlgGenericLoad('', '', 15); 
RClick: 



Name: Save
Command: Library2.DlgGenericSave('', '', 3);
RClick: 



Name: Recent Files
Command: 
RClick: 



Name: Actor1.dae
Command: RsFileIO.GenericLoad('E:\\ue4Tests\\Actor1.dae', '', 15);
RClick: 



Name: Actor1plusanim.dae
Command: RsFileIO.GenericLoad('E:\\ue4Tests\\Actor1plusanim.dae', '', 15);
RClick: 



Name: install fbx2 import export.RsObj
Command: RsFileIO.GenericLoad('C:\\Users\\ClintonReese\\Desktop\\Clintons3DFBX2015\\install fbx2 import export.RsObj', '', 15);
RClick: 



Name: CurveToolsAutoload.RsObj
Command: RsFileIO.GenericLoad('C:\\Users\\ClintonReese\\Desktop\\CurveToolsAutoload.RsObj', '', 15);
RClick: 



Name: SVG Import Autoload.RsObj
Command: RsFileIO.GenericLoad('C:\\Users\\ClintonReese\\Desktop\\SVG Import Autoload.RsObj', '', 15);
RClick: 



Name: SVG Import Autoload.RsObj
Command: RsFileIO.GenericLoad('E:\\NewServer\\workingtemp\\SVG Import Autoload.RsObj', '', 15);
RClick: 



Name: SVGimporterF.RsObj
Command: RsFileIO.GenericLoad('E:\\NewServer\\workingtemp\\SVGimporterF.RsObj', '', 15);
RClick: 



Name: SVGimporterE.RsObj
Command: RsFileIO.GenericLoad('E:\\NewServer\\workingtemp\\SVGimporterE.RsObj', '', 15);
RClick: 



Name: Exit
Command: RsApp.ShutDown()
RClick: 



Name: HW settings
Command: D3DView.ShowSettingsDialog()
RClick: 



Name: Save As RsRcd
Command: RsRec.Start(Space.CurrentScene());RsRec.Stop();RsRec.Save('');
RClick: 



Name: Help
Command: 
RClick: 



Name: About
Command: WindowsManager.OpenAboutBox();
RClick: 



Name: Manual
Command: tSBridge.SuggestTSStateByAlias("SV_HELP_HELP_PDF_MANUAL")
RClick: 



Name: United 3D Artist  
Command: RsTool.OpenWebPage("www.united3dartists.com");
RClick: 



Name: Updates
Command: RsTool.OpenWebPage("www.united3dartists.com/forum/viewforum.php?f=55");
RClick: 



Name: Set Camera
Command: D3DView.SetActiveCamera('', '');WindowsManager.Activate()
RClick: 



Name: Left
Command: D3DView.SwitchEyeCameraType('', '3');WindowsManager.Activate()
RClick: 



Name: Left
Command: D3DView.SwitchEyeCameraType('', '3');WindowsManager.Activate()
RClick: 



Name: Right
Command: D3DView.SwitchEyeCameraType('', '4');WindowsManager.Activate()
RClick: 



Name: Front
Command: D3DView.SwitchEyeCameraType('', '6');WindowsManager.Activate()
RClick: 



Name: Front
Command: D3DView.SwitchEyeCameraType('', '6');WindowsManager.Activate()
RClick: 



Name: Back
Command: D3DView.SwitchEyeCameraType('', '5');WindowsManager.Activate()
RClick: 



Name: Top
Command: D3DView.SwitchEyeCameraType('', '2');WindowsManager.Activate()
RClick: 



Name: Top
Command: D3DView.SwitchEyeCameraType('', '2');WindowsManager.Activate()
RClick: 



Name: Bottom
Command: D3DView.SwitchEyeCameraType('', '1');WindowsManager.Activate()
RClick: 



Name: Set Camera
Command: D3DView.SetActiveCamera('', '');WindowsManager.Activate()
RClick: 



Name: Set Camera
Command: D3DView.SetActiveCamera('', '');WindowsManager.Activate()
RClick: 



Name: Isometric 
Command: D3DView.SwitchEyeCameraType('', '7');WindowsManager.Activate()
RClick: 



Name: Perspective
Command: D3DView.SwitchEyeCameraType('', '0');WindowsManager.Activate()
RClick: 



Name: Perspective
Command: D3DView.SwitchEyeCameraType('', '0');WindowsManager.Activate()
RClick: 



Name: Nearest ortho
Command: RsTool.SetNearestOrthoView('');;WindowsManager.Activate()
RClick: 



Name: FP navigation
Command: Avatar.ActivateFpnToView('');WindowsManager.Activate();
RClick: RsTool.ShowFpnProperties();



Name: FP navigation
Command: Avatar.ActivateFpnToView('');WindowsManager.Activate();
RClick: RsTool.ShowFpnProperties();



Name: Reset View
Command: RsTool.ResetView('');WindowsManager.Activate()
RClick: 



Name: Reset View
Command: RsTool.ResetView('');WindowsManager.Activate()
RClick: 



Name: Look at Selection
Command: RsTool.LookAtSelection('');WindowsManager.Activate()
RClick: 



Name: Rect zoom
Command: Widgets.ActivateViewToolWidget('/Widgets/Tools/View tools/Rect zoom','Default');WindowsManager.Activate()
RClick: 



Name: Fov Cam
Command: Widgets.ActivateViewToolWidget('/Widgets/Tools/View tools/Camera fov','Default');WindowsManager.Activate()
RClick: 



Name: Rotate Cam
Command: Widgets.ActivateViewToolWidget('/Widgets/Tools/View tools/Camera rotate','Default');WindowsManager.Activate()
RClick: 



Name: Move Cam
Command: Widgets.ActivateViewToolWidget('/Widgets/Tools/View tools/Camera move','Default');WindowsManager.Activate()
RClick: 



Name: X lock
Command: RsTool.ToggleValue('/Preferences/Snapping/Enable X');WindowsManager.Activate()
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Snapping',5,1,1);



Name: Y lock
Command: RsTool.ToggleValue('/Preferences/Snapping/Enable Y');WindowsManager.Activate()
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Snapping',5,1,1);



Name: Z lock
Command: RsTool.ToggleValue('/Preferences/Snapping/Enable Z');WindowsManager.Activate()
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Snapping',5,1,1);



Name: Opaque
Command: D3DView.LoadRAPreset('', 1.0, 0.0, '', '');WindowsManager.Activate()
RClick: 



Name: Opaque
Command: D3DView.LoadRAPreset('', 1.0, 0.0, '', '');WindowsManager.Activate()
RClick: 



Name: Opaque
Command: D3DView.LoadRAPreset('', 1.0, 0.0, '', '');WindowsManager.Activate()
RClick: 



Name: OpaqueWires
Command: D3DView.LoadRAPreset('', 1.0, 1.0, '', '');WindowsManager.Activate()
RClick: 



Name: Transp
Command: D3DView.LoadRAPreset('', 0.5, 0.0, '', '');WindowsManager.Activate()
RClick: 



Name: TranspWires
Command: D3DView.LoadRAPreset('', 0.6, 1.0, '', '');WindowsManager.Activate()
RClick: 



Name: Wires
Command: D3DView.LoadRAPreset('', 0.0, 1.0, '', '');WindowsManager.Activate()
RClick: 



Name: WireframeGrid
Command: D3DView.LoadRAPreset('', -1.0, -1.0, 'Wire', '');WindowsManager.Activate()
RClick: 



Name: Wireframe Grid
Command: D3DView.LoadRAPreset('', -1.0, -1.0, 'Wire', '');WindowsManager.Activate()
RClick: 



Name: Opaque Grid
Command: D3DView.LoadRAPreset('', -1.0, -1.0, 'Solid','');WindowsManager.Activate()
RClick: 



Name: No Grid
Command: D3DView.LoadRAPreset('', -1.0, -1.0, 'None', '');WindowsManager.Activate()
RClick: 



Name: Hide
Command: Activity.Run("/Scripts/Commands/Hide");WindowsManager.Activate()
RClick: if(Node.Exists(Node.FirstSelected() + "/Object Render Attributes")){UserInterface.OpenToolPanelViewEx2("" , "" , Node.FirstSelected() + "/Object Render Attributes", 3,1,0);};



Name: Hide
Command: Activity.Run("/Scripts/Commands/Hide");WindowsManager.Activate()
RClick: if(Node.Exists(Node.FirstSelected() + "/Object Render Attributes")){UserInterface.OpenToolPanelViewEx2("" , "" , Node.FirstSelected() + "/Object Render Attributes", 3,1,0);};



Name: Show
Command: Activity.Run("/Scripts/Commands/Show");WindowsManager.Activate()
RClick: if(Node.Exists(Node.FirstSelected() + "/Object Render Attributes")){UserInterface.OpenToolPanelViewEx2("" , "" , Node.FirstSelected() + "/Object Render Attributes", 3,1,0);};



Name: HideAll
Command: Activity.Run("/Scripts/Commands/HideAll");WindowsManager.Activate()
RClick: 



Name: HideAll
Command: Activity.Run("/Scripts/Commands/HideAll");WindowsManager.Activate()
RClick: 



Name: ShowAll
Command: Activity.Run("/Scripts/Commands/ShowAll");WindowsManager.Activate()
RClick: 



Name: World
Command: Node.Value('/Preferences/Modeling preferences','Coordinate system') = 'World';WindowsManager.Activate()
RClick: 

Name: World
Command: Node.Value('/Preferences/Modeling preferences','Coordinate system') = 'World';WindowsManager.Activate()
RClick: 

Name: Object
Command: Node.Value('/Preferences/Modeling preferences','Coordinate system') = 'Local';WindowsManager.Activate()
RClick: 

Name: Tangent
Command: Node.Value('/Preferences/Modeling preferences','Coordinate system') = 'Tangent';WindowsManager.Activate()
RClick: 

Name: Screen
Command: Node.Value('/Preferences/Modeling preferences','Coordinate system') = 'Screen';WindowsManager.Activate()
RClick: 



Name: DynaPose
Command: CharacterEditor.ActivateCharacterTool('/Widgets/Tools/Character editor/Dynamic pose'); UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Character editor/Dynamic pose/Character Posing',3,1,0);WindowsManager.Activate();
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Character editor/Dynamic pose/Character Posing',3,1,0);

Name: DynaPose
Command: CharacterEditor.ActivateCharacterTool('/Widgets/Tools/Character editor/Dynamic pose'); UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Character editor/Dynamic pose/Character Posing',3,1,0);WindowsManager.Activate();
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Character editor/Dynamic pose/Character Posing',3,1,0);



Name: PhysMove
Command: Physics.ActivatePhysWidget('PhysMoveWidget');WindowsManager.Activate();
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Phys Move Preferences',3,1,0);



Name: Move
Command: Widgets.ActivateViewToolWidget('/Widgets/Tools/Move selection','Default');WindowsManager.Activate()
RClick: 

Name: Rotate
Command: Widgets.ActivateViewToolWidget('/Widgets/Tools/Rotate selection','Default');WindowsManager.Activate()
RClick: 

Name: Scale
Command: Widgets.ActivateViewToolWidget('/Widgets/Tools/Scale selection','Default');WindowsManager.Activate()
RClick: 



Name: Look At
Command: ToolMng.ActivateTool('{17D544A3-3F58-436B-83E7-F8B4D7D4E7C5}','{4E203C6C-A20D-4e32-82B4-FC482F5A0D06}' );WindowsManager.Activate();
RClick: 

Name: NewView
Command: Activity.Run("/Scripts/Commands/NewWindowViewBar");WindowsManager.Activate()
RClick: 



Name: Eye Cam
Command: Cam = Node.SubObject("/D3DView", 0);D3DView.SetActiveCamera('/D3DView/' + Cam, '%WIN_ID%');
RClick: Cam = Node.SubObject("/D3DView", 0);UserInterface.OpenToolPanelViewEx2("" , "" ,"/D3DView/" + Cam, 3, 0, 1);



Name: Cam 0
Command: D3DView.SetActiveCamera(Space.CurrentScene() + '/Camera', '%WIN_ID%');
RClick: UserInterface.OpenToolPanelViewEx2("" , "" ,Space.CurrentScene() + '/Camera/Camera', 3, 1, 1);Node.Select(Space.CurrentScene() + '/Camera');

Name: Cam 1
Command: D3DView.SetActiveCamera(Space.CurrentScene() + '/Camera, 1', '%WIN_ID%');D3DView.SetActiveCamera(Space.CurrentScene() + '/Camera,1', '%WIN_ID%');
RClick: UserInterface.OpenToolPanelViewEx2("" , "" ,Space.CurrentScene() + '/Camera, 1/Camera', 3, 1, 1);Node.Select(Space.CurrentScene() + '/Camera, 1');

Name: Cam 2
Command: D3DView.SetActiveCamera(Space.CurrentScene() + '/Camera, 2', '%WIN_ID%');D3DView.SetActiveCamera(Space.CurrentScene() + '/Camera,2', '%WIN_ID%');
RClick: UserInterface.OpenToolPanelViewEx2("" , "" ,Space.CurrentScene() + '/Camera, 2/Camera', 3, 1, 1);Node.Select(Space.CurrentScene() + '/Camera, 2');

Name: Cam 3
Command: D3DView.SetActiveCamera(Space.CurrentScene() + '/Camera, 3', '%WIN_ID%');D3DView.SetActiveCamera(Space.CurrentScene() + '/Camera,3', '%WIN_ID%');
RClick: UserInterface.OpenToolPanelViewEx2("" , "" ,Space.CurrentScene() + '/Camera, 3/Camera', 3, 1, 1);Node.Select(Space.CurrentScene() + '/Camera, 3');

Name: Cam 4
Command: D3DView.SetActiveCamera(Space.CurrentScene() + '/Camera, 4', '%WIN_ID%');D3DView.SetActiveCamera(Space.CurrentScene() + '/Camera,4', '%WIN_ID%');
RClick: UserInterface.OpenToolPanelViewEx2("" , "" ,Space.CurrentScene() + '/Camera, 4/Camera', 3, 1, 1);Node.Select(Space.CurrentScene() + '/Camera, 4');

Name: Cam 5
Command: D3DView.SetActiveCamera(Space.CurrentScene() + '/Camera, 5', '%WIN_ID%');D3DView.SetActiveCamera(Space.CurrentScene() + '/Camera,5', '%WIN_ID%');
RClick: UserInterface.OpenToolPanelViewEx2("" , "" ,Space.CurrentScene() + '/Camera, 5/Camera', 3, 1, 1);Node.Select(Space.CurrentScene() + '/Camera, 5');

Name: Cam 6
Command: D3DView.SetActiveCamera(Space.CurrentScene() + '/Camera, 6', '%WIN_ID%');D3DView.SetActiveCamera(Space.CurrentScene() + '/Camera,6', '%WIN_ID%');
RClick: UserInterface.OpenToolPanelViewEx2("" , "" ,Space.CurrentScene() + '/Camera, 6/Camera', 3, 1, 1);Node.Select(Space.CurrentScene() + '/Camera, 6');



Name: Eye2Cam
Command: Activity.Run("/Scripts/Commands/Eye2Cam");
RClick: Activity.Run("/Scripts/Commands/Position2Eye");



Name: Eye Cam
Command: Cam = Node.SubObject("/D3DView", 0);D3DView.SetActiveCamera('/D3DView/' + Cam, '%WIN_ID%');
RClick: Cam = Node.SubObject("/D3DView", 0);UserInterface.OpenToolPanelViewEx2("" , "" ,"/D3DView/" + Cam, 3, 0, 1);



Name: Copy
Command: Activity.Run("/Scripts/Commands/Copy");
RClick: 



Name: Copy
Command: Activity.Run("/Scripts/Commands/Copy");
RClick: 



Name: Cut
Command: Activity.Run("/Scripts/Commands/Cut");
RClick: 



Name: Paste
Command: Activity.Run("/Scripts/Commands/Paste");
RClick: 



Name: cubeWidget
Command: Node.Delete("/Widgets/Active Widgets Layer2/CubeWidget");Node.Copy("/Widgets/Tools/CubeWidget","/Widgets/Active Widgets Layer2");UserInterface.OpenToolPanelViewEx2("" , "" ,"/Widgets/Active Widgets Layer2/CubeWidget/Cube View Widget", 3,1,0);
RClick: if(Node.Exists("/Widgets/Active Widgets Layer2/CubeWidget")) UserInterface.OpenToolPanelViewEx2("" , "" ,"/Widgets/Active Widgets Layer2/CubeWidget/Cube View Widget", 3,1,0);



Name: Object
Command: RsTool.Arrow();Space.Unselect();
RClick: RsTool.OpenInfoPanel();



Name: Object
Command: RsTool.Arrow();Space.Unselect();
RClick: RsTool.OpenInfoPanel();



Name: Location
Command: RsTool.NormalizeLocation('');
RClick: 



Name: Scale
Command: RsTool.NormalizeSize('');
RClick: 



Name: Rotation
Command: RsTool.NormalizeRotation('');
RClick: 



Name: Reset
Command: RsTool.ResetAxes('');
RClick: 



Name: Axis
Command: RsTool.ShowAxes('');
RClick: RsTool.ToggleValue("/Widgets/Tools/Axes widget/Default/In front");



Name: Flatten
Command: MeshModifiers.FlattenAxes('');
RClick: 



Name: Lasso
Command: MeshModifiers.ActivatePointEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Mesh editor/PE lasso select','Default'); Node.Value('/Preferences/Mesh Editor Settings','PE selection tool') = '/Widgets/Tools/Mesh editor/PE lasso select';UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE lasso select/Lasso select',3,1,0,2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE lasso select/Lasso select',3,1,0,2);



Name: Lasso
Command: MeshModifiers.ActivatePointEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Mesh editor/PE lasso select','Default'); Node.Value('/Preferences/Mesh Editor Settings','PE selection tool') = '/Widgets/Tools/Mesh editor/PE lasso select';UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE lasso select/Lasso select',3,1,0,2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE lasso select/Lasso select',3,1,0,2);



Name: Paint
Command: MeshModifiers.ActivatePointEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Mesh editor/PE basic select','Default'); Node.Value('/Preferences/Mesh Editor Settings','PE selection tool') = '/Widgets/Tools/Mesh editor/PE basic select';
RClick: 



Name: Rectangle
Command: MeshModifiers.ActivatePointEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Mesh editor/PE rect select','Default'); Node.Value('/Preferences/Mesh Editor Settings','PE selection tool') = '/Widgets/Tools/Mesh editor/PE rect select';UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE rect select/Rect select',3,1,0,2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE rect select/Rect select',3,1,0,2);



Name: Lasso
Command: MeshModifiers.ActivatePointEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Mesh editor/PE lasso select','Default'); Node.Value('/Preferences/Mesh Editor Settings','PE selection tool') = '/Widgets/Tools/Mesh editor/PE lasso select';UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE lasso select/Lasso select',3,1,0,2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE lasso select/Lasso select',3,1,0,2);



Name: DynaPick
Command: MeshModifiers.ActivatePointEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Mesh editor/PE dynapick','Default'); Node.Value('/Preferences/Mesh Editor Settings','PE selection tool') = '/Widgets/Tools/Mesh editor/PE dynapick';
RClick: 



Name: Soft
Command: MeshModifiers.ActivatePointEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Mesh editor/PE soft select','Default'); Node.Value('/Preferences/Mesh Editor Settings','PE selection tool') = '/Widgets/Tools/Mesh editor/PE soft select';UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE soft select/Soft select',3,1,0,2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE soft select/Soft select',3,1,0,2);



Name: Invert
Command: MeshModifiers.InvertSelection('');
RClick: 



Name: Invert
Command: MeshModifiers.InvertSelection('');
RClick: 



Name: Connected
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Select tool','apply_cmd:{0502CC2A-7F8C-4d29-BBB4-9F1F2ECDC84C}');
RClick: 



Name: Unselect
Command: MeshModifiers.PeDeselect('');
RClick: 



Name: Materials
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Select tool','apply_cmd:{7BFCBE4C-E2C4-46d6-9A2D-4498053527EC}');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Mesh Editor Settings',9,0,0);



Name: Path
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Select tool','apply_cmd:{7DBD4078-6AC7-48f4-A52D-C4A65CAB0C51};select_invselect');
RClick: 



Name: Grow
Command: MeshModifiers.GrowPointEditSelection('');MeshModifiers.ConvertSelection('','');
RClick: 



Name: Grow
Command: MeshModifiers.GrowPointEditSelection('');MeshModifiers.ConvertSelection('','');
RClick: 



Name: Shrink
Command: MeshModifiers.ShrinkPointEditSelection('');MeshModifiers.ConvertSelection('','');
RClick: 



Name: Convert
Command: MeshModifiers.ConvertSelection('','');
RClick: 



Name: Smooth
Command: MeshModifiers.SmoothPointEditSelection('');
RClick: 



Name: Outline
Command: MeshModifiers.OutlinePointEditSelection('');
RClick: 



Name: Selected
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Rect tool','apply_cmd:{908A59AA-0921-4e53-82EA-0F427904F48E}');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/PE Rect tool/Rect select tool',3,0,0);



Name: Selected
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Rect tool','apply_cmd:{908A59AA-0921-4e53-82EA-0F427904F48E}');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/PE Rect tool/Rect select tool',3,0,0);



Name: Hide
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Rect tool','apply_cmd:{70902786-9BA6-4233-975B-342BA6A274E7}');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/PE Rect tool/Rect select tool',3,0,0);



Name: Unhide
Command: MeshModifiers.ShowHiddenPeGeometry('');
RClick: 



Name: EdgeLoops
Command: Node.Value('/Preferences/Mesh Editor Settings','PE selection mode') = 'edge loop'; MeshModifiers.ActivatePointEditWidget('','','Default');
RClick: 



Name: Context
Command: Node.Value('/Preferences/Mesh Editor Settings','PE selection mode') = 'context'; MeshModifiers.ActivatePointEditWidget('','','Default');
RClick: 



Name: Vertices
Command: Node.Value('/Preferences/Mesh Editor Settings','PE selection mode') = 'vertex'; MeshModifiers.ActivatePointEditWidget('','','Default');
RClick: 



Name: Edges
Command: Node.Value('/Preferences/Mesh Editor Settings','PE selection mode') = 'face edge'; MeshModifiers.ActivatePointEditWidget('','','Default');
RClick: 



Name: Edges
Command: Node.Value('/Preferences/Mesh Editor Settings','PE selection mode') = 'face edge'; MeshModifiers.ActivatePointEditWidget('','','Default');
RClick: 



Name: TriEdges
Command: Node.Value('/Preferences/Mesh Editor Settings','PE selection mode') = 'triangle edge'; MeshModifiers.ActivatePointEditWidget('','','Default');
RClick: 



Name: Faces
Command: Node.Value('/Preferences/Mesh Editor Settings','PE selection mode') = 'face'; MeshModifiers.ActivatePointEditWidget('','','Default');
RClick: 



Name: Faces
Command: Node.Value('/Preferences/Mesh Editor Settings','PE selection mode') = 'face'; MeshModifiers.ActivatePointEditWidget('','','Default');
RClick: 



Name: TriFaces
Command: Node.Value('/Preferences/Mesh Editor Settings','PE selection mode') = 'triangle'; MeshModifiers.ActivatePointEditWidget('','','Default');
RClick: 



Name: EdgeLoops
Command: Node.Value('/Preferences/Mesh Editor Settings','PE selection mode') = 'edge loop'; MeshModifiers.ActivatePointEditWidget('','','Default');
RClick: 



Name: EdgeLoops
Command: Node.Value('/Preferences/Mesh Editor Settings','PE selection mode') = 'edge loop'; MeshModifiers.ActivatePointEditWidget('','','Default');
RClick: 



Name: FaceLoops
Command: Node.Value('/Preferences/Mesh Editor Settings','PE selection mode') = 'face loop'; MeshModifiers.ActivatePointEditWidget('','','Default');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Modeling preferences',4,1,1);



Name: AddVertices
Command: MeshModifiers.ActivatePointEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Mesh editor/PE Vertex draw','Default')
RClick: 



Name: DynaSweep
Command: MeshModifiers.TogglePeTool('/Widgets/Tools/Mesh editor/PE Sweep',''); UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE Sweep/Dynamic Sweep',3,1, 0, 2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE Sweep/Dynamic Sweep',3,1,0,2);



Name: DynaSweep
Command: MeshModifiers.TogglePeTool('/Widgets/Tools/Mesh editor/PE Sweep',''); UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE Sweep/Dynamic Sweep',3,1, 0, 2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE Sweep/Dynamic Sweep',3,1,0,2);



Name: Bevel
Command: MeshModifiers.TogglePeTool('/Widgets/Tools/Mesh editor/PE Bevel',''); UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE Bevel/Bevel tool',3,1,0, 2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE Bevel/Bevel tool',3,1,0, 2);



Name: Sweep
Command: MeshModifiers.ExtrudeSelection('')
RClick: 



Name: Tip
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Select tool','apply_cmd:{D836AAE0-6E0C-48d9-95DC-8FDA120A29DF}');
RClick: 



Name: Modeler
Command: MeshModifiers.AddMirrorModeler('');
RClick: MeshModifiers.ShowMirrorProperties('');



Name: Modeler
Command: MeshModifiers.AddMirrorModeler('');
RClick: MeshModifiers.ShowMirrorProperties('');



Name: Mirror
Command: MeshModifiers.MirrorSelection('');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Mesh Editor Settings',7,0,0);



Name: Copy
Command: MeshModifiers.DuplicateSelection('');
RClick: 



Name: Separate
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Select tool','apply_cmd:{6D90C46D-A984-47fa-8C14-C7ADF45DD882}');
RClick: 



Name: Flip
Command: MeshModifiers.FlipFacesNormals('');
RClick: 



Name: Flip
Command: MeshModifiers.FlipFacesNormals('');
RClick: 



Name: Delete
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Select tool','apply_cmd:{8982C2F3-3070-40e5-9967-E44CFFD1763E}');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Mesh Editor Settings',8,0,0);



Name: FormFace
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Select tool','apply_cmd:{7032EC04-4E22-4e94-8E88-1F0143DCEE33};select_mode:hole');
RClick: 



Name: Vertex Snap
Command: Node.Delete("/Widgets/Active Widgets Layer2/Vertex Snap");Node.Copy("/Widgets/Tools/Vertex Snap","/Widgets/Active Widgets Layer2");UserInterface.OpenToolPanelViewEx2("", "", "Widgets/Active Widgets Layer2/Vertex Snap/Vertex Snap", 4, 0, 0);
RClick: UserInterface.OpenToolPanelViewEx2("", "", "Widgets/Active Widgets Layer2/Vertex Snap/Vertex Snap", 4, 0, 0);



Name: Face Snap
Command: Activity.Run("/Widgets/Tools/Face Snap/save obj ref");
RClick: Activity.Run("/Widgets/Tools/Face Snap/setCopyFlag");



Name: Quadrify
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Select tool','apply_cmd:{3C2CB50B-42E0-47ef-B9A8-A75E6CBCA9F0};select_mode:face');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Mesh Editor Settings',8,0,0);



Name: Split
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Select tool','apply_cmd:{0A28658A-C334-4199-9C30-EB833B77A908}');
RClick: 



Name: Merge
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Select tool','apply_cmd:{3E45513F-2866-457f-82EA-EE9FAC8BD84E}');
RClick: 



Name: SwapEdge
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Select tool','apply_cmd:{09B80301-7C86-4100-824A-C4148A696F1B};select_mode:triangle edge');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Mesh Editor Settings',8,0,0);



Name: Optimize
Command: MeshModifiers.OptimizeTriangulation('');
RClick: 



Name: Quadrify
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Select tool','apply_cmd:{3C2CB50B-42E0-47ef-B9A8-A75E6CBCA9F0};select_mode:face');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Mesh Editor Settings',8,0,0);



Name: AddLoop
Command: MeshModifiers.TogglePeTool('/Widgets/Tools/Mesh editor/PE Add loop',''); UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE Add loop/Add loop',3,1, 0, 2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE Add loop/Add loop',3,1, 0, 2);



Name: AddLoop
Command: MeshModifiers.TogglePeTool('/Widgets/Tools/Mesh editor/PE Add loop',''); UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE Add loop/Add loop',3,1, 0, 2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/PE Add loop/Add loop',3,1, 0, 2);



Name: Collapse
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Select tool','apply_cmd:{E80D376F-7073-4186-88D1-3DA687A13E79}');
RClick: 



Name: Quad
Command: MeshModifiers.Subdivide('');
RClick: 



Name: Smooth
Command: MeshModifiers.Smoothdivide('');
RClick: 



Name: AddVertices
Command: MeshModifiers.ActivatePointEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Mesh editor/PE Vertex draw','Default')
RClick: 



Name: Polydraw
Command: MeshModifiers.ActivatePointEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Mesh editor/PE Poly draw','Default')
RClick: 



Name: AddEdges
Command: MeshModifiers.ActivatePointEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Mesh editor/PE Edge draw','Default')
RClick: 



Name: AddVertices
Command: MeshModifiers.ActivatePointEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Mesh editor/PE Vertex draw','Default')
RClick: 



Name: Bridge
Command: MeshModifiers.ActivatePointEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Mesh editor/PE bridge tool','Default'); UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/PE bridge tool/Bridge tool',3,1,1);
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/PE bridge tool/Bridge tool',3,1,1);



Name: Bridge
Command: MeshModifiers.ActivatePointEditWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Mesh editor/PE bridge tool','Default'); UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/PE bridge tool/Bridge tool',3,1,1);
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/PE bridge tool/Bridge tool',3,1,1);



Name: Weld
Command: MeshModifiers.ApplySelectionTool('/Widgets/Tools/Mesh editor/PE Rect tool','apply_cmd:{87B113FD-B879-4b63-9C9A-28A38AED253B}');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/PE Rect tool/Rect select tool',3,0,0);



Name: Heal
Command: MeshModifiers.HealVertices('',-1);
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Mesh Editor Settings',6,0,0);



Name: Scissors
Command: MeshModifiers.Scissors('');
RClick: 



Name: fixBadGeometrytPanel
Command: WindowsManager.CloseWindow("/Project/Windows Manager Space/FBG_PanelFrame");Node.Copy("/Widgets/Tools/Fix Bad Geometry/FBG_PanelFrame", "/Project/Windows Manager Space");WindowsManager.Activate();WindowsManager.UpdateWindowsStructure();
RClick: 



Name: SelectAll
Command: Node.Value('/Preferences/Mesh Editor Settings','PE selection style') = 0;
RClick: 



Name: Visible
Command: Node.Value('/Preferences/Mesh Editor Settings','PE selection style') = 1;
RClick: 



Name: SelectAll
Command: Node.Value('/Preferences/Mesh Editor Settings','PE selection style') = 0;
RClick: 



Name: - SDS
Command: MeshModifiers.ChangeSSLevel(-1)
RClick: 



Name: Soft paint
Command: MeshModifiers.TogglePeTool('/Widgets/Tools/Mesh editor/PE soft paint','');UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/PE soft paint/Soft paint',3,1,0);
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/PE soft paint/Soft paint',3,1,0);



Name: - SDS
Command: MeshModifiers.ChangeSSLevel(-1)
RClick: 



Name: + SDS
Command: MeshModifiers.ChangeSSLevel(1)
RClick: 



Name: - SDS
Command: MeshModifiers.ChangeSSLevel(-1)
RClick: 



Name: ResetSDS
Command: MeshModifiers.ResetSds('',-1,-1,-1)
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Mesh Editor Settings',10,0,0);



Name: SDSVertex
Command: Widgets.ReplaceWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Mesh editor/PE vertex weight','Default','','')
RClick: 



Name: SDSEdge
Command: Widgets.ReplaceWidget('{E8913C00-9A2A-43cf-8238-27B4BFB50A1F}','/Widgets/Tools/Mesh editor/PE edge weight','Default','','')
RClick: 



Name: Normalmap
Command: MeshModifiers.BuildNormalmap('')
RClick: 



Name: Normalmap
Command: MeshModifiers.BuildNormalmap('')
RClick: 



Name: Simplify
Command: MeshModifiers.SimplifyMesh('')
RClick: 



Name: Union
Command: MeshModifiers.ActivateBooleansTool('Union','')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/Booleans tool/Booleans',3,1,0);



Name: Union
Command: MeshModifiers.ActivateBooleansTool('Union','')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/Booleans tool/Booleans',3,1,0);



Name: Intersection
Command: MeshModifiers.ActivateBooleansTool('Intersection','')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/Booleans tool/Booleans',3,1,0);



Name: Subtract
Command: MeshModifiers.ActivateBooleansTool('Subtraction','')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/Booleans tool/Booleans',3,1,0);



Name: Cut
Command: MeshModifiers.ActivateBooleansTool('Cut','')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/Booleans tool/Booleans',3,1,0);



Name: Merge
Command: MeshModifiers.ActivateBooleansTool('Merge','')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/Booleans tool/Booleans',3,1,0);



Name: Merge
Command: MeshModifiers.ActivateBooleansTool('Merge','')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/Booleans tool/Booleans',3,1,0);



Name: Add
Command: MeshModifiers.ActivateBooleansTool('Add','')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Mesh editor/Booleans tool/Booleans',3,1,0);



Name: DisBrush
Command: MeshModifiers.EnableDisplacementBrush();UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/DM Brush/Displacement Brush',4,1,0,2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/DM Brush/Displacement Brush',4,1,0,2);



Name: DisBrush
Command: MeshModifiers.EnableDisplacementBrush();UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Mesh editor/DM Brush/Displacement Brush',4,1,0,2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/DM Brush/Displacement Brush',4,1,0,2);



Name: DisMap
Command: MeshModifiers.DisplacementMapping('');
RClick: 



Name: Length
Command: MeshModifiers.EnableHairBrush('{A7782DD7-DD86-4cbe-A562-E345805E59AB}');UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Hair/Hair Length Brush/Hair Length',3,1,0,2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Hair/Hair Length Brush/Hair Length',3,1,0,2);



Name: Length
Command: MeshModifiers.EnableHairBrush('{A7782DD7-DD86-4cbe-A562-E345805E59AB}');UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Hair/Hair Length Brush/Hair Length',3,1,0,2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Hair/Hair Length Brush/Hair Length',3,1,0,2);



Name: Blowdryer
Command: MeshModifiers.EnableHairBrush('{24C5D7C9-0A06-40f5-95F3-7BE7DC4177F8}');UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Hair/Hair Blowdryer/Hair Blowdryer',3,1,0,2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Hair/Hair Blowdryer/Hair Blowdryer',3,1,0,2);



Name: Softness
Command: MeshModifiers.EnableHairBrush('{A8A8F8B0-993C-4cd0-82AE-18B39BDA000F}');UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Hair/Hair Softness Brush/Hair Softness',3,1,0,2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Hair/Hair Softness Brush/Hair Softness',3,1,0,2);



Name: Direction
Command: MeshModifiers.EnableHairBrush('{CA36494D-CC50-436b-B5B3-4F16FB8422C9}');UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Hair/Hair Direction Brush/Hair Direction',3,1,0,2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Hair/Hair Direction Brush/Hair Direction',3,1,0,2);



Name: Density
Command: MeshModifiers.EnableHairBrush('{7DB4D6AE-8BFA-41dc-A9F7-4BB7916FD6D7}');UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Hair/Hair Density Brush/Hair Density',3,1,0,2);
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Hair/Hair Density Brush/Hair Density',3,1,0,2);



Name: M.Editor
Command: MeshModifiers.OpenMaterialEditor()
RClick: 



Name: M.Editor
Command: MeshModifiers.OpenMaterialEditor()
RClick: 



Name: Inspect
Command: MeshModifiers.OpenMaterialEditor();MeshModifiers.ToggleTool('/Widgets/Tools/Material editor/Inspect')
RClick: MeshModifiers.OpenMaterialEditor()



Name: Inspect
Command: MeshModifiers.OpenMaterialEditor();MeshModifiers.ToggleTool('/Widgets/Tools/Material editor/Inspect')
RClick: MeshModifiers.OpenMaterialEditor()



Name: Objects
Command: MeshModifiers.OpenMaterialEditor();MeshModifiers.SetMaterial('')
RClick: MeshModifiers.OpenMaterialEditor()



Name: Faces
Command: MeshModifiers.OpenMaterialEditor();MeshModifiers.StartPaintFaceTool()
RClick: MeshModifiers.OpenMaterialEditor()



Name: Repaint
Command: MeshModifiers.OpenMaterialEditor();MeshModifiers.ToggleTool('/Widgets/Tools/Material editor/Repaint')
RClick: MeshModifiers.OpenMaterialEditor()



Name: UV Editor 
Command: UVEditor.Open('%THIS_BUTTON_ITEM%')
RClick: UserInterface.OpenToolPanelViewEx2('', '','Preferences/UV Editor Preferences',3, 1, 0)



Name: Cubic
Command: UVEditor.ToggleUvProjection('Cubic','')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/UV mapping/Projection tool/UV Projection tool',3,0,0);



Name: Spherical
Command: UVEditor.ToggleUvProjection('Spherical','')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/UV mapping/Projection tool/UV Projection tool',3,0,0);



Name: Planar
Command: UVEditor.ToggleUvProjection('Planar','')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/UV mapping/Projection tool/UV Projection tool',3,0,0);



Name: Cylindrical
Command: UVEditor.ToggleUvProjection('Cylindrical','')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/UV mapping/Projection tool/UV Projection tool',3,0,0);



Name: Cubic
Command: UVEditor.ToggleUvProjection('Cubic','')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/UV mapping/Projection tool/UV Projection tool',3,0,0);



Name: ShrinkUV
Command: MeshModifiers.ShrinkWrap('')
RClick: UserInterface.OpenToolPanelViewEx2('', '','Preferences/Shrink Wrap preferences',3, 1, 0);



Name: Smooth
Command: MeshModifiers.SmoothNormals('')
RClick: 



Name: Smooth
Command: MeshModifiers.SmoothNormals('')
RClick: 



Name: AutoFacet
Command: MeshModifiers.AutofacetNormals('',-1)
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Mesh Editor Settings',5,0,0);



Name: Facet
Command: MeshModifiers.FacetedNormals('')
RClick: 



Name: +PhysAttr
Command: Physics.AddPhysAttr('');Physics.OpenNodePanel('phys', 3)
RClick: Physics.OpenNodePanel('phys', 3)



Name: +PhysAttr
Command: Physics.AddPhysAttr('');Physics.OpenNodePanel('phys', 3)
RClick: Physics.OpenNodePanel('phys', 3)



Name: +PhysAttr
Command: Physics.AddPhysAttr('');Physics.OpenNodePanel('phys', 3)
RClick: Physics.OpenNodePanel('phys', 3)



Name: +LocalEnv
Command: Physics.AddEnvAttr('');Physics.OpenNodePanel('phys', 3)
RClick: Physics.OpenNodePanel('env', 3)



Name: +ClothAttr
Command: Physics.AddClothAttr('');Physics.OpenNodePanel('phys', 3)
RClick: Physics.OpenNodePanel('cloth', 3)



Name: -PhysAttr
Command: Physics.RemovePhysAttr('')
RClick: 



Name: -LocalEnv
Command: Physics.RemoveEnvAttr('')
RClick: 



Name: -ClothAttr
Command: Physics.RemoveClothAttr('')
RClick: 



Name: Speed
Command: Physics.ActivatePhysWidget('SpeedWidget')
RClick: Physics.OpenNodePanel('phys', 4)



Name: Speed
Command: Physics.ActivatePhysWidget('SpeedWidget')
RClick: Physics.OpenNodePanel('phys', 4)



Name: Rotation
Command: Physics.ActivatePhysWidget('RotationWidget')
RClick: Physics.OpenNodePanel('phys', 4)



Name: A.Speed
Command: Physics.ActivatePhysWidget('AccWidget')
RClick: Physics.OpenNodePanel('phys', 5)



Name: A.Rotation
Command: Physics.ActivatePhysWidget('RotAccWidget')
RClick: Physics.OpenNodePanel('phys', 5)



Name: COG
Command: Physics.ActivatePhysWidget('CogWidget')
RClick: Physics.OpenNodePanel('phys', 7)



Name: COG
Command: Physics.ActivatePhysWidget('CogWidget')
RClick: Physics.OpenNodePanel('phys', 7)



Name: FixPoint1
Command: Physics.ActivatePhysWidget('Fix1Widget')
RClick: Physics.OpenNodePanel('phys', 7)



Name: FixPoint2
Command: Physics.ActivatePhysWidget('Fix2Widget')
RClick: Physics.OpenNodePanel('phys', 7)



Name: ClothFix
Command: Physics.ActivatePhysWidget('ClothFixWidget')
RClick: Physics.ActivatePhysWidget('ClothFixWidget');Physics.ResetClothFixation('')



Name: WindLocal
Command: Physics.AddWind('', true)
RClick: 



Name: WindLocal
Command: Physics.AddWind('', true)
RClick: 



Name: WindGlobal
Command: Physics.AddWind('', false)
RClick: 



Name: EnviLocal
Command: Physics.ActivatePhysWidget('LocEnvWidget')
RClick: Physics.OpenNodePanel('env', 3)



Name: Gravity
Command: Physics.ActivatePhysWidget('GravityWidget')
RClick: Physics.OpenNodePanel('space', 3)



Name: HealSkin
Command: CharacterEditor.HealSkin('');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Character editor preferences',7,1,1);



Name: Skeleton
Command: CharacterEditor.ActivateCharacterToolEx('/Widgets/Tools/Character editor/Skeleton tool','Default','{62E8596C-448F-4967-A317-516B044E80FB}{70F07F89-0410-41c4-803C-64C712261727}{/Preferences/Character editor preferences}','/Preferences/Character editor preferences/Joint marker');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Character editor preferences',6,1,1);



Name: Skeleton
Command: CharacterEditor.ActivateCharacterToolEx('/Widgets/Tools/Character editor/Skeleton tool','Default','{62E8596C-448F-4967-A317-516B044E80FB}{70F07F89-0410-41c4-803C-64C712261727}{/Preferences/Character editor preferences}','/Preferences/Character editor preferences/Joint marker');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Character editor preferences',6,1,1);



Name: DelJoint
Command: CharacterEditor.RemoveJoint('');
RClick: 



Name: ShapeSkel
Command: CharacterEditor.ActivateCharacterTool('/Widgets/Edit/Character editor widget');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Character editor preferences',3, 1, 1);



Name: -Limb
Command: CharacterEditor.RemoveLimb('');
RClick: 



Name: ResetPose
Command: CharacterEditor.ResetPose('');
RClick: 



Name: Limits
Command: CharacterEditor.ActivateCharacterTool('/Widgets/Edit/Joint limits');
RClick: CharacterEditor.EditJointsDirectly('');



Name: SetPose
Command: CharacterEditor.SetDefaultPose('');
RClick: 



Name: ResetPose
Command: CharacterEditor.ResetPose('');
RClick: 



Name: Envelope
Command: CharacterEditor.ActivateCharacterTool('/Widgets/Tools/Character editor/CE bone envelope tool');
RClick: 



Name: Envelope
Command: CharacterEditor.ActivateCharacterTool('/Widgets/Tools/Character editor/CE bone envelope tool');
RClick: 



Name: Skin2Bone
Command: CharacterEditor.ActivateCharacterTool('/Widgets/Tools/Character editor/Attach objects as a skin');
RClick: 



Name: Skin2Skeleton
Command: CharacterEditor.ActivateCharacterTool('/Widgets/Tools/Character editor/Attach skin to skeleton'); UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Character editor/Attach skin to skeleton/Attach skin to skeleton',3,1,1, 2); 
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Character editor/Attach skin to skeleton/Attach skin to skeleton',3,1,1, 2);



Name: Object2Bone
Command: CharacterEditor.ActivateCharacterTool('/Widgets/Tools/Character editor/Attach objects to bone');
RClick: 



Name: HealSkin
Command: CharacterEditor.HealSkin('');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Character editor preferences',7,1,1);



Name: Weight
Command: CharacterEditor.ActivateEditModeTool('/Widgets/Edit/Helpers/CE Weight paint','/Widgets/Tools/Character editor/CE Weight paint tool','&pref:/Widgets/Tools/Character editor/CE Weight paint tool/Weight paint&tag:brush');
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Character editor/CE Weight paint tool/Weight paint',3,1,1, 2);



Name: HealSkin
Command: CharacterEditor.HealSkin('');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Character editor preferences',7,1,1);



Name: Skin2Sel
Command: CharacterEditor.SkinToSelection('');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Mesh Editor Settings',3,1,1);



Name: Sel2Skin
Command: CharacterEditor.SelectionToSkin('');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Character editor preferences',8,1,1);



Name: Transfer
Command: CharacterEditor.ActivateEditModeTool('/Widgets/Edit/Helpers/CE Weight paint','/Widgets/Tools/Character editor/Skin transfer','&pref:/Widgets/Tools/Character editor/Skin transfer/Skin transfer&tag:transfer'); 
RClick: UserInterface.OpenToolPanelViewEx2WithFlag('', '','/Widgets/Tools/Character editor/Skin transfer/Skin transfer',3,1,1, 2); 



Name: Pos.Lock
Command: CharacterEditor.ActivateCharacterToolEx('/Widgets/Tools/Character editor/Edit IK lock','Default','iklockpos.rsobj','%SKELETON%');
RClick: 



Name: Pos.Lock
Command: CharacterEditor.ActivateCharacterToolEx('/Widgets/Tools/Character editor/Edit IK lock','Default','iklockpos.rsobj','%SKELETON%');
RClick: 



Name: Rot.Lock
Command: CharacterEditor.ActivateCharacterToolEx('/Widgets/Tools/Character editor/Edit IK lock','Default','iklockrot.rsobj','%SKELETON%');
RClick: 



Name: FullLock
Command: CharacterEditor.ActivateCharacterToolEx('/Widgets/Tools/Character editor/Edit IK lock','Default','iklockfull.rsobj','%SKELETON%');
RClick: 



Name: ModIkHndl
Command: CharacterEditor.ActivateCharacterToolEx('/Widgets/Tools/Character editor/Edit Ik Motion Ctrl','Default','ikmchandle.rsobj','%SKELETON%');
RClick: 



Name: AlignHndl
Command: CharacterEditor.ActivateCharacterTool('/Widgets/Tools/Character editor/IK handle align');
RClick: 



Name: +Morph
Command: CharacterEditor.AddMorph('');
RClick: CharacterEditor.ShowMorphPanel('');



Name: C. Toolbar
Command: WindowsManager.CloseWindow("/Project/Windows Manager Space/Custom Toolbar Frame");RsFileIO.LoadObject(System.GetMainDir() + '\\Scripts\\preobjects\\Custom Toolbar Frame.RsObj', "/Project/Windows Manager Space/");Node.Value("/Project/Windows Manager Space/Custom Toolbar Frame", "SnappedTo") = WindowsManager.GetWorkWindow();Node.Value("/Project/Windows Manager Space/Custom Toolbar Frame", "OwnedBy") = WindowsManager.GetWorkWindow();WindowsManager.Activate();WindowsManager.UpdateWindowsStructure();
RClick: WindowsManager.CloseWindow("/Project/Windows Manager Space/Custom_Toolbar_Pref_Panel_Frame");Node.Copy("/Widgets/Tools/Custom Toolbar Preferences/Custom_Toolbar_Pref_Panel_Frame", "/Project/Windows Manager Space");WindowsManager.Activate();WindowsManager.UpdateWindowsStructure();



Name: X lock
Command: RsTool.ToggleValue('/Preferences/Snapping/Enable X');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Snapping',5,1,1);



Name: Y lock
Command: RsTool.ToggleValue('/Preferences/Snapping/Enable Y');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Snapping',5,1,1);



Name: Z lock
Command: RsTool.ToggleValue('/Preferences/Snapping/Enable Z');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Snapping',5,1,1);



Name: Undo
Command: RsApp.Undo()
RClick: 



Name: Undo
Command: RsApp.Undo()
RClick: 



Name: Redo
Command: RsApp.Redo()
RClick: 



Name: PointEdit
Command: RsTool.ToggleValue('/Preferences/Snapping/Vertex snapping');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Snapping/Point edit snapping',3,1,0)



Name: SnapToGrid
Command: RsTool.ToggleValue('/Preferences/Snapping/Grid snapping');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Snapping',4,1,1);



Name: DistFb
Command: RsTool.ToggleValue('/Preferences/Snapping/Distances');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Snapping',6,1,1);



Name: PointEdit
Command: RsTool.ToggleValue('/Preferences/Snapping/Vertex snapping');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Snapping/Point edit snapping',3,1,0)



Name: Unencaps
Command: LE.Unencapsulate('')
RClick: 



Name: 3D Encapsulate
Command: LE.RectEncapsulationDialog('{5B3DD4D4-BD80-480A-BFD8-0B3A19DF1558}', true)
RClick: 



Name: Encapsulate
Command: LE.RectEncapsulationDialog('{5B3DD4D4-BD80-480A-BFD8-0B3A19DF1558}', false)
RClick: 



Name: Flatten
Command: MeshModifiers.FlattenNodes('')
RClick: 



Name: Unencaps
Command: LE.Unencapsulate('')
RClick: 



Name: 3D Encapsulate
Command: LE.RectEncapsulationDialog('{5B3DD4D4-BD80-480A-BFD8-0B3A19DF1558}', true)
RClick: 



Name: 3D Encapsulate
Command: Activity.Run("/Scripts/Commands/Unglue");
RClick: 



Name: 3D Encapsulate
Command: LE.RectEncapsulationDialog('{5B3DD4D4-BD80-480A-BFD8-0B3A19DF1558}', true)
RClick: 



Name: Physical simulation
Command: Physics.init_PhysSim()
RClick: Physics.OpenPanel()



Name: Set Camera
Command: D3DView.SetActiveCamera('', '')
RClick: 



Name: Set Camera
Command: D3DView.SetActiveCamera('', '')
RClick: 



Name: Set Camera
Command: D3DView.SetActiveCamera('', '')
RClick: 



Name: Isometric 
Command: D3DView.SwitchEyeCameraType('', '7')
RClick: 



Name: Perspective
Command: D3DView.SwitchEyeCameraType('', '0')
RClick: 



Name: Perspective
Command: D3DView.SwitchEyeCameraType('', '0')
RClick: 



Name: Nearest ortho
Command: RsTool.SetNearestOrthoView('');
RClick: 



Name: Top
Command: D3DView.SwitchEyeCameraType('', '2')
RClick: 



Name: Top
Command: D3DView.SwitchEyeCameraType('', '2')
RClick: 



Name: Bottom
Command: D3DView.SwitchEyeCameraType('', '1')
RClick: 



Name: Front
Command: D3DView.SwitchEyeCameraType('', '6')
RClick: 



Name: Front
Command: D3DView.SwitchEyeCameraType('', '6')
RClick: 



Name: Back
Command: D3DView.SwitchEyeCameraType('', '5')
RClick: 



Name: Left
Command: D3DView.SwitchEyeCameraType('', '3')
RClick: 



Name: Left
Command: D3DView.SwitchEyeCameraType('', '3')
RClick: 



Name: Right
Command: D3DView.SwitchEyeCameraType('', '4')
RClick: 



Name: Opaque
Command: D3DView.LoadRAPreset('', 1.0, 0.0, '', '')
RClick: 



Name: Opaque
Command: D3DView.LoadRAPreset('', 1.0, 0.0, '', '')
RClick: 



Name: Opaque
Command: D3DView.LoadRAPreset('', 1.0, 0.0, '', '')
RClick: 



Name: OpaqueWires
Command: D3DView.LoadRAPreset('', 1.0, 1.0, '', '')
RClick: 



Name: Transp
Command: D3DView.LoadRAPreset('', 0.5, 0.0, '', '')
RClick: 



Name: TranspWires
Command: D3DView.LoadRAPreset('', 0.6, 1.0, '', '')
RClick: 



Name: Wires
Command: D3DView.LoadRAPreset('', 0.0, 1.0, '', '')
RClick: 



Name: Wireframe Grid
Command: D3DView.LoadRAPreset('', -1.0, -1.0, 'Wire', '')
RClick: 



Name: Wireframe Grid
Command: D3DView.LoadRAPreset('', -1.0, -1.0, 'Wire', '')
RClick: 



Name: Opaque Grid
Command: D3DView.LoadRAPreset('', -1.0, -1.0, 'Solid','')
RClick: 



Name: No Grid
Command: D3DView.LoadRAPreset('', -1.0, -1.0, 'None', '')
RClick: 



Name: HideAll
Command: Activity.Run("/Scripts/Commands/HideAll");
RClick: 



Name: HideAll
Command: Activity.Run("/Scripts/Commands/HideAll");
RClick: 



Name: ShowAll
Command: Activity.Run("/Scripts/Commands/ShowAll");
RClick: 



Name: Hide
Command: Activity.Run("/Scripts/Commands/Hide");
RClick: if(Node.Exists(Node.FirstSelected() + "/Object Render Attributes")){UserInterface.OpenToolPanelViewEx2("" , "" , Node.FirstSelected() + "/Object Render Attributes", 3,1,0);};



Name: Hide
Command: Activity.Run("/Scripts/Commands/Hide");
RClick: if(Node.Exists(Node.FirstSelected() + "/Object Render Attributes")){UserInterface.OpenToolPanelViewEx2("" , "" , Node.FirstSelected() + "/Object Render Attributes", 3,1,0);};



Name: Show
Command: Activity.Run("/Scripts/Commands/Show");
RClick: if(Node.Exists(Node.FirstSelected() + "/Object Render Attributes")){UserInterface.OpenToolPanelViewEx2("" , "" , Node.FirstSelected() + "/Object Render Attributes", 3,1,0);};



Name: New scene
Command: Space.NewScene()
RClick: LE.OpenLocation(Space.CurrentScene())



Name: New scene
Command: Space.NewScene()
RClick: LE.OpenLocation(Space.CurrentScene())



Name: Reset Default
Command: var Yes = System.Question("Would you like to Reset the Default Context?");if (Yes){RsApp.Reset();}else;
RClick: 



Name: Default context backup
Command: RsFileIO.SaveSystem('', '', 'Manually saved system', 0)
RClick: 



Name: Reset Default
Command: var Yes = System.Question("Would you like to Reset the Default Context?");if (Yes){RsApp.Reset();}else;
RClick: 



Name: World
Command: Node.Value('/Preferences/Modeling preferences','Coordinate system') = 'World';
RClick: 

Name: World
Command: Node.Value('/Preferences/Modeling preferences','Coordinate system') = 'World';
RClick: 

Name: Object
Command: Node.Value('/Preferences/Modeling preferences','Coordinate system') = 'Local';
RClick: 

Name: Tangent
Command: Node.Value('/Preferences/Modeling preferences','Coordinate system') = 'Tangent';
RClick: 

Name: Screen
Command: Node.Value('/Preferences/Modeling preferences','Coordinate system') = 'Screen';
RClick: 


Name: Plane
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Primitive tool','{1ABE09E8-F22F-46b3-9F8A-7F08B0FFF297}(/Preferences/Primitives/Matrix manager){C89E0C6B-3F82-4fe2-A232-FB1A7B7F6190}(/Preferences/Primitives/Factory preferences){/Preferences/Primitives/Preferences}','/Preferences/Primitives/Plane');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Primitives',12,1,1);

Name: Cube
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Primitive tool','{EEC8FEE8-EB12-4e12-8ED0-D71CAA2886FD}(/Preferences/Primitives/Matrix manager){C89E0C6B-3F82-4fe2-A232-FB1A7B7F6190}(/Preferences/Primitives/Factory preferences){/Preferences/Primitives/Preferences}','/Preferences/Primitives/Cube');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Primitives',10,1,1);

Name: Sphere
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Primitive tool','{5DB1D6C0-877C-4a84-8FF1-B5AB4E34519D}(/Preferences/Primitives/Rotation manager){C89E0C6B-3F82-4fe2-A232-FB1A7B7F6190}(/Preferences/Primitives/Factory preferences){/Preferences/Primitives/Preferences}','/Preferences/Primitives/Sphere');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Primitives',8,1,1);

Name: Cylinder
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Primitive tool','{A955CABA-CA6F-40c0-AE78-010D283ED1C5}(/Preferences/Primitives/Rotation manager){C89E0C6B-3F82-4fe2-A232-FB1A7B7F6190}(/Preferences/Primitives/Factory preferences){/Preferences/Primitives/Preferences}','/Preferences/Primitives/Cylinder');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Primitives',6,1,1);

Name: Torus
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Primitive tool','{A955CABA-CA6F-40c0-AE78-010D283ED1C5}(/Preferences/Primitives/Rotation manager){C89E0C6B-3F82-4fe2-A232-FB1A7B7F6190}(/Preferences/Primitives/Factory preferences){/Preferences/Primitives/Preferences}','/Preferences/Primitives/Torus');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Primitives',9,1,1);

Name: Plane
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Primitive tool','{1ABE09E8-F22F-46b3-9F8A-7F08B0FFF297}(/Preferences/Primitives/Matrix manager){C89E0C6B-3F82-4fe2-A232-FB1A7B7F6190}(/Preferences/Primitives/Factory preferences){/Preferences/Primitives/Preferences}','/Preferences/Primitives/Plane');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Primitives',12,1,1);

Name: Cone
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Primitive tool','{A955CABA-CA6F-40c0-AE78-010D283ED1C5}(/Preferences/Primitives/Rotation manager){C89E0C6B-3F82-4fe2-A232-FB1A7B7F6190}(/Preferences/Primitives/Factory preferences){/Preferences/Primitives/Preferences}','/Preferences/Primitives/Cone');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Primitives',11,1,1);

Name: Text
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Primitive tool','{0422ED97-497D-4623-A209-ABC4335F0380}{C89E0C6B-3F82-4fe2-A232-FB1A7B7F6190}(/Preferences/Primitives/Factory preferences){/Preferences/Primitives/Preferences}','/Preferences/Primitives/Text');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Primitives',4,1,1);

Name: Camera
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Primitive tool','{B1D12AD1-47D4-4e6c-8227-DC80FF55D7BB}{A46795D3-0DE2-4ed8-9FB6-91D84FB9F1EB}(/Preferences/Cameras/Factory preferences){/Preferences/Lights/Preferences}','/Preferences/Cameras/Camera');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Cameras',3,1,1);

Name: EntryPoint
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Primitive tool','{B1D12AD1-47D4-4e6c-8227-DC80FF55D7BB}{A46795D3-0DE2-4ed8-9FB6-91D84FB9F1EB}(/Preferences/Cameras/Factory preferences){/Preferences/Lights/Preferences}','/Preferences/Cameras/EntryPoint');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Cameras',3,1,1);

Name: Ambient
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Light tool','{B1D12AD1-47D4-4e6c-8227-DC80FF55D7BB}{A46795D3-0DE2-4ed8-9FB6-91D84FB9F1EB}(/Preferences/Lights/Factory preferences){/Preferences/Lights/Preferences}','/Preferences/Lights/Ambient');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Lights',3,1,1);

Name: Omni
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Light tool','{B1D12AD1-47D4-4e6c-8227-DC80FF55D7BB}{A46795D3-0DE2-4ed8-9FB6-91D84FB9F1EB}(/Preferences/Lights/Factory preferences){/Preferences/Lights/Preferences}','/Preferences/Lights/Omni');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Lights',3,1,1);

Name: Infinite
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Light tool','{B1D12AD1-47D4-4e6c-8227-DC80FF55D7BB}{A46795D3-0DE2-4ed8-9FB6-91D84FB9F1EB}(/Preferences/Lights/Factory preferences){/Preferences/Lights/Preferences}','/Preferences/Lights/Infinite');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Lights',3,1,1);

Name: Projector
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Light tool','{B1D12AD1-47D4-4e6c-8227-DC80FF55D7BB}{A46795D3-0DE2-4ed8-9FB6-91D84FB9F1EB}(/Preferences/Lights/Factory preferences){/Preferences/Lights/Preferences}','/Preferences/Lights/Projector');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Lights',3,1,1);

Name: Sky
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Light tool','{B1D12AD1-47D4-4e6c-8227-DC80FF55D7BB}{A46795D3-0DE2-4ed8-9FB6-91D84FB9F1EB}(/Preferences/Lights/Factory preferences){/Preferences/Lights/Preferences}','/Preferences/Lights/Sky');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Lights',3,1,1);

Name: Directional
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Light tool','{B1D12AD1-47D4-4e6c-8227-DC80FF55D7BB}{A46795D3-0DE2-4ed8-9FB6-91D84FB9F1EB}(/Preferences/Lights/Factory preferences){/Preferences/Lights/Preferences}','/Preferences/Lights/Directional');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Lights',3,1,1);

Name: Ambient
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Light tool','{B1D12AD1-47D4-4e6c-8227-DC80FF55D7BB}{A46795D3-0DE2-4ed8-9FB6-91D84FB9F1EB}(/Preferences/Lights/Factory preferences){/Preferences/Lights/Preferences}','/Preferences/Lights/Ambient');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Lights',3,1,1);

Name: Area
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Light tool','{B1D12AD1-47D4-4e6c-8227-DC80FF55D7BB}{A46795D3-0DE2-4ed8-9FB6-91D84FB9F1EB}(/Preferences/Lights/Factory preferences){/Preferences/Lights/Preferences}','/Preferences/Lights/Area');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Lights',3,1,1);

Name: Spot
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Light tool','{B1D12AD1-47D4-4e6c-8227-DC80FF55D7BB}{A46795D3-0DE2-4ed8-9FB6-91D84FB9F1EB}(/Preferences/Lights/Factory preferences){/Preferences/Lights/Preferences}','/Preferences/Lights/Spot');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Lights',3,1,1);



Name: Render Scene
Command: OfflineRender.OpenView('',0,0);OfflineRender.RenderScene('')
RClick: OfflineRender.OpenPreferencesPanel()

Name: Render Scene
Command: OfflineRender.OpenView('',0,0);OfflineRender.RenderScene('')
RClick: OfflineRender.OpenPreferencesPanel()

Name: Render Area
Command: Widgets.ReplaceWidget('{88839603-7F98-41f0-96AC-BE94E801CFF3}','/Widgets/Tools/Offline render/Area scene render','Default','','dummy')
RClick: OfflineRender.OpenPreferencesPanel()

Name: Render Object
Command: OfflineRender.OpenView('',0,0);OfflineRender.RenderObject('')
RClick: OfflineRender.OpenPreferencesPanel()

Name: Render Animation
Command: OfflineRender.OpenView('',0,0);OfflineRender.RenderAnimation('')
RClick: OfflineRender.OpenPreferencesPanel()



Name: FP navigation
Command: Avatar.ActivateFpnToView('');
RClick: Avatar.ShowFpnProperties();



Name: FP navigation
Command: Avatar.ActivateFpnToView('');
RClick: Avatar.ShowFpnProperties();



Name: Move Cam
Command: Widgets.ActivateViewToolWidget('/Widgets/Tools/View tools/Camera move','Default');
RClick: 



Name: Rotate Cam
Command: Widgets.ActivateViewToolWidget('/Widgets/Tools/View tools/Camera rotate','Default');
RClick: 



Name: Fov Cam
Command: Widgets.ActivateViewToolWidget('/Widgets/Tools/View tools/Camera fov','Default');
RClick: 



Name: Rect zoom
Command: Widgets.ActivateViewToolWidget('/Widgets/Tools/View tools/Rect zoom','Default')
RClick: 



Name: Reset
Command: RsTool.ResetView('');
RClick: 



Name: Reset
Command: RsTool.ResetView('');
RClick: 



Name: Look at Selection
Command: RsTool.LookAtSelection('');
RClick: 



Name: DynaPose
Command: CharacterEditor.ActivateCharacterTool('/Widgets/Tools/Character editor/Dynamic pose'); UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Character editor/Dynamic pose/Character Posing',3,1,0);
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Character editor/Dynamic pose/Character Posing',3,1,0);



Name: DynaPose
Command: CharacterEditor.ActivateCharacterTool('/Widgets/Tools/Character editor/Dynamic pose'); UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Character editor/Dynamic pose/Character Posing',3,1,0);
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Widgets/Tools/Character editor/Dynamic pose/Character Posing',3,1,0);



Name: PhysMove
Command: Physics.ActivatePhysWidget('PhysMoveWidget')
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Phys Move Preferences',3,1,0);



Name: Move
Command: Widgets.ActivateViewToolWidget('/Widgets/Tools/Move selection','Default');
RClick: 



Name: Rotate
Command: Widgets.ActivateViewToolWidget('/Widgets/Tools/Rotate selection','Default');
RClick: 



Name: Scale
Command: Widgets.ActivateViewToolWidget('/Widgets/Tools/Scale selection','Default');
RClick: 



Name: Look At
Command: ToolMng.ActivateTool('{17D544A3-3F58-436B-83E7-F8B4D7D4E7C5}','{4E203C6C-A20D-4e32-82B4-FC482F5A0D06}' )
RClick: 



Name: UnLook At
Command: Activity.Run("/Scripts/Commands/UnLookAt");
RClick: 



Name: Look At
Command: ToolMng.ActivateTool('{17D544A3-3F58-436B-83E7-F8B4D7D4E7C5}','{4E203C6C-A20D-4e32-82B4-FC482F5A0D06}' )
RClick: 



Name: Library browser
Command: Library2.ShowLibraryBrowserWindow()
RClick: 



Name: Output Console
Command: CmdPrompt.DebugView('Windows Manager Space', 0)
RClick: 



Name: Copy Window
Command: WindowsManager.CopyWindow('')
RClick: 



Name: LE Window
Command: WindowsManager.CreateWindowFromCLSIDEx('default', 'default', 'default', '[Scene]', 1, '2D')
RClick: 



Name: Command Prompt
Command: CmdPrompt.OpenWindow('Windows Manager Space', 0)
RClick: 



Name: Output Console
Command: CmdPrompt.DebugView('Windows Manager Space', 0)
RClick: 



Name: Command history
Command: CmdPrompt.StackView('Windows Manager Space', 0)
RClick: 



Name: Status view
Command: RsTool.OpenStatusBar();
RClick: 



Name: Stack View
Command: WindowsManager.OpenHistoryWindow()
RClick: 



Name: Anim View
Command: WindowsManager.CreateWindowFromCLSIDEx('default', 'default', 'default', '[Scene]', 1, '4D')
RClick: 



Name: Package Manager
Command: WindowsManager.CreateWindowFromCLSID('{3011C160-2294-48d9-AE95-BD144574FB99}', '', '', '', 1)
RClick: 



Name: Scene View
Command: CmdPrompt.SceneViewCreate();
RClick: 



Name: 3D Window
Command: WindowsManager.CreateWindowFromCLSIDEx('default', 'default', 'default', '[Scene]', 1, '3D')
RClick: 



Name: jScript Macro Record Toolbar
Command: WindowsManager.OpenToolbarFromPrototype('MacroRecordjS', 290, 408,-1,-1)
RClick: RsFileIO.LoadObject(System.GetMainDir() + '\\Rs Main Libraries\\System - Scripts\\jScript command.RsObj', Space.CurrentScene());



Name: Record Toolbar
Command: WindowsManager.OpenToolbarFromPrototype('Record3D', 290, 440,-1,-1)
RClick: RsRec.OpenRecPreferences()



Name: jScript Macro Record Toolbar
Command: WindowsManager.OpenToolbarFromPrototype('MacroRecordjS', 290, 408,-1,-1)
RClick: RsFileIO.LoadObject(System.GetMainDir() + '\\Rs Main Libraries\\System - Scripts\\jScript command.RsObj', Space.CurrentScene());



Name: VBScript Macro Record Toolbar
Command: WindowsManager.OpenToolbarFromPrototype('MacroRecordVB', 430, 408,-1,-1)
RClick: RsFileIO.LoadObject(System.GetMainDir() + '\\Rs Main Libraries\\System - Scripts\\VBScript command.RsObj', Space.CurrentScene());



Name: Shared Space
Command: Net.NtOpenView
RClick: 



Name: File Render
Command: D3DView.RenderToFile('', '')
RClick: 



Name: HW settings
Command: D3DView.ShowSettingsDialog()
RClick: 



Name: Manual
Command: tSBridge.SuggestTSStateByAlias("SV_HELP_HELP_PDF_MANUAL")
RClick: 



Name: Export to VE 
Command: RsImport.OpenVECollectionPanel();
RClick: 



Name: File Render
Command: D3DView.RenderToFile('', '')
RClick: 



Name: Copy
Command: Node.Copy('', '')
RClick: Activity.Run('/Scripts/Commands/Copy')



Name: Copy
Command: Node.Copy('', '')
RClick: Activity.Run('/Scripts/Commands/Copy')



Name: Delete
Command: Node.Delete('')
RClick: 



Name: Settings
Command: if (Node.Exists(Space.CurrentScene()+"/YafaRay4tS")){} else {if(Node.Exists("/Yafaray Folder")){Node.Copy("/Yafaray Folder/YafaRay4tS", Space.CurrentScene());}};Activity.Run(Space.CurrentScene() + "/YafaRay4tS/Lighting Method Switch")
RClick: if (Node.Exists(Space.CurrentScene()+"/YafaRay4tS")){} else {if(Node.Exists("/Yafaray Folder")){Node.Copy("/Yafaray Folder/YafaRay4tS", Space.CurrentScene());}};UserInterface.OpenToolPanelViewEx2("" , "" ,Space.CurrentScene()+"/YafaRay4tS", 6, 1, 0);



Name: Export
Command: if (Node.Exists(Space.CurrentScene()+"/YafaRay4tS")){} else {if(Node.Exists("/Yafaray Folder")){Node.Copy("/Yafaray Folder/YafaRay4tS", Space.CurrentScene());}};Activity.Run(Space.CurrentScene()+"/YafaRay4tS/ExportXML");Activity.Run(Space.CurrentScene()+"/YafaRay4tS/Render")
RClick: if (Node.Exists(Space.CurrentScene()+"/YafaRay4tS")){} else {if(Node.Exists("/Yafaray Folder")){Node.Copy("/Yafaray Folder/YafaRay4tS", Space.CurrentScene());}};Activity.Run(Space.CurrentScene() + "/YafaRay4tS/Lighting Method Switch");



Name: Help
Command: Activity.Run("/Yafaray Folder/YafaRay4tS/HelpHTML");
RClick: if (Node.Exists(Space.CurrentScene()+"/YafaRay4tS")){} else {if(Node.Exists("/Yafaray Folder")){Node.Copy("/Yafaray Folder/YafaRay4tS", Space.CurrentScene());}};UserInterface.OpenToolPanelViewEx2("" , "" ,Space.CurrentScene()+"/YafaRay4tS", 9, 1, 0);



Name: Settings
Command: if (Node.Exists(Space.CurrentScene()+"/YafaRay4tS")){} else {if(Node.Exists("/Yafaray Folder")){Node.Copy("/Yafaray Folder/YafaRay4tS", Space.CurrentScene());}};Activity.Run(Space.CurrentScene() + "/YafaRay4tS/Lighting Method Switch")
RClick: if (Node.Exists(Space.CurrentScene()+"/YafaRay4tS")){} else {if(Node.Exists("/Yafaray Folder")){Node.Copy("/Yafaray Folder/YafaRay4tS", Space.CurrentScene());}};UserInterface.OpenToolPanelViewEx2("" , "" ,Space.CurrentScene()+"/YafaRay4tS", 6, 1, 0);



Name: Infinite
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Light tool','{B1D12AD1-47D4-4e6c-8227-DC80FF55D7BB}{A46795D3-0DE2-4ed8-9FB6-91D84FB9F1EB}(/Preferences/Lights/Factory preferences){/Preferences/Lights/Preferences}','/Preferences/Lights/YafaRay Infinite');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Lights',3,1,1);

Name: Direct
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Light tool','{B1D12AD1-47D4-4e6c-8227-DC80FF55D7BB}{A46795D3-0DE2-4ed8-9FB6-91D84FB9F1EB}(/Preferences/Lights/Factory preferences){/Preferences/Lights/Preferences}','/Preferences/Lights/YafaRay Directional');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Lights',3,1,1);

Name: Sphere
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Light tool','{B1D12AD1-47D4-4e6c-8227-DC80FF55D7BB}{A46795D3-0DE2-4ed8-9FB6-91D84FB9F1EB}(/Preferences/Lights/Factory preferences){/Preferences/Lights/Preferences}','/Preferences/Lights/YafaRay Sphere');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Lights',3,1,1);

Name: Spot
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Light tool','{B1D12AD1-47D4-4e6c-8227-DC80FF55D7BB}{A46795D3-0DE2-4ed8-9FB6-91D84FB9F1EB}(/Preferences/Lights/Factory preferences){/Preferences/Lights/Preferences}','/Preferences/Lights/YafaRay Spot');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Lights',3,1,1);

Name: Point
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Light tool','{B1D12AD1-47D4-4e6c-8227-DC80FF55D7BB}{A46795D3-0DE2-4ed8-9FB6-91D84FB9F1EB}(/Preferences/Lights/Factory preferences){/Preferences/Lights/Preferences}','/Preferences/Lights/YafaRay Point');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Lights',3,1,1);

Name: Sun
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Light tool','{B1D12AD1-47D4-4e6c-8227-DC80FF55D7BB}{A46795D3-0DE2-4ed8-9FB6-91D84FB9F1EB}(/Preferences/Lights/Factory preferences){/Preferences/Lights/Preferences}','/Preferences/Lights/YafaRay Sun');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Lights',3,1,1);

Name: Infinite
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Light tool','{B1D12AD1-47D4-4e6c-8227-DC80FF55D7BB}{A46795D3-0DE2-4ed8-9FB6-91D84FB9F1EB}(/Preferences/Lights/Factory preferences){/Preferences/Lights/Preferences}','/Preferences/Lights/YafaRay Infinite');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Lights',3,1,1);

Name: Area
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Light tool','{B1D12AD1-47D4-4e6c-8227-DC80FF55D7BB}{A46795D3-0DE2-4ed8-9FB6-91D84FB9F1EB}(/Preferences/Lights/Factory preferences){/Preferences/Lights/Preferences}','/Preferences/Lights/YafaRay Area');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Lights',3,1,1);

Name: IES Spot
Command: RsTool.AddPrimitive('/Widgets/Tools/Primitives/Light tool','{B1D12AD1-47D4-4e6c-8227-DC80FF55D7BB}{A46795D3-0DE2-4ed8-9FB6-91D84FB9F1EB}(/Preferences/Lights/Factory preferences){/Preferences/Lights/Preferences}','/Preferences/Lights/YafaRay IES Spot');
RClick: UserInterface.OpenToolPanelViewEx2('', '','/Preferences/Lights',3,1,1);
 * */
