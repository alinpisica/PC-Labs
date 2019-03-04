#include <stdio.h>
#include <stdlib.h>

int main() {
  int *vim1, *vi, *aux;
  int n, k;
  int len = 1;
  scanf("%d %d", &n, &k);
  vim1 = malloc(len);
  vi = malloc(len + 1);
  vim1[0] = 1;
  vi[0] = 1;
  vi[1] = 1;
  len = 2;
  for (int i = 2; i <= n; i++) {
    vim1 = realloc(vim1, len);
    for (int i = 0; i < len; i++) {
      vim1[i] = vi[i];
    }
    len += 1;
    vi = realloc(vi, len);
    vi[len - 1] = 1;
    for (int i = 1; i < len - 1; i++) {
      vi[i] = vim1[i] + vim1[i - 1];
    }
  }
  printf("%d", vi[k]);
  return 0;
}

