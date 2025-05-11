#!/bin/bash
echo "Enter the file name:"
read filename

if [ -f "$filename" ]; then
    echo "File '$filename' exists."
else
    echo "File '$filename' does not exist."
fi


# Enter the file name:
# test.txt
# File 'test.txt' exists.
