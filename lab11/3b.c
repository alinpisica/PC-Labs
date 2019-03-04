#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  FILE *inputFile;
  const int MaxLength = 1000;
  char str[MaxLength];

  int counter = 0, difference = 0, numberer = 0;
  int lineNumber = 1, totalLines = 0;
  inputFile = fopen(argv[argc - 2], "r");

  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-c") == 0) {
      counter = 1;
    } else if (strcmp(argv[i], "-i") == 0) {
      difference = 1;
    } else if (strcmp(argv[i], "-n") == 0) {
      numberer = 1;
    }
  }

  if (inputFile == NULL) {
    printf("Eroare! Nu am putut deschide fisierul!");
  } else {
    while (fgets(str, MaxLength, inputFile) != NULL) {
      char aux[MaxLength];
      strcpy(aux, str);
      if (difference == 1) {
        for (int i = 0; i < strlen(str); i++) {
          str[i] = tolower(str[i]);
        }
      }
      if (strstr(str, argv[argc - 1])) {
        if (numberer == 1) {
          printf("[%d] ", lineNumber);
        }
        lineNumber++;
        printf("%s", aux);         
        totalLines++;
      }
    }
    if (counter == 1) {
      printf("Numarul total de linii: %d", totalLines);
    }
    fclose(inputFile);
  }
  return 0;
}

