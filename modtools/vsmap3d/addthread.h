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
#ifndef ADDTHREAD_H
#define ADDTHREAD_H

#include <QDomDocument>
#include <QString>
#include <QTreeWidget>
#include <QThread>
#include <QWaitCondition>
#include <QMutex>

class System;

class AddThread : public QThread
{
  Q_OBJECT
public:
  AddThread(QObject * parent = 0);
  ~AddThread();
  void scanUniverse(QDomDocument &domDocument, const QString &vegaStrikeDir);
  void run();
signals:
  void foundSystem(System *system);
  void printMsg(const QString &text);
  void initProgress(int min, int max);
  void finishedScanning();
private:
  void parseElement(const QDomElement &element);
  QMutex mutex;
  QWaitCondition condition;
  QDomDocument domDocument;
  QString vegaStrikeDir;
  bool restart;
  bool abort;
};

#endif

