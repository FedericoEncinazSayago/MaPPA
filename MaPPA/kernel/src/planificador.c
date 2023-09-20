#include "../include/planificador.h"

void incializarPlanificacion(){

}

////////////////////////////////
// Ingresar de cada fila/cola //
///////////////////////////////

// A New

void ingresarNew(char* pcb){
    addEstadoNew(pcb);
    //log_info(logger, "Se agrega el proceso:%d  a new", pcb->id);
    sem_post(&sem_hay_pcb_esperando_ready);
}

// A Ready

void ingresarReadyDesdeNew(){
    sem_wait(&sem_hay_pcb_esperando_ready);
    sem_wait(&sem_multiprogramacion);
    log_info(logger, "Grado multiprogramacion permite entrar");
    char* pcb = obtenerSiguienteNew();
    addEstadoReady(pcb);

}
void ingresarReadyDesdeExec(){
    log_info(logger, "Cambio proceso en ejecucion");
    //deberia haber algo que valide si esta algo en ejecucion?
    char* pcb = obtenerProcesoExec();
    sem_post(&sem_exec);
    addEstadoReady(pcb);
}

void ingresarReadyDesdeBloqueado(){
    sem_wait(&sem_bloqueado);
    log_info(logger, "Se desbloquea un proceso");
    char* pcb = obtenerSiguienteBloqueado();
    addEstadoReady(pcb);
        
}

// A Exec

void ingresarExec(){
    sem_wait(&sem_exec);
    log_info(logger, "Entra proceso a ejecucion");
    char* pcb = obtenerSiguienteReady();
    addEstadoExec(pcb);
}

// A Bloq

void ingresarBloqueado(){
    sem_post(&sem_bloqueado);
    log_info(logger, "Se bloquea un proceso");
    char* pcb = obtenerProcesoExec();
    sem_post(&sem_exec);
    addEstadoBloqueado(pcb);
}

// A Exit

void ingresarExitDesdeNew(){
    char pcb = obtenerSiguienteNew();
    sem_wait(&sem_hay_pcb_esperando_ready);
    addEstadoExit(pcb);
    log_info(logger, "Se libera un proceso desde New");
}

void ingresarExitDesdeReady(char* pcb){
    sem_post(&sem_multiprogramacion);
    addEstadoExit(pcb);
    log_info(logger, "Se libera un proceso desde Ready");
}

void ingresarExitDesdeExec(){
    char pcb = obtenerProcesoExec();
    sem_post(&sem_exec);
    sem_post(&sem_multiprogramacion);
    addEstadoExit(pcb);
    log_info(logger, "Se libera un proceso desde Exec");
}

void ingresarExitDesdeBloq(){
    sem_post(&sem_multiprogramacion);
    sem_wait(&sem_bloqueado);
    char pcb = obtenerSiguienteBloqueado();
    addEstadoExit(pcb);
    log_info(logger, "Se libera un proceso desde Bloqueado");
}

/////////////////////////////////////////
// Obtener siguiente de cada fila/cola //
////////////////////////////////////////

char obtenerSiguienteNew(){
    pthread_mutex_lock(&mutex_estado_new);
    char* pcb = queue_pop(estado_new);
    pthread_mutex_unlock(&mutex_estado_new);
    return pcb;
}

char obtenerSiguienteBloqueado(){
    pthread_mutex_lock(&mutex_estado_bloqueado);
    char* pcb = queue_pop(estado_bloqueado);
    pthread_mutex_unlock(&mutex_estado_bloqueado);
    return pcb;
}
//este va a cambiar segun el algoritmo de planificacion
char obtenerSiguienteReady(){
    pthread_mutex_lock(&mutex_estado_ready);
    char* pcb = queue_pop(estado_ready);
    pthread_mutex_unlock(&mutex_estado_ready);
    return pcb;
}

char obtenerProcesoExec(){
    pthread_mutex_lock(&mutex_estado_ejecutando);
    char* pcb = queue_pop(estado_exec);
    pthread_mutex_unlock(&mutex_estado_ejecutando);
    return pcb;
}

//////////////////////////////
// Añadir de cada fila/cola //
//////////////////////////////

// Add a colas o lista con mutex 
void addEstadoNew(char* pcb){
    pthread_mutex_lock(&mutex_estado_new);
    queue_push(estado_new, (void*) pcb);
    pthread_mutex_unlock(&mutex_estado_new);
}

void addEstadoReady(char* pcb){   
    pthread_mutex_lock(&mutex_estado_ready);
    list_add(estado_ready, (void*) pcb);
    pthread_mutex_unlock(&mutex_estado_ready);
}

void addEstadoExit(char* pcb){   
    pthread_mutex_lock(&mutex_estado_exit);
    queue_push(estado_exit, (void*) pcb);
    pthread_mutex_unlock(&mutex_estado_exit);
}

void addEstadoExec(char* pcb){   
    pthread_mutex_lock(&mutex_estado_ejecutando);
    queue_push(estado_exec, (void*) pcb);
    pthread_mutex_unlock(&mutex_estado_ejecutando);
}

void addEstadoBloqueado(char* pcb){   
    pthread_mutex_lock(&mutex_estado_bloqueado);
    queue_push(estado_bloqueado, (void*) pcb);
    pthread_mutex_unlock(&mutex_estado_bloqueado);
}