@echo OFF
echo 				-----------------
echo 				WinScreen Compiler
echo 				-----------------
echo Needs MingW installed.
:choice
SET Choice=
SET /P Choice=Press enter to Compile.
IF "%Choice%"=="" GOTO Start
GOTO End

:Start
cls
echo 			Starting Compiler.
g++ -w -static -o winscreen.exe main.cpp
echo 			Done...
:End
goto choice