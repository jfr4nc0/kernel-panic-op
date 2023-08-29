#ifndef ERRORS_H_
#define ERRORS_H_

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <commons/log.h>

// TODO: Testear CHECK
// Sirve para catchear errores genericos con informacion sobre los mismos
#define __ERROR "ERROR (%s:%d) -- %s\n" 

#define CHECK(result, logger) \
    do { \
        if ((result) == NULL || (result) == -1) { \
            log_error((logger),__ERROR,__FILE__,__LINE__,strerror(errno)); \
            exit(EXIT_FAILURE); \
            } \
    } while(0)

#if __STDC_VERSION__ < 201112L || __STDC_NO_ATOMICS__ == 1
#error "FATAL ERROR: Atomics not supported!"
#endif

typedef enum{
    SEGMENTATION_FAULT
}exception_code;

int check_arguments(int argc, char* argv[]);
#endif