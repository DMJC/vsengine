#---------------------------------------------------------------------------------
# Vega Strike unit.csv parser
# Copyright (C) 2008 Vega Strike team
# Contact: hellcatv@users.sourceforge.net
# Internet: http://vegastrike.sourceforge.net/
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# Description: Provides various methods to read, write, and update units information
#
# Author: pyramid
# Version: 2008-10-31 | v0.38
# Contact: pyramid@sapo.pt
#---------------------------------------------------------------------------------
# Features:
# reads and writes units.csv
# finds unit types
# gets unit record
# updates unit
# inserts new unit
# provides default unit (vessel)
# provides header line (getHeader)
#---------------------------------------------------------------------------------
# To Do:
# provide default unit for all unit types
#---------------------------------------------------------------------------------

import csv
import operator
#from operator import itemgetter

class VsUnitCsv:

  def __init__(self, vsDataDir):
    self.unitCsvAddress = vsDataDir+"/units/units.csv"
    #self.recordcnt = 0
    self.records = []

    # loads units csv
    print "Reading units.csv = ", self.unitCsvAddress
    file = open(self.unitCsvAddress, "rb")
    self.unitscsv = csv.reader(file)
    for row in self.unitscsv:
      #self.recordcnt += 1
      #if len(row)>0: # skip empty rows
      self.records += [row]
    file.close()
    #print 'Got', len(self.records), 'lines from units.csv'

  def countRecordType(self, typeName):
  # counts records of a specific type 
  # e.g. countRecordType("Vessel")
    typecnt = 0
    for i in range(len(self.records)):
      if len(self.records[i])>0: # skip empty rows
        if (self.records[i][4]==typeName):
          typecnt += 1
    return typecnt

  def getObjectType(self, typeName):
  # returns a list with records of a specific object_type 
  # e.g. countRecordType("Vessel")
    types = []
    for i in range(len(self.records)):
      if len(self.records[i])>0: # skip empty rows
        if (self.records[i][4]==typeName):
          types += [self.records[i][0].split('__')[0]]
    return types

  def getUnit(self, unitKey):
  # gets a unit with a given key 
  # e.g. getUnit("Llama")
    unit = []
    for i in range(len(self.records)):
      if len(self.records[i])>0: # skip empty rows
        if (self.records[i][0]==unitKey):
          unit = self.records[i]
    return unit

  def getUnitIndex(self, unitKey):
  # gets index of a unit with a given key 
  # e.g. getUnitIndex("Llama")
    index = 0
    for i in range(len(self.records)):
      if len(self.records[i])>0: # skip empty rows
        if (self.records[i][0]==unitKey):
          index = i
    return index

  def updateUnit(self, inputRecord):
  # updates a record where index 0 is equal to record key 
  # e.g. updateUnit(myShip) with myship = [...]
    success = False
    for i in range(len(self.records)):
      if len(self.records[i])>0: # skip empty rows
        if (self.records[i][0]==inputRecord[0]):
          print "Updated unit in line", i+1
          self.records[i] = inputRecord
          success = True
    return success

  def writeUnitCsv(self):
  # writes complete records again to units.csv file
    file = open(self.unitCsvAddress, "wb")
    self.writer = csv.writer(file)
    self.writer.writerows(self.records)
    file.close()

  def getDefaultUnit(self, unittype='Vessel'):
  # returns a default unit record
    unit = ['']*115
    if unittype=='Installation':
      unit = ['','','','','Installation','BASE','Default installtion (WRITE ME)','','1','','','','','{;;}','','','','','','','8241769.5','8241769.5','686814.13','712000', '15000', '15000', '15000', '15000', '15000', '15000', '15000', '15000', '3000', '3000', '3000', '3000', '', '', '', '', '50', '0', '', '40000', '4000', 'FALSE','', '', '', '', '0', '', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0','0', '0', '0', '0', '0', 'TRUE', '300000000','5','180','180','1.00E+11','','','','','','','0','0','0','1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1', '1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '0', '', '', '', '','', ';;;;;;', '', '{Seaxbane;4;;special-missile;2343;-200;0;;;0;0;1;0;1;0;1;1}','','', '{Consumer_and_Commercial_Goods/Domestic;.7;.2;;}{Consumer_and_Commercial_Goods/Electronics;.9;.1;;}{Industrially_Manufactured_Goods/Agricultural;.7;.1;;}{Industrially_Manufactured_Goods/Construction;1.2;.1;1;1}{Industrially_Manufactured_Goods/Electronics;1.2;.1;1;1}{Industrially_Manufactured_Goods/Manufacturing;1.2;.2;;}{Industrially_Manufactured_Goods/Mining;1.3;.1;1;1}{Industrially_Manufactured_Goods/Power_Utilities;.8;.1;;}{Industrially_Manufactured_Goods/Recycled_Products;1.1;.1;;}{Natural_Products/Life-forms;1;.1;2;2}{Natural_Products/Liquor;1.1;.1;1;1}{Natural_Products/Renewable_Resources;.7;.1;;}{Raw_Materials/Gases;1.2;.1;5;5}{Raw_Materials/Hydrocarbons;.7;.2;;}{Raw_Materials/Industrial_Gems;.7;.2;22;7}{Raw_Materials/Metals;.65;.2;42;15}{Raw_Materials/Stone;.7;.1;7;3}{Refined_Materials/Chemicals;1.1;.2;3;2}{Refined_Materials/Precious_Metals;.65;.2;22;5}{Refined_Materials/Purified_and_Enhanced_Materials;1.05;.1;10;}{Refined_Materials/Radioactive_Metals;.65;.2;25;5}{Specialty_Goods/Entertainment;1.2;.1;1;1}{Specialty_Goods/Medical;1.1;.1;5;3}{starships/Andolian/Medium;1;;12;5}{starships/Andolian/Medium;1;;6;3}{starships/Confed/Light;1;;12;5}{starships/Confed/Medium;1;;6;3}{starships/Hunter/Light;1;;12;5}{starships/Hunter/Medium;1;;6;3}{starships/Merchant/Light;1;;12;5}{starships/Merchant/Medium;1;;6;3}{starships/Regional_Guard/Light;1;;12;5}{starships/Regional_Guard/Medium;1;;6;3}{upgrades/Ammunition/Common;1;.1;100;280}{upgrades/Ammunition/Uncommon;3;.4;-10;280}{upgrades/Ammunition/Confed;2;.2;20;28}{upgrades/Armor;1;.1;10;5}{upgrades/Capacitors/Standard;1;.1;10;5}{upgrades/Cargo;1;.1;2;1}{upgrades/ECM_Systems;1;.1;;3}{upgrades/Jump_Drives;1;.1;6;3}{upgrades/Overdrive;1;.1;6;4}{upgrades/Passenger_Quarters;1;.1;10;2}{upgrades/Reactors/Standard;1;.1;10;5}{upgrades/Repair_Systems;1;.1;-1;4}{upgrades/Sensors/Advanced;1;.1;6;5}{upgrades/Sensors/Basic;1;.1;6;3}{upgrades/Sensors/Intermediate;1;.1;6;4}{upgrades/Shady_Mechanic;1;.1;-2;5}{upgrades/Shield_Systems/Standard_Dual_Shields;1;.1;20;5}{upgrades/Shield_Systems/Standard_Quad_Shields;1;.1;20;5}{upgrades/SPEC_Capacitors;1;.1;6;2}{upgrades/Weapons/Beam_Arrays_Light;1;.1;;5}{upgrades/Weapons/Beam_Arrays_Medium;1;.1;-3;5}{upgrades/Weapons/Mount_Enhancements;1;.1;-50;51}{upgrades/Weapons/Mounted_Guns_Light;1;.1;;4}{upgrades/Weapons/Mounted_Guns_Medium;1;.1;;3}', '', '', '0', '1000000', '0', '', '', '', '', '0.75','pPiI']
    if unittype=='Vessel':
      unit = ['', '', '', '', 'Vessel', '', 'Default unit (CHANGE ME)', '', '1', 'no-cockpit', '0', '0', '3.5', '{;;}', '', '','', '', '', '', '336', '336', '25', '500', '1','1', '1', '1', '1', '1', '1', '1', '0', '0', '0', '0', '', '', '', '', '0', '0', '325', '', '', 'TRUE', '1', '', '300', '120', '1', '4', '50000', '50000', '50000', '45', '50', '55', '17000', '17000', '15000', '4000', '4000', '4000', '4000', '125', '125', 'FALSE', 'FALSE', '300000000', '4', '180', '25', '2000', '', '','', '', '0', '0', '0', '0', '0', '1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1', '1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '0', '', '', '{armor03;;}{quadshield05;;}{add_spec_capacitor03;;}{capacitor04;;}{reactor05;;}{jump_drive;;}{skyscope3;;}{ecm_package01;;}', 'mult_shady_moreupgrade:1;mult_shady_morethrust:1;mult_shady_moreshields:1;mult_shady_moregunrecharge:1;mult_shady_moreshieldrecharge:1;mult_shady_moreturning:1;upgrades/Overdrive:1;upgrades/Capacitors:1;upgrades/Reactors:1;upgrades/Armor:1;upgrades/Sensors:1;upgrades/Shield_Systems:1;upgrades/Passenger_Quarters:1;upgrades/Repair_Systems:1;upgrades/ECM_Systems:1', '', ';;;;;;', '{supernova.bmp.bfxm;0.00000e+0;0.350000;-2.09200;2;;;;;}{supernova.bmp.bfxm;1.31600;-6.00000e-3;-1.82200;2;;;;;}{supernova.bmp.bfxm;-1.32800;-6.00000e-3;-1.82200;2;;;;;}', '{Disruptor;;;Light;1.01200;-6.80000e-2;3.40800;;;;;;;;;1;1}{Disruptor;;;Light;-0.964000;-6.80000e-2;3.40800;;;;;;;;;1;1}{ParticleBeam;;;Light;0.380000;0.176000;1.07600;;;;;;;;;1;1}{ParticleBeam;;;Light;-0.336000;0.176000;1.07600;;;;;;;;;1;1}{;0;48;light-missile medium-missile special-missile;0;0;0;;;;;;;;;1;1}{;0;48;light-missile medium-missile special-missile;0;0;0;;;;;;;;;1;1}', '', '', '', '', '', '0', '360', '0', '', '', '', '', '','pPiI']
    return unit

  def insertUnit(self, inputRecord):
    minpos = 0 # relevant position
    maxpos = 0 # additional info
    # find relevant position to insert record
    for i in range(len(self.records)):
      if (len(self.records[i])) and (self.records[i][4]==inputRecord[4]): # if the same unit type
        if self.records[i][2]<=inputRecord[2]: # compare the unit name, not the key
          minpos = i
        else:
          maxpos = i
    #print "Insert between min, max = ", minpos, maxpos
    self.records.insert(minpos+1, inputRecord) # insert record
    print "New unit inserted at line", minpos+2
    return

  def getHeader(self):
  # returns the unit header
    header = self.records[0]
    return header

  def getUnitKey(self, currentUnitKey='', offset=0):
  #reads next unit from given current unit key
    if currentUnitKey=='':
      index = 3
    else:
      index = self.getUnitIndex(currentUnitKey) + offset
    while len(self.records[index])==0:
      index += offset
    unitKey = self.records[index][0]
    return unitKey

  def standardSort(self):
  # sorts records by standard sorting, i.e. type, role, key
    header = self.records[0:3]
    del self.records[0]
    del self.records[0]
    idxFooter = self.getUnitIndex('last_entry_sentinel__upgrades')
    footer = self.records[idxFooter]
    del self.records[idxFooter]
    #print "header", header
    #print "footer", footer
    # CLEAN empty rows
    records = []
    for i in range(len(self.records)):
      try:
        if len(self.records[i])>0: # ignore empty rows
          records += [self.records[i]]
      except:
        pass
    self.records = records
    records = []
    #print "records:", len(self.records)

    # SORT
    def sortByTypeRole(a):
    # sort by columns 4(type), 5(role), 0(key)
        return (a[4], a[5], a[0])

    self.records.sort(key=sortByTypeRole)

    # restore header and footer    
    self.records.append(footer)
    self.records.insert(0, header[2]) # insert record
    self.records.insert(0, header[1])
    self.records.insert(0, header[0])

    # write complete records again to units.csv file
    file = open(self.unitCsvAddress, "wb")
    self.writer = csv.writer(file)
    self.writer.writerows(self.records)
    file.close()

    # backup
    #map(operator.itemgetter(4), self.records)
    #self.records.sort(key=operator.itemgetter(4))
