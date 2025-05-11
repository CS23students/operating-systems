#!/bin/bash
echo "Enter first number:"
read num1
echo "Enter second number:"
read num2
echo "Choose operation: +, -, *, /"
read op

case $op in
    +) result=$((num1 + num2)) ;;
    -) result=$((num1 - num2)) ;;
    \*) result=$((num1 * num2)) ;;
    /) result=$((num1 / num2)) ;;
    *) echo "Invalid operation"; exit 1 ;;
esac

echo "Result: $result"


# Enter first number:
# 10
# Enter second number:
# 5
# Choose operation: +
# Result: 15
