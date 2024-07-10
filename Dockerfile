FROM ubuntu:latest

# Set the working directory
WORKDIR /app

# Install dependencies
RUN apt-get update && apt-get install gcc g++ make cmake llvm python3 -y && apt-get install python3-pip -y && pip3 install jupyterlab

