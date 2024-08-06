@echo off

cd build

if "%1" == "SimpleMatrixTests" (
    cd tests
    .\SimpleMatrixTests.exe
) else (
    .\SimpleMatrixLibrary.exe
)