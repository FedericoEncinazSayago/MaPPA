#include "../include/init_cpu.h"

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