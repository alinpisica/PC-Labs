#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VALUE 200

int cmp(const void *a, const void *b) {
  return (*(int*)a - *(int*)b);
}

int main(void) {
  int N, i;
  int *v;
  printf("Introduceti dimensiunea vectorului:\n");
  scanf("%d", &N);

  v = calloc(N, sizeof(int));
  if (!v) printf("Nu am putut aloca memorie pentru v!\n");

  srand(time(NULL));
  for (i = 0; i < N; ++i) 
    v[i] = (rand() % MAX_VALUE) + 1;
  
  for (i = 0; i < N; ++i) 
    printf("%d ", *(v + i));
  printf("\n");

  qsort(v, N, sizeof(int), cmp);

  for (i = 0; i < N; ++i)
    printf("%d ", *(v + i));
  printf("\n");

  int numberToFind;
  printf("Introduceti numarul ce doriti sa fie cautat: ");
  scanf("%d", &numberToFind);

  int *itemFound;
  itemFound = (int*)bsearch(&numberToFind, v, N, sizeof(int), cmp);
  if (itemFound != NULL) {
    printf("Elementul %d a fost gasit pe pozitia %ld.\n", numberToFind,
           (itemFound - v));
  } else {
    printf("Elementul nu a fost gasit.\n");
  }

  free(v);
  return 0;
}
