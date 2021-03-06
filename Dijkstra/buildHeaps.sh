#!/bin/bash


#Build dijkstras with different N values for the heap
HEAP_TEST_NUMBER=20
i=1
while [ $i -le $HEAP_TEST_NUMBER ]
do
    DIRNAME="heap$i"
    if [ ! -d $DIRNAME ]; then
        mkdir $DIRNAME
    fi

    g++ -DN="$i" dijkstra.cpp FSgraph.cpp NHeap.cpp -o $DIRNAME/dijkstra$i
    let "i=i+1"
done
