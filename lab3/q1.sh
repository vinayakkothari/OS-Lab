echo "Enter file name: "
read file
if [ -f $file ]
then
echo $file "---> It is an ORDINARY FILE."
elif [ -d $file ]
then
echo $file "---> It is a DIRECTORY."
else
echo $file "---> It is something else."
fi
