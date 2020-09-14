#ifndef THREADUTIL_H_INCLUDED
#define THREADUTIL_H_INCLUDED
#include <pthread.h>
#include <signal.h>

#define THREAD_PAUSE 2
#define THREAD_PAUSED 3
#define THREAD_KILL 1
#define THREAD_RUNNING 0
#define THREAD_KILLED -1


struct _thread {
    pthread_t * id;
    int * signal;
    void* data;
};
typedef struct _thread Thread;
pthread_t* Thread_create(void * data,void* (* func)(void*));
void Thread_PauseAll();
void Thread_ResumeAll();
 void Thread_StopAll();
 int Thread_Stop(pthread_t* id);


#endif // THREADUTIL_H_INCLUDED
