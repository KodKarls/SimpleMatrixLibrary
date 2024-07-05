@echo off

cd build

if "%1" == "runMatrixTests" (
    cd tests\matrix_tests
    .\runMatrixTests.exe
) else (
    .\SimpleMatrixLibrary.exe
)