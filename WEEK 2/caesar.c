#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool valid_argv(string argument);
string codify(string plaintext, int key);

int main(int argc, string argv[])
{
    
    int key = 0; //key user input
    string plaintext = ""; //text user input
    string ciphertext = ""; //text result after code
    
    if (argc == 2) //if there's one argument only
    {
        if (valid_argv(argv[1])) //validates the text
        {
            key = atoi(argv[1]); //converts text to int
            
            plaintext = get_string("plaintext: "); //input text
            
            ciphertext = codify(plaintext, key); //codifies input text with key provided on arguments
            
            printf("ciphertext: %s\n", ciphertext);
            
            return 0;
        }
    }
    
    printf("Usage: ./caesar key\n"); //in case user didn't provide the right information
    
    return 1;

}

//validates the key provided, checks if it's a number or not
bool valid_argv(string argument)
{
    int i = 0;
    
    while (argument[i] != '\0') //reads every charactere, until the end
    {
        if (argument[i] < '0' || argument[i] > '9') //if it's not a number
        {
            return false;
        }
        i++;
    }
    
    return true; //it's a number
}

//codifies the text using a specific key
string codify(string plaintext, int key)
{
    char temp;
    string ciphertext = plaintext;
    
    for (int i = 0; ciphertext[i] != '\0'; i++)
    {
        temp = ciphertext[i]; //current position
        
        if (islower(temp)) //in case current is an lowercase letter
        {
            ciphertext[i] = ((((temp + key) - 97) % 26) + 97); //grants it works even with overflow
        }
        else if (isupper(temp)) //in case current is an uppercase letter
        {
            ciphertext[i] = ((((temp + key) - 65) % 26) + 65); //grants it works even with overflow
        }
    }
    
    return ciphertext;
}
