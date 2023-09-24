#ifndef COMUNICACION_H_
#define COMUNICACION_H_

#include <commons/log.h>
#include <inttypes.h>
#include <pthread.h>
#include <stdio.h>
#include "../../shared/include/protocolo.h"
#include "../../shared/include/estructuras_shared.h"
#include "../../shared/include/sockets.h"

void atender_conexion(t_log* logger, int cliente_socket);
void* server_escuchar(void* args);