#include "../include/init_kernel.h"

bool generar_conexiones(t_log* logger, t_config_k* config_kernel ,int* md_memoria, int* md_cpu_dt, int* md_cpu_it, int* md_fs) {
    char* ip_memoria = config_kernel->ip_memoria;
    char* puerto_memoria = string_itoa(config_kernel->puerto_memoria);

    char* ip_cpu = config_kernel->ip_cpu;
    char* puerto_cpu_dispatch = string_itoa(config_kernel->puerto_cpu_ds);
    char* puerto_cpu_interrupt = string_itoa(config_kernel->puerto_cpu_it);

    char* ip_fs = config_kernel->ip_fs;
    char* puerto_fs = string_itoa(config_kernel->puerto_fs); // string_itoa convierte un int a un string!

    *md_cpu_dt = crear_conexion(logger, "CPU-DT", ip_cpu, puerto_cpu_dispatch);
    *md_cpu_it = crear_conexion(logger, "CPU-IT", ip_cpu, puerto_cpu_interrupt);
    *md_memoria = crear_conexion(logger, "MEMORIA", ip_memoria, puerto_memoria); // Valores leidos de archivo de configuracion!
    *md_fs = crear_conexion(logger, "FILESYSTEM",ip_fs, puerto_fs); 
    
    // No existe valores por referencias en C! Primero le sacamos la direccion de memoria a la variable, y despues con *variable asignamos el nuevo valor!

    return *md_memoria != 0 && *md_fs != 0 && *md_cpu_dt != 0 && *md_cpu_it != 0; // Aca pregunto por el nuevo valor!
}

bool cargar_configuraciones(t_config_k* config_kernel, t_log* logger) {
    t_config* config = config_create("kernel.config");

    if(config == NULL) {
        log_info(logger, "No se pudo abrir el archivo de configuraciones!");
        
        return false;
    }

    char* configuraciones[] = {
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
        "GRADO_MULTIPROGRAMACION_INI",
        NULL
    };

    if(!tiene_todas_las_configuraciones(config, configuraciones)) {
        log_info(logger, "No se encontraron todas las configuraciones necesarias!");

        return false;
    }

    copiar_valor(&config_kernel->ip_memoria, config_get_string_value(config,"IP_MEMORIA"));
    copiar_valor(&config_kernel->ip_cpu, config_get_string_value(config, "IP_CPU"));
    copiar_valor(&config_kernel->ip_fs, config_get_string_value(config, "IP_FILESYSTEM"));
    copiar_valor(&config_kernel->algoritmo_planificacion, config_get_string_value(config, "ALGORITMO_PLANIFICACION"));

    config_kernel->puerto_memoria = config_get_int_value(config, "PUERTO_MEMORIA");
    config_kernel->puerto_fs = config_get_int_value(config, "PUERTO_FILESYSTEM");
    config_kernel->puerto_cpu_ds = config_get_int_value(config, "PUERTO_CPU_DISPATCH");
    config_kernel->puerto_cpu_it = config_get_int_value(config, "PUERTO_CPU_INTERRUPT");

    if(!tiene_algun_algoritmo_de_planificacion(config_kernel->algoritmo_planificacion)) {
        log_info(logger, "El algoritmo de planificacion no es valido!");

        return false;
    } // Ver si se puede hacer mejor!

    config_kernel->quantum = config_get_int_value(config, "QUANTUM");

    crear_vector_dinamico_char(&config_kernel->recursos, config_get_array_value(config, "RECURSOS")); // Tema importante: Este vector sabe cuantos elementos tiene porque el ultimo elemento es NULL!
    crear_vector_dinamico_int(&config_kernel->inst_recursos, config_get_array_value(config, "INSTANCIAS_RECURSOS")); // Tema importante: Este vector no sabe!

    // No libero la memoria usada por las configuraciones porque solamente se usa free() cuando se usa malloc()! 

    log_info(logger, "Se pudieron cargar todas las configuraciones necesarias!");
    config_destroy(config);

    return true;
}



void cerrar_programa(t_log* logger) {
    log_destroy(logger);
}
