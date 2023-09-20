#include "include/main.h"


int main() {

    t_log* logger_m = log_create("memoria.log", "MEMORIA", true, LOG_LEVEL_INFO);

    

    cerrar_programa(logger_m);

    return 0;
}