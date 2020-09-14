#include "ElementController.h"
#include "../../Modules/Element/ElementList/ElementList.h"
#include "../EnemieController/EnemieController.h"
#include "../../Modules/Player/player.h"
#include "../Arena/ArenaController.h"
#include "../Level/LevelController.h"

void *ElementController_Change(ElementList* arena){
        EnemieController_Move(arena);
        return (void *)0;
}
void ElementControllerRunEnimiesActionIn(Element* enemieElement,Element*targetElement){

    switch(Element_type(targetElement)){
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
    break;
    case PLAYER_TYPE :
        ArenaController_PlayerKill();
    break;
    default:

    break;

    }
    return;
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
        Player_setKey(playerElement);
        Element_setRemoved(targetElement);


    break;
    case OBJECT_TYPE_DOOR :
        if(Player_getKey(playerElement)){
            LevelController_Finished();
        }
//}
    break;
    case ENEMIES_TYPE :
        ArenaController_PlayerKill();
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




