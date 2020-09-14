#ifndef MENUVIEW_H_INCLUDED
#define MENUVIEW_H_INCLUDED
#include "../../Modules/MenuOptions/MenuOptions.h"



void MenuView_show(MenuOptions* menuOption, int optionLength);
void MenuView_Ask(MenuOptions* menuOption, int optionLength);

void MenuView_refresh(MenuOptions* menuOption, int optionSelected);
void MenuView_AskRefresh(MenuOptions* menuOption, int optionSelected);

void MenuView_showWithLabel(MenuOptions* menuOption, int optionLength);

void MenuView_RenderInCenter(MenuOptions* menuOption);

#endif // MENUVIEW_H_INCLUDED
