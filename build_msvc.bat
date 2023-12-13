@echo off

:: Init VS shell 
if "%VSINSTALLDIR%" == "" (
    for /F "tokens=* USEBACKQ" %%P in (`"%programfiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe" -property installationPath`) do call "%%P\Common7\Tools\VsDevCmd.bat" /no_logo
)

:: Project common sources
set COMMON_SOURCES=../src/interval.cpp ../src/interval_set.cpp ../src/square_inequality.cpp
set CL_ARGS=-W4 -std:c++14 -permissive- -Os -nologo -I ../include -EHsc

pushd build

:: Compile main project
cl %CL_ARGS% %COMMON_SOURCES% ../src/main.cpp 

:: Compile tests

cl %CL_ARGS% ../test/test_interval.cpp %COMMON_SOURCES% 
cl %CL_ARGS% ../test/test_interval_set.cpp %COMMON_SOURCES% 
cl %CL_ARGS% ../test/test_square_inequality.cpp %COMMON_SOURCES% 

popd