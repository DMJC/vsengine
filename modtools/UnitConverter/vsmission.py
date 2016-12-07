#---------------------------------------------------------------------------------
# Vega Strike mission editor
# Copyright (C) 2008 Vega Strike team
# Contact: hellcatv@users.sourceforge.net
# Internet: http://vegastrike.sourceforge.net/
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# Description: Provides various methods to read, write, and update .mission files
#
# Author: pyramid
# Version: 2008-10-09 | v0.32
# Contact: pyramid@sapo.pt
#---------------------------------------------------------------------------------
# Features:
# reads and writes .mission files
# updates node attributes
#---------------------------------------------------------------------------------

from xml.dom.minidom import *

class VsMission:

  def __init__(self, vsMissionFile):
    # load mission file
    self.fileAddress = vsMissionFile
    print "Reading ", vsMissionFile
    file = open(vsMissionFile)
    self.mission = parse(file)   # parse an open file
    file.close()
    #print self.mission.toxml()

  def getText(self, nodelist):
  # test function
      for node in nodelist:
        print "geText Node = ", node.localName
        print "geText Node = ", node.toxml()
      return rc

  def getFlightgroup(self):
  # test function
    flightgroup = self.mission.getElementsByTagName('flightgroup')
    #print self.getText(flightgroup)
    for node in flightgroup:
      #print node.toxml()
      #print node.attributes.keys()
      faction = node.attributes["faction"]
      faction.value = 'privateer'
      #print faction.name, faction.value
      #print faction.name, faction.value

  def updateNodeAttribute(self, nodeName, attributeName, newValue):
  # updates attribute of all nodes with a given name
    nodeList = self.mission.getElementsByTagName(nodeName)
    for node in nodeList:
      nodeList = node.attributes[attributeName]
      nodeList.value = newValue
      #print nodeList.name, nodeList.value

  def saveMissionFile(self):
  # writes the file
    file = open(self.fileAddress, 'w')
    file.write(self.mission.toxml())
    file.close()