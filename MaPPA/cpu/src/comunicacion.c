#include "../include/comunicacion.h"

void atender_conexion(t_log* logger, char* server_name, int cliente_socket) { // Si el server tuviera que procesar varias solicitudes del mismo cliente, esto debería ser un while
    op_code cop;

    if (recv(cliente_socket, &cop, sizeof(op_code), 0) != sizeof(op_code)) {
        log_info(logger, "DISCONNECT!");

        return;
    }

    switch (cop) {
        case EJECUTAR_PROCESO:
        {
            t_pcb* proceso = rcv_contexto_ejecucion(cliente_socket);

            //ciclo_de_instruccion(proceso);
            send_contexto_ejecucion(RECIBIR_PROCESO, cliente_socket, proceso);
            //check_interrupt = false;
            break;
        }
        case INTERRUPT:
        {
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

void server_escuchar(void* args) {
    printf("prueba 0");
    t_procesar_server* args_hilo = (t_procesar_server*) args;
    t_log* logger_server = args_hilo->logger;
    char* server_name = args_hilo->server_name;
    int socket_server = args_hilo->socket_server;

    printf("prueba 1");
    int socket_cliente = esperar_cliente(logger_server, server_name, socket_server);
    printf("prueba 2");
    while (1)
    {
        printf("prueba 3");
        if(socket_cliente != -1) {
            printf("prueba 4");
            atender_conexion(logger_server, server_name, socket_cliente);            
        }
    }
    printf("prueba 5");
}



