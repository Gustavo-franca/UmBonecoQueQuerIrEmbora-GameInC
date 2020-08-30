#ifndef AREANA_H_INCLUDED
#define AREANA_H_INCLUDED
#include "../../Modules/Arena/Arena.h"

ElementList* ArenaController_create(int level, Player* player);

void  ArenaController_refresh();
void  ArenaController_Resume();

int ArenaController_MovePlayer(Player* player,int forPositionX, int forPositionY);

void ArenaController_restart();

void ArenaController_RunELementAction(Element* targetElement, Element* actorElement);


#endif // AREANA_H_INCLUDED
