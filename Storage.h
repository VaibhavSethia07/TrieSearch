#include <iostream>
#include <cstdlib>
#include <cstring>

// To avoid re-definition
#ifndef STORAGE_H
#define STORAGE_H
using namespace std;

class Storage{
    int size;   // Number of documents
    int buffer_size;    // Length of largest document
    char** documents;   // Documents
    int *lengths;   // Length of documents

    public:
        Storage(int size, int buffer_size);
        ~Storage();
        int insert(char *line, int i);
        void set_length(int id, int length) { lengths[id] = length; }
        int get_length(int id) { return lengths[id]; }
        void print(int i) { cout << i << " " << documents[i] << "\n"; }
        char* get_document(int i) { return documents[i]; }
        const int get_size() { return size; }
        const int get_buffer_size(){return buffer_size;}

};
#endif