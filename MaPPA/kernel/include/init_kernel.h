#ifndef INIT_KERNEL_H_
#define INIT_KERNEL_H_

#include <stdio.h>
#include <stdbool.h>
#include <commons/config.h>
#include <commons/string.h>
#include "estructuras_kernel.h"
#include "../../shared/include/sockets.h"
#include "../../shared/include/utils.h"
#include "consola.h"

bool generar_conexiones(t_log* logger, t_config_k* config_kernel ,int* md_memoria, int* md_cpu_dt, int* md_cpu_it, int* md_fs);
bool cargar_configuraciones(t_config_k* config_kernel, t_log* logger);
void cerrar_programa(t_log *logger);

void  iniciar_modulo();

#endif
