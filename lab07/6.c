#include <stdio.h>
#include <string.h>

char *next(char *from, char *word) {
  char *p;
  int ok;
  char *sep = " `1234567890-=[]\\;',./~!@#$%^&*()_+{}|:\"<>?";
  p = strtok(from, sep);
  while(p != NULL) {
    ok = 1;
    for (int i = 0; i < strlen(p); i++) {
      if (p[i] < 'a' || p[i] > 'z') {
        ok = 0;
        break;
      }
    }
    if (ok == 1) {
      printf("%s ", p);
    }
    p = strtok(NULL, sep);
  }
}

int main() {
  char s[101], word[101];
  scanf("%100[^\n]", s);
  next(s, word);
  return 0;
}

