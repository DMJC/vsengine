#!/bin/bash

OLD_PWD="$(pwd)"
cd "$(dirname $0)"

PLATFORM=linux
EXEC_NAME=vsmap3d
RUN_TARGET=debug

callbuild() {
  echo "Target \"${RUN_TARGET}\" was not built yet, calling build script now."
  ./build.bash "${RUN_TARGET}" "${EXEC_NAME}"
  if [ $? -gt 0 ]; then
    echo "Build had errors!"
    cd "${OLD_PWD}"
    exit $?
  fi
  if [ ! -f "bin/${PLATFORM}/${RUN_TARGET}/${EXEC_NAME}" ]; then
    echo "Target \"${RUN_TARGET}\" was not built into \"bin/${PLATFORM}/${RUN_TARGET}\"!"
    cd "${OLD_PWD}"
    exit 1
  fi
}

if [ "${2}" != "" ]; then
  EXEC_NAME="${2}"
fi

if [ "${1}" == "" ]; then
  RUN_TARGET="release"
elif [ "${1}" == "release" ]; then
  RUN_TARGET="release"
elif [ "${1}" != "debug" ]; then
  echo "Invalid make target specified: ${1}"
  cd "${OLD_PWD}"
  exit 1
fi

echo "Checking run dir: bin/${PLATFORM}/${RUN_TARGET}"
if [ ! -d "bin/${PLATFORM}/${RUN_TARGET}" ]; then
  callbuild
fi

echo "Checking run executable: ${EXEC_NAME}"
if [ ! -f "bin/${PLATFORM}/${RUN_TARGET}/${EXEC_NAME}" ]; then
  callbuild
fi

echo "Refreshing build if necessary"
./build.bash "${RUN_TARGET}" "${EXEC_NAME}"
if [ $? -gt 0 ]; then
  echo "Build had errors!"
  cd "${OLD_PWD}"
  exit $?
fi

echo "Starting \"${RUN_TARGET}\" run"
cd "bin/${PLATFORM}/${RUN_TARGET}"
CMD="${EXEC_NAME}"
echo "./${CMD}"
"./${CMD}"
cd ../../..

cd "${OLD_PWD}"
exit 0
