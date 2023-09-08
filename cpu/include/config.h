/*
#ifndef CONFIG_H
#define CONFIG_H

#include <stdint.h>

typedef struct
{
    char *IP_MEMORIA;
    uint8_t PUERTO_MEMORIA;
    uint8_t PUERTO_ESCUCHA_DISPATCH;
    uint8_t PUERTO_ESCUCHA_INTERRUPT;

} t_config_cpu;

extern t_config_cpu *config_cpu;

#endif /* CONFIG_H */

