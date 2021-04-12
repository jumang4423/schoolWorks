#!/usr/local/gnu/bin/bash

    cnt=$1
while [ "$cnt" -le "$3" ]; do
    echo $cnt
    let cnt+=$2
done




