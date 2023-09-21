#include "include/main.h"

int main() {
    t_log* logger_cpu = log_create("cpu.log", "CPU", true, LOG_LEVEL_INFO);


    // CPU COMO SERVIDOR
    // conecte estos loggers en la linea 10 y 11 que no estaban siendo usados pero si en "procesar conexion"
    t_log* logger_cpu_dis = log_create("cpu_dispacht.log", "CPU DISPACHT", true, LOG_LEVEL_INFO);
    t_log* logger_cpu_int = log_create("cpu_interrupt.log", "CPU INTERRUPT", true, LOG_LEVEL_INFO);

    int server_cpu_dispacht= iniciar_servidor(logger_cpu_dis, "CPU DISPACHT", "127.0.0.1", "8006");
    int server_cpu_interrupt = iniciar_servidor(logger_cpu_int, "CPU INTERRUPT", "127.0.0.1", "8007");
   
    int client_k_dis = esperar_cliente(logger_cpu, "CPU DISPACHT", server_cpu_dispacht); 
    int client_k_int = esperar_cliente(logger_cpu, "CPU INTERRUPT", server_cpu_interrupt); 
   
    procesar_conexion(client_k_int, logger_cpu_int);
    procesar_conexion(client_k_dis, logger_cpu_dis);

    // CPU COMO CLIENTE
    t_log* logger_cpu_memoria = log_create("cpu_memoria.log", "CPU MEMORIA", true, LOG_LEVEL_INFO);

    int md_memoria = 0;

    if(!generar_conexiones(logger_cpu_memoria, &md_memoria)) {
        log_error(logger_cpu_memoria, "No se pudieron generar la conexion como cliente a la memoria");
        return 1;
    }

    send_notas(md_memoria, 5, 10);
    //CPU MANDA SUMA QUE RECIBE DE KERNEL
    cerrar_programa(logger_cpu_memoria);



    return 0;
}