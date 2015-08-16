#!/bin/bash

TESTS="./Tests"

HEAP_TEST_NUMBER=20
i=1

while [ $i -le $HEAP_TEST_NUMBER ]
do
    EXECDIR="HeapBin/heap$i"
    EXEC="dijkstra$i"
    for file in $TESTS/*.gr
    do
        TEST=`basename $file .gr`
        ANSWER="$TESTS/${TEST}.ans"
        SRC=`cat $ANSWER | cut -d ' ' -f3`
        TGT=`cat $ANSWER | cut -d ' ' -f5`
        DISTANCE=`cat $ANSWER | cut -d ' ' -f7`
        PARAMFILE="$EXECDIR/${EXEC}_${TEST}_param.txt"
        RESULT=`$EXECDIR/$EXEC $SRC $TGT <$file 2>$PARAMFILE`
        if [ $RESULT -eq $DISTANCE ];then
            echo "Processed: $EXEC $TEST $RESULT (Correct)"
        else
            echo "Processed: $EXEC $TEST $RESULT (Error)"
        fi
    done
    let "i++"
done
