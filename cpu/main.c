#include "include/inicializar_m.h"
#include "include/config.h"

t_config_cpu *config_cpu;
extern t_log* logger_cpu;

void inicializar_m() {
    config_cpu = malloc(sizeof(t_config_cpu));
}

#include <stdio.h>
int main() {

    logger_cpu = log_create("CPU_SERVER.log", "CPU_SERVER", true, LOG_LEVEL_INFO);

    int cpu_server = iniciar_servidor(logger_cpu, "CPU SERVER","127.0.0.1" ,"8006");

    if (cpu_server == -1) {
            log_error(logger_cpu, "No se pudo iniciar el servidor");
            exit(EXIT_FAILURE);
        }

    //Ver Hilos para la conexion al servidor

    int cliente_server_k= esperar_cliente(logger_cpu,"KERNEL",cpu_server);
    recibir_mensaje(cliente_server_k,logger_cpu);

	return 0;
}
