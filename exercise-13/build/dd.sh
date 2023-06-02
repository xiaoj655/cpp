#!/usr/bin/env bash
i=0
while [ "$i" != 10000 ];
do
  ./debug2.sh
  if [ $? -eq 1 ]; then 
    break
  fi
  echo $i
  i=$((i+1))
done
