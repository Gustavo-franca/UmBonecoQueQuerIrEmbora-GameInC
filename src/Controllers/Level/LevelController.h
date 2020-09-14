#ifndef LEVELCONTROLLER_H_INCLUDED
#define LEVELCONTROLLER_H_INCLUDED
#include <time.h>

//types
#include "../../Modules/Player/player.h"

int LevelController_initialize(int level,Player* player);
int LevelController_start(time_t initial);
void LevelController_resume();
void LevelController_Finished();
#endif // LEVELCONTROLLER_H_INCLUDED
