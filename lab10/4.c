#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int **a, m, n;
} MATRICE;

MATRICE *creeaza_MATRICE(int n, int m) {
  MATRICE *mtr = malloc(sizeof(MATRICE));
  mtr->m = m;
  mtr->n = n;
  mtr->a = malloc(n * sizeof(int*));
  for (int i = 0; i < n; i++) {
    mtr->a[i] = malloc(m * sizeof(int));
  }
  return mtr;
}

MATRICE *citeste_MATRICE(MATRICE *ma) {
  for (int i = 0; i < ma->n; i++) {
    for (int j = 0; j < ma->m; j++) {
      scanf("%d", &ma->a[i][j]);
    }
  }
  return ma;
}

void scrie_MATRICE(MATRICE* ma) {
  for (int i = 0; i < ma->n; i++) {
    for (int j = 0; j < ma->m; j++) {
      printf("%d ", ma->a[i][j]);
    }
    printf("\n");
  }
}

MATRICE *aduna_MATRICE(MATRICE *ma, MATRICE *mb) {
  MATRICE *res = creeaza_MATRICE(ma->n, ma->m);
  for (int i = 0; i < ma->n; i++) {
    for (int j = 0; j < ma->m; j++) {
      res->a[i][j] = ma->a[i][j] + mb->a[i][j];
    }
  } 
  return res; 
}

MATRICE *inmulteste_MATRICE(MATRICE* ma, MATRICE* mb) {
  MATRICE *res = creeaza_MATRICE(ma->n, ma->m);
  for (int i = 0; i < ma->n; i++) {
    for (int j = 0; j < ma->m; j++) {
      res->a[i][j] = ma->a[i][j] * mb->a[i][j];
    }
  }
  return res;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  MATRICE *matrix;
  matrix = creeaza_MATRICE(n, m);  
  matrix = citeste_MATRICE(matrix);
  printf("\n");
  scrie_MATRICE(matrix);
  printf("\n");
  MATRICE *adunare = aduna_MATRICE(matrix, matrix);
  scrie_MATRICE(adunare);
  printf("\n");
  MATRICE *inmultire = inmulteste_MATRICE(matrix, matrix);
  scrie_MATRICE(inmultire);
  return 0;
}

