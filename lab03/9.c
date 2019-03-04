#include <stdio.h>

int main() {
  int a, b, c, n, ok;
  a = 1; b = 1;
  scanf("%d", &n);
  n -= 3;
  do {
    c = a + b;
    ok = 1;
    for (int i = 2; i < c / 2; i++) {
      if (c % i == 0) {
        ok = 0;
        break;
      }
    }
    if (ok) {
      printf("%d\n", c);
    }
    n--;
    a = b;
    b = c;
  } while (n);
  return 0;
}
