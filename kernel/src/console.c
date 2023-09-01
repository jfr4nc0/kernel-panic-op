#include "console.h"

void* initialize_console(void *arg) {
    while (1) {
        char *input = readline("> ");  // Lee la entrada del usuario
        if (input) {
            add_history(input);  // Agrega la entrada al historial de readline
            printf("Has ingresado: %s\n", input);  // Realiza alguna acción con la entrada
            free(input);  // Libera la memoria asignada por readline
        }
    }
    return NULL;
}

void create_process();

void kill_process();

void create_scheduler();

void stop_scheduler();

void change_multiprogramming_degree();

void* list_process_by_pid(int);
