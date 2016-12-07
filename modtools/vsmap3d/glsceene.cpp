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
#include <QtOpenGL>
#include <QList>
#include <QHash>
#include <QString>

#include <math.h>
#include <stdlib.h>

#include "glsceene.h"
#include "faction.h"

#ifndef GL_MULTISAMPLE
#define GL_MULTISAMPLE  0x809D
#endif

const float piover180 = 0.0174532925f;
const float pi = 3.1415926536f;
const float maxR = 150000*1.490660009e-12*5e+5f;

GLSceene::GLSceene(QWidget* parent) :
QGLWidget(parent) {
    factionsMap = 0;

    setAutoFillBackground(false);

    starNamesFont.setFamily("Courier");
    starNamesFont.setPointSize(12);
    sceeneBackground = QColor::fromRgb(0, 0, 0, 0);

    memset(stats, 0, sizeof(stats));
    displayNames = false;
    displayJumps = false;
    displayJumplessSystems = false;
    shiftChoices = false;
    lightsOn = true;
    clipSize[0] = -500.0f;
    clipSize[1] = 500.0f;
    clipSize[2] = -500.0f;
    clipSize[3] = 500.0f;
    clipSize[4] = -500.0f;
    clipSize[5] = 500.0f;
    eyepos[0] = 0.0f;
    eyepos[1] = 0.0f;
    eyepos[2] = 0.0f;
    eyerot[0] = 0.0f;
    eyerot[1] = 0.0f;
    eyerot[2] = 0.0f;

    eyetargetpos[0] = 0.0f;
    eyetargetpos[1] = 0.0f;
    eyetargetpos[2] = 0.0f;
    flightPath[0] = 0.0f;
    flightPath[1] = 0.0f;
    flightPath[3] = 0.0f;
    currentStep = 0;
    exaggeration = 20.0f;

    eyeDestinationChanged = false;
    flyTimer = new QTimer( this );
    flyTimer->setSingleShot( false);
    flyTimer->setInterval( 40);
    zoomSpeed = 0.1;
    connect(flyTimer, SIGNAL(timeout()), this, SLOT(flyToTarget()));
}

GLSceene::~GLSceene() {
    makeCurrent();
    removeStars();
}

void GLSceene::paintGL() { // Here's Where We Do All The Drawing
    makeCurrent();

    glMatrixMode(GL_MODELVIEW);

    if (isLightsOn())
        glEnable(GL_LIGHTING);
    else
        glDisable(GL_LIGHTING);

    glPushMatrix();

    // clear screen and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    int max = systems.size();
    for (int i=0; i<max; i++) {
        System *sys = systems.at(i);
        if (!displayJumplessSystems && sys->jumps()->size()==0)
            continue;
        GLuint glSystem = sys->glSystem();
        GLuint glFactionBubble = sys->glFactionBubble();
        QList<Jump *> *glJumps = sys->glJumps(); // jumps to display if displayJumps is set
        QList<Jump *> *glSelJumps = sys->jumps(); // jumps to display if system is selected
        Jump *pathTo = sys->pathTo();
        Jump *pathFrom = sys->pathFrom();
        bool activeSelection = false; // true, if there is an active selection
        bool systemSelected = false; // true, if system is selected
        bool sectorSelected = false; // true, if system's sector is selected
        bool systemIsPartOfPath = false; // true, if system's path is set indicating, it belongs to a path of jumps
        // check if the system or the system's sector is selected
        systemSelected = (treeSystemSelection.contains(sys->name()) );
        sectorSelected = (treeSectorSelection.contains(sys->sector()) );
        // now check, if the current system is part of a path to display
        systemIsPartOfPath = (pathTo != 0 || pathFrom != 0);
        activeSelection = (pathList.size() > 0) || (treeSystemSelection.size() > 0) || (treeSectorSelection.size() > 0);
        // if system or sector is selected, list all of it's jumps
        int numJumps = glJumps->size();
        if (systemSelected || sectorSelected || systemIsPartOfPath) {
            numJumps = glSelJumps->size();
        }
        // prepare matrix for drawing
        glLoadIdentity();
        glRotatef(eyerot[0], 1.0f, 0.0f, 0.0f);
        glRotatef(eyerot[1], 0.0f, 1.0f, 0.0f);
        glRotatef(eyerot[2], 0.0f, 0.0f, 1.0f);
        glTranslatef(-eyepos[0], -eyepos[1], -eyepos[2]);
        // draw jumps if neccessary
        if ( (displayJumps && numJumps > 0) || systemSelected || sectorSelected
                || systemIsPartOfPath) {
            for (int j=0; j<numJumps; j++) {
                glPushMatrix();
                // may use different color for each sector of for a selected path
                QColor c = QColor::fromRgbF(0.161f, 0.478f, 0.702f, 1.0f); // regular jump color
                if (displayJumps) { // display all jumps in the universe
                    Jump *selJump = 0;
                    if ( !systemIsPartOfPath && !systemSelected
                            && !sectorSelected) {
                        selJump = glJumps->at(j);
                    } else {
                        selJump = glSelJumps->at(j);
                    }
                    // if a sector is selected, ignore all jumps that go into that sector, as
                    // all sectors' system are selected and outbound jumps are rendered anyways
                    if ( !treeSectorSelection.contains(sys->sector())
                            && treeSectorSelection.contains(selJump->dSector()) ) {
                        glPopMatrix();
                        continue;
                    }
                    GLuint listID = selJump->glList(); // get display list from the regular jump list
                    if (sectorSelected && selJump->destination() == 0) {
                        emit 						printMsg(tr("Warning! destination system pointer of jump to %s is not set!<br>")
                                            .arg(selJump->dSystem()));
                        glPopMatrix();
                        continue;
                    }
                    if (sectorSelected && sys->sector()
                            != selJump->destination()->sector() ) { // jump leaves system
                        c = QColor::fromRgbF(0.714f, 0.267f, 0.337f, 1.0f); // color for jump leaving the system
                    }
                    if (systemIsPartOfPath) { // system belongs to a path
                        if (pathFrom != 0) { // system is not first part of path
                            if (pathFrom->glList() == listID) { // current jump is part of path
                                glPopMatrix();
                                continue; // ignore this jump, as it will be rendered from the previous system in the path
                            }
                        }
                        if (pathTo != 0) { // system is not last part of path
                            if (pathTo->glList() == listID) { // current jump is part of path
                                c = QColor::fromRgbF(0.0f, 1.0f, 0.0f, 1.0f); // color for path
                                listID = pathTo->glList(); // get display list of that path
                            }
                        }
                    }
                    qglColor(c); // set color for display list
                    if (listID==3080192 || listID==0) { // warn for invalid list IDs
                        emit 						printMsg(tr("Warning! gl list id of jump from %1 to %2 is %3!<br>")
                                            .arg(sys->name()).arg(glJumps->at(j)->dSystem()).arg(listID));
                    } else { // display list is valid
                        glCallList(listID);
                    }
                } else { // display all jumps of the selected system or sector
                    Jump *selJump = glSelJumps->at(j);
                    GLuint listID = selJump->glList(); // get display list from the regular jump list
                    if (sectorSelected && selJump->destination() == 0) {
                        emit 						printMsg(tr("Warning! destination system pointer of jump to %s is not set!<br>")
                                            .arg(selJump->dSystem()));
                        glPopMatrix();
                        continue;
                    }
                    if (sectorSelected && sys->sector()
                            != selJump->destination()->sector() ) { // jump leaves system
                        c = QColor::fromRgbF(0.714f, 0.267f, 0.337f, 1.0f); // color for jump leaving the system
                    }
                    if (systemIsPartOfPath) { // system belongs to a path
                        if (pathFrom != 0) { // system is not first part of path
                            if (pathFrom->glList() == listID) { // current jump is part of path
                                glPopMatrix();
                                continue; // ignore this jump, as it will be rendered from the previous system in the path
                            }
                        }
                        if (pathTo != 0) { // system is not last part of path
                            if (pathTo->glList() == listID) { // current jump is part of path
                                c = QColor::fromRgbF(0.0f, 1.0f, 0.0f, 1.0f); // color for jump of path
                                listID = pathTo->glList(); // get display list of that path
                            }
                        }
                    }
                    qglColor(c); // set color for display list
                    if (listID==3080192 || listID==0) { // warn for invalid list IDs
                        emit 						printMsg(tr("Warning! gl list id of jump from %1 to %2 is %3!<br>")
                                            .arg(sys->name()).arg(glJumps->at(j)->dSystem()).arg(listID));
                    } else { // display list is valid
                        glCallList(listID);
                    }
                }
                glPopMatrix();
            }
        }
        if ((displayNames && !activeSelection) || systemSelected || sectorSelected
                || systemIsPartOfPath) {
            bool isSelectedFaction = sys->systemFaction() != 0 && factionSelection.contains(sys->systemFaction());
            QColor c = QColor::fromRgbF(0.2f, 0.2f, 1.0f, 1.0f); // regular name color
            glPushMatrix();
            // make use of faction color from factions.xml
            if (systemIsPartOfPath) {
                c = QColor::fromRgbF(0.0f, 1.0f, 0.0f, 1.0f); // color for system of path
            }
            if (isSelectedFaction) {
                c = sys->systemFaction()->color();
            }
            qglColor(c); // regular text color

            float offset = sys->sunR()*500000.0f;
            // if there are faction selections, only render system name if system's faction is selected
            if (factionSelection.isEmpty() || isSelectedFaction) {
                renderText(sys->x()+1.0001*offset, sys->y()-0.2*offset, sys->z(), sys->name(), starNamesFont);
            }

            glPopMatrix();
            // if a system is selected display the names of the reachable systems
            if (systemSelected || sectorSelected || systemIsPartOfPath) {
                int nmax = sys->jumps()->size();
                for (int ni=0; ni<nmax; ni++) {
                    System *neighbour = sys->jumps()->at(ni)->destination();
                    isSelectedFaction = neighbour->systemFaction() != 0 && factionSelection.contains(neighbour->systemFaction());
                    if (neighbour == 0)
                        continue;
                    if (neighbour->pathTo() != 0 || neighbour->pathFrom() != 0)
                        continue;
                    // if a sector is selected, ignore all neigbours that belong to that sector, as
                    // all sectors' system are selected and they are rendered anyways
                    if (treeSectorSelection.contains(sys->sector())
                            && sys->sector() == neighbour->sector() ) {
                        continue;
                    }
                    if (systemSelected || sectorSelected) {
                        c = QColor::fromRgbF(0.714f, 0.267f, 0.337f, 1.0f); // color of neighbour
                    } else {
                        c = QColor::fromRgbF(0.2f, 0.2f, 1.0f, 1.0f);
                    }
                    if (isSelectedFaction) {
                        c = neighbour->systemFaction()->color();
                    }
                    glPushMatrix();
                    qglColor(c); // regular text color
                    offset = neighbour->sunR()*500000.0f;
                    // if there are faction selections, only render system name if system's faction is selected
                    if (factionSelection.isEmpty() || isSelectedFaction) {
                        renderText(neighbour->x()-0.9*offset, neighbour->y()-0.6*offset,neighbour->z(), neighbour->name(), starNamesFont);
                    }
                    glPopMatrix();
                }
            }
        }
        glPushMatrix();
        // if system was visited make use of star's color from it's system's xml file
        qglColor(sys->starColor());
        glCallList(glSystem);
        glPopMatrix();
        // draw faction bubbles around systems indicating ownership
        if (systemSelected || sectorSelected
                || systemIsPartOfPath || factionSelection.contains(sys->systemFaction())) {
            glPushMatrix();
            glCallList(glFactionBubble);
            glPopMatrix();
            // also display neighboring faction bubbles
            if (systemSelected || sectorSelected || systemIsPartOfPath) {
                int nmax = sys->jumps()->size();
                for (int ni=0; ni<nmax; ni++) {
                    System *neighbour = sys->jumps()->at(ni)->destination();
                    if (neighbour == 0)
                        continue;
                    if (neighbour->pathTo() != 0 || neighbour->pathFrom() != 0)
                        continue;
                    if (treeSectorSelection.contains(sys->sector())
                            && sys->sector() == neighbour->sector() ) {
                        continue;
                    }
                    glPushMatrix();
                    glCallList(neighbour->glFactionBubble());
                    glPopMatrix();
                }
            }
        }
    }

    // render positioning information

    glPopMatrix();

    // overpaint with QPainter
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    overpaint(&painter);
    painter.end();
}

void GLSceene::initializeGL() {
    makeCurrent();

    qglClearColor(sceeneBackground);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
    glClearDepth(1.0f); // Depth Buffer Setup
    glDepthFunc(GL_LEQUAL); // The Type Of Depth Testing (Less Or Equal)
    glEnable(GL_DEPTH_TEST); // Enable Depth Testing
    glShadeModel(GL_SMOOTH); // Select Smooth Shading  glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE); // don't need Z testing for convex objects
    glEnable(GL_MULTISAMPLE);

    glEnable(GL_COLOR_MATERIAL);
    glDisable(GL_TEXTURE_2D);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

// LIGHT
    GLfloat LightAmbient[]= { 0.25f, 0.25f, 0.25f, 1.0f };
    GLfloat LightDiffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat LightSpecular[]= { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat LightPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    GLfloat LightSpotDirection[] = {0.0f, 0.0f, 1.0f};
    GLfloat LightSpotCutOff = 180.0f;
    GLfloat LightSpotExponent = 0.0f;
    GLfloat LightAttenuationConst = 1.0f;
    GLfloat LightAttenuationLinear = 0.0f;
    GLfloat LightAttenuationQuad = 0.0f;

    glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, LightSpecular);
    glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, LightSpotDirection);
    glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, LightSpotCutOff);
    glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, LightSpotExponent);
    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, LightAttenuationConst);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, LightAttenuationLinear);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, LightAttenuationQuad);
    glEnable(GL_LIGHT0);
    if (isLightsOn())
        glEnable(GL_LIGHTING);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void GLSceene::resizeGL(int w, int h) {
    if (h == 0) {// Prevent A Divide By Zero
        h = 1; // Making Height Equal One
    }
    glViewport(0, 0, (GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective( 45.0f, (GLfloat)w/(GLfloat)h, 0.1f, 2*maxClip ); // Calculate The Aspect Ratio Of The Window
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    updateGL();
}

void GLSceene::setPath(const QString &startSystemName,
                       const QString &destinationSystemName, const QStringList &factions) {
    avoidedFactions = factions;
    // first rest any star that is currently in a list
    int count = pathList.size();
    for (int c=0; c<count; c++) {
        System *s = pathList.at(c);
        s->setPath(); // defaults to  setPath(0, 0) which resets the path
        s->setCosts(); // defaults to  setCosts(0.0, 0.0) which resets the costs
    }
    pathList.clear();
    if (startSystemName.isEmpty() || destinationSystemName.isEmpty()
            || startSystemName == destinationSystemName)
        return;
    // lists for A* algorithm
    QList<System *> toDoQueue;
    QList<System *> visitedList;
    QList<System *> modifiedList;
    System *startSystem = 0, *destinationSystem = 0;
    if (systemForSystemName.contains(startSystemName)
            && systemForSystemName.contains(destinationSystemName)) {
        startSystem = systemForSystemName.value(startSystemName);
        destinationSystem = systemForSystemName.value(destinationSystemName);
    } else {
        emit 		printMsg(tr("Path finding aborted since either start or destination system is unknown to GLSceene!<br>"));
        return;
    }
    if (factions.contains(startSystem->faction()) || factions.contains(destinationSystem->faction())) {
        emit 		printMsg(tr("Path finding aborted since either start or destination system's faction has to be avoided!<br>"));
        return;
    }
    // the A* algorithm
    // coordinates for distance heuristic
    float dsx = destinationSystem->x(), dsy = destinationSystem->y(), dsz =
                    destinationSystem->z();
    // while searching the shortest path, systems may get its pathFrom set
    // which needs to be undone in case of failure at the end
    bool failed = true;
    toDoQueue.append(startSystem); // add start system to to do list
    while ( !toDoQueue.isEmpty() ) {
        System *currentSystem = toDoQueue.takeFirst();
        if (visitedList.contains(currentSystem) ) { // a system must never be checked twice
            emit 			printMsg(tr("There is no path to from %1 to %2!<br>")
                             .arg(startSystem->name()).arg(destinationSystem->name()));
            break;
        }
        // add system to visited list
        visitedList.append(currentSystem);
        if (currentSystem == destinationSystem) {
            // reconstructShortestPath
            System *node = destinationSystem;
            if (node != startSystem) {
                while ( true) {
                    // prepend to path list
                    pathList.prepend(node);
                    // if start of path reached, stop reconstructing path
                    if (node == startSystem)
                        break;
                    // remove from list of modified systems
                    int index = modifiedList.indexOf(node);
                    if ( index < 0 || index > modifiedList.size()) {
                        emit printMsg(tr("ERROR at index (%2) of modifiedList for system %1!<br>")
                                      .arg(node->name()).arg(index));
                        break;
                    }
                    modifiedList.removeAt(index);
                    if (node->pathFrom() == 0) {
                        emit 						printMsg(tr("ERROR at pathFrom pointer!<br>"));
                        break;
                    }
                    // find previous node
                    System *prevSystem = node->pathFrom()->destination();
                    System *nextSystem = node;
                    if (prevSystem != 0) {
                        node = prevSystem;
                    } else {
                        node = systemForSystemName.value(node->pathFrom()->dSystem());
                    }
                    if (node == 0) {
                        emit 						printMsg(tr("Error! Couldn't reconstruct system pointer for system that led to %1!<br>")
                                            .arg(nextSystem->name()));
                        break;
                    }
                    // set forward pointer of path in the systems
                    Jump *jumpFrom = node->pathFrom();
                    Jump *jumpTo = 0;
                    count = node->jumps()->size();
                    for (int c=0; c<count; c++) {
                        Jump *jump = node->jumps()->at(c);
                        if (jump->dSystem() == nextSystem->name()) {
                            jumpTo = jump;
                        }
                    }
                    node->setPath(jumpTo, jumpFrom);
                }
            }
            // now reset all systems in list of modified systems that are not part of pathList
            count = modifiedList.size();
            for (int c=0; c<count; c++) {
                System *s = modifiedList.at(c);
                s->setPath(); // defaults to  setPath(0, 0) which resets the path
                s->setCosts(); // defaults to  setCosts(0.0, 0.0) which resets the costs
            }
            failed = false;
            break;
        } else {
            // find all neighbouring systems
            QList<System *> successors;
            count = currentSystem->jumps()->size();
            for (int c=0; c<count; c++) {
                successors.append(currentSystem->jumps()->at(c)->destination() );
            }
            count = successors.size();
            for (int c=0; c<count; c++) {
                System *s = successors.at(c);
                // ignore successors, that are already in the to do list and closer to destination or visited list
                // and ignore successors if their faction is to be avoided
                if (visitedList.contains(s) || factions.contains(s->faction()) ) {
                    continue;
                }
                // find jump from s to current system out of s' jumps
                int jcount = s->jumps()->size();
                float f = 0.0, g = 0.0, h = 0.0;
                bool ignoreSuccessor = false;
                for (int jc=0; jc<jcount; jc++) {
                    Jump *jump = s->jumps()->at(jc);
                    // set current system as pathFrom in successor
                    if (jump->destination() == currentSystem) {
                        // calculate f-costs
                        g = jump->distance() + currentSystem->gCosts();
                        float dx = dsx - s->x(), dy = dsy - s->y(), dz = dsz - s->z();
                        h = sqrt(dx*dx + dy*dy + dz*dz);
                        f = g + h;
                        if (toDoQueue.contains(s) ) {
                            if (s->fCosts() < f) {
                                ignoreSuccessor = true;
                                break;
                            } else {
                                toDoQueue.removeAt(toDoQueue.indexOf(s) );
                            }
                        }
                        s->setPath(0, jump);
                        s->setCosts(f, g);
                        if ( !modifiedList.contains(s) )
                            modifiedList.append(s);
                        break;
                    }
                }
                if (ignoreSuccessor)
                    continue;
                // insert s into to do list sorted by f costs if not already present
                int todocount = toDoQueue.size();
                bool inserted = false;
                for (int pos=0; pos<todocount; pos++) {
                    // if estimated costs are smaller than current pos in to do queue, insert there
                    if (toDoQueue.at(pos)->fCosts() > f) {
                        toDoQueue.insert(pos, s);
                        inserted = true;
                        break;
                    }
                }
                if ( !inserted)
                    toDoQueue.append(s);
            }
        }
    }
    // reset all systems in modified list, if no path was found
    if (failed) {
        count = modifiedList.size();
        for (int c=0; c<count; c++) {
            System *s = modifiedList.at(c);
            s->setPath(); // defaults to  setPath(0, 0) which resets the path
            s->setCosts(); // defaults to  setCosts(0.0, 0.0) which resets the costs
        }
    }
    emit 	printMsg(tr("Path search finished!<br>"));
    count = pathList.size();
    for (int c=0; c<count; c++) {
        System *s = pathList.at(c);
        QString toName = "-";
        QString fromName = "-";
        if (s->pathTo() != 0)
            toName = s->pathTo()->dSystem();
        if (s->pathFrom() != 0)
            fromName = s->pathFrom()->dSystem();
        emit 		printMsg(tr("pathList[%1] is %2 (to: %3, from: %4)<br>")
                        .arg(c).arg(s->name()).arg(toName).arg(fromName));
    }
    updateGL();
}

void GLSceene::addStar(System *star) {
    if (star == 0) return;
    float x = star->x(), y = star->y(), z = star->z(), r = star->sunR();
    QString name = star->name();
    makeCurrent();
    // the star
    GLuint list = glGenLists(1);
    glNewList(list, GL_COMPILE);
    glPushMatrix();

    glTranslatef(x, y, z);
    GLUquadricObj *quadric = gluNewQuadric();
    gluSphere(quadric, r*500000.0f, 32, 32);

    glPopMatrix();
    glEndList();
    star->setGLSystem(list);

    // the faction bubble
    makeFactionBubble(star, bubbleFactor());

    // the name label
    //get pixmaps for each char of name string
    //for each pixmap call bindTexture; Qt caches these, so it's just fine
    //sum width of pixmaps total width of quad
    //hight of all font char pixmaps should be the same
    //create quad
    //go through textures and bind them to the quad from L2R

    stats[0]++;
    stats[1]++;
    int iR = (int)(r/1.490660009e-12);
    stats[4] = (stats[4]==0)?iR:stats[4];
    stats[4] = (iR<stats[4] && iR > 0)?iR:stats[4];
    stats[5] = (iR>stats[5] && iR > 0)?iR:stats[5];
    if (star->jumps()->size() > 0)
        stats[3]++;
    systems.append(star);
    if (!systemForSystemName.contains(name)) {
        systemForSystemName.insert(name, star);
    }
}

void GLSceene::makeFactionBubble(System *star, float exaggerate) {
    if (star == 0) return;
    float x = star->x(), y = star->y(), z = star->z();
    QColor col(0, 0, 0, 0);
    Faction *fac = star->systemFaction();
    if (fac != 0) {
        col.setRgb(fac->color().rgb());
        col.setAlpha(128);
    }
    if (star->sector().compare("Sol") == 0 || star->sector().compare("Vega") == 0) {
        exaggerate /= 5.0f;
    }
    exaggerate = (exaggerate < 1.0f) ? 1.0f : exaggerate;
    GLuint list = glGenLists(1);
    glNewList(list, GL_COMPILE);
    glPushMatrix();
    glTranslatef(x, y, z);
    qglColor(col);
    GLUquadricObj *quadric = gluNewQuadric();
    gluSphere(quadric, maxR*exaggerate, 32, 32);
    glPopMatrix();
    glEndList();
    star->setGLFactionBubble(list);
}

void GLSceene::makeFactionBubble(System *star, float exaggerate, bool replaceDisplayList) {
    GLuint oldBubble = star->glFactionBubble();
    makeFactionBubble(star, exaggerate);
    // delete display lists
    if (replaceDisplayList) {
        glDeleteLists(oldBubble, 1);
    }
}

void GLSceene::setBubbleFactor(double d) {
    float f = (float)d;
    makeCurrent();
    exaggeration = f;
    int max = systems.size();
    for (int i=0; i<max; i++) {
        System *sys = systems.at(i);
        makeFactionBubble(sys, bubbleFactor(), true); // true deletes old display list
    }
    updateGL();
}

float GLSceene::bubbleFactor() {
    if (exaggeration == 0.0f) {
        exaggeration = 20.0f;
    } else if (exaggeration < 1.0f) {
        exaggeration = 1.0f;
    }
    return exaggeration;
}

void GLSceene::removeStars() {
    int max = systems.size();
    for (int i=0; i<max; i++) {
        System *sys = systems.at(i);
        // delete display lists
        glDeleteLists(sys->glSystem(), 1);
        glDeleteLists(sys->glFactionBubble(), 1);
        QList<Jump *> *glJumps = sys->glJumps();
        int num = glJumps->size();
        for (int j=0; j<num; j++) {
            glDeleteLists(glJumps->at(j)->glList(), 1);
        }
        // delete objets
        QList<Jump *> *jumps = sys->jumps();
        num = jumps->size();
        for (int j=0; j<num; j++) {
            delete jumps->at(j);
        }
        delete sys;
    }
    // reset state
    memset(stats, 0, sizeof(stats));
    displayNames = false;
    displayJumps = false;
    displayJumplessSystems = false;
    lightsOn = true;
    clipSize[0] = -500.0f;
    clipSize[1] = 500.0f;
    clipSize[2] = -500.0f;
    clipSize[3] = 500.0f;
    clipSize[4] = -500.0f;
    clipSize[5] = 500.0f;
    eyepos[0] = 0.0f;
    eyepos[1] = 0.0f;
    eyepos[2] = 0.0f;
    eyerot[0] = 0.0f;
    eyerot[1] = 0.0f;
    eyerot[2] = 0.0f;
    eyetargetpos[0] = 0.0f;
    eyetargetpos[1] = 0.0f;
    eyetargetpos[2] = 0.0f;
    flightPath[0] = 0.0f;
    flightPath[1] = 0.0f;
    flightPath[3] = 0.0f;
    currentStep = 0;
    treeSystemSelection.clear();
    treeSectorSelection.clear();
    eyeDestinationChanged = false;
    // finally, clear lists
    systems.clear();
    systemForSystemName.clear();
    pathList.clear();
}

void GLSceene::addJump(System *src, System *dest, Jump *jump) {
    float sx = src->x(), sy = src->y(), sz = src->z();
    float dx = dest->x(), dy = dest->y(), dz = dest->z();
    makeCurrent();
    GLuint list = glGenLists(1);
    glNewList(list, GL_COMPILE);
    glTranslatef(sx, sy, sz);
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(dx-sx, dy-sy, dz-sz);
    glEnd();
    glEndList();
    jump->setGLList(list);
    src->addGLJump(jump);
    // now make sure that for the case of system selection the jump from dest to src has the same gl list
    int max = dest->jumps()->size();
    for (int i=0; i<max; i++) {
        Jump *revjump = dest->jumps()->at(i);
        if (revjump->dSystem() == src->name()) {
            revjump->setGLList(list);
            revjump->setDestination(src, jump->distance());
            break;
        }
    }
    stats[2]++;
}

void GLSceene::initializeSceene(float minx, float maxx, float miny, float maxy,
                                float minz, float maxz) {
    clipSize[0] = 2*minx;
    clipSize[1] = 2*maxx;
    clipSize[2] = 2*miny;
    clipSize[3] = 2*maxy;
    clipSize[4] = 2*minz;
    clipSize[5] = 2*maxz;
    // figure out biggest extention
    float dx = clipSize[1]-clipSize[0];
    float dy = clipSize[3]-clipSize[2];
    float dz = clipSize[5]-clipSize[4];
    maxClip = (dx>dy) ? dx : dy;
    maxClip = (maxClip>dz) ? maxClip : dz;

    int max = systems.size();
    float minD = maxClip * maxClip + 5.0f, maxD = 0.0f;
    System *minSystem = 0, *maxSystem = 0;
    for (int i=0; i<max; i++) {
        System *sys = systems.at(i);
        float dx = sys->x()-eyepos[0], dy = sys->y()-eyepos[1], dz = sys->z()-eyepos[2];
        float r = dx*dx + dy*dy + dz*dz;
        if (r < minD) {
            minD = r;
            minSystem = sys;
        }
        if (r > maxD) {
            maxD = r;
            maxSystem = sys;
        }
    }
    QString closeSys = tr("%1").arg((minSystem != 0) ? minSystem->name() : "");
    QString farSys = tr("%1").arg((maxSystem != 0) ? maxSystem->name() : "");
    emit 	printMsg(tr("Closest star            : %1<br>").arg(closeSys));
    emit 	printMsg(tr("Furthest star           : %1<br>").arg(farSys));

    emit 	printMsg(tr("Number of system objects: %1<br>").arg(stats[0]));
    emit 	printMsg(tr("Smallest star radius    : %1<br>").arg(stats[4]));
    emit 	printMsg(tr("Biggest star radius     : %1<br>").arg(stats[5]));
    emit 	printMsg(tr("Number of reachable system objects: %1<br>").arg(stats[3]));
    emit 	printMsg(tr("Number of name objects  : %1<br>").arg(stats[1]));
    emit 	printMsg(tr("Number of jump objects  : %1<br>").arg(stats[2]));
    updateGL();
}

void GLSceene::flyToTarget() {
    float steps = 5.0;
    if (eyeDestinationChanged) {
        // the vector between the current pos and the target pos is set only when the target pos was changed
        flightPath[0] = (eyetargetpos[0] - eyepos[0] ) / steps;
        flightPath[1] = (eyetargetpos[1] - eyepos[1] ) / steps;
        flightPath[2] = (eyetargetpos[2] - eyepos[2] ) / steps;
        eyeDestinationChanged = false;
        currentStep = 0;
    }
    if (currentStep >= steps) {
        flyTimer->stop();
        eyetargetpos[0] = eyepos[0];
        eyetargetpos[1] = eyepos[1];
        eyetargetpos[2] = eyepos[2];
        zoomSpeed = 0.1;
    } else {
        currentStep++;
        eyepos[0] += flightPath[0];
        eyepos[1] += flightPath[1];
        eyepos[2] += flightPath[2];
    }
    updateGL();
}

void GLSceene::zoom(float steps) {
    float rx = eyerot[0]*piover180;
    float ry = eyerot[1]*piover180;
    float view[3];
    view[0] = sin(ry);
    view[1] = -sin(rx);
    float zx = -cos(rx);
    float zy = -cos(ry);
    if (zx < 0.0 && zy < 0.0) {
        view[2] = -1.0 * zx * zy;
    } else if (zx > 0.0 && zy > 0.0) {
        view[2] = zx * zy;
    } else if ( (zx >= 0.0 && zy < 0.0 ) || (zx < 0.0 && zy >= 0.0 )) {
        view[2] = -1.0 * zx * zy;
    } else { // zx==zy==0.0 || zx == 0.0 || zy = 0.0
        view[2] = zx * zy;
    }
    // one "step" on the mouse wheele will translate to 120 ticks.
    // the inital zoom step will be 1 tick.
    steps /= 120.0;
    // if the fly timer is active, increase zoom speed
    zoomSpeed *= 1.5;
    steps *= zoomSpeed;
    eyetargetpos[0] += (view[0] * steps );
    eyetargetpos[1] += (view[1] * steps );
    eyetargetpos[2] += (view[2] * steps );
    // limit eye distance from center depending on total expansion of universe
    if (eyetargetpos[0] > maxClip)
        eyetargetpos[0] = maxClip;
    if (eyetargetpos[0] < -maxClip)
        eyetargetpos[0] = -maxClip;
    if (eyetargetpos[1] > maxClip)
        eyetargetpos[1] = maxClip;
    if (eyetargetpos[1] < -maxClip)
        eyetargetpos[1] = -maxClip;
    if (eyetargetpos[2] > maxClip)
        eyetargetpos[2] = maxClip;
    if (eyetargetpos[2] < -maxClip)
        eyetargetpos[2] = -maxClip;
    eyeDestinationChanged = true;
    if ( !flyTimer->isActive() ) {
        flyTimer->start();
    }
}

void GLSceene::turnLeft(float rotStep) {
    turn(rotStep, 0.0f);
}

void GLSceene::turnRight(float rotStep) {
    turn(rotStep, 0.0f);
}

void GLSceene::turnUp(float rotStep) {
    turn(0.0f, rotStep);
}

void GLSceene::turnDown(float rotStep) {
    turn(0.0f, rotStep);
}

void GLSceene::turn(float dx, float dy) {
    eyerot[0] += dy;
    if (eyerot[0] < 0.0f)
        eyerot[0] += 360.0f;
    if (eyerot[0] > 359.0f)
        eyerot[0] -= 360.0f;
    eyerot[1] += dx;
    if (eyerot[1] < 0.0f)
        eyerot[1] += 360.0f;
    if (eyerot[1] > 359.0f)
        eyerot[1] -= 360.0f;
    updateGL();
}

void GLSceene::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        setFocus();
    }
}

void GLSceene::loadingFinished() {
    makeCurrent();
    updateGL();
}

void GLSceene::setSelection(QList<QTreeWidgetItem *> selectedItems) {
    treeSystemSelection.clear();
    treeSectorSelection.clear();
    int max = selectedItems.size();
    for (int i=0; i<max; i++) {
        QTreeWidgetItem *item = selectedItems.at(i);
        if (item->type() == 0) {
            treeSectorSelection.append(item->text(0) );
        } else if (item->type() == 1) {
            treeSystemSelection.append(item->text(0) );
        }
    }
    if ( !flyTimer->isActive() ) {
        updateGL();
    }
}

void GLSceene::treeDoubleClicked(QTreeWidgetItem *item, int col) {
    if (item->type() == 1) {
        // make sure, the item is also selected
        QString text = item->text(0);
        if ( !treeSystemSelection.contains(text) )
            treeSystemSelection.append(text);
        System *sys = systemForSystemName.value(item->text(col));
        float vx = sys->x()-eyepos[0];
        float vy = sys->y()-eyepos[1];
        float vz = sys->z()-eyepos[2];
        eyetargetpos[0] += vx;
        eyetargetpos[1] += vy;
        eyetargetpos[2] += vz;
        zoom(-6.0);
    }
}

float GLSceene::getAngle(float rx, float ry, float offset) {
    float r = sqrt(rx*rx + ry*ry);
    float a = acos(rx / r) * 180.0 / pi + offset;
    if ( (ry<0.0 && ry>=0.0) || (rx>=0.0 && ry<0.0))
        a += 180.0;
    while (a < 0.0)
        a += 360.0;
    while (a >= 360.0)
        a -= 360.0;
    return a;
}

void GLSceene::toggleFullScreen() {
    if (isFullScreen()) {
        showNormal();
    } else {
        showFullScreen();
    }
}

void GLSceene::showShiftChoices(bool bvalue) {
    bool oldValue = shiftChoices;
    shiftChoices = bvalue;
    if (oldValue != shiftChoices) {
        updateGL();
    }
}

void GLSceene::toggleFaction(Faction *faction) {
    if (faction == 0) return;
    if (factionSelection.contains(faction)) {
        factionSelection.remove(faction);
    } else {
        factionSelection.insert(faction);
    }
    updateGL();
}

void GLSceene::setDisplayFactionBubbles(bool bvalue) {
    QList<QString> names = factionsMap->keys();
    for (int i = 0, max = names.size(); i < max; i++) {
        QString name = names.at(i);
        Faction *faction = factionsMap->value(name);
        if (bvalue && !factionSelection.contains(faction)) {
            factionSelection.insert(faction);
        } else if (!bvalue) {
            factionSelection.clear();
        }
    }
    updateGL();
}

/*
    Overpainting stuff in here
*/
void GLSceene::overpaint(QPainter *painter) {
    // Quick help at top of OpenGL widget
    QString text = tr("LMB: select sector(s) and system(s) from tree | RMB: tilt + pan | MWheel: dolly | "
                      "F11: toggles full screen. Ctrl+Q: quits.");
    QFontMetrics metrics = QFontMetrics(font());
    int border = qMax(4, metrics.leading());

    QRect rect = metrics.boundingRect(0, 0, width() - 2*border, int(height()*0.125),
                                      Qt::AlignCenter | Qt::TextWordWrap, text);
    painter->setRenderHint(QPainter::TextAntialiasing);
    painter->setPen(Qt::white);
    painter->fillRect(QRect(0, 0, width(), rect.height() + 2*border), QColor(127, 127, 127, 64));
    painter->drawText((width() - rect.width())/2, border,
                      rect.width(), rect.height(),
                      Qt::AlignCenter | Qt::TextWordWrap, text);

    // positioning information at bottom left of OpenGL widget
    QFont font("Courier", 10);
    QFontMetrics fm = QFontMetrics(font);
    border = qMax(4, fm.leading());
    painter->setFont(font);
    painter->fillRect(QRect(0, height()-5*metrics.height()-2*border, 2*border+5*fm.maxWidth(), height()), QColor(127, 127, 127, 64));
    QString deg = QString::fromUtf8("°");
    painter->drawText(border, height()-4*metrics.height()-border, tr("pan  : %1%2").arg(eyerot[1]).arg(deg));
    painter->drawText(border, height()-3*metrics.height()-border, tr("tilt : %1%2").arg(eyerot[0]).arg(deg));
    painter->drawText(border, height()-2*metrics.height()-border, tr("crab : %1").arg(eyepos[0]));
    painter->drawText(border, height()-1*metrics.height()-border, tr("boom : %1").arg(eyepos[1]));
    painter->drawText(border, height()-0*metrics.height()-border, tr("dolly: %1").arg(eyepos[2]));

    // display a legend of faction names
    font.setPointSize(8);
    fm = QFontMetrics(font);
    if ((shiftChoices || !factionSelection.isEmpty()) && factionsMap != 0 && !factionsMap->isEmpty()) {
        QString legend = "";
        bool filterFactionNames = !shiftChoices && !factionSelection.isEmpty();
        QList<QString> names = factionsMap->keys();
        int x = 5, y = int(height()*0.125) + 2, increment = fm.height();
        y -= increment;
        for (int i = 0, max = names.size(); i < max; i++) {
            QString name = names.at(i);
            Faction *faction = factionsMap->value(name);
            if (shiftChoices && faction != 0) {
                name = tr("[%1] %2").arg(faction->shortCut()).arg(name);
            }
            if (filterFactionNames && !factionSelection.contains(faction)) {
                continue;
            }
            QColor col = faction->color();
            painter->setPen(col);
            painter->drawText(x, y, name);
            y += increment;
        }
    }
}
