#!/bin/sh

echo "Enter basic salary"
read basics
echo "Enter travelling allowance"
read ta
GS=$(echo "$basics + $ta + 0.1 * $basics"|bc -l)
echo Gross salary is $GS
