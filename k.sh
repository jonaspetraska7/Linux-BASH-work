#!/bin/bash

arr=$@
if (( $# == 0 )); then
	ps -e -o tty | sort | uniq
fi
for x in $arr; do
	echo "=== Terminalo vardas : $x === \n\n2 a)"
	ps -e -o pid,tty,comm | awk -v var=$x '{if ($2 == var) print}'
	echo "\n2 b)"
	ps -e -o pid,tty,comm,user | awk -v var=$x '{if ($2 == var) print $4}' | uniq
	echo "\n2 c)"
	nam=$(who | awk -v var=$x '{if ($2 == var) print $1}')
	IP=""
	if [ "$nam" != "" ];
	then
		IP=$(who | awk -v var=$x '{if ($2 == var) print $6}')
		printf $IP
	else
		echo "Vartotojas siuo metu neprisijunges"
	fi
	check=$(echo $IP | grep 158.129)
	if [ "$check" != "" ];
        then
                echo "-vidinis IP"
        fi
	echo "\n2 e"
	username=$(ps -e -o pid,tty,comm,user | awk -v var=$x '{if ($2 == var) print $4}' | uniq)
	proc=$(ps -e -o pid,tty,comm,user | awk -v var=$username '{if ($4 == var) print}')
	if [[ "$nam" == "" && "$proc" != "" ]];
        then
                echo "Neprisijunges bet yra procesu"
	fi
        if [[ "$nam" == "" && "$proc" == "" ]];
	then
                echo "Neprisijunges ir nera procesu"
        fi

		
done 
