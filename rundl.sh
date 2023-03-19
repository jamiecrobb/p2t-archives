#! /bin/bash

# P2T Linux Lecture 4
# Script to run a data logger
# Jamie Robb (02 February 2023)

# Get data logger application
application=${1}

# Check the arguments
if [[ $# != 1 ]]; then
        echo "Usage: ./rundl.sh DATALOGGER"
        exit 1
# Check the argument is executable
elif [[ ! -x ${application} ]]; then
        echo "ERROR: Not executable: ${application}"
        exit 2
fi

# Run datalogger 5 times
for count in {1..5}; do 
    echo "Running ${application}: ${count}"
    ${application}
    sleep 1
done

# Process output
for filename in *.dat; do
    grep 'Offline' ${filename} > /dev/null
    
    #Remove offline results
    if [[ $0 == 0 ]]; then 
        rm ${filename}
    else
        data=$(tail -n 1 ${filename})
        echo "Data: ${data}" 
    fi
done

# Success!
exit 0