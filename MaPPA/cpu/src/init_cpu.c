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

}

void SUM (char resgistroA, char registroB){

    t_registros_cpu* resgistroAAplicar;

    t_registros_cpu* registroBaSumar;

    //AX

        if(resgistroA=='AX'&& registroB=='BX') resgistroAAplicar->AX+registroBaSumar->BX;

        else if(resgistroA=='AX'&& registroB=='CX') resgistroAAplicar->AX+registroBaSumar->CX;

        else if(resgistroA=='AX'&& registroB=='DX') resgistroAAplicar->AX+registroBaSumar->DX;

    //BX

        else if(resgistroA=='BX'&& registroB=='AX') resgistroAAplicar->BX+registroBaSumar->AX;

        else if(resgistroA=='BX'&& registroB=='CX') resgistroAAplicar->BX+registroBaSumar->CX;

        else if(resgistroA=='BX'&& registroB=='DX') resgistroAAplicar->BX+registroBaSumar->DX;

    //CX

        else if(resgistroA=='CX'&& registroB=='AX') resgistroAAplicar->CX+registroBaSumar->AX;

        else if(resgistroA=='CX'&& registroB=='BX') resgistroAAplicar->CX+registroBaSumar->BX;

        else if(resgistroA=='CX'&& registroB=='DX') resgistroAAplicar->CX+registroBaSumar->DX;

    //DX

        else if(resgistroA=='DX'&& registroB=='AX') resgistroAAplicar->DX+registroBaSumar->AX;

        else if(resgistroA=='DX'&& registroB=='BX') resgistroAAplicar->DX+registroBaSumar->BX;

        else if(resgistroA=='DX'&& registroB=='CX') resgistroAAplicar->DX+registroBaSumar->CX;

}