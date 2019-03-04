#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  int n;
  int counter = 0;
  char s[20];
  int cap = 3;
  int *shows = (int*)calloc(cap, sizeof(int));
  char **words = malloc(cap * sizeof(char*));
  int appears;

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    appears = 0;
    for (int j = 0; j < counter; j++) {
        if (strcmp(s, words[j]) == 0) {
          shows[j]++;
          appears = 1;
          break;
        }
    }
    if (appears == 0) {
      if (counter + 1 == cap) {
        cap += 3;
        shows = realloc(shows, cap * sizeof(int));
        words = realloc(words, cap * sizeof(char*));
      }
      words[counter] = malloc(20);
      strcpy(words[counter], s);
      shows[counter] = 1;
      counter++;
    }
  }
  for (int i = 0; i < counter; i++) {
    printf("%s %d\n", words[i], shows[i]);
  }
  return 0;
}

