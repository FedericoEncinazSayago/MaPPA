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
#include "../../shared/include/estructuras_shared.h"


t_log * logger;
//semaforos mutex
pthread_mutex_t mutex_estado_new;
pthread_mutex_t mutex_estado_ready;
pthread_mutex_t mutex_estado_exit;
pthread_mutex_t mutex_estado_bloqueado;
//pthread_mutex_t mutex_estado_suspendido;
pthread_mutex_t mutex_estado_ejecutando;

//Semaforo binario
pthread_mutex_t mutex_pcb_ejecutando; //no entiendo si tiene que ser otro tipo de sem

//Semaforos contadores
sem_t sem_multiprogramacion; //inicia en el grado multriprogamacion
sem_t sem_ready; //inicia 0

sem_t sem_fin_proceso; //inicia 0
sem_t sem_bloqueado; //inicia 0
sem_t sem_hay_pcb_esperando_ready; //inicia 0

//listas de cada estado
//uint32_t id_pcb_ejecutando;
t_queue * estado_new;
t_list * estado_ready;
t_list * estado_exec;//capaz no hace falta una lista
t_list * estado_exit;//podria ser una lista es indiferente
t_queue * estado_bloqueado;//asumiendo que se liberan por I/O y en orden usaria cola

//t_pcb * iniciarPcb(t_proceso* proceso);
void inicializarPlanificacion();

//void addEstadoNew(t_pcb* pcb);
//void addEstadoExit(t_pcb* pcb);
//void addEstadoReady(t_pcb* pcb);
//void addEstadoExec(t_pcb* pcb);
//void addEstadoBloqueado(t_pcb* pcb);
void ingresarNew(t_pcb* pcb);
void ingresarReadyDesdeNew(); // siempre es el primero de la cola new
void ingresarReadyDesdeExec();//siempre el unico en exec
void ingresarReadyDesdeBloqueado(); //siempre es el primero de la cola new
void ingresarExec(); // Define quien entre el obtenerSiguienteReady
void ingresarBloqueado(); //siempre el unico en exec
void ingresarExitDesdeNew(); //suponiendo que van por cola estaria correcto esto
void ingresarExitDesdeReady(t_pcb* pcb); //si es lista hay q pasar el pcb cuando usemos distintos algoritmos de planificacion
void ingresarExitDesdeExec();  //solo hay uno a la vez
void ingresarExitDesdeBloq();  //si es por orden no hace falta si no lo mismo que ready

#endif