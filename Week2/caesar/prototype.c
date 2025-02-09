#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int cipher(int key, char p);

int main(void)
{
    int key = get_int("key: ");
    char input = get_char("Input: ");
    printf("Your input is %c\n", input);
    int output = cipher(key, input);
    printf("Your output: %c\n", output);
}

// function to generate encrypted letter
int cipher(int key, char p)
{
    if (isupper(p))
    {
        int c = 'A' + (('A' - p + key) % 26);
        return c;
    }
    else
    {
        int c = 'a' + ('a' - p + key) % 26;
        return c;
    }
}
