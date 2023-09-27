#include "../include/init_cpu.h"



bool generar_conexiones(t_log* logger, int* md_memoria) {

    

    // no es el puerto correcto, pero debo levantar por config

    char* puerto_memoria = "8002";

    char* ip = "127.0.0.1";



    *md_memoria = crear_conexion(logger, "MEMORIA", ip, puerto_memoria); // No harcodearlo! Sino leerlo de kernel.config

    // No existe valores por referencias en C! Primero le sacamos la direccion de memoria a la variable, y despues con *variable asignamos el nuevo valor!



    return *md_memoria != 0; // Aca pregunto por el nuevo valor!

}



void cerrar_programa(t_log* logger) {

    log_destroy(logger);

}

//Propotipo de SET(AX,23) transfomrar el uint_t var 

//prototipo de SUM(AX,&BX) BX guarda la suma de AX

void SET(char registro,uint8_t valor){

    t_registros_cpu* registroAAplicar;

    switch (registro){

        case 'AX':

            registroAAplicar->AX=valor;

        break;

        case 'BX':

            registroAAplicar->BX=valor;

        break;

        case 'CX':

            registroAAplicar->CX=valor;

        break;

        case 'DX':

            registroAAplicar->DX=valor;

        break;

    }
    //operacion=""
    //linea=ReadLine("<") ejemploFucion
    //sscanf(linea,"%99",operacion)
    //ejemplo
}

void SUM (char registroA, char registroB){

    t_registros_cpu* registroDestino;

    t_registros_cpu* registroOrigen;

    //Probar Codigo 

    //AX

        if(registroA=='AX'&& registroB=='BX') registroDestino->AX= registroDestino->AX+registroOrigen->BX;

        else if(registroA=='AX'&& registroB=='CX') registroDestino->AX=registroDestino->AX+registroOrigen->CX;

        else if(registroA=='AX'&& registroB=='DX') registroDestino->AX=registroDestino->AX+registroOrigen->DX;

    //BX

        else if(registroA=='BX'&& registroB=='AX') registroDestino->BX=registroDestino->BX+registroOrigen->AX;

        else if(registroA=='BX'&& registroB=='CX') registroDestino->BX=registroDestino->BX+registroOrigen->CX;

        else if(registroA=='BX'&& registroB=='DX') registroDestino->BX=registroDestino->BX+registroOrigen->DX;

    //CX

        else if(registroA=='CX'&& registroB=='AX') registroDestino->CX=registroDestino->CX+registroOrigen->AX;

        else if(registroA=='CX'&& registroB=='BX') registroDestino->CX=registroDestino->CX+registroOrigen->BX;

        else if(registroA=='CX'&& registroB=='DX') registroDestino->CX=registroDestino->CX+registroOrigen->DX;

    //DX

        else if(registroA=='DX'&& registroB=='AX') registroDestino->DX=registroDestino->DX+registroOrigen->AX;

        else if(registroA=='DX'&& registroB=='BX') registroDestino->DX=registroDestino->DX+registroOrigen->BX;

        else if(registroA=='DX'&& registroB=='CX') registroDestino->DX=registroDestino->DX+registroOrigen->CX;

}