#include "../include/init_kernel.h"

bool generar_conexiones(t_log* logger, t_config_k* config_kernel ,int* md_memoria, int* md_cpu_dt, int* md_cpu_it, int* md_fs) {
    
    printf("HOLA!");
    
    char* ip_memoria = config_kernel->ip_memoria;
    char* puerto_memoria = string_itoa(config_kernel->puerto_memoria);
    printf("IP MEMORIA: %s\n", ip_memoria);
    printf(config_kernel->ip_memoria);
    printf("PUERTO MEMORIA: %s\n", puerto_memoria);
    
    char* ip_cpu = config_kernel->ip_cpu;
    char* puerto_cpu_dispatch = string_itoa(config_kernel->puerto_cpu_ds);
    char* puerto_cpu_interrupt = string_itoa(config_kernel->puerto_cpu_it);
    printf("IP CPU: %s\n", ip_cpu);
    printf("PUERTO CPU DISPATCH: %s\n", puerto_cpu_dispatch);
    printf("PUERTO CPU INTERRUPT: %s\n", puerto_cpu_interrupt);

    char* ip_fs = config_kernel->ip_fs;
    char* puerto_fs = string_itoa(config_kernel->puerto_fs); // string_itoa convierte un int a un string!
    printf("IP FS: %s\n", ip_fs);
    printf("PUERTO FS: %s\n", puerto_fs);

    printf("Hola!");
    /*
    *md_cpu_dt = crear_conexion(logger, "CPU-DT", ip_cpu, puerto_cpu_dispatch);
    *md_cpu_it = crear_conexion(logger, "CPU-IT", ip_cpu, puerto_cpu_interrupt);
    *md_memoria = crear_conexion(logger, "MEMORIA", ip_memoria, puerto_memoria); // Valores leidos de archivo de configuracion!
    *md_fs = crear_conexion(logger, "FILESYSTEM",ip_fs, puerto_fs); 
    */
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

    config_kernel->ip_memoria = config_get_string_value(config,"IP_MEMORIA");
    printf("IP_MEMORIA: %s", config_kernel->ip_memoria);
    config_kernel->puerto_memoria = config_get_int_value(config, "PUERTO_MEMORIA");
    // printf("PUERTO_MEMORIA: %d", config_kernel->puerto_memoria);
    config_kernel->ip_fs = config_get_string_value(config, "IP_FILESYSTEM");
    config_kernel->puerto_fs = config_get_int_value(config, "PUERTO_FILESYSTEM");
    // printf("PUERTO_FILESYSTEM: %d", config_kernel->puerto_fs);
    config_kernel->ip_cpu = config_get_string_value(config, "IP_CPU");
    config_kernel->puerto_cpu_ds = config_get_int_value(config, "PUERTO_CPU_DISPATCH");
    // printf("PUERTO_CPU_DISPATCH: %d", config_kernel->puerto_cpu_ds);
    config_kernel->puerto_cpu_it = config_get_int_value(config, "PUERTO_CPU_INTERRUPT");
    // printf("PUERTO_CPU_INTERRUPT: %d", config_kernel->puerto_cpu_it);

    config_kernel->alg_planificacion = config_get_string_value(config, "ALGORITMO_PLANIFICACION");

    if(!tiene_algun_algoritmo_de_planificacion(config_kernel->alg_planificacion)) {
        log_info(logger, "El algoritmo de planificacion no es valido!");

        return false;
    } // Ver si se puede hacer mejor!

    config_kernel->quantum = config_get_int_value(config, "QUANTUM");
    config_kernel->recursos = config_get_array_value(config, "RECURSOS");
    config_kernel->inst_recursos = config_get_array_value(config, "INSTANCIAS_RECURSOS");

    // No libero la memoria usada por las configuraciones porque solamente se usa free() cuando se usa malloc()! 

    log_info(logger, "Se pudieron cargar todas las configuraciones necesarias!");
    config_destroy(config);

    return true;
}



void cerrar_programa(t_log* logger) {
    log_destroy(logger);
}
