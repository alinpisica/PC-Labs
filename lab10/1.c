#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double integrala(double (*func) (double x), double a, double b, int n) {
  double step = (b - a) / n;
  double result = 0;
  for (double i = a; i <= b; i += step) {
     result += (((*func)(i) + (*func)(i + step)) * step / 2);
  }
  return result;
}

double square(double x) {
  return x * x;
}

double cosinus(double x) {
  return cos(x);
}

int main() {
  printf("f(x) = x^2, f : [0, 2] -> R: %lf\n", integrala(&square, 0, 2, 1000));
  printf("f(x) = cos(x), f : [0, PI] -> R: %lf\n", integrala(&cosinus, 0, M_PI,
                                                             1000));
  return 0;
}

