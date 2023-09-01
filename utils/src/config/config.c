#include "config.h"

t_config* iniciar_config(char* pathConfig, t_log* logger) {
    t_config* nuevo_config;
    char *directorioActual = getcwd();

    free(directorioActual);
    if ((nuevo_config = config_create(pathConfig)) == NULL) {
        // log_error(logger, E__CONFIG_CREATE);
        exit(1);
    }

    //log_debug(logger, cantidad_strings_a_mostrar(3), D__CONFIG_INICIAL_CREADO, "-> ", pathConfig);
    return nuevo_config;
}