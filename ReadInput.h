#include <iostream>
#include "Storage.h"
#include "Trie.h"

int read_sizes(int* line_counter, int* max_line_length, char* docfile);
int read_input(Storage *storage,Trie* trie, char *docfile);