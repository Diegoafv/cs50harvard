#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int height = 0;
    
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8 || height == EOF || height == '\n'); //error cases
    
    
    for (int i = height; i >= 1; i--) //for each line
    {
        for (int j = 1; j <= height; j++) //for each position in line
        {
            (j < i) ? printf(" ") : printf("#"); //prints ' ' if it's on the left side 
        }                                          // or '#' if it's on the right side
        printf("\n"); //next line
    }
    
    
    return 0;
}
