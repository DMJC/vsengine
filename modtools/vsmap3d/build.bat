@echo off

set PLATFORM=win32

if "%2"=="" goto defaultExecName
set execname=%2
goto checkTarget

:defaultExecName
set execname=vsmap3d
goto checkTarget

:checkTarget
if "%1"=="debug" goto debug
if "%1"=="" goto release
if "%1"=="release" goto release

echo Invalid make target specified: %1
goto end

:debug
set maketarget=debug
goto build

:release
set maketarget=release
goto build

:build
echo %maketarget% build
@echo on
qmake -project -after QT+=opengl QT+=xml QT+=gui win32:CONFIG+=console OBJECTS_DIR=obj/%PLATFORM%/%maketarget% MOC_DIR=moc/%PLATFORM%/%maketarget% DESTDIR=bin/%PLATFORM%/%maketarget% TARGET=%execname%
qmake
copy *.png bin\%PLATFORM%\%maketarget%
copy *pl.txt bin\%PLATFORM%\%maketarget%
copy *.ico bin\%PLATFORM%\%maketarget%
make %maketarget%
if errorlevel 1 goto builderror
@echo off
goto end

:builderror
exit 1

:end
exit 0
