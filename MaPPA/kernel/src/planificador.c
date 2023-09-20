#include "../include/planificador.h"
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
    //esto deberia estar siempre activo por que es controlado 
    //por semaforo, y seria que siempre que puedo meto a ready
    // otra tarea desde new
    while(1){
        sem_wait(&sem_hay_pcb_esperando_ready);
        sem_wait(&sem_multiprogramacion);  
        log_info(logger, "Grado multiprogramacion permite entrar");
        char* pcb = obtenerSiguienteNew();
        addEstadoReady(pcb);
        sem_post(&sem_ready);
    }
}
void ingresarReadyDesdeExec(){
    //deberia haber algo que valide si esta algo en ejecucion?
    char* pcb = obtenerProcesoExec();
    pthread_mutex_unlock(&mutex_pcb_ejecutando);
    addEstadoReady(pcb);
    sem_post(&sem_ready);
    log_info(logger, "Cambio proceso en ejecucion");
}

void ingresarReadyDesdeBloqueado(){
    sem_wait(&sem_bloqueado);
    char* pcb = obtenerSiguienteBloqueado();
    addEstadoReady(pcb);
    sem_post(&sem_ready);
    log_info(logger, "Se desbloquea un proceso");    
}

// A Exec

void ingresarExec(){
    while(1){
    pthread_mutex_lock(&mutex_pcb_ejecutando);
    sem_wait(&sem_ready);
    char* pcb = obtenerSiguienteReady();
    addEstadoExec(pcb);
    log_info(logger, "Entra proceso a ejecucion");
    }
}

// A Bloq

void ingresarBloqueado(){
    sem_post(&sem_bloqueado);
    char* pcb = obtenerProcesoExec();
    pthread_mutex_unlock(&mutex_pcb_ejecutando);
    addEstadoBloqueado(pcb);
    log_info(logger, "Se bloquea un proceso");
}

// A Exit

void ingresarExitDesdeNew(){ 
    sem_wait(&sem_hay_pcb_esperando_ready);
    char pcb = obtenerSiguienteNew();
    addEstadoExit(pcb);
    log_info(logger, "Se libera un proceso desde New");
}

void ingresarExitDesdeReady(char* pcb){
    sem_wait(&sem_ready);
    sem_post(&sem_multiprogramacion);
    addEstadoExit(pcb);
    log_info(logger, "Se libera un proceso desde Ready");
}

void ingresarExitDesdeExec(){
    //hay que hacer algo que revise que no esta vacio?
    char pcb = obtenerProcesoExec();
    pthread_mutex_unlock(&mutex_pcb_ejecutando);
    sem_post(&sem_multiprogramacion);
    addEstadoExit(pcb);
    log_info(logger, "Se libera un proceso desde Exec");
}

void ingresarExitDesdeBloq(){
    sem_wait(&sem_bloqueado);   
    char pcb = obtenerSiguienteBloqueado();
    addEstadoExit(pcb);
    sem_post(&sem_multiprogramacion);
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