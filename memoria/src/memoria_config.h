#ifndef MEMORIA_CONFIG_H_
#define MEMORIA_CONFIG_H_

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <commons/collections/dictionary.h>
#include <commons/config.h>
#include <logs/logs.h>
#include <errors/errors.h>
#include <sockets/sockets.h>

t_config* config;
t_log* logger;
int server;


#endif