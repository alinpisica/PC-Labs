#include <stdio.h>

int main() {
  int s = 0;
  int n, m, p, q, a[101][101], b[101][101], c[101][101];
  scanf("%d %d", &m, &n);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  scanf("%d %d", &p, &q);
  for (int i = 0; i < p; i++) {
    for (int j = 0; j < q; j++) {
      scanf("%d", &b[i][j]);
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < q; j++) {
      s = 0;
      for (int k = 0; k < n; k++) {
        s += a[i][k] * b[k][j];
      }
      c[i][j] = s;
    }
  }

  printf("%d %d\n", m, q);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < q; j++) {
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }
  return 0;
}

