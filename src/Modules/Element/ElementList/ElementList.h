#ifndef ELEMENTLIST_H_INCLUDED
#define ELEMENTLIST_H_INCLUDED

#include "../element.h"

typedef struct _ElementList ElementList;

struct _ElementList {
    int positionX,positionY;
    Element* element;
    ElementList* prox;
};

ElementList* ElementList_create();

ElementList* ElementList_insert(ElementList* elementList,Element* element,int positionX , int positionY);

ElementList* ElementList_copyListAndConcat(ElementList * fatherElementList,ElementList* somElementList);


Element* ElementList_returnElementIn(ElementList* elementList,int positionX , int positionY);

ElementList* ElementList_remove(ElementList* elementList, int positionX, int positionY);

ElementList* ElementList_removethisElement(ElementList* elementList,Element* element, int positionX, int positionY);

int ElementList_ElementIsTransposable(ElementList* elementList,int positionX,int positionY);

int ElementList_hasElementIn(ElementList* elementList,int positionX , int positionY);

int ElementList_hasThisElementIn(ElementList* elementList,Element* element,int positionX , int positionY);

Element* ElementList_returnElementIn(ElementList* elementList,int positionX , int positionY);

ElementList* ElementList_AllElementType(ElementList* arena,int type);

//properties set and get



/*
int ElementList_HasElementTransposableOrNotHasElement(Map* mapX, int positionX, int positionY) {
       Map* mapFind;
    for(mapFind = mapX; mapFind != NULL; mapFind = mapFind->prox) {
            if(mapFind->positionX == positionX && mapFind->positionY == positionY && Element_isTransposable(mapFind->element)){
                return true;
            }else if( mapFind->positionX == positionX && mapFind->positionY == positionY ){
                return false;
            }
    }
    return true;
}*/

#endif // ELEMENTLIST_H_INCLUDED
