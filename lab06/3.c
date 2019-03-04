#include <stdio.h>

int extract(int a[], int lenA, int b[], int lenB, int c[]) {
  int lenC = 0;
  for (int i = 0; i < lenA; i++) {
    for (int j = 0; j < lenB; j++) {
      if (a[i] == b[j]) {
        c[lenC++] = a[i];
      }
    }
  }
  return lenC;
}

int main() {
  int lenA, lenB, a[1000], b[1000], c[1000];  
  scanf("%d", &lenA);
  for (int i = 0; i < lenA; i++) {
    scanf("%d", &a[i]);
  }
  scanf("%d", &lenB);
  for (int i = 0; i < lenB; i++) {
    scanf("%d", &b[i]);
  }
  int lenC = extract(a, lenA, b, lenB, c);
  printf("%d\n", lenC);
  for (int i = 0; i < lenC; i++) {
    printf("%d ", c[i]);
  }
  return 0;
}

