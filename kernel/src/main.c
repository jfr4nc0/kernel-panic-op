#include "kernel_config.h"

int main(int argc, char* argv[]) {

    atexit(cleanup);

    if(argc < 2){
        fprintf(stderr,__ERROR,__FILE__,__LINE__,argv[0]);
        exit(EXIT_FAILURE);
    }

    CHECK_NULL(config = config_create(argv[1]));
    CHECK_NULL(logger = iniciar_logger(argv[2],ENUM_KERNEL));

    int server = init_server(config, logger);

    //TODO Implementar config inicial, leida por archivo .config
    //TODO Implementar logger
    //TODO Implementar conexiones con modulos CPU, File System y Memoria

    pthread_t p_terminal;
    if(pthread_create(&p_terminal, NULL, initialize_console, NULL) != 0){
        perror("Error al crear al hilo de consola");
        return 1;
    }
    // Espera a que el hilo pthread termine
    pthread_join(p_terminal, NULL);

    exit(EXIT_SUCCESS);
}
