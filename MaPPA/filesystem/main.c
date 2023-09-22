#include "include/main.h"

// esto hace que cuando cierro modulo con Ctrl + C maneja el cierre para no romper
t_log* logger;

void sighandler(int s) {
    cerrar_programa(logger);
    exit(0);
}

// levanto los parametros del config
t_config_fs* config_fs;

void inicializar_config(void) { // Voy a inicializar config de fs!s
    config_fs = malloc(sizeof(t_config_fs));    // define el tamaño total del config
    config_fs->ip_memoria = NULL;
    config_fs->path_fath = NULL;
    config_fs->path_bloques = NULL;
    config_fs->path_fcb = NULL;
}

int main() {

    t_log* logger_fs = log_create("filesystem_memoria.log", "FILESYSTEM", true, LOG_LEVEL_INFO);


    // me traigo del archivo config los valores
    if(!cargar_configuraciones(config_fs, logger_fs)) { // Traigo las configuraciones de fsconfig_fs!
        log_error(logger_fs, "No se pudieron cargar las configuraciones del fs");

        return 1;
    }

    iniciar_modulo(); // Acá voy a crear el servidor con las cosas!

    cerrar_programa(logger_fs);

    return 0;
}