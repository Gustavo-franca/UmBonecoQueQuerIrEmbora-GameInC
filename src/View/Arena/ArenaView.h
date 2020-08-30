#ifndef ARENAVIEW_H_INCLUDED
#define ARENAVIEW_H_INCLUDED

#include "../../Modules/Element/ElementList/ElementList.h"

void ArenaView_render(ElementList* arena);

void ArenaView_Refresh(ElementList* arena);

void remove_Element(int positionX , int positionY);

void ArenaView_renderLevel(int level);
void ArenaView_clean();

#endif // ARENAVIEW_H_INCLUDED
