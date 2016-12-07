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
#include "saxhandler.h"

#include <QVariant>
#include "vsmap3dconfig.h"

SaxHandler::SaxHandler(VSMap3DConfig *vsmap3dconfig)
{
  config = vsmap3dconfig;
}

bool SaxHandler::startElement(const QString &namespaceURI, const QString &localName,
                    const QString &qName, const QXmlAttributes &attributes)
{
  if (qName == "property") {
    QString name = attributes.value("name");
    QString type = attributes.value("type");
    QString stringValue = attributes.value("value");
    QVariant *value = 0;
    if (type == "String") {
      value = new QVariant(stringValue);
    }
    if (value) {
      config->setProperty(name, value);
    }
  }
  return true;
}

bool SaxHandler::endElement(const QString &namespaceURI, const QString &localName,
                  const QString &qName)
{
  return true;
}

bool SaxHandler::characters(const QString &str)
{
  return true;
}

bool SaxHandler::fatalError(const QXmlParseException &exception)
{
  return false;
}

