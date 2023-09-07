#include "cpu_config.h"

int main(int argc, char* argv[]) {
    atexit(cleanup);

    if(argc < 2){
        fprintf(stderr,__ERROR,__FILE__,__LINE__,argv[0]);
        exit(EXIT_FAILURE);
    }

    CHECK_NULL(config = config_create(argv[1]));
    CHECK_NULL(logger = iniciar_logger(argv[2],ENUM_CPU, false));

    CHECK_INT(server_dispatcher = init_server(config, "CPU DISPATCHER","PUERTO_ESCUCHA_DISPATCH" , logger));
    CHECK_INT(server_interrupter = init_server(config, "CPU INTERRUPTER","PUERTO_ESCUCHA_INTERRUPT" , logger));

    exit(EXIT_SUCCESS);
}
