#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "../Element/element.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define KEY_SPACE 32
#define KEY_ESC 27
#define KEY_s 115
#define KEY_S 83
#define KEY_n 110
#define KEY_N 78




typedef struct _ElementList ElementList;

typedef struct playerStruct Player;

void Player_move(Player* player,char* keyMove,char* hasMove);

Player* Player_create(char symbol, int color);

Player* Player_setInitialPosition(Player* player,int positionX,int positionY);


int Player_SetNewPosition(Player* player,int newPositionX,int newPositionY);
int Player_getPositionX(Player* player);

int Player_getPositionY(Player* player);

int Player_getPreviousPositionX(Player* player);

int Player_getPreviousPositionY(Player* player);

Element* Player_getAvatar(Player* player);

int Player_setKey(Player* playerElement);

int Player_getKey(Player* playerElement);

#endif // PLAYER_H_INCLUDED
