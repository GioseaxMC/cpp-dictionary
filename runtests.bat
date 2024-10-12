@echo off

cd ./tests

g++ "set.cpp" -o test
.\test
del .\test.exe

g++ "edit.cpp" -o test
.\test
del .\test.exe

g++ "pop.cpp" -o test
.\test
del .\test.exe

