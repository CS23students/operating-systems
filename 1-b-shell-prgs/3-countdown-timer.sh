#!/bin/bash
echo "Enter countdown time (in seconds):"
read time

while [ $time -gt 0 ]; do
    echo "$time seconds remaining..."
    sleep 1
    time=$((time - 1))
done

echo "Time's up!"


# Enter countdown time (in seconds):
# 5
# 5 seconds remaining...
# 4 seconds remaining...
# 3 seconds remaining...
# 2 seconds remaining...
# 1 seconds remaining...
# Time's up!
