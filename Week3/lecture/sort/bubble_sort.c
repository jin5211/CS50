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
    printf("==============================================\n");
    int cnt = 1;
    while (1)
    {
        int swap_cnt = 0;
        for (int i = 0; i < 9; i++)
        {
            if (numbers[i] > numbers[i+1])
            {
                int tmp = numbers[i+1];
                numbers[i+1] = numbers[i];
                numbers[i] = tmp;
                swap_cnt++;
            }
        }
        printf("cnt = %d\n", cnt);
        printf("swap_cnt = %d\n", swap_cnt);
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
        printf("==============================================\n");
        cnt++;
        if (swap_cnt == 0)
        {
            break;
        }
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

    return 0;
}
