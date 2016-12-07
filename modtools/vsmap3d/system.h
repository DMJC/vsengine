/**
   VSMap3D is an OpenGL universe explorer for Vega Strike
   universes. You can also search for systems, planets, stations or
   plan routes.

   Copyright (C) 2005  Robert Wloch,
   robertwloch@tempel-der-guten-dinge.de

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Steet, Fifth Floor,
   Boston, MA 02110-1301, USA.
**/
#ifndef SYSTEM_H
#define SYSTEM_H

#include <QString>
#include <QColor>
#include <QList>
#include <QPixmap>
#include <qgl.h>

class System;
class Faction;
class QPixmap;

class Jump
{
public:
  Jump(const QString &dSector, const QString &dSystem);
  QString dSector() {return destinationSector;}
  QString dSystem() {return destinationSystem;}
  void setDestination(System *dest, float d) {destSystem=dest; dist=d;}
  System *destination() {return destSystem;}
  float distance() {return dist;}
  void setGLList(GLuint lid) {list=lid;}
  GLuint glList() {return list;}
private:
  QString destinationSector;
  QString destinationSystem;
  System *destSystem;
  float dist;
  GLuint list;
};

class System
{
public:
  System(const QString &sector, const QString &name);
  void setFaction(const QString &fac);
  // scale sun's radius to global Vega Strike universe axis scale
  // assumptions made for this: Vega Strike Sol sun radius of
  // 16600 units = real Sol radius of 695000 km AND Vega Strike distance
  // Sol->Alpha_Centauri = real distance Sol->Alpha Centauri of 4.36 light years
  void setSunRadius(float sunR) {sunRadius = sunR * 1.490660009e-12;}
  void setXYZ(float x, float y, float z) {xCoord=x; yCoord=y; zCoord=z;}
  void addJump(const QString &jumpName);
  void addGLJump(Jump *jump) {glJumpsList.append(jump);}
  void setGLSystem(GLuint systemID) {glSystemList = systemID;}
  void setGLFactionBubble(GLuint bubbleID) {glFactionBubbleList = bubbleID;}
  QString sector() {return sectorName;}
  QString name() {return systemName;}
  QString faction() {return factionName;}
  float sunR() {return sunRadius;}
  float x() {return xCoord;}
  float y() {return yCoord;}
  float z() {return zCoord;}
  QList<Jump *> *jumps() {return &jumpsList;}
  QList<Jump *> *glJumps() {return &glJumpsList;}
  GLuint glSystem() {return glSystemList;}
  GLuint glFactionBubble() {return glFactionBubbleList;}
  Jump *pathTo() {return pathJumpTo;}
  Jump *pathFrom() {return pathJumpFrom;}
  bool isEndOfPath() {return (pathJumpTo==0 && pathJumpFrom!=0);}
  bool isStartOfPath() {return (pathJumpTo!=0 && pathJumpFrom==0);}
  void setPath(Jump *jumpTo=0, Jump *jumpFrom=0) {pathJumpTo = jumpTo; pathJumpFrom=jumpFrom;}
  void setCosts(float f=0.0, float g=0.0) {astarf=f; astarg=g;}
  float fCosts() {return astarf;}
  float gCosts() {return astarg;}
  void setStarColor(const QColor &color) {sysColor = color;}
  void setStarTexture(const QString &texture) {textureName = texture;}
  QColor starColor() {return sysColor;}
  QString starTexture() {return textureName;}
  void setSystemFaction(Faction *f) {theFaction = f;}
  Faction *systemFaction() {return theFaction;}

private:
  QString sectorName;
  QString systemName;
  QString factionName;
  Faction *theFaction;
  float sunRadius;
  float xCoord;
  float yCoord;
  float zCoord;
  QList<Jump *> jumpsList; // all jumps that connect this system to others
  GLuint glSystemList;
  GLuint glFactionBubbleList;
  QList<Jump *> glJumpsList; // this list contains only the jumps that will be painted since each jump exists in both directions
  Jump *pathJumpTo; // points to next system in a path
  Jump *pathJumpFrom; // points to the previous system in a path
  float astarg;
  float astarf;

  QColor sysColor;
  QString textureName;
  QString theShortCut;
};

#endif

