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
#ifndef SAXHANDLER_H
#define SAXHANDLER_H

#include <QXmlDefaultHandler>

class VSMap3DConfig;

class SaxHandler : public QXmlDefaultHandler
{
public:
  SaxHandler(VSMap3DConfig *vsmap3dconfig);

  bool startElement(const QString &namespaceURI, const QString &localName,
                    const QString &qName, const QXmlAttributes &attributes);
  bool endElement(const QString &namespaceURI, const QString &localName,
                  const QString &qName);
  bool characters(const QString &str);
  bool fatalError(const QXmlParseException &exception);

private:
  VSMap3DConfig *config;
};

#endif
