#!/bin/bash

# If given file doesn't exist, write N random numbers to it

# Exits with 1 if a file exists matching the filename provided
function file_exists {
    if [[ ! $# -eq 1 ]]
    then
        echo "Incorrect arguments provided"
        exit 1
    elif [[ -e $1 ]]
        then
            echo "File with this name already exists."
            exit 1
    fi
}


# Write N random numbers to the file
function write_random_to_file {
    if [[ ! $# -eq 2 ]]
    then    
        echo "Incorrect arguments provided"
        exit 1
    fi

    for (( i=0;i<$2;i++ ))
    do
        echo $RANDOM >> $1
    done    

    exit 0
}

file_exists random.txt
write_random_to_file random.txt 50
