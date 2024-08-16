echo "Enter text file"
read file
lno =1
while IFS= read -r line;do
if [ "$((lno%2))" -eq 1 ]; then
echo "$line" >> temp
fi
((lno++))
done<"$file"
mv temp "$file"
echo "Even numbered lines deleted"
