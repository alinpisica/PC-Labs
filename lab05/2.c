#include <stdio.h>

int cifra(int n, int c) {
  if (n == 0) {
    return (c == 0);
  }
  if (n % 10 == c) {
    return 1;
  } else {
    return cifra(n / 10, c);
  }
}

int main() {
  int numar, cif;
  scanf("%d %d", &numar, &cif);
  printf((cifra(numar, cif) ? "DA" : "NU"));
  return 0;
}

