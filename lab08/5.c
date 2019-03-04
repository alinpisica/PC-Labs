#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int n;
  int sizeOfStr = 0;
  char *str, s[100];
  scanf("%d", &n);
  scanf("%s", s);
  str = malloc(strlen(s) + 1);
  sizeOfStr = strlen(s) + 1;
  strcpy(str, s);
  for (int i = 0; i < n - 1; i++) {
    scanf("%s", s);
    if (tolower(s[0]) == tolower(str[strlen(str) - 2])
        && tolower(s[1]) == tolower(str[strlen(str) - 1])) {
      sizeOfStr += strlen(s) + 2;
      str = realloc(str, sizeOfStr * sizeof(char));
      strcat(str, "-");
      strcat(str, s);
    }
  }
  printf("%s", str);
  return 0;
}

