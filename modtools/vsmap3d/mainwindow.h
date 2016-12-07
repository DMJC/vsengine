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
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QSet>
#include "vsmap3dconfig.h"
#include "starstxt.h"

class QProgressBar;
class QTextEdit;
class QDoubleSpinBox;
class UniverseTree;
class GLSceene;
class QSplitter;
class QAction;
class QWidgetAction;
class System;
class StarsTxt;
class Faction;

class MainWindow : public QMainWindow {
Q_OBJECT

public:
	MainWindow();
	bool restoreWindowProperties();

private slots:
	void open();
	void about();
	void initProgress(int min, int max);
	void advanceProgress();
	void finalizeLoading();
	void processItemSelection();
	void showFindRouteDialog();
	void filterSystem(System *s);
	void toggleFullScreen();
  void setFactions(QMap<QString, Faction *> *factions);
  void factionToggled();
signals:
	void displayNames(bool bvalue);
	void displayJumps(bool bvalue);
	void displayFactionBubbles(bool bvalue);
	void lightOn(bool bvalue);
	void displayJumplessSystems(bool bvalue);
	void plusPressed(float zoomStep);
	void minusPressed(float zoomStep);
	void leftPressed(float rotStep);
	void rightPressed(float rotStep);
	void upPressed(float rotStep);
	void downPressed(float rotStep);
	void mouseDragged(float dx, float dy);
	void mouseScrolled(float steps);
  void printMsg(const QString &text);
  void showShiftChoices(bool bvalue);
protected:
	void keyPressEvent(QKeyEvent *event);
  void keyReleaseEvent(QKeyEvent *event);
	void wheelEvent(QWheelEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void resizeEvent ( QResizeEvent * event );
	void moveEvent ( QMoveEvent * event );

private:
	void createActions();
	void createMenus();

	int lastDragX;
	int lastDragY;

	UniverseTree *tree;
	GLSceene* sceene;
	QTextEdit *edit;
	QSplitter *hSplitter;
	QByteArray hState;
	QSplitter *vSplitter;
	QDoubleSpinBox *bubbleSpinner;
	QByteArray vState;

	QMenu *fileMenu;
	QMenu *viewMenu;
  QMenu *viewFactionsMenu;
	QMenu *helpMenu;
	QAction *openAct;
	QAction *toggleFullScreenAct;
	QAction *toggleNamesAct;
	QAction *toggleJumpsAct;
	QAction *toggleLightsAct;
	QAction *toggleJumplessSystemsAct;
	QAction *toggleFactionBubblesAct;
  QWidgetAction *bubbleAct;
	QAction *findRouteAct;
	QAction *exitAct;
	QAction *aboutAct;
	QAction *aboutQtAct;
	QProgressBar *progress;
	QStringList systemsWithJumps;
	VSMap3DConfig config;
  StarsTxt *starsData;

  QMap<QAction *, Faction *> factionActions;
  QSet<Faction *> factionSelection;
  QMap<QString, Faction *> *allFactions;
};

#endif
