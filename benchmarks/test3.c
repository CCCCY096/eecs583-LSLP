
// test3: SLP fails. Opcode Mismatch
// #include <stdio.h>

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


int main() {
    for (int j = 0; j < 1000000; ++j) {
        for (long i = 0; i < n/2; i= i+2) {
          A[i+0] = ((B[2*i] << F[2*i]) & 0x11) + ((C[2*i]+G[2*i]) & 0x12);
          A[i+1] = ((D[2*i] + G[2*i+1]) & 0x13) + ((E[2*i] << F[2*i+1]) & 0x14);
        }
    }
    // printf("%ld %ld %ld\n", A[1000], B[1000], C[1000]);

}