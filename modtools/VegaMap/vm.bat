@echo off
rem "development version of the batch file"
set CMD = %1
set OPTS = %2
:Execute
cd dist
java -jar vegamap.jar %CMD %%OPTS %
cd ..
echo bye bye traveler!