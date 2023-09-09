
#include "../include/iniciar_kernel.h"
#include "../include/logs.h"
#include <stdio.h>


uint8_t generar_conexiones(int *socket_memoria, int *socket_fs, int *socket_cpu_dp, int *socket_cpu_it , t_config_kernel *confi_kernel) {
	printf("Generar Conexiones");
    char *puerto_memoria = string_itoa(confi_kernel->PUERTO_MEMORIA);
    char *puerto_fs = string_itoa(confi_kernel->PUERTO_FILESYSTEM);
    char *puerto_cpu_dispatch = string_itoa(confi_kernel->PUERTO_CPU_DISPATCH);
    char *puerto_cpu_interrupt = string_itoa(confi_kernel->PUERTO_CPU_INTERRUPT);

    *socket_memoria = crear_conexion(logger_kernel, "SERVER_MEMORIA", confi_kernel->IP_MEMORIA, puerto_memoria);
    *socket_fs = crear_conexion(logger_kernel, "SERVER_FS", confi_kernel->IP_FILESYSTEM, puerto_fs);
    *socket_cpu_dp = crear_conexion(logger_kernel, "SERVER_CPU", confi_kernel->IP_CPU, puerto_cpu_dispatch);
    *socket_cpu_it = crear_conexion(logger_kernel, "SERVER_CPU", confi_kernel->IP_CPU, puerto_cpu_interrupt);

    free(puerto_memoria); 
    free(puerto_fs);
    free(puerto_cpu_dispatch);
    free(puerto_cpu_interrupt);

    return *socket_memoria != 0 && *socket_fs != 0  && *socket_cpu_dp != 0 && *socket_cpu_it != 0;
}

uint8_t cargar_configuracion(t_config_kernel *config_kernel) {
	printf("Cargar Configuraciones");
    t_config* config = config_create("kernel.config");

    if (config == NULL) {
        log_error(logger_kernel, "No se pudo cargar el archivo de configuracion");
        exit(EXIT_FAILURE);
    }


    char *configuraciones[] = {
        "IP_MEMORIA",
        "PUERTO_MEMORIA",
        "IP_FILESYSTEM",
        "PUERTO_FILESYSTEM",
        "IP_CPU",
        "PUERTO_CPU_DISPATCH",
        "PUERTO_CPU_INTERRUPT",
        "ALGORITMO_PLANIFICACION",
        "QUANTUM",
        "RECURSOS",
        "INSTANCIAS_RECURSOS",
        "GRADO_MULTIPROGRAMACION_INI"
    };
    /*
    if(!tiene_todas_las_configuraciones(config, configuraciones)) {
        log_error(logger_kernel, "No se pudo cargar el archivo de configuracion");
        exit(EXIT_FAILURE);
    }
	*/

    config_kernel->IP_MEMORIA = config_get_string_value(config, "IP_MEMORIA");
    config_kernel->PUERTO_MEMORIA = config_get_int_value(config, "PUERTO_MEMORIA");
    config_kernel->IP_FILESYSTEM = config_get_string_value(config, "IP_FILESYSTEM");
    config_kernel->PUERTO_FILESYSTEM = config_get_int_value(config, "PUERTO_FILESYSTEM");
    config_kernel->IP_CPU = config_get_string_value(config, "IP_CPU");
    config_kernel->PUERTO_CPU_DISPATCH = config_get_int_value(config, "PUERTO_CPU_DISPATCH");
    config_kernel->PUERTO_CPU_INTERRUPT = config_get_int_value(config, "PUERTO_CPU_INTERRUPT");
    config_kernel->ALGORITMO_PLANIFICACION = config_get_string_value(config, "ALGORITMO_PLANIFICACION");
    config_kernel->QUANTUM = config_get_int_value(config, "QUANTUM");
    config_kernel->RECURSOS = config_get_array_value(config, "RECURSOS");
    config_kernel->INSTANCIAS_RECURSOS = config_get_array_value(config, "INSTANCIAS_RECURSOS");
    config_kernel->GRADO_MULTIPROGRAMACION = config_get_int_value(config, "GRADO_MULTIPROGRAMACION_INI");

    free(config);
    free(configuraciones);

    return 0;
}

void cerrar_programa(t_log *logger_kernel, t_config_kernel *confi_kernel) {
    log_destroy(logger_kernel);
    free(config_kernel);
}

