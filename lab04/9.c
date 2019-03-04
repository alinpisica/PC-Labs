#include <stdio.h>

int main() {
  int n, v[101];
  int crescator = 1, descrescator = 1, constant = 1;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  for (int i = 1; i < n; i++) {
    if (v[i - 1] > v[i]) {
      crescator = 0;
      constant = 0;
    }
    if (v[i - 1] < v[i]) {
      descrescator = 0;
      constant = 0;
    }
    if (v[i - 1] == v[i]) {
      descrescator = 0;
      crescator = 0;
    }
  }
  if (crescator) printf("crescator\n");
  else if (descrescator) printf("descrescator\n");
  else if (constant) printf("constant\n");
  else printf("neordonat\n");
  return 0;
}

