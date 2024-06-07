#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // User input
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Print rows
    for (int i = 0; i < height; i++)
    {
        // Print spaces
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }

        // Print left hashes
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }

        // Print gap
        printf("  ");

        // Print right hashes
        for (int l = 0; l < i + 1; l++) 
        {
            printf("#");
        }

        // next line
        printf("\n");
    }
}