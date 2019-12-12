
// test3: SLP fails. Opcode Mismatch
#include <stdio.h>

const int n = 50000000;
long A[n] = {0};
long B[n] = {1};
long C[n] = {1};
long D[n] = {1};
long E[n] = {1};

int main() {

    for (long i = 0; i < n/2; i= i+2) {
        A[i+0] = ((B[2*i] << 1) & 0x11) + ((C[2*i] + 2) & 0x12);
        A[i+1] = ((D[2*i] + 3) & 0x13) + ((E[2*i] << 4) & 0x14);
    }
    printf("%ld %ld %ld\n", A[1000], B[1000], C[1000]);

}
