#include "include/inicializar_cpu.h"
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

    char* ip_memoria = "127.0.0.1"; // No HARDCODEAR!
    char* puerto_memoria = "8010";
    int md_memoria = crear_conexion(logger_cpu,"Memoria",ip_memoria ,puerto_memoria );
    enviar_mensaje("HOLA MEMORIA",md_memoria);

	return 0;
}
