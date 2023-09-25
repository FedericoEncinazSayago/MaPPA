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
#include "estructuras_shared.h"

typedef enum {
    INICIAR_PROCESO,
    EJECUTAR_PROCESO,
    INTERRUPT,
    RECIBIR_PROCESO,
    DEVOLVER_PROCESO,
    MENSAJES,
} op_code;

typedef struct
{
	int size;
	void* stream;
} t_buffer;

typedef struct
{
	op_code codigo_operacion;
	t_buffer* buffer;
} t_paquete;


// uint8_t: 1 byte - 8 bits -> 0 a 255

t_paquete* crear_paquete(op_code operacion);
void crear_buffer(t_paquete* paquete);
void agregar_a_paquete(t_paquete* paquete, void* valor, int tamanio);
void enviar_paquete(t_paquete* paquete, int socket_cliente);
void* serializar_paquete(t_paquete* paquete, int bytes);
void eliminar_paquete(t_paquete* paquete);
void* recibir_buffer(int* size, int socket_cliente);

// Operaciones de CPU
void send_contexto_ejecucion(op_code operacion, int socket_cliente, t_pcb* proceso);
void agregar_a_paquete_PCB(t_paquete* paquete, t_pcb* proceso);
void agregar_a_paquete_registros(t_paquete* paquete, t_registros_cpu* registros);
void agregar_a_paquete_archivos_abiertos(t_paquete* paquete, t_list* archivos_abiertos);
void agregar_a_paquete_string(t_paquete* paquete, void* valor, int tamanio);
t_pcb* rcv_contexto_ejecucion(int socket_cliente);

#endif