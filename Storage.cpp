#include "Storage.h"

using namespace std;

Storage::Storage(int size, int buffer_size) : size(size), buffer_size(buffer_size){
    // Allocate memory for the array of pointers to documents and their lengths
    documents = (char **)malloc(size * sizeof(char *));
    lengths = (int*)malloc(buffer_size * sizeof(int));

    for (int i = 0; i < size;i++){
        documents[i] = (char *)malloc(buffer_size * sizeof(char));
    }
}

Storage::~Storage(){
    // Deallocate memory for each document and then for the array
    for (int i = 0; i < size;i++){
        free(documents[i]);
    }

    free(documents);
    free(lengths);
}

int Storage::insert(char* line,int i){

    int curr;
    // Either space or tab
    char* token;
    token= strtok(line, " \t");
    curr = atoi(token);
    if(curr!=i){
        token = NULL;
        free(token);
        return -1;
    }

    token = strtok(NULL, "\n");
    while(token[0]==' ')
        token++;

    int end = 0;
    while (token[end] != '\0')
        end++;

    end--;
    while(end>0 && token[end]==' ')
        token[end--] = '\0';

    strcpy(documents[i],token);
    token = NULL;
    free(token);
    return 1;
}