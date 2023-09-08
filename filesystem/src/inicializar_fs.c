/*
#include "../include/inicializar_fs.h"
#include "../include/config.h" 
#include "../include/logs.h"

void cargar_configuraciones(t_config_cpu *config_fs) {
    t_config* config = config_create("fs.config");

    if (config == NULL) {
        log_error(logger_fs, "No se pudo cargar el archivo de configuracion");
        exit(EXIT_FAILURE);
    }

    char *caracteristicas[] = {
        "IP_MEMORIA"
        "PUERTO_MEMORIA"
        "PUERTO_ESCUCHA"
        "PATH_FAT"
        "PATH_BLOQUES"
        "PATH_FCB"
        "CANT_BLOQUES_TOTAL"
        "CANT_BLOQUES_SWAP"
        "TAM_BLOQUE"
        "RETARDO_ACCESO_BLOQUE"
        "RETARDO_ACCESO_FAT"
    }

    if(!tiene_todas_las_configuraciones(config, caracteristicas)) {
        log_error(logger_fs, "No se pudo cargar el archivo de configuracion");
        exit(EXIT_FAILURE);
    }
    
    config_fs->IP_MEMORIA = config_get_string_value(config, "IP_MEMORIA");
    config_fs->PUERTO_MEMORIA = config_get_string_value(config, "PUERTO_MEMORIA");
    config_fs->PUERTO_ESCUCHA = config_get_string_value(config, "PUERTO_ESCUCHA");
    config_fs->PATH_FAT = config_get_string_value(config, "PATH_FAT");
    config_fs->PATH_BLOQUES = config_get_string_value(config, "PATH_BLOQUES");
    config_fs->PATH_FCB = config_get_string_value(config, "PATH_FCB");
    config_fs->CANTIDAD_BLOQUES_TOTAL = config_get_string_value(config, "CANTIDAD_BLOQUES_TOTAL");
    config_fs->CANTIDAD_BLOQUES_SWAP = config_get_string_value(config, "CANTIDAD_BLOQUES_SWAP");
    config_fs->TAM_BLOQUES = config_get_string_value(config, "TAM_BLOQUES");
    config_fs->RETARDO_ACCESO_BLOQUE = config_get_string_value(config, "RETARDO_ACCESO_BLOQUE");
    config_fs->RETARDO_ACCESO_FAT = config_get_string_value(config, "RETARDO_ACCESO_FAT");

    free(config);
    free(caracteristicas);
}*/
