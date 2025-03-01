#include <stdio.h>

void calc(int x, int y, int *a1, int *a2);

int main(void) {
    int calc1;
    int calc2;
    calc(30, 20, &calc1, &calc2);
    printf("calc1 : %d\n", calc1);
    printf("calc2 : %d\n", calc2);
    return 0;
}

void calc(int x, int y, int *a1, int *a2) {
    *a1 = x + y;
    *a2 = x - y;
}
