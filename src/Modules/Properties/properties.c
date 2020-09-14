#include "properties.h"
#include <stdlib.h>

struct _Properties {
    int type;
    int isTransposable;
    int interaction;
    int removed;
    void * especific;

};

Properties* Properties_SetInitialPropertiesForType(int type,void * especific){
    Properties* properties = (Properties*) malloc(sizeof(Properties));
    properties->type = type;
    properties->removed = 0;
    properties->especific = especific;
    switch(type){
    case BACKGROUND_TYPE :
        properties->isTransposable = 1;
        properties->interaction = 0;
    break;
    case WALL_TYPE :
        properties->isTransposable = 0;
        properties->interaction = 0;
    break;
    case OBJECT_TYPE :
    case OBJECT_TYPE_KEY :
    case OBJECT_TYPE_DOOR :
        properties->isTransposable = 0;
        properties->interaction = 1;
    break;
    case ENEMIES_TYPE :
        properties->isTransposable = 0;
        properties->interaction = 1;
    break;
    case PLAYER_TYPE :
        properties->isTransposable = 1;
        properties->interaction = 0;
    break;
    default:
        properties->isTransposable =0;
        properties->interaction = 0;
        properties->type = 0;
    break;

    }

    return properties;
}

int Properties_isTransposable(Properties* properties){
 if(properties->isTransposable == 0){
        return 0;
    }
    return 1;
}

int Properties_setRemoved(Properties* targetProperties){
    return targetProperties->removed = 1;
}

int Properties_IsRemoved(Properties* targetProperties){
    return targetProperties->removed;
}

int Properties_hasAction(Properties* targetProperties){
    return targetProperties->interaction;
}

int Properties_type(Properties* targetProperties){
    return targetProperties->type;
}

void * Properties_getEspecProps(Properties* properties){
    return properties->especific;
}

