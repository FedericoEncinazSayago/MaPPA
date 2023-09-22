#ifndef ESTRUCTURAS_FILESYSTEM_H_
#define ESTRUCTURAS_FILESYSTEM_H_


typedef struct {
    char* ip_memoria; // IP de escucha de la fs
    int puerto_memoria; 
    int puerto_escucha; // Puerto de escucha de la fs
    char* path_fath;
    char* path_bloques;
    char* path_fcb;
    int cant_bloques_total;
    int cant_bloques_swap;
    int tam_bloque;
    int retardo_acceso_bloque;
    int retardo_acceso_fat;
} t_config_fs;

#endif /* ESTRUCTURAS_fs_H_ */