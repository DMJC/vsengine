#!/bin/sh
ARG=$1
SETUPARG=${ARG:="nosetup"}
CURPWD=$PWD

DATAFOLDER="data4.x"

#Now search for the data directory in supported directories.

VSDATADIR=0

for TEMPDATADIR in $CURPWD $CURPWD/$DATAFOLDER $CURPWD/../$DATAFOLDER /usr/local/games/vegastrike/$DATAFOLDER /usr/share/local/vegastrike/$DATAFOLDER /usr/local/share/vegastrike/$DATAFOLDER /usr/share/vegastrike/$DATAFOLDER /usr/games/vegastrike/$DATAFOLDER /opt/share/vegastrike/$DATAFOLDER /usr/local/vegastrike/$DATAFOLDER ; do
  {
  if [ -s $TEMPDATADIR/factions.xml ]; then
    VSDATADIR=$TEMPDATADIR
    echo Got data $VSDATADIR
    break
  fi
  } ; done

if [ $VSDATADIR != 0 ]; then

  VERSION=`head -1 $VSDATADIR/Version.txt`
  mkdir -p $HOME/$VERSION
  cd $HOME/$VERSION
  if [ \! -e ~/$VERSION/setup.config ]; then
    cp $VSDATADIR/setup.config .
  fi
  if [ \! -e ~/$VERSION/vegastrike.config ]; then
    cp $VSDATADIR/vegastrike.config .
    vssetup
  fi
  if [ $SETUPARG = "setup" ] || [ $SETUPARG = "--setup" ]; then
    vssetup
  fi
  cd $VSDATADIR
  vslauncher

else
  echo Una directory di programma non � stata trovata.
fi
