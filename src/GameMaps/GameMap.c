#include "GameMaps.h"
#include "level1/level1.h"
#include "level2/level.h"
#include <stdlib.h>

Map* GameMap_getMaplevel(int level){
    switch(level){
        case 1:
            return Level1_getMap();
        break;
        case 2:
            return Level2_getMap();
        break;
    }

    return NULL;
}
