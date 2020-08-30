#include "player.h"
#include <stdio.h>
#include <stdlib.h>

#include "../Arena/Arena.h"//dependencia passada pelo nivel superior

struct playerStruct {
    int positionX,positionY;

    Element* avatar;
};

Player* Player_create(char symbol, int color){
    Player* player = (Player*) malloc(sizeof(Player));
    Element* avatar = Element_create(PLAYER_TYPE,symbol,color);
    player->positionX = 0;
    player->positionY = 0;

    player->avatar = avatar;
    return player;
}

Player* Player_setInitialPosition(Player* player,int positionX,int positionY){
    player->positionX = positionX;
    player->positionY = positionY;

    return player;
}
int Player_getPositionX(Player* player){
    return player->positionX;
}
int Player_getPositionY(Player* player){
return player->positionY;
}

Element* Player_getAvatar(Player* player){
    return player->avatar;
}
int Player_setKey(Player* playerElement){
    return Element_setKey(Player_getAvatar(playerElement));
}
int Player_getKey(Player* playerElement){
    return Element_getKey(Player_getAvatar(playerElement));
}

int Player_SetNewPosition(Player* player,int newPositionX,int newPositionY){
     player->positionX = newPositionX;
     player->positionY = newPositionY;
     return 1;
}

