#!/bin/bash

GENERATION="./Generation"
TESTS="./Tests"
VERTS=10000
CONNECTIVITY=0.2
i=1
$GENERATION/gen $VERTS $CONNECTIVITY 1>$TESTS/t${i}.gr 2>$TESTS/t${i}.ans


