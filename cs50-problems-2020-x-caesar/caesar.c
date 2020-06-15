#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{

    // argc - number of cmd line arguments the user typed
    // argv - argument vector - the text that user typed - the first element argv[0] and the last element argv[argc-1]

    // accepts a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // the secret key
    int k;

    // make sure all characters of the argument are digits (in ASCII 0 is 48 and 9 is 57)
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (argv[1][i] < 48 || argv[1][i] > 57)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        else
        {
            // convert the string argv[1] (the secret key) into an integer
            k = atoi(argv[1]);
        }
    }

    // prompts the user for plaintext
    string text = get_string("plaintext: ");

    // iterates through the plaintext and adds the secret key to each letter, then print the ciphertext
    printf("ciphertext: ");
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if islower(text[i])
        {
            // there are 26 letters in the alphabet
            // starts from 97 (letter a)
            printf("%c", (((text[i] + k) - 'a') % 26) + 'a');
        }
        else if isupper(text[i])
        {
            // starts from 65 (letter A)
            printf("%c", (((text[i] + k) - 'A') % 26) + 'A');
        }
        else
        {
            // if the character is not a letter, leave it and print it as it is
            printf("%c", text[i]);
        }

    }
    printf("\n");
    return 0;
}