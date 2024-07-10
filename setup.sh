#!/bin/sh

# Build C libraries
for dir in ./clibs/*; do
  if [ -d $dir ]; then
    cd $dir
    rm -rf ./build/*
    cmake -S . -B build
    cmake --build build
    ./build/test_program
    cd ../../
  fi
done

# remove previous build
rm -rf ./mypysort/__pycache__/ 
rm -rf ./mypysort/build/
rm -rf ./mypysort/mypysort.egg-info

# install python packages
pip install -r requirements.txt
