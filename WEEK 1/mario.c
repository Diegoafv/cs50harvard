#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int height = 0;
    
    do
    {
        height = get_int("Height: "); //input
    }
    while (height < 1 || height > 8 || height == EOF || height == '\n'); //error cases
    
    
    for (int i = height; i >= 1; i--) //for each line
    {
        for (int j = 1; j <= (height + 1) * 2; j++) //for each position in line, number of positions mirrored
        {
            if (j < i) //left side
            {
                printf(" "); 
            }
            else if (j > height && j <= height + 2) //middle
            { 
                printf(" ");
            }
            else if (j > height + 2 + (height - i + 1)) //right side, leaves loop
            {
                break;
            }
            else
            {
                printf("#"); //pyramid itself
            }
        }                                          
        printf("\n"); //next line
    }
    
    
    return 0;
}
