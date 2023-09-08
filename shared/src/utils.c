#include "../include/utils.h"
#include <stdio.h>

uint8_t tiene_todas_las_configuraciones(t_config *config, char **configuraciones) {
    for(uint8_t i = 0; configuraciones[i] != NULL; i++) {
        if(!config_has_property(config, configuraciones[i]))
            return false;
    }
    return true;
}

