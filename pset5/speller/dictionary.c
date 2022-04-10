// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 18226;
int counter = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    for (node *o = table[hash(word)]; o != NULL; o = o->next)
    {
        if (strcasecmp(o->word, word) == 0)
        {
            return true;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    int k = tolower(word[0]) - 'a';
    int l = 0;
    int o = 0;
    int strl = strlen(word);
    if (strl > 1 && word[1] != 39)
    {
        l = tolower(word[1]) - 'a';

        if (strl > 2 && word[2] != 39)
        {
            o = tolower(word[2]) - 'a';

        }

    }

    return 675 * k + 25 * l + o;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    char buffer[45];
    FILE *way = fopen(dictionary, "r");

    if (way == NULL)
    {
        fclose(way);
        return false;
    }

    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    while (fscanf(way, "%s", buffer) != EOF)
    {
        counter++;
        if (table[hash(buffer)] != NULL)
        {
            node *n = malloc(sizeof(node));
            if (n == NULL)
            {

                fclose(way);
                return false;
            }
            strcpy(n->word, buffer);
            n->next = table[hash(buffer)];
            table[hash(buffer)] = n;

        }
        else
        {
            node *p = malloc(sizeof(node));
            if (p == NULL)
            {

                fclose(way);
                return false;
            }
            strcpy(p->word, buffer);
            p->next = NULL;
            table[hash(buffer)] = p;
        }
    }
    fclose(way);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO

    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            node *s = table[i];
            node *t = NULL;
            while (s != NULL)
            {
                t = s->next;
                free(s);
                s = t;
            }
            free(s);
        }
    }
    return true;
}


