#!/bin/sh

echo "Which folder would you like to parse?"
read folder
echo "Enter pattern"
read pattern
x=`find $folder -type f -iname "$pattern*"`
for i in $x;do
echo "$i"
done
