#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *x;
    int *y;

    x = malloc(sizeof(int));

    *x = 42;
    // *y = 13; このコードを有効にするとプログラムがクラッシュします
    // （yはポインターの定義されているが、データを格納するメモリを定義していないからです。

    printf("x : %p\n", x); // xのメモリアドレス
    printf("y : %p\n", y); // yのメモリアドレス

    printf("*x : %i\n", *x); // x : 42
    printf("*y : %i\n", *y); // y : ゴミ

    y = x;

    printf("x : %p\n", x); // xのメモリアドレス
    printf("y : %p\n", y); // yのメモリアドレス

    *y = 13;
    printf("*x : %i\n", *x); // x : 13
    printf("*y : %i\n", *y); // y : 13
}
