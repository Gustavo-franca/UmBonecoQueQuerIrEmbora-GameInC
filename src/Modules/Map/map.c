#include <stdio.h>
#include <stdlib.h>
#include "Map.h"


#include "../Player/player.h"



struct _MapObject{
    int level;
    ElementList* mapElements;
    ElementList* enemiesElements;
    ElementList* objectElements;
    int initialPlayerPositionX;
    int initialPlayerPositionY;
};


Map* Map_create(int level) {
    Map* mapX = (Map*) malloc(sizeof(Map));
    mapX->level = level;
    mapX->mapElements =  ElementList_create();
    mapX->enemiesElements =  ElementList_create();
    mapX->objectElements =  ElementList_create();
    mapX->initialPlayerPositionX = 2;
    mapX->initialPlayerPositionY = 2;
    return mapX;
}

int Map_insert(Map* mapX, int positionX, int positionY, Element* element){
   if( Map_hasElementIn(mapX,positionX,positionY)){
        return 0;
    }
    mapX->mapElements =  ElementList_insert(mapX->mapElements,element,positionX,positionY);
    return 1;
}
int Map_insertEnimiesElements(Map* mapX, int positionX, int positionY, Element* element){
    if( Map_hasElementIn(mapX,positionX,positionY)){
        return 1;
    }
    mapX->enemiesElements =  ElementList_insert(mapX->enemiesElements,element,positionX,positionY);
    return 0;
}
int Map_insertObjectElements(Map* mapX, int positionX, int positionY, Element* element){
     if( Map_hasElementIn(mapX,positionX,positionY)){
        return 0;
    }
    mapX->objectElements =  ElementList_insert(mapX->objectElements,element,positionX,positionY);
    return 1;
}

int Map_hasElementIn(Map* mapX, int positionX, int positionY){
   if(ElementList_hasElementIn(mapX->mapElements,positionX,positionY)){
        return 1;
   }else if(ElementList_hasElementIn(mapX->enemiesElements,positionX,positionY)){
        return 1;
   }else if(ElementList_hasElementIn(mapX->objectElements,positionX,positionY)){
        return 1;
    }else if(positionX == mapX->initialPlayerPositionX && positionY == mapX->initialPlayerPositionY){
        return 1;
    }else{
    return 0;
    }
}

ElementList* Map_ElementList(Map* mapX) {
  return mapX->mapElements;
}

ElementList* Map_ObjectElementList(Map* mapX) {
  return mapX->objectElements;
}

ElementList* Map_EnemiesElementList(Map* mapX) {
  return mapX->enemiesElements;
}
int Map_removeMapElements(Map* mapX, int positionX, int positionY) {
  mapX->mapElements = ElementList_remove(mapX->mapElements,positionX,positionY);
  return 1;
}
int Map_removeEnimiesElements(Map* mapX, int positionX, int positionY) {
  mapX->enemiesElements = ElementList_remove(mapX->enemiesElements,positionX,positionY);
  return 1;
}
int Map_removeObjectsElements(Map* mapX, int positionX, int positionY) {
  mapX->objectElements = ElementList_remove(mapX->objectElements,positionX,positionY);
  return 1;
}

int Map_SetinitialPlayerPosition(Map* mapX,int positionX, int positionY){
    mapX->initialPlayerPositionX = positionX;
    mapX->initialPlayerPositionY = positionY;
    return 1;
}
int Map_initialPlayerPositionX(Map* mapX){
    return  mapX->initialPlayerPositionX;
}
int Map_initialPlayerPositionY(Map* mapX){
    return mapX->initialPlayerPositionY;
}

