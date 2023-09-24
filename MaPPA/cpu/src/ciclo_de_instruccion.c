bool check_interrupt = false;

void ciclo_de_instruccion(t_contexto_ejecucion proceso) {
    int md_memoria = crear_conexion(); // Conectamos con memoria!

    while(1) {
        send_instruccion(md_memoria, proceso); // Le enviamos la instruccion a memoria -> fetch
        t_instruccion ins = rcv_instruccion(md_memoria); // Recibimos la instruccion de memoria -> decode


        switch(op_code) { // En proceso de creacion! 
            case SET:
            case SUM:
            case SUB:
        }
        
        if(check_interrupt) {
            break;
        }
        
    }
}