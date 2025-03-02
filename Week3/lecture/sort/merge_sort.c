#include <stdio.h>

// main関数以外の関数のプロトタイプの宣言
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
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
    mergeSort(numbers, 0, size-1);

    // 整列後の配列の表示
    printf("整列後の配列の表示\n");
    printArray(numbers, size);

    return 0;
}

// マージソート本体
void mergeSort(int arr[], int left, int right)
{
    if (left < right) {
        int mid = left + (right - left) / 2;

        // 再帰的にソート
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // マージ
        merge(arr, left, mid, right);
    }
}

// 配列をマージする関数
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // 一時配列を作成
    int L[n1], R[n2];

    // データをコピー
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // マージ処理
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 残りの要素をコピー
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// 配列を表示する関数
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}
