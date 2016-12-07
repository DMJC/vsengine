#---------------------------------------------------------------------------------
# Vega Strike modding program for obj to bfxm conversion
# Copyright (C) 2008, 2011 Vega Strike team
# Contact: hellcatv@users.sourceforge.net
# Internet: http://vegastrike.sourceforge.net/
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 3
# of the License, or (at your option) any later version.
#
# Description: Takes obj file inputs master textures, creates bfxm output
#              Also converts textures to dds
# Author: pyramid
# Version: 2011-04-07 | v0.40
# Contact: pyramid@sapo.pt
#---------------------------------------------------------------------------------
# Features:
# assign textures to models
# convert model meshes
# convert shield meshes
# compress dafault and faction master textures to dds
# remembers input (master) textures
# change model techniques and blend mode
# error checking, validation, and correction
# create new mtl file or default mtl file if none exists
# view on-screen instructions for each workflow module
# option to back up mtl/bfxm/xmesh files before writing
# copy the converted files to units data dir
# remember workspace between sessions
# save workspace with several models
# per subunit texture numbers
# validation for texture naming with spaces (nvcompress doesn't recognize)
# compresses hud image and creates a .sprite file
# units.csv entry editor with creator (with default unit stats for new units)
# update modelview.mission and display model using VS
# display mesh stats (dimensions) from obj file
# engine thruster placement from marker helper obj file
# turret placement from marker helper obj file and type editor
# turret name matching between helper marker naming and registered turret types
# texture file extension check for png
# does not require material export for obj
# back conversion from bfxm to obj+mtl
# saves separate config files for each workspace
# config options for (backing up obj/mtl files, creating xmesh files)
# config option for using input textures (instead of compressed)
# no compressionm of PRT texture
# installations testing as bases in Modelview.system file
# submesh processing with different textures (each submesh should have only one material assigned)
# integration of blink lights (in bfxm) with ani texture 0
# standard sorting of units.csv (by type, role, and alpha)
# check png textures for POT dimensions
#---------------------------------------------------------------------------------
# Known issues:
# mesher error: add from Wavefront to BFXM unimplemneted
#---------------------------------------------------------------------------------
# To do:
# move starting position of ship closer to base (modelview.mission)
# integrate LoD processing (what is the obj encoding for LoD?)
# storing and batch conversion of faction textures
# make frames scrollable (for units editor)
# create new unit entries also for .blank .stock .milspec (vessels only)
# optimization (avoid repeated parsing of obj files)

from appwindow import *
from objparse import *
from vsunitcsv import *
from vsmission import *
from vssystem import *
from png import *
from Tkinter import *
from tkFileDialog import *
import tkMessageBox
import ConfigParser
import shutil               # for copying file backups
import os.path              # for path splitting
import atexit               # catching program exit
import sys
import platform             # get os information

# global watch variables for option changes
state = None
faction = ''
technique = None
blendmode = None
turret = None
upgradeclass = None
inputtex = None
submodelscont = None

class UnitConverter:

    #--------------------------------------------------------------------------------------------
    # PROCESSING
    #--------------------------------------------------------------------------------------------
    def processEvents(self):
    # processes various events
      global submodelscont
      # trigger to fill workspace option button
      global state
      if state!=self.activemodel.get():
        state=self.activemodel.get()
        self.updateSubModels()
        self.getParameters()
        #self.refreshTextureInfo()
        self.readObjMaterials()
        self.updateScreen()
        #print "processEvents - activemodel"
        #print "processEvents", self.models
        #print "processEvents", self.workspace[self.models.index(self.activemodel.get())]
      #trigger for submodels list
      if submodelscont != self.submodelsListBox.curselection():
        submodelscont = self.submodelsListBox.curselection()
        self.getParameters()
        #print "processEvents - submodelscont"
      # trigger for changing faction entry
      if self.faction.get()=="(default)":
        self.faction.set("")
      global faction
      if faction!=self.faction.get():
        faction=self.faction.get()
        self.refreshTextureInfo()
        #print "processEvents - faction"
      # trigger for changing technique option
      if self.technique.get()=='(none)':
        self.technique.set('')
        #print "processEvents - technique"
      global technique
      if technique!=self.technique.get():
        technique=self.technique.get()
        self.setParameters()
        #print "processEvents - technique"
      # trigger for changing blendmode option
      global blendmode
      if blendmode!=self.blendmode.get():
        #write = 1
        #if blendmode==None:
        #  write = 0
        blendmode=self.blendmode.get()
        self.setParameters()
        # write if parameter was changed for current submodel, not when switching selections
        #if write==1 and submodelscont==self.submodelsListBox.curselection():
        #  self.workspaceWrite()
        #print "processEvents - blendmode"
      # trigger for changing turret option
      global turret
      if turret!=self.subunittype.get():
        turret=self.subunittype.get()
        #print "processEvents - turret"
      # trigger for upgrade class option dropdown
      global upgradeclass
      if upgradeclass!=self.upgradeclass.get():
        upgradeclass=self.upgradeclass.get()
        self.updateUpgradeType()
        #print "processEvents - upgradeclass"
      # trigger for use input textures config option
      global inputtex
      if inputtex!=self.inputtex.get():
        inputtex=self.inputtex.get()
        self.refreshTextureInfo()
        #print "processEvents - inputtex"
      # call me again
      root.after(1000, self.processEvents)

    def uniqify(self, seq):
    # Not order preserving removing of key duplicates
        return {}.fromkeys(seq).keys()

    def validateInputs(self):
    # validates and cross-checks various input parameters
      # validates obj and mtl file coherencey
      (dirName, fileName) = os.path.split(self.mtlpath.get())
      if len(self.objtext)>0 and not(self.objtext[0][1].get()==fileName):
        self.replaceMtlLink()
      # validates obj link to mtl file
      (dirName, fileName) = os.path.split(self.objpath.get())
      if self.objpath.get()!='' and (fileName.lower().find("marker")==-1):
        self.objmat = GetObjMaterial(self.objpath.get())
        if (self.objmat[0][0]!='mtllib'):
          #tkMessageBox.showwarning("Warning",
          #  "The mtllib link entry in the OBJ file ("+fileName+") is missing.\n" +
          #  "Please export the obj file from your modeling application including materials.")
          self.createMtlLink()
      # validates if master textures contain spaces (which nvcompress will not accept)
      error = 0
      if not(self.texmaster0.get()=="") and not(self.texmaster0.get().find(" ")==-1):
        error = 1
        mastertexture = self.texmaster0.get()
      if not(self.texmaster1.get()=="") and not(self.texmaster1.get().find(" ")==-1):
        error = 1
        mastertexture = self.texmaster1.get()
      if not(self.texmaster2.get()=="") and not(self.texmaster2.get().find(" ")==-1):
        error = 1
        mastertexture = self.texmaster2.get()
      if not(self.texmaster3.get()=="") and not(self.texmaster3.get().find(" ")==-1):
        error = 1
        mastertexture = self.texmaster3.get()
      if not(self.texmaster4.get()=="") and not(self.texmaster4.get().find(" ")==-1):
        error = 1
        mastertexture = self.texmaster4.get()
      if error==1:
        print "Error (TEXTURE) = ", self.objpath.get()+"/"+mastertexture
        tkMessageBox.showwarning("Warning",
          "The master texture ("+self.objpath.get()+"/"+mastertexture+") contains spaces.\n" +
          "Nvcompress will not recognize this texture for dds compression.\n" +
          "Please substitute the spaces (' ') with underscores ('_') or rename the texture so that it does not contain any spaces.\n" +
          "When finished, you may proceed.")
      # validates if master textures are of png which nvcompress will not accept other formats)
      error = 0
      if self.canPythonImages()==False:
        if self.texmaster0.get()!='' and os.path.splitext(self.texmaster0.get())[1]!='.png' and os.path.splitext(self.texmaster0.get())[1]!='.ani':
          error = 1
          mastertexture = self.texmaster0.get()
        if self.texmaster1.get()!='' and os.path.splitext(self.texmaster1.get())[1]!='.png':
          error = 1
          mastertexture = self.texmaster1.get()
        if self.texmaster2.get()!='' and os.path.splitext(self.texmaster2.get())[1]!='.png':
          error = 1
          mastertexture = self.texmaster2.get()
        if self.texmaster3.get()!='' and os.path.splitext(self.texmaster3.get())[1]!='.png':
          error = 1
          mastertexture = self.texmaster3.get()
        if self.texmaster4.get()!='' and os.path.splitext(self.texmaster4.get())[1]!='.png':
          error = 1
          mastertexture = self.texmaster4.get()
        if error==1:
          print "Error (TEXTURE) = ", self.objpath.get()+"/"+mastertexture
          tkMessageBox.showwarning("Warning",
            "The master texture ("+mastertexture+") is not of png type\n" +
            "Nvcompress will not recognize this texture for dds compression.\n" +
            "Please convert your file to png and proceed when finished.")

    def setDefault(self, variableDefault):
    # sets default variables
      if variableDefault==self.technique:
        self.defaulttechnique = self.technique.get()
        self.iniWrite()

    def canPythonImages(self):
    # determines if python version can process images
      version = sys.version_info
      version = str(version[0])+'.'+str(version[1])+'.'+str(version[2])
      if version>'2.5.9':
        #print version, 'is greater than 2.5.2'
        return True
      return False

    def dec2hex(self, n):
    # return the hexadecimal string representation of integer n
      return "%X" % n

    def hex2dec(self, s):
    # return the integer value of a hexadecimal string s
      return int(s, 16)

    def is_power_of_2(self, n):
      from math import log
      return log(n, 2) % 1.0 == 0.0
     
    def next_power_of_2(self, n):
      from math import log, ceil
      return (2 ** ceil(log(n, 2)))

    #--------------------------------------------------------------------------------------------
    # FILE INPUT/OUTPUT
    #--------------------------------------------------------------------------------------------
    def iniRead(self):
    # read and set variables from ini file
      config = ConfigParser.ConfigParser()
      config.read(self.appdir+"/unitconverter.ini")
      try:
        self.mesherpath.set(config.get("Config", "MESHER_PATH"))
      except:
        self.mesherpath.set("")
      try:
        self.nvcompresspath.set(config.get("Config", "NVCOMPRESS_PATH"))
      except:
        self.nvcompresspath.set("")
      try:
        self.workdir.set(config.get("Config", "WORKDIR"))
      except:
        self.workdir.set("")
        print "iniRead: config variable Config/WORKDIR not yet set"
      try:
        self.vegastrike.set(config.get("Config", "VEGASTRIKE_ROOT"))
      except:
        self.vegastrike.set("")
        print "iniRead: config variable Config/VEGASTRIKE_ROOT not yet set"
        tkMessageBox.showwarning("Warning",
          "The UnitConverter is not yet configured properly.\n" +
          "Please go to configure and set the vegastrike data directory and the mesher and nvcompress paths.")
      try:
        self.defaulttechnique = config.get("Config", "DEFAULT_TECHNIQUE")
      except:
        self.defaulttechnique = ''
      # unit class directory
      try:
        self.useclassdir.set(config.get("Config", "USE_UNITS_CLASSDIR"))
      except:
        self.useclassdir.set(0)
      # backup meshes
      try:
        self.backupobj.set(config.get("Config", "BACKUP_MESHFILES"))
      except:
        self.backupobj.set(0)
      # create xmesh
      try:
        self.createxmesh.set(config.get("Config", "CREATE_XMESH"))
      except:
        self.createxmesh.set(0)
      # use input textures
      try:
        self.inputtex.set(config.get("Config", "USE_INPUT_TEXTURES"))
      except:
        self.inputtex.set(0)
      try:
        self.activemodel.set(config.get("Config", "ACTIVE_MODEL"))
        #if len(self.activemodel.get())>0:
        #  self.nrmodels = 1
      except:
        self.activemodel.set("")
        #self.nrmodels = 0
        print "iniRead: FAILED reading active model"
      self.workspaceRead()

    def iniWrite(self):
    # write variables to ini file
      config = ConfigParser.ConfigParser()
      # set variables
      config.add_section("Config")
      config.set("Config", "MESHER_PATH", self.mesherpath.get())
      config.set("Config", "NVCOMPRESS_PATH", self.nvcompresspath.get())
      config.set("Config", "VEGASTRIKE_ROOT", self.vegastrike.get())
      config.set("Config", "DEFAULT_TECHNIQUE", self.defaulttechnique)
      config.set("Config", "USE_UNITS_CLASSDIR", self.useclassdir.get())
      config.set("Config", "BACKUP_MESHFILES", self.backupobj.get())
      config.set("Config", "CREATE_XMESH", self.createxmesh.get())
      config.set("Config", "USE_INPUT_TEXTURES", self.inputtex.get())
      config.set("Config", "WORKDIR", self.workdir.get())
      config.set("Config", "ACTIVE_MODEL", self.unitname.get())
      #config.set("Config", "UNIT_MODELNAME", self.unitname.get())
      # write ini file
      cfgfile = open(self.appdir+"/unitconverter.ini","w")
      config.write(cfgfile) # write to file
      print "Configuration file updated"

    def workspaceRead(self):
    # read and set variables from ini file
      print "Reading workspace"
      wsConfig = ConfigParser.ConfigParser()
      if self.workdir.get()!='' and self.activemodel.get()!='':
        wsFile = self.workdir.get()+'/'+self.activemodel.get()+'.ini'
        wsConfig.read(wsFile)
      # READ WORKSPACE
      try:
        self.activemodel.set(wsConfig.get("Workspace", "ACTIVE_MODEL"))
        if len(self.activemodel.get())>0:
          self.nrmodels = 1
      except:
        self.activemodel.set("")
        self.nrmodels = 0
        #print "workspaceRead: FAILED reading active model"
      try:
        self.nrmodels = int(wsConfig.get("Workspace", "NR_OF_MODELS"))
      except:
        self.nrmodels = 0
      try:
        self.unitname.set(wsConfig.get("Workspace", "UNIT_MODELNAME"))
        self.setUnitType()
      except:
        pass
      try:
        self.hudimage.set(wsConfig.get("Workspace", "HUD_IMAGE"))
      except:
        self.hudimage.set("")
      try:
        self.faction.set(wsConfig.get("Workspace", "TEXTURE_FACTION"))
      except:
        self.faction.set("")
      # READ MODELS INTO WORKSPACE
      self.workspace = []
      #for i in range(len(self.models)):
      for i in range(self.nrmodels):
        self.workspace += [[]]
        try:
          nrsubmodels = int(wsConfig.get("Workspace", "SUBMODELS_MODEL_"+str(i)))
        except:
          nrsubmodels = 1
          self.workspace += [[['']*11]]
        try:
          if i<len(self.models):
            self.models[i] = wsConfig.get('MODEL_'+str(i)+"_SUBMODEL_0", 'name')
          else:
            self.models += [wsConfig.get('MODEL_'+str(i)+"_SUBMODEL_0", 'name')]
        except:
          if i<len(self.models):
            self.models[i] = self.unitname.get()
          else:
            self.models += [self.unitname.get()]
        #self.workspace[i] = [[]]
        for s in range(nrsubmodels):
          self.workspace[i] += [[]]
          for p in range(len(self.PARAMS)):
            try:
                self.workspace[i][s] += [wsConfig.get("MODEL_"+str(i)+"_SUBMODEL_"+str(s), self.PARAMS[p])]
            except:
              self.workspace[i][s] += ['']
          # set default blend mode
          if self.workspace[i][s][3]=='':
            self.workspace[i][s][3] = "['0','ONE ZERO']"
          # update changed workdir
          if self.workdir.get()!=os.path.split(self.workspace[i][s][1])[0]:
            self.workspace[i][s][1] = self.workdir.get()+'/'+os.path.split(self.workspace[i][s][1])[1]
            print "readWS", self.workspace[i][s][1]
        #self.activemodel.set(self.models[0])
        self.updateWorkspace()
        #self.refreshOptionMenu(self.optws, self.models, self.activemodel, len(self.models)-1)
        #self.refreshOptionMenu(self.opttx, self.models, self.activemodel, len(self.models)-1)
        self.getParameters() # from ws to screen

    def workspaceWrite(self):
    # write variables to ini file
      wsConfig = ConfigParser.ConfigParser()
      # save models workspace
      if self.workdir.get()!='' and self.unitname.get()!='':
        wsConfig.add_section("Workspace")
        wsConfig.set("Workspace", "NR_OF_MODELS", len(self.models))
        wsConfig.set("Workspace", "ACTIVE_MODEL", self.activemodel.get())
        wsConfig.set("Workspace", "ACTIVE_MODELNR", self.models.index(self.activemodel.get()))
        wsConfig.set("Workspace", "TEXTURE_FACTION", self.faction.get())
        wsConfig.set("Workspace", "UNIT_MODELNAME", self.unitname.get())
        wsConfig.set("Workspace", "HUD_IMAGE", self.hudimage.get())
        #nrsubmodels = self.submodelsListBox.size()
        for i in range(len(self.models)):
          self.obj = ObjParse(self.workspace[i][0][1])
          nrsubmodels = max(len(self.obj.getObjectNames()),1) #has at least a default submodel
          if self.models[i].lower().find('marker')>-1:
            nrsubmodels = 1
          #print "workspaceWrite: nrsubmodels", nrsubmodels
          wsConfig.set("Workspace", "SUBMODELS_MODEL_"+str(i), nrsubmodels)
          for s in range(nrsubmodels):
            wsConfig.add_section("MODEL_"+str(i)+"_SUBMODEL_"+str(s))
            for p in range(len(self.PARAMS)):
              wsConfig.set("MODEL_"+str(i)+"_SUBMODEL_"+str(s), self.PARAMS[p], self.workspace[i][s][p])
        # write ini file
        wsFile = open(self.workdir.get()+'/'+self.unitname.get()+'.ini','w')
        wsConfig.write(wsFile) # write to file
        print "Workspace file updated"

    def getFolder(self, setstrvar):
    # gets a folder name
      folder = askdirectory(initialdir=self.vegastrike.get(), title="Select A Folder", mustexist=1)
      if len(folder) > 0:
        setstrvar.set(folder)
        self.setParameters()
        self.iniWrite()

    def getPath(self, setstrvar):
    # get a file and return the full address (path+filename)
      #self.changeToWorkdir()
      file = askopenfilename(initialdir=self.workdir.get(), title="Select A File")
      (dirName, fileName) = os.path.split(file)
      (fileBaseName, fileExtension)=os.path.splitext(fileName)
      if file=='':
        return ''
      if setstrvar!=None:
        setstrvar.set(file)
      # perform some operations if new obj file is selected
      if (setstrvar==self.objpath) and fileBaseName!=self.activemodel.get():
        print "getPath: getting new model"
        if fileExtension.lower()=='.obj':
          self.workdir.set(dirName)
          self.activemodel.set(fileBaseName)
        # convert bfxm if selected selected
        if fileExtension.lower()=='.bfxm':
          self.workdir.set(dirName)
          self.activemodel.set(fileBaseName)
          self.convertBfxmObj()
          self.objpath.set(dirName+'/'+fileBaseName+'.obj')
        self.updateMtlPath()
        self.updateSubModels()
        self.updateWorkspace()
        self.deleteFactionEntry()
        self.setParameters()
        print "unitname", self.getUnitName()
        self.unitname.set(self.getUnitName())
        self.unitmesh.set('{'+self.unitname.get().lower()+'.bfxm;;}')
        print "unitname", self.unitname.get()
        self.setUnitType()
        self.readUnitCsv()
        #self.updateScreen()
        if fileExtension.lower()=='.bfxm':
          self.getTextureFromMtl()
        self.iniWrite()
        # swap from marker to first model
        if (self.activemodel.get().lower().find('marker')!=-1) and (len(self.models)>0):
          self.activemodel.set(self.models[0])
          self.updateSubModels()
          self.getParameters()
          self.updateScreen()
        self.workspaceWrite()
      return file

    def validateImage(self, fileAddress):
    # validates image for png type and POT
      import imghdr
      type = imghdr.what(fileAddress)
      if type!='png':
        print "Error (TEXTURE) = ", fileAddress
        tkMessageBox.showwarning("Warning",
          "The master texture ("+os.path.split(fileAddress)[1]+") is not of png type\n" +
          "Nvcompress will not recognize this texture for dds compression.\n" +
          "Please convert your file to png and proceed when finished.")
      # get dimensions
      (width, height) = loadPngHeader(fileAddress)
      if width==0 or height==0:
        return
      #print "Png size =", width, height
      # POT check
      #print "pot =", self.is_power_of_2(width), self.is_power_of_2(height)
      error = 0
      if self.is_power_of_2(width)==False:
        error = 1
      if self.is_power_of_2(height)==False:
        error = 1
      if error==1:
        print "Error (TEXTURE) = ", fileAddress
        tkMessageBox.showwarning("Warning",
          "The master texture ("+os.path.split(fileAddress)[1]+") has the dimensions\n" +
          str(width)+","+str(height)+" and is therefore not POT (power-of-two).\n" +
          "Vega Strike will not display this texture correctly.\n" +
          "Please redo the file to POT and proceed when finished.")

    def getFile(self, setstrvar):
    # get a file and return only the filename without path
      file = askopenfilename(initialdir=self.workdir.get(), title="Select A File")
      if file=='':
        return ''
      (dirName, fileName) = os.path.split(file)
      setstrvar.set(fileName)
      self.setParameters()
      self.validateInputs()
      if os.path.splitext(file)[1].find('.ani')==-1:
        self.workdir.set(dirName)
        # check POT
        if self.canPythonImages():
          self.validateImage(file)
      return fileName

    def getFileAndUpdateMaterial(self, command1, var1, nrTexture):
      imageFile = command1(var1)
      if imageFile=='':
        return ''
      # validate POT size
      imageAddress = self.workdir.get()+"/"+imageFile
      print "Image = ", imageAddress
      #im = Image.open(imageAddress)
      #print "Dimensions = ", im.format, im.size, im.mode
      # save texture inormation
      self.refreshTextureInfo()
      self.workspaceWrite()

    def getFileAndHudImage(self, command1, var1):
      imageFile = command1(var1)
      if imageFile=='':
        return ''
      self.workspaceWrite()
      # update unit information
      (fileBaseName, fileExtension)=os.path.splitext(imageFile)
      self.unithud.set(fileBaseName.lower()+'.sprite')

    def changeToWorkdir(self):
    # set workdir
      (dirName, fileName) = os.path.split(self.workdir.get())
      os.chdir(dirName) #change to workdir

    def readUnitCsv(self):
    # reads unit.csv and displays information
      if self.vegastrike.get()=='':
        return
      self.unitcsv = VsUnitCsv(self.vegastrike.get())
      if not(self.unitname.get()==''):
        self.unit = self.unitcsv.getUnit(self.unitname.get())
        if len(self.unit)==0:
          self.unit = self.unitcsv.getDefaultUnit(self.unittype.get())
        header = self.unitcsv.getHeader()
        self.unitdescription.set(self.unit[header.index('Textual_Description')])
        self.unitdescr.delete(1.0, END)
        self.unitdescr.insert(INSERT, self.unitdescription.get())
        self.unittype.set(self.unit[header.index('Object_Type')])
        self.unitrole.set(self.unit[header.index('Combat_Role')])
        self.unithud.set(self.unit[header.index('Hud_image')])
        self.unitscale.set(self.unit[header.index('Unit_Scale')])
        self.unitcockpit.set(self.unit[header.index('Cockpit')])
        self.unitmesh.set(self.unit[header.index('Mesh')])
        self.unitshieldmesh.set(self.unit[header.index('Shield_Mesh')])
        self.unitsounds.set(self.unit[header.index('Sound')])
        self.unitthruster.set(self.unit[header.index('Light')])
        self.unitmass.set(self.unit[header.index('Mass')]) #20
        self.unitinertia.set(self.unit[header.index('Moment_Of_Inertia')]) #21
        self.unitfuel.set(self.unit[header.index('Fuel_Capacity')]) #22
        self.unithull.set(self.unit[header.index('Hull')]) #23
        self.unitarmor.set(self.unit[header.index('Armor_Front_Top_Right')]) #24
        self.unitshield.set(self.unit[header.index('Shield_Front_Top_Right')]) #32
        self.unitshieldquad.set(self.unit[header.index('Shield_Front_Bottom_Right')]) #34
        self.unitshieldrecharge.set(self.unit[header.index('Shield_Recharge')]) #40
        self.unitcapacitorprimary.set(self.unit[header.index('Warp_Capacitor')]) #42
        self.unitcapacitorwarp.set(self.unit[header.index('Primary_Capacitor')])
        self.unitreactorrecharge.set(self.unit[header.index('Reactor_Recharge')])
        self.unitjumpdrive.set(self.unit[header.index('Jump_Drive_Present')]) #45
        self.unitjumpcost.set(self.unit[header.index('Outsystem_Jump_Cost')]) #48
        self.unitwarpcost.set(self.unit[header.index('Warp_Usage_Cost')])
        self.unitoverdrivetype.set(self.unit[header.index('Afterburner_Type')]) #50
        self.unitoverdrivecost.set(self.unit[header.index('Afterburner_Usage_Cost')])
        self.unitmaneuveryaw.set(self.unit[header.index('Maneuver_Yaw')]) #51
        self.unitmaneuverpitch.set(self.unit[header.index('Maneuver_Pitch')])
        self.unitmaneuverroll.set(self.unit[header.index('Maneuver_Roll')])
        self.unitgovernoryaw.set(self.unit[header.index('Yaw_Governor')]) #55
        self.unitgovernorpitch.set(self.unit[header.index('Pitch_Governor')])
        self.unitgovernorroll.set(self.unit[header.index('Roll_Governor')])
        self.unitoverdriveaccel.set(self.unit[header.index('Afterburner_Accel')]) #58
        self.unitaccelforward.set(self.unit[header.index('Forward_Accel')]) #59
        self.unitaccelretro.set(self.unit[header.index('Retro_Accel')])
        self.unitaccelleft.set(self.unit[header.index('Left_Accel')])
        self.unitaccelright.set(self.unit[header.index('Right_Accel')])
        self.unitacceltop.set(self.unit[header.index('Top_Accel')])
        self.unitaccelbottom.set(self.unit[header.index('Bottom_Accel')])
        self.unitoverdrive.set(self.unit[header.index('Afterburner_Speed_Governor')]) #65
        self.unitspeed.set(self.unit[header.index('Default_Speed_Governor')]) #66
        self.unititts.set(self.unit[header.index('ITTS')]) #67
        self.unitradarcolor.set(self.unit[header.index('Radar_Color')]) # 68
        self.unitradarrange.set(self.unit[header.index('Radar_Range')])
        self.unitconetracking.set(self.unit[header.index('Tracking_Cone')])
        self.unitconemax.set(self.unit[header.index('Max_Cone')])
        self.unitconelock.set(self.unit[header.index('Lock_Cone')])
        self.unitholdvolume.set(self.unit[header.index('Hold_Volume')]) #73
        self.unitupgrades.set(self.unit[header.index('Upgrades')]) #97
        self.unitsubunits.set(self.unit[header.index('Sub_Units')]) #99
        self.unitmounts.set(self.unit[header.index('Mounts')]) #102
        self.unitdocks.set(self.unit[header.index('Dock')])
        self.unitcargoimport.set(self.unit[header.index('Cargo_Import')]) # 105
        self.unitcargo.set(self.unit[header.index('Cargo')]) # 106
        self.unitupgradevolume.set(self.unit[header.index('Upgrade_Storage_Volume')]) #109

        thrusters = self.parseMounts(self.unitthruster.get())
        if len(thrusters)>0: 
          self.thrustertype.set(thrusters[0][0])
        if (self.hudimage.get()!='') and (self.unitname.get()==self.getUnitName()):
          self.unithud.set(self.getUnitName().lower()+'-hud.sprite')
        # update shield information
        if self.workspaceHasShield() and (self.unitname.get().lower()==self.getUnitName()):
          self.unitshieldmesh.set(self.unitname.get().lower()+'-shield.bfxm')
        # update dimensions
        if self.unitname.get().lower()==self.getUnitName().lower():
          self.objGetDims()
        else:
          self.unitlength.set('')
          self.unitwidth.set('')
          self.unitheight.set('')
        #update mounts
        self.displayThrusterDiameter()
        self.currentturret.set('')
        self.subunittype.set('')
        self.subunittypesource.set('')
        self.updateSubunits()

    def writeUnitCsv(self):
    # writes unit.csv from current display
      # collect variables from screen editor
      self.unitcsv = VsUnitCsv(self.vegastrike.get())
      header = self.unitcsv.getHeader()
      #print "Header =", header
      if not(self.unitname.get()==''):
        self.unitdescription.set(self.unitdescr.get(1.0, END).replace('\n',''))
        self.unit[0]  = self.unitname.get()
        if self.unit[header.index('Directory')]=='':
          if self.useclassdir.get()=='1':
            self.unit[header.index('Directory')] = './'+self.unittype.get().lower()+'s/'+self.unitname.get()
          else:
            self.unit[header.index('Directory')] = './'+self.unitname.get()
        self.unit[header.index('Name')]  = self.unitname.get()#2
        self.unit[header.index('Object_Type')]  = self.unittype.get() #4
        self.unit[header.index('Combat_Role')]  = self.unitrole.get()
        self.unit[header.index('Textual_Description')]  = self.unitdescription.get()
        self.unit[header.index('Hud_image')]  = self.unithud.get()
        self.unit[header.index('Unit_Scale')]  = self.unitscale.get()
        self.unit[header.index('Cockpit')]  = self.unitcockpit.get()
        self.unit[header.index('Mesh')]  = self.unitmesh.get() #'{'+self.unitname.get().lower()+'.bfxm;;}' #13
        self.unit[header.index('Shield_Mesh')] = self.unitshieldmesh.get()
        self.unit[header.index('Mass')] = self.unitmass.get() #20
        self.unit[header.index('Moment_Of_Inertia')] = self.unitinertia.get() #21
        self.unit[header.index('Fuel_Capacity')] = self.unitfuel.get() #22
        self.unit[header.index('Hull')] = self.unithull.get() #23
        self.unit[header.index('Armor_Front_Top_Right')] = self.unitarmor.get() #24
        self.unit[header.index('Armor_Front_Top_Left')] = self.unitarmor.get()
        self.unit[header.index('Armor_Front_Bottom_Right')] = self.unitarmor.get()
        self.unit[header.index('Armor_Front_Bottom_Left')] = self.unitarmor.get()
        self.unit[header.index('Armor_Back_Top_Right')] = self.unitarmor.get() #28
        self.unit[header.index('Armor_Back_Top_Left')] = self.unitarmor.get()
        self.unit[header.index('Armor_Back_Bottom_Right')] = self.unitarmor.get()
        self.unit[header.index('Armor_Back_Bottom_Left')] = self.unitarmor.get()
        self.unit[header.index('Shield_Front_Top_Right')] = self.unitshield.get() #32
        self.unit[header.index('Shield_Back_Top_Left')] = self.unitshield.get()
        self.unit[header.index('Shield_Front_Bottom_Right')] = self.unitshieldquad.get() # 34
        self.unit[header.index('Shield_Front_Bottom_Left')] = self.unitshieldquad.get()
        self.unit[header.index('Shield_Recharge')] = self.unitshieldrecharge.get() #40
        self.unit[header.index('Warp_Capacitor')] = self.unitcapacitorprimary.get() #42
        self.unit[header.index('Primary_Capacitor')] = self.unitcapacitorwarp.get()
        self.unit[header.index('Reactor_Recharge')] = self.unitreactorrecharge.get()
        self.unit[header.index('Jump_Drive_Present')] = self.unitjumpdrive.get() #45
        self.unit[header.index('Outsystem_Jump_Cost')] = self.unitjumpcost.get() #48
        self.unit[header.index('Warp_Usage_Cost')] = self.unitwarpcost.get()
        self.unit[header.index('Afterburner_Type')] = self.unitoverdrivetype.get() #50
        self.unit[header.index('Afterburner_Usage_Cost')] = self.unitoverdrivecost.get()
        self.unit[header.index('Maneuver_Yaw')] = self.unitmaneuveryaw.get() #52
        self.unit[header.index('Maneuver_Pitch')] = self.unitmaneuverpitch.get()
        self.unit[header.index('Maneuver_Roll')] = self.unitmaneuverroll.get()
        self.unit[header.index('Yaw_Governor')] = self.unitgovernoryaw.get() #55
        self.unit[header.index('Pitch_Governor')] = self.unitgovernorpitch.get()
        self.unit[header.index('Roll_Governor')] = self.unitgovernorroll.get()
        self.unit[header.index('Afterburner_Accel')] = self.unitoverdriveaccel.get() #58
        self.unit[header.index('Forward_Accel')] = self.unitaccelforward.get() #59
        self.unit[header.index('Retro_Accel')] = self.unitaccelretro.get()
        self.unit[header.index('Left_Accel')] = self.unitaccelleft.get()
        self.unit[header.index('Right_Accel')] = self.unitaccelright.get()
        self.unit[header.index('Top_Accel')] = self.unitacceltop.get()
        self.unit[header.index('Bottom_Accel')] = self.unitaccelbottom.get()
        self.unit[header.index('Afterburner_Speed_Governor')] = self.unitoverdrive.get() #65
        self.unit[header.index('Default_Speed_Governor')] = self.unitspeed.get() #66
        self.unit[header.index('ITTS')] = self.unititts.get() #67
        self.unit[header.index('Radar_Color')] = self.unitradarcolor.get() # 68
        self.unit[header.index('Radar_Range')] = self.unitradarrange.get()
        self.unit[header.index('Tracking_Cone')] = self.unitconetracking.get()
        self.unit[header.index('Max_Cone')] = self.unitconemax.get()
        self.unit[header.index('Lock_Cone')] = self.unitconelock.get()
        self.unit[header.index('Hold_Volume')] = self.unitholdvolume.get() #73
        self.unit[header.index('Upgrades')] = self.unitupgrades.get() #97
        self.unit[header.index('Sub_Units')] = self.unitsubunits.get() #99
        self.unit[header.index('Sound')] = self.unitsounds.get()
        self.unit[header.index('Light')] = self.unitthruster.get()
        self.unit[header.index('Mounts')] = self.unitmounts.get()
        self.unit[header.index('Dock')] = self.unitdocks.get() #104
        self.unit[header.index('Cargo_Import')] = self.unitcargoimport.get() # 105
        self.unit[header.index('Cargo')] = self.unitcargo.get() # 106
        self.unit[header.index('Upgrade_Storage_Volume')] = self.unitupgradevolume.get() #109

        # write units.csv
        if not(self.unitcsv.updateUnit(self.unit)): # if update fails
          self.unitcsv.insertUnit(self.unit)        # insert new record
        self.unitcsv.writeUnitCsv()                 # write units.csv file
        if self.unitname.get()==self.getUnitName():
          #self.iniWrite()
          self.workspaceWrite()

    def sortUnitCsv(self):
    # sorts units.csv
      self.unitcsv = VsUnitCsv(self.vegastrike.get())
      self.unitcsv.standardSort()

    def updateModelViewMission(self):
    # updates modelview.mission file with current vessel model and faction
      vsmission = VsMission(self.vegastrike.get()+'/mission/modelview.mission')
      if self.missionfaction.get()=='(default)':
        vsmission.updateNodeAttribute('flightgroup', 'faction', 'privateer')
      else:
        vsmission.updateNodeAttribute('flightgroup', 'faction', self.missionfaction.get())
      if self.unittype.get()=='Installation':
        vsmission.updateNodeAttribute('flightgroup', 'type', 'Llama')
      else:
        vsmission.updateNodeAttribute('flightgroup', 'type', self.unitname.get())
      vsmission.saveMissionFile()

    def updateModelViewSystem(self):
    # updates Modelview.system file with current installation model and faction
      vssystem = VsSystem(self.vegastrike.get()+'/sectors/Special/Modelview.system')
      if self.unittype.get()=='Installation':
        vssystem.updateNodeAttribute('Unit', 'file', self.unitname.get())
        vssystem.saveSystemFile()

    def readUnitUpgrades(self):
    # reads upgrades from unit.csv and updates option dropdown
      # read upgrades
      if self.vegastrike.get()=='':
        return
      #self.unitcsv = VsUnitCsv(self.vegastrike.get())
      self.upgrades = self.unitcsv.getObjectType("Upgrade_Additive")
      self.upgrades += self.unitcsv.getObjectType("Upgrade_Replacement")
      # get classes
      upgrades = []
      for u in range(len(self.upgrades)):
        upgrades += [self.upgrades[u].strip('_0123456789')]
      classes = self.uniqify(upgrades)
      # set class option dropdown
      self.refreshOptionMenu(self.optupclasses, classes, self.upgradeclass)

    def updateUpgradeType(self):
    # updates upgrate type option dropdown based on selected class
      if self.unitname.get()=='' or self.vegastrike.get()=='':
        return
      upgrades = []
      for u in range(len(self.upgrades)):
        if self.upgrades[u].find(self.upgradeclass.get())!=-1:
          upgrades += [self.upgrades[u]]
      self.refreshOptionMenu(self.optupgrades, upgrades, self.upgradetype)

    def readUnitWeapons(self):
    # reads weapons from units.csv
      # read upgrades
      if self.vegastrike.get()=='':
        return
      #self.unitcsv = VsUnitCsv(self.vegastrike.get())
      self.weapons = self.unitcsv.getObjectType("Weapon")
      #print "Weapons = ", self.weapons

    def createMtlLink(self):
    # creates an mtllib entry in the obj file if missing
      fileAddress = self.objpath.get()
      print "Creating missing mtllib entry in", fileAddress
      self.obj = ObjParse(fileAddress)
      lines = self.obj.getFile()
      #search comments
      for i in range(len(lines)):
        if lines[i][0]=='#':
          newline = i+1
      #insert mtllib entry
      newentry = os.path.splitext(os.path.split(fileAddress)[1])[0]
      lines.insert(newline, 'mtllib ' + newentry + '.mtl\n')
      saveObj(fileAddress, lines)
      self.obj = ObjParse(fileAddress)

    def replaceMtlLink(self):
    # replaces an mtllib entry in the obj file if wrong
      fileAddress = self.objpath.get()
      self.obj = ObjParse(fileAddress)
      lines = self.obj.getFile()
      #search comments
      for i in range(len(lines)):
        if lines[i].split(' ')[0]=='mtllib':
          #insert mtllib entry
          print "Updating mtllib entry in", fileAddress
          newentry = os.path.splitext(os.path.split(fileAddress)[1])[0]
          lines[i] = 'mtllib ' + newentry + '.mtl\n'
          saveObj(fileAddress, lines)
          self.obj = ObjParse(fileAddress)

    #--------------------------------------------------------------------------------------------
    # TEXTURES
    #--------------------------------------------------------------------------------------------
    def getTextureForMaster(self,iMaterial,iSubmesh,iTexture):
    # creates a texture name by convention "text_m_s_t" where
    # m - model
    # s - submodel
    # t - texture set
      submodelnr = self.getActiveSubModel()
      if self.faction.get()!='' and iSubmesh==submodelnr:
        factionText = self.faction.get()+'_'
      else:
        factionText = ''
      return factionText+"tex_"+str(iMaterial)+str(iSubmesh)+str(iTexture)+".texture"

    def getActiveSubModel(self):
      if len(self.submodelsListBox.curselection())==0:
        return 0
      else:
        return int(self.submodelsListBox.curselection()[0])

    def refreshTextureInfo(self):
      self.textures = []
      if self.activemodel.get()=='':
        return
      modelnr = self.models.index(self.activemodel.get())
      self.obj = ObjParse(self.workspace[modelnr][0][1])
      nrsubmodels = max(len(self.obj.getObjectNames()),1)
      submodelnr = self.getActiveSubModel()
      if self.activemodel.get().lower().find('marker')!=-1:
        nrsubmodels = 1
      # determine faction
      faction = self.faction.get()
      if faction!='':
        faction += "_"
      # update textures
      for s in range(nrsubmodels):
        self.textures += [{}]
        self.nrtextures = 0
        # texture 0
        if self.workspace[modelnr][s][5]!='':
          if self.inputtex.get()=='1' or os.path.splitext(self.workspace[modelnr][s][5])[1]=='.ani':
            self.textures[s][self.nrtextures] = ["map_0",self.workspace[modelnr][s][5]]
          else:
            self.textures[s][self.nrtextures] = ["map_0",self.getTextureForMaster(modelnr,s,0)]
          self.nrtextures += 1
        # texture 1
        if self.workspace[modelnr][s][6]!='':
          if self.inputtex.get()=='1':
            self.textures[s][self.nrtextures] = ["map_1",self.workspace[modelnr][s][6]]
          else:
            self.textures[s][self.nrtextures] = ["map_1",self.getTextureForMaster(modelnr,s,1)]
          self.nrtextures += 1
        # texture 2
        if self.workspace[modelnr][s][7]!='':
          if self.inputtex.get()=='1':
            self.textures[s][self.nrtextures] = ["map_2",self.workspace[modelnr][s][7]]
          else:
            self.textures[s][self.nrtextures] = ["map_2",self.getTextureForMaster(modelnr,s,2)]
          self.nrtextures += 1
        # texture 3
        if self.workspace[modelnr][s][8]!='':
          if self.inputtex.get()=='1':
            self.textures[s][self.nrtextures] = ["map_3",self.workspace[modelnr][s][8]]
          else:
            self.textures[s][self.nrtextures] = ["map_3",self.getTextureForMaster(modelnr,s,3)]
          self.nrtextures += 1
        # texture 4
        if self.workspace[modelnr][s][9]!='':
          if self.inputtex.get()=='1':
            self.textures[s][self.nrtextures] = ["map_4",self.workspace[modelnr][s][9]]
          else:
            self.textures[s][self.nrtextures] = ["map_4",self.getTextureForMaster(modelnr,s,4)]
          self.nrtextures += 1
        # texture 5
        if self.workspace[modelnr][s][10]!='':
          # no compression for texture 5 (PRT)
          self.textures[s][self.nrtextures] = ["map_5",self.workspace[modelnr][s][10]]
          self.nrtextures += 1
      # set display
      self.texture0.set("")
      self.texture1.set("")
      self.texture2.set("")
      self.texture3.set("")
      self.texture4.set("")
      self.texture5.set("")
      #print "refreshTextureInfo: model", modelnr
      #print "refreshTextureInfo: submodelnr", submodelnr
      #print "refreshTextureInfo: workspace", self.workspace
      if self.inputtex.get()=='1': # use input textures
        if self.workspace[modelnr][submodelnr][5]!='':
          self.texture0.set(faction+self.workspace[modelnr][submodelnr][5])
        if self.workspace[modelnr][submodelnr][6]!='':
          self.texture1.set(faction+self.workspace[modelnr][submodelnr][6])
        if self.workspace[modelnr][submodelnr][7]!='':
          self.texture2.set(faction+self.workspace[modelnr][submodelnr][7])
        if self.workspace[modelnr][submodelnr][8]!='':
          self.texture3.set(faction+self.workspace[modelnr][submodelnr][8])
        if self.workspace[modelnr][submodelnr][9]!='':
          self.texture4.set(faction+self.workspace[modelnr][submodelnr][9])
      else:
        if self.workspace[modelnr][submodelnr][5]!='' and os.path.splitext(self.workspace[modelnr][submodelnr][5])[1]!='.ani':
          self.texture0.set(self.getTextureForMaster(modelnr,submodelnr,0))
        elif os.path.splitext(self.workspace[modelnr][submodelnr][5])[1]=='.ani':
          self.texture0.set(self.workspace[modelnr][submodelnr][5])
        else:
          self.texture0.set('')
        if self.workspace[modelnr][submodelnr][6]!='':
          self.texture1.set(self.getTextureForMaster(modelnr,submodelnr,1))
        else:
          self.texture1.set('')
        if self.workspace[modelnr][submodelnr][7]!='':
          self.texture2.set(self.getTextureForMaster(modelnr,submodelnr,2))
        else:
          self.texture2.set('')
        if self.workspace[modelnr][submodelnr][8]!='':
          self.texture3.set(self.getTextureForMaster(modelnr,submodelnr,3))
        else:
          self.texture3.set('')
        if self.workspace[modelnr][submodelnr][9]!='':
          self.texture4.set(self.getTextureForMaster(modelnr,submodelnr,4))
        else:
          self.texture4.set('')
      self.texture5.set(self.workspace[modelnr][submodelnr][10])
      # update factionalized master textures
      if self.workspace[modelnr][submodelnr][5]!='' and os.path.splitext(self.workspace[modelnr][submodelnr][5])[1]!='.ani':
        self.texmaster0.set(faction+self.workspace[modelnr][submodelnr][5])
      else:
        self.texmaster0.set(self.workspace[modelnr][submodelnr][5])
      if self.workspace[modelnr][submodelnr][6]!='':
        self.texmaster1.set(faction+self.workspace[modelnr][submodelnr][6])
      if self.workspace[modelnr][submodelnr][7]!='':
        self.texmaster2.set(faction+self.workspace[modelnr][submodelnr][7])
      if self.workspace[modelnr][submodelnr][8]!='':
        self.texmaster3.set(faction+self.workspace[modelnr][submodelnr][8])
      if self.workspace[modelnr][submodelnr][9]!='':
        self.texmaster4.set(faction+self.workspace[modelnr][submodelnr][9])
      if self.workspace[modelnr][submodelnr][10]!='':
        self.texmaster5.set(self.workspace[modelnr][submodelnr][10])

    def deleteEntry(self, variable):
    # deletes content of a display variable
      variable.set("")
      #self.setParameters()
      #self.refreshTextureInfo()
      #self.workspaceWrite()

    def deleteFactionEntry(self):
    # deletes faction variable and textures
      self.deleteEntry(self.faction)
      #self.texmaster0.set("")
      #self.texmaster1.set("")
      #self.texmaster2.set("")
      #self.texmaster3.set("")
      #self.texmaster4.set("")
      #self.texmaster5.set("")
      #self.setParameters()
      self.refreshTextureInfo()
      #self.iniWrite()

    def getTextureFromMtl(self):
    # reads output texture info from mtl file
    # used when converting from bfxm to obj
      #print "getTextureFromMtl"
      self.mtl = MtlParse(self.mtlpath.get())
      texture = self.mtl.getMtlTexture(('map_0','map_kd','map_Kd'))
      self.texture0.set(texture)
      self.texmaster0.set(texture)
      texture = self.mtl.getMtlTexture(('map_1','map_ks','map_Ks'))
      self.texture1.set(texture)
      self.texmaster1.set(texture)
      texture = self.mtl.getMtlTexture(('map_2','map_ka','map_Ka','map_damage'))
      self.texture2.set(texture)
      self.texmaster2.set(texture)
      texture = self.mtl.getMtlTexture(('map_3','map_ke','map_Ke'))
      self.texture3.set(texture)
      self.texmaster3.set(texture)
      texture = self.mtl.getMtlTexture(('map_4','map_normal','map_Normal'))
      self.texture4.set(texture)
      self.texmaster4.set(texture)
      texture = self.mtl.getMtlTexture(('map_5'))
      self.texture5.set(texture)
      self.texmaster5.set(texture)
      self.setParameters()

    #--------------------------------------------------------------------------------------------
    # WORKSPACE
    #--------------------------------------------------------------------------------------------
    def updateWorkspace(self):
    # updates workspace parameters
    # workspace structure: workspace[model][submodel][parameter]
      exists = 0
      self.nrmodels = len(self.models)
      nrsubmodels = self.submodelsListBox.size()
      # check if model is already in workspace
      for w in range(len(self.models)):
        if self.models[w]==self.activemodel.get():
          exists = 1
      if exists==0:
        if self.models[0]=='':
          self.models[0] = self.activemodel.get()
          self.workspace = [[[]]]
        else:
          self.models += [self.activemodel.get()]
          self.workspace += [[[]]]
        self.nrmodels = len(self.models)
        #print "updateWorkspace: nrmodels", self.nrmodels
        #print "updateWorkspace: workspace", self.workspace
        for s in range(nrsubmodels):
          if len(self.workspace[self.nrmodels-1])-1<s:
            self.workspace[self.nrmodels-1] += [[]]
          for p in range(len(self.PARAMS)):
            try:
              self.workspace[self.nrmodels-1][s][p] = ''
            except:
              self.workspace[self.nrmodels-1][s] += ['']
          self.workspace[self.nrmodels-1][s][2] = self.defaulttechnique
          self.workspace[self.nrmodels-1][s][3] = self.BLENDMODES[0]
      self.refreshOptionMenu(self.optws, self.models, self.activemodel, self.models.index(self.activemodel.get()))
      self.refreshOptionMenu(self.opttx, self.models, self.activemodel, self.models.index(self.activemodel.get()))

    def setParameters(self):
    # sets all workspace parameters from screen variables
      if self.activemodel.get()=='':
        return
      modelnr = self.models.index(self.activemodel.get())
      submodelnr = self.getActiveSubModel()
      # add submodel entry if missing
      if submodelnr+1>len(self.workspace[modelnr]):
        self.workspace[modelnr] += [[]]
        for p in range(len(self.PARAMS)):
          self.workspace[modelnr][submodelnr] += ['']
        self.workspace[modelnr][submodelnr][2] = self.defaulttechnique
        self.workspace[modelnr][submodelnr][3] = self.BLENDMODES[0]
      self.workspace[modelnr][submodelnr][0] = self.activemodel.get()
      self.workspace[modelnr][submodelnr][1] = self.objpath.get()
      self.workspace[modelnr][submodelnr][2] = self.technique.get()
      self.workspace[modelnr][submodelnr][3] = self.blendmode.get()
      self.workspace[modelnr][submodelnr][4] = self.faction.get()
      self.workspace[modelnr][submodelnr][5] = self.texmaster0.get()
      self.workspace[modelnr][submodelnr][6] = self.texmaster1.get()
      self.workspace[modelnr][submodelnr][7] = self.texmaster2.get()
      self.workspace[modelnr][submodelnr][8] = self.texmaster3.get()
      self.workspace[modelnr][submodelnr][9] = self.texmaster4.get()
      self.workspace[modelnr][submodelnr][10] = self.texmaster5.get()

    def getParameters(self):
    # sets all screen variables from workspace parameters
      try:
        modelnr = self.models.index(self.activemodel.get())
        submodelnr = self.getActiveSubModel()
        self.objpath.set(self.workspace[modelnr][0][1])
        self.technique.set(self.workspace[modelnr][submodelnr][2])
        self.blendmode.set(self.workspace[modelnr][submodelnr][3])
        self.faction.set(self.workspace[modelnr][submodelnr][4])
        self.texmaster0.set(self.workspace[modelnr][submodelnr][5])
        self.texmaster1.set(self.workspace[modelnr][submodelnr][6])
        self.texmaster2.set(self.workspace[modelnr][submodelnr][7])
        self.texmaster3.set(self.workspace[modelnr][submodelnr][8])
        self.texmaster4.set(self.workspace[modelnr][submodelnr][9])
        self.texmaster5.set(self.workspace[modelnr][submodelnr][10])
        self.updateMtlPath()
        self.refreshTextureInfo()
      except:
        pass

    def updateMtlPath(self):
    # updates the mtlpath entry
      if not(self.objpath.get()==''):
        (dirName, fileName) = os.path.split(self.objpath.get())
        (fileBaseName, fileExtension)=os.path.splitext(fileName)
        self.mtlpath.set(dirName+"/"+fileBaseName+".mtl")
      else:
        self.mtlpath.set('')

    def removeWorkspaceModel(self):
    # remove active model from workspace
      #print "Activemodel = ", self.activemodel.get()
      try:
        modelnr = self.models.index(self.activemodel.get())
        #print "removeWorkspaceModel: Moldelnr = ", modelnr
        del self.models[modelnr]
        del self.workspace[modelnr]
        self.activemodel.set(self.models[0])
        self.updateSubModels()
        self.updateSubunits()
        self.iniWrite()
        self.workspaceWrite()
      except:
        self.newWorkspace()
      self.refreshOptionMenu(self.optws, self.models, self.activemodel)
      self.refreshOptionMenu(self.opttx, self.models, self.activemodel)

    def newWorkspace(self):
    # create a new workspace
      self.models = ['']
      self.workspace = [[['']*11]]
      self.activemodel.set('')
      self.updateSubModels()
      self.objpath.set('')
      self.mtlpath.set('')
      self.unitname.set('')
      self.hudimage.set('')
      # reset material info
      for i in range(len(self.labels)):
        self.labels[i][0]['text'] = ''
        self.labels[i][1]['text'] = ''
      # set default technique and blendmode
      self.workspace[0][0][2] = self.defaulttechnique
      self.technique.set(self.defaulttechnique)
      self.workspace[0][0][3] = self.BLENDMODES[0]
      self.getParameters()
      self.nrmodels = 0
      self.resetUnitInfo()
      self.refreshOptionMenu(self.optws, self.models, self.activemodel)
      self.refreshOptionMenu(self.opttx, self.models, self.activemodel)
      self.iniWrite()

    def openWorkspace(self):
    # opens an ini file with the workspace
      file = self.getPath(None)
      if file=='':
        return
      (dirName, fileName) = os.path.split(file)
      (fileBaseName, fileExtension)=os.path.splitext(fileName)
      self.workdir.set(dirName)
      self.unitname.set(fileBaseName)
      self.activemodel.set(fileBaseName)
      self.workspaceRead()
      #self.updateWorkspace()
      self.readUnitCsv()
      self.readUnitUpgrades()
      self.readUnitWeapons()
      self.updateScreen()
      self.refreshOptionMenu(self.optws, self.models, self.activemodel)
      self.refreshOptionMenu(self.opttx, self.models, self.activemodel)

    def getUnitName(self):
    # generates standard (title case) unit name
      unitname = ''
      if len(self.models)>0:
        if not(self.models[0].lower().find("shield")==-1) and (len(self.models)>=2):
          unitname = self.models[1]
        else:
          unitname = self.models[0]
      return unitname

    def setUnitType(self):
    # guesses unit type for installations if not yet set
      if self.unittype.get()=='':
        unitname = self.unitname.get().lower()
        if (unitname.find('station')>0) or (unitname.find('base')>0) or (unitname.find('center')>0) or (unitname.find('barracks')>0) or (unitname.find('fortress')>0) or (unitname.find('factory')>0) or (unitname.find('outpost')>0) or (unitname.find('yard')>0) or (unitname.find('mine')>0) or (unitname.find('refinery')>0):
          self.unittype.set('Installation')
        else:
          self.unittype.set('Vessel')

    def workspaceHasShield(self):
    # returns true if a shield mesh is included in workspace
      hasshield = False
      for i in range(len(self.models)):
        if not(self.models[i].lower().find("shield")==-1):
          hasshield = True
      return hasshield

    def getWorkspaceMarker(self):
    # returns model index if an object with markers is included in workspace
      hasmount = -1
      for i in range(len(self.models)):
        if not(self.models[i].lower().find("marker")==-1):
          hasmount = i
      #print "Hasmount = ", hasmount
      return hasmount

    #--------------------------------------------------------------------------------------------
    # UNIT
    #--------------------------------------------------------------------------------------------

    def testUnitInVegastrike(self):
    # saves the mission file and starts Vegastrike with modelview.mission
      self.updateModelViewMission()
      if self.unittype.get()=='Installation':
        self.updateModelViewSystem()
      # verify if viewed model is edited model
      if (self.unitname.get().lower()==self.getUnitName().lower()):
        # verify if hud image was updated in units.csv
        if not(self.hudimage.get()==self.unit[7]):
          self.writeUnitCsv()
      # get operating system
      #print platform.system(), platform.release()
      self.platform = platform.system()
      if self.platform=='Linux':
        os.chdir(self.vegastrike.get()) #change to workdir
        command = self.vegastrike.get()+'/vegastrike modelview.mission'
        print "Command = ", command
        os.system(command) #execute command in workdir
      elif self.platform in ('Windows', 'Microsoft'):
        os.chdir(self.vegastrike.get()+'/bin') #change to workdir
        command = self.vegastrike.get()+'/bin/vegastrike modelview.mission'
        print "Command = ", command
        os.system(command) #execute command in workdir
      elif self.platform=='Darwin': # Mac
        os.chdir(self.vegastrike.get()+'/VegaStrike.app/Contents/MacOS') #change to workdir
        command = self.vegastrike.get()+'/VegaStrike.app/Contents/MacOS/vegastrike modelview.mission'
        print "Command = ", command
        os.system(command) #execute command in workdir
      else:
        os.chdir(self.vegastrike.get()) #change to workdir
        command = self.vegastrike.get()+'/vegastrike modelview.mission'
        print "Command = ", command
        os.system(command) #execute command in workdir

    def objGetDims(self):
    # reads model dimensions from obj file
      self.obj = ObjParse(self.workspace[0][0][1])
      dims = self.obj.getDimensions()
      self.unitlength.set(round(dims[0],4))
      self.unitwidth.set(round(dims[1],4))
      self.unitheight.set(round(dims[2],4))
      self.getObjMounts()
      #print "Object markers = ", self.getObjMounts()

    def getObjMounts(self):
    # reads marker points from "marker" obj file
      if (self.getWorkspaceMarker()>=0):
        self.obj = ObjParse(self.workspace[self.getWorkspaceMarker()][0][1])
        self.markers = self.obj.getObjectNames()
        self.centers = []
        self.forward = []
        self.up      = []
        self.radius      = []
        for i in range(len(self.markers)):
          self.centers += [self.obj.getHelperCenter(i)]
          self.forward += [self.obj.getHelperForward(i)]
          self.up      += [self.obj.getHelperUp(i)]
          self.radius  += [self.obj.getHelperRadius(i)]
      self.subunits = self.parseMounts(self.unitsubunits.get())
      return self.markers

    def resetUnit(self):
    # resets unit to workspace model unit
      self.resetUnitInfo()
      self.unitname.set(self.getUnitName())
      self.readUnitCsv()
      self.updateThruster()
      self.updateSubunits()
      self.updateDocks()
      self.iniWrite()

    def updateThruster(self):
    # update engine thruster parameters
      if not(self.unitname.get()=='') and (self.unitname.get().lower()==self.getUnitName().lower()):
        if self.getWorkspaceMarker()>=0:
          thruster = ''
          for i in range(len(self.markers)):
            if not(self.markers[i].lower().find('engine')):
              # {supernova.bmp.bfxm;0;0;-1260;100;;;;;}
              thruster += '{'
              if self.thrustertype.get()!='':
                thruster += self.thrustertype.get()
              else:
                thruster += 'supernova.bmp.bfxm'
              thruster += ';'+str(round(self.centers[i][0],2))+';'+str(round(self.centers[i][1],2))+';'+str(round(self.centers[i][2],2))+';'
              thruster += str(round(self.radius[i]*4,3)) + ';;;;;}'
              self.unitthrdia.set(round(self.radius[i]*4,3))
              #if (float(self.unitthrdia.get())>0):
              #  thruster += self.unitthrdia.get()+';;;;;}'
              #else:
              #  thruster += str(round(float(self.unitheight.get())/4,0))+';;;;;}'
              #  self.unitthrdia.set(round(float(self.unitheight.get())/4,0))
          self.unitthruster.set(thruster)
        else:
          self.displayThrusterDiameter()

    def displayThrusterDiameter(self):
    # parse diameter from units.csv
      mounts = self.parseMounts(self.unitthruster.get())
      if len(mounts)>0:
        self.unitthrdia.set(mounts[0][4])

    def parseMounts(self, mountlist):
    # parses mount entries from units.csv
    # e.g. {supernova.bmp.bfxm;0;0;-1260;100;;;;;}
    # e.g. {turretLR_PminusBeam;-0.65;-101.44;-14.37;0.0;0.0;1.0;0.0;-1.0;0.0;180.0}
      items = []
      mounts = mountlist.split('}')
      for m in mounts:
        if len(m)==0:
          mounts.remove(m)
        else:
          items += [m.split(';')]
          items[len(items)-1][0] = items[len(items)-1][0].split('{')[1]
          #print "Item = ", len(items[len(items)-1]), items[len(items)-1]
      #print "markers = ", len(mounts), mounts
      return items

    def updateSubunits(self):
    # update turret screen parameters
    # self.currentturret = screen counter
    # self.unitsubunits  = complete subunits column
    # self.subunittype   = option dropdown
    # self.subunits      = units.csv subunits list
    # self.markers       = obj marker helper list
    # self.smounts       = turret mount helper list
      self.subunits = self.parseMounts(self.unitsubunits.get())
      #print "updateSubunits - subunits csv", self.subunits
      #print "updateSubunits - mounts obj", self.markers
      self.smounts = []
      subunits = ''
      # create turret mounts from helper object
      if (self.getWorkspaceMarker()>=0) and (self.unitname.get().lower()==self.getUnitName().lower()):
        for i in range(len(self.markers)):
          if (self.markers[i].lower().find('turret')!=-1) or (self.markers[i].lower().find('subunit')!=-1):
            self.smounts += [self.markers[i]]
      # add entries to units.csv mounts if nr of mounts is greater than subunit entries
      if len(self.smounts)>len(self.subunits):
        for i in range(len(self.smounts)-len(self.subunits)):
          self.subunits += [''*10]
      # update screen
      if not(self.unitname.get()==''):
        # update type option
        if not(self.unitsubunits.get()=='') and (self.subunittype.get()==''):
          self.currentturret.set(1)
          if (len(self.smounts)>0):
            mountname = self.smounts[0].split('_')[1].split('.')[0]
            if self.findSubunitName(mountname)!='':
              self.subunittype.set(self.findSubunitName(mountname))
            else:
              self.subunittype.set(mountname)
            self.subunittypesource.set('(from marker)')
          else:
            self.subunittype.set(self.subunits[0][0])
            self.subunittypesource.set("(from units.csv)")
        # create subunits entry
        for i in range(len(self.subunits)):
          subunits += '{'
          # get subunits from obj mounts
          if not(self.currentturret.get()=='') and not(self.subunittype.get()=='') and (i<=len(self.smounts)-1):
            # and (i==int(self.currentturret.get())-1)  and (len(self.smounts)>0)
            index = self.markers.index(self.smounts[i])
            if (i==int(self.currentturret.get())-1): 
              subunits += self.subunittype.get()
            # get turret name from units
            #elif (len(self.subunits)>len(self.smounts)):
            else:
              subunits += self.subunits[i][0]
            #else:
            #  subunits += self.subunittype.get()
            subunits += ';'+str(round(self.centers[index][0],2))+';'+str(round(self.centers[index][1],2))+';'+str(round(self.centers[index][2],2))+';'
            subunits += str(round(self.forward[index][0],2))+';'+str(round(self.forward[index][1],2))+';'+str(round(self.forward[index][2],2))+';'
            subunits += str(round(self.up[index][0],2))+';'+str(round(self.up[index][1],2))+';'+str(round(self.up[index][2],2))+';'
            subunits += '180.0}'
          # get turret from units.csv
          else:
            for t in range(len(self.subunits[i])):
              if t>0: subunits += ';'
              subunits += self.subunits[i][t]
            subunits += '}'
        self.unitsubunits.set(subunits)

    def findSubunitName(self,mountname):
    # matches substring from helper object with preset turret type
      found = ''
      # find exact match
      for i in range(len(self.SUBUNITTYPES)):
        if self.SUBUNITTYPES[i]==mountname:
          found = self.SUBUNITTYPES[i]
          return found
      # find closest match
      for i in range(len(self.SUBUNITTYPES)):
        if self.SUBUNITTYPES[i].find(mountname)>=0:
          found = self.SUBUNITTYPES[i]
          return found
      return found

    def prevSubunit(self):
      if (len(self.subunits)>0):
        if (self.currentturret.get()=='') or (int(self.currentturret.get())==1):
          self.currentturret.set(len(self.subunits))
        elif int(self.currentturret.get())>1:
          self.currentturret.set(int(self.currentturret.get())-1)
        if (len(self.smounts)>=int(self.currentturret.get())) and (self.unitname.get().lower()==self.getUnitName().lower()):
          mountname = self.smounts[int(self.currentturret.get())-1].split('_')[1].split('.')[0]
          if self.findSubunitName(mountname)!='':
            self.subunittype.set(self.findSubunitName(mountname))
          else:
            self.subunittype.set(mountname)
          self.subunittypesource.set("(from marker)")
        else:
          self.subunittype.set(self.subunits[int(self.currentturret.get())-1][0])
          self.subunittypesource.set("(from units.csv)")

    def nextSubunit(self):
      if (len(self.subunits)>0):
        if self.currentturret.get()=='' or int(self.currentturret.get())==len(self.subunits):
          self.currentturret.set(1)
        elif int(self.currentturret.get())<len(self.subunits):
          self.currentturret.set(int(self.currentturret.get())+1)
        if (len(self.smounts)>=int(self.currentturret.get())) and (self.unitname.get().lower()==self.getUnitName().lower()):
          mountname = self.smounts[int(self.currentturret.get())-1].split('_')[1].split('.')[0]
          if self.findSubunitName(mountname)!='':
            self.subunittype.set(self.findSubunitName(mountname))
          else:
            self.subunittype.set(mountname)
          self.subunittypesource.set("(from marker)")
        else:
          self.subunittype.set(self.subunits[int(self.currentturret.get())-1][0])
          self.subunittypesource.set("(from units.csv)")

    def addUpgrade(self):
    # adds upgrade to upgrades screen parameters
      upgrades = self.unitupgrades.get()
      # update screen
      if not(self.upgradetype.get()==''):
        upgrades += '{'
        upgrades += self.upgradetype.get()+';;}'
      self.unitupgrades.set(upgrades)

    def updateDocks(self):
    # update docking points screen parameters
      if self.unitname.get()=='':
        return
      if self.unitdocks.get()!='':
        self.docks = self.parseMounts(self.unitdocks.get())
      self.dockmarkers = []
      docks = ''
      # create turret markers from helper object
      if (self.getWorkspaceMarker()>=0) and (self.unitname.get().lower()==self.getUnitName().lower()):
        for i in range(len(self.markers)):
          if (self.markers[i].lower().find('dock')!=-1):
            self.dockmarkers += [self.markers[i]]
      # create subunits entry
      if len(self.dockmarkers)>0:
        for i in range(len(self.dockmarkers)):
          # get subunits from obj mounts
          index = self.markers.index(self.dockmarkers[i])
          docks += '{;'+str(round(self.centers[index][0],2))+';'+str(round(self.centers[index][1],2))+';'+str(round(self.centers[index][2],2))+';'
          docks += str(round(self.radius[index]*2,2))+';' # size
          docks += '0}'
      # get turret from units.csv
      else:
        for i in range(len(self.docks)):
          docks += '{'
          for t in range(len(self.docks[i])):
            if t>0: docks += ';'
            docks += self.docks[i][t]
          docks += '}'
      self.unitdocks.set(docks)

    def getNextUnit(self):
    #reads next unit from units.csv and displays it
      self.unitcsv = VsUnitCsv(self.vegastrike.get()) # get class instance
      self.unitname.set(self.unitcsv.getUnitKey(currentUnitKey=self.unitname.get(), offset=+1))
      self.readUnitCsv()

    def getPreviousUnit(self):
    #reads next unit from units.csv and displays it
      self.unitcsv = VsUnitCsv(self.vegastrike.get()) # get class instance
      self.unitname.set(self.unitcsv.getUnitKey(currentUnitKey=self.unitname.get(), offset=-1))
      self.readUnitCsv()

    #--------------------------------------------------------------------------------------------
    # CONVERT
    #--------------------------------------------------------------------------------------------
    def saveAndConvert(self):
      print "saveAndConvert"
      self.saveMtl()
      self.convertObjBfxm()

    def saveMtl(self):
      print "Save MTL file(s)"
      currentmodel = self.activemodel.get() # remember selection
      for i in range(len(self.models)):
        if self.models[i].find('Marker')==-1:
          self.activemodel.set(self.models[i])
          self.getParameters()
          self.updateWorkspace()
          self.readObjMaterials()
          self.refreshTextureInfo()
          #print "saveMtl - tex", self.textures
          (dirName, fileName) = os.path.split(self.mtlpath.get())
          (fileBaseName, fileExtension)=os.path.splitext(fileName)
          if self.backupobj.get()=='1':
            try: # backup mtl
              shutil.copyfile(self.mtlpath.get(), dirName+"/"+fileBaseName+".mtl~") # backup file
              print "Backup file "+dirName+"/"+fileBaseName+".mtl"
            except:
              pass
          modelnr = self.models.index(self.activemodel.get())
          #print "saveMtl - Model", self.activemodel.get()
          #print "saveMtl - mtl", self.mtlpath.get()
          #print "saveMtl - mat", self.materials
          #print "saveMtl - tex", self.textures
          techniques = []
          blendmodes = []
          for t in range(len(self.workspace[i])):
            techniques += [self.workspace[i][t][2]]
            blendmodes += [self.workspace[i][t][3]]
          #print "saveMtl - techniques", techniques
          #print "saveMtl - blendmodes", blendmodes
          saveMtl(self.mtlpath.get(), self.materials, self.textures, techniques, blendmodes, modelnr)
      # restore previous active model
      self.activemodel.set(currentmodel)
      self.getParameters()
      self.updateWorkspace()
      self.readObjMaterials()

    def convertBfxmObj(self):
    # call mesher and convert obj file to bfxm
      print "Converting BFXM file to OBJ"
      currentmodel = self.activemodel.get() # remember selection
      (dirName, fileName) = os.path.split(self.objpath.get())
      (fileBaseName, fileExtension)=os.path.splitext(fileName)
      os.chdir(dirName) #change to workdir
      command = self.mesherpath.get()+" "+fileName+" "+currentmodel.lower()+".obj"+" "
      command += "boc"
      print "Command = ", command
      result = os.system(command) #execute command in workdir
      print "Model converted to "+fileBaseName.lower()+".obj"
      # restore previous active model

    def convertObjBfxm(self):
    # call mesher and convert obj file to bfxm
      print "Converting OBJ file(s) to BFXM"
      currentmodel = self.activemodel.get() # remember selection
      # swap models, if first one is shield
      if not(self.models[0].lower().find("shield")==-1) and len(self.models)>0:
        basemodel = self.models[1]
        self.models[1] = self.models[0]
        self.models[0] = basemodel
        workspace = self.workspace[1]
        self.workspace[1] = self.workspace[0]
        self.workspace[0] = workspace
      basemodel = self.models[0]
      for i in range(len(self.models)):
        self.activemodel.set(self.models[i])
        self.getParameters()
        (dirName, fileName) = os.path.split(self.objpath.get())
        (fileBaseName, fileExtension)=os.path.splitext(fileName)
        os.chdir(dirName) #change to workdir
        print "Directory = ", os.getcwd() #print working dir
        if self.backupobj.get()=='1':
          try: # backup bfxm
            shutil.copyfile(dirName+"/"+fileBaseName.lower()+".bfxm", dirName+"/"+fileBaseName.lower()+".bfxm~") # backup file
            print "Backup file "+dirName+"/"+fileBaseName.lower()+".bfxm"
          except:
            pass
          try: # backup xmesh
            shutil.copyfile(dirName+"/"+fileBaseName.lower()+".xmesh", dirName+"/"+fileBaseName.lower()+".xmesh~") # backup file
            print "Backup file "+dirName+"/"+fileBaseName.lower()+".xmesh"
          except:
            pass
        # convert shield into separate file but don't convert mounts
        if self.models[i].lower().find("shield")!=-1 and self.models[i].lower().find("marker")==-1:
          command = self.mesherpath.get()+" "+fileName+" "+fileBaseName.lower()+".bfxm"+" obc"
          print "Command = ", command
          result = os.system(command) #execute command in workdir
          print "Model converted to "+fileBaseName.lower()+".bfxm"
        elif self.models[i].lower().find("marker")==-1:
          # convert submeshes adding them to one bfxm file
          if (i==0):
            command = self.mesherpath.get()+" "+fileName+" "+basemodel.lower()+".bfxm"+" "
            command += "obc"
          else:
            command = self.mesherpath.get()+" "+fileName+" "+basemodel.lower()+".bfxm"+" "
            command += "oba"
          print "Command = ", command
          result = os.system(command) #execute command in workdir
          print "Model converted to "+fileBaseName.lower()+".bfxm"
        # convert to xmesh, too
        if self.createxmesh.get()=='1' and self.models[i].lower().find("marker")==-1:
          command = self.mesherpath.get()+" "+fileBaseName.lower()+".bfxm "+fileBaseName.lower()+".xmesh"+" bxc"
          result = os.system(command) #execute command in workdir
          print "Model converted to "+fileBaseName.lower()+".xmesh"
      # restore previous active model
      self.activemodel.set(currentmodel)
      self.getParameters()

    def compressTextures(self):
    # execute nvcompress
      if self.inputtex.get()=='1': #if using uncompressed input textures
        return
      (dirName, fileName) = os.path.split(self.objpath.get())
      commandBase = self.nvcompresspath.get()
      compressionBase = "-bc1" #DXT1 compression
      os.chdir(dirName) #change to workdir
      print "Directory = ", os.getcwd() #print working dir
      modelnr = self.models.index(self.activemodel.get())
      self.obj = ObjParse(self.workspace[modelnr][0][1])
      nrsubmodels = max(len(self.obj.getObjectNames()),1)
      submodelnr = self.getActiveSubModel()
      for s in range(nrsubmodels):
        if self.faction.get()!='' and s==submodelnr:
          faction = self.faction.get()+'_'
        else:
          faction = ''
        for j in range(len(self.textures[s])):
          if self.textures[s][j][0][4]=="0" and not(self.workspace[modelnr][s][5]==""):
            texmaster = faction+self.workspace[modelnr][s][5]
            compressionBase = "-bc1" #DXT1 compression
          if self.textures[s][j][0][4]=="1" and not(self.workspace[modelnr][s][6]==""):
            texmaster = faction+self.workspace[modelnr][s][6]
            compressionBase = "-bc1" #DXT1 compression
          if self.textures[s][j][0][4]=="2" and not(self.workspace[modelnr][s][7]==""):
            texmaster = faction+self.workspace[modelnr][s][7]
            compressionBase = "-bc1" #DXT1 compression
          if self.textures[s][j][0][4]=="3" and not(self.workspace[modelnr][s][8]==""):
            texmaster = faction+self.workspace[modelnr][s][8]
            compressionBase = "-bc2" #DXT3 compression
          if self.textures[s][j][0][4]=="4" and not(self.workspace[modelnr][s][9]==""):
            texmaster = faction+self.workspace[modelnr][s][9]
            compressionBase = "-bc1" #DXT1 compression
          # compress texture
          command = commandBase + " " + compressionBase + " " + texmaster + " " + self.getTextureForMaster(modelnr,s,self.textures[s][j][0][4])
          if texmaster.find('.ani')==-1:
            print "Command = ", command
            os.system(command) #execute command in workdir
            # print dds stats
            #command = "nvddsinfo " + self.getTextureForMaster(modelnr,s,self.textures[s][j][0][4])
            #os.system(command) #execute command in workdir
      print "Model textures have been compressed"

    def compressHudImage(self):
    # execute nvcompress for hud image and write .sprite file
      if self.objpath.get()!='':
        (dirName, fileName) = os.path.split(self.objpath.get())
        os.chdir(dirName) #change to workdir
      elif self.workdir.get()!='':
        dirName = self.workdir.get()
        os.chdir(dirName) #change to workdir
      commandBase = self.nvcompresspath.get()
      print "Directory = ", os.getcwd() #print working dir
      if self.hudimage.get()!='':
        #(dirName, fileName) = os.path.split(self.objpath.get())
        fileName = self.hudimage.get()
        (fileBaseName, fileExtension)=os.path.splitext(fileName)
        compressionBase = "-bc2 -nomips" #DXT3 compression without mipmaps
        # compress image
        command = commandBase + " " + compressionBase + " " + fileName + " " + fileBaseName.lower() + ".image"
        print "Command = ", command
        os.system(command) #execute command in workdir
        # print dds stats
        #command = "nvddsinfo " + fileBaseName.lower()+".image"
        #os.system(command) #execute command in workdir
        print "Hud image is now compressed"
        # now write the sprite file
        spritefile = dirName+'/'+fileBaseName.lower()+'.sprite'
        print "Spritefile = ", spritefile
        f=open(dirName+'/'+fileBaseName.lower()+'.sprite', 'w')
        f.write(fileBaseName.lower()+'.image '+fileBaseName.lower()+'.image\n')
        f.write('256 256\n') # scale
        f.write('0 0\n') # position
        f.close()
        print "Sprite file written"

    def copyData(self):
    # copy model and textures to units data folder
      currentmodel = self.activemodel.get() # remember selection
      self.activemodel.set(self.getUnitName())
      # make folder
      if self.useclassdir.get()=='1':
        unitFolder = self.vegastrike.get()+'/units/'+self.unittype.get().lower()+'s/'+self.unitname.get()
      else:
        unitFolder = self.vegastrike.get()+'/units/'+self.unitname.get()
      print "Unit dir = ", unitFolder
      try:
        os.mkdir(unitFolder)
      except:
        pass
      # copy all bfxm and textures
      for i in range(len(self.models)):
        self.activemodel.set(self.models[i])
        self.updateSubModels()
        self.getParameters()
        #self.refreshTextureInfo()
        if self.models[i].lower().find("marker")==-1:
          copyFileSrc = self.workdir.get()+"/"+self.activemodel.get().lower()+".bfxm"
          copyFileTgt = unitFolder+"/"+self.activemodel.get().lower()+".bfxm"
          print "Copy", self.activemodel.get().lower()+'.bfxm'
          try:
            shutil.copyfile(copyFileSrc, copyFileTgt) # copy file
          except:
            pass
          # copy textures
          self.obj = ObjParse(self.workspace[i][0][1])
          nrsubmodels = max(len(self.obj.getObjectNames()),1)
          for s in range(nrsubmodels):
            for j in range(len(self.textures[s])):
              if (self.inputtex.get()=='1') or (j==5): #if using uncompressed input textures
                texture = self.textures[s][j][1]
              else:
                texture = self.getTextureForMaster(i,s,self.textures[s][j][0][4])
              copyFileSrc = self.workdir.get()+"/"
              if not(self.faction.get()==''):
                copyFileSrc += self.faction.get()+'_'
              copyFileSrc += texture
              copyFileTgt = unitFolder+"/"
              if not(self.faction.get()==''):
                copyFile = self.faction.get()+'_'
              else:
                copyFile = ''
              copyFile += texture
              copyFileTgt += copyFile
              print "Copy", copyFile
              try:
                shutil.copyfile(copyFileSrc, copyFileTgt) # copy file
              except:
                pass
      # copy hud image
      if not(self.hudimage.get()==''):
        (dirName, fileName) = os.path.split(self.hudimage.get())
        (fileBaseName, fileExtension)=os.path.splitext(fileName)
        copyFileSrc = self.workdir.get()+"/"+fileName
        copyFileTgt = unitFolder+"/"+fileBaseName.lower()+".image"
        print 'Copy', fileBaseName.lower()+'.image'
        try:
          shutil.copyfile(copyFileSrc, copyFileTgt) # copy file
        except:
          pass
      # copy sprite file
      if not(self.hudimage.get()==''):
        copyFileSrc = self.workdir.get()+"/"+fileBaseName.lower()+".sprite"
        copyFileTgt = unitFolder+"/"+fileBaseName.lower()+".sprite"
        print 'Copy', fileBaseName.lower()+'.sprite'
        try:
          shutil.copyfile(copyFileSrc, copyFileTgt) # copy file
        except:
          pass
      # restore previous active model
      self.activemodel.set(currentmodel)
      self.getParameters()

    #--------------------------------------------------------------------------------------------
    # DISPLAY
    #--------------------------------------------------------------------------------------------
    def updateScreen(self):
    # updates all screen variables
      self.readObjMaterials()
      self.refreshTextureInfo()
      self.validateInputs()
      # update base unit name
      if self.unitname.get()=='':
        self.unitname.set(self.getUnitName())
      # update units.csv shield entry
      for i in range(len(self.models)):
        if not(self.models[i].lower().find("shield")==-1):
          self.unitshieldmesh.set(self.unitname.get().lower()+'-shield.bfxm')
      if not(self.hudimage.get()==''):
        self.unithud.set(self.unitname.get().lower()+'-hud.sprite')
      # update engine and turret info
      self.updateThruster()
      self.updateSubunits()
      self.updateDocks()
      self.updateSubModels()

    def updateSubModels(self):
    # updates screen display of submodels
      self.obj = ObjParse(self.objpath.get())
      self.submodels = self.obj.getObjectNames()
      if len(self.submodels)==0 or self.activemodel.get().lower().find('marker')!=-1:
        self.submodels = ['default']
      self.submodelsListBox.delete(0, END) # clear
      for item in self.submodels:
        self.submodelsListBox.insert(END, item)
      self.submodelsListBox.selection_set(0)

    def readObjMaterials(self):
    # reads material library and material information from obj file and displays materials
      self.materials = {}
      # read object names from marker obj
      if (self.activemodel.get().lower().find('marker')!=-1) and (len(self.models)>0):
        self.objmat = {}
        self.objmat[0] = ["","Marker Objects"]
        for i in range(len(self.markers)):
          self.objmat[i+1] = ["",self.markers[i]]
      # otherwise for models show the materials names
      else:
        self.objmat = GetObjMaterial(self.objpath.get())
      self.nrmaterials = 0
      # write new obj mtl information
      for i in range(len(self.objmat)):
        # if labels don't exist, create them
        if (i>=len(self.objtext)):
            # make headers
            if (i==0) and (self.nrobjentries==0):
              self.header0 = self.displayHeader(self.f1,"Material Info - Library")
            if (i==1) and (self.nrobjentries==0):
              self.header1 = self.displayHeader(self.f1,"Material Info - Materials")
            #display materials
            iframe = Frame(self.f1, relief=FLAT)
            self.objtext[i] = [StringVar(),StringVar()]
            self.objtext[i][0].set(self.objmat[i][0]) 
            self.objtext[i][1].set(self.objmat[i][1])
            label1 = Label(iframe, text=self.objtext[i][0].get())
            label1.pack(side=LEFT, padx=5)
            label2 = Label(iframe, text=self.objtext[i][1].get())
            label2.pack(side=LEFT, padx=5)
            self.labels += [[label1, label2]]
            iframe.pack(expand=1, fill=X, pady=0, padx=5)
        # if labels exist, update their entries
        else:
          self.objtext[i][0].set(self.objmat[i][0])
          self.objtext[i][1].set(self.objmat[i][1])
          # this updates the material labels display
          for l in range(len(self.labels)):
            self.labels[l][0]['text'] = self.objtext[l][0].get()
            self.labels[l][1]['text'] = self.objtext[l][1].get()
        # assign materials
        if (self.objmat[i][0] in ('usemtl', 'usemat')):
          self.materials[self.nrmaterials] = self.objmat[i][1]
          self.nrmaterials += 1
      self.nrobjentries = len(self.objmat)
      # if there are too many labels, empty them
      if (len(self.objmat)<len(self.labels)):
        for l in range(len(self.objmat),len(self.labels)):
          self.labels[l][0]['text'] = ''
          self.labels[l][1]['text'] = ''

    def displayHeader(self,frame,titleText):
    # displays a title line across frame width
      iframe = Frame(frame, relief=FLAT)
      header = Label(iframe, text=titleText, bg="#483855", fg="#BFB8FE")
      header.pack(fill=BOTH, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      return iframe

    def displayTextBox(self, frame, lines, text, finalstate=NORMAL, scroll=True):
    # creates a row frame with text widget and writes text
      iframe = Frame(frame, relief=FLAT)
      textbox = Text(iframe, wrap=WORD, width=200, height=lines, relief=FLAT, bg="#DFDFFF", fg="#000033")
      if scroll:
        scrollbar = Scrollbar(iframe)
        scrollbar.pack(side=RIGHT, fill=Y)
        textbox.config(yscrollcommand=scrollbar.set)
        scrollbar.config(command=textbox.yview)
      textbox.insert(INSERT, text)
      textbox.config(state=finalstate)
      textbox.pack(side=LEFT, fill=X, padx=5)
      iframe.pack(expand=1, fill=BOTH, pady=5, padx=5)
      return textbox

    def refreshOptionMenu(self, optMenu, newValues, watchVariable, preselectIndex=0):
    # rebuilds the option menu entries after a change
      #print "refreshOptionMenu: Values = ", newValues
      # delete old options
      m = optMenu.children['menu']
      m.delete(0,END)
      # set new options
      for i in range(len(newValues)):
        val = newValues[i]
        m.add_command(label=val, command=lambda v=watchVariable,l=val:watchVariable.set(l))
      if len(newValues)==0:
        watchVariable.set("")
        print "ERROR (refreshOptionMenu): empty newValues list given. Setting index to ''."
      try:
        watchVariable.set(newValues[preselectIndex])
      except:
        print "ERROR (refreshOptionMenu): wrong index for newValues list. Setting index 0."
        watchVariable.set(newValues[0])

    def resetUnitInfo(self):
    # resets screen variables in unit editor
      self.unitdescription.set('')
      self.unitdescr.delete(1.0, END)
      self.unittype.set('')
      self.unitrole.set('')
      self.unithud.set('')
      self.unitmesh.set('')
      self.unitshieldmesh.set('')
      self.unitcockpit.set('')
      self.unitlength.set('')
      self.unitwidth.set('')
      self.unitheight.set('')
      self.unitscale.set('')
      self.unitthruster.set('')
      self.unitsubunits.set('')
      self.unitthruster.set('')
      self.unitthrdia.set('')
      self.thrustertype.set('')
      self.unitupgrades.set('')
      self.subunittype.set('')
      self.upgradetype.set('')
      self.currentturret.set('')
      self.subunittypesource.set('')
      self.unitmounts.set('')
      self.upgradeclass.set('')
      self.unitdocks.set('')
      self.unitsounds.set('')
      self.unitcargo.set('')
      self.unitcargoimport.set('')
      self.unitmass.set('')
      self.unitinertia.set('')
      self.unitfuel.set('')
      self.unithull.set('')
      self.unitarmor.set('')
      self.unitshield.set('')
      self.unitshieldrecharge.set('')
      self.unitupgradevolume.set('')
      self.unitholdvolume.set('')
      self.unitspeed.set('')
      self.unitoverdrive.set('')
      self.unitoverdriveaccel.set('')
      self.unitoverdrivetype.set('')
      self.unitoverdrivecost.set('')
      self.unitaccelforward.set('')
      self.unitaccelretro.set('')
      self.unitaccelleft.set('')
      self.unitaccelright.set('')
      self.unitacceltop.set('')
      self.unitaccelbottom.set('')
      self.unitgovernoryaw.set('')
      self.unitgovernorpitch.set('')
      self.unitgovernorroll.set('')
      self.unitmaneuveryaw.set('')
      self.unitmaneuverpitch.set('')
      self.unitmaneuverroll.set('')
      self.unitcapacitorprimary.set('')
      self.unitcapacitorwarp.set('')
      self.unitreactorrecharge.set('')
      self.unitjumpdrive.set('')
      self.unitjumpcost.set('')
      self.unitwarpcost.set('')
      self.unititts.set('')
      self.unitradarcolor.set('')
      self.unitradarrange.set('')
      self.unitconetracking.set('')
      self.unitconemax.set('')
      self.unitconelock.set('')

    #--------------------------------------------------------------------------------------------
    # INIT
    #--------------------------------------------------------------------------------------------
    def __init__(self, master):
    # initiate aplication
      master.title("Unit Converter OBJ->BFXM") # application title
      self.appdir = os.getcwd()  # get application dir
      config = ConfigParser.ConfigParser() # instance config class
      config.read(self.appdir+"/unitconverter.ini") # read the config file
      master.geometry("860x600") # window size on instantiation
      window = AppWindow(master, LEFT) # create main frame with left side menu
    # initiate variables
      self.nrobjentries = 0 # OBJ file *mtl* entries count
      self.nrmaterials = 0  # materials count
      self.nrtextures = 0   # selected textures count
      self.nrmodels = 0     # models count - reserved for future use in submeshes
      self.help = ''        # help text
      self.defaulttechnique = ''
      self.FACTIONS = ["(default)","privateer","aera","andolian","confed","dgn","forsaken","highborn","homeland-security","hunter","ISO","klkk","LIHW","luddites","mechanist","merchant_guild","pirates","purist","shaper","shmrn","rlaan","rlaan_briin","uln","unadorned","aeran_merchant_marine","andolian_citizen","dgn_citizen","forsaken_citizen","highborn_citizen","klkk_citizen","LIHW_citizen","mechanist_citizen","merchant_guild_citizen","purist_citizen","rlaan_citizen","shaper_citizen","shmrn_citizen","uln_citizen","unadorned_citizen"]
      self.TECHNIQUES = ["(none)","cinemut_opaque","cinemut_fireglass","highend","default","fixed","highend_simple","fixed_simple","sample","cel","cel_simple","fixed5","fixedgl"]
      self.BLENDMODES = ["['0','ONE ZERO']","['0.5','SRCALPHA INVSRCALPHA']","['1','ONE ONE']"]
      self.PARAMS = ["NAME","OBJ_PATH","TECHNIQUE","BLENDMODE","FACTION","TEXTURE_0","TEXTURE_1","TEXTURE_2","TEXTURE_3","TEXTURE_4","TEXTURE_5"]
      self.UNITTYPES = ["Vessel","Installation"]
      self.UNITROLES = ["BASE","BOMB","BOMBER","CAPITAL","CARGO","CARRIER","ESCORTCAP","FIGHTER","GROUND","HEAVYMISSILE","INERT","INTERCEPTOR","MINE","MISSILE","POINTDEF","SCAVENGER","SHUTTLE","SUPPORT"]
      self.SUBUNITTYPES = ['aeraturretadvtorp','aeraturretcapshipgun','aeraturretLR_heavy','aeraturretLR_heavygun','aeraturretpd','aeraturretRLR_pd','franklinpd','rlaanturret','rlaanturretgun','rlaanturretmini','rlaanturretminigun','rlaanturretpd','rlaanturretpdgun','turret','turretbeam','turretbeamgun','turretbeamheavy','turretbeamheavygun','turretbeampgun','turretcapmissile', 'turretcapmissiledeep',  'turret_capship_dreadnaughtblend', 'turret_capship_dreadnaughtblend_guns', 'turret_capship_gun', 'turret_capship_layered_defense', 'turret_capship_layered_defense_guns', 'turret_capship_light_particlebeamgun', 'turret_capship_pd_gun', 'turret_capship_torplauncher', 'turret_capship_torplauncher_gun', 'turretflak', 'turretflakgun', 'turretgun', 'turretgunheavy', 'turretgunsmall', 'turretheavy', 'turretlauncher', 'turretlaunchercapmissile', 'turretlaunchergun', 'turretlauncherswarm','turretLR_PminusBeam', 'turretmain', 'turretmaingun', 'turretmaingunheavy', 'turretmainheavy', 'turret_medium', 'turret_medium_gun', 'turretpd', 'turretpdgun', 'turretpdlong', 'turretpdlonggun', 'turretpunisher', 'turretpunishergun', 'subunitsmall', 'subunitswarm']
      self.THRUSTTYPES = ['supernova.bmp.bfxm','aeraburn.bfxm','thrust1.bfxm','confedburn.bfxm']
      self.UPGRADES = ['']
      self.UPGRADECLASSES = ['']
      self.labels = []      # for dynamically creating labels with material names
      self.textures = {}    # stores selected textures
      self.materials = {}   # stores material names
      self.models = ['']    # variable that stores model names
      self.submodels = ['']  # variable that stores obj subunit names
      self.objtext = {}     # text variable for displaying the OBJ file materials
      self.workspace = [[[]]] # for workspace model parameters
      self.markers = []      # for marker helper import
      self.upgrades = []
      self.centers = []     # marker centers
      self.docks = []       # docking ports
      self.objpath = StringVar()        # OBJ file address
      self.mtlpath = StringVar()        # MTL file address
      self.nvcompresspath = StringVar() # command with address to nvcompress including the nvcompress app
      self.mesherpath = StringVar()     # command with address to mesher including the mesher app
      self.workdir = StringVar()        # working directory
      self.vegastrike = StringVar()     # Vega Strike installation directory root
      self.useclassdir = StringVar()    # use units/vessels or just units/ to store the model
      self.backupobj = StringVar()      # backup obj/mtl files if checked
      self.createxmesh = StringVar()    # create xmesh files if checked
      self.inputtex = StringVar()       # use input (not compressed textures) if checked
      self.activemodel = StringVar()    # active model name in title case
      self.faction = StringVar()        # faction name
      self.technique = StringVar()      # technique parameter
      self.blendmode = StringVar()      # blend mode parameter
      self.texmaster0 = StringVar()     # uncompressed (input) texture
      self.texmaster1 = StringVar()
      self.texmaster2 = StringVar()
      self.texmaster3 = StringVar()
      self.texmaster4 = StringVar()
      self.texmaster5 = StringVar()
      self.texmaster6 = StringVar()
      self.texmaster7 = StringVar()
      self.texture0 = StringVar()       # compressed (output) texture
      self.texture1 = StringVar()
      self.texture2 = StringVar()
      self.texture3 = StringVar()
      self.texture4 = StringVar()
      self.texture4 = StringVar()
      self.texture5 = StringVar()
      self.texture6 = StringVar()
      self.texture7 = StringVar()
      self.hudimage = StringVar()
      self.upgradeclass = StringVar()
      self.upgradetype = StringVar()
      self.missionfaction = StringVar()
      self.currentturret = StringVar()
      self.thrustertype = StringVar()
      self.subunittypesource = StringVar()
      # units.csv variables
      self.unitname = StringVar()       # unit base name
      self.unitdescription = StringVar()
      self.unittype = StringVar()
      self.unitrole = StringVar()
      self.unithud = StringVar()
      self.unitmesh = StringVar()
      self.unitshieldmesh = StringVar()
      self.unitlength = StringVar()
      self.unitwidth = StringVar()
      self.unitheight = StringVar()
      self.unitscale = StringVar()
      self.unitcockpit = StringVar()
      self.unitthruster = StringVar()
      self.unitthrdia = StringVar()
      self.unitsubunits = StringVar()
      self.unitupgrades = StringVar()
      self.unitcargo = StringVar()
      self.unitcargoimport = StringVar()
      self.subunittype = StringVar()
      self.unitmounts = StringVar()
      self.unitdocks = StringVar()
      self.unitsounds = StringVar()
      self.unitmass = StringVar()             # unit mass
      self.unitinertia = StringVar()
      self.unitfuel = StringVar()
      self.unithull = StringVar()
      self.unitarmor = StringVar()
      self.unitshield = StringVar()
      self.unitshieldquad = StringVar()
      self.unitshieldrecharge = StringVar()
      self.unitupgradevolume = StringVar()
      self.unitholdvolume = StringVar()
      self.unitspeed = StringVar()
      self.unitoverdrive = StringVar()
      self.unitoverdriveaccel = StringVar()
      self.unitoverdrivetype = StringVar()
      self.unitoverdrivecost = StringVar()
      self.unitaccelforward = StringVar()
      self.unitaccelretro = StringVar()
      self.unitaccelleft = StringVar()
      self.unitaccelright = StringVar()
      self.unitacceltop = StringVar()
      self.unitaccelbottom = StringVar()
      self.unitgovernoryaw = StringVar()
      self.unitgovernorpitch = StringVar()
      self.unitgovernorroll = StringVar()
      self.unitmaneuveryaw = StringVar()
      self.unitmaneuverpitch = StringVar()
      self.unitmaneuverroll = StringVar()
      self.unitcapacitorprimary = StringVar()
      self.unitcapacitorwarp = StringVar()
      self.unitreactorrecharge = StringVar()
      self.unitjumpdrive = StringVar()
      self.unitjumpcost = StringVar()
      self.unitwarpcost = StringVar()
      self.unititts = StringVar()
      self.unitradarcolor = StringVar()
      self.unitradarrange = StringVar()
      self.unitconetracking = StringVar()
      self.unitconemax = StringVar()
      self.unitconelock = StringVar()

      #--------------------------------------------------------------------------------------------
      # WORKSPACE, MODEL OBJ AND MTL FILES
      #--------------------------------------------------------------------------------------------
      self.f1 = f1 = Frame(window()) # tab frame
      # HELP
      self.help = "INSTRUCTIONS: Browse (Add Model) for the model (OBJ or BFXM) file you want to add to the workspace.\n"
      self.help += "You can (Remove) the active model from the workspace, or make a new empty workspace (Clear Workspace). Then proceed to Textures.  [scroll down for more]\n"
      self.help += "Information on model requirements can be found in the VS Wiki: http://vegastrike.sourceforge.net/wiki/Development:Model_Guidelines"
      self.displayTextBox(self.f1, 4, self.help, DISABLED)
      # WORKSPACE
      self.displayHeader(self.f1,"Workspace") # header line
      # model dropdown for workspace
      iframe = Frame(self.f1, relief=FLAT)
      Label(iframe, text="Active model", width=18).pack(side=LEFT, padx=5)
      self.optws = OptionMenu(iframe, self.activemodel, *self.models)
      self.optws.pack(side=LEFT, padx=5)
      Button(iframe, text='Add Model', command=lambda:self.getPath(self.objpath), bg="#BFB8FE", fg="#483855").pack(side=LEFT, padx=5)
      Button(iframe, text='Remove Model', command=lambda:self.removeWorkspaceModel(), bg="#BFB8FE", fg="#483855").pack(side=LEFT, padx=5)
      Button(iframe, text='Clear Workspace', command=lambda:self.newWorkspace(), bg="#BFB8FE", fg="#483855").pack(side=LEFT, padx=5)
      Button(iframe, text='Load Workspace', command=lambda:self.openWorkspace(), bg="#BFB8FE", fg="#483855").pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # ACTIVE MODEL
      self.displayHeader(self.f1,"Model Files") # header line
      # row frame
      iframe = Frame(f1, relief=FLAT)
      Label(iframe, text="OBJ File", width=10).pack(side=LEFT, padx=5)
      Entry(iframe, width=80, textvariable=self.objpath).pack(side=LEFT, padx=5)
      Button(iframe, text='...', command=lambda:self.getPath(self.objpath)).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # row frame
      iframe12 = Frame(f1, relief=FLAT)
      Label(iframe12, text="MTL File", width=10).pack(side=LEFT, padx=5)
      Entry(iframe12, textvariable=self.mtlpath).pack(padx=5, fill=BOTH)
      #Button(iframe12, text='...', command=lambda:self.getPath(self.mtlpath)).pack(side=LEFT, padx=5)
      iframe12.pack(expand=1, fill=X, pady=0, padx=5)

      #--------------------------------------------------------------------------------------------
      # MATERIALS AND TEXTURES
      #--------------------------------------------------------------------------------------------
      self.f2 = f2 = Frame(window()) # tab frame
      # HELP
      self.help = "INSTRUCTIONS: Here you can set texture and shader options for the active model in the workspace. Browse for the master textures that are provided and leave the missing ones empty.\n"
      self.help += "Compressed texture names will be set automatically. Select a faction for faction textures (not required for default texture). You can clean all textures with the top 'x' button, or each individual texture with the 'x' buttons on the right. [scroll down for more]\n"
      self.help += "You can further change the default parameters for technique and blend mode before exporting and converting the model.\n"
      self.help += "Save and Convert or just individually save the MTL file and then Convert to BFXM. You'll need to configure the address of the VS mesher tool beforehand in the Config section.\n"
      self.help += "You may compress the master textures to dds if you have nVidia's nvcompress installed and configured the command path under Config.\n"
      self.help += "Finally, you can copy all required files to the data units folder. A new folder will be created for you if required. Vega Strike data dir must also be set correctly in Config."
      self.displayTextBox(self.f2, 4, self.help, DISABLED)
      # ACTIVE MODEL
      self.displayHeader(self.f2,"Model & Submodels") # header line
      # row frame
      iframe = Frame(f2, relief=FLAT)
      Label(iframe, text="Active model", width=16, anchor=E).pack(side=LEFT, padx=5)
      self.opttx = OptionMenu(iframe, self.activemodel, *self.models)
      self.opttx.pack(side=LEFT, padx=5)
      Label(iframe, text="Submodels", width=16, anchor=E).pack(side=LEFT, padx=5)
      #self.submodelscont = None
      scrollbar = Scrollbar(iframe, orient=VERTICAL)
      self.submodelsListBox = Listbox(iframe, yscrollcommand=scrollbar.set, width=40, height=2, selectmode=EXTENDED)
      self.submodelsListBox.pack(fill=X, side=LEFT)
      scrollbar.config(command=self.submodelsListBox.yview)
      scrollbar.pack(side=RIGHT, fill=Y)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # TEXTURES
      self.displayHeader(self.f2,"Texture Assignment") # header line
      # list - disbled
      #lframe = Frame(self.f2, relief=FLAT)
      #scrollbar = Scrollbar(lframe, orient=VERTICAL)
      #self.mtlListBox = Listbox(lframe, yscrollcommand=scrollbar.set, width=20, height=2)
      #self.mtlListBox.pack(side=LEFT)
      #scrollbar.config(command=self.mtlListBox.yview)
      #scrollbar.pack(side=RIGHT, fill=Y)
      #lframe.pack()
      # options dropdown for faction textures
      iframe = Frame(f2, relief=FLAT)
      Label(iframe, text="Faction", width=10, anchor=E).pack(side=LEFT, padx=5)
      apply(OptionMenu, (iframe, self.faction) + tuple(self.FACTIONS)).pack(side=LEFT, padx=5)
      Button(iframe, text='x', command=lambda:self.deleteFactionEntry()).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # row
      iframe = Frame(self.f2, relief=FLAT)
      Label(iframe, text="", width=16).pack(side=LEFT, padx=5)
      Label(iframe, text="Input Texture", width=30).pack(side=LEFT, padx=5)
      Label(iframe, text="", width=4).pack(side=LEFT, padx=5)
      Label(iframe, text="Output Texture", width=30).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # row
      iframe = Frame(self.f2, relief=FLAT)
      Label(iframe, text="Texture 0 (diffuse)", width=16, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=30, textvariable=self.texmaster0).pack(side=LEFT, padx=5)
      Button(iframe, text='...', command=lambda:self.getFileAndUpdateMaterial(self.getFile,self.texmaster0, 0)).pack(side=LEFT, padx=5)
      Entry(iframe, width=30, textvariable=self.texture0).pack(side=LEFT, padx=5)
      Button(iframe, text='x', command=lambda:self.deleteEntry(self.texmaster0)).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # row frame
      iframe = Frame(self.f2, relief=FLAT)
      Label(iframe, text="Texture 1 (specular)", width=16, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=30, textvariable=self.texmaster1).pack(side=LEFT, padx=5)
      Button(iframe, text='...', command=lambda:self.getFileAndUpdateMaterial(self.getFile,self.texmaster1,1)).pack(side=LEFT, padx=5)
      Entry(iframe, width=30, textvariable=self.texture1).pack(side=LEFT, padx=5)
      Button(iframe, text='x', command=lambda:self.deleteEntry(self.texmaster1)).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # row frame
      iframe = Frame(self.f2, relief=FLAT)
      Label(iframe, text="Texture 2 (damage)", width=16, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=30, textvariable=self.texmaster2).pack(side=LEFT, padx=5)
      Button(iframe, text='...', command=lambda:self.getFileAndUpdateMaterial(self.getFile,self.texmaster2, 2)).pack(side=LEFT, padx=5)
      Entry(iframe, width=30, textvariable=self.texture2).pack(side=LEFT, padx=5)
      Button(iframe, text='x', command=lambda:self.deleteEntry(self.texmaster2)).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # row frame
      iframe = Frame(self.f2, relief=FLAT)
      Label(iframe, text="Texture 3 (glow)", width=16, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=30, textvariable=self.texmaster3).pack(side=LEFT, padx=5)
      Button(iframe, text='...', command=lambda:self.getFileAndUpdateMaterial(self.getFile,self.texmaster3, 3)).pack(side=LEFT, padx=5)
      Entry(iframe, width=30, textvariable=self.texture3).pack(side=LEFT, padx=5)
      Button(iframe, text='x', command=lambda:self.deleteEntry(self.texmaster3)).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # row frame
      iframe = Frame(self.f2, relief=FLAT)
      Label(iframe, text="Texture 4 (normal)", width=16, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=30, textvariable=self.texmaster4).pack(side=LEFT, padx=5)
      Button(iframe, text='...', command=lambda:self.getFileAndUpdateMaterial(self.getFile,self.texmaster4, 4)).pack(side=LEFT, padx=5)
      Entry(iframe, width=30, textvariable=self.texture4).pack(side=LEFT, padx=5)
      Button(iframe, text='x', command=lambda:self.deleteEntry(self.texmaster4)).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # row frame
      iframe = Frame(self.f2, relief=FLAT)
      Label(iframe, text="Texture 5 (PRT)", width=16, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=30, textvariable=self.texmaster5).pack(side=LEFT, padx=5)
      Button(iframe, text='...', command=lambda:self.getFileAndUpdateMaterial(self.getFile,self.texmaster5, 5)).pack(side=LEFT, padx=5)
      Entry(iframe, width=30, textvariable=self.texture5).pack(side=LEFT, padx=5)
      Button(iframe, text='x', command=lambda:self.deleteEntry(self.texmaster5)).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # PARAMETERS
      self.displayHeader(self.f2,"Shader Parameters") # header line
      # technique
      iframe = Frame(self.f2, relief=FLAT)
      Label(iframe, text="Technique", width=16, anchor=E).pack(side=LEFT, padx=5)
      self.technique.set(self.defaulttechnique)
      apply(OptionMenu, (iframe, self.technique) + tuple(self.TECHNIQUES)).pack(side=LEFT, padx=5)
      Entry(iframe, width=30, textvariable=self.technique).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # blend mode
      iframe = Frame(self.f2, relief=FLAT)
      Label(iframe, text="Blend mode", width=16, anchor=E).pack(side=LEFT, padx=5)
      self.blendmode.set(self.BLENDMODES[0])
      apply(OptionMenu, (iframe, self.blendmode) + tuple(self.BLENDMODES)).pack(side=LEFT, padx=5)
      #Entry(iframe, width=30, textvariable=self.blendmode).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # PROCESS
      self.displayHeader(self.f2,"Process Materials and Unit") # header line
      # row frame
      iframe = Frame(self.f2, relief=FLAT)
      Button(iframe, text='Save And Convert', bg="#BFB8FE", fg="#483855", command=self.saveAndConvert).pack(side=LEFT, padx=5)
      Label(iframe, text="=   (").pack(side=LEFT)
      Button(iframe, text='Save Mtl', command=self.saveMtl).pack(side=LEFT, padx=5)
      Label(iframe, text=" + ").pack(side=LEFT)
      Button(iframe, text='Convert to Bfxm', command=self.convertObjBfxm).pack(side=LEFT, padx=5)
      Label(iframe, text=")").pack(side=LEFT)
      Label(iframe, text=" (for all models in workspace)").pack(side=LEFT)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # compress textures
      iframe = Frame(self.f2, relief=FLAT)
      Button(iframe, text='Compress Textures', bg="#BFB8FE", fg="#483855", command=self.compressTextures).pack(side=LEFT, padx=5)
      Label(iframe, text=" (for active model only)").pack(side=LEFT)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # copy model and textures
      iframe = Frame(self.f2, relief=FLAT)
      Button(iframe, text='Copy Data', bg="#BFB8FE", fg="#483855", command=self.copyData).pack(side=LEFT, padx=5)
      Label(iframe, text=" (for all models in workspace)").pack(side=LEFT)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)

      #--------------------------------------------------------------------------------------------
      # HUD-IMAGE
      #--------------------------------------------------------------------------------------------
      self.f6 = f6 = Frame(window(), width=100, height=400) # tab frame
      # HELP
      self.help = "INSTRUCTIONS: To convert a hud image select the master image and press Convert.\n"
      self.help += "A sprite file will be created for your an copied to the unit data together with the image file."
      self.displayTextBox(self.f6, 2, self.help, DISABLED, scroll=False)
      # OPTIONS
      self.displayHeader(f6,"HUD Image") # header line
      # row
      iframe = Frame(f6, relief=FLAT)
      Label(iframe, text="HUD image", width=16).pack(side=LEFT, padx=5)
      Entry(iframe, width=30, textvariable=self.hudimage).pack(side=LEFT, padx=5)
      Button(iframe, text='...', command=lambda:self.getFileAndHudImage(self.getFile,self.hudimage)).pack(side=LEFT, padx=5)
      Button(iframe, text='x', command=lambda:self.deleteEntry(self.hudimage)).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # compress
      iframe = Frame(self.f6, relief=FLAT)
      Button(iframe, text='Compress Image', bg="#BFB8FE", fg="#483855", command=self.compressHudImage).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # copy model and textures
      iframe = Frame(self.f6, relief=FLAT)
      Button(iframe, text='Copy Data', bg="#BFB8FE", fg="#483855", command=self.copyData).pack(side=LEFT, padx=5)
      Label(iframe, text=" (all models, textures, and image in workspace)").pack(side=LEFT)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)

      #--------------------------------------------------------------------------------------------
      # UNIT EDITOR
      #--------------------------------------------------------------------------------------------
      self.f5 = f5 = Frame(window(), width=100, height=400) # tab frame
      # HELP
      self.help = "INSTRUCTIONS: This is a unit parameter editor. Edit the parameters and Save them to units.csv\n"
      self.help += "To revert your edits before saving, use Load. The information will be loaded from units.csv. If the the information doesn't yet exist in units.csv a (change me) message will be shown in the unit description.\n"
      self.help += "You may also read other units by typing the name directly and clicking Load. [scroll down for more]\n"
      self.help += "Reset will reload unit information for the current model in workspace.\n"
      self.help += "To view a unit, type the name and change to View tab for viewing the unit in vegastrike.\n"
      self.help += "You may browse through units by using the < and > keys."
      self.displayTextBox(self.f5, 4, self.help, DISABLED)
      # INFORMATION
      self.displayHeader(f5,"Unit Information") # header line
      # row
      iframe = Frame(f5, relief=FLAT)
      Label(iframe, text="Unit name", width=16).pack(side=LEFT, padx=5)
      Button(iframe, text='<', command=self.getPreviousUnit).pack(side=LEFT, padx=5)
      Entry(iframe, width=30, textvariable=self.unitname).pack(side=LEFT, padx=5)
      Button(iframe, text='>', command=self.getNextUnit).pack(side=LEFT, padx=5)
      Button(iframe, text='Save', bg="#BFB8FE", fg="#483855", command=self.writeUnitCsv).pack(side=LEFT, padx=5)
      Button(iframe, text='Load', bg="#BFB8FE", fg="#483855", command=self.readUnitCsv).pack(side=LEFT, padx=5)
      Button(iframe, text='Reset', bg="#BFB8FE", fg="#483855", command=self.resetUnit).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # row
      iframe = Frame(f5, relief=FLAT)
      Label(iframe, text="Unit mesh", width=20).pack(side=LEFT, padx=5)
      Entry(iframe, width=30, textvariable=self.unitmesh).pack(side=LEFT, padx=5)
      Label(iframe, text="Shield mesh", width=20).pack(side=LEFT, padx=5)
      Entry(iframe, width=30, textvariable=self.unitshieldmesh).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # row
      iframe = Frame(f5, relief=FLAT)
      Label(iframe, text="HUD image", width=20).pack(side=LEFT, padx=5)
      Entry(iframe, width=30, textvariable=self.unithud).pack(side=LEFT, padx=5)
      Label(iframe, text="Cockpit file", width=20).pack(side=LEFT, padx=5)
      Entry(iframe, width=30, textvariable=self.unitcockpit).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # DESCRIPTION
      self.displayHeader(f5,"Unit Description") # header line
      # object type choice
      iframe = Frame(f5, relief=FLAT)
      Label(iframe, text="Unit description", width=24).pack(side=LEFT, padx=5)
      Label(iframe, text="Unit type", width=16).pack(side=LEFT, padx=5)
      OptionMenu(iframe, self.unittype, *self.UNITTYPES).pack(side=LEFT, padx=5)
      Label(iframe, text="Unit role", width=16).pack(side=LEFT, padx=5)
      OptionMenu(iframe, self.unitrole, *self.UNITROLES).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # row
      #iframe = Frame(f5, relief=FLAT)
      #Label(iframe, text="Unit description", width=16).pack(side=LEFT, padx=5)
      #iframe.pack(expand=1, fill=X, pady=0, padx=5)
      iframe = Frame(f5, relief=FLAT)
      self.unitdescr = self.displayTextBox(self.f5, 2, self.unitdescription.get(), NORMAL)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # DESCRIPTION
      self.displayHeader(f5,"Unit Dimensions") # header line
      # row
      iframe = Frame(f5, relief=FLAT)
      Label(iframe, text="Scale").pack(side=LEFT, padx=5)
      Entry(iframe, width=8, textvariable=self.unitscale).pack(side=LEFT, padx=5)
      Label(iframe, text="Dimensions (Length/z, Width/x, Height/y) [m]").pack(side=LEFT, padx=5)
      Entry(iframe, width=8, textvariable=self.unitlength).pack(side=LEFT, padx=5)
      Entry(iframe, width=8, textvariable=self.unitwidth).pack(side=LEFT, padx=5)
      Entry(iframe, width=8, textvariable=self.unitheight).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # ENGINE
      self.displayHeader(f5,"Engine Thrusters") # header line
      # row
      self.unitthrdia.set(0)
      self.thrustertype.set(self.THRUSTTYPES[0])
      iframe = Frame(f5, relief=FLAT)
      Label(iframe, text="Thruster Diameter", width=16).pack(side=LEFT, padx=5)
      Entry(iframe, width=6, textvariable=self.unitthrdia).pack(side=LEFT, padx=5)
      Label(iframe, text="Thruster type", width=16).pack(side=LEFT, padx=5)
      OptionMenu(iframe, self.thrustertype, *self.THRUSTTYPES).pack(side=LEFT, padx=5)
      Button(iframe, text='Update', command=self.updateThruster).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # row
      iframe = Frame(f5, relief=FLAT)
      Label(iframe, text="Thruster Glow", width=16).pack(side=LEFT, padx=5)
      Entry(iframe, textvariable=self.unitthruster).pack(fill=BOTH, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # SUBUNITS
      self.displayHeader(f5,"Turrets & Subunits") # header line
      # row
      iframe = Frame(f5, relief=FLAT)
      Label(iframe, text="Subunits/Turrets", width=16).pack(side=LEFT, padx=5)
      Entry(iframe, width=76, textvariable=self.unitsubunits).pack(fill=BOTH, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # row
      iframe = Frame(f5, relief=FLAT)
      Label(iframe, text="Subunit nr.", width=16).pack(side=LEFT, padx=5)
      Button(iframe, text='<', command=self.prevSubunit).pack(side=LEFT, padx=5)
      Entry(iframe, width=6, textvariable=self.currentturret).pack(side=LEFT, padx=5)
      Button(iframe, text='>', command=self.nextSubunit).pack(side=LEFT, padx=5)
      Label(iframe, text="Subunit type", width=10, anchor=E).pack(side=LEFT, padx=5) # anchor EAST for right text alignment
      Entry(iframe, width=14, textvariable=self.subunittypesource).pack(side=LEFT, padx=5)
      #self.typesrc = self.displayTextBox(self.f5, 1, self.subunittypesource.get(), DISABLED, scroll=False)
      OptionMenu(iframe, self.subunittype, *self.SUBUNITTYPES).pack(side=LEFT, padx=5)
      Button(iframe, text='Update', command=self.updateSubunits).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # DOCKING
      self.displayHeader(f5,"Docking Ports") # header line
      # row
      iframe = Frame(f5, relief=FLAT)
      Label(iframe, text="Docks", width=16).pack(side=LEFT, padx=5)
      Entry(iframe, width=76, textvariable=self.unitdocks).pack(fill=BOTH, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)

      #--------------------------------------------------------------------------------------------
      # UNIT EDITOR 2
      #--------------------------------------------------------------------------------------------
      self.f8 = f8 = Frame(window(), width=100, height=400) # tab frame
      # HELP
      self.help = "INSTRUCTIONS: For quick guide see Unit screen.\n"
      self.displayTextBox(self.f8, 1, self.help, DISABLED, scroll=False)
      # INFORMATION
      self.displayHeader(f8,"Unit Information") # header line
      # row
      iframe = Frame(f8, relief=FLAT)
      Label(iframe, text="Unit name", width=16).pack(side=LEFT, padx=5)
      Button(iframe, text='<', command=self.getPreviousUnit).pack(side=LEFT, padx=5)
      Entry(iframe, width=30, textvariable=self.unitname).pack(side=LEFT, padx=5)
      Button(iframe, text='>', command=self.getNextUnit).pack(side=LEFT, padx=5)
      Button(iframe, text='Save', bg="#BFB8FE", fg="#483855", command=self.writeUnitCsv).pack(side=LEFT, padx=5)
      Button(iframe, text='Load', bg="#BFB8FE", fg="#483855", command=self.readUnitCsv).pack(side=LEFT, padx=5)
      Button(iframe, text='Reset', bg="#BFB8FE", fg="#483855", command=self.resetUnit).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # UPGRADES & MOUNTS
      self.displayHeader(f8,"Upgrades & Mounts & Cargo") # header line
      # row
      iframe = Frame(f8, relief=FLAT)
      Label(iframe, text="Upgrades", width=16).pack(side=LEFT, padx=5)
      Entry(iframe, width=76, textvariable=self.unitupgrades).pack(fill=BOTH, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # row
      iframe = Frame(f8, relief=FLAT)
      Label(iframe, text="Upgrade class", width=16).pack(side=LEFT, padx=5)
      self.optupclasses = OptionMenu(iframe, self.upgradeclass, *self.UPGRADECLASSES)
      self.optupclasses.pack(side=LEFT, padx=5)
      Label(iframe, text="Upgrade type", width=16).pack(side=LEFT, padx=5)
      self.optupgrades = OptionMenu(iframe, self.upgradetype, *self.UPGRADES)
      self.optupgrades.pack(side=LEFT, padx=5)
      Button(iframe, text='Add Upgrade', command=self.addUpgrade).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # row
      iframe = Frame(f8, relief=FLAT)
      Label(iframe, text="Mounts", width=16).pack(side=LEFT, padx=5)
      Entry(iframe, width=76, textvariable=self.unitmounts).pack(fill=BOTH, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # row
      iframe = Frame(f8, relief=FLAT)
      Label(iframe, text="Cargo", width=16).pack(side=LEFT, padx=5)
      Entry(iframe, width=76, textvariable=self.unitcargo).pack(fill=BOTH, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # row
      iframe = Frame(f8, relief=FLAT)
      Label(iframe, text="Trading Cargo", width=16).pack(side=LEFT, padx=5)
      Entry(iframe, width=76, textvariable=self.unitcargoimport).pack(fill=BOTH, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # PROPERTIES
      self.displayHeader(f8,"Unit Properties") # header line
      # row
      iframe = Frame(f8, relief=FLAT)
      Label(iframe, text="Legend: t - metric ton | m - meter | s - second | deg - degrees | VSD - Vega Strike Damage (unit) | MJ - Megajoule", anchor=W).pack(fill=BOTH, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # row
      iframe = Frame(f8, relief=FLAT)
      Label(iframe, text="Mass [t]", width=25, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=10, textvariable=self.unitmass).pack(side=LEFT, padx=5)
      Label(iframe, text="Moment of Inertia [t*m^2]", width=25, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=10, textvariable=self.unitinertia).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # row
      iframe = Frame(f8, relief=FLAT)
      Label(iframe, text="Fuel capacity [t]", width=25, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=10, textvariable=self.unitfuel).pack(side=LEFT, padx=5)
      Label(iframe, text="Upgrade volume [m^3]", width=25, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=10, textvariable=self.unitupgradevolume).pack(side=LEFT, padx=5)
      Label(iframe, text="Hold volume [m^3]", width=25, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=10, textvariable=self.unitholdvolume).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # row
      iframe = Frame(f8, relief=FLAT)
      Label(iframe, text="Primary Capacitor [100MJ]", width=25, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=10, textvariable=self.unitcapacitorprimary).pack(side=LEFT, padx=5)
      Label(iframe, text="SPEC Capacitor [800MJ]", width=25, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=10, textvariable=self.unitcapacitorwarp).pack(side=LEFT, padx=5)
      Label(iframe, text="Reactor Recharge [100MJ/s]", width=25, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=10, textvariable=self.unitreactorrecharge).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # row
      iframe = Frame(f8, relief=FLAT)
      Label(iframe, text="Jump Drive [-]", width=25, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=10, textvariable=self.unitjumpdrive).pack(side=LEFT, padx=5)
      Label(iframe, text="Jump Cost [800MJ]", width=25, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=10, textvariable=self.unitjumpcost).pack(side=LEFT, padx=5)
      Label(iframe, text="SPEC Cost [800MJ/s]", width=25, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=10, textvariable=self.unitwarpcost).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # PROTECTIVE
      self.displayHeader(f8,"Hull, Armor, Shields") # header line
      # row
      iframe = Frame(f8, relief=FLAT)
      Label(iframe, text="Hull [VSD]", width=25, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=10, textvariable=self.unithull).pack(side=LEFT, padx=5)
      Label(iframe, text="Armor [VSD]", width=25, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=10, textvariable=self.unitarmor).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # row
      iframe = Frame(f8, relief=FLAT)
      Label(iframe, text="Shield recharge [VSD/s]", width=25, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=10, textvariable=self.unitshieldrecharge).pack(side=LEFT, padx=5)
      Label(iframe, text="Shield (top) [VSD]", width=25, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=10, textvariable=self.unitshield).pack(side=LEFT, padx=5)
      Label(iframe, text="Shield (bottom) [VSD]", width=25, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=10, textvariable=self.unitshieldquad).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # SPEED, GOVERNORS, MENEUVER
      self.displayHeader(f8,"Maneuverability") # header line
      # row
      iframe = Frame(f8, relief=FLAT)
      Label(iframe, text="Max. Speed [m/s]", width=25, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=10, textvariable=self.unitspeed).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # row
      iframe = Frame(f8, relief=FLAT)
      Label(iframe, text="Overdrive Speed [m/s]", width=25, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=10, textvariable=self.unitoverdrive).pack(side=LEFT, padx=5)
      Label(iframe, text="Overdrive Acceleration [t*m/s^2]", width=35, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=10, textvariable=self.unitoverdriveaccel).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # row
      iframe = Frame(f8, relief=FLAT)
      Label(iframe, text="Overdrive Type [-]", width=25, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=10, textvariable=self.unitoverdrivetype).pack(side=LEFT, padx=5)
      Label(iframe, text="Overdrive Cost [100MJ/s]", width=35, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=10, textvariable=self.unitoverdrivecost).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # row
      iframe = Frame(f8, relief=FLAT)
      Label(iframe, text="Acceleration Forward [t*m/s^2]", width=25, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=10, textvariable=self.unitaccelforward).pack(side=LEFT, padx=5)
      Label(iframe, text="Acceleration Retro [t*m/s^2]", width=35, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=10, textvariable=self.unitaccelretro).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # row
      iframe = Frame(f8, relief=FLAT)
      Label(iframe, text="Acceleration Left [t*m/s^2]", width=25, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=10, textvariable=self.unitaccelleft).pack(side=LEFT, padx=5)
      Label(iframe, text="Acceleration Right [t*m/s^2]", width=35, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=10, textvariable=self.unitaccelright).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # row
      iframe = Frame(f8, relief=FLAT)
      Label(iframe, text="Acceleration Top [t*m/s^2]", width=25, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=10, textvariable=self.unitacceltop).pack(side=LEFT, padx=5)
      Label(iframe, text="Acceleration Bottom [t*m/s^2]", width=35, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=10, textvariable=self.unitaccelbottom).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # row
      iframe = Frame(f8, relief=FLAT)
      Label(iframe, text="Speed Yaw [deg/s]", width=25, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=10, textvariable=self.unitgovernoryaw).pack(side=LEFT, padx=5)
      Label(iframe, text="Speed Pitch [deg/s]", width=25, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=10, textvariable=self.unitgovernorpitch).pack(side=LEFT, padx=5)
      Label(iframe, text="Speed Roll [deg/s]", width=25, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=10, textvariable=self.unitgovernorroll).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # row
      iframe = Frame(f8, relief=FLAT)
      Label(iframe, text="Acceleration Yaw [t*deg/s^2]", width=25, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=10, textvariable=self.unitmaneuveryaw).pack(side=LEFT, padx=5)
      Label(iframe, text="Acceleration Pitch [t*deg/s^2]", width=25, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=10, textvariable=self.unitmaneuverpitch).pack(side=LEFT, padx=5)
      Label(iframe, text="Acceleration Roll [t*deg/s^2]", width=25, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=10, textvariable=self.unitmaneuverroll).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)

      #--------------------------------------------------------------------------------------------
      # UNIT EDITOR 3
      #--------------------------------------------------------------------------------------------
      self.f9 = f9 = Frame(window(), width=100, height=400) # tab frame
      # HELP
      self.help = "INSTRUCTIONS: For quick guide see Unit screen.\n"
      self.displayTextBox(self.f9, 1, self.help, DISABLED, scroll=False)
      # INFORMATION
      self.displayHeader(f9,"Unit Information") # header line
      # row
      iframe = Frame(f9, relief=FLAT)
      Label(iframe, text="Unit name", width=16).pack(side=LEFT, padx=5)
      Button(iframe, text='<', command=self.getPreviousUnit).pack(side=LEFT, padx=5)
      Entry(iframe, width=30, textvariable=self.unitname).pack(side=LEFT, padx=5)
      Button(iframe, text='>', command=self.getNextUnit).pack(side=LEFT, padx=5)
      Button(iframe, text='Save', bg="#BFB8FE", fg="#483855", command=self.writeUnitCsv).pack(side=LEFT, padx=5)
      Button(iframe, text='Load', bg="#BFB8FE", fg="#483855", command=self.readUnitCsv).pack(side=LEFT, padx=5)
      Button(iframe, text='Reset', bg="#BFB8FE", fg="#483855", command=self.resetUnit).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # RADAR & TRACKING
      self.displayHeader(f9,"Radar") # header line
      # row
      iframe = Frame(f9, relief=FLAT)
      Label(iframe, text="Radar Range [m]", width=25, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=10, textvariable=self.unitradarrange).pack(side=LEFT, padx=5)
      Label(iframe, text="Color Radar", width=25, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=10, textvariable=self.unitradarcolor).pack(side=LEFT, padx=5)
      Label(iframe, text="ITTS [-]", width=25, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=10, textvariable=self.unititts).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # row
      iframe = Frame(f9, relief=FLAT)
      Label(iframe, text="Tracking Cone [deg]", width=25, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=10, textvariable=self.unitconetracking).pack(side=LEFT, padx=5)
      Label(iframe, text="Max Cone [deg]", width=25, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=10, textvariable=self.unitconemax).pack(side=LEFT, padx=5)
      Label(iframe, text="Lock Cone [deg]", width=25, anchor=E).pack(side=LEFT, padx=5)
      Entry(iframe, width=10, textvariable=self.unitconelock).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # SOUNDS
      self.displayHeader(f9,"Sounds") # header line
      # row
      iframe = Frame(f9, relief=FLAT)
      Label(iframe, text="Sounds", width=16).pack(side=LEFT, padx=5)
      Entry(iframe, width=76, textvariable=self.unitsounds).pack(fill=BOTH, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)

      #--------------------------------------------------------------------------------------------
      # VIEW UNIT
      #--------------------------------------------------------------------------------------------
      self.f7 = f7 = Frame(window()) # tab frame
      # HELP
      self.help = 'INSTRUCTIONS: You can test the unit in-game.\n'
      self.help +=  'To test faction textures, select the unit faction before viewing the unit.'
      self.displayTextBox(self.f7, 2, self.help, DISABLED, scroll=False)
      # INFORMATION
      self.displayHeader(f7,"Unit Information") # header line
      # options dropdown for faction textures
      iframe = Frame(self.f7, relief=FLAT)
      Label(iframe, text="Faction", width=16).pack(side=LEFT, padx=5)
      self.missionfaction.set(self.FACTIONS[1])
      apply(OptionMenu, (iframe, self.missionfaction) + tuple(self.FACTIONS)).pack(side=LEFT, padx=5)
      Button(iframe, text='View', bg="#BFB8FE", fg="#483855", command=self.testUnitInVegastrike).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)

      #--------------------------------------------------------------------------------------------
      # CONFIG
      #--------------------------------------------------------------------------------------------
      self.f3 = f3 = Frame(window(), width=100, height=400) # tab frame
      # HELP
      self.help = "INSTRUCTIONS: Configure the Vega Strike data directory (in which resides vegastrike.config). It will be used to copy converted files.\n"
      self.help += "Configure the address (directory path + tool name, e.g. C:\mesher.exe or /opt/vs/mesher). You may browse for mesher to set the address. [scroll down for more]\n"
      self.help += "Configure nVidia's nvcompress command path as used from command line (nvcompress is sufficient if it resides in a directory of your system PATH variable).\n"
      self.help += "Help on obtaining nVidia's Texture Tools can be found here: http://vegastrike.sourceforge.net/wiki/Links:Graphic_Applications#nVidia_Texture_Tools\n"
      self.help += "You can set a default technique and default directory when saving and copying model and texture files. Make sure to press the (Save Settings) button after any change."
      self.displayTextBox(self.f3, 4, self.help, DISABLED)
      # OPTIONS
      self.displayHeader(f3,"Paths") # header line
      # row
      iframe = Frame(f3, relief=FLAT)
      Label(iframe, text="Vega Strike directory", width=18).pack(side=LEFT, padx=5)
      Entry(iframe, width=70, textvariable=self.vegastrike).pack(side=LEFT, padx=5)
      Button(iframe, text='Browse', command=lambda:self.getFolder(self.vegastrike)).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # row
      self.displayHeader(f3,"External Tools") # header line
      iframe = Frame(f3, relief=FLAT)
      Label(iframe, text="Path to mesher", width=18).pack(side=LEFT, padx=5)
      Entry(iframe, width=70, textvariable=self.mesherpath).pack(side=LEFT, padx=5)
      Button(iframe, text='Browse', command=lambda:self.getPath(self.mesherpath)).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # row
      iframe = Frame(f3, relief=FLAT)
      Label(iframe, text="Path to nvcompress", width=18).pack(side=LEFT, padx=5)
      Entry(iframe, width=70, textvariable=self.nvcompresspath).pack(side=LEFT, padx=5)
      Button(iframe, text='Browse', command=lambda:self.getPath(self.nvcompresspath)).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # DEFAULTS
      self.displayHeader(f3,"Defaults") # header line
      # techniques
      iframe = Frame(self.f3, relief=FLAT)
      Label(iframe, text="Current Technique", width=16).pack(side=LEFT, padx=5)
      apply(OptionMenu, (iframe, self.technique) + tuple(self.TECHNIQUES)).pack(side=LEFT, padx=5)
      Button(iframe, text='Save Settings', bg="#BFB8FE", fg="#483855", command=lambda:self.setDefault(self.technique)).pack(side=RIGHT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # units directory structure & bypass compression
      iframe = Frame(self.f3, relief=FLAT)
      Checkbutton(iframe, variable=self.useclassdir).pack(side=LEFT, padx=5)
      Label(iframe, text='Use unit class directory', width=30, anchor=W).pack(side=LEFT, padx=5)
      Checkbutton(iframe, variable=self.inputtex).pack(side=LEFT, padx=5)
      Label(iframe, text='Bypass compression (use input textures)', width=35, anchor=W).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # backup obj/mtl & create xmesh files
      iframe = Frame(self.f3, relief=FLAT)
      Checkbutton(iframe, variable=self.backupobj).pack(side=LEFT, padx=5)
      Label(iframe, text='Backup obj/mtl files', width=30, anchor=W).pack(side=LEFT, padx=5)
      Checkbutton(iframe, variable=self.createxmesh).pack(side=LEFT, padx=5)
      Label(iframe, text='Create xmesh files', width=30, anchor=W).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # INFO
      self.displayHeader(f3,"Info") # header line
      # row
      iframe = Frame(f3, relief=FLAT)
      Label(iframe, text="Working directory", width=18).pack(side=LEFT, padx=5)
      Entry(iframe, width=70, textvariable=self.workdir).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # ADMIN
      self.displayHeader(f3,"Admin") # header line
      # row
      iframe = Frame(f3, relief=FLAT)
      Button(iframe, text='Standard Sort units.csv', bg="#BFB8FE", fg="#483855", command=self.sortUnitCsv).pack(side=LEFT, padx=5)
      Label(iframe, text="by unit type, unit role, and unit key", width=30, anchor=W).pack(side=LEFT, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)


      #--------------------------------------------------------------------------------------------
      # ABOUT
      #--------------------------------------------------------------------------------------------
      self.f4 = f4 = Frame(window(), width=100, height=400) # tab frame
      self.displayHeader(f4,"Vega Strike Unit Converter (obj->bfxm)") # header line
      # HELP
      self.help = "Get the latest version:\n"
      self.help += "'svn co https://vegastrike.svn.sourceforge.net/svnroot/vegastrike/trunk/modtools/UnitConverter'"
      self.displayTextBox(self.f4, 2, self.help, DISABLED)
      # row frame
      iframe = Frame(f4, relief=FLAT)
      Label(iframe, text="Version: 2011-04-07 | v0.40 | Vega Strike team").pack(fill=BOTH, padx=5)
      Label(iframe, text="http://vegastrike.sourceforge.net/").pack(fill=BOTH, padx=5)
      Label(iframe, text="pyramid users sourceforge net | pyramid sapo pt").pack(fill=BOTH, padx=5)
      iframe.pack(expand=1, fill=X, pady=0, padx=5)
      # LICENSE
      self.help = "Copyright (C) 2008 Vega Strike team\n"
      self.help += "Contact: hellcatv@users.sourceforge.net\n"
      self.help += "Internet: http://vegastrike.sourceforge.net/\n"
      self.help += "Forums: http://vegastrike.sourceforge.net/forums/\n\n"
      self.help += "This program is free software; you can redistribute it and/or\n"
      self.help += "modify it under the terms of the GNU General Public License\n"
      self.help += "as published by the Free Software Foundation; either version 3\n"
      self.help += "of the License, or (at your option) any later version."
      self.displayTextBox(self.f4, 8, self.help, DISABLED)

      #--------------------------------------------------------------------------------------------
      # MENU
      #--------------------------------------------------------------------------------------------
      # keeps the reference to the radiobutton (optional)
      window.add_screen(f1, "Model")
      window.add_screen(f2, "Textures")
      window.add_screen(f6, "HUDImage")
      window.add_screen(f5, "Unit")
      window.add_screen(f8, "Unit 2")
      window.add_screen(f9, "Unit 3")
      window.add_screen(f7, "View")
      window.add_screen(f3, "Config")
      window.add_screen(f4, "About")

      #--------------------------------------------------------------------------------------------
      # EXECUTE
      #--------------------------------------------------------------------------------------------
      self.iniRead()
      self.readUnitCsv()
      self.readUnitUpgrades()
      self.readUnitWeapons()
      self.updateScreen()
      if __name__ == "__main__":
        self.processEvents()
        master.mainloop()

def exitApp():
# confirmation if user wants to quit, disabled
  #if tkMessageBox.askokcancel("Quit", "Do you really wish to quit?"):
    #app.iniWrite() #can't call class functions as class is already destroyed
    root.destroy()

# create application window
root = Tk()
root.protocol("WM_DELETE_WINDOW", exitApp)
root.option_add("*Dialog.msg.wrapLength", "600px")
root.option_add("*Dialog.msg.Font", "helvetica 10 normal")
root.option_add("*Text.Font", "helvetica 9 normal")
if platform.system() in ('Windows', 'Microsoft'):
  root.iconbitmap('unitconverter.ico')
app = UnitConverter(root)

def OnExit(*args):
# write configuration on exit
  #print "OnExit", args
  app.iniWrite()
  #print "Adios, artista"
  #print "So long (and thanks for all the converting)"
  #print "Looks sharp, Chief" #v0.35
  #print "May the UnitConverter be with you" #v0.36 / v0.37
  #print "Goodby to conversion magic" #v0.38
  print "Go, model, go!" #v0.39

# register exit handler
atexit.register(OnExit)

# END 
