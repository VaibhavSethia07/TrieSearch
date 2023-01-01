#include <iostream>
#include <cstdlib>
#include <cstring>
#include "WordFreq.h"

#ifndef TRIENODE_H
#define TRIENODE_H

using namespace std;

class TrieNode{
    TrieNode** children=NULL;
    bool is_end;
    WordFreqList* word_freq_list;

public:
    TrieNode();
    ~TrieNode();
    void increment_word_frequency(int id);
    TrieNode* get_child(int id) { return children[id]; }
    void set_child(int id, TrieNode *node) { children[id] = node; }
    void set_is_end(bool end) { is_end = end; }
    WordFreqListNode* get_head() { return word_freq_list->get_head(); }

};

class Trie{
    TrieNode *root = NULL;
    public:
        Trie();
        ~Trie();
        void insert(char* word,int id);
};

#endif
