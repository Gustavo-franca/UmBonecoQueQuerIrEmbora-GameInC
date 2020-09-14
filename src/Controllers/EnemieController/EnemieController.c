#include "stdlib.h"
#include <unistd.h>
#include <windows.h>

#include "EnemieController.h"
#include "../../Modules/Enemie/Enemie.h"
#include "../../Modules/Arena/Arena.h"
#include "../Arena/ArenaController.h"


void   Enemie_moveHorizontal(ElementList* enemies){

           int positionX = 0;
            int positionY = 0;
             switch(Enemie_getDirection(enemies->element)){
                case LEFT:
                    positionX = enemies->positionX - 1;
                    positionY = enemies->positionY;
                break;
                case RIGHT:;
                    positionX = enemies->positionX + 1;
                    positionY = enemies->positionY;
                break;
             }

    if(!ArenaController_Move(enemies,positionX,positionY)){
        if(Enemie_getDirection(enemies->element) == LEFT){
            Enemie_setDirection(enemies->element,RIGHT);
        }else{
             Enemie_setDirection(enemies->element,LEFT);
        }
    }




}

void   Enemie_moveVertical(ElementList* enemies){
           int positionX = 0;
            int positionY = 0;
             switch(Enemie_getDirection(enemies->element)){
                case UP:;
                    positionX = enemies->positionX;
                    positionY = enemies->positionY - 1;
                break;
                case DOWN:;
                    positionX = enemies->positionX;
                    positionY = enemies->positionY + 1;
                break;
             }

    if(!ArenaController_Move(enemies,positionX,positionY)){
        if(Enemie_getDirection(enemies->element) == UP){
            Enemie_setDirection(enemies->element,DOWN);
        }else{
            Enemie_setDirection(enemies->element,UP);
        }
    }

}

void Enemie_moveRandom(ElementList* enemies){
    int positionX ;
    int positionY ;
    int lower;
    int upper;
    int direction;
 do{
            positionX = 0;
            positionY = 0;
            lower = 1;
            upper = 4;
            direction = (rand() % (upper - lower + 1)) + lower;
             switch(direction){
                case LEFT:
                    positionX = enemies->positionX - 1;
                    positionY = enemies->positionY;
                break;
                case RIGHT:;
                    positionX = enemies->positionX + 1;
                    positionY = enemies->positionY;
                break;
                case UP:;
                    positionX = enemies->positionX;
                    positionY = enemies->positionY - 1;
                break;
                case DOWN:;
                    positionX = enemies->positionX;
                    positionY = enemies->positionY + 1;
                break;
             }

    }while(!(ArenaController_Move(enemies,positionX,positionY)));

}



void EnemieController_Move(ElementList* arena){

    ElementList* enemiesList = ArenaController_getEnemies();

   /* Element* ElementList_returnElementIn(ElementList* elementList,int positionX , int positionY);*/
    ElementList* enemies;
    Sleep(200); // sincronização entre treads

    for(enemies = enemiesList; enemies != NULL; enemies = enemies->prox) {
            int typeMove = Enemie_getTypeMove(enemies->element);
            switch(typeMove){
            case 0:
                 Enemie_moveRandom(enemies);
            break;
            case 1 :
                Enemie_moveVertical(enemies);
            break;
            case 2 :
                Enemie_moveHorizontal(enemies);
            break;

            }

    }

}

