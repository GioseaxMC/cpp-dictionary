@echo off

cd ./tests

g++ "set.cpp" -o test
.\test

g++ "edit.cpp" -o test
.\test

g++ "pop.cpp" -o test
.\test

del .\test.exe