#ifndef PLAYERCONTROLLER_H_INCLUDED
#define PLAYERCONTROLLER_H_INCLUDED
#include "../../Modules/Player/player.h"

Player* PlayerController_create(char symbol, int color);

void PlayerController_move(Player* player,int keyMove);


#endif // PLAYERCONTROLLER_H_INCLUDED
