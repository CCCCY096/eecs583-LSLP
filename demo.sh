#!/bin/bash
for i in {1..4}
do
    echo "Test${i} results:"  
    ./run.sh test${i}_correctness
done