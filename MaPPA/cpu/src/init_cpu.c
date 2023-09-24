#include "../include/init_cpu.h"

// FALTA CHEQUEAR ESTO PARA CLIENTE
bool generar_conexiones(t_log* logger, int* md_memoria) {
    
    // no es el puerto correcto, pero debo levantar por config
    char* puerto_memoria = "8002";
    char* ip = "127.0.0.1";

    *md_memoria = crear_conexion(logger, "MEMORIA", ip, puerto_memoria); // No harcodearlo! Sino leerlo de kernel.config
    // No existe valores por referencias en C! Primero le sacamos la direccion de memoria a la variable, y despues con *variable asignamos el nuevo valor!

    return *md_memoria != 0; // Aca pregunto por el nuevo valor!
}

bool cargar_configuraciones( t_config_cpu* config_cpu, t_log* logger) {
    t_config* config_c = config_create("cpu.config");

    if(config_cpu == NULL) {
        log_error(logger, "No se pudo cargar la configuracion del filesystem");

        return false;
    }

    char* configuraciones[] = {
        "IP_MEMORIA",
        "PUERTO_MEMORIA",
        "PUERTO_ESCUCHA_DISPATCH",
        "PUERTO_ESCUCHA_INTERRUPT",
        NULL
    };

    if(!tiene_todas_las_configuraciones(config_cpu, configuraciones)) {
        log_error(logger, "No se pudo cargar la configuracion del cpu");

        return false;
    }
    

    copiar_valor(&config_cpu->ip_memoria, config_get_string_value(config_c, "IP_MEMORIA"));
    config_cpu->puerto_memoria = config_get_int_value(config_c, "PUERTO_MEMORIA");
    config_cpu->puerto_escucha_dispatch = config_get_int_value(config_c, "PUERTO_ESCUCHA_DISPATCH");
    config_cpu->puerto_escucha_interrupt = config_get_int_value(config_c, "PUERTO_ESCUCHA_INTERRUPT");

    log_info(logger, "Configuraciones cargadas correctamente");
    config_destroy(config_c);
}

bool crear_servidores(t_logger* logger, t_config_cpu* config_cpu, int* md_cpu_ds, int* md_cpu_it) {
    char* puerto_dispatch = string_itoa(config_cpu->puerto_escucha_dispatch);
    char* puerto_interrupt = string_itoa(config_cpu->puerto_escucha_interrupt);
    char* ip_cpu_ds = config_cpu->ip_memoria;
    char* ip_cpu_it = config_cpu->ip_memoria;

    *md_cpu_ds = crear_conexion(logger, "DISPATCH", ip_cpu_ds, puerto_dispatch);
    *md_cpu_it = crear_conexion(logger, "INTERRUPT", ip_cpu_it, puerto_interrupt);

    return *md_cpu_ds != 0 && *md_cpu_it != 0;
}

void iniciar_modulo(t_log* logger_cpu, t_config_cpu* config_cpu) {
    int md_cpu_ds = 0;
    int md_cpu_it = 0;

    if(!crear_servidores(logger_cpu, config_cpu, &md_cpu_ds, &md_cpu_it)) {
        log_error(logger_cpu, "No se pudo crear los servidores de escucha");

        return;
    }

    pthread_t hilo_cpu_ds;
    pthread_t hilo_cpu_it;

    t_procesar_server* args_ds = malloc(sizeof(t_procesar_server));
    args_ds->logger = logger_cpu;
    args_ds->socket_server = md_cpu_ds;
    args_ds->server_name = "DISPATCH";

    t_procesar_server* args_it = malloc(sizeof(t_procesar_server));
    args_it->logger = logger_cpu;
    args_it->socket_server = md_cpu_it;
    args_it->server_name = "INTERRUPT";
    
    pthread_create(&hilo_cpu_ds, NULL, server_escuchar, (void*) args_ds); 
    pthread_create(&hilo_cpu_it, NULL, server_escuchar, (void*) args_it);
}

void cerrar_programa(t_log* logger) {
    log_destroy(logger);
}