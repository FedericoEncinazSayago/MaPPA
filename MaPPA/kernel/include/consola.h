#ifndef CONSOLA_H_
#define CONSOLA_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/file.h>
#include <sys/stat.h>
#include <sys/errno.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct {
    char* nombre;
    void* funcion;
} COMMAND;

void iniciar_consola();
char* eliminar_espacio(char* cadena);
int ejecutar_comando(char* linea);
COMMAND* encontrar_comando(char* nombre);
void iniciar_readline();
char* generador_de_comandos(const char* texto, int estado);
char** completar_MaPPA(const char* texto, int inicio, int fin);
void* iniciar_proceso(void* args);

#endif