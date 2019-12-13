#include <stdio.h>

const long long n = 4000;
long A[n];
long B[n];
long C[n];
long D[n];
long E[n];

void init(long *arr) {
    for (int i = 0; i < n; ++i) {
        arr[i] = i;
    }
}

__attribute__((optnone)) void verify(long *arr) {
    long total = 0;
    for (int i = 0; i < n; ++i) {
        total += arr[i];
    }
    printf("%ld\n", total);
}

// test1: SLP can vectorize
int main() {
    init(A);
    init(B);
    init(C);
    init(D);
    init(E);
    for (long long i = 0; i < n-2; i=i+2) {
        A[i+0] = B[i+0] + (D[i+0] << E[i+0]);
        A[i+1] = (D[i+1] << E[i+1]) + B[i+1];
    }

    verify(A);
    verify(B);
    verify(C);
    return 0;
}
