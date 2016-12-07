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
#include <QtCore/QtCore>

#include "addthread.h"
#include "system.h"

AddThread::AddThread(QObject *parent)
  : QThread(parent)
{
  restart = false;
  abort = false;
}

AddThread::~AddThread()
{
  mutex.lock();
  abort = true;
  condition.wakeOne();
  mutex.unlock();
  wait();
}

void AddThread::scanUniverse(QDomDocument &domDocument, const QString &vegaStrikeDir)
{
  QMutexLocker locker(&mutex);
  this->domDocument = domDocument;
  this->vegaStrikeDir = vegaStrikeDir;
  if (!isRunning()) {
    start(LowPriority);
  } else {
    restart = true;
    condition.wakeOne();
  }
}

/** Starts to parse the dom document of the universe xml file. */
void AddThread::run()
{
  mutex.lock();
  QDomDocument domDocument = this->domDocument;
  QString vegaStrikeDir = this->vegaStrikeDir;
  mutex.unlock();

  // scan the xml data and build up the item tree
  QDomElement root = domDocument.documentElement();
  if (root.tagName() != "galaxy") {
    emit printMsg(tr("The file is not a Vega Strike universe file."));
    return;
  }

  QTime time;
  QDomElement child;
  time.start();
  child = root.firstChildElement("systems");
  // now fetch the universe structure
  if (!child.isNull()) {
    // count number of systems
    int systemCount = 0;
    QDomElement childSector = child.firstChildElement("sector");
    while (!childSector.isNull()) {
      QDomElement childSystem = childSector.firstChildElement("system");
      while (!childSystem.isNull()) {
        systemCount++;
        childSystem = childSystem.nextSiblingElement("system");
      }
      childSector = childSector.nextSiblingElement("sector");
    }
    emit initProgress(0, systemCount);
    emit printMsg(tr("counting systems took %1 ms<br>").arg(time.elapsed()));
    parseElement(child);
    child = child.nextSiblingElement("systems");
  }
  // reset progress bar after loading
  emit finishedScanning();
  emit printMsg(tr("fetching systems took %1 ms<br>").arg(time.elapsed()));
}

void AddThread::parseElement(const QDomElement &element)
{
  QString parentName;
  if (element.hasAttribute("name")) {
    parentName = element.attribute("name");
  }
  if (parentName.isEmpty()) {
    if (element.tagName() == "systems") {
      parentName = QObject::tr("Systems");
    }
    else if (element.tagName() == "sector") {
      parentName = QObject::tr("Sector");
    }
    else {
      parentName = "Unknown";
    }
  }
  QDomElement child = element.firstChildElement();
  while (!child.isNull()) {
    if (child.tagName() == "sector") {
      parseElement(child);
    }
    else if (child.tagName() == "system") {
      QString childName;
      if (child.hasAttribute("name")) {
        childName = child.attribute("name");
      }
      if (!childName.isEmpty()) {
        System *system = new System(parentName, childName);
        // get most important info about the system
        QDomElement systemChild = child.firstChildElement("var");
        while (!systemChild.isNull()) {
          QString attrName = systemChild.attribute("name", "");
          if (attrName == "faction") {
            system->setFaction(systemChild.attribute("value", "unknown"));
          }
          else if (attrName == "sun_radius") {
            system->setSunRadius(systemChild.attribute("value", "16600.000000").toFloat());
          }
          else if (attrName == "xyz") {
            QString tmp = systemChild.attribute("value", "invalid");
            QStringList tmpList = tmp.split(" ");
            system->setXYZ(tmpList.at(0).toFloat(), tmpList.at(1).toFloat(), tmpList.at(2).toFloat());
          }
          else if (attrName == "jumps") {
            QString tmp = systemChild.attribute("value", "");
            if (!tmp.isEmpty()) {
              QStringList tmpList = tmp.split(" ");
              int max = tmpList.size();
              for (int j=0; j<max; ++j) {
                QString jumpName = tmpList.at(j);
                system->addJump(jumpName);
              }
            }
          }
          systemChild = systemChild.nextSiblingElement("var");
        }
        emit foundSystem(system);
      }
    }
    child = child.nextSiblingElement();
  }
}

