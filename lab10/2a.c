#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100

typedef struct {
  unsigned int n;
  unsigned char *a;
} multime;

void init(multime *m, int n) {
  m->n = n;
  m->a = calloc(n / 8 + 1, sizeof(m) * (n / 8 + 1));
}

void add(multime *m, int x) {
  int el = x / 8;
  unsigned char mask = 1;
  mask = mask << (x % 8);
  m->a[el] = m->a[el] | mask;
}

void del(multime *m, int x) {
  int el = x / 8;
  unsigned char mask = 1;
  mask = mask << (x % 8);
  m->a[el] = m->a[el] ^ mask;
}

int contains(multime *m, int x) {
  int el = x / 8;
  if (m->a[el] & (1 << (x % 8))) {
    return 1;
  }
  return 0;
}

void print(multime *m) {
  for (int j = 0; j < m->n; j++) {
    if (contains(m, j)) {
      printf("%d ", j);
    }
  }
  printf("\n");
}

int main() {
  int n;
  printf("n = "); scanf("%d", &n);
  multime m;
  init(&m, n);
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

