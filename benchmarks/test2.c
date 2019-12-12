// test2: SLP fails. Load Address Mismatch.
#include <stdio.h>

const int n = 5000;
long A[n] = {0};
long B[n] = {1};
long C[n] = {1};
long D[n] = {1};
long E[n] = {1};


int main() {
    for (int j = 0; j < 1000000; ++j) {
        for (long i = 0; i < n/2; i= i+2) {
            A[i+0] = (B[i+0] << D[i+0]) & (C[i+0] << E[i+0]);
            A[i+1] = (C[i+1] << E[i+1]) & (B[i+1] << D[i+1]);
        }
    }
    printf("%ld %ld %ld\n", A[1000], B[1000], C[1000]);
    return 0;
}
