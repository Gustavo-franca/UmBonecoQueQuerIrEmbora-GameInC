#ifndef ENEMIE_H_INCLUDED
#define ENEMIE_H_INCLUDED
#include "../Element/ElementList/ElementList.h"
#define ENEMIE_DIRECTION_RANDOM 0
#define ENEMIE_DIRECTION_HORIZONTAL 2
#define ENEMIE_DIRECTION_VERTICAL 1

#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4
/*void Enemie_move(Enemie* enemie);*/
Element* Enemie_create(char symbol,int color,int typeMove);
int Enemie_getTypeMove(Element* enemie);
void Enemie_setDirection(Element* enemie,int number);
int Enemie_getDirection(Element* enemie);

#endif // ENEMIE_H_INCLUDED
