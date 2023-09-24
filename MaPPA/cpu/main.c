#include "include/main.h"

t_config_cpu *config_cpu;

void iniciarlizar_config() {
    config_cpu = malloc(sizeof(t_config_cpu));
    config_cpu->ip_memoria = NULL;
    config_cpu->puerto_memoria = 0;
    config_cpu->puerto_escucha_dispatch = 0;
    config_cpu->puerto_escucha_interrupt = 0;
}

int main() {
    t_log* logger_cpu = log_create("cpu.log", "CPU", true, LOG_LEVEL_INFO);
    iniciarlizar_config();

    // me traigo del archivo config los valores
    if(!cargar_configuraciones(config_cpu, logger_cpu)) {
        log_error(logger_cpu, "No se pudieron cargar las configuraciones del cpu");

        return 1;
    }

    iniciar_modulo(logger_cpu, config_cpu); // Acá voy a crear el servidor con las cosas!

    cerrar_programa(logger_cpu);

    return 0;
}