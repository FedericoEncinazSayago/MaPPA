#ifndef INIT_CPU_H_
#define INIT_CPU_H_

#include "comunicacion.h"
#include <commons/log.h>
#include <commons/config.h>
#include <commons/string.h>
#include "../../shared/include/utils.h"
#include "../../shared/include/sockets.h"
#include "../../shared/include/protocolo.h"
#include "estructuras_cpu.h"

bool generar_conexiones(t_log* logger, int* md_memoria);
void cerrar_programa(t_log* logger);

#endif
