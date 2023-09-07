#include "fs_config.h"

int main(int argc, char* argv[]) {
    atexit(cleanup);

    if(argc < 2){
        fprintf(stderr,__ERROR,__FILE__,__LINE__,argv[0]);
        exit(EXIT_FAILURE);
    }

    CHECK_NULL(config = config_create(argv[1]));
    CHECK_NULL(logger = iniciar_logger(argv[2],ENUM_CPU, false));

    CHECK_INT(server = init_server(config, "FILE SYSTEM", "PUERTO_ESCUCHA", logger));
    
    exit(EXIT_SUCCESS);
}