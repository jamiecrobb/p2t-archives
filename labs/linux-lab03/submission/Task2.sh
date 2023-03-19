#! /bin/bash

# Create three directories. If any or them exists then exit with error code

if [[ -d "data" || -d "data/processed" || -d "docs" ]]; then
    echo "ERROR: Directory already exists"
    exit 1

else
    mkdir -p data data/processed docs
fi