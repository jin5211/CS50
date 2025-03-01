#include <stdio.h>

void calc(int x, int y, int *a1, int *a2);

int main(void) {
    int array[5];
    int len = sizeof(array) / sizeof(array[0]);
    printf("%d\n", len);
}

void calc(int x, int y, int *a1, int *a2) {
    *a1 = x + y;
    *a2 = x - y;
}
