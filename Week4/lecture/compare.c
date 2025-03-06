#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("s: ");
    string t = get_string("t: ");
    // printf("s = %p\n", s);
    // printf("t = %p\n", t);

    if (strcmp(s, t) == 0)
    // if (s == t)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
    return 0;
}
