#ifndef PLANIFICADOR_H_
#define PLANIFICADOR_H_

#include <stdio.h>
#include <stdbool.h>
#include <semaphore.h>
#include <pthread.h>
#include <commons/string.h>
#include <commons/collections/list.h>
#include <commons/collections/queue.h>
#include <commons/log.h>
#include "../../shared/include/sockets.h"
#include "../../shared/include/utils.h"


t_log * logger;
//semaforos mutex
pthread_mutex_t mutex_estado_new;
pthread_mutex_t mutex_estado_ready;
pthread_mutex_t mutex_estado_exit;
pthread_mutex_t mutex_estado_bloqueado;
//pthread_mutex_t mutex_pcb_ejecutando;
//pthread_mutex_t mutex_estado_suspendido;
pthread_mutex_t mutex_estado_ejecutando;


//Semaforos contadores
sem_t sem_multiprogramacion;
sem_t sem_ready;
sem_t sem_exec;
sem_t sem_fin_proceso;
sem_t sem_bloqueado;
sem_t sem_hay_pcb_esperando_ready;

//listas de cada estado
//uint32_t id_pcb_ejecutando;
t_queue * estado_new;
t_queue * estado_ready;//despues sera una lista para poder elegir quien va a exec
t_queue * estado_exec;//capaz no hace falta una lista
t_queue * estado_exit;//podria ser una lista es indiferente
t_queue * estado_bloqueado;//asumiendo que se liberan por I/O y en orden usaria cola

//t_pcb * iniciarPcb(t_proceso* proceso);
void inicializarPlanificacion();
void addEstadoNew(char* pcb);
void addEstadoExit(char* pcb);
void addEstadoReady(char* pcb);
void addEstadoExec(char* pcb);
void addEstadoBloqueado(char* pcb);
void ingresarNew(char* pcb);
void ingresarReadyDesdeNew(); // siempre es el primero de la cola new
void ingresarReadyDesdeExec();//siempre el unico en exec
void ingresarReadyDesdeBloqueado(); //siempre es el primero de la cola new
void ingresarExec(); // Define quien entre el obtenerSiguienteReady
void ingresarBloqueado(); //siempre el unico en exec
void ingresarExitDesdeNew(); //suponiendo que van por cola estaria correcto esto
void ingresarExitDesdeReady(char* pcb); //si es lista hay q pasar el pcb cuando usemos distintos algoritmos de planificacion
void ingresarExitDesdeExec();  //solo hay uno a la vez
void ingresarExitDesdeBloq();  //si es por orden no hace falta si no lo mismo que ready

#endif