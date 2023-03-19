#!/bin/bash

# Make a directory containing 10 files each containing 50 random numbers

# Create a directory where the name is the current timestamp
date=$(date +%s)
mkdir "${date}"

# Make 10 files
for N in {0..9}
do
    # Call the file RandomN.dat
    file_name="${date}/Random${N}.dat"
    # Append 50 random numbers to the file
    for j in {0..49}
    do
        random=$(( $RANDOM % 50 + 1 ))
        echo ${random} >> ${file_name}
    done
done

exit 0