echo "printing 1 to 10 using loop"
a=1
while [ $a -lt 11 ]
do
    echo $a
    a=$(($a+1))
done