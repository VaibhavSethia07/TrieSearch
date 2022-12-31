#include "TrieSearch.h"

using namespace std;
#define ARG_COUNT 5

int main(int argc, char **argv){

    if(argc!=ARG_COUNT || strcmp(argv[1],"-d") || strcmp(argv[3],"-k")){
        cout << "Wrong set of arguments\n";
        exit(1);
    }

    int line_counter = 0;
    int max_line_length = -1;
    int k = atoi(argv[4]);

    if(read_sizes(&line_counter, &max_line_length, argv[2])==-1)
        exit(1);
    

    Storage *storage = new Storage(line_counter, max_line_length);
    if(read_input(storage, argv[2])==-1){
        delete (storage);
        exit(1);
    }

    for (int i = 0; i < storage->get_size();i++){
        storage->print(i);
    }

        delete (storage);
    return 0;
}

/* Install valgrid to check for memory leak
sudo apt-get install valgrind
valgrind --leak-check=yes
*/