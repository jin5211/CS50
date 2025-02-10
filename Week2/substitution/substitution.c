#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int check_key(string s);
int check_strlen(string s);
int check_duplicate(string s);
string toUpperStr(string s);
int check_alpha(string s);

int main(int argc, string argv[])
{
    {
        // check argc
        if (argc != 2)
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
        // check whether key contains 26 characters or not
        else if (check_key(argv[1]) != 0)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        int lenArgV1 = strlen(argv[1]);
        char upper_key[lenArgV1];
        char lower_key[lenArgV1];
        for (int i = 0; i < lenArgV1; i++)
        {
            upper_key[i] = toupper(argv[1][i]);
        }
        for (int j = 0; j < lenArgV1; j++)
        {
            lower_key[j] = tolower(argv[1][j]);
        }
        string text = get_string("plaintext: ");
        printf("ciphertext: ");
        for (int k = 0, p = strlen(text); k < p; k++)
        {
            if (isalpha(text[k]))
            {
                if (isupper(text[k]))
                {
                    int n = text[k] - 'A';
                    text[k] = upper_key[n];
                    printf("%c", text[k]);
                }
                else if (islower(text[k]))
                {
                    int m = text[k] - 'a';
                    text[k] = lower_key[m];
                    printf("%c", text[k]);
                }
            }
            else
            {
                printf("%c", text[k]);
            }
        }
        printf("\n");
        return 0;
    }
}

int check_key(string s)
{
    if (check_strlen(s) == 0)
    {
        if (check_alpha(s) == 0)
        {
            s = toUpperStr(s);
            if (check_duplicate(s) == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}

int check_strlen(string s)
{
    const int n = 26;
    if (strlen(s) != n)
    {
        return 1;
    }
    return 0;
}

int check_duplicate(string s)
{
    int lenS = strlen(s);
    int n = 0;
    for (int i = 0; i < lenS; i++)
    {
        for (int j = 0; j < lenS; j++)
        {
            if (s[i] == s[j])
            {
                n++;
            }
        }
    }
    if (n != lenS)
    {
        return 1;
    }
    return 0;
}

string toUpperStr(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        s[i] = toupper(s[i]);
    }
    return s;
}

int check_alpha(string s)
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
