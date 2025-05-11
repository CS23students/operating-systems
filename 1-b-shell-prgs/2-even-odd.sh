#!/bin/bash
echo "Enter a number:"
read num

if (( num % 2 == 0 )); then
    echo "$num is Even"
else
    echo "$num is Odd"
fi


# Enter a number:
# 7
# 7 is Odd
