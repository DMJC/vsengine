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
#ifndef GLSCEENE_H
#define GLSCEENE_H

#include <QGLWidget>
#include <QHash>
#include <QMap>
#include <QSet>

#include "system.h"

//glFont character structure
typedef struct
{
	float dx, dy;
	float tx1, ty1;
	float tx2, ty2;
} GLFONTCHAR;

//glFont structure
typedef struct
{
	int Tex;
	int TexWidth, TexHeight;
	int IntStart, IntEnd;
	GLFONTCHAR *Char;
} GLFONT;

class Jump;
class StarsTxt;
class QString;
class QStringList;
class QTimer;
class QTreeWidgetItem;
class QFont;
class Faction;

class GLSceene : public QGLWidget
{
  Q_OBJECT
public:
  GLSceene( QWidget* parent = 0 );
  ~GLSceene();
  float bubbleFactor();
  bool isLightsOn() {return lightsOn;}
  QString routeStart() {return (pathList.isEmpty()) ? QString("") : pathList.first()->name();}
  QString routeEnd() {return (pathList.isEmpty()) ? QString("") : pathList.last()->name();}
  QStringList routeAvoidsFactions() {return avoidedFactions;}
public slots:
  void initializeSceene(float minx, float maxx, float miny, float maxy, float minz, float maxz);
  void addStar(System *star);
  void removeStars();
  void addJump(System *src, System *dest, Jump *jump);
  void setDisplayNames(bool bvalue) {displayNames=bvalue; updateGL();}
  void setDisplayJumps(bool bvalue) {displayJumps=bvalue; updateGL();}
  void setDisplayJumplessSystems(bool bvalue) {displayJumplessSystems=bvalue; updateGL();}
  void setDisplayFactionBubbles(bool bvalue);
  void setLightsOn(bool bvalue) {lightsOn=bvalue; updateGL();}
  void turnLeft(float rotStep);
  void turnRight(float rotStep);
  void turnUp(float rotStep);
  void turnDown(float rotStep);
  void turn(float dx, float dy);
  void zoom(float steps);
  void loadingFinished();
  void flyToTarget();
  void setSelection(const QList<QTreeWidgetItem *> selectedItems);
  void treeDoubleClicked(QTreeWidgetItem *item, int col);
  void setPath(const QString &startSystemName=QString(), const QString &destinationSystemName=QString(), const QStringList &factions=QStringList());
  void toggleFullScreen();
  void setBubbleFactor(double f);
  void makeFactionBubble(System *star, float exaggerate, bool replaceDisplayList);
  void setFactions(QMap<QString, Faction *> *factions) {factionsMap = factions;}
  void showShiftChoices(bool bvalue);
  void toggleFaction(Faction *faction);
signals:
  void printMsg(const QString &text);
protected:
  void mouseReleaseEvent(QMouseEvent *event);
  void initializeGL();
  void paintGL();
  void resizeGL( int w, int h );
  void overpaint(QPainter *painter);
  void makeFactionBubble(System *star, float exaggerate);

private:
  float getAngle(float rx, float ry, float offset = 0.0);
  QMap<QString, QString> *toggleShortCuts();

  QFont starNamesFont;
  QColor sceeneBackground;
  int numGLObjects;
  int stats[8];
  QList<System *> systems;
  QHash<QString, System *> systemForSystemName;
  QHash<QString, GLuint> textures;
  bool displayNames;
  bool displayJumps;
  bool displayJumplessSystems;
  bool shiftChoices;
  bool lightsOn;
  float eyepos[3];
  float eyerot[3];
  float clipSize[6];
  float maxClip;
  float eyetargetpos[3];
  float flightPath[3];
  float dummy;
  float exaggeration;
  int currentStep;
  bool eyeDestinationChanged;
  QTimer *flyTimer;
  float zoomSpeed;
  QList<QString> treeSystemSelection;
  QList<QString> treeSectorSelection;
  QList<System *> pathList;
  QMap<QString, Faction *> *factionsMap;
  QSet<Faction *> factionSelection;
  QStringList avoidedFactions;
};

#endif
