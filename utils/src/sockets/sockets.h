#ifndef SOCKETS_H_
#define SOCKETS_H_

#include <sys/socket.h>
#include <sys/stat.h>
#include <netdb.h>
#include <string.h>
#include <commons/config.h>
#include <commons/collections/list.h>
#include <commons/log.h>
#include <commons/string.h>
#include <errors/errors.h>
#include <logs/logs.h>

typedef enum {
    TEST
}operation_code;

typedef struct buffer{
    int size;
    void* stream;
}t_buffer;

typedef struct package{
    operation_code code_operation;
    t_buffer* buffer;
}t_package;

int init_server(t_config* config, char* modulo, char* key_puerto, t_log* logger);
int wait_client(int socket_server, t_log* logger);
int build_connection(t_config* config, char* modulo, t_log* logger);
int create_connection(char *ip, char* puerto, char* modulo, t_log* logger);
int receive_operation(int client);
void* receive_buffer(int* size, int client);
t_list* receive_package(int client);
void send_package(t_package* package, int client);
void send_operation(int conexion, operation_code, size_t size_value, void* value);
void create_buffer(t_package* package);
t_package* create_package(operation_code);
void* serialize_package(t_package*, int bytes);
void add_to_package(t_package*, void* value, size_t size);

#endif