/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/cambioDeColor.h" // Incluye el archivo de encabezado

enum Color {
    DEFAULT = 0,
    BLACK = 30,
    RED = 31,
    GREEN = 32,
    YELLOW = 33,
    BLUE = 34,
    MAGENTA = 35,
    CYAN = 36,
    WHITE = 37
};

char* ponerColorLogs(const char* texto, char* color) {
    char* cambioColorTitulo = color; // Cambia el color del texto a negrita (1m)
    char* finalizarCambioColor = "\033[0m"; // Cambia el color del texto a negrita (1m)

    // Usa malloc para asignar memoria dinámicamente
    char* tituloLog = (char*)malloc(strlen(cambioColorTitulo) + strlen(texto) + strlen(finalizarCambioColor) + 1);
    
    // Construye el título concatenando las partes
    strcpy(tituloLog, cambioColorTitulo);
    strcat(tituloLog, texto);
    strcat(tituloLog, finalizarCambioColor);

    return tituloLog;
}
/* 
"\033[1;31m": Esto es una cadena de caracteres que contiene una secuencia de escape ANSI. 
Analicemos cada parte de esta secuencia:

\033: Esta es la parte inicial de la secuencia de escape y se conoce como el "código de escape ANSI". 
Indica que se va a realizar una acción de formato o color en la salida de la consola.

[1;31m: Esta es la parte principal de la secuencia de escape que controla el estilo y el color 
del texto. Aquí hay una descomposición detallada:
[: Indica el inicio de una secuencia de control.

1;31: Estos números son parámetros que se utilizan para establecer el estilo y el color del texto. 
En este caso, 1 significa "negrita" (el texto se verá más grueso o enfatizado), y 31 significa 
"rojo" (el color del texto será rojo).

m: Indica el final de la secuencia de control.
*/
