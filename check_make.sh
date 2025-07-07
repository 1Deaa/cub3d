#!/bin/bash

# Run make command
make

# Check if make succeeded
if [ $? -ne 0 ]; then
    echo "Make failed. Exiting with error code."
    make fclean
    exit 1
else
    echo "Make succeeded."
    make fclean
    exit 0
fi
