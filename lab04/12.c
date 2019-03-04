#include <stdio.h>

int main() {
  int n, m;
  int v[1000001] = {0};
  int x, y, z;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &x, &y, &z);
    for (int j = x; j <= y; j++) {
      v[j] += z;
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", v[i]);
  }
  return 0;
}
