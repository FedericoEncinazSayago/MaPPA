/*
#include "../include/inicializar_k.h"
#include "../include/config.h" 
#include "../include/logs.h"

void cargar_configuraciones(t_config_m *config_m) {
    t_config* config = config_create("memoria.config");

    if (config == NULL) {
        log_error(logger_fs, "No se pudo cargar el archivo de configuracion");
        exit(EXIT_FAILURE);
    }

    char *caracteristicas[] = {
        "PUERTO_ESCUCHA"
        "TAM_MEMORIA"
        "TAM_PAGINA"
        "PATH_INSTRUCCIONES"
        "RETARDO_RESPUESTA"
        "ALGORITMO_REEMPLAZO"
    }

    if(!tiene_todas_las_configuraciones(config, caracteristicas)) {
        log_error(logger_fs, "No se pudo cargar el archivo de configuracion");
        exit(EXIT_FAILURE);
    }
    
    config_m->PUERTO_ESCUCHA_FS=config_get_string_value(config, "PUERTO_ESCUCHA");
    config_m->TAM_MEMORIA=config_get_string_value(config, "TAM_MEMORIA");
    config_m->TAM_PAGINA=config_get_string_value(config, "TAM_PAGINA");
    config_m->PATH_INSTRUCCIONES=config_get_string_value(config, "PATH_INSTRUCCIONES");
    config_m->RETARDO_RESPUESTA=config_get_string_value(config, "RETARDO_RESPUESTA");
    config_m->ALGORITMO_REEMPLAZO=config_get_string_value(config, "ALGORITMO_REEMPLAZO");

    config_destroy(config_m);
    free(caracteristicas);
}
*/
