#include <stdio.h>

const long long n = 100000000;
long A[n];
long B[n];
long C[n];

// test1: SLP can vectorize
int main() {
    for (long long i = 0; i < n-2; i=i+2) {
        A[i+0] = B[i+0] + (C[i+0]+3);
        A[i+1] = (C[i+1]-4) + B[i+1];
    }

    printf("%ld %ld %ld\n", A[1000], B[1000], C[1000]);
    return 0;
}
