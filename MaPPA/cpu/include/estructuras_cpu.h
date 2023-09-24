#ifndef ESTRUCTURAS_CPU_H_
#define ESTRUCTURAS_CPU_H_
typedef struct {
    char* ip_memoria; 
    int puerto_memoria; 
    int puerto_escucha_dispatch; 
    int puerto_escucha_interrupt; 
} t_config_cpu;

typedef struct {
    t_log* logger;
    char* server_name;
    int socket_server;
} t_procesar_server;

extern t_config_cpu* config_cpu;

#endif /* ESTRUCTURAS_cpu_H_ */