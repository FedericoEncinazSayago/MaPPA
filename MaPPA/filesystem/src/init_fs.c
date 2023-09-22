#include "../include/init_fs.h"

bool cargar_configuraciones( t_config_fs* config_fs, t_log* logger) {
    t_config* config_fs_open = config_create("fs.config");

    if(config_fs == NULL) {
        log_error(logger, "No se pudo cargar la configuracion del filesystem");

        return false;
    }

    char* configuraciones[] = {
        "IP_MEMORIA",
        "PUERTO_MEMORIA",
        "PUERTO_ESCUCHA",
        "PATH_FAT",
        "PATH_BLOQUES",
        "PATH_FCB",
        "CANT_BLOQUES_TOTAL",
        "CANT_BLOQUES_SWAP",
        "TAM_BLOQUE",
        "RETARDO_ACCESO_BLOQUE",
        "RETARDO_ACCESO_FAT",
        NULL
    };

    if(!tiene_todas_las_configuraciones(config_fs, configuraciones)) {
        log_error(logger, "No se pudo cargar la configuracion del filesystem");

        return false;
    }
    

    copiar_valor(&config_fs->ip_memoria, config_get_string_value(config_fs_open, "IP_MEMORIA"));
    config_fs->puerto_memoria = config_get_int_value(config_fs_open, "PUERTO_MEMORIA");
    config_fs->puerto_escucha = config_get_int_value(config_fs_open, "PUERTO_ESCUCHA");
    copiar_valor(&config_fs->path_fath, config_get_string_value(config_fs_open, "PATH_FAT"));
    copiar_valor(&config_fs->path_bloques, config_get_string_value(config_fs_open, "PATH_BLOQUES"));
    copiar_valor(&config_fs->path_fcb, config_get_string_value(config_fs_open, "PATH_FCB"));
    config_fs->cant_bloques_total = config_get_int_value(config_fs_open, "CANT_BLOQUES_TOTAL");
    config_fs->cant_bloques_swap = config_get_int_value(config_fs_open, "CANT_BLOQUES_SWAP");
    config_fs->tam_bloque = config_get_int_value(config_fs_open, "TAM_BLOQUE");
    config_fs->retardo_acceso_bloque = config_get_int_value(config_fs_open, "RETARDO_ACCESO_BLOQUE");
    config_fs->retardo_acceso_fat = config_get_int_value(config_fs_open, "RETARDO_ACCESO_FAT");

    log_info(logger, "Configuraciones cargadas correctamente");
    config_destroy(config_fs_open);
}

void cerrar_programa(t_log* logger) {
    log_destroy(logger);
}