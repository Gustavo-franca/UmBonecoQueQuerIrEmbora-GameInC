#ifndef ELEMENT_H_INCLUDED
#define ELEMENT_H_INCLUDED

#include "../Properties/properties.h"


typedef struct _Element Element;


Element* Element_create(int type,char symbol,int color,void * espec);

int Element_getColor(Element*  element);
int Element_setColor(Element*  element, int color);

int Element_getSymbol(Element*  element);
int Element_setSymbol(Element*  element, char symbol);

int Element_isTransposable(Element* element);

int Element_IsTheSame(Element* element1, Element* element2);



int Element_hasAction(Element* targetElement);

int Element_type(Element* targetElement);

int Element_setRemoved(Element* targetElement);

int Element_IsRemoved(Element* targetElement);

int Element_setKey(Element* playerElement);

int Element_getKey(Element* playerElement);

void * Element_getEspecProps(Element* element);

#endif // ELEMENT_H_INCLUDED
