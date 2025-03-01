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
}

void sort(int list[], int size) // 引数に整列対象の配列を受け取る
{
    int tmp; // 入替えの退避用
    int min; // 最小値の要素番号
    // 整列対象の配列を最初から順に参照する
    for (int i = 0; i < size; i++)
    {
        min = i; // 最小値の要素番号を現在の要素番号で初期化
        // 比較対象より後の要素を順に参照する
        for (int j = i+1; j < size; j++)
        {
            // 比較対象より小さい値があれば、要素番号をminに代入する
            if (list[j] < list[min])
            {
                min = j;
            }
        }
        // 現在の要素を一旦退避して、最小値と入れ替える
        tmp = list[i];
        list[i] = list[min];
        list[min] = tmp;
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
