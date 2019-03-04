#include <stdio.h>
#include <stdlib.h>

int main() {
  int cap = 5;
  int n = 0;
  int *v = (int*)malloc(cap * sizeof(int));
  int number;
  while (1) {
    scanf("%d", &number);
    if (number == 0) {
      break;
    }
    if (n + 1 == cap) {
      cap *= 2;
      v = realloc(v, cap * sizeof(int));
    }
    v[n] = number;
    n++;
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", v[i]);
  }
  return 0;
}

