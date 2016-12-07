#!/bin/bash

OLD_PWD="$(pwd)"
cd "$(dirname $0)"

PLATFORM=linux
EXEC_NAME=vsmap3d
MAKE_TARGET=debug

if [ "${2}" != "" ]; then
  EXEC_NAME="${2}"
fi

if [ "${1}" == "" ]; then
  MAKE_TARGET="release"
elif [ "${1}" == "release" ]; then
  MAKE_TARGET="release"
elif [ "${1}" != "debug" ]; then
  echo "Invalid make target specified: ${1}"
  cd "${OLD_PWD}"
  exit 1
fi

echo "${MAKE_TARGET} build"
CMD="qmake -project -after QT+=opengl QT+=xml QT+=gui win32:CONFIG+=console OBJECTS_DIR=\"obj/${PLATFORM}/${MAKE_TARGET}\" MOC_DIR=\"moc/${PLATFORM}/${MAKE_TARGET}\" DESTDIR=\"bin/${PLATFORM}/${MAKE_TARGET}\" TARGET=\"${EXEC_NAME}\""
echo "${CMD}"
${CMD}
CMD="qmake"
echo "${CMD}"
${CMD}
for miscFile in $( ls *{.png,pl.txt,.ico} 2> /dev/null ) 
do
  echo "cp \"${miscFile}\" \"bin/${PLATFORM}/${MAKE_TARGET}/\""
  cp "${miscFile}" "bin/${PLATFORM}/${MAKE_TARGET}/"
done
CMD="make"
echo "${CMD}"
${CMD}


if [ $? -gt 0 ]; then
  cd "${OLD_PWD}"
  exit $?
fi

cd "${OLD_PWD}"
exit 0
