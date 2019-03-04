#include <stdio.h>

int factorial(int n) {
  if (n == 0) {
    return 1;
  }
  return n * factorial(n - 1);
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  // int sol = factorial(n) / (factorial(m) * factorial(n - m));
  int sol = 1;
  for (int i = m; i >= 1; i--) {
    sol *= (n - i + 1) / i;
  }
  printf("%d", sol);
  return 0;
}
