#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int main(void)
{
    char c = get_char("Input: ");
    if (isalnum(c))
    {
        printf("Your input is alphanumeric.\n");
    }
    else
    {
        printf("Your input is not alphanumeric.\n");
    }
}
