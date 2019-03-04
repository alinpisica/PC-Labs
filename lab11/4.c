#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  const int MAX_LENGTH = 3005;
  char table[27];
  char codifierLine[10];
  char line[MAX_LENGTH];
  FILE *src, *dest, *codifier;
  codifier = fopen(argv[1], "r");
  src = fopen(argv[2], "r");
  dest = fopen(argv[3], "w");
  if (!dest || !src || !codifier) {
    printf("Un fisier nu a putut fi deschis.");
    return 0;
  }

  for (int i = 0; i < 27; i++) {
    table[i] = '0';
  }

  while(fgets(codifierLine, 10, codifier) != NULL) {
    table[(int)(codifierLine[0] - 'a')] = codifierLine[2];
  }

  while(fgets(line, MAX_LENGTH, src) != NULL) {
    for (int i = 0; i < strlen(line); i++) {
      if (!((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <=
                                                   'Z')) ) {
        continue;
      }
      if (table[tolower(line[i]) - 'a'] != '0') {
        if (line[i] >= 'A' && line[i] <= 'Z') {
          line[i] = toupper(table[tolower(line[i]) - 'a']);
        } else {
          line[i] = table[tolower(line[i]) - 'a'];
        }
      }
    }
    fputs(line, dest);
  }

  fclose(dest);
  fclose(src);
  fclose(codifier);
  return 0;
}

