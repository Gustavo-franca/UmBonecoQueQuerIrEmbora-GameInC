#ifndef AREANA_H_INCLUDED
#define AREANA_H_INCLUDED
#include "../../Modules/Arena/Arena.h"
#include <time.h>


ElementList* ArenaController_create(Map* mapX, Player* player);

void  ArenaController_refresh(Player* player,time_t initial);
void  ArenaController_Resume();
void  ArenaController_Pause();

int ArenaController_MovePlayer(Player* player,int forPositionX, int forPositionY);
int ArenaController_Move(ElementList* elementList,int forPositionX, int forPositionY);
ElementList* ArenaController_removethisElement(Element* element,int positionX, int positionY);
void ArenaController_restart();

void ArenaController_RunELementAction(Element* targetElement, Element* actorElement);

void ArenaController_PlayerKill();
ElementList* ArenaController_getEnemies();
#endif // AREANA_H_INCLUDED
