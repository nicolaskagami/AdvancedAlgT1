#!/bin/bash

TESTS="./Tests"
DATAFILE="./Benchmarks${1}.dat"
WINDATAFILE="./BenchmarksWin${1}.dat"
HEAP_TEST_NUMBER=20
i=1

echo "n test inserts deletes updates time" > $DATAFILE
echo "n test inserts deletes updates time" > $WINDATAFILE
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
        echo -e "$i $TEST `cat $PARAMFILE`\r" >> $WINDATAFILE
        echo "$i $TEST `cat $PARAMFILE`" >> $DATAFILE
        
    done
    let "i++"
done
