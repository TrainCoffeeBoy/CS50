#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int count_letters(string text);//countrthe number of letter of text
int dup_check(string text);//check the duplication of characters
void encrypt(string text, string key);//create cipher text

int main(int argc, string argv[])
{
    if (argc != 2)//check the number of arguments
    {
        printf("Error: You must input only one argument.\n");
        return 1;
    }

    if (count_letters(argv[1]) != 26) //check the number of key(argv[1])
    {
        printf("Key must be 26 characters.\n");
        return 1;
    }

    if (dup_check(argv[1]))
    {
        printf("Every single key character should be unique.\n");
        return 1;
    }

    string plain = get_string("plaintext: ");
    printf("ciphertext: ");

    encrypt(plain, argv[1]);

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

int dup_check(string text)
{
    int i = 0;
    // conver all charater into lowercase
    while (text[i] != '\0')
    {
        text[i] = tolower(text[i]);
        i++;
    }
    //check duplicated characters
    i = 0;
    int j = 0;
    while (text[i] != '\0')
    {
        while (text[j] != '\0')
        {
            if (i != j && text[i] == text[j])
                {
                return 1;//return error
                }
            j++;
        }
        i++;
    }
    return 0;//return no error
}

//encrypt plain text by key
void encrypt(string text, string key)
{
    int i = 0;

    while (text[i] != '\0')
    {
        if(isalpha(text[i]))//for alphabet
        {
            if(isupper(text[i]))//for uppercase
            {
                printf("%c", toupper(key[text[i] - 'A']));
            }
            else//for lowercase
            {
                printf("%c", tolower(key[text[i] - 'a']));
            }
        }
        else//for non alphanet case
        {
            printf("%c", text[i]);
        }
        i++;
    }
    printf("\n");
}