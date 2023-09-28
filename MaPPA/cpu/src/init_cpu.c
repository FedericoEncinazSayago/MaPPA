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


//    sum(char** registroDestino, char** registroOrigen);
void SUM(t_registros_cpu* registroDestino,  t_registros_cpu* registroOrigen) {
    registroDestino->valor1 += registroOrigen->valor1;
	
       printf("ValorSum: %d\n", registroDestino.valor1);
}



//Propotipo de SUB(AX,&BX) BX guarda la resta de AX

void SUB(t_registros_cpu* registroDestino,  t_registros_cpu* registroOrigen) {

        registroDestino->valor1 -= registroOrigen->valor1;
	
       printf("ValorSub: %d\n", registroDestino.valor1);
}


//Propotipo de EXIT

void EXIT(int contextoDeEjecucion) {
    // Realizar cualquier procesamiento necesario antes de salir

    // Salir del programa con el contexto de ejecución proporcionado
    exit(contextoDeEjecucion);
}

int main() {
    // Realizar operaciones en el programa

    // Llamar a la función EXIT con un contexto específico
    EXIT(42);

    // Este código nunca se ejecutará, ya que EXIT sale del programa
    printf("Este mensaje nunca se mostrará.\n");

    return 0;
}