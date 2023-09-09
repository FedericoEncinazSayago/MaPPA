#include "include/main.h"

int main() {
    t_log* logger_m = log_create("memoria.log", "MEMORIA", true, LOG_LEVEL_INFO);

    int server_m = iniciar_servidor(logger_m, "MEMORIA", "127.0.0.1", "8002");
    int client_k = esperar_cliente(logger_m, "MEMORIA", server_m);
    
    procesar_conexion(client_k, logger_m);

    return 0;
}