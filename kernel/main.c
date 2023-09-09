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
    char* ip_cpu = "127.0.0.1"; // No HARDCODEAR!
    char* puerto_cpu = "8006";
    char* ip_fs = "127.0.0.1"; // No HARDCODEAR!
    char* puerto_fs = "8008";
    int md_memoria = crear_conexion(logger_kernel,"Memoria",ip_memoria ,puerto_memoria );
    enviar_mensaje("HOLA MEMORIA",md_memoria);
    int md_cpu = crear_conexion(logger_kernel,"CPU",ip_cpu ,puerto_cpu);
    enviar_mensaje("HOLA CPU",md_cpu);
    int md_filesystem = crear_conexion(logger_kernel,"FileSystem",ip_fs ,puerto_fs );
    enviar_mensaje("HOLA File",md_filesystem);
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
