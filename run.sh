#!/bin/bash

set -e

CXX=clang++
CXXFLAGS="-std=c++17 -Wall -Wextra -Wpedantic -Werror -O3"

exe=$1/main
infile=$1/input.txt

$CXX $CXXFLAGS -o $exe $exe.cpp
cat $infile | $exe

