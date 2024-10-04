#!/bin/bash

if [[ $# -gt 2 ]]
then
	echo "ERROR: Too many arguments!"
	exit 1
elif [[ $# -lt 2 ]]
then
	echo "ERROR: Too few arguments!"
	exit 1
elif [[ ! -d $1 ]]
then
	echo "ERROR: Filesdir does not exist!"
	exit 1
fi

#Number of files
X=0
#Number of lines containing the string
Y=0

Z=$(find $1 -type f)

for file in $Z
do
	((X=X+1))
	((Y=Y+$(cat $file | grep $2 | wc -l)))
done

echo "The number of files are "$X" and the number of matching lines are "$Y""
