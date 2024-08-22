n=$#
if [ $n -eq 0 ]
echo "NOTE: Please enter yes/no when prompted"
then
	echo "No files provided"
	exit 1
fi
rm -i $*
