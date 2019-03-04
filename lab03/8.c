#include <stdio.h>
#include <math.h>

int main() {
  double x, eps, r1, r2;
  scanf("%lf %lf", &x, &eps);
  r1 = r2  = x / 2;
  do {
    r1 = r2;
    r2 = (r1 + x / r1) / 2;
  } while (fabs(r1 - r2) > eps);
  printf("%lf %lf", r1, sqrt(x));
  return 0;
}

