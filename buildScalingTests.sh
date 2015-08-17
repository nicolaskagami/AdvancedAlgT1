#!/bin/bash

GENERATION="./Generation"
TESTS="./Tests"
MIN_VERTS=16
CONNECTIVITY=0.4
i=1
NUM_TESTS=8
while [ $i -le $NUM_TESTS ]
do
    VERTS=$(bc <<< "scale=0;$MIN_VERTS*2^$i")
    $GENERATION/gen $VERTS $CONNECTIVITY 1>$TESTS/t${i}.gr 2>$TESTS/t${i}.ans
    let "i=i+1"
done


