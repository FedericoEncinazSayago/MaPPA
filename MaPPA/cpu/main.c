#include "include/main.h"

int main() {
    t_log* logger_cpu = log_create("cpu.log", "CPU", true, LOG_LEVEL_INFO);

    // me traigo del archivo config los valores
    if(!cargar_configuraciones(config_cpu, logger_cpu)) { // Traigo las configuraciones de fsconfig_fs!
        log_error(logger_cpu, "No se pudieron cargar las configuraciones del cpu");

        return 1;
    }

    iniciar_modulo(config_cpu, logger_cpu); // Acá voy a crear el servidor con las cosas!

    cerrar_programa(logger_cpu);

    return 0;
}