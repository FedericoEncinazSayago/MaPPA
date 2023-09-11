#ifndef ESTRUCUTRAS_KERNEL_H_
#define ESTRUCUTRAS_KERNEL_H_

#include <stdint.h>
#include <commons/collections/list.h>

typedef struct { // Todavia no se si esto se va a quedar aca! 
    char* ip_memoria;
    uint8_t puerto_memoria;
    char* ip_fs;
    uint8_t puerto_fs;
    char* ip_cpu;
    uint8_t puerto_cpu_ds;
    uint8_t puerto_cpu_it;
    char* alg_planificacion;
    uint8_t quantum;
    t_list* recursos;
    t_list* inst_recursos;
    uint8_t grado_multip;

} t_config_k;

#endif 