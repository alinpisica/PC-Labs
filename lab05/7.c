#include <stdio.h>

int transforma(int n) {
  int v[10] = {0};
  while (n) {
    v[n % 10]++;
    n /= 10;
  }
  if (v[0] > 0) {
    for (int i = 9; i >= 0; i--) {
      while (v[i]) {
        n *= 10;
        n += i;
        v[i]--;
      }
    }
  } else {
    for (int i = 1; i < 10; i++) {
      while (v[i]) {
        n *= 10;
        n += i;
        v[i]--;
      }
    }
  }
  return n;
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", transforma(n));
  return 0;
}

