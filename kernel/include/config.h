//#ifndef CONFIG_H
#define CONFIG_H

#include <stdint.h>
#include <commons/collections/list.h>

typedef struct {
    char *IP_MEMORIA;
    uint8_t PUERTO_MEMORIA;
    char *IP_FILESYSTEM;
    uint8_t PUERTO_FILESYSTEM;
    char *IP_CPU;
    uint8_t PUERTO_CPU_DISPATCH;
    uint8_t PUERTO_CPU_INTERRUPT;
    char *ALGORITMO_PLANIFICACION;
    uint8_t QUANTUM;
    t_list *RECURSOS;
    t_list *INSTANCIAS_RECURSOS;
    uint8_t GRADO_MULTIPROGRAMACION;

} t_config_kernel;

extern t_config_kernel *config_kernel;