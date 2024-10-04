#!/bin/bash

if [[ $# -gt 2 ]]
then
	echo "ERROR: Too many arguments!"
	exit 1
elif [[ $# -lt 2 ]]
then
	echo "ERROR: Too few arguments!"
	exit 1
fi

if [[ -f $1 ]]
then
	echo $2 >> $1
elif [[ ! -f $1 ]]
then 
	touch $1
	echo $2 >> $1
fi

if [[ ! -f $1 ]]
then
	echo "ERROR: Could not create file!"
	exit 1
fi
