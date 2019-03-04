#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_replace(char *s, char *s1, char *s2) {
  char *aux;
  int counter = 0;
  for (int i = 0; i < strlen(s); i++) {
    if (strstr(s + i, s1) == (s + i)) {
      counter++;
    }
  }
  aux = (char*)malloc((strlen(s) + counter * (strlen(s2) - strlen(s1) + 1) *
sizeof(char)));
  strcpy(aux, "");
  char charToString[2];
  charToString[1] = '\0';
  for (int i = 0; i < strlen(s); i++) {
    if (strstr(s + i, s1) == (s + i)) {
      strcat(aux, s2);
      i += strlen(s1) - 1;
      continue;
    }
    charToString[0] = s[i];
    strcat(aux, charToString);
  }
  return aux;
}

int main() {
  char *str = (char*)malloc(101 * sizeof(char));
  char *toBeReplaced = (char*)malloc(101 * sizeof(char));
  char *toReplaceWith = (char*)malloc(101 * sizeof(char));
  scanf("%[^\n]%*c", str);
  scanf("%s %s", toBeReplaced, toReplaceWith);
  printf("%s", my_replace(str, toBeReplaced, toReplaceWith));
  return 0;
}

