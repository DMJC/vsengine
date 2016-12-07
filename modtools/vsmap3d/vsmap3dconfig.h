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
#ifndef VSMAPS3DCONFIG_H
#define VSMAPS3DCONFIG_H

#include <QObject>
#include <QHash>

class QVariant;

class VSMap3DConfig : public QObject
{
  Q_OBJECT

public:
  VSMap3DConfig(QObject *parent = 0);
  ~VSMap3DConfig();
  void loadConfig();
  void setProperty(const QString &name, QVariant *value);
  QVariant *property(const QString &name);

private:
  void saveConfig();
  QHash<QString, QVariant*> properties;
};

#endif
