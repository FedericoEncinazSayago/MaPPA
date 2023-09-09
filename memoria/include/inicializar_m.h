#ifndef INICIAR_MEMORIA_H_
#define INICIAR_MEMORIA_H_

#include <commons/config.h>
#include <commons/string.h>
#include <commons/log.h>
#include <commons/collections/list.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "../../shared/include/sockets.h"
#include "../../shared/include/utils.h"
#include "config.h"


void cargar_configuraciones(t_config_memoria *config_memoria);

#endif
