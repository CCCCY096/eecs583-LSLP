// test2: SLP fails. Load Address Mismatch

int main() {
    const int n = 50;
    long A[n] = {0};
    long B[n] = {1};
    long C[n] = {1};
    for (long i = 0; i < n-2; i= i+2) {
        A[i+0] = (B[i+0] << 1) & (C[i+0] << 2);
        A[i+1] = (C[i+1] << 3) & (B[i+1] <<4);
    }
}
