#ifndef ESTRUCTURAS_SHARED_H_
#define ESTRUCTURAS_SHARED_H_

#include <commons/log.h> 

typedef struct {
    t_log* logger;
    char* server_name;
    int socket_cliente;
} t_procesar_conexion;

#endif /* ESTRUCTURAS_SHARED_H_ */