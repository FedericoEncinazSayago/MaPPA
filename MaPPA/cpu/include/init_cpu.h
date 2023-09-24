#ifndef INIT_CPU_H_
#define INIT_CPU_H_

#include "comunicacion.h"
#include <commons/log.h>
#include <commons/config.h>
#include <commons/string.h>
#include <pthread.h>
#include "../../shared/include/utils.h"
#include "../../shared/include/sockets.h"
#include "../../shared/include/protocolo.h"
#include "estructuras_cpu.h"

bool generar_conexiones(t_log* logger, int* md_memoria);
bool crear_servidores(t_logger* logger, t_config_cpu* config_cpu, int* md_cpu_ds, int* md_cpu_it);
void iniciar_modulo(t_log* logger_cpu, t_config_cpu* config_cpu);
void cerrar_programa(t_log* logger);

#endif
