#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include "../Element/element.h"
#include "../Element/ElementList/ElementList.h"
///dependica passada pelo nivel superior



/* TAD Lista Jogo */


typedef struct _MapObject Map;
// Cria uma nova lista

Map* Map_create(int level);


// Insere um novo elemento na lista com as coordenadas informadas
int Map_insert(Map* mapX, int positionX, int positionY, Element* element);

int Map_insertEnimiesElements(Map* mapX, int positionX, int positionY, Element* element);

int Map_insertObjectElements(Map* mapX, int positionX, int positionY, Element* element);


ElementList* Map_ElementList(Map* mapX);

ElementList* Map_ObjectElementList(Map* mapX);


ElementList* Map_EnemiesElementList(Map* mapX);


// Imprime objetos da lista
void Map_show(Map* mapX);

// Verifica se nas coordenadas informadas (x e y) existe um elemento
int Map_hasElementIn(Map* mapX, int positionX, int positionY);

// Retira um elemento que esteja nas coordenadas x e y
int Map_removeMapElements(Map* mapX, int positionX, int positionY);

int Map_removeEnimiesElements(Map* mapX, int positionX, int positionY);

int Map_removeObjectsElements(Map* mapX, int positionX, int positionY);

int Map_SetinitialPlayerPosition(Map* mapX,int positionX, int positionY);

int Map_initialPlayerPositionX(Map* mapX);

int Map_initialPlayerPositionY(Map* mapX);

#endif // MAP_H_INCLUDED
