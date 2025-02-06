#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int count_words(string s);
int count_letters(string s);
int count_sentences(string s);
float avg_letter(string s);
float avg_sentence(string s);
float Coleman_Liau_index(string s);

int main(void)
{
    string text = get_string("Text: ");

    // Index
    float grade = Coleman_Liau_index(text);
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", grade);
    }
}

int count_words(string s)
{
    int count = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if ((ispunct(s[i - 1]) && isspace(s[i])) || (s[i] == '\'') || (s[i] == '-') ||
            (s[i] == '\"'))
        {
            // Do nothing
        }
        else if (ispunct(s[i]) || isspace(s[i]))
        {
            count++;
        }
    }
    return count;
}

int count_letters(string s)
{
    int count = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isalpha(s[i]))
        {
            count++;
        }
    }
    return count;
}

int count_sentences(string s)
{
    int count = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            count++;
        }
    }
    return count;
}

// Coleman-Liau index.
// index = 0.0588 * L - 0.296 * S - 15.8
float avg_letter(string s)
{
    float nWords = count_words(s);
    float nLetters = count_letters(s);

    // AL is the average number of letters per 100 words
    float AL = (nLetters / nWords) * 100;
    return AL;
}

float avg_sentence(string s)
{
    float nSen = count_sentences(s);
    float nWords = count_words(s);

    // AS is the average number of sentences per 100 words in the text
    float AS = (nSen / nWords) * 100;
    return AS;
}

float Coleman_Liau_index(string s)
{
    float L = avg_letter(s);
    float S = avg_sentence(s);
    float index = 0.0588 * L - 0.296 * S - 15.8;
    return index;
}
