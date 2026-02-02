@echo off
rem Author: i0gan
rem Email : l418894113@gmail.com
rem Date  : 2022-11-27
rem Github: https://github.com/pwnsky/squick
rem Description: Generate configuration files

del /f /q /s  XlsxGen\*

set ExportPath=.\XlsxGen
set XlsxPath=.\Xlsx

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
    copy XlsxGen\excel.lua ..\src\lua\struct
    copy XlsxGen\excel.h ..\src\struct
)else if "%1"=="unreal" (
    echo "Copy to unreal"
    xcopy /s /e /y XlsxGen\Lua ..\Content\Script\Excel
    del /f /q /s  ..\Content\Script\Excel\Root.lua
)else (
    pause
)