@echo off
setlocal

REM Set default target to SimpleMatrixLibrary
set TARGET=SimpleMatrixLibrary

REM Check if user add parameter
if not "%~1"=="" (
    set TARGET=%~1
)

REM Create build directory and go into it
if not exist build (
    mkdir build
)
cd build

REM Run cmake if files not exist
if not exist Makefile (
    cmake -G "MinGW Makefiles" ..
)

REM Build selecting target
mingw32-make %TARGET%

endlocal