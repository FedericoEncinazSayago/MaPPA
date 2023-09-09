#include "include/inicializar_fs.h"
#include "include/config.h"

t_config_fs *config_fs;
extern t_log* logger_fs;

void inicializar_fs() {
    config_fs = malloc(sizeof(t_config_fs));
    config_fs->IP_MEMORIA = NULL;
    config_fs->PATH_FAT = NULL;
    config_fs->PATH_BLOQUES = NULL;
    config_fs->PATH_FCB = NULL;
}

#include <stdio.h>
int main() {
	logger_fs = log_create("FS_SERVER.log", "FS_SERVER", true, LOG_LEVEL_INFO);

	int fs_server = iniciar_servidor(logger_fs, "FS SERVER","127.0.0.1" ,"8008");

	if (fs_server == -1) {
		log_error(logger_fs, "No se pudo iniciar el servidor");
	    exit(EXIT_FAILURE);
	        }

	//Ver Hilos para la conexion al servidor

	int cliente_server_k= esperar_cliente(logger_fs,"KERNEL",fs_server);
	recibir_mensaje(cliente_server_k,logger_fs);

	char* ip_memoria = "127.0.0.1"; // No HARDCODEAR!
	char* puerto_memoria = "8012";
	int md_memoria = crear_conexion(logger_fs,"Memoria",ip_memoria ,puerto_memoria );
	enviar_mensaje("HOLA MEMORIA",md_memoria);

    return 0;
}
