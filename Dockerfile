FROM python:3.14.0a3-bookworm

# Set the working directory
WORKDIR /app

# Install dependencies
RUN apt-get update && apt-get install gcc g++ make cmake llvm -y && \
    pip3 install jupyterlab
