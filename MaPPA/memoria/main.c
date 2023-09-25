#include "include/main.h"

// esto hace que cuando cierro modulo con Ctrl + C maneja el cierre para no romper
t_log* logger;

void sighandler(int s) {
    cerrar_programa(logger);
    exit(0);
}

t_config_memoria* config_memoria;

void inicializar_config(void) { // Voy a inicializar config de memoria!s
    config_memoria = malloc(sizeof(t_config_memoria));
    config_memoria->ip_fs = NULL;
    config_memoria->ip_escucha = NULL;
    config_memoria->path_instrucciones = NULL;
    config_memoria->algoritmo_reemplazo = NULL;
} 

int main() {

    t_log* logger_m = log_create("memoria.log", "MEMORIA", true, LOG_LEVEL_INFO);
    inicializar_config();

    if(!cargar_configuraciones(config_memoria, logger_m)) { // Traigo las configuraciones de memoria!
        log_error(logger_m, "No se pudieron cargar las configuraciones de memoria");

        return 1;
    }

    t_pcb* pcb = malloc(sizeof(t_pcb));
    pcb->pid = 1;
    pcb->program_counter = 0;
    pcb->registros = malloc(sizeof(t_registros_cpu));
    pcb->registros->AX = 0;
    pcb->registros->BX = 0;
    pcb->registros->CX = 0;
    pcb->registros->DX = 0;
    pcb->archivos_abiertos = list_create();

    iniciar_modulo(logger_m, config_memoria); // Acá voy a crear el servidor con las cosas!

    cerrar_programa(logger_m);

    return 0;
}