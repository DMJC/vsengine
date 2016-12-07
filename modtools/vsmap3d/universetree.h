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
#ifndef UNIVERSETREE_H
#define UNIVERSETREE_H

#include <QDomDocument>
#include <QHash>
#include <QIcon>
#include <QTreeWidget>
#include "addthread.h"

class System;
class Jump;

class UniverseTree : public QTreeWidget
{
  Q_OBJECT

public:
  UniverseTree(QWidget *parent = 0);

  bool read(const QString &dirName, const QString &universeFile);
  QString *getVegaStrikeDir() {return &vegaStrikeDir;}
  QDomDocument *getDomDocument() {return &domDocument;}
  float minX() {return minXCoord;}
  float maxX() {return maxXCoord;}
  float minY() {return minYCoord;}
  float maxY() {return maxYCoord;}
  float minZ() {return minZCoord;}
  float maxZ() {return maxZCoord;}
  QHash<QString, System *> systems() {return systemForSystemName;}

public slots:
  void addSystem(System *system);
  void finishedScanning();
signals:
  void printMsg(const QString &text);
  void initProgress(int min, int max);
  void advanceProgress();
  void finishedLoading();
  void foundUniverseBounds(float minx, float maxx, float miny, float maxy, float minz, float maxz);
  void createStar(System *star);
  void deleteStars();
  void createJump(System *src, System *dest, Jump *jump);

private:
  AddThread thread;
  QDomDocument domDocument;
  QHash<QString, System *> systemForSystemName;
  QHash<QString, QTreeWidgetItem *> sectorNameForItem;
  QHash<QString, QTreeWidgetItem *> systemNameForItem;
  QIcon sectorIcon;
  QIcon systemIcon;

  QString vegaStrikeDir;
  // statistical information about the universe
  float minXCoord;
  float maxXCoord;
  float minYCoord;
  float maxYCoord;
  float minZCoord;
  float maxZCoord;
  QHash<QString, int> ownershipPerFaction;
};

#endif

