#include <stdio.h>

int main() {
  int n1, n2, v1[1001], v2[1001];
  int sorted[2002], idx1 = 0, idx2 = 0, idxs = 0;
  scanf("%d", &n1);
  for (int i = 0; i < n1; i++) {
    scanf("%d", &v1[i]);
  }
  scanf("%d", &n2);
  for (int i = 0; i < n2; i++) {
    scanf("%d", &v2[i]);
  }
  while (idx1 < n1 && idx2 < n2) {
    if (v1[idx1] < v2[idx2]) {
      sorted[idxs++] = v1[idx1++];
    } else {
      sorted[idxs++] = v2[idx2++];
    }
  }
  while (idx1 < n1) {
    sorted[idxs++] = v1[idx1++];
  }
  while (idx2 < n2) {
    sorted[idxs++] = v2[idx2++];
  }
  for (int i = 0; i < idxs; i++) {
    printf("%d ", sorted[i]);
  }
  return 0;
}

