#include "sockets.h"

int init_server(t_config* config, t_log* logger) {
    int socket_server;
    char* puerto = config_get_string_value(config, "PUERTO_LOCAL");

    struct addrinfo hints, *servinfo;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    getaddrinfo(NULL, puerto, &hints, &servinfo);

    socket_server = socket(servinfo->ai_family,
           servinfo->ai_socktype,
           servinfo->ai_protocol);

    int active = 1; //Defino un true para poder pasarle el puntero al true
    setsockopt(socket_server, SOL_SOCKET, SO_REUSEADDR, &active, sizeof(active)); //Para cerrar el socket en cuanto se termine el proceso

    // Asociamos el socket a un puerto
    bind(socket_server, servinfo->ai_addr, servinfo->ai_addrlen);

    // Escuchamos las conexiones entrantes
    listen(socket_server, SOMAXCONN);

    freeaddrinfo(servinfo);

    return socket_server;
}

int wait_client(int socket_server, t_log* logger) {
    uint32_t handshake;
    // uint32_t resultOk = 0;
    // uint32_t resultError = -1;

    // Aceptamos un nuevo cliente
    int client = accept(socket_server, NULL, NULL);
    // if (client == -1) {
    //     socket_server(logger, E__CONEXION_ACEPTAR);
    //     return -1;
    // }

    log_debug(logger, "Se realiza un handshake de parte del servidor");

    recv(client, &handshake, sizeof(uint32_t), MSG_WAITALL);

    // if(handshake == 1) {
    //     send(client, &resultOk, sizeof(uint32_t), 0);
    //     socket_server(logger, HANDSHAKE, OK);
    // } else {
    //     log_error(logger, HANDSHAKE, ERROR);
    //     send(client, &resultError, sizeof(uint32_t), 0);
    // }

    return client;
}

int receive_operation(int client) {
    operation_code cod_op;
    if(recv(client, &cod_op, sizeof(operation_code), MSG_WAITALL) > 0) {
        return cod_op;
    }else {
    	close(client);
        return -1;
    }
}

void* receive_buffer(int* size, int client) {
    void* buffer;

    recv(client, size, sizeof(int), MSG_WAITALL);
    buffer = malloc(*size);
    recv(client, buffer, *size, MSG_WAITALL);

    return buffer;
}

t_list* receive_package(int client) {
    int size;
    int offset = 0;
    void * buffer;
    t_list* valores = list_create();
    int tamanio;

    buffer = receive_buffer(&size, client);
    while(offset < size)
    {
        memcpy(&tamanio, buffer + offset, sizeof(int));
        offset+=sizeof(int);
        char* valor = malloc(tamanio);
        memcpy(valor, buffer+offset, tamanio);
        offset+=tamanio;
        list_add(valores, valor);
    }
    free(buffer);
    return valores;
}

void* serialize_package(t_package* package, int bytes) {
    void * magic = malloc(bytes);
    int desplazamiento = 0;

    memcpy(magic + desplazamiento, &(package->code_operation), sizeof(int));
    desplazamiento += sizeof(int);
    memcpy(magic + desplazamiento, &(package->buffer->size), sizeof(int));
    desplazamiento += sizeof(int);
    memcpy(magic + desplazamiento, package->buffer->stream, package->buffer->size);
    desplazamiento+= package->buffer->size;

    return magic;
}

void send_package(t_package* package, int client) {
    int bytes = package->buffer->size + 2*sizeof(int);
    void* a_enviar = serialize_package(package, bytes);

    send(client, a_enviar, bytes, 0);

    free(a_enviar);
}

void send_to_package(t_package* package, void* valor, size_t tamanio) {
    package->buffer->stream = realloc(package->buffer->stream, package->buffer->size + tamanio + sizeof(int));

    memcpy(package->buffer->stream + package->buffer->size, &tamanio, sizeof(int));
    memcpy(package->buffer->stream + package->buffer->size + sizeof(int), valor, tamanio);

    package->buffer->size += tamanio + sizeof(int);
}

void send_operation(int conexion, operation_code codOperacion, size_t tamanio_valor, void* valor) {
	if (conexion > 0) {
		t_package* package = create_package(codOperacion);
		if (tamanio_valor>0) {
			send_to_package(package, valor, tamanio_valor);
		}
		send_package(package, conexion);
		free(package);
	}
}

void create_buffer(t_package* package) {
    package->buffer = malloc(sizeof(t_buffer));
    package->buffer->size = 0;
    package->buffer->stream = NULL;
}

t_package* create_package(operation_code code_operation) {
    t_package* package = malloc(sizeof(t_package));
    package->code_operation = code_operation;
    create_buffer(package);
    return package;
}