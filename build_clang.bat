@echo off

:: Project common sources
set COMMON_SOURCES=src/interval.cpp src/interval_set.cpp src/square_inequality.cpp
set CLANG_FLAGS=-Wall -Wextra -std=c++14 -pedantic -Os -I include

:: Compile main project
clang %CLANG_FLAGS% -o build/interval.exe %COMMON_SOURCES% src/main.cpp

:: Compile tests

clang %CLANG_FLAGS% -o build/test_interval.exe %COMMON_SOURCES% test/test_interval.cpp
clang %CLANG_FLAGS% -o build/test_interval_set.exe %COMMON_SOURCES% test/test_interval_set.cpp
clang %CLANG_FLAGS% -o build/test_square_inequality.exe %COMMON_SOURCES% test/test_square_inequality.cpp