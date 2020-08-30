#include "ElementController.h"



void ElementControllerRunEnimiesActionIn(Element* enemieElement,Element*targetElement){

}


void ElementControllerRunPlayerActionIn(Element* playerElement,Element* targetElement){
    if((!Element_hasAction(targetElement))){
        return;
    }
    switch(Element_type(targetElement)){
    case BACKGROUND_TYPE :
    break;
    case WALL_TYPE :

    break;
    case OBJECT_TYPE :

    break;
    case OBJECT_TYPE_KEY :
        /*Key_runActionItPlayer(playerElement,targetElement);*/
        Element_setKey(playerElement);
        Element_setRemoved(targetElement);


    break;
    case OBJECT_TYPE_DOOR :
        if(Element_getKey(playerElement)){
            GameController_NextLevel();
        }
    break;
    case ENEMIES_TYPE :
    break;
    case PLAYER_TYPE :
    break;
    default:

    break;

    }



}

void ElementController_RunAction(Element* targetElement,Element* actorElement){
     switch(Element_type(actorElement)){
    case BACKGROUND_TYPE :
    break;
    case WALL_TYPE :
    break;
    case OBJECT_TYPE :

    break;
    case OBJECT_TYPE_KEY :
    break;
    case OBJECT_TYPE_DOOR :
    break;
    case ENEMIES_TYPE :
        ElementControllerRunEnimiesActionIn(actorElement,targetElement);
    break;
    case PLAYER_TYPE :
         ElementControllerRunPlayerActionIn(actorElement,targetElement);
    break;
    default:
    break;

    }

}




