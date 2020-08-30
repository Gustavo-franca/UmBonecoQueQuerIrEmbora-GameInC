#include <stdlib.h>
#include <stdio.h>
#include "arena.h"
#include "../../Uteis/console/console.h"
#include "../Map/Map.h"
#include "../Element/element.h"


struct _Element {
    char symbol;
    int color;
    int isTransposable;
};

typedef struct _Element Element;




ElementList* Arena_create(Map* mapX,Player* player){
    ElementList* arena =  ElementList_create();
    arena = ElementList_copyListAndConcat(arena,(ElementList*) Map_ElementList(mapX));
    arena = ElementList_copyListAndConcat(arena,(ElementList*) Map_ObjectElementList(mapX));
    arena = ElementList_copyListAndConcat(arena,(ElementList*) Map_EnemiesElementList(mapX));
    player = Player_setInitialPosition((Player*)player,(int)Map_initialPlayerPositionX(mapX),(int)Map_initialPlayerPositionY(mapX));
    arena = Arena_insertElement(arena,Player_getAvatar(player),Player_getPositionX(player),Player_getPositionY(player));
    return arena;
}


int Arena_hasElementIn(ElementList* arena,int positionX , int positionY){
    return ElementList_hasElementIn(arena,positionX,positionY);
}
Element* Arena_returnElementIn(ElementList* arena,int forPositionX, int forPositionY){
    return ElementList_returnElementIn(arena,forPositionX,forPositionY);
}

ElementList* Arena_removeElement(ElementList* arena,int positionX , int positionY){
    return ElementList_remove(arena,positionX,positionY);
}

ElementList* Arena_insertElement(ElementList* arena,Element* element ,int positionX,int positionY){
            return ElementList_insert(arena,element,positionX,positionY);
}

int Arena_ElementIsTransposable(ElementList* arena,int positionX,int positionY){
  return ElementList_ElementIsTransposable(arena,positionX,positionY);
}
