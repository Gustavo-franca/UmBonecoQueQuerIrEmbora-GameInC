#ifndef MENUCONTROLLER_H_INCLUDED
#define MENUCONTROLLER_H_INCLUDED
#include "../../Modules/MenuOptions/MenuOptions.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define KEY_SPACE 32
#define KEY_ESC 27
#define KEY_s 115
#define KEY_S 83
#define KEY_n 110
#define KEY_N 78


int  MenuController_Run(MenuOptions* menuOption,int optionsLenght);
int  MenuController_Ask(MenuOptions* menuOption);

#endif // MENUCONTROLLER_H_INCLUDED
