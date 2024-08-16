echo "Enter text file"
read file

even="even"
odd="odd"
lno=1
while IFS= read -r line;do
if [ "$((lno%2))" -eq 0 ]; then
echo "$line" >> "$even"
else
echo "$line" >> "$odd"
fi
((lno++))
done<"$file"
echo "Even and odd lines transferred"
