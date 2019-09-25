#include <stdio.h>
#include <cs50.h>
#include <math.h>

bool check(long int card);
string checkBrand(long int card);

int main()
{

    long int card = 0;
    bool isValid = false;
    string brand = "none";
    
    do
    {
        card = get_long("Number: "); //get input
    }
    while (card <= 0); //rejects negative numbers
    
    
    isValid = check(card); //check if it's valid
    
    if (isValid) //valid
    {
        brand = checkBrand(card); //check brand
        printf("%s\n", brand);
    }
    else //invalid
    {
        printf("INVALID\n");
    }
    
    
    return 0;
}


//validates the number
bool check(long int card)
{
    
    long int temp = 0; //a copy of the card number
    int oddSum = 0;
    int evenSum = 0;
    int checkSum = 0; //final sum
    int tempSum = 0; //temp variable for helping with evenSum
    
    //invalidates card if number is too small or too big
    if (card > 9999999999999999 || card < 1000000000000)
    {
        return false;
    }
    
    temp = card; //card number
    
    while (temp > 0)
    {
        
        tempSum = 2 * ((temp % 100) / 10); //gets the left number of the 2 last numbers
        
        if (tempSum < 10) //single digit
        {
            evenSum = evenSum + tempSum;
        }
        else //if after x2 it has 2 digits, sums both
        {
            evenSum = evenSum + (tempSum % 10) + (tempSum / 10);
        }
        
        oddSum = oddSum + ((temp % 100) % 10); //gets the right number of the 2 last numbers
        
        temp = temp / 100; //cuts out the 2 last digits
    }
    
    checkSum = oddSum + evenSum; //sums both
    
    if (checkSum % 10 == 0) //checks if last number is 0, validates
    {
        return true;
    }
    
    return false; //in case it's not, invalidates
   
}

//checks brand
string checkBrand(long int card)
{
    //tries each window 
    if ((card >= 340000000000000 && card < 350000000000000) || (card >= 370000000000000 && card < 380000000000000))
    {
        return ("AMEX");
    }
    else if (card >= 5100000000000000 && card < 5600000000000000)
    {
        return ("MASTERCARD");
    }
    else if ((card >= 4000000000000 && card < 5000000000000) || (card >= 4000000000000000 && card < 5000000000000000))
    {
        return ("VISA");
    }
    
    return ("INVALID");
}
