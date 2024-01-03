# Use an Ubuntu base image
FROM ubuntu:latest

# Set the working directory inside the container
WORKDIR /app

# Copy the contents of your project to the container
COPY . .

# Install build dependencies
RUN apt-get update && \
    apt-get install -y build-essential meson && \
    rm -rf /var/lib/apt/lists/*

# Run Meson to configure the build
RUN meson build

# Change to the build directory
WORKDIR /app/build

# Build the project
RUN ninja

# Install the library system-wide
RUN ninja install

# Set the entry point for the container
ENTRYPOINT ["/bin/bash"]
