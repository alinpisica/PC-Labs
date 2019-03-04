#include <stdio.h>

int main() {
  int glMin = 2e9, curmax, n, m, v[101][101];
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &v[i][j]);
    }
  }
  for (int i = 0; i < n; i++) {
    curmax = -2e9;
    for (int j = 0; j < m; j++) {
      if (v[i][j] > curmax) {
        curmax = v[i][j];
      }
    }
    if (curmax < glMin) {
      glMin = curmax;
    }
  }
  printf("%d\n", glMin);
  return 0;
}
