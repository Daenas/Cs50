#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int letras;

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    letras = strlen(argv[1]);
    if (letras != 26)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }

    char key[26];
    for (int i = 0; i < 26; i++)
    {
        if (argv[1][i] >= 97)
        {
            key[i] = argv[1][i] - 32;
        }
        else
        {
            key[i] = argv[1][i];
        }
    }

    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]))
        {
            int letter = plaintext[i] - 65;
            printf("%c", key[letter]);
        }
        else if (islower(plaintext[i]))
        {
            int letter = plaintext[i] - 97;
            printf("%c", key[letter] + 32);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}