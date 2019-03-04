#include <stdio.h>
#include <string.h>

int compare(char *a, char *b) {
  int lenA = strlen(a);
  int lenB = strlen(b);
  for (int i = 0; i < lenA && i < lenB; i++) {
    if ((int)a[i] > (int)b[i]) {
      return 1;
    }
  }  
  if (lenA == lenB) {
    return 0;
  }
  return -1;
}

int main() {
  char a[100], b[100];
  scanf("%s", a);
  scanf("%s", b);
  printf("%d", compare(a, b));
  return 0;
}

