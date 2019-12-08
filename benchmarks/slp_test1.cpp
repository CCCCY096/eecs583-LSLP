#include <stdio.h>

int main() {
  long A[53] = {0};
  long B[53] = {1};
  long C[53] = {1};
  for (long i = 0; i < 50; i=i+2) {
    A[i] = B[i] + (C[i]+3);
    A[i+1] = (C[i+1]-4) + B[i+1];
  }
  return 0;
}
