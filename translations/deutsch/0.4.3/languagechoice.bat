REM Script to choose the english or german language for vegastrike-0.4.3
REM Author: Plueschinger
REM Copyright: GPL2 or any later version

@ECHO OFF
CLS

:jump1
ECHO If you want to play Vegastrike in english,
ECHO enter "en" or "q" to quit this program and press the "enter buttom".
ECHO Wenn Sie Vegastrike in deutscher Sprache spielen wollen,
Echo geben Sie "de" ein  oder "b" um das Programm zu beenden und druecken die "Enter"-Taste.
SET /P MYLANGVAR=
if "%MYLANGVAR%" == "de" GOTO jump2
if "%MYLANGVAR%" == "en" GOTO jump3
if "%MYLANGVAR%" == "q" EXIT
if "%MYLANGVAR%" == "b" EXIT
GOTO jump1

:jump2
COPY master_part_list.csv.de master_part_list.csv
copy bases\*.pyde bases\*.py 
copy bases\fixers\*.pyde bases\fixers\*.py 
copy modules\*.pyde modules\*.py 
xcopy communications.de communications /Y
ECHO Die deutsche Version von Vegastrike ist jetzt aktiv,
Echo wenn sie Vegastrike lieber in englischer Sprache spielen wollen,
ECHO muessen sie das Script "languagechoice" nocheinmal aufrufen und "en" waehlen.
PAUSE
EXIT

:jump3
COPY master_part_list.csv.en master_part_list.csv
copy bases\*.pyen bases\*.py 
copy bases\fixers\*.pyen bases\fixers\*.py 
copy modules\*.pyen modules\*.py 
xcopy communications.en communications /Y
ECHO The english version of vegastrike is now aktiv,
ECHO if you prefer to play vegastrike in german language,
ECHO you have to rerun the script "languagechoice" again and choose "de".
PAUSE
EXIT
