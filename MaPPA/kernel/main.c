#include "include/main.h"

int main() {
    t_log* logger_kernel = log_create("kernel.log", "KERNEL", true, LOG_LEVEL_INFO);

    int md_memoria = 0, md_cpu_dt = 0, md_cpu_it = 0, md_fs = 0;

    if(!generar_conexiones(logger_kernel, &md_memoria, &md_cpu_dt, &md_cpu_it, &md_fs)) {
        log_error(logger_kernel, "No se pudieron generar las conexiones");
        return 1;
    }

    send_notas(md_memoria, 10, 10);
    // send_notas(md_fs, 20, 20);  Si anda bien md_memoria probamos con Filesystem

    cerrar_programa(logger_kernel);
    
    return 0;
}
