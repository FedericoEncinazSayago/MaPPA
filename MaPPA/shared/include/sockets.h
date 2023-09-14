#ifndef SOCKETS_H_
#define SOCKETS_H_

#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <commons/log.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <errno.h>

#define MAX_RETRIES 5  // Número máximo de intentos de conexión
#define RETRY_INTERVAL_SECONDS 5  // Intervalo entre intentos de conexión

int iniciar_servidor(t_log* logger, const char* name, char* ip, char* puerto);
int esperar_cliente(t_log* logger, const char* name, int socket_servidor);
int crear_conexion(t_log* logger, const char* server_name, char* ip, char* puerto);
void liberar_conexion(int* socket_cliente);

#endif