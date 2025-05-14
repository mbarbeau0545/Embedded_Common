@echo off
REM Spécifiez le chemin vers l'exécutable Python si nécessaire
set PYTHON_PATH=python

cd /d %~dp0\..\..

REM Exécuter le script Python avec des arguments fixes
%PYTHON_PATH% Doc\APP_Codegen\Script\main.py Doc\APP_Codegen\Cfg\Project_SoftwareCfg.xlsm

echo Press any key to continue...
pause