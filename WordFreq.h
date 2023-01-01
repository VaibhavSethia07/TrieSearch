#include <iostream>
#include <cstdlib>
#include <cstring>

#ifndef WORDFREQ_H
#define WORDFREQ_H

class WordFreqListNode{
    int doc_id;
    int freq;
    WordFreqListNode* next;
    public:
        WordFreqListNode(int doc_id);
        ~WordFreqListNode();
        int get_doc_id() { return doc_id; }
        WordFreqListNode *get_next_node() { return next; }
        void increase_freq_by_one() { freq++; }
        void set_next_node(WordFreqListNode *node) { next = node; }
};

class WordFreqList{
    WordFreqListNode* head;
    public:
        WordFreqList();
        ~WordFreqList();
        void add(int doc_id);
        WordFreqListNode *get_head() { return head; }
        void set_head(WordFreqListNode *node) { head = node; }
    
};
#endif