#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool isRepeteadCharacter();
bool isDigit();
string cipherText();

int main(int argc, string argv[])
{
    // argc - number of cmd line arguments the user typed
    // argv - argument vector - the text that user typed - the first element argv[0] and the last element argv[argc-1]

    // accepts a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // the secret key
    string k = argv[1];

    // key validation

    // the key must have 26 characters
    if (strlen(k) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    // the key and should not contain numbers
    else if (isDigit(k) == true)
    {
        printf("Key must only contain alphabetic characters.\n");
        return 1;
    }
    // the key should not contain repetead characters (case insensitive)
    else if (isRepeteadCharacter(k) == true)
    {
        printf("Key must not contain repetead characters.\n");
        return 1;
    }

    // prompts the user for plaintext
    string text = get_string("plaintext: ");

    cipherText(text, k);
}

bool isRepeteadCharacter(string text)
{
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (tolower(text[i]) == tolower(text[j]))
            {
                return true;
            }
        }
    }
    return false;
}

bool isDigit(string text)
{
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if isdigit(text[i])
        {
            return true;
        }
    }
    return false;
}

string cipherText(string text, string key)
{
    string alphabet = "abcdefghijklmnopqrstuvwxyz"; // 26 letters
    int n = strlen(text);
    char ciphertext[n];

    printf("ciphertext: ");

    // looping through the user's input text
    for (int i = 0; i < n; i++)
    {
        // if the char from the input text is equal to a letter from the alphabet,
        // then that char is replaced with the corresponding char (with the same index) from the key (upper or lower)
        if (isupper(text[i]))
        {
            for (int j = 0; j < 26; j++)
            {
                if (alphabet[j] == tolower(text[i]))
                {
                    ciphertext[i] = toupper(key[j]);
                    printf("%c", ciphertext[i]);
                }
            }
        }
        else if (islower(text[i]))
        {
            for (int j = 0; j < 26; j++)
            {
                if (alphabet[j] == text[i])
                {
                    ciphertext[i] = tolower(key[j]);
                    printf("%c", ciphertext[i]);
                }
            }
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

