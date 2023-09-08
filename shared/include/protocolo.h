#ifndef PROTOCOLO_H
#define PROTOCOLO_H

#include <inttypes.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef enum {
    INICIAR_PROCESO,
    FINALIZAR_PROCESO,
    DETENER_PLANIFICACION,
    INICIAR_PLANIFICACION,
    MUTIPROGRAMACION,
    PROCESO_ESTADO,
    NEW,
    READY,
    BLOCKED,
    EXEC,
    EXIT,
    WAIT,
    SIGNAL,
    F_OPEN,
    F_CLOSE,
    F_SEEK,
    F_TRUNCATE,
    F_READ,
    F_WRITE,
} op_code;

typedef struct {
    int size;
    void *stream;
}; // Esto todavia no sé si lo vamos a usar! 

typedef struct
{
	op_code codigo_operacion;
	//t_buffer* buffer;
} t_paquete; // Esto todavia no sé si lo vamos a usar!

bool send_aprobar_operativos(int socket_servidor, uint8_t nota1, uint8_t nota2);
bool recv_aprobar_operativos(int socket_servidor, uint8_t *nota1, uint8_t *nota2);

#endif /* PROTOCOLO_H */
