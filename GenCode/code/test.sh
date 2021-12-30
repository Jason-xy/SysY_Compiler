#!/bin/sh
rm output/output*

cnt=0
for file in ../../test_cases/*
do
    # ./rdparser $file ./log.txt
    ./genllvm $file | grep "err"
    mv output.txt output/output$cnt.txt
    rm ast.txt
    # ./rdparser $file log.txt
    cnt=$((cnt+1))
done
echo $cnt