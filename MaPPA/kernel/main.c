#include "include/main.h"

int main() {
    t_log* logger_kernel = log_create("kernel.log", "KERNEL", true, LOG_LEVEL_INFO);

    int md_memoria = 0, md_cpu_dt = 0, md_cpu_it = 0, md_fs = 0;

    if(!generar_conexiones(logger_kernel, &md_memoria, &md_cpu_dt, &md_cpu_it,&md_fs)) {
        log_error(logger_kernel, "No se pudieron generar las conexiones");
        return 1;
    }
    uint8_t pruebadeConsola=0;
    scanf("estamos probando :%hhu",&pruebadeConsola);
    send_notas(md_memoria, 5, 10);
    scanf("estamos probando :%hhu",&pruebadeConsola);
    send_notas(md_fs,9, 10);
    
    scanf("estamos probando :%hhu",&pruebadeConsola);
    send_notas(md_cpu_dt, 7, 10);
    scanf("estamos probando :%hhu",&pruebadeConsola);
    send_notas(md_cpu_it,8, 10);

    cerrar_programa(logger_kernel);
    
    return 0;
}
