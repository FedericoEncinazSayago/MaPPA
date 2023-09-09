#include "include/main.h"

int main() {
    t_log* logger_cpu = log_create("Cpu.log", "CPU", true, LOG_LEVEL_INFO);
    int server_cpu_dispacht= iniciar_servidor(logger_cpu, "Cpu_DISPACHT", "127.0.0.1", "8006");
    int server_cpu_interrupt = iniciar_servidor(logger_cpu, "Cpu", "127.0.0.1", "8007");
   
    int client_k_dis = esperar_cliente(logger_cpu, "Cpu", server_cpu_dispacht); 
    int client_k_int = esperar_cliente(logger_cpu, "Cpu_INTERRUTP", server_cpu_interrupt); 

   
    procesar_conexion(client_k_dis, logger_cpu);
    procesar_conexion(client_k_int, logger_cpu);
    //blackbox

    return 0;
}