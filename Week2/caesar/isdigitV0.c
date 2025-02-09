#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int only_digits(string s);

int main(void)
{
    string str = get_string("Input: ");
    if (only_digits(str))
    {
        printf("Your input is only digits.\n");
    }
    else
    {
        printf("Your input is not only digits.\n");
    }
}

int only_digits(string s)
{
    int n = strlen(s);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (isdigit(s[i]))
        cnt++;
    }
    if (cnt == n)
    {
        return true;
    }
    return false;
}
