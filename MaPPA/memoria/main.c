#include "include/main.h"

int main() {
    // nunca uso el primer logger
    t_log* logger_m = log_create("memoria.log", "MEMORIA", true, LOG_LEVEL_INFO);
    t_log* logger_memoria_kernel = log_create("memoria_kernel.log", "MEMORIA KERNEL ", true, LOG_LEVEL_INFO);
    t_log* logger_memoria_cpu = log_create("memoria_cpu.log", "MEMORIA CPU", true, LOG_LEVEL_INFO);


    // MEMORIA COMO SERVIDOR
    int server_memoria_kernel = iniciar_servidor(logger_memoria_kernel, "MEMORIA KERNEL", "127.0.0.1", "8002");
    // no esta bien asignado el puerto
    int server_memoria_cpu = iniciar_servidor(logger_memoria_cpu, "MEMORIA CPU", "127.0.0.1", "8003");
    
    // MEMORIA COMO CLIENTE
    t_log* logger_memoria_fs = log_create("memoria_filesystem.log", "MEMORIA FILESYSTEM", true, LOG_LEVEL_INFO);

    int md_fs = 0;

    if(!generar_conexiones(logger_memoria_fs, &md_fs)) {
        log_error(logger_memoria_fs, "No se pudo generar la conexion como cliente al File System");
        return 1;
    }

    int client_memoria_kernel = esperar_cliente(logger_memoria_kernel, "MEMORIA KERNEL", server_memoria_kernel);
    int client_memoria_cpu = esperar_cliente(logger_memoria_cpu, "MEMORIA CPU", server_memoria_cpu);
    
    procesar_conexion(client_memoria_kernel, logger_m);
    procesar_conexion(client_memoria_cpu, logger_m);

    send_notas(md_fs, 1, 1);
    
    cerrar_programa(logger_memoria_fs);



    return 0;
}