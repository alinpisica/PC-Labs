#include <stdio.h>
#include <math.h>

int arie_intersectie(int x11, int y11, int x12, int y12, int x21, int y21, int
                     x22, int y22) {
  int height = 0, width = 0;
  int minX = x11;
  int maxX = x12;
  if (x21 > minX) {
    minX = x21;
  }
  if (x22 < maxX) {
    maxX = x22;
  }
  int minY = y12;
  int maxY = y11;
  if (y21 < maxY) {
    maxY = y21;
  }
  if (y22 > minY) {
    minY = y22;
  }
  width = maxX - minX;
  height = maxY - minY;
  if (width < 0 || height < 0) return 0;
  return width * height;
}

int main() {
  int a, b, c, d, e, f, g, h;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  scanf("%d %d %d %d", &e, &f, &g, &h);
  printf("%d\n", arie_intersectie(a, b, c, d, e, f, g, h));
  return 0;
}
