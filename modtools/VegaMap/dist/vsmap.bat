@echo off
rem "starting Vega Map"
set CMD = %1
set OPTS = %2
:Execute
java -jar vegamap.jar %CMD %%OPTS %
echo bye bye traveler!