#!/bin/bash

# Checks whether a .bak file exists for each 
# .data file in the directory

# Iterate over files in working directory
for file in "$PWD"/*
do

    if [[ $file == *.data ]]; then

        if [[ ! -e $file.bak ]]; then

            echo "No .bak file for: $file"
            cp $file "$file".bak

        fi

    fi
done