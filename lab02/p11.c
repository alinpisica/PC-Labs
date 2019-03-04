#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c, delta, x1, x2;
    printf("ax^2 + bx + c\n");
    printf("(a, b, c) = ");
    scanf("%f %f %f", &a, &b, &c);
    delta = b * b - 4 * a * c;
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                printf("Infinit\n");
            } else {
                printf("Nu exista solutii\n");
            }
        } else {
            x1 = -c / b;
            printf("%.2f\n", x1);
        }
    } else {
        if (delta < 0) {
            printf("Nu exista solutii\n");
        } else if (delta == 0) {
            x1 = (-b + sqrt(delta)) / (2 * a);
            printf("%.2f\n", x1);
        } else {
            x1 = (-b + sqrt(delta)) / (2 * a);
            x2 = (-b - sqrt(delta)) / (2 * a);
            if (x1 > x2) {
                printf("%.2f %.2f", x2, x1);
            } else {
                printf("%.2f %.2f", x1, x2);
            }
        }
    }
    return 0;
}

