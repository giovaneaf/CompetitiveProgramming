#!/bin/bash

usage="$(basename $0) directory executable [input file extension] [output file extension]
directory where have all inputs and outputs (the name of both should be the same)
executable to run the test cases
file extensions are optional and shouldn't have the dot (.in for input and .ans for output are the default extensions)"


if [ "$1" == "--help" ] || [ "$1" == "-h" ]
then
    echo "$usage"
    exit 0
fi

if [ "$2" == "" ]
then
    echo "Number of arguments is invalid, check --help for more details"
    exit 0
fi

path=$1
FILES=$path*
executable=$2
inputExtension=${3:-in}
outputExtension=${4:-ans}
tests=()

for file in $FILES
do
    if [[ $file == *.$inputExtension ]]
    then
       foo=("${foo[@]}" $(basename $file .$inputExtension))
    fi
done

failed=0

echo "Running testcases..."

for i in "${foo[@]}"
do
    $executable < $path$i.$inputExtension | diff $path$i.$outputExtension -
    if [ $? -ne 0 ]
    then
	echo "Failed test case $i"
	let "failed+=1"
    fi
done

if [ $failed -eq 0 ]
then
    echo "All test cases has passed!"
fi

