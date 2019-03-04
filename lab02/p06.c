#include <stdio.h>

int main() {
    float a, b, c;
    printf("a, b, c = ");
    scanf("%f %f %f", &a, &b, &c);
    if (a == b && b == c) {
        printf("echilateral");
    } else if ((a * a + b * b - c * c < 0.1) || (a * a + c * c -  b * b < 0.1) || 
               (b * b + c * c - a * a < 0.1)) {
        printf("dreptunghic ");
        if (a == b || a == c || b == c) {
            printf("isoscel");
        }
    } else if ((a == b && a != c) || (a == c && a != b) || (b == c && b != a)) {
        printf("isoscel");
    } else {
        printf("oarecare");
    }
    printf("\n");
    return 0;
}

