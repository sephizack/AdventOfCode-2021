#!/bin/bash

set -e

CXX=clang++
CXXFLAGS="$(cat compile_flags.txt | tr '\n' ' ')"

exe=$1/main
infile=$1/input.txt

$CXX $CXXFLAGS -o $exe $exe.cpp
cat $infile | $exe

