#include <stdio.h>

// main関数以外の関数のプロトタイプの宣言
void sort(int list[], int size);
void printArray(int arr[], int size);

int main(void)
{
    // 整数型の配列
    int numbers[] = {6, 4, 3, 1, 9, 7, 0, 8, 2, 5};
    // 配列の要素数
    int size = sizeof(numbers) / sizeof(numbers[0]);

    // 整列前の配列の表示
    printf("整列前の配列の表示\n");
    printArray(numbers, size);

    // 配列を整列する
    sort(numbers, size);

    // 整列後の配列の表示
    printf("整列後の配列の表示\n");
    printArray(numbers, size);

    return 0;
}

void sort(int list[], int size) // 引数に整列対象の配列を受け取る
{
    int tmp; // 入替の退避用
    for (int i = 0; i < size-1; i++)
    {
        int swap_cnt = 0; // 入替え回数をカウントする変数を0で初期化する
        for (int j = 0; j < size-i-1; j++)
        {
            if (list[j] > list[j+1])
            {
                tmp = list[j];
                list[j] = list[j+1];
                list[j+1] = tmp;
                swap_cnt++; // 入替え回数をカウントする
            }
        }
        // 前回の繰り返し処理で入替えが一回も発生しなかった場合、
        // 整列済みと認識し無限ループから出る処理
        if (swap_cnt == 0)
        {
            break;
        }
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}
