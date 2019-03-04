#include <stdio.h>

int cmmdc(int a, int b) {
  if (b == 0) {
    return a;
  }
  return cmmdc(b, a % b);
}

int cmmmc(int a, int b) {
  return a * b / cmmdc(a, b);
}

int main() {
  int x1, x2, y1, y2;
  scanf("%d %d", &x1, &x2);
  scanf("%d %d", &y1, &y2);
  int multiplu = cmmmc(x2, y2);
  printf("%d %d\n", x1 * (multiplu / x2), multiplu);
  printf("%d %d\n", y1 * (multiplu / y2), multiplu);
  return 0;
}

