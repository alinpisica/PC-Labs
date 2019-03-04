#include <stdio.h>

void spirala(int a[][100], int rows, int cols, int v[]) {
  int x = 0, row = rows - 1, col = 0, s = 0;
  while (row > 0 && col < cols) {
    for (int i = 0; i < rows; i++) {
      v[x] = a[i][col]; x++;
    }
    col++;
    for (int i = col; i < cols; i++) {
      v[x] = a[row][i]; x++;
    }
    row--;
    rows--;
    for (int i = row; i >= 0; i--) {
      v[x] = a[i][cols - 1]; x++;
    }
    cols--;
    for (int i = cols - 1; i > col; i--) {
      v[x] = a[0][i]; x++;
    }
  }
}

void afisare(int v[], int dim) {
  for (int i = 0; i < dim; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");
}

int main() {
  int n, m;
  int v[100][100];
  int sol[10000];
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &v[i][j]);
    }
  }
  spirala(v, n, m, sol);
  afisare(sol, m * n);
  return 0;
}

