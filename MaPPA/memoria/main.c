#include "include/main.h"


int main() {

    t_log* logger_m = log_create("memoria.log", "MEMORIA", true, LOG_LEVEL_INFO);

    int server_memoria = iniciar_servidor(logger_m, "MEMORIA MULTIHILOS", "127.0.0.1", "8002"); // Tenemos que hacer un servidor multi-hilos
    int md_fs = crear_conexion_con_timer(logger_m, "FILE SYSTEM", "127.0.0.1", "8003");

    while(server_escucha(logger_m, "MEMORIA MULTIHILOS", server_memoria));

    cerrar_programa(logger_m);

    return 0;
}