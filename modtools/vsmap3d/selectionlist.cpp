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
#include "selectionlist.h"

#include <QStringList>
#include <QListWidget>
#include <QListWidgetItem>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

// public
SelectionList::SelectionList(QWidget *parent)
    : QWidget(parent)
{
  QHBoxLayout *hlayout = new QHBoxLayout;
  hlayout->setSpacing(5);

  availableList = new QListWidget();
  QLabel *label = new QLabel(tr("Factions"));
  QVBoxLayout *vlayout = new QVBoxLayout();
  vlayout->addWidget(label);
  vlayout->addWidget(availableList);
  hlayout->addLayout(vlayout);

  selectedList = new QListWidget();
  label = new QLabel(tr("Avoid"));
  vlayout = new QVBoxLayout();
  vlayout->addWidget(label);
  vlayout->addWidget(selectedList);
  hlayout->addLayout(vlayout);

  setLayout(hlayout);
}

void SelectionList::addItems(QMap<QString, QColor> *colorMap) {
  disconnect(availableList, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(select(QListWidgetItem *)));
  disconnect(selectedList, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(unselect(QListWidgetItem *)));

  selection.clear();
  selectedList->clear();
  availableList->clear();
  fillAvailableItems(colorMap);

  connect(availableList, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(select(QListWidgetItem *)));
  connect(selectedList, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(unselect(QListWidgetItem *)));
}

void SelectionList::setSelectedItems(const QStringList &selected) {
  QList<QListWidgetItem *> items;
  int size = availableList->count();
  for (int i = 0; i < size; i++) {
    QListWidgetItem *item = availableList->item(i);
    if (selected.contains(item->text())) {
      items.append(item);
    }
  }
  size = items.size();
  for (int i = 0; i < size; i++) {
    QListWidgetItem *item = items.at(i);
    select(item);
  }
}

void SelectionList::fillAvailableItems(QMap<QString, QColor> *colorMap) {
	if (colorMap != 0) {
	  QStringList names(colorMap->keys());
	  for (int i = 0, size = names.size(); i < size; i++) {
	    QString name = names.at(i);
	    QColor color = colorMap->value(name);
	    QListWidgetItem *item = new QListWidgetItem(name);
	    item->setForeground(color);
	    availableList->addItem(item);
	  }
	}
}

QStringList SelectionList::selectedItems() {
  QStringList selection;
  int size = selectedList->count();
  for (int i = 0; i < size; i++) {
    QListWidgetItem *item = selectedList->item(i);
    selection.append(item->text());
  }
  return selection;
}

// private slots
void SelectionList::select(QListWidgetItem *item) {
  int row = availableList->row(item);
  QString choice = item->text();
  if (!selection.contains(choice)) {
    selection.append(choice);
  }
  availableList->takeItem(row);
  availableList->sortItems();
  selectedList->addItem(item);
  selectedList->sortItems();
}

void SelectionList::unselect(QListWidgetItem *item) {
  int row = selectedList->row(item);
  QString choice = item->text();
  if (selection.contains(choice)) {
    selection.removeAll(choice);
  }
  selectedList->takeItem(row);
  selectedList->sortItems();
  availableList->addItem(item);
  availableList->sortItems();
}
