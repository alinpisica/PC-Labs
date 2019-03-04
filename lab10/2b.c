#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100

typedef struct {
  unsigned char a;
} multime;

void init(multime *m) {
  m->a = 0;
}

void add(multime *m, int x) {
  unsigned char mask = 1;
  mask = mask << x;
  m->a = m->a | mask;
}

void del(multime *m, int x) {
  unsigned char mask = 1;
  mask = mask << x;
  m->a = m->a ^ mask;
}

int contains(multime *m, int x) {
  if (m->a & (1 << x)) {
    return 1;
  }
  return 0;
}

void print(multime *m) {
  unsigned char mask = 1;
  for (int i = 0; i < 8; i++) {
    if (contains(m, i)) {
      printf("%d ", i);
    }
  }
  printf("\n");
}

int main() {
  multime m;
  init(&m);
  char a; int t;
  while (scanf("%c", &a)) {
    if (a == 'P') {
      print(&m);
      continue;
    }
    if (a == 'A') {
      scanf("%d", &t);
      add(&m, t);
      continue;
    }
    if (a == 'D') {
      scanf("%d", &t);
      del(&m, t);
      continue;
    }
    if (a == 'C') {
      scanf("%d", &t);
      if (contains(&m, t)) {
        printf("DA\n");
      } else {
        printf("NU\n");
      }
    }
  }
  return 0;
}

