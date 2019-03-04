#include <stdio.h>
#include <string.h>

char *substr(char *src, int n, char *dest) {
  strncpy(dest, src, n);
  strcat(dest, "\0");
}

int main() {
  char s[101], dest[101];
  int poz, n;
  scanf("%101[^\n]", s);
  scanf("%d %d", &poz, &n);
  substr(s + poz, n, dest);
  printf("%s", dest);
  return 0;
}

