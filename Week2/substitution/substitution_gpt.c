#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool check_key(string key);
string substitute_text(string text, string key);

int main(int argc, string argv[])
{
    // コマンドライン引数のチェック
    if (argc != 2 || !check_key(argv[1]))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // ユーザー入力の取得
    string plaintext = get_string("plaintext: ");

    // 変換処理
    string ciphertext = substitute_text(plaintext, argv[1]);

    // 結果の出力
    printf("ciphertext: %s\n", ciphertext);

    // メモリ解放
    free(ciphertext);

    return 0;
}

// 鍵が有効かをチェックする関数
bool check_key(string key)
{
    if (strlen(key) != 26) // 26文字であること
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }

    bool seen[26] = {false};

    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i])) // すべて英字であること
        {
            printf("Key must only contain alphabetic characters.\n");
            return false;
        }

        int index = toupper(key[i]) - 'A';
        if (seen[index]) // 重複チェック
        {
            printf("Key must not contain repeated characters.\n");
            return false;
        }
        seen[index] = true;
    }

    return true;
}

// 文字列を変換する関数
string substitute_text(string text, string key)
{
    int len = strlen(text);
    char *ciphertext = malloc(len + 1); // 動的メモリ確保
    if (ciphertext == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < len; i++)
    {
        if (isupper(text[i]))
        {
            ciphertext[i] = toupper(key[text[i] - 'A']);
        }
        else if (islower(text[i]))
        {
            ciphertext[i] = tolower(key[text[i] - 'a']);
        }
        else
        {
            ciphertext[i] = text[i]; // 記号や数字はそのまま
        }
    }
    ciphertext[len] = '\0'; // 文字列の終端を追加

    return ciphertext;
}
