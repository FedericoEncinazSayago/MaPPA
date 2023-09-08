#include "../include/init_kernel.h"

bool generar_conexiones(t_log* logger, int* md_memoria, int* md_cpu_dt, int* md_cpu_it, int* md_fs) {
    char* ip_memoria = "127.0.0.1"; // No HARDCODEAR!
    char* puerto_memoria = "8002";

    char* ip_cpu = "127.0.0.1";
    char* puerto_cpu_dispatch = "8006";
    char* puerto_cpu_interrupt = "8007";

    char* ip_fs = "127.0.0.1";
    char* puerto_fs = "8005";

    *md_memoria = crear_conexion(ip_memoria, puerto_memoria, logger);
    *md_cpu_dt = crear_conexion(ip_cpu, puerto_cpu_dispatch, logger);
    *md_cpu_it = crear_conexion(ip_cpu, puerto_cpu_interrupt, logger);
    *md_fs = crear_conexion(ip_fs, puerto_fs, logger);

    free(ip_memoria);
    free(puerto_memoria);

    free(ip_cpu);
    free(puerto_cpu_dispatch);
    free(puerto_cpu_interrupt);

    free(ip_fs);
    free(puerto_fs);

    return *md_memoria != 0 && *md_cpu_dt != 0 && *md_cpu_it != 0 && *md_fs != 0;
}

void cerrar_programa(t_log* logger) {
    log_destroy(logger);
}
