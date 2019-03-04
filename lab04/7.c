#include <stdio.h>

int main() {
  int n, v[101], lmax = 1, idxmax = 0, idxcurr = 0, currlen = 1;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  for (int i = 1; i < n; i++) {
    if (v[i] >= v[i - 1]) {
      currlen++;
    } else {
      if (currlen > lmax) {
        lmax = currlen;
        currlen = 1;
        idxmax = idxcurr;
        idxcurr = i;
      }
    }
  }
  for (int i = idxmax; i < idxmax + lmax; i++) {
    printf("%d ", v[i]);
  }
  return 0;
}

