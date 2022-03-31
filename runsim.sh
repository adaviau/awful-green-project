#!/bin/bash

file_name=$1
path=$2

for i in {1..1000} 
do
./AwfulGreen 10000 > "$path/$file_name$(printf "%04d" $i)".txt     
done
