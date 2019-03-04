#include <stdio.h>
#include <math.h>

int prim(int n) {
  if (n == 1) {
    return 1;
  }
  int sqrRoot = sqrt(n);
  for (int i = 2; i <= sqrRoot; i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int number;
  scanf("%d", &number);
  for (int i = 1; i <= number / 2; i++) {
    if (prim(i) && prim(number - i)) {
      printf("%d %d\n", i, number - i);
    }
  }
  return 0;
}
