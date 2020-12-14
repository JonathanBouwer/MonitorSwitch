@echo off
if not exist "build" mkdir build
set STARTTIME=%TIME%
cl main.c /Febuild/MonitorSwitch.exe /nologo -link user32.lib
set ENDTIME=%TIME%
del *.obj

set /A STARTTIME=(1%STARTTIME:~0,2%-100)*3600000 + (1%STARTTIME:~3,2%-100)*60000 + (1%STARTTIME:~6,2%-100)*1000 + (1%STARTTIME:~9,2%-100)
set /A ENDTIME=(1%ENDTIME:~0,2%-100)*3600000 + (1%ENDTIME:~3,2%-100)*60000 + (1%ENDTIME:~6,2%-100)*1000 + (1%ENDTIME:~9,2%-100)
set /A DURATION=(%ENDTIME%-%STARTTIME%)
echo Took %DURATION% milliseconds