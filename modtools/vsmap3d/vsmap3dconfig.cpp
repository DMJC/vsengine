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
#include <QVariant>
#include <QList>
#include <QXmlSimpleReader>
#include <stdio.h>
#include <QDir>
#include <QCoreApplication>

#include "vsmap3dconfig.h"
#include "saxhandler.h"
#include "xmlgenerator.h"

VSMap3DConfig::VSMap3DConfig(QObject *parent) :
	QObject(parent) {
}

VSMap3DConfig::~VSMap3DConfig() {
	QList<QVariant *> values = properties.values();
	int max = values.size();
	for (int i=0; i<max; i++) {
		delete values.at(i);
	}
	properties.clear();
}

void VSMap3DConfig::loadConfig() {
	QFile file(QDir::convertSeparators(QDir::cleanPath(tr("%1/vsmap3dconfig.xml")
	.arg(QCoreApplication::applicationDirPath()) )));
	if (!file.exists())
		return;
	if (!file.open(QFile::ReadOnly | QFile::Text)) {
		QString msg = tr("Cannot read file %1:\n%2.")
		.arg(file.fileName()).arg(file.errorString());
		fprintf(stderr, "VSMap3DConfigFile: %s\n", msg.toLatin1().data());
		fflush(stderr);
		return;
	}
	QXmlSimpleReader reader;
	SaxHandler handler(this);
	reader.setContentHandler(&handler);
	reader.setErrorHandler(&handler);

	reader.parse(&file);
}

void VSMap3DConfig::saveConfig() {
	QFile file(QDir::convertSeparators(QDir::cleanPath(tr("%1/vsmap3dconfig.xml")
	.arg(QCoreApplication::applicationDirPath()) )));
	if (!file.open(QFile::WriteOnly | QFile::Text)) {
		QString msg = tr("Cannot write file %1:\n%2.")
		.arg(file.fileName()).arg(file.errorString());
		fprintf(stderr, "VSMap3DConfigFile: %s\n", msg.toLatin1().data());
		fflush(stderr);
		return;
	}
	XmlGenerator generator(&properties);
	generator.write(&file);
	file.flush();
	file.close();
}

void VSMap3DConfig::setProperty(const QString &name, QVariant *value) {
	QVariant *oldValue = 0;
	if (properties.contains(name))
		oldValue = properties.value(name);
	properties.insert(name, value);
	if (oldValue)
		delete oldValue;
	saveConfig();
}

QVariant *VSMap3DConfig::property(const QString &name) {
	QVariant *value = 0;
	if (properties.contains(name))
		value = properties.value(name);
	return value;
}

