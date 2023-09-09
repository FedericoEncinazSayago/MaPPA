#include "../include/inicializar_m.h"
#include "../include/logs.h"
t_log* logger_memoria;

void cargar_configuraciones(t_config_memoria *config_memoria) {

    t_config* config = config_create("memoria.config");

    if (config == NULL) {
    	log_error(logger_memoria, "No se pudo cargar el archivo de configuracion");
    	exit(EXIT_FAILURE);
    }

    char *caracteristicas[] = {
        "PUERTO_ESCUCHA"
    	"PUERTO_FILESYSTEM"
        "IP_FILESYSTEM"
        "TAM_PAGINA"
        "PATH_INSTRUCCIONES"
        "RETARDO_RESPUESTA"
        "ALGORITMO_REEMPLAZO"
    };
    /*
    if(!tiene_todas_las_configuraciones(config, caracteristicas)) {
    	log_error(logger_memoria, "No se pudo cargar el archivo de configuracion");
        exit(EXIT_FAILURE);
    }
    */
    config_memoria->PUERTO_ESCUCHA=config_get_string_value(config, "PUERTO_ESCUCHA");
    config_memoria->PUERTO_FILESYSTEM=config_get_string_value(config, "PUERTO_FILESYSTEM");
    config_memoria->IP_FILESYSTEM=config_get_string_value(config, "IP_FILESYSTEM");
    config_memoria->TAM_MEMORIA=config_get_string_value(config, "TAM_MEMORIA");
    config_memoria->TAM_PAGINA=config_get_string_value(config, "TAM_PAGINA");
    config_memoria->PATH_INSTRUCCIONES=config_get_string_value(config, "PATH_INSTRUCCIONES");
    config_memoria->RETARDO_RESPUESTA=config_get_string_value(config, "RETARDO_RESPUESTA");
    config_memoria->ALGORITMO_REEMPLAZO=config_get_string_value(config, "ALGORITMO_REEMPLAZO");

    config_destroy(config);
    free(caracteristicas);
}

