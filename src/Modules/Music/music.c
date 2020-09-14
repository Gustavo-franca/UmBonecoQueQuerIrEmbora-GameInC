#include "music.h"
#include <windows.h>
#include <mmsystem.h>
#include <pthread.h>
#include <unistd.h>
#include "../../Uteis/thread/threadUtil.h"

pthread_t* idMenu;
pthread_t* idGame;


void* ThreadMenuMusic(void* arg){
  Thread* data = (Thread*)arg;
    int* signal = data->signal;

    PlaySound(TEXT("menu.wav"),NULL,SND_ASYNC);
    while(1) {

        if(*signal == THREAD_KILL){

            break;
        }else if(*signal == THREAD_PAUSE){
            PlaySound(NULL, 0, 0);
            *signal = THREAD_PAUSED;
            while(*signal == THREAD_PAUSED){

            }
            PlaySound(TEXT("menu.wav"),NULL,SND_ASYNC);
        }
         usleep(20000);
    }
    PlaySound(NULL, 0, SND_SYNC);
    *signal = THREAD_KILLED;
    return (void*)0;
}

void* ThreadGameMusic(void* arg){
  Thread* data = (Thread*)arg;
    int* signal = data->signal;

    PlaySound(TEXT("game.wav"),NULL,SND_ASYNC);
    while(1) {

        if(*signal == THREAD_KILL){

            break;
        }else if(*signal == THREAD_PAUSE){
            PlaySound(NULL, 0, 0);
            *signal = THREAD_PAUSED;
            while(*signal == THREAD_PAUSED){

            }
            PlaySound(TEXT("game.wav"),NULL,SND_ASYNC);
        }
         usleep(20000);
    }
    PlaySound(NULL, 0, SND_SYNC);
    *signal = THREAD_KILLED;
    return (void*)0;
}


int Music_PlayMusicMenu(){
  idMenu =  Thread_create(NULL,ThreadMenuMusic);
  return 1;
}
int Music_StopMusicMenu(){
    return Thread_Stop(idMenu);
}
int Music_PlayMusicGame(){
  idGame =  Thread_create(NULL,ThreadGameMusic);
  return 1;
}
int Music_StopMusicGame(){
    return Thread_Stop(idGame);
}

