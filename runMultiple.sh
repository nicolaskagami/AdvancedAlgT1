#!/bin/bash

NUM_BATCHES=30
i=1
while [ $i -le $NUM_BATCHES ]
do
    bash buildScalingTests.sh
    bash runTests.sh
    bash formatResults.sh $i
    echo "Batch $i done"
    let "i++"
done

