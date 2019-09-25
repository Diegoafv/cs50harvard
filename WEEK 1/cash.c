#include <stdio.h>
#include <cs50.h>
#include <math.h>

int count_coins(int change);

int main()
{

    float change = 0;
    int cents = 0;
    int coins = 0;
    
    
    do 
    {
        change = get_float("Change owed: ");
    } 
    while (change < 0);
    
    cents = round(change * 100);
    
    coins = count_coins(cents);
    
    printf("%d\n", coins);
    
    return 0;
}

int count_coins(int cents)
{
    
    int cents25 = 0;
    int cents10 = 0;
    int cents5 = 0;
    int cents1 = 0;
    
    int change = cents;
    
    cents25 = change / 25;
    change = change % 25;
    
    cents10 = change / 10;
    change = change % 10;
    
    cents5 = change / 5;
    change = change % 5;
    
    cents1 = change;
    
    return cents25 + cents10 + cents5 + cents1;
}
