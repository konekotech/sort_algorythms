#! /bin/sh

# Build bubble_sort
cd ./clibs/bubble_sort && rm -rf ./build/* && cmake -S . -B build && cmake --build build && ./build/test_program && cd ../../

# remove previous build
rm -rf ./mypysort/__pycache__/ 
rm -rf ./mypysort/build/
rm -rf ./mypysort/mypysort.egg-info

# install python packages
pip install -r requirements.txt

pip install ./mypysort

# start jupyter notebook
jupyter-lab --allow-root --no-browser --ip=0.0.0.0 --port=8888 --NotebookApp.token='' --notebook-dir=/app --NotebookApp.disable_check_xsrf=True