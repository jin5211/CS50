#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int k = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("(%i,%i) '#'\t", i, j);  // 文字とタブを追加
            k++;
        }
        printf("\n");  // 各行の最後に改行
    }
}
