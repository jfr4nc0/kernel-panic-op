#include "kernel_config.h"

int main(int argc, char* argv[]) {

    atexit(cleanup);

    if(argc < 2){
        fprintf(stderr,__ERROR,__FILE__,__LINE__,argv[0]);
        exit(EXIT_FAILURE);
    }

    CHECK_NULL(config = config_create(argv[1]));
    CHECK_NULL(logger = iniciar_logger(argv[2],ENUM_KERNEL, false));

    //TODO Implementar conexiones con modulos CPU, File System y Memoria

    CHECK_INT(pthread_create(&p_terminal, NULL, initialize_console, NULL));

    // Espera a que el hilo pthread termine
    pthread_join(p_terminal, NULL);

    exit(EXIT_SUCCESS);
}
