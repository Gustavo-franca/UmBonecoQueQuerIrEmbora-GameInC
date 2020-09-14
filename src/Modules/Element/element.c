#include "element.h"
#include <stdlib.h>



struct _Element {
    char symbol;
    int color;
    Properties* properties;
};

void * Element_getEspecProps(Element* element){
    return Properties_getEspecProps(element->properties);
}

Element* Element_create(int type,char symbol,int color,void * espec){
    Element* element = (Element*) malloc(sizeof(Element));

    element->symbol = symbol;
    element->color = color;
    element->properties = Properties_SetInitialPropertiesForType(type,espec);
    return element;
}


int Element_getColor(Element*  element){
    return element->color;
}

int Element_setColor(Element*  element, int color){
    return element->color = color;
}

int Element_getSymbol(Element*  element){
    return  element->symbol;
}

int Element_setSymbol(Element*  element, char symbol){
      return element->symbol = symbol;
}

int Element_isTransposable(Element* element){
    return Properties_isTransposable(element->properties);
}



int Element_hasAction(Element* targetElement){
    return Properties_hasAction(targetElement->properties);
}

int Element_IsTheSame(Element* element1, Element* element2){
    if(element1->symbol == element2->symbol && element1->color == element2->color )return 1;
    return 0;

}

int Element_type(Element* targetElement){
    return Properties_type(targetElement->properties);
}

int Element_setRemoved(Element* targetElement){
    return Properties_setRemoved(targetElement->properties);
}

int Element_IsRemoved(Element* targetElement){
    return Properties_IsRemoved(targetElement->properties);
}
