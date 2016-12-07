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

#include "mainwindow.h"
#include "universetree.h"
#include "glsceene.h"
#include "system.h"
#include "findpathdialog.h"
#include "faction.h"

const char* VSMapVersion = "1.3.5 from "__DATE__;

MainWindow::MainWindow() {
	lastDragX = -1;
	lastDragY = -1;
	starsData = new StarsTxt(this);
	// tree view of the main window (left)
	tree = new UniverseTree;
	QSizePolicy policy = tree->sizePolicy();
	policy.setHorizontalStretch(0);
	policy.setVerticalStretch(0);
	tree->setSizePolicy(policy);
	// messages view of the main window (bottom)
	edit = new QTextEdit;
	policy = edit->sizePolicy();
	policy.setHorizontalStretch(0);
	policy.setVerticalStretch(0);
	edit->setSizePolicy(policy);
	edit->setReadOnly(true);
	edit->setMaximumHeight(120);
	// OpenGL universe view of the main window
	sceene = new GLSceene();
	sceene->setMinimumSize(1, 1);
	sceene->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	policy = sceene->sizePolicy();
	policy.setHorizontalStretch(1);
	policy.setVerticalStretch(1);
	sceene->setSizePolicy(policy);

	// connect signals with slots
	connect(this, SIGNAL(displayNames(bool)), sceene, SLOT(setDisplayNames(bool)));
	connect(this, SIGNAL(displayJumps(bool)), sceene, SLOT(setDisplayJumps(bool)));
	connect(this, SIGNAL(displayJumplessSystems(bool)), sceene, SLOT(setDisplayJumplessSystems(bool)));
	connect(this, SIGNAL(displayFactionBubbles(bool)), sceene, SLOT(setDisplayFactionBubbles(bool)));
  connect(this, SIGNAL(showShiftChoices(bool)), sceene, SLOT(showShiftChoices(bool)));
	connect(this, SIGNAL(lightOn(bool)), sceene, SLOT(setLightsOn(bool)));
	connect(this, SIGNAL(printMsg(const QString &)), edit, SLOT(insertHtml(const QString &)));
	connect(tree, SIGNAL(printMsg(const QString &)), edit, SLOT(insertHtml(const QString &)));
	connect(sceene, SIGNAL(printMsg(const QString &)), edit, SLOT(insertHtml(const QString &)));
	connect(starsData, SIGNAL(printMsg(const QString &)), edit, SLOT(insertHtml(const QString &)));
  connect(starsData, SIGNAL(allTheFactions(QMap<QString, Faction *> *)), this, SLOT(setFactions(QMap<QString, Faction *> *)));
	connect(tree, SIGNAL(initProgress(int, int)), this, SLOT(initProgress(int, int)));
	connect(tree, SIGNAL(advanceProgress()), this, SLOT(advanceProgress()));
	connect(tree, SIGNAL(finishedLoading()), this, SLOT(finalizeLoading()));
	connect(tree, SIGNAL(finishedLoading()), sceene, SLOT(loadingFinished()));
	connect(tree, SIGNAL(foundUniverseBounds(float, float, float, float, float, float)), sceene, SLOT(initializeSceene(float, float, float, float, float, float)));
	connect(tree, SIGNAL(createStar(System *)), this, SLOT(filterSystem(System *)));
	connect(tree, SIGNAL(deleteStars()), sceene, SLOT(removeStars()));
	connect(tree, SIGNAL(createJump(System *, System*, Jump*)), sceene, SLOT(addJump(System *, System*, Jump*)));
	connect(tree, SIGNAL(itemSelectionChanged()), this, SLOT(processItemSelection()));
	connect(tree, SIGNAL(itemDoubleClicked(QTreeWidgetItem *, int)), sceene, SLOT(treeDoubleClicked(QTreeWidgetItem *, int)));
	connect(this, SIGNAL(plusPressed(float)), sceene, SLOT(zoom(float)));
	connect(this, SIGNAL(minusPressed(float)), sceene, SLOT(zoom(float)));
	connect(this, SIGNAL(leftPressed(float)), sceene, SLOT(turnLeft(float)));
	connect(this, SIGNAL(rightPressed(float)), sceene, SLOT(turnRight(float)));
	connect(this, SIGNAL(upPressed(float)), sceene, SLOT(turnUp(float)));
	connect(this, SIGNAL(downPressed(float)), sceene, SLOT(turnDown(float)));
	connect(this, SIGNAL(mouseDragged(float, float)), sceene, SLOT(turn(float, float)));
	connect(this, SIGNAL(mouseScrolled(float)), sceene, SLOT(zoom(float)));

	// layout the 3 main window components: tree view, 3d view, and message view
	hSplitter = new QSplitter(this);
	hSplitter->addWidget(tree);
	hSplitter->addWidget(sceene);
	hSplitter->setCollapsible(0, true);
	hSplitter->setCollapsible(1, false);
	hState.clear();
	hState.append(hSplitter->saveState());
	vSplitter = new QSplitter(Qt::Vertical, this);
	vSplitter->addWidget(hSplitter);
	vSplitter->addWidget(edit);
	vSplitter->setCollapsible(0, false);
	vSplitter->setCollapsible(1, true);
	vState.clear();
	vState.append(vSplitter->saveState());

	// send focus to OpenGL view
	sceene->setFocus();
	// apply layout to main window
	setCentralWidget(vSplitter);

    // !!!sceene has to be created bevor creating actions!!!
	createActions();
	createMenus();
	// create a progress bar within a status bar
	progress = new QProgressBar();
	statusBar()->insertPermanentWidget(0, progress);
	statusBar()->showMessage(tr("Ready"));

	// load saved configuration (the last opened vega strike directory
	config.loadConfig();
	setWindowTitle(tr("VSMap3D %1").arg(QString::fromLatin1(VSMapVersion)));

  restoreWindowProperties();
}

void MainWindow::processItemSelection() {
	sceene->setSelection(tree->selectedItems() );
}

void MainWindow::setFactions(QMap<QString, Faction *> *factions) {
  if (factions == 0) return;
  allFactions = factions;
  sceene->setFactions(factions);
  char key = QChar('A').toAscii(), maxKey = QChar('Z').toAscii();
  QList<QString> names = factions->keys();
  for (int i = 0, max = names.size(); i < max; i++) {
    QString name = names.at(i);
    Faction *faction = factions->value(name);

    QAction *act = new QAction(tr("%1").arg(name), this);
    QString shortCut = tr("Shift+%1").arg(key);
    faction->setShortCut(shortCut);
    act->setShortcut(shortCut);
    act->setCheckable(true);

    factionActions.insert(act, faction);

    connect(act, SIGNAL(toggled(bool)), this, SLOT(factionToggled()));

    viewFactionsMenu->addAction(act);

    key++;
    if (key > maxKey) break;
  }
}

void MainWindow::factionToggled() {
  QList<QAction *> actions = factionActions.keys();
  for (int i = 0, max = actions.size(); i < max; i++) {
    QAction *act = actions.at(i);
    Faction *faction = factionActions.value(act);
    bool active = act->isChecked();
    if (active && !factionSelection.contains(faction)) {
      factionSelection.insert(faction);
      sceene->toggleFaction(faction);
    } else if (!active && factionSelection.contains(faction)) {
      factionSelection.remove(faction);
      sceene->toggleFaction(faction);
    }
  }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event) {
  if (event->key() == Qt::Key_Shift) {
emit    showShiftChoices(false);
  }
  QWidget::keyReleaseEvent(event);
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
	switch (event->key()) {
	case Qt::Key_Plus:
emit 		plusPressed(10);
		break;
	case Qt::Key_Minus:
emit 		minusPressed(-10);
		break;
	case Qt::Key_Left:
emit 		leftPressed(-5);
		break;
	case Qt::Key_Right:
emit 		rightPressed(5);
		break;
	case Qt::Key_Up:
emit 		upPressed(-5);
		break;
	case Qt::Key_Down:
emit 		downPressed(5);
		break;
  case Qt::Key_Shift:
emit    showShiftChoices(true);
    break;
	default:
		QWidget::keyPressEvent(event);
	}
}

/**
 * Mouse wheel zooms in/out of view direction.
 **/
void MainWindow::wheelEvent(QWheelEvent *event) {
emit 	mouseScrolled(-event->delta());
	event->accept();
}

/**
 * RMB starts rotating eye position
 **/
void MainWindow::mousePressEvent(QMouseEvent *event) {
	if (event->button() == Qt::RightButton) {
		lastDragX = event->x();
		lastDragY = event->y();
	}
}

/**
 * While RMB is pressed rotate eye position.
 **/
void MainWindow::mouseMoveEvent(QMouseEvent *event) {
	if (event->buttons() & Qt::RightButton) {
		int dx = event->x() - lastDragX;
		int dy = event->y() - lastDragY;
emit 		mouseDragged(dx, dy);
		lastDragX = event->x();
		lastDragY = event->y();
	}
}

/**
 * End eye position rotation if RMB.
 * Initiate 3D picking code if LMB.
 **/
void MainWindow::mouseReleaseEvent(QMouseEvent *event) {
	if (event->button() == Qt::RightButton) {
		lastDragX = -1;
		lastDragY = -1;
	}
}

void MainWindow::finalizeLoading() {
	progress->reset();
	openAct->setEnabled(true);
	toggleJumpsAct->setEnabled(true);
	toggleNamesAct->setEnabled(true);
	findRouteAct->setEnabled(true);
	toggleJumplessSystemsAct->setEnabled(true);
  toggleFactionBubblesAct->setEnabled(true);
  viewFactionsMenu->setEnabled(true);
}

void MainWindow::initProgress(int min, int max) {
	progress->setRange(min, max);
	progress->reset();
}

void MainWindow::advanceProgress() {
	progress->setValue(progress->value()+1);
}

void MainWindow::open() {
	QString defaultDir = QDir::currentPath();
	// check, if there's a vega strike install dir cached in the configuration. if so, set that dir in the dialog.
	QVariant *var = config.property("VegaStrikeInstallDir");
	if (var && var->canConvert(QVariant::String) ) {
		QDir dir = QDir(var->toString());
		if (dir.exists() ) {
			defaultDir = var->toString();
		}
	}
	QString dirName = QFileDialog::getExistingDirectory(this,
			tr("Select Vega Strike Installation Directory"), defaultDir,
			QFileDialog::ShowDirsOnly);
	if (dirName.isEmpty())
		return;

	config.setProperty("VegaStrikeInstallDir", new QVariant(dirName));

  // load star and faction data (primarily the colors and textures/logos)
 	starsData->loadData(dirName, config);

	// get the universe file name from the configuration
	QString universeFile = QDir::convertSeparators("universe/milky_way.xml");
	var = config.property("UniverseFile");
	if (var && var->canConvert(QVariant::String) ) {
		QFile file(var->toString());
		if (file.exists() ) {
			universeFile = var->toString();
		}
  }

	if (universeFile.isEmpty()) {
    // use default universe file
    universeFile = QDir::convertSeparators("universe/milky_way.xml");
  }

	// disable open action while reading in a universe
	openAct->setEnabled(false);

	QString fileName = QDir::convertSeparators("%1/%2").arg(dirName).arg(universeFile);
	QFile file(fileName);
	if (!file.open(QFile::ReadOnly | QFile::Text)) {
		// maybe the default milky_way.xml doesn't apply -> check for wcuniverse.xml
		universeFile = QDir::convertSeparators("universe/wcuniverse.xml");
		fileName = QDir::convertSeparators("%1/%2").arg(dirName).arg(universeFile);
		file.setFileName(fileName);
		if (!file.open(QFile::ReadOnly | QFile::Text)) {
			// still unlucky -> show error message
			QMessageBox::warning(0, tr("Universe XML File"), tr("Cannot find file %1:\n%2. Make sure you chose the top level installation folder!")
			.arg(fileName)
			.arg(file.errorString()));
			openAct->setEnabled(true);
			return;
		}
	}

	// store universe file in the configuration
	config.setProperty("UniverseFile", new QVariant(universeFile));

	QStringList oldList(systemsWithJumps);
	systemsWithJumps.clear();

	if (tree->read(dirName, universeFile)) {
		setWindowTitle(tr("VSMap3D %1 - Displaying universe from %2")
		.arg(QString::fromLatin1(VSMapVersion)).arg(dirName));
	} else {
      QMessageBox::warning(0, tr("Universe XML File"), tr("Cannot read file %1!")
      .arg(fileName));
		openAct->setEnabled(true);
		systemsWithJumps = oldList;
	}
}

/*
    returns true, if width and height was restored, else false, even if position was restored
*/
bool MainWindow::restoreWindowProperties() {
  QVariant *var;

  var = config.property("WindowFullScreen");
  if (var && var->canConvert(QVariant::Bool) ) {
    if (var->toBool() && !isFullScreen()) {
      // default size
      resize(800, 600);
      toggleFullScreen();
      return true;
    }
  }

	var = config.property("WindowX");
	if (var && var->canConvert(QVariant::Int) ) {
        int x = var->toInt();
        var = config.property("WindowY");
        if (var && var->canConvert(QVariant::Int) ) {
            int y = var->toInt();
            move(x, y);
        }
	}

	var = config.property("WindowWidth");
	if (var && var->canConvert(QVariant::Int) ) {
        int width = var->toInt();
        var = config.property("WindowHeight");
        if (var && var->canConvert(QVariant::Int) ) {
            int height = var->toInt();
            resize(width, height);
            return true;
        }
	}

  // default size
  resize(800, 600);

  return false;
}

void MainWindow::resizeEvent ( QResizeEvent * event ) {
  if (event == 0) return; // unbelievable, but this really happens!!!
  QVariant *var = new QVariant(isFullScreen());
  config.setProperty("WindowFullScreen", var);
  // don't save fullscreen window size
  int w = window()->width();
  int h = window()->height();
  var = new QVariant(w);
  config.setProperty("WindowWidth", var);
  var = new QVariant(h);
  config.setProperty("WindowHeight", var);
}

void MainWindow::moveEvent ( QMoveEvent * event ) {
  if (event == 0) return; // unbelievable, but this really happens!!!
  QVariant *var = new QVariant(isFullScreen());
  config.setProperty("WindowFullScreen", var);
  // don't save fullscreen window position
  int x = window()->x();
  int y = window()->y();
  var = new QVariant(x);
  config.setProperty("WindowX", var);
  var = new QVariant(y);
  config.setProperty("WindowY", var);
}

void MainWindow::about() {
	QMessageBox::about(this, tr("About VSMap3D %1").arg(QString::fromLatin1(VSMapVersion)),
			tr("<b>VSMap3D</b> is an OpenGL universe explorer for Vega Strike"
				" universes.<br>"
				"So far it features route planning and system/sector selection.<br>"
				"In the upcoming releases I'm going to add the following features:<br>"
				"Dive into visited systems and explore its planets and stations and"
				" search for systems, planets, stations."));
}

void MainWindow::filterSystem(System *s) {
    if (s == 0) return;
    starsData->setupSystem(s);
	if (s->jumps()->size() > 0) {
		systemsWithJumps.append(s->name());
	}
	tree->addSystem(s);
	sceene->addStar(s);
}

void MainWindow::showFindRouteDialog() {
	systemsWithJumps.sort();
	FindPathDialog dialog(this, systemsWithJumps, allFactions, sceene->routeStart(), sceene->routeEnd(), sceene->routeAvoidsFactions());
	connect( &dialog, SIGNAL(findRoute(const QString &, const QString &, const QStringList &)), sceene, SLOT(setPath(const QString &, const QString &, const QStringList &)));
	dialog.exec();
	disconnect( &dialog, SIGNAL(findRoute(const QString &, const QString &, const QStringList &)), sceene, SLOT(setPath(const QString &, const QString &, const QStringList &)));
}

void MainWindow::toggleFullScreen() {
  if (!isVisible()) {
    show();
  }
  if (isFullScreen()) {
    showNormal();

    hSplitter->handle(0)->setVisible(true);
    hSplitter->handle(1)->setVisible(true);
    vSplitter->handle(0)->setVisible(true);
    vSplitter->handle(1)->setVisible(true);
    hSplitter->restoreState(hState);
    vSplitter->restoreState(vState);
  } else {
    hState.clear();
    hState.append(hSplitter->saveState());
    vState.clear();
    vState.append(vSplitter->saveState());

    QList<int> hSizes;
    hSizes << 0 << tree->width() + sceene->width();
    hSplitter->setSizes(hSizes);
    hSplitter->setHandleWidth(1);
    hSplitter->handle(0)->setVisible(false);
    hSplitter->handle(1)->setVisible(false);

    QList<int> vSizes;
    vSizes << sceene->height() + edit->height() << 0;
    vSplitter->setSizes(vSizes);
    vSplitter->setHandleWidth(1);
    vSplitter->handle(0)->setVisible(false);
    vSplitter->handle(1)->setVisible(false);

    showFullScreen();
  }
  QVariant *var = new QVariant(isFullScreen());
  config.setProperty("WindowFullScreen", var);
}

void MainWindow::createActions() {
	openAct = new QAction(tr("&Open..."), this);
	openAct->setShortcut(tr("Ctrl+O"));
	connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

	exitAct = new QAction(tr("E&xit"), this);
	exitAct->setShortcut(tr("Ctrl+Q"));
	connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

	findRouteAct = new QAction(tr("Find &Route"), this);
	findRouteAct->setShortcut(tr("Ctrl+R"));
	connect(findRouteAct, SIGNAL(triggered()), this, SLOT(showFindRouteDialog()));

	toggleFullScreenAct = new QAction(tr("Toggle &FullScreen"), this);
	toggleFullScreenAct->setShortcut(tr("F11"));
	toggleFullScreenAct->setCheckable(true);
	connect(toggleFullScreenAct, SIGNAL(triggered()), this, SLOT(toggleFullScreen()));

	toggleNamesAct = new QAction(tr("Toggle &Names"), this);
	toggleNamesAct->setShortcut(tr("Ctrl+N"));
	toggleNamesAct->setCheckable(true);
	connect(toggleNamesAct, SIGNAL(toggled(bool)), this, SIGNAL(displayNames(bool)));

	toggleJumpsAct = new QAction(tr("Toggle &Jumps"), this);
	toggleJumpsAct->setShortcut(tr("Ctrl+J"));
	toggleJumpsAct->setCheckable(true);
	connect(toggleJumpsAct, SIGNAL(toggled(bool)), this, SIGNAL(displayJumps(bool)));

	toggleFactionBubblesAct = new QAction(tr("Toggle F&actions"), this);
	toggleFactionBubblesAct->setShortcut(tr("Ctrl+F"));
	toggleFactionBubblesAct->setCheckable(true);
	connect(toggleFactionBubblesAct, SIGNAL(toggled(bool)), this, SIGNAL(displayFactionBubbles(bool)));

	toggleJumplessSystemsAct = new QAction(tr("Toggle J&umpless Systems"), this);
	toggleJumplessSystemsAct->setShortcut(tr("Ctrl+A"));
	toggleJumplessSystemsAct->setCheckable(true);
	connect(toggleJumplessSystemsAct, SIGNAL(toggled(bool)), this, SIGNAL(displayJumplessSystems(bool)));

	toggleJumpsAct->setEnabled(false);
	toggleNamesAct->setEnabled(false);
	findRouteAct->setEnabled(false);
	toggleJumplessSystemsAct->setEnabled(false);
  toggleFactionBubblesAct->setEnabled(false);

	toggleLightsAct = new QAction(tr("Toggle &Lights"), this);
	toggleLightsAct->setShortcut(tr("Ctrl+L"));
	toggleLightsAct->setCheckable(true);
	toggleLightsAct->setChecked(sceene->isLightsOn());

	connect(toggleLightsAct, SIGNAL(toggled(bool)), this, SIGNAL(lightOn(bool)));

	aboutAct = new QAction(tr("&About"), this);
	connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

	aboutQtAct = new QAction(tr("About &Qt"), this);
	connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void MainWindow::createMenus() {
	fileMenu = menuBar()->addMenu(tr("&File"));
	fileMenu->addAction(openAct);
	fileMenu->addAction(exitAct);

	viewMenu = menuBar()->addMenu(tr("&View"));

 	bubbleSpinner = new QDoubleSpinBox();
 	bubbleSpinner->setRange(1.0, 101.0);
 	bubbleSpinner->setDecimals(0);
 	bubbleSpinner->setSingleStep(5);
 	bubbleSpinner->setValue(sceene->bubbleFactor());
 	QLabel *label = new QLabel(tr("Bubble exaggeration"));

 	QHBoxLayout *layout = new QHBoxLayout;
 	layout->addSpacing(18);
 	layout->addWidget(label, 1);
 	layout->addWidget(bubbleSpinner);
 	layout->addSpacing(45);
 	QWidget *bubbleEntry = new QWidget();
 	bubbleEntry->setToolTip(tr("Size of faction bubble. Changing this value takes a few seconds due to updating the display lists!"));
 	bubbleEntry->setLayout(layout);

 	bubbleAct = new QWidgetAction(this);
 	bubbleAct->setDefaultWidget(bubbleEntry);
 	connect(bubbleSpinner, SIGNAL(valueChanged(double)), sceene, SLOT(setBubbleFactor(double)));

	viewMenu->addAction(toggleFullScreenAct);
	viewMenu->addSeparator();
	viewMenu->addAction(findRouteAct);
	viewMenu->addSeparator();
	viewMenu->addAction(toggleNamesAct);
	viewMenu->addAction(toggleJumpsAct);
	viewMenu->addAction(toggleFactionBubblesAct);
	viewMenu->addAction(bubbleAct);
  viewFactionsMenu = viewMenu->addMenu(tr("Fa&ctions"));
  viewFactionsMenu->setEnabled(false);

	viewMenu->addAction(toggleJumplessSystemsAct);
	viewMenu->addSeparator();
	viewMenu->addAction(toggleLightsAct);

	menuBar()->addSeparator();

	helpMenu = menuBar()->addMenu(tr("&Help"));
	helpMenu->addAction(aboutAct);
	helpMenu->addAction(aboutQtAct);
}

