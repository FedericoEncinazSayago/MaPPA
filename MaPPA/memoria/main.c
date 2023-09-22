#include "include/main.h"

t_config_memoria* config_memoria;

void inicializar_config(void) { // Voy a inicializar config de memoria!s
    config_memoria = malloc(sizeof(t_config_memoria));
    config_memoria->ip_fs = NULL;
    config_memoria->ip_escucha = NULL;
    config_memoria->path_instrucciones = NULL;
    config_memoria->algoritmo_reemplazo = NULL;
} 

int main() {

    t_log* logger_m = log_create("memoria.log", "MEMORIA", true, LOG_LEVEL_INFO);

    if(!cargar_configuraciones(config_memoria, logger_m)) { // Traigo las configuraciones de memoria!
        log_error(logger_m, "No se pudieron cargar las configuraciones");

        return 1;
    }

    iniciar_modulo() // Acá voy a crear el servidor con las cosas!

    cerrar_programa(logger_m);

    return 0;
    //
    //
}