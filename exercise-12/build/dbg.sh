#!/usr/bin/env bash

./$1.cpp.out < ./debug/input.txt > ./debug/output.txt
diff ./debug/correct.txt ./debug/output.txt 
if [[ $? -eq 0 ]];then
  echo "pass!"
fi
