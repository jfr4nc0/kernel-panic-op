#include "logs.h"

bool obtener_valores_para_logger(int moduloPos, bool *mostrarConsola, t_log_level *log_level, char* *modulo) {
    switch(moduloPos) {
        case ENUM_KERNEL:
            *modulo = "KERNEL";
            *mostrarConsola = !!(MOSTRAR_OCULTAR_MENSAJES_LOG_KERNEL);
            *log_level = LOG_LEVEL_TRACE;
            break;
        case ENUM_CPU:
            *modulo = "CPU";
            *mostrarConsola = !!(MOSTRAR_OCULTAR_MENSAJES_LOG_CPU);
            *log_level = LOG_LEVEL_TRACE;
            break;
        case ENUM_MEMORIA:
            *modulo = "MEMORIA";
            *mostrarConsola = !!(MOSTRAR_OCULTAR_MENSAJES_LOG_MEMORIA);
            *log_level = LOG_LEVEL_TRACE;
            break;
        case ENUM_FILE_SYSTEM:
            *modulo = "FILE_SYSTEM";
            *mostrarConsola = !!(MOSTRAR_OCULTAR_MENSAJES_LOG_FILE_SYSTEM);
            *log_level = LOG_LEVEL_TRACE;
            break;
        default:
            *modulo = "LOG";
            *mostrarConsola = true;
            *log_level = LOG_LEVEL_INFO;
            return true;
    }
    return false;
}

t_log* iniciar_logger(char* pathLog, int moduloPos) {
        bool mostrarConsola = true;
        t_log_level log_level;
        char* modulo;
        bool valoresPorDefecto = obtener_valores_para_logger(moduloPos, &mostrarConsola, &log_level, &modulo);

    t_log *logger;
    char *directorioActual = getcwd();

    if (( logger = log_create(pathLog, modulo, mostrarConsola, log_level)) == NULL ) {
        // printf(cantidad_strings_a_mostrar(3), E__LOGGER_CREATE, directorioActual, ENTER);
        free(directorioActual);
        exit(1);
    }
    free(directorioActual);
    /*
    if (valoresPorDefecto) {
    	log_warning(logger, cantidad_strings_a_mostrar(4), D__LOG_CREADO, "-> ", pathLog, " con valores por defecto");
    }else {
        log_debug(logger, cantidad_strings_a_mostrar(3), D__LOG_CREADO, "-> ", pathLog);
    }
	*/
    return logger;
}