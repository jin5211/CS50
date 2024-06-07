#include <cs50.h>
#include <stdio.h>

// 定数の定義
#define AMEX_MIN 340000000000000
#define AMEX_MAX 379999999999999
#define MASTERCARD_MIN 5100000000000000
#define MASTERCARD_MAX 5599999999999999
#define VISA_MIN_13 4000000000000
#define VISA_MAX_13 4999999999999
#define VISA_MIN_16 4000000000000000
#define VISA_MAX_16 4999999999999999

// Checksum関数
int checksum(long long cardNumber);

// カードのブランドを表示させる
void printBrand(long long cardNumber);

// プログラム本体
int main(void)
{
    long long cardNumber;
    do
    {
        // 入力を求める
        cardNumber = get_long("Number: ");
    }
    while (cardNumber < 0);

    if (cardNumber <= 999999999999)
    {
        // 桁数が13桁以上なければINVALIDと表示させる
        printf("INVALID\n");
    }
    else
    {
        int sum = checksum(cardNumber);

        // Checksumの結果でINVALIDなのかどうか判断する
        if (sum % 10 != 0)
        {
            printf("INVALID\n");
        }
        else
        {
            printBrand(cardNumber);
        }
    }
}

// Checksum関数
int checksum(long long cardNumber)
{
    long long tempCardNumber = cardNumber;
    int second_last_sum = 0;
    int last_sum = 0;
    int i = 0;

    while (tempCardNumber > 0)
    {
        int digit = tempCardNumber % 10;
        tempCardNumber /= 10;
        if (i % 2 == 0)
        {
            last_sum += digit;
        }
        else
        {
            digit *= 2;
            if (digit > 9)
            {
                digit = (digit / 10) + (digit % 10);
            }
            second_last_sum += digit;
        }
        i++;
    }
    return second_last_sum + last_sum;
}

// カードのブランドを表示させる
void printBrand(long long cardNumber)
{
    if ((cardNumber >= AMEX_MIN && cardNumber <= AMEX_MAX) && 
        ((cardNumber / 10000000000000 == 34) || (cardNumber / 10000000000000 == 37)))
    {
        // American Express: 15digits, starts with 34 or 37
        printf("AMEX\n");
    }
    else if (cardNumber >= MASTERCARD_MIN && cardNumber <= MASTERCARD_MAX)
    {
        // MasterCard: 16digits, starts with 51-55
        printf("MASTERCARD\n");
    }
    else if ((cardNumber >= VISA_MIN_13 && cardNumber <= VISA_MAX_13) ||
             (cardNumber >= VISA_MIN_16 && cardNumber <= VISA_MAX_16))
    {
        // Visa: 13 or 16 digits, starts with 4
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
