#include <stdio.h>

int main() {
  int n, numcif = 0;
  int cif = 0, a, b = 0;
  scanf("%d", &n);
  while (1) {
    a = b + 1;
    b = a * 10 - 1;
    cif++;
    if (n >= b) {
      numcif += (b - a + 1) * cif;
    } else {
      numcif += (n - a + 1) * cif;
      break;
    }
  }
  printf("%d", numcif);
  return 0;
}

