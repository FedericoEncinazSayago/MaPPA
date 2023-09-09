#ifndef CONFIG_H
#define CONFIG_H

#include <stdint.h>
#include <commons/collections/list.h>

typedef struct {
	uint8_t PUERTO_ESCUCHA;
	char * IP_FILESYSTEM;
    uint8_t PUERTO_FILESYSTEM;
    uint8_t TAM_MEMORIA;
    uint8_t TAM_PAGINA;
    char *PATH_INSTRUCCIONES;
    uint8_t RETARDO_RESPUESTA;
    char *ALGORITMO_REEMPLAZO;

} t_config_cpu;

extern t_config_cpu *config_cpu;

#endif
