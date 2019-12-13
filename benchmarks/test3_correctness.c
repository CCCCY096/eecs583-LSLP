
// test3: SLP fails. Opcode Mismatch
#include <stdio.h>

const int n = 5000;
long A[n] = {0};
long B[n] = {1};
long C[n] = {1};
long D[n] = {1};
long E[n] = {1};

long F[n] = {1};
long G[n] = {1};
long H[n] = {1};
long I[n] = {1};


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
    init(F);
    init(G);
    init(H);
    init(I);
    for (int j = 0; j < 1000; ++j) {
        for (long i = 0; i < n/2; i= i+2) {
            A[i+0] = ((B[2*i] << F[2*i]) & 0x11) + ((C[2*i]+G[2*i]) & 0x12);
            A[i+1] = ((D[2*i] + G[2*i+1]) & 0x13) + ((E[2*i] << F[2*i+1]) & 0x14);
        }
    }
    verify(A);
    verify(B);
    verify(C);
    return 0;
}
