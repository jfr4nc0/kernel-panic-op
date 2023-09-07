#ifndef KERNEL_CONFIG_H_
#define KERNEL_CONFIG_H_

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <commons/collections/dictionary.h>
#include <commons/config.h>
#include <logs/logs.h>
#include <errors/errors.h>
#include <sockets/sockets.h>

#include "console.h"

t_config* config;
t_log* logger;
int server;
int client_memory;
int client_filesystem;
int client_cpu_dispatcher;
int client_cpu_interrupter;


pthread_t p_terminal;
pthread_t p_conexion_memoria;
pthread_t p_conexion_filesystem;
pthread_t p_conexion_cpu_dispatcher;
pthread_t p_conexion_cpu_interrupter;


#endif