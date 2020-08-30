#include "GameMaps.h"
#include "level1/level1.h"
#include <stdlib.h>

Map* GameMap_getMaplevel(int level){
    if(level == 1){
        return Level1_getMap();
    }

    return NULL;
}
