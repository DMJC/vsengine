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
#ifndef SELECTIONLIST_H_INCLUDED
#define SELECTIONLIST_H_INCLUDED

#include <QWidget>
#include <QMap>

class QStringList;
class QListWidget;
class QListWidgetItem;
class QString;
class QColor;

class SelectionList : public QWidget
{
  Q_OBJECT

public:
  SelectionList(QWidget *parent = 0);
  void addItems(QMap<QString, QColor> *colorMap);
  void setSelectedItems(const QStringList &selected);
  QStringList selectedItems();
private slots:
  void select(QListWidgetItem *item);
  void unselect(QListWidgetItem *item);
private:
  void fillAvailableItems(QMap<QString, QColor> *colorMap);

  QStringList selection;
  QListWidget *availableList;
  QListWidget *selectedList;
};

#endif // SELECTIONLIST_H_INCLUDED
