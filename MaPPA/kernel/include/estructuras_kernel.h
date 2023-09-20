#ifndef ESTRUCTURAS_KERNEL_H_
#define ESTRUCTURAS_KERNEL_H_

#include <stdint.h>
#include <commons/collections/list.h>

typedef struct { // Todavia no se si esto se va a quedar aca! 
    char* ip_memoria;
    int puerto_memoria;
    char* ip_fs;
    int puerto_fs;
    char* ip_cpu;
    int puerto_cpu_ds;
    int puerto_cpu_it;
    char* algoritmo_planificacion;
    int quantum;
    char** recursos;
    int* inst_recursos;
    int grado_multip;

} t_config_k;

#endif 