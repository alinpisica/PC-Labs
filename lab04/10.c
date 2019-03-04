#include <stdio.h>

int main() {
  int n, m, a[1001], cnt;
  float v[101];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%f", &v[i]);
  }
  scanf("%d", &m);
  scanf("%d", &a[0]);
  for (int i = 1; i < m; i++) {
    scanf("%d", &a[i]);
    if (a[i] < a[i - 1]) {
      printf("Error\n");
      return 0;
    }
  }
  for (int i = 1; i < m; i++) {
    cnt = 0;
    for (int j = 0; j < n; j++) {
      if (v[j] > a[i - 1] && v[j] < a[i]) {
        cnt++;
      }
    }
    printf("%d ", cnt);
  }
  return 0;
}

