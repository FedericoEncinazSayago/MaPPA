#ifndef ESTRUCTURAS_CPU_H_
#define ESTRUCTURAS_CPU_H_


typedef struct {
    char* ip_memoria; 
    int puerto_memoria; 
    int puerto_escucha_dispatch; 
    int puerto_escucha_interrupt; 

} t_config_cpu;

#endif /* ESTRUCTURAS_cpu_H_ */