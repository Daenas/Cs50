#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int letter = 0;
int sentences = 0;
int words = 0;
float L;
float S;
int index;

int main(void)
{
    string text;
    text = get_string("Text: ");
    letter = count_letters(text);
    words = count_words(text);
    sentences = count_sentences(text);
    L = (float)letter / (float)words * 100;
    S = (float)sentences / (float)words * 100;
    index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 1 && index < 16)
    {
        printf("Grade %i\n", index);
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
}

int count_letters(string text)
{
    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 65 && text[i] <= 90 ) || (text[i] >= 97 && text[i] <= 122))
        letter++;
    }
    return letter;
}

int count_words(string text)
{
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == 32)
        words++;
    }
    return words + 1;
}

int count_sentences(string text)
{
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        sentences++;
    }
    return sentences;
}


// index = 0.0588 * L - 0.296 * S - 15.8        =        Formula
// L is the average number of letters per 100 words in the text
// S is the average number of sentences per 100 words in the text.

