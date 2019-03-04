#include <stdio.h>
#include <math.h>

int main() {
    double x, PI = M_PI;
    double sinx, cosx;
    printf("|       x|  sin(x)|  cos(x)|\n");
    printf("|==========================|\n");
    for (x = 0; x <= 2 * PI; x += PI / 20) {
        printf("|  +%.3f|", x);
        sinx = sin(x);
        if (sinx >= 0)
            printf("  +%.3f|", sinx);
        else 
            printf("  %.3f|", sinx);
        cosx = cos(x);
        if (cosx >= 0) 
            printf("  +%.3f|\n", cosx);
        else
            printf("  %.3f|\n", cosx);
    }
    return 0;
}
