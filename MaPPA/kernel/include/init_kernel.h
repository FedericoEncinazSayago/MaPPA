#ifndef INIT_KERNEL_H_
#define INIT_MOD1_H_

#include "../../shared/include/sockets.h"
#include "../../shared/include/protocolo.h"

bool generar_conexiones(t_log* logger, int *md_memoria, int *md_cpu_dt, int *md_cpu_it, int *md_fs);
void cerrar_programa(t_log* logger);

#endif