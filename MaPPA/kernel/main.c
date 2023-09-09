#include "include/main.h"

int main() {
    t_log* logger_kernel = log_create("kernel.log", "KERNEL", true, LOG_LEVEL_INFO);

    int md_memoria = 0;

    if(!generar_conexiones(logger_kernel, &md_memoria) {
        log_error(logger_kernel, "No se pudieron generar las conexiones");
        return 1;
    }

    send_notas(md_memoria, 10, 10);
    // send_notas(md_fs, 20, 20);  Si anda bien md_memoria probamos con Filesystem

    cerrar_programa(logger_kernel);
    
    return 0;
}
