#include "ElementList.h"
#include <stdio.h>
#include <stdlib.h>
#include "../../Properties/properties.h"



ElementList* ElementList_create(){
    return NULL;
}

ElementList* ElementList_insert(ElementList* elementList,Element* element,int positionX , int positionY){
    ElementList* newItem = (ElementList*) malloc(sizeof(ElementList));
    newItem->positionX = positionX;
    newItem->positionY = positionY;
    newItem->element = element;
    newItem->prox = elementList;
    return newItem;
}
ElementList* ElementList_copyListAndConcat(ElementList* fatherElementList,ElementList* somElementList){
   ElementList* elementIteractor;
    for(elementIteractor = somElementList; elementIteractor != NULL; elementIteractor = elementIteractor->prox) {
          fatherElementList = ElementList_insert(fatherElementList,elementIteractor->element,elementIteractor->positionX, elementIteractor->positionY);
    }
    return fatherElementList;
}

Element* ElementList_returnElementIn(ElementList* elementList,int positionX , int positionY){
    ElementList* elementFind;
    for(elementFind = elementList; elementFind != NULL; elementFind = elementFind->prox) {
            if(elementFind->positionX == positionX && elementFind->positionY == positionY){
                return elementFind->element;
            }
    }
    return NULL;

}

int ElementList_hasElementIn(ElementList* elementList,int positionX , int positionY){
    ElementList* elementFind;
    for(elementFind = elementList; elementFind != NULL; elementFind = elementFind->prox) {
            if(elementFind->positionX == positionX && elementFind->positionY == positionY){
                return 1;
            }
    }
    return 0;

}
int ElementList_hasThisElementIn(ElementList* elementList,Element* element,int positionX , int positionY){
    ElementList* elementFind;
    for(elementFind = elementList; elementFind != NULL; elementFind = elementFind->prox) {
            if(elementFind->positionX == positionX && elementFind->positionY == positionY && Element_IsTheSame(elementFind->element,element)){
                return 1;
            }
    }
    return 0;

}

ElementList* ElementList_remove(ElementList* elementList, int positionX, int positionY) {
    ElementList* previousElement = NULL;
    ElementList* currentElement = elementList;
    while(currentElement != NULL && (currentElement->positionX != positionX || currentElement->positionY != positionY)){
        previousElement = currentElement;
        currentElement = currentElement->prox;
    }
    if(currentElement == NULL)//não foi encontrado o elemento
        return elementList;

    if(previousElement == NULL)
        elementList = currentElement->prox;
    else
        previousElement->prox = currentElement->prox;

    free(currentElement); // libera memoria do elemento atual
    return elementList;
}

int ElementList_ElementIsTransposable(ElementList* elementList,int positionX,int positionY){
    ElementList* elementFind;
    for(elementFind = elementList; elementFind != NULL; elementFind = elementFind->prox) {
         if(elementFind->positionX == positionX && elementFind->positionY == positionY &&( Element_isTransposable(elementFind->element) || Element_IsRemoved(elementFind->element))){
                return 1;
            }else if( elementFind->positionX == positionX && elementFind->positionY == positionY ){
                return 0;
            }
    }
    return 1;

}

ElementList* ElementList_removethisElement(ElementList* elementList,Element* element, int positionX, int positionY){
    ElementList* previousElement = NULL;
    ElementList* currentElement = elementList;
    while(currentElement != NULL && (currentElement->positionX != positionX || currentElement->positionY != positionY || (!Element_IsTheSame(element,currentElement->element)))){
        previousElement = currentElement;
        currentElement = currentElement->prox;
    }
    if(currentElement == NULL)//não foi encontrado o elemento
        return elementList;

    if(previousElement == NULL)
        elementList = currentElement->prox;
    else
        previousElement->prox = currentElement->prox;

    free(currentElement); // libera memoria do elemento atual
    return elementList;
}

ElementList* ElementList_AllElementType(ElementList* arena,int type){
    ElementList * listType = ElementList_create();
    ElementList* elementFind;
    for(elementFind = arena; elementFind != NULL; elementFind = elementFind->prox) {
        if(Element_type(elementFind->element) == type){
          listType = ElementList_insert(listType,elementFind->element,elementFind->positionX,elementFind->positionY);
        }
    }
    return listType;
}


