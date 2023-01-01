#include "Trie.h"
#define ALPH_SIZE 256

TrieNode::TrieNode(){
    children = new TrieNode*[ALPH_SIZE];
    word_freq_list = NULL;

    for (int i = 0; i < ALPH_SIZE;i++){
        children[i] = NULL;
    }
    is_end = false;
}

TrieNode::~TrieNode(){
  if(children!=NULL){
    delete(children);
  }
    
  if(word_freq_list=NULL){
    delete(word_freq_list);
  }
}

void TrieNode::increment_word_frequency(int id){
  if (word_freq_list == NULL)
    word_freq_list = new WordFreqList();
  word_freq_list->add(id);
}

Trie::Trie() : root(new TrieNode()){};
Trie::~Trie(){
    if(root=NULL)
        delete(root);
}

void Trie::insert(char* word, int id){
    int word_length = strlen(word);
    TrieNode* curr = root;

    for (int i = 0; i < word_length; i++){
        int key = word[i];
        if(curr->get_child(key)==NULL)
            curr->set_child(key, new TrieNode());
        curr = curr->get_child(key);
    }

    curr->set_is_end(true);

    curr->increment_word_frequency(id);
}