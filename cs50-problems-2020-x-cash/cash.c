#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float change;
    int coins = 0;
    int quarter = 25;
    int dime = 10;
    int nickle = 5;
    int penny = 1;

    //promts user and accepts only non-negative values
    do
    {
        change = get_float("Change owed: ");
    } 
    while (change < 0); 

    //convert dollars to cents and round that number to the nearest penny
    change = round(change * 100);

    //use largest coins to get fewest number of coins
    while (change >= quarter)
    {
        change -= quarter;
        coins++;
    }
    while (change >= dime)
    {
        change -= dime;
        coins++;
    }
    while (change >= nickle)
    {
        change -= nickle;
        coins++;
    }
    while (change >= penny)
    {
        change -= penny;
        coins++;
    }
    printf("%i\n", coins); 
}
