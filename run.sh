#!/bin/bash
### benchmark runner script
### run script project directory. 
### usage: ./run.sh test1

PATH_MYPASS=build/LSLP/LSLPPass.dylib  ### Action Required: Specify the path to your pass ###
NAME_MYPASS=-LSLPPass                           ### Action Required: Specify the name for your pass ###
BENCH=benchmarks/${1}.c
INPUT=${2}
CLANG=/usr/local/opt/llvm@8/bin/clang
OPT=/usr/local/opt/llvm@8/bin/opt


# Disable loop vectorizer: clang -fno-vectorize file.c
# Disable slp: clang -fno-slp-vectorize file.c
${CLANG} -O3 -fno-vectorize -fno-slp-vectorize -emit-llvm -c ${BENCH} -o ${1}.bc

${OPT} -o ${1}.lslp.bc -load ${PATH_MYPASS} ${NAME_MYPASS} -view-lslp-tree < ${1}.bc > /dev/null

${CLANG} ${1}.bc -o ${1}_no_lslp
${CLANG} ${1}.lslp.bc -o ${1}_lslp


${CLANG} -O3 -fno-vectorize -emit-llvm -c ${BENCH} -o ${1}slp_enable.bc
${CLANG} ${1}slp_enable.bc -o ${1}_slp



echo -e "1. Performance of unoptimized code"
time ./${1}_no_lslp > /dev/null
echo -e "\n\n"

echo -e "2. Performance of SLP optimized code"
time ./${1}_slp > /dev/null
echo -e "\n\n"

echo -e "3. Performance of LSLP optimized code"
time ./${1}_lslp > /dev/null
echo -e "\n\n"

# llvm-dis ${1}.bc
# llvm-dis ${1}.slp.bc
# llvm-dis ${1}.lslp.bc

# remove temp files
rm -f default.profraw ${1}_lslp ${1}_no_lslp ${1}_slp *.bc *_output?
