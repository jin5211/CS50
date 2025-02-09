#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool check_char(string s);
bool check_duplicate(string s);
string toUpperStr(string s);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./prototype key\n");
        return 1;
    }
        // check whether key contains 26 characters or not
    else if (check_char(argv[1]) == false)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    printf("Correct keys!\n");
    return 0;
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
