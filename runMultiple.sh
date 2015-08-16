#!/bin/bash

NUM_BATCHES=30
i=21
while [ $i -le $NUM_BATCHES ]
do
    bash buildTests.sh
    bash runTests.sh
    bash formatResults.sh $i
    echo "Batch $i done"
    let "i++"
done

