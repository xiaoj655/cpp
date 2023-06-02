#!/usr/bin/env bash

./E < ./input.txt > ./output.txt
./Ee < ./input.txt > ./correct.txt
diff ./output.txt ./correct.txt
