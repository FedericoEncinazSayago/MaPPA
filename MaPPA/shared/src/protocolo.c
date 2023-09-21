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


//SET
bool send_SET(int socket_server, uint8_t num, uint8_t num2,uint8_t res){
    size_t size = malloc(sizeof(op_code) + sizeof(uint8_t) * 3);
    void* stream = serializar_SET(num, num2,res);

    if(send(socket_server, stream, size, 0) != size) { // send() devuelve la cantidad de bytes enviados
        free(stream);

        return false;
    }

    return true;
}
static void* serializar_SET(uint8_t num, uint8_t num2,uint8_t res) { // size_t es un tipo de dato que representa el tamaño de un objeto
    void* stream = malloc(sizeof(op_code) + sizeof(uint8_t) * 3);

    op_code opereacion = SET;
    res = (num < num2) ? 1 : 0;
    memcpy(stream, &opereacion, sizeof(op_code)); // Copio el código de operación
    memcpy(stream + sizeof(op_code), &num, sizeof(uint8_t)); // Copio la nota 1
    memcpy(stream + sizeof(op_code) + sizeof(uint8_t), &num2, sizeof(uint8_t)); // Copio la nota 2
    memcpy(stream + sizeof(op_code) + sizeof(uint8_t)+sizeof(uint8_t), &res, sizeof(uint8_t)); // Copio la nota 2
    
    return stream; // Devuelvo el stream
}

static void deserializar_SET(void* stream, uint8_t* num, uint8_t* num2,uint8_t* res) {
    memcpy(num, stream, sizeof(uint8_t)); // Copio la nota 1
    memcpy(num2, stream + sizeof(uint8_t), sizeof(uint8_t));
    memcpy(res, stream + sizeof(uint8_t), sizeof(uint8_t)); // Copio la nota 2
}
bool rcv_SET(int socket_server,uint8_t* numero,u_int8_t* numero2,u_int8_t* res){
    size_t size = sizeof(uint8_t) * 3;
    void* stream  = malloc(size);

    if(recv(socket_server, stream, size, 0) != size) // recv() devuelve la cantidad de bytes recibidos
        return false;

    deserializar_SET(stream, numero, numero2,res);

    free(stream);
    return true;

}


bool procesar_conexion(int socket_cliente, t_log* logger) {
    op_code operacion;
    size_t size = sizeof(op_code);

    if(recv(socket_cliente, &operacion, size, 0) != size)  // recv() devuelve la cantidad de bytes recibidos
        return false;

    switch(operacion) {
        case NOTAS:
            uint8_t nota1, nota2;
            
            if(!rcv_notas(socket_cliente, &nota1, &nota2))
                return false;
            log_info(logger, "RECIBE INFORMACION DEL KERNEL");
            printf("Nota 1: %d\n", nota1);
            printf("Nota 2: %d\n", nota2);
        break;
        case SET:
            uint8_t num,num2,res;
            if(!rcv_SET(socket_cliente,&num,&num2,&res))
                return false;
            log_info(logger,"Recibe Informacion del Kernel");
            printf("Resultado ",res);

    }

    return true;
}
