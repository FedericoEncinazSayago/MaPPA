/*
#include "../include/config.h"
#include "../include/logs.h"

void cargar_configuraciones(t_config_cpu *config_cpu) { 
    t_config_cpu *config = config_create("cpu.config");
    
    if (config_cpu == NULL) {
        log_error(logger_cpu, "No se pudo cargar el archivo de configuracion");
        exit(EXIT_FAILURE);
    }

    char *configuraciones[] = {
        "IP_MEMORIA"
        "PUERTO_MEMORIA"
        "PUERTO_ESCUCHA_DISPATCH"
        "PUERTO_ESCUCHA_INTERRUPT"
    };

    if(!tiene_todas_las_configuraciones(config_cpu, configuraciones)) {
        log_error(logger_cpu, "No se pudo cargar el archivo de configuracion");
        exit(EXIT_FAILURE);
    }

    config_cpu->IP_MEMORIA = config_get_string_value("cpu.config", "IP_MEMORIA");
    config_cpu->PUERTO_MEMORIA = config_get_int_value("cpu.config", "PUERTO_MEMORIA");
    config_cpu->PUERTO_ESCUCHA_DISPATCH = config_get_int_value("cpu.config", "PUERTO_ESCUCHA_DISPATCH");
    config_cpu->PUERTO_ESCUCHA_INTERRUPT = config_get_int_value("cpu.config", "PUERTO_ESCUCHA_INTERRUPT");

    config_destroy(config);
    free(configuraciones);
}
*/

#include "../include/inicializar_cpu.h"
#include "../include/logs.h"
t_log* logger_cpu;

void cargar_configuraciones(t_config_cpu *config_cpu) {

    t_config* config = config_create("cpu.config");

    if (config == NULL) {
    	log_error(logger_cpu, "No se pudo cargar el archivo de configuracion");
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
    config_cpu->PUERTO_ESCUCHA=config_get_string_value(config, "PUERTO_ESCUCHA");
    config_cpu->PUERTO_FILESYSTEM=config_get_string_value(config, "PUERTO_FILESYSTEM");
    config_cpu->IP_FILESYSTEM=config_get_string_value(config, "IP_FILESYSTEM");
    config_cpu->TAM_MEMORIA=config_get_string_value(config, "TAM_MEMORIA");
    config_cpu->TAM_PAGINA=config_get_string_value(config, "TAM_PAGINA");
    config_cpu->PATH_INSTRUCCIONES=config_get_string_value(config, "PATH_INSTRUCCIONES");
    config_cpu->RETARDO_RESPUESTA=config_get_string_value(config, "RETARDO_RESPUESTA");
    config_cpu->ALGORITMO_REEMPLAZO=config_get_string_value(config, "ALGORITMO_REEMPLAZO");

    config_destroy(config);
    free(caracteristicas);
}


