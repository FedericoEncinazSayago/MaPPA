/*
#include "../include/config.h"
#include "../include/iniciar_cpu.h"

t_congig_cpu *config_cpu;
t_log *logger_cpu;

void iniciar_confi() {
    config_cpu = malloc(sizeof(t_config_cpu));
    config_cpu->IP_MEMORIA = NULL;
}
*/
#include <stdio.h>
int main() {
	/*
    logger_cpu = log_create("CPU.log", "CPU", true, LOG_LEVEL_INFO);

    char *puerto_dispatch = config_cpu->PUERTO_ESCUCHA_DISPATCH;
    char *puerto_interrupt = config_cpu->PUERTO_ESCUCHA_INTERRUPT;

    // Esto hay que modificarlo! 
    int cpu_server_dispatch = iniciar_servidor(logger_cpu, "127.0.0.1" ,puerto_dispatch);
    int cpu_server_interrupt = iniciar_servidor(logger_cpu, "127.0.0.1", puerto_interrupt);
    // Hasta aca

    crear_conexion(logger_cpu, "SERVER_MEMORIA", config_cpu->IP_MEMORIA, config_cpu->PUERTO_MEMORIA);

    free(puerto_dispatch);
    free(puerto_interrupt);

    if (cpu_server_dispatch == -1 || cpu_server_interrupt == -1) {
        log_error(logger_cpu, "No se pudo iniciar el servidor");
        exit(EXIT_FAILURE);
    }

    while(server_escuchar(logger_cpu, "CPU", cpu_server_dispatch) || server_escuchar(logger_cpu, "CPU", cpu_server_interrupt)); // Esto estaria bien? 

    // Crear un funcion que libere la memoria de config_cpu
	*/
	printf("CPU");
    return 0;
}
