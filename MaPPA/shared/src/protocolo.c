#include "../include/protocolo.h"

t_paquete* crear_paquete(op_code operacion) {
	t_paquete* paquete = malloc(sizeof(t_paquete));
    paquete->codigo_operacion = operacion;
	crear_buffer(paquete);
	return paquete;
}

void crear_buffer(t_paquete* paquete) {
	paquete->buffer = malloc(sizeof(t_buffer));
	paquete->buffer->size = 0;
	paquete->buffer->stream = NULL;
}

void agregar_a_paquete(t_paquete* paquete, void* valor, int tamanio) {
	paquete->buffer->stream = realloc(paquete->buffer->stream, paquete->buffer->size + tamanio + sizeof(int));

	memcpy(paquete->buffer->stream + paquete->buffer->size, &tamanio, sizeof(int));
	memcpy(paquete->buffer->stream + paquete->buffer->size + sizeof(int), valor, tamanio);

	paquete->buffer->size += tamanio + sizeof(int);
}

void enviar_paquete(t_paquete* paquete, int socket_cliente) {
	int bytes = paquete->buffer->size + 2 * sizeof(int);
	void* a_enviar = serializar_paquete(paquete, bytes);

	send(socket_cliente, a_enviar, bytes, 0);

	free(a_enviar);
}

void* serializar_paquete(t_paquete* paquete, int bytes) {
	void * magic = malloc(bytes);
	int desplazamiento = 0;

	memcpy(magic + desplazamiento, &(paquete->codigo_operacion), sizeof(int));
	desplazamiento+= sizeof(int);
	memcpy(magic + desplazamiento, &(paquete->buffer->size), sizeof(int));
	desplazamiento+= sizeof(int);
	memcpy(magic + desplazamiento, paquete->buffer->stream, paquete->buffer->size);
	desplazamiento+= paquete->buffer->size;

	return magic;
}

void eliminar_paquete(t_paquete* paquete) {
	free(paquete->buffer->stream);
	free(paquete->buffer);
	free(paquete);
}

void* recibir_buffer(int* size, int socket_cliente) {
	void * buffer;

	recv(socket_cliente, size, sizeof(int), MSG_WAITALL);
	buffer = malloc(*size);
	recv(socket_cliente, buffer, *size, MSG_WAITALL);

	return buffer;
}

void send_contexto_ejecucion(op_code operacion, int socket_cliente, t_pcb* proceso) {
    t_paquete* paquete = crear_paquete(operacion);
    agregar_a_paquete_PCB(paquete, proceso);
    agregar_a_paquete_registros(paquete, proceso->registros);
    agregar_a_paquete_archivos_abiertos(paquete, proceso->archivos_abiertos);

    enviar_paquete(paquete, socket_cliente);
    eliminar_paquete(paquete);
}

void agregar_a_paquete_PCB(t_paquete* paquete, t_pcb* proceso) {
    agregar_a_paquete(paquete, &proceso->pid, sizeof(int));
    agregar_a_paquete(paquete, &proceso->program_counter, sizeof(int));
}

void agregar_a_paquete_registros(t_paquete* paquete, t_registros_cpu* registros) {
    agregar_a_paquete(paquete, &registros->AX, sizeof(uint32_t));
    agregar_a_paquete(paquete, &registros->BX, sizeof(uint32_t));
    agregar_a_paquete(paquete, &registros->CX, sizeof(uint32_t));
    agregar_a_paquete(paquete, &registros->DX, sizeof(uint32_t));
}

void agregar_a_paquete_archivos_abiertos(t_paquete* paquete, t_list* archivos_abiertos) {
    int cantidad_archivos = list_size(archivos_abiertos);

    for(int i = 0; i < cantidad_archivos; i++) {
        char* archivo = list_get(archivos_abiertos, i);
        agregar_a_paquete(paquete, archivo, strlen(archivo) + 1);
    }
}

t_pcb* rcv_contexto_ejecucion(int socket_cliente) {
    t_pcb* proceso = malloc(sizeof(t_pcb));
    proceso->registros = malloc(sizeof(t_registros_cpu));
    proceso->archivos_abiertos = list_create();

    // PCB -> PID, PC, Registros, Archivos abiertos

    int desplazamiento = 0;
    void* buffer = recibir_buffer(&size, socket_cliente);

    memcpy(&proceso->pid, buffer + desplazamiento, sizeof(int));
    desplazamiento += sizeof(int);

    memcpy(&proceso->program_counter, buffer + desplazamiento, sizeof(int));
    desplazamiento += sizeof(int);

    memcpy(&proceso->registros->AX, buffer + desplazamiento, sizeof(uint32_t));
    desplazamiento += sizeof(uint32_t);

    memcpy(&proceso->registros->BX, buffer + desplazamiento, sizeof(uint32_t));
    desplazamiento += sizeof(uint32_t);

    memcpy(&proceso->registros->CX, buffer + desplazamiento, sizeof(uint32_t));
    desplazamiento += sizeof(uint32_t);

    memcpy(&proceso->registros->DX, buffer + desplazamiento, sizeof(uint32_t));
    desplazamiento += sizeof(uint32_t);

    int tamanio;

    while(desplazamiento < size) {
        memcpy(&tamanio, buffer + desplazamiento, sizeof(int));
        desplazamiento += sizeof(int);

        char* archivo = malloc(tamanio);
        memcpy(archivo, buffer + desplazamiento, tamanio);
        desplazamiento += tamanio;

        list_add(proceso->archivos_abiertos, archivo);
    }

    free(buffer);
    return proceso;
}


