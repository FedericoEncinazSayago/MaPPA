#include "../include/init_kernel.h"

bool generar_conexiones(t_log* logger, int* md_memoria, int* md_fs) {
 // No HARDCODEAR!
    char* ip_memoria = "127.0.0.1";
    char* puerto = "8002";

    char* ip_fs = "127.0.0.1";
    char* puerto_fs = "8003";

    *md_memoria = crear_conexion(logger, "MEMORIA", ip_memoria, puerto); // No harcodearlo! Sino leerlo de kernel.config
    *md_fs = crear_conexion(logger, "FILESYSTEM",ip_fs, puerto_fs);
    // No existe valores por referencias en C! Primero le sacamos la direccion de memoria a la variable, y despues con *variable asignamos el nuevo valor!

    return *md_memoria != 0 && *md_fs != 0; // Aca pregunto por el nuevo valor!
}

void cerrar_programa(t_log* logger) {
    log_destroy(logger);
}
