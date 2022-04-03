#!/bin/bash

file_name=$1
path=$2
i=1
echo "Press [CTRL+C] to stop.."

while :
do
    echo "\nSimulation($(printf "%06d" $i))" >> "$path/$file_name.txt"
    ./AwfulGreen | grep -B 5 Monsters\ faced >> "$path/$file_name.txt"
    ((i+=1))
    if ! (( i % 100 )); then
        echo "$file_name completed $(printf "%06d" $i)"
    fi
done
