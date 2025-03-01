#include <stdio.h>

int main(void)
{
    // Array of numbers
    int numbers[] = {6, 4, 3, 1, 9, 7, 0, 8, 2, 5};
    printf("Before sorting\n");
    printf("numbers = ");
    printf("[ %d,", numbers[0]);
    printf(" %d,", numbers[1]);
    printf(" %d,", numbers[2]);
    printf(" %d,", numbers[3]);
    printf(" %d,", numbers[4]);
    printf(" %d,", numbers[5]);
    printf(" %d,", numbers[6]);
    printf(" %d,", numbers[7]);
    printf(" %d,", numbers[8]);
    printf(" %d]\n", numbers[9]);
    // For i from 0 to n-1
    for (int i = 0; i < 10; i++)
    {
        int temp = numbers[i];
        int temp_pos = i;
        // Find the smallest number between numbers[i] and numbers[n-1]
        for (int j = i+1; j < 10; j++)
        {
            if (temp > numbers[j])
            {
                temp = numbers[j];
                temp_pos = j;
            }
        }
        numbers[temp_pos] = numbers[i];
        numbers[i] = temp;
    }
    printf("After sorting\n");
    printf("numbers = ");
    printf("[ %d,", numbers[0]);
    printf(" %d,", numbers[1]);
    printf(" %d,", numbers[2]);
    printf(" %d,", numbers[3]);
    printf(" %d,", numbers[4]);
    printf(" %d,", numbers[5]);
    printf(" %d,", numbers[6]);
    printf(" %d,", numbers[7]);
    printf(" %d,", numbers[8]);
    printf(" %d]\n", numbers[9]);
}


// numbers = {6, 4, 3, 1, 9, 7, 0, 8, 2, 5}
// int tmp = numbers[0] = 6; int tmp_pos = i = 0;
// 6 > 4 -> tmp = 4, tmp_pos = 1;
// tmp(4) > 3 -> tmp = 3, tmp_pos = 2;
// tmp(3) > 1 -> tmp = 1
// tmp(1) < 9 -> tmp = 1
// ......
// tmp = 0, tmp_pos = 6;
// After inner loop;
// number[tmp_pos] = number[i];
// number[i] = tmp;
