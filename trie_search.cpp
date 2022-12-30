#include "TrieSearch.h"

using namespace std;
#define no_of_args 5

int main(int argc, char **argv){

    if(argc!=no_of_args || strcmp(argv[1],"-d") || strcmp(argv[3],"-k")){
        cout << "Wrong set of arguments\n";
        exit(1);
    }

    int line_counter = 0;
    int max_line_length = -1;
    int k = atoi(argv[4]);

    if(read_sizes(&line_counter, &max_line_length, argv[2])==-1){
        exit(1);
    }

    return 0;
}