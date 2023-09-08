/*
#ifdef COMUNICACION_H_
#define COMUNICACION_H_

#include <stdint.h>
#include <string.h>
#include <pthread.h>
#include <inttypes.h>
#include <commons/log.h>

#include "../../shared/include/sockets.h"
#include "../../shared/include/protocolo.h"

int server_escuchar(t_log* logger, char* server_name, int server_socket);

#endif /* COMUNICACION_H_ */
