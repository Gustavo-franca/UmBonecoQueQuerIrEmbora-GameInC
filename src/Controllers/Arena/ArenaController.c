#include "ArenaController.h"
#include <time.h> // time
#include <unistd.h> // usleep

#include <stdio.h>
#include <stdlib.h>
#include "../../GameMaps/GameMaps.h"
#include "../../Uteis/console/console.h"
#include "../../Modules/Player/player.h"
#include "../../View/Arena/ArenaView.h"
#include "../../Modules/Arena/Arena.h"
#include "../ElementController/ElementController.h"
#include "../GameController/GameController.h"
#include "../../View/Bar/BarView.h"







struct _ArenaCrontroller{
    Player* player;
    Map* map;
    ElementList* arena;
    int level;
};

typedef struct _ArenaCrontroller ArenaCrontroller;


ArenaCrontroller this;



void  ArenaController_Pause(){
//    Arena_StopThread();
}
void  ArenaController_Resume(){
    system("cls");
 //  Arena_InializeThread();
    ArenaView_clean();
}
void ArenaController_restart(){
    ArenaView_renderLevel(this.level);




    this.arena = Arena_create(this.map,this.player);

    ArenaController_Resume();
}




ElementList* ArenaController_create(Map* mapX, Player* player){
    this.arena = Arena_create(mapX,player);
    ArenaView_render(this.arena);

   return this.arena;
}


void  ArenaController_refresh(Player* player,time_t initial){
   // Arena_PauseThread();
    ArenaView_Refresh(this.arena);
  //  Arena_ResumeThread();
    BarView_render(player,initial);
    // relogio


}


void ArenaController_RunELementAction(Element* targetElement, Element* actorElement){
    ElementController_RunAction(targetElement,actorElement);
}




ElementList* ArenaController_removethisElement(Element* element,int positionX, int positionY){
    this.arena = ElementList_removethisElement(this.arena,element,positionX,positionY);
    return this.arena;
}



int ArenaController_Move(ElementList* elementList,int forPositionX, int forPositionY){
    int positionX = elementList->positionX;
    int positionY = elementList->positionY;
    Element* elementIn = Arena_returnElementIn(this.arena,forPositionX,forPositionY);
    if(elementIn != NULL){
        ArenaController_RunELementAction(elementIn,elementList->element);
        if(Element_isTransposable(elementIn)|| Element_IsRemoved(elementIn)){
            ArenaController_removethisElement(elementList->element,positionX,positionY);
            this.arena = Arena_insertElement(this.arena,elementList->element,forPositionX,forPositionY);
           // Arena_SetElementRemoved(this.arena,positionX,positionY);
            return 1;
        }
    }else{
        ArenaController_removethisElement(elementList->element,positionX,positionY);
        this.arena = Arena_insertElement(this.arena,elementList->element,forPositionX,forPositionY);
       // Arena_SetElementRemoved(this.arena,positionX,positionY);
        return 1;
    }
    return 0;
}

int ArenaController_MovePlayer(Player* player,int forPositionX, int forPositionY){
    int positionX = Player_getPositionX(player);
    int positionY = Player_getPositionY(player);
    Element* elementIn = Arena_returnElementIn(this.arena,forPositionX,forPositionY);
    if(elementIn != NULL){
        ArenaController_RunELementAction(elementIn,Player_getAvatar(player));
        if(Element_isTransposable(elementIn)|| Element_IsRemoved(elementIn)){
            ArenaController_removethisElement(Player_getAvatar(player),positionX,positionY);
            this.arena = Arena_insertElement(this.arena,Player_getAvatar(player),forPositionX,forPositionY);
         //   Arena_SetElementRemoved(this.arena,positionX,positionY);
            return 1;
        }
    }else{
        ArenaController_removethisElement(Player_getAvatar(player),positionX,positionY);
        this.arena = Arena_insertElement(this.arena,Player_getAvatar(player),forPositionX,forPositionY);
        // Arena_SetElementRemoved(this.arena,positionX,positionY);
        return 1;
    }

    return 0;
}

ElementList* ArenaController_getEnemies(){
    return Arena_getEnemies(this.arena);
}

void ArenaController_PlayerKill(){
    if(Player_kill(this.player)){
        GameController_GameOver();
    };
  this.arena = Arena_resetPlayerPosition(this.arena,this.player,this.map);
}
