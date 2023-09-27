#include "../include/consola.h"

COMMAND comandos[] = {
    {"INICIAR_PROCESO", iniciar_proceso},
    /*{"FINALIZAR_PROCESO", finalizar_proceso},
    {"DETENER_PLANIFICACION", detener_planificacion},
    {"INICIAR_PLANIFICACION", iniciar_planificacion},
    {"MULTIPROGRAMACION", multiprogramacion},
    {"PROCESO_ESTADO", proceso_estado},
    {"HELP", help},*/
    {NULL, NULL}
};

void iniciar_consola() {
    char* linea;
    char* operacion;

    iniciar_readline();

    while(1) {
        linea = readline("MaPPA: ");

        if(!linea)
            break;

        operacion = eliminar_espacios(linea);

        if(operacion != NULL) {
            add_history(linea);
            ejecutar_comando(linea);
        }
           
        free(linea);
    }
}

char* eliminar_espacio(char* cadena) {
    char* aux = cadena;
    char* aux2;

    // Elimina los espacios en blanco al principio de la cadena
    while (*aux && isspace(*aux))
        aux++;

    if (*aux == '\0') {
        // Si la cadena queda vacía después de eliminar espacios en blanco,
        // se retorna una cadena vacía
        return aux;
    }

    aux2 = aux + strlen(aux) - 1;

    // Elimina los espacios en blanco al final de la cadena
    while (aux2 > aux && isspace(*aux2))
        aux2--;

    // Coloca el carácter nulo '\0' después del último carácter no espacio en blanco
    *(++aux2) = '\0';

    // Retorna la dirección del primer carácter no espacio en blanco
    return aux;
}


int ejecutar_comando(char* linea) {
    int i = 0;
    char* palabra;
    COMMAND* comando;

    while(linea[i] && isspace(linea[i]))
        i++;
    
    palabra = linea + i;

    while(linea[i] && !isspace(linea[i]))
        i++;
    
    if(linea[i])
        linea[i++] = '\0';

    comando = encontrar_comando(palabra);

    if(!comando) {
        printf("Comando desconocido: %s\n", palabra);

        return -1;
    }

    while(linea[i] && isspace(linea[i]))
        i++;

    palabra = linea + i;

    return (*(comando->funcion) (palabra));
}

COMMAND* encontrar_comando(char* nombre) {
    for(int i = 0; comandos[i].nombre; i++) {
        if(strcmp(nombre, comandos[i].nombre) == 0)
            return &comandos[i];
    }

    return ((COMMAND*) NULL);
}

void iniciar_readline() {
    rl_readline_name = "MaPPA";
    rl_attempted_completion_function = completar_MaPPA;
}

char** completar_MaPPA(const char* texto, int inicio, int fin) {
    char** matches = NULL;

    if(inicio == 0)
        matches = rl_completion_matches(texto, generador_de_comandos);

    return (matches);
}

char* generador_de_comandos(const char* texto, int estado) {
    static int lista_index, len;
    char* nombre;

    if(!estado) {
        lista_index = 0;
        len = strlen(texto);
    }

    while((nombre = comandos[lista_index].nombre)) {
        lista_index++;

        if(strncmp(nombre, texto, len) == 0)
            return strdup(nombre);
    }

    return ((char*) NULL);
}

void* iniciar_proceso(void* args) {
    printf("Iniciando proceso...\n");
}