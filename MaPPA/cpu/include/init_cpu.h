#ifndef INIT_CPU_H_
#define INIT_MOD2_H_

#include "../../shared/include/sockets.h"
#include "../../shared/include/protocolo.h"
#include "../../shared/include/estructuras_shared.h"
bool generar_conexiones(t_log* logger, int* md_memoria);
void cerrar_programa(t_log* logger);
void SUM(t_registros_cpu* registroDestino,  t_registros_cpu* registroOrigen) ;
void SET(char* registro,uint8_t valor);

void SUB(t_registros_cpu* registroDestino,  t_registros_cpu* registroOrigen) ;
#endif