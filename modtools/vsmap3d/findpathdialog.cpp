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
#include "findpathdialog.h"
#include "glsceene.h"
#include "selectionlist.h"
#include "faction.h"

FindPathDialog::FindPathDialog(QWidget *parent, const QStringList &systemNames, QMap<QString, Faction *> *factionMap,
      const QString &initStart, const QString &initEnd, const QStringList &initAvoided)
    : QDialog(parent)
{
  QMap<QString, QColor> *coloredItems = new QMap<QString, QColor>();
  if (factionMap != 0) {
 	  QStringList names(factionMap->keys());
	  for (int i = 0, size = names.size(); i < size; i++) {
	    QString name = names.at(i);
	    Faction *faction = factionMap->value(name);
      coloredItems->insert(name, faction->color());
	  }
  }

  QLabel *fromLabel = new QLabel(tr("From:"));
  QLabel *toLabel = new QLabel(tr("To:"));
  fromCombo = new QComboBox();
  fromCombo->addItems( systemNames );
  toCombo = new QComboBox();
  toCombo->addItems( systemNames );
  if ( systemNames.size() > 0 ) {
    if (initStart.isEmpty()) {
      fromCombo->setCurrentIndex(0);
    } else {
      fromCombo->setCurrentIndex(systemNames.indexOf(initStart));
    }
    if (initEnd.isEmpty()) {
      toCombo->setCurrentIndex(0);
    } else {
      toCombo->setCurrentIndex(systemNames.indexOf(initEnd));
    }
  }
  factionSelection = new SelectionList();
  factionSelection->addItems( coloredItems );
  factionSelection->setSelectedItems( initAvoided );
  QGroupBox *groupBox = new QGroupBox(tr("Choose the factions to be avoided:"));
  QVBoxLayout *vbox = new QVBoxLayout;
  vbox->addWidget(factionSelection);
  groupBox->setLayout(vbox);

  QPushButton *searchButton = new QPushButton(tr("Search"));
  searchButton->setDefault( true );
  QPushButton *cancelButton = new QPushButton(tr("Cancel"));

  connect(searchButton, SIGNAL(clicked()), this, SLOT(startSearch()));
  connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));

  QGridLayout *layout = new QGridLayout;
  layout->setColumnStretch(1, 1);
  layout->setColumnMinimumWidth(1, 250);
  layout->addWidget(fromLabel, 0, 0);
  layout->addWidget(fromCombo, 0, 1);
  layout->addWidget(toLabel, 1, 0);
  layout->addWidget(toCombo, 1, 1);
  layout->addWidget(groupBox, 2, 0, 1, 2);
  layout->addWidget(searchButton, 4, 0);
  layout->addWidget(cancelButton, 4, 1);
  setLayout(layout);

  setWindowTitle(tr("Find Path"));
}

void FindPathDialog::startSearch()
{
  emit findRoute(fromCombo->currentText(), toCombo->currentText(), factionSelection->selectedItems());
  accept();
}

