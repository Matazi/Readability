#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int combine(int letters, int words, int sentences);


int main(void)
{

    string text = get_string("TEXT: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);


    int grade = combine(letters, words, sentences); // Grade level
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");

    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

// Counts the number of letters in a text
int count_letters(string text)
{
    int total = 0;
    for (int i = 0, n = strlen(text); i < n ; i++)
    {
        if (isalpha(text[i])) // Checks if character is an alphabet
        {
            total++;
        }
        else
        {

        }
    }
    return total;
}

// Counts the number of words in a text
int count_words(string text)
{
    int total = 0;
    bool start = false;
    for (int i = 0, n = strlen(text); i < n ; i++)
    {
        if( isalpha(text[i]))
        {
            start = true;
        }

        else if(isspace(text[i]) && start == true) // Checks if character is a space
        {
            total++;
            start = false;
        }
        else
        {

        }
    }
    return total + 1;
}


// Counts the number of sentences in a text
int  count_sentences(string text)
{
    int total = 0;
    for (int i = 0, n = strlen(text); i < n ; i++)
    {
        if(text[i] == 33 || text[i] == 63 || text[i] == 46)
        {
            total++;
        }
        else
        {

        }
    }
    return total;
}


// Combines the number of letters, words and sentences previously calculated
// and execute the Coleman-Liau index formula to get the grade level
int combine(int letters, int words, int sentences)
{
    float lperW = (float) letters*100 / (float) words; // The L in the Coleman-Liau formula
    float sperW = (float) sentences*100/ (float) words; // The S in the Coleman-liau formula

    float index = 0.0588 * lperW - 0.296 * sperW - 15.8;
    index = round(index);
    return index;
}
