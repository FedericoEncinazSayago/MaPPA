#include "../include/comunicacion.h"

void atender_conexion(t_log* logger, int cliente_socket) { // Si el server tuviera que procesar varias solicitudes del mismo cliente, esto debería ser un while
    op_code cop;

    if (recv(cliente_socket, &cop, sizeof(op_code), 0) != sizeof(op_code)) {
        log_info(logger, "DISCONNECT!");

        return;
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

    log_warning(logger, "El cliente se desconecto de %s server", server_name);

    return;
}

void* server_escuchar(void* args) {
    t_procesar_server* args_hilo = (t_procesar_server*) args;
    t_log* logger_server = args_hilo->logger;
    char* server_name = args_hilo->server_name;
    int socket_server = args_hilo->socket_server;

    while (1)
    {
        int socket_cliente = esperar_cliente(logger_server, server_name, socket_server);

        if(socket_cliente != -1) {
            atender_conexion(logger_server, socket_cliente);            

            continue;
        }
    }

    return NULL;
}



