echo "Let's reverse a number"
echo "enter a number"
read num
a=0
while [ $num -gt 0 ]
do
    b=$(($num%10))
    a=$(($a*10+b))
    num=$(($num/10))
done

echo "Reversed num is: $a"