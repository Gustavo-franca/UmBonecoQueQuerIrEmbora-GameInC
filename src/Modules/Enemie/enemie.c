#include "Enemie.h"


#include <stdlib.h>
struct _EnemiesProps{
    int direction;
    int typeMove;
};

typedef struct _EnemiesProps EnemiesProps;

Element* Enemie_create(char symbol,int color,int typeMove){

    EnemiesProps* props = (EnemiesProps*) malloc(sizeof(EnemiesProps));
    props->typeMove = typeMove;
    switch(typeMove){
    case ENEMIE_DIRECTION_HORIZONTAL:;
        props->direction = LEFT;
    break;
    case ENEMIE_DIRECTION_VERTICAL :
        props->direction = UP;
    break;
    case ENEMIE_DIRECTION_RANDOM:
        props->direction = 0;
    break;
    default:
        return NULL;
    }
    return Element_create(ENEMIES_TYPE,symbol,color,(void*)props);
}
int Enemie_getTypeMove(Element* enemie){
    EnemiesProps* props = (EnemiesProps*) Element_getEspecProps(enemie);
    return props->typeMove;
}

int direction = 4;
void Enemie_setDirection(Element* enemie,int number){
    EnemiesProps* props = (EnemiesProps*) Element_getEspecProps(enemie);
    return props->direction  = number;
}
int Enemie_getDirection(Element* enemie){
    EnemiesProps* props = (EnemiesProps*) Element_getEspecProps(enemie);
    return props->direction;
}
