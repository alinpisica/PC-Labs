#include <stdio.h>

int main() {
  int v[101], n, pos = 0, neg = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  for (int i = 0; i < n; i++) {
    if (v[i] < 0) {
      neg++;
    } else if (v[i] > 0) {
      pos++;
    }
  }
  printf("Sunt %d numere pozitive si %d numere negative.\n", pos, neg);
  return 0;
}
