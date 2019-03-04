#include <stdio.h>

int main() {
  int n, v[101][101];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &v[i][j]);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = n - i; j < n; j++) {
      printf("%d ", v[j][i]);  
    }
  }
  return 0;
}

