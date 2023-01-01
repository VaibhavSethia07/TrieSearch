#include "WordFreq.h"

using namespace std;

WordFreqListNode::WordFreqListNode(int id) : doc_id(id), freq(1),next(NULL){}

WordFreqListNode::~WordFreqListNode(){ free(next); }

WordFreqList::WordFreqList() : head(NULL){}

WordFreqList::~WordFreqList(){ free(head); }

void WordFreqList::add(int doc_id){
    WordFreqListNode* head = get_head();
    if (head == NULL)
    {
        head = new WordFreqListNode(doc_id);
        return;
    }

    WordFreqListNode *curr = head;
    while(curr!=NULL){
        if(curr->get_doc_id()==doc_id){
            curr->increase_freq_by_one();
            return;
        }
        curr = curr->get_next_node();
    }

    WordFreqListNode* new_node = new WordFreqListNode(doc_id);
    new_node->set_next_node(head);
    set_head(new_node);
}