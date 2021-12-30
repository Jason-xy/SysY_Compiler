#!/bin/sh

# clear
rm log.txt

cnt=0
for file in ../../../test_cases/*
do
    # ./rdparser $file ./log.txt
    ./rdparser $file log.txt | grep "err"
    # ./rdparser $file log.txt
    cnt=$((cnt+1))
done
echo $cnt