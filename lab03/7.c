#include <stdio.h>
#include <math.h>

int main() {
  int n;
  double EPS, x;
  double s1 = 1, rez = 1, s2 = 1;
  scanf("%lf %d %lf", &x, &n, &EPS);
  for (int i = 1; i < n; i++) {
    rez *= x / i;
    s1 += rez;
  }
  rez = 1;
  for (int i = 1; ; i++) {
    rez *= x / i;
    if (rez > EPS) {
      s2 += rez;
    } else {
      break;
    }
  }
  printf("%lf %lf %lf %lf", s1, s2, exp(x), pow(2.718, x));
  return 0;
}

