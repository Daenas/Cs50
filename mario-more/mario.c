#include <cs50.h>
#include <stdio.h>



int main(void)
{
    int altura = 0;
    do{
        altura = get_int("Height: ");
    } while (altura <=0 || altura > 8);


    for (int i = 0; i < altura; i++) // linha
    {
        for (int j = 0; j < altura; j++) // coluna
        {
            if (i + j + 1 >= altura)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }

        }
    printf("  ");
    for (int j = 0; j <= i; j++)
    {
        printf("#");
    }
    printf("\n");
    }
}