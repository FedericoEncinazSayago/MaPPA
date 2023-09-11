#include "../include/init_kernel.h"

bool generar_conexiones(t_log* logger, int* md_memoria, int* md_cpu_dt, int* md_cpu_it, int* md_fs) {
    // No HARDCODEAR!
    char* puerto_memoria = "8002";
    char* ip = "127.0.0.1";
    char* puerto_fs = "8003";
    char* puerto_cpu_dispatch="8006";
    char* puerto_cpu_interrupt="8007";

    *md_cpu_dt = crear_conexion(logger, "CPU DT", ip, puerto_cpu_dispatch);
    *md_cpu_it = crear_conexion(logger, "CPU IT", ip, puerto_cpu_interrupt);
    *md_memoria = crear_conexion(logger, "MEMORIA", ip, puerto_memoria); // No harcodearlo! Sino leerlo de kernel.config
    *md_fs = crear_conexion(logger, "FILESYSTEM",ip, puerto_fs); 
    
    // No existe valores por referencias en C! Primero le sacamos la direccion de memoria a la variable, y despues con *variable asignamos el nuevo valor!

    return *md_memoria != 0 && *md_fs != 0; // Aca pregunto por el nuevo valor!
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

    config_kernel->ip_memoria = config_get_string_value(config, "IP_MEMORIA");
    config_kernel->puerto_memoria = config_get_int_value(config, "PUERTO_MEMORIA");
    config_kernel->ip_fs = config_get_string_value(config, "IP_FILESYSTEM");
    config_kernel->puerto_fs = config_get_int_value(config, "PUERTO_FILESYSTEM");
    config_kernel->ip_cpu = config_get_string_value(config, "IP_CPU");
    config_kernel->puerto_cpu_ds = config_get_int_value(config, "PUERTO_CPU_DISPATCH");
    config_kernel->puerto_cpu_it = config_get_int_value(config, "PUERTO_CPU_INTERRUPT");

    config_kernel->alg_planificacion = config_get_string_value(config, "ALGORITMO_PLANIFICACION");

    // Falta ver si el algoritmo de planificacion es valido!

    config_kernel->quantum = config_get_int_value(config, "QUANTUM");
    config_kernel->recursos = config_get_array_value(config, "RECURSOS");
    config_kernel->inst_recursos = config_get_array_value(config, "INSTANCIAS_RECURSOS");

    // Falta agregar la liberacion de memoria de los arrays y de la config!

    log_info(logger, "Se pudieron cargar todas las configuraciones necesarias!");

    return true;
}



void cerrar_programa(t_log* logger) {
    log_destroy(logger);
}
