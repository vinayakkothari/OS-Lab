for file in *;do
if[ -f "$file" ];
sed -i -E 's/(^|\.)xample:/\Example:/g' "$file"
done
echo "File modified"
