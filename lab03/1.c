#include <stdio.h>

int main() {
  for (int i = 32; i <= 127; i+= 10) {
    for (int ch = i; ch < i + 10; ch++) {
      printf("%c = %d ", ch, ch);
    }
    printf("\n");
  }
  return 0;
}

