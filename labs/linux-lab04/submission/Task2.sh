#!/bin/bash

# For each empty file in the current directory, ask if the
# user wants to delete it. If yes, delete it. If no, do 
# nothing.

for file in "$PWD"/*
do 
    # Only check for files that aren't directories
    if [[ -f $file ]]
    then
        # If the file is empty
        if [[ ! -s ${file} ]]
        then
            echo "${file} is empty"
            echo "Do you want to delete it? [y/n]"
            # Get input
            read delete_file
            if [[ delete_file == "y" ]]
            then
                echo "Deleted"
                rm -f ${file}
            fi
        fi
    fi
done

exit 0