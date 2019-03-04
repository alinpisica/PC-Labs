#include <stdio.h>

int main() {
    int inputval, valmax = -2e9, valmin = 2e9;
    for (int i = 0; i < 4; i++) {
        scanf("%d", &inputval);
        if (inputval > valmax)
            valmax = inputval;
        if (inputval < valmin)
            valmin = inputval;
    }
    printf("%d %d\n", valmin, valmax);
    return 0;
}
