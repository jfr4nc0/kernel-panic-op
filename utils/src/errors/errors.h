#ifndef ERRORS_H_
#define ERRORS_H_

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <commons/log.h>
#include <setjmp.h>

// Usar con syscalls para saber porque rompe, strerror(errno) para breve descripcion, usar perror para abreviar

// Macro para manejar errores
// #define CHECK(X,LOG) ({void* __val = (X); t_log* __log = (LOG); (__val == (void*)-1 || __val == NULL ? \
// ({log_error(__log,"ERROR (" __FILE__ ":%d) -- %s\n",__LINE__,strerror(errno)); \
// exit(-1);-1;}) : (int)__val; })

// #define CHECK_NULL(X,LOG) ({void* __val = (X); t_log* __log = (LOG); (__val == NULL ? \
// ({log_error(__log,"ERROR (" __FILE__ ":%d) -- %s\n",__LINE__,strerror(errno)); \
// exit(-1);-1;}) : __val; })

#define TRY if ((exception_value = setjmp(savebuf)) == 0)
#define CATCH(NUM) else if (exception_value == NUM)
#define CATCHALL else
#define THROW(NUM) longjmp(savebuf, NUM)
#define HANDLE_EXCEPTION(NUM,LOG) handle_exception(NUM,LOG)

#if __STDC_VERSION__ < 201112L || __STDC_NO_ATOMICS__ == 1
#error "FATAL ERROR: Atomics not supported!"
#endif

typedef enum{
    SEGMENTATION_FAULT
}exception_code;

int check_arguments(int argc, char* argv[]);
void handle_exception(exception_code code, t_log*);
#endif