#include "../include/protocolo.h"

// NOTAS:
static void* serializar_notas(uint8_t nota1, uint8_t nota2) { // size_t es un tipo de dato que representa el tamaño de un objeto
    void* stream = malloc(sizeof(op_code) + sizeof(uint8_t) * 2);

    op_code opereacion = NOTAS;

    memcpy(stream, &opereacion, sizeof(op_code)); // Copio el código de operación
    memcpy(stream + sizeof(op_code), &nota1, sizeof(uint8_t)); // Copio la nota 1
    memcpy(stream + sizeof(op_code) + sizeof(uint8_t), &nota2, sizeof(uint8_t)); // Copio la nota 2

    return stream; // Devuelvo el stream
}

static void deserializar_notas(void* stream, uint8_t* nota1, uint8_t* nota2) {
    memcpy(nota1, stream, sizeof(uint8_t)); // Copio la nota 1
    memcpy(nota2, stream + sizeof(uint8_t), sizeof(uint8_t)); // Copio la nota 2
}

bool send_notas(int socket_server, uint8_t nota1, uint8_t nota2) {
    size_t size = malloc(sizeof(op_code) + sizeof(uint8_t) * 2);
    void* stream = serializar_notas(nota1, nota2);

    if(send(socket_server, stream, size, 0) != size) { // send() devuelve la cantidad de bytes enviados
        free(stream);

        return false;
    }

    return true;
}

bool rcv_notas(int socket_cliente, uint8_t* nota1, uint8_t* nota2) {
    size_t size = sizeof(uint8_t) * 2;
    void* stream  = malloc(size);

    if(recv(socket_cliente, stream, size, 0) != size) // recv() devuelve la cantidad de bytes recibidos
        return false;

    deserializar_notas(stream, nota1, nota2);

    free(stream);
    return true;
}

bool procesar_conexion(int socket_cliente) {
    op_code operacion;
    size_t size = sizeof(op_code);

    if(recv(socket_cliente, &operacion, size, 0) != size)  // recv() devuelve la cantidad de bytes recibidos
        return false;

    switch(operacion) {
        case NOTAS:
            uint8_t nota1, nota2;
            
            if(!rcv_notas(socket_cliente, &nota1, &nota2))
                return false;
     
            printf("Nota 1: %d\n", nota1);
            printf("Nota 2: %d\n", nota2);
    }

    return true;
}
