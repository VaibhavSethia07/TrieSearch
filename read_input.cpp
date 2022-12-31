
#include "ReadInput.h"
#include "Storage.h"

using namespace std;

int get_line_length(int full_length,int line_number){

    while(line_number>=10){
        full_length--;
        line_number /= 10;
    }

    return full_length - 4;
}

int read_sizes(int* line_counter, int* max_line_length, char* docfile){
    FILE *file = fopen(docfile, "r");

    if(file==NULL){
        cout << "Error opening the file\n";
        return -1;
    }

    char *line = NULL;
    size_t line_buffer=0;
    int full_length = 0;
    int current_length = 0;

    while ((full_length = getline(&line,&line_buffer,file))!=-1){
        current_length = get_line_length(full_length, *line_counter);

        if (current_length > *max_line_length)
            *max_line_length = current_length;

        (*line_counter)++;
        /* line_buffer when set to 0, can store as many characters as given but when set to number>0, then stores
           that many number of characters 
        */
        line_buffer = 0;
        free(line);
        line = NULL;
    }

    fclose(file);
    free(line);

    if (*line_counter==0 || *max_line_length<0){
        cout << "File is empty or has improper content formatting\n";
        return -1;
    }

    return 1;
}

int read_input(Storage* storage, char* docfile){

    FILE* file = fopen(docfile, "r");

    char* line = NULL;
    size_t line_buffer = 0;

    for (int i = 0; i < storage->get_size();i++){
        getline(&line, &line_buffer, file);

        if(storage->insert(line,i)==-1){
            printf("Document=%d does not meet the requirements\n",i);
            free(line);
            fclose(file);
            return -1;
        }
        free(line);
        line = NULL;
        line_buffer = 0;
    }

    fclose(file);

    return 1;
}