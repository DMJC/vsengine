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

echo Invalid run target specified: %1
goto end

:debug
set runtarget=debug
goto checkTargetDir

:release
set runtarget=release
goto checkTargetDir

:checkTargetDir
echo Checking run dir: bin\%PLATFORM%\%runtarget%
if exist bin\%PLATFORM%\%runtarget% goto checkExecutable
goto callbuild

:checkExecutable
echo Checking run executable: %execname%
if exist bin\%PLATFORM%\%runtarget%\%execname%.exe goto dorun
echo No run executable: bin\%PLATFORM%\%runtarget%\%execname%.exe
goto callbuild

:callbuild
echo Target %runtarget% was not built yet, calling build script now
call build.bat %runtarget% %execname%
if errorlevel 1 goto builderror
if exist bin\%PLATFORM%\%runtarget%\%execname%.exe goto dorun
echo Target %runtarget% was not built into bin\%PLATFORM%\%runtarget%!
goto end

:builderror
echo Build had errors!
exit 1
goto end

:dorun
echo Refreshing build if necessary
call build.bat %runtarget% %execname%
if errorlevel 1 goto builderror
echo Starting %runtarget% run
cd bin\%PLATFORM%\%runtarget%
%execname%
cd ..\..\..
goto end

:end
exit 0
