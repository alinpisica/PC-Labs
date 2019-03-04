#include <stdio.h>
#include <math.h>

double calc(double x, int k, int coef[]) {
  if (k == 0) {
    return coef[0];
  }
  return x * calc(x, k - 1, coef) + coef[k];
}

int main() {
  double x, result = 0;
  int n, coeficienti[51];
  scanf("%lf %d", &x, &n);
  n += 1;
  for (int i = 0; i < n; i++) {
    scanf("%d", &coeficienti[i]);
  }

  printf("Ca suma de termeni calculati separat: ");
  for (int i = n - 1; i >= 0; i--) {
    result += (coeficienti[i] * pow(x, n - 1 - i));
  }
  printf("%.2lf\n", result);

  printf("Prin relatie: %.2lf\n", calc(x, n - 1, coeficienti)); 
  return 0;
}

