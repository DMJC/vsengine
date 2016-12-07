#---------------------------------------------------------------------------------
# Vega Strike modding program for obj to bfxm conversion
# Copyright (C) 2008 Vega Strike team
# Contact: hellcatv@users.sourceforge.net
# Internet: http://vegastrike.sourceforge.net/
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 3
# of the License, or (at your option) any later version.
#
# Description: Simple PNG IHDR header reader to get width & heigth of image
# 
# Author: pyramid
# Version: 2008-11-03 | v0.38
# Contact: pyramid@sapo.pt
#---------------------------------------------------------------------------------

#import zlib, struct

signature = "89504e470d0a1a0a"

def loadPngHeader(fileAddress):
  f = open(fileAddress, 'rb')
  chunk = f.read(8) #signature
  if chunk.encode('hex')!=signature:
    f.close()
    return 0, 0
  chunk = f.read(4) #chunk length
  chunk = f.read(4) #IHDR
  chunk = f.read(4) #width
  width = int(chunk.encode('hex'), 16)
  #print chunk.encode('hex'), chunk.encode('utf')
  chunk = f.read(4) #heigth
  heigth = int(chunk.encode('hex'), 16)
  #print chunk.encode('hex'), chunk.encode('utf')
  f.close()
  return width, heigth
