#include <stdio.h>

int main() {
  int P, i, j, k;
  scanf("%d", &P);
  for (i = 1; i <= P; i++) {
    for (j = 1; j <= (P - i) / 2; j++) {
      k = P - i - j;
      if ((i + j > k) && (i + k > j) && (j + k > i)) {
        printf("%d %d %d\n", i, j, k);
      }
    }
  }
  return 0;
}

