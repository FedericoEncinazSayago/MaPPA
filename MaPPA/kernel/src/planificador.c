#include "../include/planificador.h"
/////////////////////////
// Inciar planificador //
/////////////////////////

void inicializarPlanificacion(){
    pthread_t tid[5];
    int HiloReadyDesdeNew = pthread_create(&(tid[0]), NULL, ingresarReadyDesdeNew, NULL);
    int HiloExec = pthread_create(&(tid[1]), NULL, ingresarExec, NULL);
    pthread_join(HiloReadyDesdeNew,NULL);
    pthread_join(HiloExec,NULL);
}

///////////////
// crear pcb //
///////////////


t_pcb* iniciarPcb(){ //t_proceso* proceso estaria bueno para definir la data que venga de lo que se lea en consola
    pid_nuevo = pid_nuevo+1;
    t_pcb* pcb = malloc(sizeof(t_pcb));
    pcb->pid = pid_nuevo;
    pcb->program_counter = 0; //a definir segun el path 
    pcb->registros = NULL;
    pcb->archivos_abiertos = NULL;

    return pcb;
}


////////////////////////////////
// Ingresar de cada fila/cola //
///////////////////////////////

// A New
void ingresarNew(t_pcb* pcb){
    addEstadoNew(pcb);
    log_info(logger, "Se agrega el proceso:%d  a new", pcb->pid);
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
        t_pcb* pcb = obtenerSiguienteNew();
        addEstadoReady(pcb);
        log_info(logger, "Se agrega el proceso:%d  a Ready desde New", pcb->pid);
        sem_post(&sem_ready);
    }
}
void ingresarReadyDesdeExec(){
    //deberia haber algo que valide si esta algo en ejecucion?
    t_pcb* pcb = obtenerProcesoExec();
    if (pcb != NULL) {
        pthread_mutex_unlock(&mutex_pcb_ejecutando);
        addEstadoReady(pcb);
        log_info(logger, "Se agrega el proceso:%d  a Ready desde Exec",pcb->pid);
        sem_post(&sem_ready);
        log_info(logger, "");
    }
}

void ingresarReadyDesdeBloqueado(){
    sem_wait(&sem_bloqueado);
    t_pcb* pcb = obtenerSiguienteBloqueado();
    addEstadoReady(pcb);
    sem_post(&sem_ready);
    log_info(logger, "Se agrega el proceso:%d  a Ready desde Bloqueado", pcb->pid);   
}

// A Exec

void ingresarExec(){
    while(1){
    pthread_mutex_lock(&mutex_pcb_ejecutando);
    sem_wait(&sem_ready);
    t_pcb* pcb = obtenerSiguienteReady();
    addEstadoExec(pcb);
    log_info(logger, "Se agrega el proceso:%d  a Exec desde Ready", pcb->pid);
    }
}

// A Bloq

void ingresarBloqueado(){ // si solo se entre por I/O y los I/O son siempre temporales estaria bueno definir como parametro cuanto tiempo se bloquea y asi se va liberando
    sem_post(&sem_bloqueado);
    t_pcb* pcb = obtenerProcesoExec();
    pthread_mutex_unlock(&mutex_pcb_ejecutando);
    addEstadoBloqueado(pcb);
    log_info(logger, "Se agrega el proceso:%d  a Exec desde Bloqueado", pcb->pid);
}

// A Exit (preguntar si es correcto sacar el proximo en ejecucion
// o hay que hace exit de algun de forma especifica,
// en este caso hay que diseñar una funcion general y que revise
// donde esta el PCB y luego sacarlo de ahi y mandarlo a exit

//void ingresarExit(t_pcb* pcb){
//    
//}

void ingresarExitDesdeNew(){ 
    sem_wait(&sem_hay_pcb_esperando_ready);
    t_pcb* pcb = queue_pop(estado_new);
    addEstadoExit(pcb);
    log_info(logger, "Se agrega el proceso:%d  a Exit desde New", pcb->pid);
}

void ingresarExitDesdeReady(t_pcb* pcb){
    sem_wait(&sem_ready);
    sem_post(&sem_multiprogramacion);
    t_pcb* pcb = obtenerSiguienteReady(); 
    addEstadoExit(pcb);
    log_info(logger, "Se agrega el proceso:%d  a Exit desde Ready", pcb->pid);
}

void ingresarExitDesdeExec(){
    //hay que hacer algo que revise que no esta vacio?
    t_pcb* pcb = obtenerProcesoExec();
    pthread_mutex_unlock(&mutex_pcb_ejecutando);
    sem_post(&sem_multiprogramacion);
    addEstadoExit(pcb);
    log_info(logger, "Se agrega el proceso:%d  a Exit desde Exec", pcb->pid);
}

void ingresarExitDesdeBloq(){
    sem_wait(&sem_bloqueado);   
    t_pcb* pcb = obtenerSiguienteBloqueado();
    addEstadoExit(pcb);
    sem_post(&sem_multiprogramacion);
    log_info(logger, "Se agrega el proceso:%d  a Exit desde Exec", pcb->pid);
}

/////////////////////////////////////////
// Obtener siguiente de cada fila/cola //
////////////////////////////////////////

t_pcb* obtenerSiguienteNew(){
    pthread_mutex_lock(&mutex_estado_new);
    t_pcb* pcb = queue_pop(estado_new);
    pthread_mutex_unlock(&mutex_estado_new);
    return pcb;
}

t_pcb* obtenerSiguienteBloqueado(){
    pthread_mutex_lock(&mutex_estado_bloqueado);
    t_pcb* pcb = queue_pop(estado_bloqueado);
    pthread_mutex_unlock(&mutex_estado_bloqueado);
    return pcb;
}
//este va a cambiar segun el algoritmo de planificacion
t_pcb* obtenerSiguienteReady(){
    pthread_mutex_lock(&mutex_estado_ready);
    t_pcb* pcb = list_get(estado_ready,0);
    list_remove(estado_ready,0);
    pthread_mutex_unlock(&mutex_estado_ready);
    return pcb;
}

t_pcb* obtenerProcesoExec(){
    pthread_mutex_lock(&mutex_estado_ejecutando);
    t_pcb* pcb = list_get(estado_exec,0);
    list_remove(estado_exec,0);
    pthread_mutex_unlock(&mutex_estado_ejecutando);
    return pcb;
}

//////////////////////////////
// Añadir de cada fila/cola //
//////////////////////////////

// Add a colas o lista con mutex 
void addEstadoNew(t_pcb* pcb){
    pthread_mutex_lock(&mutex_estado_new);
    queue_push(estado_new, (void*) pcb);
    pthread_mutex_unlock(&mutex_estado_new);
}

void addEstadoReady(t_pcb* pcb){   
    pthread_mutex_lock(&mutex_estado_ready);
    list_add(estado_ready, pcb);
    pthread_mutex_unlock(&mutex_estado_ready);
}

void addEstadoExit(t_pcb* pcb){   
    pthread_mutex_lock(&mutex_estado_exit);
    list_add(estado_exit, pcb);
    pthread_mutex_unlock(&mutex_estado_exit);
}

void addEstadoExec(t_pcb* pcb){   
    pthread_mutex_lock(&mutex_estado_ejecutando);
    list_add(estado_exec, pcb);
    pthread_mutex_unlock(&mutex_estado_ejecutando);
}

void addEstadoBloqueado(t_pcb* pcb){   
    pthread_mutex_lock(&mutex_estado_bloqueado);
    queue_push(estado_bloqueado,pcb);
    pthread_mutex_unlock(&mutex_estado_bloqueado);
}

