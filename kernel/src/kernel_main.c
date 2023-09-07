#include "kernel_config.h"

int main(int argc, char* argv[]) {

    atexit(cleanup);

    if(argc < 2){
        fprintf(stderr,__ERROR,__FILE__,__LINE__,argv[0]);
        exit(EXIT_FAILURE);
    }

    CHECK_NULL(config = config_create(argv[1]));
    CHECK_NULL(logger = iniciar_logger(argv[2],ENUM_KERNEL, false));

    // Manejar las conexiones con hilos
    CHECK_INT(client_memory = build_connection(config,"MEMORIA",logger));
    CHECK_INT(client_filesystem = build_connection(config,"FILESYSTEM",logger));
    CHECK_INT(client_cpu_dispatcher = build_connection(config,"CPU_DISPATCH",logger));
    CHECK_INT(client_cpu_interrupter = build_connection(config,"CPU_INTERRUPT",logger));

    CHECK_INT(pthread_create(&p_terminal, NULL, initialize_console, NULL));

    // Espera a que el hilo pthread termine
    pthread_join(p_terminal, NULL);

    exit(EXIT_SUCCESS);
}
