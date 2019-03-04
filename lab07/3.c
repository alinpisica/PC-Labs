#include <stdio.h>
#include <string.h>

char *strdel(char *p, int n) {
  strcpy(p, p + n);
}

char *strins(char *p, char *s) {
  char t[3000];
  strcpy(t, s);
  strcat(t, p);
  strcpy(p, t);
}

int main() {
  char str[3001], strToFind[20], strToReplace[20];
  scanf("%3000[^\n]", str);
  scanf("%s", strToFind);
  scanf("%s", strToReplace);
  char *p = str;
  while (p = strstr(p, strToFind)) {
    strdel(p, strlen(strToFind));
    strins(p, strToReplace);
    p += strlen(strToFind);
  }
  printf("%s", str);
  return 0;
}

