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
    int length = sizeof(numbers) / sizeof(numbers[0]);
    void merge_sort(int nums[10])
    {
        int len = sizeof(nums) /sizeof(nums[0]);
        if (len = )
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


// int numbers[] = {6, 4, 3, 1, 9, 7, 0, 8, 2, 5};
// len = sizeof(numbers) / sizeof(numbers[0])
// if only one number(len == 1)
//      quit;
// else
//      sort left half number
//      sort right half number
//      merge sorted halves


// 6, 4, 3, 1, 9(left);
//      sort left half number
// 1, 3, 4, 6, 9(left);

// 7, 0, 8, 2, 5(right);
//      sort right half number
// 0,
