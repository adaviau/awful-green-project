#!/bin/bash
#script to run the Awful Green Thing Simulation

#make the output file
file="sim_log_$(date +"%Y-%m-%d_%H-%M").log"
touch "$file"

#Log simulation data to head of the file
date >> "$file"

runcount=1

re='^[0-9]+$'

if [[ $1 =~ $re ]]; then
    runcount=$1
fi

echo "Simulation will run" $runcount "times." >> "$file"
echo >> "$file"

exechere=./AwfulGreen
if [ -f "$exechere" ]; then
    echo "Running Simulation."
    echo >> "$file"
    counter=1
    while [ $counter -le $runcount ]
    do
        echo "Runing" "$counter" 
        ./AwfulGreen | tail -6 >> "$file" 
        echo "--------------" >> "$file"
        ((counter++))
    done
else
    echo "No Simulation Exec Here."
fi
