#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 5;
    int y = 7;

    printf("Before swapping\n");
    printf("x : %i\n", x);
    printf("y : %i\n", y);

    // Swapping
    swap(&x, &y);

    printf("Before swapping\n");
    printf("x : %i\n", x);
    printf("y : %i\n", y);
    return(0);
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
