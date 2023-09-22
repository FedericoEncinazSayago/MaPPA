#include "../include/init_cpu.h"

bool cargar_configuraciones( t_config_cpu* config_cpu, t_log* logger) {
    t_config* config_cpu_open = config_create("fs.config");

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
    

    copiar_valor(&config_cpu->ip_memoria, config_get_string_value(config_cpu_open, "IP_MEMORIA"));
    config_cpu->puerto_memoria = config_get_int_value(config_cpu_open, "PUERTO_MEMORIA");
    config_cpu->puerto_escucha_dispatch = config_get_int_value(config_cpu_open, "PUERTO_ESCUCHA_DISPATCH");
    config_cpu->puerto_escucha_interrupt = config_get_int_value(config_cpu_open, "PUERTO_ESCUCHA_INTERRUPT");

    log_info(logger, "Configuraciones cargadas correctamente");
    config_destroy(config_cpu_open);
}
// FALTA CHEQUEAR ESTO PARA CLIENTE
bool generar_conexiones(t_log* logger, int* md_memoria) {
    
    // no es el puerto correcto, pero debo levantar por config
    char* puerto_memoria = "8002";
    char* ip = "127.0.0.1";

    *md_memoria = crear_conexion(logger, "MEMORIA", ip, puerto_memoria); // No harcodearlo! Sino leerlo de kernel.config
    // No existe valores por referencias en C! Primero le sacamos la direccion de memoria a la variable, y despues con *variable asignamos el nuevo valor!

    return *md_memoria != 0; // Aca pregunto por el nuevo valor!
}

void cerrar_programa(t_log* logger) {
    log_destroy(logger);
}