#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int checkalpha(string s);

int main(void)
{
    string text = get_string("Input: ");
    if (checkalpha(text) == 0)
    {
        printf("Your text contains only alphabets.\n");
    }
    else
    {
        printf("Fail.\n");
    }

}

int checkalpha(string s)
{
    int n = strlen(s);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (isalpha(s[i]))
        {
            cnt++;
        }
    }
    if (cnt != n)
    {
        return 1;
    }
    return 0;
}
