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
#include "xmlgenerator.h"
#include <QVariant>
#include <QHashIterator>

XmlGenerator::XmlGenerator(QHash<QString, QVariant*> *props)
{
  properties = props;
}

bool XmlGenerator::write(QIODevice *device)
{
  out.setDevice(device);
  out.setCodec("UTF-8");
  out << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
  out << "<properties>\n";

  QHashIterator<QString, QVariant *> i(*properties);
  while (i.hasNext()) {
    i.next();
    QVariant *var = i.value();
    QString value = "unknown";
    QString type = "unknown";
    if ( var->canConvert<QString>() ) {
      value =  var->toString();
      type = "String";
    }
    out << indent(1) << "<property name=" << escapedAttribute(i.key());
    out << " value=" << escapedAttribute(value) << " ";
    out << "type=" << escapedAttribute(type) << " />" << endl;
  }

  out << "</properties>\n";
  return true;
}

QString XmlGenerator::indent(int depth)
{
  const int IndentSize = 2;
  return QString(IndentSize * depth, ' ');
}

QString XmlGenerator::escapedText(const QString &str)
{
  QString result = str;
  result.replace("&", "&amp;");
  result.replace("<", "&lt;");
  result.replace(">", "&gt;");
  return result;
}

QString XmlGenerator::escapedAttribute(const QString &str)
{
  QString result = escapedText(str);
  result.replace("\"", "&quot;");
  result.prepend("\"");
  result.append("\"");
  return result;
}

