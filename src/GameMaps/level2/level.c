#include "level.h"
#include "../../Uteis/console/console.h"
#include <stdlib.h>
#include "../../Modules/Enemie/Enemie.h"



Map* Level2_getMap(){
    Map* map1 = Map_create(1);


    Map_SetinitialPlayerPosition(map1,5,1);

    Element* wall = Element_create(WALL_TYPE,(char)219,COLOR_YELLOW,NULL);

    Element* door = Element_create(OBJECT_TYPE_DOOR,(char)178,COLOR_RED,NULL);


    Element* key = Element_create(OBJECT_TYPE_KEY,(char)170,COLOR_BROWN,NULL);

    Element* enemieH = Enemie_create('M',COLOR_RED,ENEMIE_DIRECTION_HORIZONTAL);
    Element* enemieV = Enemie_create('M',COLOR_RED,ENEMIE_DIRECTION_VERTICAL);
    Element* enemieR = Enemie_create('M',COLOR_RED,ENEMIE_DIRECTION_RANDOM);

    /*insert Enemies element*/
    for(int j = 1; j <= 23; j++){
         Map_insert(map1, 30, j,enemieR);
         Map_insert(map1, 15, j,enemieR);
         Map_insert(map1, 50, j,enemieR);
    }
    Map_insertEnimiesElements(map1,60,10,enemieH);
    Map_insertEnimiesElements(map1,74,20,enemieH);
    Map_insertEnimiesElements(map1,75,6,enemieV);
    Map_insertEnimiesElements(map1,16,19,enemieR);


   // Map_insertEnimiesElements(map1,60,13,Enemie);

    Map_insertObjectElements(map1,14,2,door);
   // Map_insertObjectElements(map1,75,2,key);
    Map_insertObjectElements(map1,73,3,key);//73,3


/*Create Map*/
    //4 walls around the screen
    for(int i = 0; i <= 79; i++){
     Map_insert(map1, i, 0,wall);
     Map_insert(map1, i, 24,wall);
    }
    for(int j = 0; j <= 24; j++){
         Map_insert(map1, 79, j,wall);
         Map_insert(map1, 0, j,wall);
    }


    for(int j = 1; j <= 3; j++){
             Map_insert(map1, 10, j,wall);
             Map_insert(map1, 11, j,wall);
        }
             Map_insert(map1, 9, 3,wall);
             Map_insert(map1, 8, 3,wall);
             Map_insert(map1, 7, 3,wall);

             Map_insert(map1, 4, 3,wall);
             Map_insert(map1, 3, 3,wall);
             Map_insert(map1, 2, 3,wall);
             Map_insert(map1, 1, 3,wall);
    return map1;
}
