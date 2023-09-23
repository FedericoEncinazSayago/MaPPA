#ifndef COMUNICACION_H_
#define COMUNICACION_H_

#include <commons/log.h>
#include <inttypes.h>
#include <pthread.h>
#include <stdio.h>
#include "../../shared/include/protocolo.h"
#include "../../shared/include/estructuras_shared.h"
#include "../../shared/include/sockets.h"

int server_escucha(t_log* logger_server, char* server_name, int socket_server);

#endif /* COMUNICACION_H_ */