// Declares a dictionary's functionality

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45
typedef struct Trie{
    bool eow;
    struct Trie * Branch[27];
}
Trie;

// Prototypes
bool check(const char *word);
bool load(const char *dictionary);
unsigned int size(void);
bool unload(void);

int chartoind(char c);
Trie *newBranch(void);
bool free_trie();

#endif // DICTIONARY_H
