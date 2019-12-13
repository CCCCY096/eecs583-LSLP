// test2: SLP fails. Load Address Mismatch.
#include <stdio.h>

const int n = 5000;
long A[n] = {0};
long B[n] = {1};
long C[n] = {1};
long D[n] = {1};
long E[n] = {1};

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

int main() {
    init(A);
    init(B);
    init(C);
    init(D);
    init(E);
    for (int j = 0; j < 1000; ++j) {
        for (long i = 0; i < n/2; i= i+2) {
            A[i+0] = (B[i+0] << D[i+0]) & (C[i+0] << E[i+0]);
            A[i+1] = (C[i+1] << E[i+1]) & (B[i+1] << D[i+1]);
        }
    }
    verify(A);
    verify(B);
    verify(C);
    return 0;
}
