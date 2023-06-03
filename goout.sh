#!/usr/bin/env bash
function g {
  g++ $1 -o ./build/$1.out &> log.txt
  if [[ $? -eq 1 ]];then
    mkdir ./build
    g++ $1 -o ./build/$1.out
  fi
  ./build/$1.out
}
