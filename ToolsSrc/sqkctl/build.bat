@echo off
rem Author: i0gan
rem Email : l418894113@gmail.com
rem Date  : 2023-01-04
rem Github: https://github.com/pwnsky/squick
rem Description: Build sqkctl tools

set build_path=%~dp0\build
mkdir %build_path%
cd %build_path%
cmake ..
cmake --build . 

if "%1"=="no_pause" (
    echo continue
) else (
    pause
)