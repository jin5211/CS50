#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;
    char *s = "HI!";
    printf("n : %i\n", n);
    printf("&n : %p\n", &n);
    printf("*p : %i\n", *p);
    printf("p : %p\n", p);
    printf("&p : %p\n", &p);
    printf("s : %s\n", s);
    printf("s : %p\n", s);
    printf("*s : %c\n", *s);
    printf("&s[0] : %p\n", &s[0]);
    printf("&s[1] : %p\n", &s[1]);
    printf("&s[2] : %p\n", &s[2]);
    printf("&s[3] : %p\n", &s[3]);
    printf("s[0] : %c\n", s[0]);
    printf("s[1] : %c\n", s[1]);
    printf("s[2] : %c\n", s[2]);
    printf("s[3] : %i\n", s[3]);
    printf("s[0] : %c\n", *s);
    printf("s[0] : %c\n", *(s + 1));
    printf("s[0] : %c\n", *(s + 2));
    printf("s[0] : %i\n", *(s + 3));
    printf("s : %s\n", s);
    printf("s + 1 : %s\n", s + 1);
    printf("s + 2 : %s\n", s + 2);
    printf("s + 3 : %s\n", s + 3);
    return 0;
}
