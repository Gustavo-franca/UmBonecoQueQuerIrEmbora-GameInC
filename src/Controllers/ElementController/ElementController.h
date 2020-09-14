#ifndef ELEMENTCONTROLLER_H_INCLUDED
#define ELEMENTCONTROLLER_H_INCLUDED
#include "../../Modules/Element/element.h"
#include "../../Modules/Properties/properties.h"
#include "../../Modules/Element/ElementList/ElementList.h"

void ElementController_RunAction(Element* targetElement,Element* actorElement);
void *ElementController_Change(ElementList* arena);
#endif // ELEMENTCONTROLLER_H_INCLUDED
