#include <cs50.h>
#include <stdio.h>

int get_positive_int(void);

int main(void)
{
    int n = get_positive_int();
    
    for (int i = 1; i <= n; i++)
    {
        for (int spaces = n - i; spaces > 0; spaces--)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        for (int spaces = 0; spaces < 2; spaces++)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}

int get_positive_int(void)
{
    do
    {
        int n = get_int("Height: ");
        if (n >= 1 && n <= 8)
        {
            return n;
        }
    }
    while (true);
}

