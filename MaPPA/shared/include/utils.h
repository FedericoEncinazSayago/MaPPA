#ifndef UTILS_H
#define UTILS_H

#include <commons/config.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool tiene_todas_las_configuraciones(t_config* config, char* configs[]);
bool es_esta_palabra(char* palabra, char* palabraNecesaria);
bool tiene_algun_algoritmo_de_planificacion(char* palabra);
void liberar_espacios_de_memoria(void** vector);

#endif