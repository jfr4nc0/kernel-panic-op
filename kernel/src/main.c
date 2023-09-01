#include "console.h"
#include "kernel_config.h"

int main(int argc, char* argv[]) {

    // check_arguments(argc,argv[],2);
    t_dict

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

    return 0;
}
