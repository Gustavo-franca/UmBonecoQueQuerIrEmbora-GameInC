#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

#include "../Element/ElementList/ElementList.h"
#include "../Map/Map.h"

#include "../Player/player.h"
 //depencias passadas pelo nivel superior




ElementList* Arena_create(Map* mapX,Player* player);

int Arena_hasElementIn(ElementList* arena,int positionX , int positionY);

Element* Arena_returnElementIn(ElementList* arena,int forPositionX, int forPositionY);


ElementList* Arena_removeElement(ElementList* arena,int positionX , int positionY);

ElementList* Arena_insertElement(ElementList* arena,Element* element ,int positionX,int positionY);

int Arena_ElementIsTransposable(ElementList* arena,int positionX,int positionY);


ElementList* Arena_clean(ElementList* arena);


#endif // DISPLAY_H_INCLUDED
