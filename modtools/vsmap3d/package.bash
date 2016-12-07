#!/bin/bash

PACK_DIR=packages
PROG=vsmap3d
BIN_DIR=bin
RELEASE_BIN=release

VERSION=""
if [ "${1}" != "" ]; then
  VERSION="-${1}"
else
  echo "Warning: Packaging without version string!"
fi

OLD_PWD="$(pwd)"
cd "$(dirname $0)"

BASE_DIR="$(pwd)"
BIN_DIR="${BASE_DIR}/${BIN_DIR}"
PACK_DIR="${BASE_DIR}/${PACK_DIR}"
PROG_DIR="${PACK_DIR}/${PROG}"

# create packages dir if necessary
if [ ! -d "${PACK_DIR}" ]; then
  mkdir "${PACK_DIR}"
fi
cd "${PACK_DIR}"

# create programm dir if necessary
if [ ! -d "${PROG_DIR}" ]; then
  mkdir "${PROG_DIR}"
else
  rm -fr "${PROG_DIR}/*"
fi

# package sources
cd "${BASE_DIR}"
cp changelog "${PROG_DIR}"
cp readme "${PROG_DIR}"
for sourceFile in $( ls *{.png,pl.txt,.cpp,.h,.bat,.bash,.cbp,.ico,.xcf} 2> /dev/null ) 
do
  if [ -f "${sourceFile}" ]; then
    cp "${sourceFile}" "${PROG_DIR}"
  fi
done
cd "${PACK_DIR}"
tar -cjf "${PROG}${VERSION}-src.tar.bz2" "${PROG}"
cd "${PROG}"
rm -fr *

# package all binary releases
cd "${BIN_DIR}"
for platform in $( ls -d */ | sed -e s/[/]//g 2> /dev/null ) 
do
  RELEASE_DIR="${BIN_DIR}/${platform}/${RELEASE_BIN}"
  if [ -d "${RELEASE_DIR}" ]; then
    cd "${RELEASE_DIR}"
    cp -r * "${PROG_DIR}"
    cd "${PACK_DIR}"
    tar -cjf "${PROG}${VERSION}-${platform}.tar.bz2" "${PROG}"
    cd "${PROG}"
    rm -fr *
  fi
done

cd "${OLD_PWD}"
exit 0
