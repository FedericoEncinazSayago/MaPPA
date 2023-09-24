#include "../include/consola.h"

void iniciarConsola(){
    char * operacion = "";
    while(1){ 
        char* linea = readline("> ");

        if(sscanf(linea, "%99s", operacion) == 1) {
            if (operacion = "INICIAR_PROCESO"){
                printf("Entre a Inciar proceso");
                //create hilo 
                        //t_pcb* pcb = inciarPCB()
                        //ingresarNew(pcb);
                //join hilo
            }else if (operacion = "FINALIZAR_PROCESO"){
                printf("Entre Finalizar proceso");
                //ingresarExit(PID);
            }else if(operacion = "DETENER_PLANIFICACION"){
                printf("Entre DETENER_PLANIFICACION");

            }else if(operacion = "INICIAR_PLANIFICACION"){
                printf("Entre INICIAR_PLANIFICACION");

            }else if(operacion = "MULTIPROGRAMACION"){
                printf("Entre MULTIPROGRAMACION");

            }else if(operacion = "PROCESO_ESTADO"){
                printf("Entre PROCESO_ESTADO");

            }else {
                printf("La funcion no existe!\n");

            }
        } else {
            printf("No se pudo leer la palabra.\n");
        }       
    }
}