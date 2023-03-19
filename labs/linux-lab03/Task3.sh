#! /bin/bash

# Append 100 random numbers to random.txt

for i in {0..99}
do
    echo $RANDOM >> random.txt
done