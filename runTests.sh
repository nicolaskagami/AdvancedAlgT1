#!/bin/bash

TEST="t100.gr"
SRC=`cat haha | cut -d ' ' -f3`
TGT=`cat haha | cut -d ' ' -f5`
DISTANCE=`cat haha | cut -d ' ' -f7`
RESULT=`./dijkstra $SRC $TGT < $TEST`

if [ $RESULT -eq $DISTANCE ];then
    echo YAY
else
    echo NAY
fi

echo $DISTANCE $RESULT
