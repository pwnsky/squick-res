@echo off
rem Author: i0gan
rem Email : l418894113@gmail.com
rem Date  : 2022-11-27
rem Github: https://github.com/pwnsky/squick
rem Description: Generate configuration files

del /f /q /s  XlsxCode\*
del /f /q /s  XlsxXML\*

set ExportPath=.\
set XlsxPath=.\Xlsx

mkdir %ExportPath%\XlsxCode
mkdir %ExportPath%\XlsxXML\Struct
mkdir %ExportPath%\XlsxXML\Ini

.\Tools\sqkctl excel %XlsxPath% %ExportPath%
if %errorlevel% equ 0 (
    echo "Excel to config succ"
) else (
    echo "Excel to config Failed!"
    pause
    exit 1
)

if "%1"=="no_pause" (
    echo continue
)else if "%1"=="server" (
    echo "Copy to server"
    copy XlsxCode\excel.lua ..\src\lua\struct
    copy XlsxCode\excel.h ..\src\struct
)else (
    pause
)