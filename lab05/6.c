#include <stdio.h>
#include <math.h>

float dist(int x1, int y1, int x2, int y2) {
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)); 
}

int main() {
  int n, vX[100], vY[100];
  int x1Max, x2Max, y1Max, y2Max;
  float distMax = 0, distCurr = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &vX[i], &vY[i]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      distCurr = dist(vX[i], vY[i], vX[j], vY[j]);
      if (distCurr > distMax) {
        distMax = distCurr;
        x1Max = vX[i];
        x2Max = vX[j];
        y1Max = vY[i];
        y2Max = vY[j];
      }
    }
  }
  printf("%d %d\n%d %d\n%f", x1Max, y1Max, x2Max, y2Max, distMax);
  return 0;
}

