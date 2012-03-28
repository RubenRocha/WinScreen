@echo off
cls

:ws
winscreen
ping -n 5 localhost >nul
cls
goto ws