#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int strScore(string s);
int charScore(char c);
bool charGroup(char c, string s);

int main(void)
{
    string str1 = get_string("Player 1: ");
    string str2 = get_string("Player 2: ");

    // Calculate the score of Player 1
    int score1 = strScore(str1);

    // Calculate the score of Player 2
    int score2 = strScore(str2);

    // Compare the scores and say either tie or who wins
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// Function to calculate the score of a word
int strScore(string s)
{
    int score = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        score += charScore(s[i]);
    }
    return score;
}

// Function to calculate the score of a letter(whether the letter is upper or not)
int charScore(char c)
{
    c = toupper(c);
    string one = "AEILNORSTU";
    string two = "DG";
    string three = "BCMP";
    string four = "FHVWY";
    string five = "K";
    string eight = "JX";
    string ten = "QZ";

    // return the point values of character
    if (charGroup(c, one))
    {
        return 1;
    }
    else if (charGroup(c, two))
    {
        return 2;
    }
    else if (charGroup(c, three))
    {
        return 3;
    }
    else if (charGroup(c, four))
    {
        return 4;
    }
    else if (charGroup(c, five))
    {
        return 5;
    }
    else if (charGroup(c, eight))
    {
        return 8;
    }
    else if (charGroup(c, ten))
    {
        return 10;
    }
    else
    {
        return 0;
    }
}

bool charGroup(char c, string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (c == s[i])
        {
            return true;
        }
    }
    return false;
}
