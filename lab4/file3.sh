declare -a arrayOfNumbers
j=0
for i in $@
do
arrayOfNumbers[j]=$i
((j++))
done
echo "${arrayOfNumbers[@]}"
