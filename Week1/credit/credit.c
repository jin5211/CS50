#include <cs50.h>
#include <stdio.h>

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
    int sum = second_last_sum + last_sum;
    return sum;
}

// カードのブランドを表示させる
void printBrand(long long cardNumber)
{
    if (cardNumber >= 340000000000000 && cardNumber <= 349999999999999)
    {
        // American Express: 15digits, starts with 34 or 37
        printf("AMEX\n");
    }
    else if (cardNumber >= 370000000000000 && cardNumber <= 379999999999999)
    {
        // American Express: 15digits, starts with 34 or 37
        printf("AMEX\n");
    }
    else if (cardNumber >= 5100000000000000 && cardNumber <= 5199999999999999)
    {
        // MasterCard: 16digits, starts with 51, 52, 53, 54 or 55
        printf("MASTERCARD\n");
    }
    else if (cardNumber >= 5200000000000000 && cardNumber <= 5299999999999999)
    {
        // MasterCard: 16digits, starts with 51, 52, 53, 54 or 55
        printf("MASTERCARD\n");
    }
    else if (cardNumber >= 5300000000000000 && cardNumber <= 5399999999999999)
    {
        // MasterCard: 16digits, starts with 51, 52, 53, 54 or 55
        printf("MASTERCARD\n");
    }
    else if (cardNumber >= 5400000000000000 && cardNumber <= 5499999999999999)
    {
        // MasterCard: 16digits, starts with 51, 52, 53, 54 or 55
        printf("MASTERCARD\n");
    }
    else if (cardNumber >= 5500000000000000 && cardNumber <= 5599999999999999)
    {
        // MasterCard: 16digits, starts with 51, 52, 53, 54 or 55
        printf("MASTERCARD\n");
    }
    else if (cardNumber >= 4000000000000 && cardNumber <= 4999999999999)
    {
        // Visa: 13 or 16 digits, starts with 4
        printf("VISA\n");
    }
    else if (cardNumber >= 4000000000000000 && cardNumber <= 4999999999999999)
    {
        // Visa: 13 or 16 digits, starts with 4
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}