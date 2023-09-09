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

    int m_server = iniciar_servidor(logger_memoria, "MEMORIA","127.0.0.1" ,"8002");

    if (m_server == -1) {
            log_error(logger_memoria, "No se pudo iniciar el servidor");
            exit(EXIT_FAILURE);
        }

    //Ver Hilos para la conexion al servidor
    
    int cliente_server_k= esperar_cliente(logger_memoria,"KERNEL",m_server);
    recibir_mensaje(cliente_server_k,logger_memoria);
    int cliente_server_fs= esperar_cliente(logger_memoria,"FILESYSTEM",m_server);
    recibir_mensaje(cliente_server_fs,logger_memoria);
    int cliente_server_cpu= esperar_cliente(logger_memoria,"CPU",m_server);
    recibir_mensaje(cliente_server_cpu,logger_memoria);

    // Crear un funcion que libere la memoria de config

	printf("hola");
	return 0;
}
