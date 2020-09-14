#include "threadUtil.h"
#include <stdlib.h>

typedef struct _ThreadList ThreadList;


struct _ThreadList {
    Thread * thread;
    ThreadList* prox;
};

ThreadList* Threads = NULL;

ThreadList* ThreadList_insert(ThreadList* threadList,pthread_t* thread_id,void * data){
     ThreadList* thread = (ThreadList*)malloc(sizeof(ThreadList));
     thread->thread =  (Thread*)malloc(sizeof(Thread));
     thread->thread->signal = (int*)malloc(sizeof(int));
    *thread->thread->signal = 0;
    thread->thread->id = thread_id;
    thread->thread->data = data;
    thread->prox = threadList;
    return thread;
}
ThreadList* ThreadList_removeThreadWithId(ThreadList* threads,pthread_t id){
     ThreadList* previousThread = NULL;
    ThreadList* currentThread = threads;
    while(currentThread != NULL && *currentThread->thread->id != id){
        previousThread = currentThread;
        currentThread = currentThread->prox;
    }
    if(currentThread == NULL)//não foi encontrado o elemento
        return threads;

    if(previousThread == NULL)
        threads = currentThread->prox;
    else
        previousThread->prox = currentThread->prox;

    free(currentThread); // libera memoria do elemento atual
    return threads;
}
ThreadList* ThreadList_returnThreadWithId(ThreadList* threads,pthread_t id){
    ThreadList* ThreadFind;
    for(ThreadFind = threads; ThreadFind != NULL; ThreadFind = ThreadFind->prox) {
            if(*ThreadFind->thread->id == id){
                return ThreadFind;
            }
    }
    return NULL;

}


pthread_t* Thread_create(void * data,void* (* func)(void*)){
 pthread_t* thread_id =(pthread_t*) malloc(sizeof(pthread_t));
 Threads = ThreadList_insert(Threads,thread_id,data);
 while(pthread_create(thread_id, NULL,func,(void *)Threads->thread));
 return thread_id ;
}
void Thread_PauseAll(){
    ThreadList* ThreadFind;
    for(ThreadFind = Threads; ThreadFind != NULL; ThreadFind = ThreadFind->prox) {
            *ThreadFind->thread->signal = THREAD_PAUSE;
            while(*ThreadFind->thread->signal != THREAD_PAUSED);
    }
}
void Thread_ResumeAll(){
    ThreadList* ThreadFind;
    for(ThreadFind = Threads; ThreadFind != NULL; ThreadFind = ThreadFind->prox) {
            *ThreadFind->thread->signal = THREAD_RUNNING;
    }
}
int Thread_Stop(pthread_t * id){
    ThreadList* thread =  ThreadList_returnThreadWithId(Threads,*id);
    if(thread == NULL){
        return 0;
    }
    *thread->thread->signal = THREAD_KILL;
     while( *thread->thread->signal != THREAD_KILLED );
      Threads = ThreadList_removeThreadWithId(Threads,*id);
    return 1;
 }
void Thread_StopAll(){
       ThreadList* ThreadFind;
    for(ThreadFind = Threads; ThreadFind != NULL; ThreadFind = ThreadFind->prox) {
            *ThreadFind->thread->signal = THREAD_KILL;

    }
    for(ThreadFind = Threads; ThreadFind != NULL; ThreadFind = ThreadFind->prox) {
            while( *ThreadFind->thread->signal != THREAD_KILLED );
    }
    while(Threads != NULL){
        ThreadFind = Threads;
        Threads = ThreadFind->prox;
        free(ThreadFind);
    }
    return;

}
