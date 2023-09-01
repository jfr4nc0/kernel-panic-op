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

#define CHECK_NULL(result) ({ ((result) == NULL ? \
            ({fprintf(stderr,__ERROR,__FILE__,__LINE__,strerror(errno)); \
            exit(EXIT_FAILURE);NULL;}) : (result)); })

#define CHECK_INT(result) ({ int __val = (result); (__val == -1 ? \
            ({fprintf(stderr,__ERROR,__FILE__,__LINE__,strerror(errno)); \
            exit(EXIT_FAILURE);-1;}) : __val); })

#if __STDC_VERSION__ < 201112L || __STDC_NO_ATOMICS__ == 1
#error "FATAL ERROR: Atomics not supported!"
#endif

typedef enum{
    SEGMENTATION_FAULT
}exception_code;

int check_arguments(int argc, char* argv[]);
void cleanup();

#endif