/*
#ifndef CONFIG_H
#define CONFIG_H

#include <stdint.h>

typedef struct
{
    char *IP_MEMORIA;
    uint8_t PUERTO_MEMORIA;
    uint8_t PUERTO_ESCUCHA;
    char *PATH_FAT;
    char *PATH_BLOQUES;
    char *PATH_FCB;
    uint8_t CANTIDAD_BLOQUES_TOTAL;
    uint8_t CANTIDAD_BLOQUES_SWAP;
    uint8_t TAM_BLOQUES;
    uint8_t RETARDO_ACCESO_BLOQUE;
    uint8_t RETARDO_ACCESO_FAT;
} t_config_fs;

extern t_config_fs *config_fs;

#endif /* CONFIG_H */

