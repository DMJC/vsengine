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
#include <QtCore>
#include <QtGui>
#include <QFile>
#include <QVariant>
#include <QDir>
#include <QTextStream>

#include "starstxt.h"
#include "vsmap3dconfig.h"
#include "faction.h"

StarsTxt::StarsTxt(QObject *parent)
  : QObject(parent)
{
}

StarsTxt::StarsTxt(const QString &vegaStrikeDir, VSMap3DConfig &config, QObject * parent)
    : QObject(parent)  {
    loadData(vegaStrikeDir, config);
}

StarsTxt::~StarsTxt() {
}

void StarsTxt::loadData(const QString &vegaStrikeDir, VSMap3DConfig &config) {
  vegaDir = vegaStrikeDir;
  // load star info first (color for radius, texture file name)
  QString fileName = "universe/stars.txt";
	// check, if there's a different name cached in the configuration. if so, set that one
	QVariant *var = config.property("starsTxtFile");
	if (var && var->canConvert(QVariant::String) ) {
		QFile file(var->toString());
		if (file.exists() ) {
			fileName = var->toString();
		}
	}
	if (!fileName.isEmpty()) {
        config.setProperty("starsTxtFile", new QVariant(fileName));
        fileName = QString("%1/%2").arg(vegaDir).arg(fileName);
        fileName = QDir::convertSeparators(fileName);
	    loadData(fileName);
	} else {
        QMessageBox::warning(0, tr("Star data file"),
            tr("No star data file. Please set yours in config file using property name \"starsTxtFile\", e.g. \"universe/stars.txt\"!"));
	}

	// load faction info second (logo and color for each faction)
 	fileName = "factions.xml";
	// check, if there's a different name cached in the configuration. if so, set that one
	var = config.property("factionsFile");
	if (var && var->canConvert(QVariant::String) ) {
		QFile file(var->toString());
		if (file.exists() ) {
			fileName = var->toString();
		}
	}
	if (!fileName.isEmpty()) {
        config.setProperty("factionsFile", new QVariant(fileName));
        fileName = QString("%1/%2").arg(vegaDir).arg(fileName);
        fileName = QDir::convertSeparators(fileName);
	    loadFactions(fileName);
	} else {
        QMessageBox::warning(0, tr("Factions XML file"),
            tr("No factions file. Please set yours in config file using property name \"factionsFile\", e.g. \"factions.xml\"!<br>"));
	}
}

void StarsTxt::loadFactions(const QString &filePath) {
    factions.clear();
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(0, tr("Factions XML file"),
            tr("Star data file not readable: %1!<br>").arg(filePath));
        return;
    }

    QString errorStr;
    int errorLine;
    int errorColumn;
    QDomDocument domDocument;
    if (!domDocument.setContent(&file, true, &errorStr, &errorLine,
                            &errorColumn)) {
        QMessageBox::information(0, tr("Factions XML file"),
                               tr("Parse error at line %1, column %2:\n%3")
                               .arg(errorLine)
                               .arg(errorColumn)
                               .arg(errorStr));
        return;
    }
    scanFactions(domDocument);
    file.close();
}

void StarsTxt::scanFactions(QDomDocument &domDocument) {
  // scan the xml data and build up the item tree
  QDomElement root = domDocument.documentElement();
  if (root.tagName() != "Factions") {
    emit printMsg(tr("The file is not a factions file."));
    return;
  }
  QDomElement child;
  child = root.firstChildElement("Faction");
  // now fetch the factions
  while (!child.isNull()) {
    parseElement(child);
    child = child.nextSiblingElement("Faction");
  }
  emit allTheFactions(&factions);
}

void StarsTxt::parseElement(const QDomElement &element)
{
  if (!element.hasChildNodes()) return; // ignore "empty" dummy entries
  QString factionName;
  if (element.hasAttribute("name")) {
    factionName = element.attribute("name");
  }
  if (factionName.isEmpty()) {
    // skip faction tag with no name
    return;
  }
  QIcon factionIcon;
  if (element.hasAttribute("logoRGB")) {
    QString logoName = element.attribute("logoRGB");
    loadIcon(&factionIcon, logoName);
  }
  double dR = 0.5;
  if (element.hasAttribute("sparkred")) {
    QVariant v(element.attribute("sparkred"));
    dR = v.toDouble();
  }
  double dG = 0.5;
  if (element.hasAttribute("sparkgreen")) {
    QVariant v(element.attribute("sparkgreen"));
    dG = v.toDouble();
  }
  double dB = 0.5;
  if (element.hasAttribute("sparkblue")) {
    QVariant v(element.attribute("sparkblue"));
    dB = v.toDouble();
  }
  QColor color = QColor::fromRgbF(dR, dG, dB);
  Faction *faction = new Faction(factionName, color, factionIcon);
  factions.insert(factionName, faction);
  emit printMsg(tr("found faction: <b><font color=\"%1\">%2</font></b><br>").arg(color.name()).arg(factionName));
}

void StarsTxt::loadIcon(QIcon *icon, QString &fileName) {
  fileName = QString("%1/textures/%2").arg(vegaDir).arg(fileName);
  fileName = QDir::convertSeparators(fileName);
	QFile file(fileName);
  if (!file.exists()) {
    fileName = "unknown.png";
  }
  icon->addPixmap(QPixmap(fileName));
}

void StarsTxt::loadData(const QString &filePath) {
    colors.clear();
    textures.clear();
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
//	  emit printMsg(
        QMessageBox::warning(0, tr("Star data file"),
            tr("Star data file not readable: %1!<br>").arg(filePath));
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        processLine(line);
    }
    file.close();
}

/* universe/stars.txt:
0 .3  1  .3  .1 stars/white_star.png
1000 .5  .5  1  .1 stars/white_star.png
2000  .6  .6  1 .1 stars/white_star.png
2998  0  0   0  0  stars/white_star.png
2999  .65  .65   1 .2 sol/sun.png
3500  .7  .7    1 .2 stars/white_star.png
4000  .8  .9   1 .1 sol/sun.png
5500  1  1    1 .1 stars/white_star.png
8000     1  .2  .2 .1 stars/red_star.png
13500 1  1  1  .1 stars/white_star.png
15000  1  .8  .5 .1 stars/white_star.png
18000  1  1   .7 .2 sol/sun.png
36500  1  1    .8 .1 stars/orange_star.png
43000  1  .7   .4 .2 stars/white_star.png
80000  1  .6  .6 .1 stars/red_star.png
*/

void StarsTxt::processLine(const QString &line) {
    QStringList list;
    list = line.split(QRegExp("\\s+"));
    if (list.size() != 6) {
        return;
    }
    QVariant v;
    v.setValue(list.at(0));
    int iSunR = v.toInt();
    v.setValue(list.at(1));
    double dR = v.toDouble();
    v.setValue(list.at(2));
    double dG = v.toDouble();
    v.setValue(list.at(3));
    double dB = v.toDouble();
    // don't want the alpha value
//    v.setValue(list.at(4));
//    double dA = v.toDouble();
    QColor color = QColor::fromRgbF(dR, dG, dB);
    QString texture = list.at(5);
    texture = QString("%1/textures/%2").arg(vegaDir).arg(texture);
    texture = QDir::convertSeparators(texture);
    colors.insert(iSunR, color);
    textures.insert(iSunR, texture);
}

void StarsTxt::setupSystem(System *system) {
    int iR = (int)(system->sunR()/1.490660009e-12);
    QList<int> keys = colors.keys();
    int key = -1, highR = 0;
    for (int i = 0, max = keys.size(); i < max; i++) {
        if (i < max - 1) {
            highR = keys.at(i + 1);
            int lowR = keys.at(i);
            int pivot = lowR + (highR - lowR) / 2;
            if (iR < pivot) {
                key = lowR;
                break;
            }
        } else if (i == max - 1) {
            // last star in the list
            key = keys.at(i);
            break;
        }
    }
    if (key >= 0) {
      system->setStarColor(colors.value(key));
      system->setStarTexture(textures.value(key));
    }
    QString facName = system->faction();
    system->setSystemFaction((factions.contains(facName)) ? factions.value(facName) : 0);
}
