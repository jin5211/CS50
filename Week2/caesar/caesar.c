#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int only_digits(string s);
int strtoint(string k);
int cipher(int key, char p);

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
    int key = strtoint(argv[1]);
    string message = get_string("plaintext: ");
    // encrypts messages using Caesar’s cipher
    printf("ciphertext: ");
    for (int i = 0, n = strlen(message); i < n; i++)
    {
        if (isalpha(message[i]))
        {
            printf("%c", cipher(key, message[i]));
        }
        else
        {
            printf("%c", message[i]);
        }
    }
    printf("\n");
    return 0;
}

int only_digits(string s)
{
    int n = strlen(s);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (isdigit(s[i]))
        {
            cnt++;
        }
    }
    if (cnt == n)
    {
        return true;
    }
    return false;
}

// function to convert string to integer
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

// function to generate encrypted letter
int cipher(int key, char p)
{
    if (isupper(p))
    {
        int c = 'A' + ((p - 'A' + key) % 26);
        return c;
    }
    else
    {
        int c = 'a' + (p - 'a' + key) % 26;
        return c;
    }
}
