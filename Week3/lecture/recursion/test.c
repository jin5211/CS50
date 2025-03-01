#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x = 10;
    int y = ++x; // y は 11, x は 11
    int z = y++; // z は 11, y は 12
    printf("x = %d\n", x); // x = 11
    printf("y = %d\n", y); // y = 12
    printf("z = %d\n", z); // z = 11
}
