#include "include/inicializar_m.h"
#include "include/config.h"

t_config_memoria *config_memoria;
extern t_log* logger_memoria;

void inicializar_m() {
    config_memoria = malloc(sizeof(t_config_memoria));
}

#include <stdio.h>
int main() {

    logger_memoria = log_create("M.log", "M", true, LOG_LEVEL_INFO);

    int k_server = iniciar_servidor(logger_memoria, "KERNEL","127.0.0.1" ,"8002");
    int fs_server = iniciar_servidor(logger_memoria, "FILESYSTEM","127.0.0.1" ,"8012");
    int cpu_server = iniciar_servidor(logger_memoria, "CPU","127.0.0.1" ,"8010");
    if (k_server == -1) {
            log_error(logger_memoria, "No se pudo iniciar el servidor");
            exit(EXIT_FAILURE);
        }
    if (fs_server == -1) {
                log_error(logger_memoria, "No se pudo iniciar el servidor");
                exit(EXIT_FAILURE);
            }
    if (cpu_server == -1) {
                log_error(logger_memoria, "No se pudo iniciar el servidor");
                exit(EXIT_FAILURE);
            }

    //Ver Hilos para la conexion al servidor
    
    int cliente_server_k= esperar_cliente(logger_memoria,"KERNEL",k_server);
    int cliente_server_cpu= esperar_cliente(logger_memoria,"CPU",cpu_server);
    int cliente_server_fs= esperar_cliente(logger_memoria,"FILESYSTEM",fs_server);


    recibir_mensaje(cliente_server_k,logger_memoria);
    recibir_mensaje(cliente_server_cpu,logger_memoria);
    recibir_mensaje(cliente_server_fs,logger_memoria);
    // Crear un funcion que libere la memoria de config
	return 0;
}
