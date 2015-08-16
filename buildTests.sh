#!/bin/bash

GENERATION="./Generation"
TESTS="./Tests"
VERTS=1000
MIN_CONNECTIVITY=0.1
MAX_CONNECTIVITY=0.4
i=1
NUM_TESTS=20
while [ $i -le $NUM_TESTS ]
do
    CONNECTIVITY=$(bc <<< "scale=2;$MIN_CONNECTIVITY+$i*(($MAX_CONNECTIVITY-$MIN_CONNECTIVITY)/$NUM_TESTS)")
    $GENERATION/gen $VERTS $CONNECTIVITY 1>$TESTS/t${i}.gr 2>$TESTS/t${i}.ans
    let "i=i+1"
done


