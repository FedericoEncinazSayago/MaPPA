#include "include/main.h"

int main() {
    t_log* logger_fs = log_create("filesystem.log", "FILESYSTEM", true, LOG_LEVEL_INFO);
    t_log* logger_fs_kernel = log_create("filesystem_kernel.log", "FILESYSTEM KERNEL", true, LOG_LEVEL_INFO);
    t_log* logger_fs_memoria = log_create("filesystem_memoria.log", "FILESYSTEM MEMORIA", true, LOG_LEVEL_INFO);


    int server_fs_kernel = iniciar_servidor(logger_fs_kernel, "FILESYSTEM KERNEL", "127.0.0.1", "8003");
    // puerto mal asignado
    int server_fs_memoria = iniciar_servidor(logger_fs_memoria, "FILESYSTEM MEMORIA", "127.0.0.1", "8007");


    int client_fs_kernel = esperar_cliente(logger_fs_kernel, "FILESYSTEM KERNEL", server_fs_kernel);
    int client_fs_memoria = esperar_cliente(logger_fs_memoria, "FILESYSTEM MEMORIA", server_fs_memoria);

    procesar_conexion(client_fs_kernel, logger_fs_kernel);
    procesar_conexion(client_fs_memoria, logger_fs_memoria);

    return 0;
}