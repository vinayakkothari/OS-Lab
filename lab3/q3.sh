x=`find . -type f -iname "*.txt"`
for i in $x;do
j=`echo "$i" | cut -d '.' -f 2` 
mv "$i" "./$j.text"
done
