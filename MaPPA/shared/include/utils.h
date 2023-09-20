#ifndef UTILS_H
#define UTILS_H

#include <commons/config.h>
#include <commons/string.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool tiene_todas_las_configuraciones(t_config* config, char* configs[]);
bool es_esta_palabra(char* palabra, char* palabraNecesaria);
bool tiene_algun_algoritmo_de_planificacion(char* palabra);
bool tiene_algun_algoritmo_de_reemplazo(char* palabra);
void liberar_espacios_de_memoria(void** vector);
void copiar_valor(char** destino, char* valor);
void crear_vector_dinamico_char(char*** vector, char* informacion[]);
void crear_vector_dinamico_int(int** vector, char* informacion[]);
void recorrer_vector_char(char* vector[]);
void tipodeVariables(char* variable);//FUncion piola dieguito
#endif