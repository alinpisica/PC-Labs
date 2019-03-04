#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  FILE *inputFile;
  const int MaxLength = 1000;;
  char str[MaxLength];
  inputFile = fopen(argv[1], "r");
  if (inputFile == NULL) {
    printf("Eroare! Nu am putut deschide fisierul!");
  } else {
    while (fgets(str, MaxLength, inputFile) != NULL) {
      if (strstr(str, argv[2])) {
        printf("%s", str);
      }
    }
    fclose(inputFile);
  }
  return 0;
}

