IFS='
'
set -o noglob
echo "Enter file extension"
read ext
echo "Enter destination folder"
read dest
mkdir -p "$dest"
files=$(find . -maxdepth 1 -type f -name "*.$ext")
for file in $files; do
	cp "$file" "$dest"
done
echo "Succesffully copied files"
