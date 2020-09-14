#include "player.h"
#include <stdio.h>
#include <stdlib.h>

#include "../Arena/Arena.h"//dependencia passada pelo nivel superior

struct _PlayerProps {
    int hasKey;
    int life;
};
typedef struct _PlayerProps PlayerProps;

struct playerStruct {
    int positionX,positionY;
    Element* avatar;
    PlayerProps* props;
};



Player* Player_create(char symbol, int color){
    Player* player = (Player*) malloc(sizeof(Player));
    PlayerProps* props = (PlayerProps*) malloc(sizeof(PlayerProps));
    props->hasKey = 0;
    props->life = 3;

    Element* avatar = Element_create(PLAYER_TYPE,symbol,color,(void*)props);
    player->positionX = 0;
    player->positionY = 0;
    player->props = props;

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
int Player_setKey(Element* playerElement){
    PlayerProps* props = (PlayerProps*) Element_getEspecProps(playerElement);
    return props->hasKey = 1;
}
int Player_getKey(Element* playerElement){
    PlayerProps* props = (PlayerProps*) Element_getEspecProps(playerElement);
    return props->hasKey;
}
int Player_getLife(Element* playerElement){
    PlayerProps* props = (PlayerProps*) Element_getEspecProps(playerElement);
    return props->life;
}

int Player_SetNewPosition(Player* player,int newPositionX,int newPositionY){
     player->positionX = newPositionX;
     player->positionY = newPositionY;
     return 1;
}
int Player_kill(Player* player){
    if(player->props->life != 0){
        player->props->life--;
        return 0;
    }
    return 1;
}
int Player_isDeath(Player* player){
    if(player->props->life != 0){
        return 0;
    }
    return 1;
}

