#include <stdio.h>
#include <math.h>

void solveVec(double l[], double x[]) {
  double cos0 = (l[1] * l[1] + l[2] * l[2] - l[0] * l[0]) / (2 * l[1] * l[2]);
  double cos1 = (l[0] * l[0] + l[2] * l[2] - l[1] * l[1]) / (2 * l[0] * l[2]);
  double cos2 = (l[1] * l[1] + l[0] * l[0] - l[2] * l[2]) / (2 * l[0] * l[1]);
  x[0] = acos(cos0) * 180 / M_PI;
  x[1] = acos(cos0) * 180 / M_PI;
  x[2] = acos(cos0) * 180 / M_PI;
}

void solveVal(double l1, double l2, double l3, double *x1, double *x2, double *x3) {
  double cos1 = (l2 * l2 + l3 * l3 - l1 * l1) / (2 * l2 * l3);
  double cos2 = (l1 * l1 + l3 * l3 - l2 * l2) / (2 * l1 * l3);
  double cos3 = (l1 * l1 + l2 * l2 - l3 * l3) / (2 * l1 * l2);
  *x1 = acos(cos1) * 180 / M_PI;
  *x2 = acos(cos2) * 180 / M_PI;
  *x3 = acos(cos3) * 180 / M_PI;
}

int main() {
  double l1, l2, l3, x1, x2, x3;
  scanf("%lf %lf %lf", &l1, &l2, &l3);

  double l[3], x[3];
  l[0] = l1; l[1] = l2; l[2] = l3;
  solveVec(l, x);
  printf("%.3lf %.3lf %.3lf\n", x[0], x[1], x[2]);

  solveVal(l1, l2, l3, &x1, &x2, &x3);
  printf("%.3lf %.3lf %.3lf\n", x1, x2, x3);
  return 0;
}

