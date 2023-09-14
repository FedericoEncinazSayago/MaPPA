#include "include/main.h"

int main() {
    // t_log* logger_fs = log_create("filesystem.log", "FILESYSTEM", true, LOG_LEVEL_INFO);
    // t_log* logger_fs_kernel = log_create("filesystem_kernel.log", "FILESYSTEM KERNEL", true, LOG_LEVEL_INFO);
    t_log* logger_fs = log_create("filesystem_memoria.log", "FILESYSTEM", true, LOG_LEVEL_INFO);

    int server_fs = iniciar_servidor(logger_fs, "FILESYSTEM", "127.0.0.1", "8003");
    int md_memoria = crear_conexion(logger_fs, "MEMORIA", "127.0.0.1", "8002");

    // int client_fs_kernel = esperar_cliente(logger_fs_kernel, "FILESYSTEM KERNEL", server_fs);
    // int client_fs_memoria = esperar_cliente(logger_fs, "FILESYSTEM MEMORIA", server_fs);

    send_notas(md_memoria, 5, 10);
    // procesar_conexion(client_fs_memoria, logger_fs_memoria);
    
    return 0;
}