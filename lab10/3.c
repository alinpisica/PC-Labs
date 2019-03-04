#include <stdio.h>
#include <stdlib.h>

#define MAX 3

typedef struct {
  char nume[15];
  int ore_curs;
  char tip_examen;
} MATERIA;

void citire_MAT(MATERIA *m) {
  char aux[3];
  fgets(m->nume, 15, stdin);
  fgets(aux, 3, stdin);
  m->ore_curs = atoi(aux);
  fgets(&m->tip_examen, 2, stdin);
}

void citire_PROGRAMA(MATERIA *p) {
  for (int i = 0; i < MAX; i++) {
    citire_MAT(&p[i]);
  }
}

void afisare(char c, int o, MATERIA *p) {
  for (int i = 0; i < MAX; i++) {
    if (p[i].tip_examen == c && p[i].ore_curs == o) {
      printf("%s | %c | %d\n", p[i].nume, p[i].tip_examen, p[i].ore_curs);
    }
  }
}

int main() {
  MATERIA m;
  MATERIA PROGRAMA[MAX];
  citire_PROGRAMA(PROGRAMA);
  afisare('s', 5, &PROGRAMA);
  return 0;
}

