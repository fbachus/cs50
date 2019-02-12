// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
//#include <cs50.h>


#include "dictionary.h"

Trie * dict;
bool loaded = false;
unsigned int dictsize = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    Trie * crawler = dict;
    int i = 0;
    int wordchar;
    while (word[i] != '\0')
    {
        wordchar = chartoind(word[i]);
        if (crawler->Branch[wordchar] == NULL) return false;
        crawler = crawler->Branch[wordchar];
        i++;
    }
    if (crawler->eow == true) return true;
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary) //fin
{
    FILE * fileptr = fopen(dictionary, "r");
    dict = newBranch();

    if (!dict || !fileptr) return false;

    Trie * crawler = dict;

    char chara = fgetc(fileptr);
    int trieindex;

    while (chara != EOF)
    {
        for(chara = fgetc(fileptr); chara != '\n'; chara = fgetc(fileptr))
        {
            trieindex = chartoind(chara);
            if (crawler->Branch[trieindex] == NULL) crawler->Branch[trieindex] = newBranch();
            crawler = crawler->Branch[trieindex];
        }
        crawler->eow = true;
        crawler = dict;
        dictsize++;
        chara = fgetc(fileptr);
    }
    loaded = true;
    fclose(fileptr);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return dictsize;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void) //fin
{
    if (free_trie(dict))
    {
        return true;
    }
    else return false;
}

bool free_trie(Trie *chain)
{
    for(int i = 0; i < 26; i++)
    {
        if (chain->Branch[i] == NULL) continue;
        free_trie(chain->Branch[i]);
    }
    free(chain);
    return true;
}

int chartoind(char c) //fin?
{
    if (c >= 'a' && c <= 'z') return (c-97);
    if (c >= 'A' && c <= 'Z') return (c-65);
    if (c == '\'') return (26); //ASCII #39 is '
    return 'F';
}

Trie *newBranch(void) //fin?
{
    Trie * branchptr = calloc(1, sizeof(Trie));
    branchptr->eow = false;
    return branchptr;
}
