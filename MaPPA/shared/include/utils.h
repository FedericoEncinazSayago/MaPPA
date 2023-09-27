#ifndef UTILS_H
#define UTILS_H

#include <commons/config.h>
#include <commons/string.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// FUnciones para el manejo de archivos de configuracion
bool tiene_todas_las_configuraciones(t_config* config, char* configs[]);
bool tiene_algun_algoritmo_de_planificacion(char* palabra);
bool tiene_algun_algoritmo_de_reemplazo(char* palabra);

// Funciones para el manejo de vectores dinamicos
void crear_vector_dinamico_char(char*** vector, char* informacion[]);
void crear_vector_dinamico_int(int** vector, char* informacion[]);
void recorrer_vector_char(char* vector[]);

// Funciones para el manejo de strings
char* eliminar_espacios(char* cadena);
void copiar_valor(char** destino, char* valor);
bool es_esta_palabra(char* palabra, char* palabraNecesaria);

// Funciones para el manejo de memoria
void liberar_espacios_de_memoria(void** vector);

#endif /* UTILS_H */