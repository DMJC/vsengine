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
#ifndef STARSTXT_H_INCLUDED
#define STARSTXT_H_INCLUDED

#include <QString>
#include <QColor>
#include <QIcon>
#include <QMap>
#include <QDomDocument>
#include "system.h"
#include "vsmap3dconfig.h"

class Faction;

class StarsTxt: public QObject
{
  Q_OBJECT
public:
    StarsTxt(QObject * parent = 0);
    StarsTxt(const QString &vegaStrikeDir, VSMap3DConfig &config, QObject * parent = 0);
    ~StarsTxt();
    void loadData(const QString &vegaStrikeDir, VSMap3DConfig &config);
    void setupSystem(System *system);
signals:
    void printMsg(const QString &text);
    void allTheFactions(QMap<QString, Faction *> *factions);
protected:
    void loadData(const QString &filePath);
    void loadFactions(const QString &filePath);
    void processLine(const QString &line);
    void scanFactions(QDomDocument &domDocument);
    void parseElement(const QDomElement &element);
    void loadIcon(QIcon *icon, QString &fileName);
private:
    QMap<int, QColor> colors;
    QMap<int, QString> textures;
    QMap<QString, Faction *> factions;
    QString vegaDir;
};

#endif // STARSTXT_H_INCLUDED
