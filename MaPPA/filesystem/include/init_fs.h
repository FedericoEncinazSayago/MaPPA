#ifndef INIT_FILESYSTEM_H_
#define INIT_FILESYSTEM_H_

#include "comunicacion.h"
#include <commons/log.h>
#include <commons/config.h>
#include <commons/string.h>
#include "../../shared/include/utils.h"
#include "../../shared/include/sockets.h"
#include "../../shared/include/protocolo.h"
#include "estructuras_fs.h"

bool generar_conexiones(t_log* logger, int* md_fs); // No sé si lo voy a usar! 
bool cargar_configuraciones( t_config_fs* config_fs, t_log* logger);
void cerrar_programa(t_log* logger);

#endif
