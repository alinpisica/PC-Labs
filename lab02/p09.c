#include <stdio.h>

int main() {
    int hh, mm, ss;
    printf("hh mm ss = ");
    scanf("%d %d %d", &hh, &mm, &ss);
    printf("%02d:%02d:%02d\n", hh, mm, ss);
    return 0;
}

