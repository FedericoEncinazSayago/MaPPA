#include "include/main.h"

int main() {
    t_log* logger_cpu = log_create("cpu.log", "CPU", true, LOG_LEVEL_INFO);
    t_log* logger_cpu_dis = log_create("cpuDis.log", "DISPACHT", true, LOG_LEVEL_INFO);
    t_log* logger_cpu_int = log_create("interrupt.log", "INTERRUPT", true, LOG_LEVEL_INFO);

    int server_cpu_dispacht= iniciar_servidor(logger_cpu, "CPU_DISPACHT", "127.0.0.1", "8006");
    int server_cpu_interrupt = iniciar_servidor(logger_cpu, "CPU_INTERRUPT", "127.0.0.1", "8007");
   
    int client_k_dis = esperar_cliente(logger_cpu, "CPU_DISPACHT", server_cpu_dispacht); 
    int client_k_int = esperar_cliente(logger_cpu, "CPU_INTERRUPT", server_cpu_interrupt); 
   
    procesar_conexion(client_k_int, logger_cpu_int);
    procesar_conexion(client_k_dis, logger_cpu_dis);


    return 0;
}