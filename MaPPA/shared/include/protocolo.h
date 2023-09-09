#ifndef PROTOCOLO_H_
#define PROTOCOLO_H_

#include <inttypes.h>
#include <commons/log.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef enum {
    NOTAS,
    MENSAJES,
} op_code;

// uint8_t: 1 byte - 8 bits -> 0 a 255

bool send_notas(int socket_server, uint8_t nota1, uint8_t nota2);
bool rcv_notas(int socket_server, uint8_t* nota1, uint8_t* nota2);
bool procesar_conexion(int socket_cliente, t_log* logger) ;

#endif