#include "level1.h"
#include "../../Uteis/console/console.h"
#include <stdlib.h>
#include "../../Modules/Enemie/Enemie.h"



Map* Level1_getMap(){
    Map* map1 = Map_create(1);


    Map_SetinitialPlayerPosition(map1,5,5);

    Element* wall = Element_create(WALL_TYPE,(char)219,COLOR_MAGENTA,NULL);

    Element* door = Element_create(OBJECT_TYPE_DOOR,(char)178,COLOR_BROWN,NULL);


    Element* key = Element_create(OBJECT_TYPE_KEY,(char)170,COLOR_BROWN,NULL);

    Element* enemieH = Enemie_create('M',COLOR_RED,ENEMIE_DIRECTION_HORIZONTAL);
    Element* enemieV = Enemie_create('M',COLOR_RED,ENEMIE_DIRECTION_VERTICAL);
    Element* enemieR = Enemie_create('M',COLOR_RED,ENEMIE_DIRECTION_RANDOM);

    /*insert Enemies element*/
    Map_insertEnimiesElements(map1,60,10,enemieH);
    Map_insertEnimiesElements(map1,74,20,enemieH);
    Map_insertEnimiesElements(map1,75,6,enemieV);
    Map_insertEnimiesElements(map1,16,19,enemieR);
    Map_insertEnimiesElements(map1,10,5,enemieR);
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
    //fist left  square
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

    //wall X1 X2
     Map_insert(map1, 2, 10,wall);
     Map_insert(map1, 1, 10,wall);


    //wall X4
    for(int j = 4; j <= 21; j++){
        for(int i = 3; i <=4; i++){
            if(j == 8 || j==9 || j==17 || j== 18){
                continue;
            }
             Map_insert(map1, i, j,wall);
        }
    }

    //X5 X6

     Map_insert(map1, 5, 19,wall);
     Map_insert(map1, 6, 19,wall);

     Map_insert(map1, 5, 21,wall);
     Map_insert(map1, 6, 21,wall);


     //wall X7
    for(int j = 4; j <= 21; j++){
        for(int i = 7; i <=8; i++){
            if(j == 10 || j==20){
                continue;
            }
             Map_insert(map1, i, j,wall);
        }
    }

      //wall X9 10 12
        for(int i = 9; i <=12; i++){
             Map_insert(map1, i,9 ,wall);
             Map_insert(map1, i,11,wall);
             Map_insert(map1, i,21,wall);
        }

        //wall X3 a 17
        for(int i = 13; i <=18; i++){
             Map_insert(map1, i,6,wall);
             Map_insert(map1, i,9 ,wall);
             Map_insert(map1, i,11,wall);
             Map_insert(map1, i,14,wall);
             Map_insert(map1, i,17,wall);
             Map_insert(map1, i,21,wall);
        }
        //Y7 X17
        for(int j = 1; j <= 8; j++){
        for(int i = 17; i <=18; i++){
            if(j == 4 || j==5){
                continue;
            }
             Map_insert(map1, i, j,wall);
        }
    }

      //wall X3 a 17
        for(int i = 19; i <=23; i++){
              Map_insert(map1, i,3,wall);
              Map_insert(map1, i,11,wall);
             Map_insert(map1, i,14,wall);
             Map_insert(map1, i,17,wall);
        }

        //Y9 X22 23
        for(int j = 4; j <= 9; j++){
            for(int i = 22; i <=23; i++){
                 Map_insert(map1, i, j,wall);
            }
        }


       //wall X24 a 35
        for(int i = 24; i <=35; i++){
              Map_insert(map1, i,9,wall);
             Map_insert(map1, i,11,wall);
             Map_insert(map1, i,14,wall);
             Map_insert(map1, i,17,wall);
              Map_insert(map1, i,19,wall);
               Map_insert(map1, i,21,wall);
            if(i == 24 || i == 25){
                continue;
            }
             Map_insert(map1, i,2,wall);

        }

        //X24 e 25
         Map_insert(map1, 24,20,wall);
         Map_insert(map1, 25,20,wall);


        //X26 Y3
         Map_insert(map1, 26,3,wall);
         Map_insert(map1, 26,4,wall);
         Map_insert(map1, 27,3,wall);
         Map_insert(map1, 27,4,wall);

         Map_insert(map1, 28,4,wall);
         Map_insert(map1, 29,4,wall);
         Map_insert(map1, 30,4,wall);
         Map_insert(map1, 31,4,wall);

         //Y9 X22 23
        for(int j = 5; j <= 7; j++){
            for(int i = 30; i <=31; i++){
                 Map_insert(map1, i, j,wall);
            }
        }

        //wall X32 7
        for(int i = 32; i <=35; i++){
              Map_insert(map1, i,7,wall);
        }

        //wall X36 7
        for(int i = 36; i <=38; i++){
             Map_insert(map1, i,2,wall);
             Map_insert(map1, i,7,wall);
             Map_insert(map1, i,9,wall);
             Map_insert(map1, i,11,wall);
             Map_insert(map1, i,14,wall);
             Map_insert(map1, i,17,wall);
             Map_insert(map1, i,19,wall);
             Map_insert(map1, i,21,wall);
        }

    //wall X37 38 Y12
         Map_insert(map1, 38,12,wall);
         Map_insert(map1, 37,12,wall);
         Map_insert(map1, 38,13,wall);
         Map_insert(map1, 37,13,wall);


         Map_insert(map1, 38,3,wall);
         Map_insert(map1, 37,3,wall);

         Map_insert(map1, 38,5,wall);
         Map_insert(map1, 37,5,wall);
         Map_insert(map1, 38,6,wall);
         Map_insert(map1, 37,6,wall);

         //wall X36 7
        for(int i = 39; i <=41; i++){
             Map_insert(map1, i,3,wall);
             Map_insert(map1, i,5,wall);
             Map_insert(map1, i,17,wall);
             Map_insert(map1, i,19,wall);
        }


         // X43 x42
        for(int j = 2; j <= 3; j++){
            for(int i = 42; i <=43; i++){
                 Map_insert(map1, i, j,wall);
            }
        }
         for(int j = 5; j <= 9; j++){
            for(int i = 42; i <=43; i++){
                 Map_insert(map1, i, j,wall);
            }
        }
         for(int j = 11; j <= 17; j++){
            for(int i = 42; i <=43; i++){
                 Map_insert(map1, i, j,wall);
            }
        }
        for(int j = 21; j <= 23; j++){
            for(int i = 42; i <=43; i++){
                 Map_insert(map1, i, j,wall);
            }
        }
         Map_insert(map1, 42, 19,wall);
         Map_insert(map1, 43, 19,wall);

        //wall X36 7
        for(int i = 44; i <=50; i++){
             Map_insert(map1, i,2,wall);
             Map_insert(map1, i,9,wall);
             Map_insert(map1, i,19,wall);
             Map_insert(map1, i,21,wall);
        }
        for(int i = 46; i <=50; i++){
             Map_insert(map1, i,11,wall);
        }
        //X46 Y12

        for(int j = 12; j <= 16; j++){
            for(int i = 46; i <=47; i++){
                 Map_insert(map1, i, j,wall);
            }
        }

         //X51 Y

        for(int j = 2; j <= 5; j++){
            for(int i = 51; i <=52; i++){
                 Map_insert(map1, i, j,wall);
            }
        }
         for(int j = 7; j <= 9; j++){
            for(int i = 51; i <=52; i++){
                 Map_insert(map1, i, j,wall);
            }
        }
        for(int j = 11; j <=11; j++){
            for(int i = 51; i <=52; i++){
                 Map_insert(map1, i, j,wall);
            }
        }
        for(int j = 13; j <=19; j++){
            for(int i = 51; i <=52; i++){
                 Map_insert(map1, i, j,wall);
            }
        }
         Map_insert(map1, 51, 21,wall);
          Map_insert(map1, 52, 21,wall);

         ///X

        for(int i = 53; i <=55; i++){
             Map_insert(map1, i,11,wall);
             Map_insert(map1, i,19,wall);
             Map_insert(map1, i,21,wall);
        }

         /// Y

        for(int j = 1; j <= 3; j++){
            for(int i = 56; i <=57; i++){
                 Map_insert(map1, i, j,wall);
            }
        }
        for(int j = 5; j <=9; j++){
            for(int i = 56; i <=57; i++){
                 Map_insert(map1, i, j,wall);
            }
        }
        for(int j = 11; j <=17; j++){
            for(int i = 56; i <=57; i++){
                 Map_insert(map1, i, j,wall);
            }
        }
         for(int j = 19; j <=19; j++){
            for(int i = 56; i <=57; i++){
                 Map_insert(map1, i, j,wall);
            }
        }
        for(int j = 21; j <=21; j++){
            for(int i = 56; i <=57; i++){
                 Map_insert(map1, i, j,wall);
            }
        }

           ///X

        for(int i = 58; i <=60; i++){
             Map_insert(map1, i,5,wall);
             Map_insert(map1, i,19,wall);
             Map_insert(map1, i,21,wall);
        }

          /// Y

        for(int j = 5; j <= 7; j++){
            for(int i = 61; i <=62; i++){
                 Map_insert(map1, i, j,wall);
            }
        }
        for(int j = 10; j <= 19; j++){
            for(int i = 61; i <=62; i++){
                 Map_insert(map1, i, j,wall);
            }
        }

          ///X

        for(int i = 63; i <=66; i++){
             Map_insert(map1, i,7,wall);
             Map_insert(map1, i,10,wall);
             Map_insert(map1, i,19,wall);
             Map_insert(map1, i,21,wall);
        }

         /// Y
        for(int j = 22; j <= 23; j++){
            for(int i = 63; i <=64; i++){
                 Map_insert(map1, i, j,wall);
            }
        }
        for(int j =5; j <= 7; j++){
            for(int i = 67; i <=68; i++){
                 Map_insert(map1, i, j,wall);
            }
        }
         for(int j =9; j <= 10; j++){
            for(int i = 67; i <=68; i++){
                 Map_insert(map1, i, j,wall);
            }
        }

           ///X

        for(int i = 67; i <=68; i++){
             Map_insert(map1, i,19,wall);
             Map_insert(map1, i,21,wall);
        }
          for(int i = 69; i <=72; i++){
             Map_insert(map1, i,5,wall);
             Map_insert(map1, i,9,wall);
             Map_insert(map1, i,19,wall);
             Map_insert(map1, i,21,wall);
        }

        /// Y
        for(int j = 5; j <= 15; j++){
            for(int i = 73; i <=74; i++){
                 Map_insert(map1, i, j,wall);
            }
        }
        for(int j = 17; j <= 19; j++){
            for(int i = 73; i <=74; i++){
                 Map_insert(map1, i, j,wall);
            }
        }
         for(int j = 21; j <= 21; j++){
            for(int i = 73; i <=74; i++){
                 Map_insert(map1, i, j,wall);
            }
        }

        ///X

        for(int i = 75; i <=77; i++){
             Map_insert(map1, i,5,wall);
             Map_insert(map1, i,21,wall);
        }
        for(int i = 76; i <=78; i++){
             Map_insert(map1, i,8,wall);

        }

        /// Y
        for(int j =1 ; j <= 4; j++){
            for(int i = 70; i <=71; i++){
                 Map_insert(map1, i, j,wall);
            }
        }
        for(int j =9 ; j <= 18; j++){
            for(int i = 76; i <=77; i++){
                 Map_insert(map1, i, j,wall);
            }
        }
        for(int j = 22; j <= 22; j++){
            for(int i = 76; i <=77; i++){
                 Map_insert(map1, i, j,wall);
            }
        }

return map1;
}

