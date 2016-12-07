@echo off
echo "starting Vega Map v0.20 | 2011-03-10"
set CMD = %1
set OPTS = %2
if "%1" == "" goto SetOpts
if "%2" == "" goto SetFile
goto Execute
:SetOpts
set CMD = -f
:SetFile
set OPTS = milky_way.xml
:Execute
java -jar dist/vegamap.jar %CMD %%OPTS %
echo bye bye traveler!