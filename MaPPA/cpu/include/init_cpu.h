#ifndef INIT_CPU_H_
#define INIT_MOD2_H_

#include "../../shared/include/sockets.h"
#include "../../shared/include/protocolo.h"

bool generar_conexiones(t_log* logger, int* md_memoria);
void cerrar_programa(t_log* logger);

#endif
