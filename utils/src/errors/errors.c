#include "errors.h"

jmp_buf savebuf; // Proteger con mutex

int check_arguments(int argc, char* argv[]){
    if(argc != 2){
        fprintf(stderr,"usage: %s <filename>\n",argv[0]);
        exit(-1);
    }
    return 0;
}

void handle_exception(exception_code code, t_log* logger){
    log_error(logger, "ERROR (" __FILE__ ":%d) -- %s\n",__LINE__,strerror(errno));
}