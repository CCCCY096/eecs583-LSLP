#!/bin/bash
### benchmark runner script
### run script project directory. 
### usage: ./run.sh test1

PATH_MYPASS=~/eecs583-LSLP/build/LSLP/LSLPPass.so  ### Action Required: Specify the path to your pass ###
NAME_MYPASS=-LSLPPass                           ### Action Required: Specify the name for your pass ###
BENCH=benchmarks/${1}.c
INPUT=${2}


# Disable loop vectorizer: clang -fno-vectorize file.c
# Disable slp: clang -fno-slp-vectorize file.c
clang -O3 -fno-vectorize -fno-slp-vectorize -emit-llvm -c ${BENCH} -o ${1}.bc

opt -o ${1}.lslp.bc -load ${PATH_MYPASS} ${NAME_MYPASS} < ${1}.bc > /dev/null

clang ${1}.bc -o ${1}_no_lslp
clang ${1}.lslp.bc -o ${1}_lslp


echo -e "1. Performance of unoptimized code"
time ./${1}_no_lslp > /dev/null
echo -e "\n\n"
echo -e "2. Performance of optimized code"
time ./${1}_lslp > /dev/null
echo -e "\n\n"

# remove temp files
rm -f default.profraw ${1}_lslp ${1}_no_lslp *.bc *_output?
