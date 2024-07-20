FROM python:3.12.4-bookworm

# Set the working directory
WORKDIR /app

# Install dependencies
RUN apt-get update && apt-get install gcc g++ make cmake llvm -y && \
    pip3 install jupyterlab
