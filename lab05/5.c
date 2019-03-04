#include <stdio.h>

int factorial(int n) {
  if (n == 0) {
    return 1;
  }
  return n * factorial(n - 1);
}

double putere(double x, int n) {
  if (n == 0) {
    return 1;
  }
  return x * putere(x, n - 1);
}

double taylor(double x, int n) {
  double ex = 0;
  for (int i = 0; i < n; i++) {
    ex += putere(x, i) / factorial(i);
  }
  return ex;
}

int main() {
  double number;
  int index;
  scanf("%lf %d", &number, &index);
  printf("%.4lf", taylor(number, index));
  return 0;
}
