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
#ifndef FACTION_H_INCLUDED
#define FACTION_H_INCLUDED

#include <QColor>
#include <QString>
#include <QIcon>

class Faction {
public:
  Faction(const QString &n, const QColor &c, const QIcon &i) {factionName = n; factionColor = c; factionLogo = i;}
  QColor color() {return factionColor;}
  QString name() {return factionName;}
  QIcon icon() {return factionLogo;}
  void setShortCut(const QString &cut) {theShortCut = cut;}
  QString shortCut() {return theShortCut;}
private:
  QColor factionColor;
  QString factionName;
  QIcon factionLogo;
  QString theShortCut;
};

#endif // FACTION_H_INCLUDED
