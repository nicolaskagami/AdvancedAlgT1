#!/bin/bash



MAX_NODE=23947347


file=$1
NUM_TESTS=30
i=1
while [ $i -le $NUM_TESTS ]
do
    SRC=$RANDOM
    TGT=$RANDOM
    echo "USA ${i} $SRC to $TGT started"
    ./dijkstra $SRC $TGT <$file 2>USA${SRC}_${TGT}
    echo "USA ${i} $SRC to $TGT done"
    let "i++"
done

