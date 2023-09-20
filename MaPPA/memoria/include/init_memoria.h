#ifndef INIT_MEMORIA_H_
#define INIT_MOD3_H_

#include "comunicacion.h"
#include <commons/log.h>
#include <commons/config.h>
#include <commons/string.h>
#include "../../shared/include/utils.h"
#include "../../shared/include/sockets.h"
#include "../../shared/include/protocolo.h"

bool generar_conexiones(t_log* logger, int* md_fs);
void cerrar_programa(t_log* logger);

#endif
