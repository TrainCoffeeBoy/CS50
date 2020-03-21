// Implements a dictionary's functionality
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 512;

// Hash table
node *table[N];


// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    unsigned int i = hash(word);
    node *temp = table[i];

    while (temp != NULL)
    {
        if (strcasecmp(temp->word, word) == 0)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    unsigned sum = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        sum += tolower(word[i]) - 'a';
    }
    return sum % N;
    //return tolower(word[0]) - 'a';
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");//open the dictionary
    if (file == NULL)
    {
        printf("Dictionary file cannot be opened.\n");
        return 1;
    }
    //Initialize hash table
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    char line[LENGTH + 1];
    while (1)
    {

        if (fscanf(file, "%s", line) == EOF)
        {
            fclose(file);
            return true;
        }
        else
        {
            node *n = malloc(sizeof(node));//allocate memory for each word
            if (n == NULL)
            {
                printf("Memory cannot be allcoated.\n");
                return false;
            }
            strcpy(n->word, line);
            unsigned int h = hash(line);
            n->next = table[h];
            table[h] = n;
        }
    }

    return false;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    unsigned int i = 0;
    for (int j = 0; j < N; j++)
    {
        node *temp = table[j];

        while (temp != NULL)
        {
            temp = temp->next;
            i++;
        }
    }
    return i;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO

    for (int i = 0; i < N; i++)
    {
        node *temp = table[i];

        while (temp != NULL)
        {
            node *cursor = temp->next;
            free(temp);
            temp = cursor;
        }
        if (i == N - 1)
        {
            return true;
        }
    }

    return false;
}
