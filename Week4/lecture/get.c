#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = malloc(4);
    printf("s: ");
    scanf("%s", s);
    printf("s: %s\n", s);
    free(s);
}








// int main(void)
// {
//     int n;
//     printf("n: ");
//     scanf("%i", &n);
//     printf("n: %i\n", n);
//     return 0;
// }
