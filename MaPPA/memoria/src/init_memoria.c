#include "../include/init_memoria.h"

bool generar_conexiones(t_log* logger, int* md_fs) {
    
    char* ip = "127.0.0.1";

    // no es el puerto correcto, pero debo levantar por config
    char* puerto_fs = "8003";

    *md_fs = crear_conexion(logger, "MEMORIA", ip, puerto_fs); // No harcodearlo! Sino leerlo de kernel.config
    // No existe valores por referencias en C! Primero le sacamos la direccion de memoria a la variable, y despues con *variable asignamos el nuevo valor!

    return *md_fs != 0; // Aca pregunto por el nuevo valor!
}

bool cargar_configuraciones( t_config_memoria* config_memoria, t_log* logger) {
    t_config* config_m = config_create("memoria.config");
    t_config* config_kernel = config_create("../kernel/kernel.config"); // No sé si puedo hacer esto!

    if(config_m == NULL || config_kernel == NULL) {
        log_error(logger, "No se pudo cargar la configuracion");

        return false;
    }

    char* configutaciones[] = {
        "PUERTO_ESCUCHA",
        "IP_FILESYSTEM",
        "PUERTO_FILESYSTEM",
        "TAM_MEMORIA",
        "TAM_PAGINA",
        "PATH_INSTRUCCIONES",
        "RETARDO_RESPUESTA",
        "ALGORITMO_REEMPLAZO",
        NULL
    }

    if(!tiene_todas_las_configuraciones(config_m, configutaciones)) {
        log_error(logger, "No se pudo cargar la configuracion");

        return false;
    }
    
    
    config_memoria->puerto_escucha = config_get_int_value(config_m, "PUERTO_ESCUCHA");
    config_memoria->puerto_filesystem = config_get_int_value(config_m, "PUERTO_FILESYSTEM");
    config_memoria->tam_memoria = config_get_int_value(config_m, "TAM_MEMORIA");
    config_memoria->tam_pagina = config_get_int_value(config_m, "TAM_PAGINA");
    config_memoria->retardo_respuesta = config_get_int_value(config_m, "RETARDO_RESPUESTA");

    copiar_valor(&config_memoria->ip_escucha, config_get_string_value(config_kernel, "IP_MEMORIA"));
    copiar_valor(&config_memoria->path_instrucciones, config_get_string_value(config_m, "PATH_INSTRUCCIONES"));
    copiar_valor(&config_memoria->ip_filesystem, config_get_string_value(config_m, "IP_FILESYSTEM"));
    copiar_valor(&config_memoria->algoritmo_reemplazo, config_get_string_value(config_m, "ALGORITMO_REEMPLAZO"));

    if(!tiene_algun_algoritmo_de_reemplazo(config_memoria->algoritmo_reemplazo)) { // Deberia de hacer la funcion que ya incopore el algoritmo de reemplazo?
        log_error(logger, "No se pudo cargar la configuracion");

        return false;
    }

    log_info(logger, "Configuraciones cargadas correctamente");
    config_destroy(config_m);
    config_destroy(config_kernel);
}

void cerrar_programa(t_log* logger) {
    log_destroy(logger);
}