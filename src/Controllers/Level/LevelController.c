#include "LevelController.h"
#include <time.h>
#include "../Arena/ArenaController.h"
#include "../../View/Arena/ArenaView.h"
#include "../GameController/GameController.h"
#include "../ElementController/ElementController.h"
#include "../../Uteis/thread/threadUtil.h"
#include "../../Uteis/console/console.h"
#include "../../Modules/Music/music.h"
struct _LevelController{
    Player* player;
    Map* map;
    ElementList* arena;
    int isFinished;
    int level;
};

typedef struct _LevelController LevelController;
 struct _DataArena {
        time_t* initial;
        Player * player;
};
typedef struct _DataArena DataArena;
LevelController this;

int LevelController_initialize(int level,Player* player){
    this.isFinished = 0;
    this.level = level;
    this.player = player;
    this.map =  GameMap_getMaplevel(level);
    if(this.map == NULL){
        return 0;
    }
    ArenaView_renderLevel(level);

    this.arena = ArenaController_create(this.map,this.player);
    return 1;
    //Arena_InializeThread();
   // Arena_PauseThread();

   // Arena_ResumeThread();
   // int tempo;
   // time_t inicial, atual;

 //   tempo = 0;
  //  time(&inicial);
}

int getKeyboard_key(){
    char* keyMove = (char*) malloc(sizeof(char));
    char* hasMove = (char*) malloc(sizeof(char));
    pickUpKey(keyMove,hasMove);
        if(*hasMove == 1) {
            *hasMove = 0;
            return (int) *keyMove;
        }
        return -1;
}
int LevelController_isFinished(){
    return this.isFinished;
}
LevelController_PlayerIsDeath(){
    return Player_isDeath(this.player);
}
void LevelController_Finished(){
     this.isFinished = 1;
}
void * ElementsActions(void* arg){
    Thread* data = (Thread*)arg;
    ElementList* arena = data->data;
    int* signal = data->signal;
    while(1) {

        ElementController_Change(arena);

        if(*signal == THREAD_KILL){

            break;
        }else if(*signal == THREAD_PAUSE){
            *signal = THREAD_PAUSED;
            while(*signal == THREAD_PAUSED){

            }
        }
        usleep(50000);
    }
    *signal = THREAD_KILLED;
    return (void*)0;
}
void * THArenaController_refresh(void* arg){
    Thread* data = (Thread*)arg;
    DataArena* arena =(DataArena*) data->data;
    time_t initial = *arena->initial;
    Player* player = arena->player;
    int* signal = data->signal;
    while(1) {

        ArenaController_refresh(player,initial);
        if(*signal == THREAD_KILL){
            break;
        }else if(*signal == THREAD_PAUSE){
            *signal = THREAD_PAUSED;
            while(*signal == THREAD_PAUSED){

            }
        }
         usleep(20000);
    }
    *signal = THREAD_KILLED;
    return (void*)0;
}
int LevelController_start(time_t initial){




    DataArena* data = (DataArena*)malloc(sizeof(DataArena));

    data->initial = &initial;
    data->player = this.player;

    Music_PlayMusicGame();
    Thread_create(this.arena,ElementsActions);
    Thread_create(data,THArenaController_refresh);

    while(1) {
        // ArenaController_refresh(this.player);
       //  ElementController_Change(this.arena);
    //LevelController_Finished();
        if(LevelController_isFinished()){
            Music_StopMusicGame();
            Thread_StopAll();
            return NEXT_LEVEL;
        }

        if(LevelController_PlayerIsDeath()){
              Music_StopMusicGame();
            Thread_StopAll();
            return GAME_OVER;
        }
        int key = getKeyboard_key();
        switch(key){
            case KEY_UP:;
            case KEY_DOWN: ;
            case KEY_LEFT: ;
            case KEY_RIGHT:;
                PlayerController_move(this.player,key);
            break;
            case KEY_ESC:;
                  Music_StopMusicGame();
                Thread_StopAll();
              return PAUSE_GAME;
            break;
        }


    Element* avatar = Player_getAvatar(this.player);


     usleep(50000);
    }
}
void LevelController_resume(){
    ArenaView_clean();

}
