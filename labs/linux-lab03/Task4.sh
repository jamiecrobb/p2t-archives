#! /bin/bash

# Loops through filenames provided as CLIs
# and prints the kind of file, or whether 
# the file doesn't exist.

# Loop through filenames as arguments
for filename in "$@"
do
    # Check if the file is a directory
    if [[ -d $filename ]]; then
        echo "$filename is a directory."

    # Check if it's a regular file
    elif [[ -f $filename ]]; then
        echo "$filename is a regular file."

    elif [[ ! -e $filename ]]; then
        echo "$filename doesn't exist."

    # It's none of the above
    else
        echo "$filename isn't a file or directory. What is it?!"
    fi
done