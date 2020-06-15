#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string s = get_string("Text: ");

    int lettersCounter = 0, wordsCounter = 1, sentencesCounter = 0;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            lettersCounter++;
        }
        else if (s[i] == ' ')
        {
            wordsCounter++;
        }
        else if (s[i] == '!' || s[i] == '?' || s[i] == '.')
        {
            sentencesCounter++;
        }
    }

    float L = (lettersCounter * 100) / (float) wordsCounter;
    float S = (sentencesCounter * 100) / (float) wordsCounter;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}