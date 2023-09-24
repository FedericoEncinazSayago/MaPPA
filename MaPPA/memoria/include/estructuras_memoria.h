#ifndef ESTRUCTURAS_MEMORIA_H_
#define ESTRUCTURAS_MEMORIA_H_

typedef struct {
    char* ip_escucha; // IP de escucha de la memoria
    int puerto_escucha; // Puerto de escucha de la memoria
    char* ip_fs;
    int puerto_fs;
    int tam_memoria;
    int tam_pagina;
    char* path_instrucciones;
    int retardo_respuesta;
    char* algoritmo_reemplazo;
} t_config_memoria;

#endif /* ESTRUCTURAS_MEMORIA_H_ */