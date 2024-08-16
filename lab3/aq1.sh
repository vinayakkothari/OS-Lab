echo "Enter a number: "
read n
is_prime=true
if [ "$n" -lt 2 ]; then
is_prime=false
else
	for((i=2;i <=$((n/2)); i++));do
		if [ "$((n % i))" -eq 0 ]; then
		is_prime=false
		break
	fi
done
fi
if [ "$is_prime" = true ];then
echo "$n is prime"
else
echo "$n is not prime"
fi
