#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct entry {
  void *key;
  void *value;
} entry;

typedef struct map {
  entry **elem;
  int n_elem;
  int cap;
} map;

void printEntry(const entry* s) {
  printf("%s\n", (char*)s);
}

void init(map *m, int cap) {
  m->cap = cap;
  m->n_elem = 0;
  m->elem = malloc(m->cap * sizeof(entry *));
}

void add(map *m, entry *e) {
  if (m->n_elem == m->cap) {
    m->cap = 2 * m->cap;
    m->elem = realloc(m->elem, m->cap * sizeof(entry *));
  }
  memcpy(m->elem[m->n_elem], e, sizeof(entry));
  m->n_elem++;
}

void print(map *m, void (*printEntry) (const entry*)) {
  for (int i = 0; i < m->n_elem; i++) {
    printEntry(m->elem[i]);
  }
}



int main() {
  int selecter;
  map m;
  init(&m, 32);
  do {
    printf("Introduceti optiunea: ");
    scanf("%d", &selecter);
    if (selecter == 0) {
      break;
    } else if (selecter == 1) {
      print(&m, printEntry);
    } else if (selecter == 2) {
      char k[100], val[100];
      entry en;
      printf("Introduceti cheia: ");
      scanf("%s", k);
      en.key = malloc(strlen(k) + 1);
      strcpy(en.key, k);
      getchar();
      printf("Introduceti valoarea: ");
      scanf("%s", val);
      en.value = malloc(strlen(val) + 1);
      strcpy(en.value, val);
      add(&m, &en);
    }
  } while (selecter != 0);
  return 0;
}

