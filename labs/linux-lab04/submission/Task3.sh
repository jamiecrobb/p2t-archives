#!/bin/bash

# Read the contents of help-read.txt and print 
# the number of words in each line.

while read line; do
#   echo "$line"
  num_words=$( echo ${line} | wc -w )
  echo ${num_words}
done < help-read.txt

exit 0