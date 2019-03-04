#include <stdio.h>

int main() {
    int hh, mm, ss;
    printf("hh mm ss = ");
    if (scanf("%d %d %d", &hh, &mm, &ss) == 3) {
        printf("%02d:%02d:%02d\n", hh, mm, ss);
    } else {
        printf("Date incorect introduse!\n");
    }
    return 0;
}

