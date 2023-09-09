#include "../include/init_kernel.h"

bool generar_conexiones(t_log* logger, int* md_memoria) {
    char* ip_memoria = "127.0.0.1"; // No HARDCODEAR!
    char* puerto_memoria = "8002";
    
    *md_memoria = crear_conexion(ip_memoria, puerto_memoria, logger);

    free(ip_memoria);
    free(puerto_memoria);

    return *md_memoria != 0;
}

void cerrar_programa(t_log* logger) {
    log_destroy(logger);
}
