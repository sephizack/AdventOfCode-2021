#!/bin/bash

set -e

POSITIONAL=()
while [[ $# -gt 0 ]]; do
  key="$1"
  case $key in
    -h|--help)
      print_usage
      exit 0
      ;;
    -d|--gdb)
      GDB="Y"
      shift
      ;;
    *)
      POSITIONAL+=("$1")
      shift
      ;;
  esac
done
set -- "${POSITIONAL[@]}" # restore positional parameters

CXX=clang++
CXXFLAGS="$(cat compile_flags.txt | tr '\n' ' ')"

exe=$1/main
infile=$1/input.txt

$CXX $CXXFLAGS -o $exe $exe.cpp

if [[ -n $GDB ]]; then
    gdb -ex "set args -2 < $infile" $exe
else
    $exe < $infile
fi

