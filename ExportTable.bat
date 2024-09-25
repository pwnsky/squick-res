@echo off
rem Author: i0gan
rem Email : l418894113@gmail.com
rem Date  : 2022-11-27
rem Github: https://github.com/pwnsky/squick
rem Description: Generate configuration files

set ExportPath=.\
set XlsxPath=.\Xlsx
set struct_path=..\src\struct
set lua_struct_path=..\src\lua\struct
set client_config_path=..\client
set lua_src_path=..\src\lua

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
) else (
    pause
)

@REM rem copy to server
@REM copy ..\config\excel\excel.h %struct_path%
@REM mkdir %lua_struct_path%
@REM copy ..\config\excel\excel.lua %lua_struct_path%

@REM rem copy to client
@REM mkdir %client_config_path%\ini
@REM mkdir %client_config_path%\excel
@REM mkdir %client_config_path%\struct
@REM mkdir %client_config_path%\lua
@REM mkdir %client_config_path%\csharp


@REM xcopy /s /e /y %config_path%\ini %client_config_path%\ini
@REM xcopy /s /e /y %config_path%\struct %client_config_path%\struct

@REM xcopy /s /e /y %config_path%\excel %client_config_path%\excel
@REM rd /s/q %config_path%\excel

