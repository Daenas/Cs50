#include <stdio.h>
#include <cs50.h>

int altura;

int main(void)
{
    do
    {
        altura = get_int("Qual a altura da piramide? ");
    } while (altura > 8 || altura <= 0);
    for (int i = 0; i < altura;     i++)
    {
        for (int j = 0; j < altura; j++)
        {
            if (i + j < altura - 1)
                printf(" ");
            else printf("#");
        }
        printf("\n");
    }
}
