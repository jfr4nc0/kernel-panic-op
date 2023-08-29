#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "console.h"

int main(int argc, char* argv[]) {

    // check_arguments(argc,argv[],2);

    int server = init_server

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
