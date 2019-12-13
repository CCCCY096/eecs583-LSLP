// #include <stdio.h>

const long long n = 40000000;
long A[n];
long B[n];
long C[n];
long D[n];
long E[n];

// test1: SLP can vectorize
int main() {
    for (long long i = 0; i < n-2; i=i+2) {
        A[i+0] = B[i+0] + (D[i+0] << E[i+0]);
        A[i+1] = (D[i+1] << E[i+1]) + B[i+1];
    }

    // printf("%ld %ld %ld\n", A[1000], B[1000], C[1000]);
    return  A[1000]+ B[1000]+ C[1000];
}
