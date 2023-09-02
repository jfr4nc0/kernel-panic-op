#ifndef LOGS_H_
#define LOGS_H_

#include <stdio.h>
#include <stdlib.h>
#include <commons/log.h>
#include <errors/errors.h>

#define MOSTRAR_OCULTAR_MENSAJES_LOG_CONSOLA        1
#define MOSTRAR_OCULTAR_MENSAJES_LOG_CPU            1
#define MOSTRAR_OCULTAR_MENSAJES_LOG_FILE_SYSTEM    1
#define MOSTRAR_OCULTAR_MENSAJES_LOG_MEMORIA        1
#define MOSTRAR_OCULTAR_MENSAJES_LOG_KERNEL         1

typedef enum {
    ENUM_CPU,
    ENUM_FILE_SYSTEM,
    ENUM_KERNEL,
    ENUM_MEMORIA
}enum_modulos;

bool obtener_valores_para_logger(int moduloPos, bool *mostrarConsola, t_log_level *log_level, char* *modulo);
t_log* iniciar_logger(char* pathLog, int moduloPos, bool mostrarConsola);


#define _SERVER_STARTED "Se inicio el servidor del modulo %s, en el puerto %s"
#define E_CONFIG_PROPERTY "Propiedad inexistente en el archivo de configuracion"

#endif