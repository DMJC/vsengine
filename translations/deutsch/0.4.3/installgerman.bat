REM Installation script for the already translated files into german of vegastrike-0.4.3
REM Author: Plueschinger
REM Copyright: GPL2 or any later version

@Echo OFF
CLS
SET MYPATH=C:\Program Files\Vegastrike\Vegastrike-0.4.3
ECHO %MYPATH%

:jump1
REM ECHO %MYPATH% pathcontrol
IF NOT EXIST "%MYPATH%\master_part_list.csv" goto jump2
REM ECHO test1
goto jump3

:jump2
REM Could not find the path C:\Program Files\Vegastrike\Vegastrike-0.4.3 
ECHO Konnte das Verzeichnis C:\Program Files\Vegastrike\Vegastrike-0.4.3
ECHO nicht finden.
REM Please enter the correct path or "B" to quit
ECHO Bitte geben Sie das Installationsverzeichnis von vegastrike oder "b" 
ECHO zum benden des Installationsprogramm ein, anschliessend "Enter druecken". 
SET /P INPUT=
IF "%INPUT%" == "b" EXIT
REM Echo Varcontrol %INPUT%
set MYPATH=%INPUT%
REM ECHO %MYPATH% pathcontrol1
goto jump1

:jump3
REM Installation starts
ECHO Installation beginnt
ECHO %MYPATH% Pfadkontrolle2
copy languagechoice.bat "%MYPATH%\" 
copy master_part_list.csv "%MYPATH%\master_part_list.csv.de"
xcopy *.py "%MYPATH%\*.pyde" /S 
xcopy communications "%MYPATH%\communications.de\" 

REM copy the english files, if the copies are not already existing
REM only to avoid that they go lost, they are needed later for the programm "languagechoice".
IF NOT EXIST "%MYPATH%\master_part_list.csv.en" ( 
COPY "%MYPATH%\master_part_list.csv" "%MYPATH%\master_part_list.csv.en" )
IF NOT EXIST "%MYPATH%\bases\bartender.pyen" (
copy "%MYPATH%\bases\bartender.py" "%MYPATH%\bases\bartender.pyen" )
IF NOT EXIST "%MYPATH%\bases\fixers\no.pyen" (
copy "%MYPATH%\bases\fixers\no.py" "%MYPATH%\bases\fixers\no.pyen" )
IF NOT EXIST "%MYPATH%\modules\cargo_mission.pyen" (
copy "%MYPATH%\modules\cargo_mission.py" "%MYPATH%\modules\cargo_mission.pyen")
IF NOT EXIST "%MYPATH%\modules\dynamic_mission.pyen" (
copy "%MYPATH%\modules\dynamic_mission.py" "%MYPATH%\modules\dynamic_mission.pyen")
IF NOT EXIST "%MYPATH%\communications.en" (
xcopy "%MYPATH%communications" "%MYPATH%\communications.en\") 
REM Installation of the german files was successful, the program languagechoise starts now
REM after pressing a buttom
Echo Installation der deutschen Dateien erfolgreich abgeschlossen.
Echo Das Programm "Languagechoise" (Sprachauswahl) wird gestartet.   
PAUSE
CD "%MYPATH%"
LANGUAGECHOICE
EXIT 
