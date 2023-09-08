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
