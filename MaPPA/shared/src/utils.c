#include "../include/utils.h"

bool tiene_todas_las_configuraciones(t_config* config, char* configs[]) {  
    for(size_t i = 0; configs[i] !=  NULL; i++) {
        if(!config_has_property(config, configs[i]))
            return false;
    }

    return true;
}