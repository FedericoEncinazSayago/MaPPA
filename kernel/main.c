#include "include/config.h"
#include "include/logs.h"
#include <stdio.h>

t_config_kernel *config_kernel;
t_log *logger_kernel;


void iniciar_config() {
    config_kernel = malloc(sizeof(t_config_kernel));
    config_kernel->IP_MEMORIA = NULL;
    config_kernel->IP_FILESYSTEM = NULL;
    config_kernel->IP_CPU = NULL;
}


int main() {

    logger_kernel = log_create("kernel.log", "KERNEL", true, LOG_LEVEL_INFO);
    log_info(logger_kernel,"Prueba");

    //int memoria, filesystem, cpu_dp, cpu_it;
    char* ip_memoria = "127.0.0.1"; // No HARDCODEAR!
    char* puerto_memoria = "8002";

    int md_memoria = crear_conexion(logger_kernel,"Memoria",ip_memoria ,puerto_memoria );

    enviar_mensaje("HOLA",md_memoria);
    log_info(logger_kernel,"pase enviar mensaje");

    /*
    if (!cargar_configuracion(config_kernel) && !generar_conexiones(&memoria, &filesystem, &cpu_dp, &cpu_it, config_kernel)){
    	log_info(logger_kernel,"Entre al IF");
        cerrar_programa(logger_kernel, config_kernel);
        return 1;
    }
    */


    return 0;
    
}
