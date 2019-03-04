#include <stdio.h>

int main() {
  int n, v[101];
  int smax = -2e9, posmax = 0, lmax = 1, currlen = 1, currsum, currpos = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  currsum = v[0];
  for (int i = 1; i < n; i++) {
    currsum += v[i];
    currlen++;
    if (currsum > smax) {
      smax = currsum;
      posmax = currpos;
      lmax = currlen;
    } 
    if (currsum < 0) {
      currsum = v[i];
      currlen = 1;
      currpos = i;
    }
  }
  for (int i = posmax; i < posmax + lmax; i++) {
    printf("%d ", v[i]);
  }
  return 0;
}

