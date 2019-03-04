#include <stdio.h>

void transform(int v[], int n, int x) {
  int l = n - 1, aux;
  for (int i = 0; i < n && i < l; i++) {
    if (v[i] >= x) {
      aux = v[i];
      v[i] = v[l];
      v[l] = aux;
      l--; i--;
    }
  }
}

int main() {
  int n, x, v[100];
  scanf("%d %d", &n, &x);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  transform(v, n, x);
  for (int i = 0; i < n; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");
  return 0;
}

