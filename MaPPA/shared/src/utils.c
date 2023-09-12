#include "../include/utils.h"

bool tiene_todas_las_configuraciones(t_config* config, char* configs[]) {  
    for(size_t i = 0; configs[i] !=  NULL; i++) {
        if(!config_has_property(config, configs[i]))
            return false;
    }

    return true;
}

void liberar_espacios_de_memoria(void** vector) { // Funcion: libera todos los espacios de memoria de un array de punteros asignados dinamicamente
    for(size_t i = 0; vector[i] != NULL; i++) {
        printf("Aca estoy!\n");
        free(vector[i]);
    }

    free(vector);
} // Comentario: tipo de dato (cualquiera)** nombre de la variable = array de punteros

bool es_esta_palabra(char* palabra, char* palabraNecesaria) { // Funcion: compara dos palabras y devuelve true si son iguales
    return strcmp(palabra, palabraNecesaria) == 0;
}

bool tiene_algun_algoritmo_de_planificacion(char* palabra) { // Funcion: devuelve true si la palabra es FIFO, RR o PRIORIDADES
    if (es_esta_palabra(palabra, "FIFO"))
        return true;
    else 
    {
        if (es_esta_palabra(palabra, "RR")) 
            return true;
        else
        {
            if(es_esta_palabra(palabra, "PRIORIDADES")) 
                return true;
        }
    }

    return false;
}