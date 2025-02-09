#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int only_digits(string s);
int strtoint(string k);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else if (only_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int result = strtoint(argv[1]);
    printf("Twise of Your input is integer %i\n", result*2);
    return 0;
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

int strtoint(string k)
{
    int result = 0;
    int len = strlen(k);
    int exp = len - 1;
    for (int i = 0; i < len; i++)
    {
        result += (k[i] - '0') * (pow(10, exp));
        exp--;
    }
    return result;
}
