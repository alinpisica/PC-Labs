#include <stdio.h>

int main() {
  int n, counter;
  float x, sx = 0;
  float y, sy = 0;
  scanf("%d %f %f", &n, &x, &y);
  counter = n / 10;
  for (int i = 1; i <= n; i++) {
    sx += x;
    sy += y;
    if (i % counter == 0) {
      printf("%f %e %f %e\n", sx, sx, sy, sy);
    }
  }
  return 0;
}
