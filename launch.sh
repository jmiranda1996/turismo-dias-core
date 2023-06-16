#!/bin/bash
# g++ ./src/main.cpp -o program.exe -std=c++17 -I .
g++ -g $(find ./src -type f -iregex ".*\.cpp") -o program.exe -std=c++17
./program.exe dev