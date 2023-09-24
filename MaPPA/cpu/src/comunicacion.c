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
            case EJECUTAR_PROCESO:
            {
                t_contexto_ejecucion* proceso;

                if (!rcv_contexto_ejecucion(cliente_socket, &proceso)) {
                    log_error(logger, "Fallo recibiendo EJECUTAR_PROCESO");
                    break;
                }

                ciclo_de_instruccion(proceso);
                send_contexto_ejecucion(cliente_socket, proceso);
                check_interrupt = false;
                break;
            }
            case INTERRUPT:
            {
                check_interrupt = true;
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

int server_escuchar(t_log* logger_server, char* server_name, int socket_server) {
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

void* server_hilo(void* args) {
    t_procesar_server* args_hilo = (t_procesar_server*) args;
    t_log* logger_server = args_hilo->logger;
    char* server_name = args_hilo->server_name;
    int socket_server = args_hilo->socket_server;

    while(server_escuchar(logger_server, server_name, socket_server));

    return NULL;
}



