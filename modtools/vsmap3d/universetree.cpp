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
#include <QtGui>
#include <math.h>
#include "universetree.h"
#include "system.h"
#include "faction.h"

UniverseTree::UniverseTree(QWidget *parent)
    : QTreeWidget(parent)
{
   minXCoord = 0.0;
   maxXCoord = 0.0;
   minYCoord = 0.0;
   maxYCoord = 0.0;
   minZCoord = 0.0;
   maxZCoord = 0.0;
   QStringList labels;
   labels << tr("Sector/System");

   header()->setResizeMode(QHeaderView::Interactive);
   setHeaderLabels(labels);
   setSelectionMode( QAbstractItemView::ExtendedSelection );

   sectorIcon.addPixmap(QPixmap("sector32.png"));
   systemIcon.addPixmap(QPixmap("system32.png"));

   connect(&thread, SIGNAL(foundSystem(System*)), this, SIGNAL(createStar(System*)));
   connect(&thread, SIGNAL(printMsg(const QString &)), this, SIGNAL(printMsg(const QString &)));
   connect(&thread, SIGNAL(initProgress(int, int)), this, SIGNAL(initProgress(int, int)));
   connect(&thread, SIGNAL(foundSystem(System*)), this, SIGNAL(advanceProgress()));
   connect(&thread, SIGNAL(finishedScanning()), this, SLOT(finishedScanning()));
   connect(&thread, SIGNAL(finishedScanning()), this, SIGNAL(finishedLoading()));
}

bool UniverseTree::read(const QString &dirName, const QString &universeFile)
{
  QString errorStr;
  int errorLine;
  int errorColumn;
  // get universe file
  if (dirName.isEmpty()) return false;

  QString fileName = QDir::convertSeparators("%1/%2").arg(dirName).arg(universeFile);
  QFile file(fileName);
  if (!file.open(QFile::ReadOnly | QFile::Text)) {
    QMessageBox::warning(this, tr("Universe XML file"),
                         tr("Cannot find file %1:\n%2. Make sure you chose the top level installation folder!")
                         .arg(fileName)
                         .arg(file.errorString()));
    return false;
  }

  // read the xml data
  QTime time;
  time.start();
  if (!domDocument.setContent(&file, true, &errorStr, &errorLine,
                            &errorColumn)) {
    QMessageBox::information(window(), tr("VSMap3D"),
                               tr("Parse error at line %1, column %2:\n%3")
                               .arg(errorLine)
                               .arg(errorColumn)
                               .arg(errorStr));
    return false;
  }
  emit printMsg(tr("setting content took %1 ms<br>").arg(time.elapsed()));
  // safe the current Vega Strike directory
  vegaStrikeDir = dirName;

  // clear the lists
  clear();
  systemForSystemName.clear();
  sectorNameForItem.clear();
  systemNameForItem.clear();
  emit deleteStars(); // it's the responsibility of GLSceene to delete the display lists and stars
  // start thread that adds the sectors and systems to the tree widget
  thread.scanUniverse(domDocument, vegaStrikeDir);

  return true;
}

void UniverseTree::addSystem(System *system)
{
  QString sectorName = system->sector();
  QString systemName = system->name();
  QTreeWidgetItem *sectorItem;
  if (sectorNameForItem.contains(sectorName)) {
    sectorItem = sectorNameForItem.value(sectorName);
  }
  else {
    sectorItem = new QTreeWidgetItem(this, 0);
    sectorItem->setText(0, sectorName);
    sectorItem->setIcon(0, sectorIcon);
    bool folded = true;
    setItemExpanded(sectorItem, !folded);
    sectorNameForItem.insert(sectorName, sectorItem);
  }
  if (!systemNameForItem.contains(systemName)) {
    // create new tree widget item
    QTreeWidgetItem *systemItem = systemItem = new QTreeWidgetItem(sectorItem, 1);
    systemItem->setText(0, systemName);
    Faction *fac = system->systemFaction();
    if (fac != 0) {
      QPixmap pm = fac->icon().pixmap(32, 32);
      QIcon icon(pm);
      systemItem->setIcon(0, icon);
    } else {
      systemItem->setIcon(0, systemIcon);
    }
    QList<Jump *> *jumps = system->jumps();
    int max = jumps->size();
    QString jumpNames;
    if (max==0) {
      jumpNames = "No jumps.";
    }
    else {
      jumpNames = "Jumps:";
    }
    for (int j=0; j<max; ++j) {
      Jump *jump = jumps->at(j);
      jumpNames.append(tr(" %1/%2").arg(jump->dSector()).arg(jump->dSystem()));
      if (j<max-1) jumpNames.append(",");
      // only create display lists for jumps whos destination systems are already scanned in
      if (systemForSystemName.contains(jump->dSystem())) {
        System *destSystem = systemForSystemName.value(jump->dSystem());
        float dx = destSystem->x()-system->x();
        float dy = destSystem->y()-system->y();
        float dz = destSystem->z()-system->z();
        float dist = sqrt(dx*dx + dy*dy + dz*dz);
        jump->setDestination(destSystem, dist);
        // now find the backwards pointing jump in the destination system to set it's destination system, too
        int djmax = destSystem->jumps()->size();
        for (int dji=0; dji<djmax; dji++) {
          Jump *djump = destSystem->jumps()->at(dji);
          if (djump->dSector() == system->sector() && djump->dSystem() == system->name()) {
            djump->setDestination(system, dist);
            break;
          }
        }
        emit createJump(system, destSystem, jump);
      }
    }
    QString facName = system->faction();
    if (facName == "") {
      facName = "unknown";
      system->setFaction(facName);
    }
    QString starInfo = "";
    if (system->sunR() > 0.0f) {
        int iR = (int)(system->sunR()/1.490660009e-12);
        QColor c = system->starColor();
        starInfo = tr("Radius: %1\nColor: %2 %3 %4 %5\nTexture: %6\n").arg(iR).arg(c.red()).arg(c.green()).arg(c.blue()).arg(c.alpha()).arg(system->starTexture());
    }
    QString tip(tr("%1Faction: %2\n%3").arg(starInfo).arg(facName).arg(jumpNames));
    systemItem->setToolTip(0, tip);
    bool folded = true;
    setItemExpanded(sectorItem, !folded);
    systemNameForItem.insert(systemName, systemItem);
    systemForSystemName.insert(systemName, system);

    if (system->x() < minXCoord) minXCoord = system->x();
    else if (system->x() > maxXCoord) maxXCoord = system->x();
    if (system->y() < minYCoord) minYCoord = system->y();
    else if (system->y() > maxYCoord) maxYCoord = system->y();
    if (system->z() < minZCoord) minZCoord = system->z();
    else if (system->z() > maxZCoord) maxZCoord = system->z();
    if (ownershipPerFaction.contains(facName)) {
      int count = ownershipPerFaction.value(facName)+1;
      ownershipPerFaction.insert(facName, count);
    }
    else {
      ownershipPerFaction.insert(facName, 1);
    }
  }
}

void UniverseTree::finishedScanning()
{
  emit foundUniverseBounds(minXCoord, maxXCoord, minYCoord, maxYCoord, minZCoord, maxZCoord);
  emit printMsg(tr("Universe statistical data:<br>"));
  emit printMsg(tr("X dimension (min/max): %1 / %2<br>").arg(minXCoord).arg(maxXCoord));
  emit printMsg(tr("Y dimension (min/max): %1 / %2<br>").arg(minYCoord).arg(maxYCoord));
  emit printMsg(tr("Z dimension (min/max): %1 / %2<br>").arg(minZCoord).arg(maxZCoord));
  int numSystems = systemForSystemName.size();
  if (numSystems == 0) numSystems = 1;
  QHashIterator<QString, int> i(ownershipPerFaction);
  while (i.hasNext()) {
    i.next();
    int owns = i.value();
    emit printMsg(tr("Faction %1 owns %2 systems (%3 %).<br>").arg(i.key()).arg(owns).arg(100*owns/numSystems));
  }
  emit printMsg(tr("%1 systems in total.<br>").arg(numSystems));
}

