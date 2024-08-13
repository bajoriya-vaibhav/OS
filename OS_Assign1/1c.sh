#!/bin/bash

# Create named pipe
mkfifo my_pipe

# Process 1: Write data to the named pipe
echo "Hello, this is Process 1" > my_pipe

# Process 2: Read data from the named pipe
read data < my_pipe
echo "Process 2 received: $data"

# Clean up
rm my_pipe