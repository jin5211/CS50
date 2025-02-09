#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool check_char(string s);
bool check_duplicate(string s);
string toUpperStr(string s);

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
        else if (check_char(argv[1]) == false)
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
                    int n =  text[k] - 'A';
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

bool check_char(string s)
{
    s = toUpperStr(s);
    int lenStr = strlen(s);
    string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int lenLets = strlen(letters);
    if (lenStr != strlen(letters))
    {
        return false;
    }
    else if (check_duplicate(s))
    {
        return false;
    }
    else
    {
        int cnt = 0;
        for (int i = 0; i < lenStr; i++)
        {
            for (int j = 0; j < lenLets; j++)
            {
                if (s[i] == letters[j])
                {
                    cnt++;
                }
            }
        }
        if (cnt == lenLets)
        {
            return true;
        }
        return false;
    }
    return false;
}



bool check_duplicate(string s)
{
    s = toUpperStr(s);
    int lenS = strlen(s);
    int nums[lenS];
    for (int i = 0; i < lenS; i++)
    {
        nums[i] = 0;
        for (int j = 0; j < lenS; j++)
        {
            if (s[i] == s[j])
            {
                nums[i]++;
            }
        }
    }
    for (int k = 0; k < lenS; k++)
    {
        if (nums[k] > 1)
        {
            return true;
        }
    }
    return false;
}

string toUpperStr(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        s[i] = toupper(s[i]);
    }
    return s;
}
