#ifndef GAMECONTROLLER_H_INCLUDED
#define GAMECONTROLLER_H_INCLUDED
#include "../../Modules/Player/player.h"
#include <time.h>
#define GAME_EXIT -1
#define GAME_START 0
#define GAME_RESTART 1
#define GAME_CONTINUE 2
#define NEXT_LEVEL 3
#define GAME_OVER 4
#define PAUSE_GAME 5
#define GAME_MENU 6
#define GAME_FINISHED 10

int GameController_GameOver();
int GameController_Menu();
int GameController_start(int level);
int GameController_play(time_t initial);
void GameController_congratulations();
#endif // GAMECONTROLLER_H_INCLUDED
