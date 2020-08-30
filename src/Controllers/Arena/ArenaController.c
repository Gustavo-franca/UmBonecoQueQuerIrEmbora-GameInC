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


struct _ArenaCrontroller{
    Player* player;
    Map* map;
    ElementList* arena;
    int level;
};
typedef struct _ArenaCrontroller ArenaCrontroller;

ArenaCrontroller this;

void  ArenaController_Resume(){
    system("cls");
    ArenaView_clean();
}
void ArenaController_restart(){
    ArenaView_renderLevel(this.level);


/*
    int tempo;
    time_t inicial, atual;

    tempo = 0;
    time(&inicial);*/
    this.arena = Arena_create(this.map,this.player);

    ArenaController_Resume();
}
ElementList* ArenaController_create(int level, Player* player){
    this.level = level;
    ArenaView_renderLevel(level);
    this.player = player;
    this.map =  GameMap_getMaplevel(level);

/*
    int tempo;
    time_t inicial, atual;

    tempo = 0;
    time(&inicial);*/

    this.arena = Arena_create(this.map,this.player);
    Sleep(2000);
    ArenaView_render(this.arena);

    return this.arena;
}

void  ArenaController_refresh(){

    ArenaView_Refresh(this.arena);

                // relogio

    gotoxy(0,26);
    printf("cooerdenadas : %d && %d && %d |\n   ", Player_getPositionX(this.player),Player_getPositionY(this.player), Player_getKey(this.player));

}

void ArenaController_RunELementAction(Element* targetElement, Element* actorElement){
    ElementController_RunAction(targetElement,actorElement);
}

int ArenaController_MovePlayer(Player* player,int forPositionX, int forPositionY){
    int positionX = Player_getPositionX(player);
    int positionY = Player_getPositionY(player);
    Element* elementIn = Arena_returnElementIn(this.arena,forPositionX,forPositionY);
    if(elementIn != NULL){
        ArenaController_RunELementAction(elementIn,Player_getAvatar(player));
        if(Element_isTransposable(elementIn)|| Element_IsRemoved(elementIn)){
            this.arena =  Arena_removeElement(this.arena,positionX,positionY);
            this.arena = Arena_insertElement(this.arena,Player_getAvatar(player),forPositionX,forPositionY);
            return 1;
        }
    }else{
        this.arena =  Arena_removeElement(this.arena,positionX,positionY);
        this.arena = Arena_insertElement(this.arena,Player_getAvatar(player),forPositionX,forPositionY);
        return 1;
    }

    return 0;
}

