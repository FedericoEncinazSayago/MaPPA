#include "../include/comunicacion.h"

static void atender_conexiones(void* args) {
    t_procesar_conexion* args_hilo = (t_procesar_conexion*) args;
    t_log* logger = args_hilo->logger;
    int cliente_socket = args_hilo->socket_cliente;
    char* server_name = args_hilo->server_name;
    free(args);

    op_code cop;
    while (cliente_socket != -1) {

        if (recv(cliente_socket, &cop, sizeof(op_code), 0) != sizeof(op_code)) {
            log_info(logger, "DISCONNECT!");
            break;
        }

        switch (cop) {
            case NOTAS:
            {
                uint8_t nota1, nota2;

                if (!rcv_notas(cliente_socket, &nota1, &nota2)) {
                    log_error(logger, "Fallo recibiendo APROBAR_OPERATIVOS");
                    break;
                }

                log_info(logger, "Aprobe operativos con %" PRIu8 " y %" PRIu8 "!", nota1, nota2);

                break;
            }

            // Errores
            case -1:
                log_error(logger, "Cliente desconectado de %s...", server_name);
                return;
            default:
                log_error(logger, "Algo anduvo mal en el server de %s", server_name);
                return;
        }
    }

    log_warning(logger, "El cliente se desconecto de %s server", server_name);
    return;
}


int server_escucha(t_log* logger_server, char* server_name, int socket_server) {
    int socket_cliente = esperar_cliente(logger_server, server_name, socket_server);

    if(socket_cliente != -1) {
        pthread_t hilo_conexiones;
        t_procesar_conexion* args = malloc(sizeof(t_procesar_conexion));
        args->logger = logger_server;
        args->socket_cliente = socket_cliente;
        args->server_name = server_name;
        pthread_create(&hilo_conexiones, NULL, (void*) atender_conexiones, (void*) args);
        pthread_detach(hilo_conexiones);

        return 1;
    }

    return 0;
}