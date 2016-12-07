#---------------------------------------------------------------------------------
# Vega Strike Wavefront obj and mtl parser
# Copyright (C) 2008 Vega Strike team
# Contact: hellcatv@users.sourceforge.net
# Internet: http://vegastrike.sourceforge.net/
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# Description: Takes obj and mtl files, parses material information
#
# Author: pyramid
# Version: 2008-10-28 | v0.38
# Contact: pyramid@sapo.pt
#---------------------------------------------------------------------------------
#inspired by://www.pygame.org/wiki/OBJFileLoader?parent=CookBook
#import pygame
#from OpenGL.GL import *
#---------------------------------------------------------------------------------
# Features:
# saves MTL files
# reads material info from OBJ files
# reads material info from MTL files
# reads texture info from MTL files
# reads objects from OBJ files
# gets center, forward, up vectors and radius of helper objects
#---------------------------------------------------------------------------------

from types import *
from vector import *

def saveMtl(fileName, materialList, textureList, technique, blendmode, modelnr):
# make a new material file
  #print materialList
  #print "saveMtl - tex", textureList
  #print "saveMtl - tec", technique
  #print "saveMtl - ble", blendmode
  f = open(fileName, "w")
  f.write('# Exported from Vega Strike Unit Converter\n')
  for i in range(len(materialList)):
    f.write("newmtl "+materialList[i]+"\n")
    f.write("Ns 100"+"\n")
    f.write("Ni 1.0"+"\n")
    f.write("d 1.0"+"\n")
    f.write("illum 2"+"\n")
    f.write("Kd 1.00000 1.00000 1.00000"+"\n")
    f.write("Ka 1.00000 1.00000 1.00000"+"\n")
    f.write("Ks 1.00000 1.00000 1.00000"+"\n")
    f.write("Ke 0.00000 0.00000 0.00000"+"\n")
    if i<=len(textureList)-1 and len(blendmode)>=i:
      if len(blendmode[i])>0:
        f.write("BLEND "+blendmode[i].split(",")[0][1:].strip("'")+"\n")
      if not(technique[i]==''):
        f.write("technique "+technique[i]+"\n")
      for j in range(len(textureList[i])):
        f.write(textureList[i][j][0]+" "+textureList[i][j][1]+"\n")
    else:
      f.write("BLEND "+blendmode[0].split(",")[0][1:].strip("'")+"\n")
      if not(technique[0]==""):
        f.write("technique "+technique[0]+"\n")
      for j in range(len(textureList[0])):
        f.write(textureList[0][j][0]+" "+textureList[0][j][1]+"\n")
    f.write("\n")
  print "file "+fileName+" saved"

def saveObj(fileName, linesList):
# save the obj file
  f = open(fileName, "w")
  if linesList[0].find('Vega Strike')==-1:
    f.write('# Exported from Vega Strike Unit Converter\n')
  for i in range(len(linesList)):
    f.write(linesList[i])
  print "file "+fileName+" saved"

#def getTexture(iModel,iTexture):
# creates a texture name by convention "text_m_s_t" where
# m - mesh
# s - submesh
# t - texture set
#  return "tex_"+str(iModel)+"0"+str(iTexture)+".texture"

def GetMtlMaterial(fileName, materialName):
    contents = {}
    i = 0
    mtl = None
    for line in open(fileName, "r"):
        if line.startswith('#'): continue
        values = line.split()
        if not values:
          mtl = None
          continue
        if (values[0] == 'newmtl')&(values[1]==materialName):
          mtl = values[1]
        if mtl is None: continue
        if values[0] in ('map_0','map_1','map_2','map_3','map_4','map_Kd','map_Ks','map_Ke','map_kd','map_ks','map_ke','map_damage','map_normal'):
            contents[i] = [values[0],values[1]]
            i+=1
    return contents

def GetObjMaterial(filename):
    contents = {}
    i = 0
    try:
      for line in open(filename, "r"):
          if line.startswith('#'): continue
          values = line.split()
          if not values: continue
          elif values[0] in ('usemtl', 'usemat'):
              contents[i] = [values[0],values[1]]
              i+=1
          elif values[0] == 'mtllib':
              contents[i] = [values[0],values[1]]
              i+=1
      return contents
    except:
      return contents

class MtlParse:

  def __init__(self, filename, swapyz=False):
  # Loads a Wavefront MTL file
    self.lines = []
    contents = []
    i = 0

    # parse the MTL file
    material = None
    try:
      file = open(filename, "r")
    except:
      return
    for line in file:
      self.lines.append(line)
    #print "MtlParse lines=", len(self.lines)

  def getMtlTexture(self, textureNames):
  #gets the named texture
    texture = ''
    for line in self.lines:
      if line.startswith('#'): continue
      values = line.split()
      if not values:
        mtl = None
        continue
      if values[0]in textureNames:
        texture = values[1]
    return texture

class ObjParse:

  def __init__(self, filename, swapyz=False):
  # Loads a Wavefront OBJ file
    self.vertices = []
    self.normals = []
    self.texcoords = []
    self.faces = []
    self.objnames = []
    self.objvertices = []
    self.lines = []
    contents = {}
    i = 0

    # parse the OBJ file
    material = None
    try:
      file = open(filename, "r")
    except:
      return
    for line in file:
      self.lines.append(line)
      if line.startswith('#'): continue
      values = line.split()
      if not values: continue
      # get vertices
      if values[0] == 'o':
        self.objnames.append(values[1])
        self.objvertices += [[]]
      # get vertices
      elif values[0] == 'v':
          v = map(float, values[1:4])
          if swapyz:
              v = v[0], v[2], v[1]
          self.vertices.append(v)
          if len(self.objnames)>0:
            self.objvertices[len(self.objnames)-1].append(v)
      # get normals
      elif values[0] == 'vn':
          v = map(float, values[1:4])
          if swapyz:
              v = v[0], v[2], v[1]
          self.normals.append(v)
      # get texture corrdinates
      elif values[0] == 'vt':
          self.texcoords.append(map(float, values[1:3]))
      # get materials
      elif values[0] in ('usemtl', 'usemat'):
          material = values[1]
          contents[i] = values[0]
          contents[i+1] = values[1]
          i+=2
      elif values[0] == 'mtllib':
          contents[i] = values[0]
          contents[i+1] = values[1]
          i+=2
      # get faces
      elif values[0] == 'f':
          face = []
          texcoords = []
          norms = []
          for v in values[1:]:
              w = v.split('/')
              face.append(int(w[0]))
              if len(w) >= 2 and len(w[1]) > 0:
                  texcoords.append(int(w[1]))
              else:
                  texcoords.append(0)
              if len(w) >= 3 and len(w[2]) > 0:
                  norms.append(int(w[2]))
              else:
                  norms.append(0)
          self.faces.append((face, norms, texcoords, material))
    #print "---OBJ FIle---"
    #print "Vertices = ", len(self.vertices)
    #print "Normals = ", len(self.normals)
    #print "Faces = ", len(self.faces)
    #print "Texturecoords = ", len(self.texcoords)
    #print self.vertices
    #print self.objvertices

  def getFile(self):
  # returns all the file lines
    return self.lines

  def getDimensions(self):
  # calculates length, width, height from vertices
    #print "Vertices = ", self.vertices
    len_min = 0
    len_max = 0
    wid_min = 0
    wid_max = 0
    hei_min = 0
    hei_max = 0
    for vertex in self.vertices:
      if vertex[2]<len_min:
        len_min = vertex[2]
      if vertex[2]>len_max:
        len_max = vertex[2]
      if vertex[0]<wid_min:
        wid_min = vertex[0]
      if vertex[0]>wid_max:
        wid_max = vertex[0]
      if vertex[1]<hei_min:
        hei_min = vertex[1]
      if vertex[1]>hei_max:
        hei_max = vertex[1]
    #print "Length = ", len_max - len_min
    #print "Width = ", wid_max - wid_min
    #print "Height = ", hei_max - hei_min
    #print "Object Extensions (L/W/H Min/Max) = ", len_min, len_max, wid_min, wid_max, hei_min, hei_max
    #print "Object Dimensions (L/W/H) = ", len_max-len_min, wid_max-wid_min, hei_max-hei_min
    return len_max-len_min, wid_max-wid_min, hei_max-hei_min

  def getObjectNames(self):
  # gets the names of the different objects
    #print 'Helper Objects = ', self.objnames
    return self.objnames

  def getObjectVerticesBak(self):
  # gets the names of the different objects
    return self.objvertices

  def getObjectVertices(self, object=None):
  # gets the vertices of the different objects
  # simulated overload, object can be none (returns all object vertices), 
  # string (returns vertices for object name, or
  # integer (returns vertices for object index)
    if object==None:
      return self.objvertices
    if type(object)==StringType:
      return self.objvertices[self.objnames.index(object)]
    if type(object)==IntType:
      return self.objvertices[object]

  def getObjDistanceShortest(self, vertexlist):
  # finds the shortest distance between two vertices
  # and returns both vertices
    distance = vector(vertexlist[0])
    vertices = None
    for v1 in range(len(vertexlist)):
      for v2 in range(v1+1,len(vertexlist)):
        #print "From-To", v1, v2
        #print "From-To", vertexlist[v1], vertexlist[v2]
        length = vlength(vector(vertexlist[v2])-vector(vertexlist[v1]))
        if length<distance:
          distance = length
          vertices = [vertexlist[v1], vertexlist[v2]]
    return vertices

  def getVertexLongest(self, vertexlist, center):
  # finds the vertex with longest distance from center
    distance = 0
    vertex = None
    for v in range(len(vertexlist)):
      length = vlength(vector(vertexlist[v])-vector(center))
      if length>distance:
        distance = length
        vertex = vertexlist[v]
    return vertex

  def getVertexMedium(self, vertexlist, center):
  # finds the vertex with medium distance from center
    distance = 0
    vertex = None
    vshortest = self.getObjDistanceShortest(vertexlist)
    vlongest = self.getVertexLongest(vertexlist, center)
    for v in range(len(vertexlist)):
      if vertexlist[v]!=vshortest[0] and vertexlist[v]!=vshortest[1] and vertexlist[v]!=vlongest:
        vertex = vertexlist[v]
    return vertex

  def getVertexDistance(self, vertexlist, center, distance):
  # finds the vertex with longest distance from center
    vertex = None
    tol_min = distance-distance*0.01
    tol_max = distance+distance*0.01
    for v in range(len(vertexlist)):
      length = vlength(vector(vertexlist[v])-vector(center))
      if length>=tol_min and length<=tol_max:
        vertex = vertexlist[v]
    return vertex

  def getVertCenter(self, vertex1, vertex2):
  # calculates the center between two vertices
    return (vector(vertex1)+(vector(vertex2)-vector(vertex1))/2)

  def getHelperCenter(self, object):
  # gets the center of the predefined helper object
    vertices = self.getObjectVertices(object)
    corners = self.getObjDistanceShortest(vertices)
    return self.getVertCenter(corners[0],corners[1])

  def getHelperForward(self, object):
  # gets the center of the predefined helper object
    vertices = self.getObjectVertices(object)
    center = self.getHelperCenter(object)
    forward = vnormal(vector(self.getVertexLongest(vertices, center))-center)
    #print "Forward = ", forward
    return forward 

  def getHelperUp(self, object):
  # gets the center of the predefined helper object
    vertices = self.getObjectVertices(object)
    center = self.getHelperCenter(object)
    up = vnormal(vector(self.getVertexMedium(vertices, center))-center)
    #up = vnormal(vector(self.getVertexDistance(vertices, center, distance))-center)
    return up

  def getHelperRadius(self, object):
  # gets the forward radius of the predefined helper object
    vertices = self.getObjectVertices(object)
    center = self.getHelperCenter(object)
    radius = vlength(vector(self.getVertexLongest(vertices, center))-center)
    return radius 

  def paintObject():
  # untested, disabled
    #self.gl_list = glGenLists(1)
    #glNewList(self.gl_list, GL_COMPILE)
    #glEnable(GL_TEXTURE_2D)
    #glFrontFace(GL_CCW)
    #for face in self.faces:
      #vertices, normals, texture_coords, material = face
      #mtl = self.mtl[material]
      #if 'texture_Kd' in mtl:
        # use diffuse texmap
        #glBindTexture(GL_TEXTURE_2D, mtl['texture_Kd'])
      #else:
        # just use diffuse colour
        #glColor(*mtl['Kd'])
      #glBegin(GL_POLYGON)
      #for i in range(0, len(vertices)):
      #    if normals[i] > 0:
      #        glNormal3fv(self.normals[normals[i] - 1])
      #    if texture_coords[i] > 0:
      #        glTexCoord2fv(self.texcoords[texture_coords[i] - 1])
      #    glVertex3fv(self.vertices[vertices[i] - 1])
      #glEnd()
    #glDisable(GL_TEXTURE_2D)
    #glEndList()
    return
