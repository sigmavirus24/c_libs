#!/bin/bash

count=0
declare -a arr

make

for file in tests/* ; do 
    if [[ -x $file ]] ; then
        $file
        if [[ 0 -ne $? ]] ; then
            arr[$count]="$file"
            count=$(($count + 1))
        fi
    fi
done

if [[ 0 -ne $count ]] ; then
    echo "================================================================"
    echo "$count errors encountered in:"
    for file in ${arr[@]} ; do
        echo "$file"
    done
fi
