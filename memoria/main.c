/*
#include "../include/inicializar_m.h"
#include "../include/config.h"

t_config_fs *config_m;
t_log *logger_m;

void inicializar_fs() {
    config_m = malloc(sizeof(t_config_m));
}
*/
#include <stdio.h>
int main() {
/*
    logger_m = log_create("M.log", "M", true, LOG_LEVEL_INFO);
    
    int m_server = iniciar_servidor(logger_m, "127.0.0.1" ,config_m->PUERTO_ESCUCHA);

    //Ver Hilos para la conexion al servidor
    int cliente_server_k= esperar_cliente(logger_m, m_server);
    int cliente_server_fs= esperar_cliente(logger_m, m_server);  
    int cliente_server_cpu= esperar_cliente(logger_m, m_server);
    
    if (fs_server == -1) {
        log_error(logger_fs, "No se pudo iniciar el servidor");
        exit(EXIT_FAILURE);
    }

    while (server_escuchar(logger_m, "M", m_server))

    // Crear un funcion que libere la memoria de config
    destroy_config(config_m);
*/	printf("hola");
	return 0;
}
