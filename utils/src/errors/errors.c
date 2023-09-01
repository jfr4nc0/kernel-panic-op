#include "errors.h"

int check_arguments(int argc, char* argv[]){
    if(argc != 2){
        fprintf(stderr,"usage: %s <filename>\n",argv[0]);
        exit(-1);
    }
    return 0;
}

void cleanup(){
    printf("Bye!");
}

