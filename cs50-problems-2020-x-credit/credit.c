#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int counter = 0;
    int first_sum = 0;
    int second_sum = 0;
    int first_remainder, first_if_remainder, second_if_remainder, second_remainder, total_sum;
    
    long credit_card = get_long("Credit card: ");
    long credit_card1 = credit_card;
    long credit_card2 = credit_card;

    while (credit_card2 > 0)
    {
        credit_card2 /= 10;
        counter++;
    }
    
    while (credit_card > 0)
    {
        first_remainder = credit_card % 10;
        first_sum += first_remainder;
        credit_card /= 10;
        
        second_remainder = credit_card % 10;
        second_remainder *= 2;

        if (second_remainder >= 10)
        {
            first_if_remainder = second_remainder % 10;
            second_if_remainder = second_remainder / 10;
            second_sum = second_sum + first_if_remainder + second_if_remainder;
        } 
        else 
        {
            second_sum += second_remainder;
        }
        credit_card /= 10;
    }

    total_sum = first_sum + second_sum;
    
    if (counter < 13)
    {
        printf("INVALID\n");
    } 
    else if ((total_sum % 10 == 0) && (counter == 13 || counter == 15 || counter == 16))
    {
        while (credit_card1 > 0)
        {
            credit_card1 /= 10;
            if (credit_card1 == 4)
            {
                printf("VISA\n");
                break;
            }
            if (credit_card1 >= 51 && credit_card1 <= 55)
            {
                printf("MASTERCARD\n");
                break;
            }
            if (credit_card1 == 34 || credit_card1 == 37)
            {
                printf("AMEX\n");
                break;
            }
            if (credit_card1 < 10)
            {
                printf("INVALID\n");
                break;
            }
        }
    } 
    else 
    {
        printf("INVALID\n");
    }
}

