#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string answer = get_string("What's your name? ");
    if (answer[0] == '\0')
    {
        printf("hello, word\n");
        return 1;
    }
    printf("hello, %s\n", answer);
    return 0;
}
