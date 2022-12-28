#include "trie_search.h"

using namespace std;
#define no_of_args 5

int main(int argc, char **argv){

    if(argc!=no_of_args || strcmp(argv[1],"-d") || strcmp(argv[3],"-k")){
        cout << "Wrong set of arguments\n";
        exit(1);
    }

    int line_counter = 0;
    int max_length = -1;
    int k = atoi(argv[4]);

    FILE* file = fopen(argv[2], "r");
    if(file==NULL){
        cout << "Error opening file\n";
    }
    fclose(file);

    return 0;
}