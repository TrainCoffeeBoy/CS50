#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");//ask user to input text
    int letter = count_letters(text);
    int word = count_words(text);
    int sentence = count_sentences(text);

    //index = 0.0588 * L - 0.296 * S - 15.8
    int index = round(0.0588 * (float)letter / word * 100 - 0.296 * (float)sentence / word * 100 - 15.8);

    //decide grade
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index >= 1)
    {
        printf("Grade %d\n", index);
    }
    else
    {
        printf("Before Grade 1\n");
    }

    //printf("%d letter(s)\n", letter);
    //printf("%d word(s)\n", word);
    //printf("%d setence(s)\n", sentence);

    return 0;
}

int count_letters(string text)//countrthe number of letter of text
{
    int letter = 0;
    int i = 0;
    while (text[i] != '\0')
    {
        if (isalpha(text[i]))
        {
            letter++;
        }
        i++;
    }
    return letter;
}

int count_words(string text)//count number of space -> words (space + 1)
{
    int space = 0;
    int i = 0;
    while (text[i] != '\0')
    {
        if (isspace(text[i]))
        {
            space++;
        }
        i++;
    }
    return space + 1;
}

int count_sentences(string text)//count number of . ! ?
{
    int endmark = 0;
    int i = 0;
    while (text[i] != '\0')
    {
        if (text [i] == '.' || text[i] == '!' || text[i] == '?')
        {
            endmark++;
        }
        i++;
    }
    return endmark;
}