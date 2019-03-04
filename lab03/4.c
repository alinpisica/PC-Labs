#include <stdio.h>

int addSum(int number) {
  int s = 0;
  while (number) {
    s += number % 10;
    number /= 10;
  }
  return s;
}

int main() {
  int a, b;
  scanf("%d", &a);
  do {
    scanf("%d", &b);
    if (b == a % addSum(a)) {
      printf("(%d, %d)\n", a, b);
    }
    a = b;
  } while (a != 0);
  return 0;
}
