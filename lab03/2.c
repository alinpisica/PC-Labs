#include <stdio.h>

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    printf("%d ", i);
    if (i % m == 0 && i >= m) {
      printf("\n");
    }
    if (i / m % 24 == 0 && i >= m) {
      printf("\n");
    }
  }
  return 0;
}
