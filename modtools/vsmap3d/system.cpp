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
#include "system.h"

#include "faction.h"
#include <QStringList>

Jump::Jump(const QString &dSector, const QString &dSystem)
{
  destinationSector = dSector;
  destinationSystem = dSystem;
  dist = -1.0;
  destSystem = 0;
}

System::System(const QString &sector, const QString &name)
{
    sysColor.setRgbF(1.0f, 1.0f, 0.6f, 1.0f);
    textureName.clear();

    sectorName = QString(sector);
    systemName = QString(name);
    sunRadius = 1.0;
    xCoord = 1.0;
    yCoord = 1.0;
    zCoord = 1.0;
    pathJumpTo = 0;
    pathJumpFrom = 0;
    astarf = 0.0;
    astarg = 0.0;
}

void System::setFaction(const QString &fac)
{
  if (fac.isEmpty()) {
    factionName = "unknown";
  }
  else {
    factionName = QString(fac);
  }
}
void System::addJump(const QString &jumpName)
{
  QStringList list = jumpName.split("/");
  jumpsList.append(new Jump(list.first(), list.last()));
}

