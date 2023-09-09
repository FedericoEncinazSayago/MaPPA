#include "include/main.h"

int main() {
    t_log* logger_fs = log_create("filesystem.log", "FILESYSTEM", true, LOG_LEVEL_INFO);

    int server_fs = iniciar_servidor(logger_fs, "FILESYSTEM", "127.0.0.1", "8003");
    int client_k = esperar_cliente(logger_fs, "FILESYSTEM", server_fs);

    procesar_conexion(client_k, logger_fs);

    return 0;
}