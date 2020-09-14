#include "MenuController.h"
#include <stdlib.h>
#include <unistd.h> // usleep
#include "../../View/Menu/MenuView.h"
#include "../../Uteis/pickUpKey/pickUpKey.h"
#include "../../Uteis/console/console.h"
#include "../../Modules/Music/music.h"

 void MenuController_RenderInCenter(MenuOptions* menuOption,int sleep){
     MenuView_RenderInCenter( menuOption);
     Sleep(sleep);
 }
int  MenuController_Ask(MenuOptions* menuOption){
    int isTrue = 0;
    Music_PlayMusicMenu();
    MenuView_Ask(menuOption,isTrue);


    char* keyMove =(char*) malloc(sizeof(char));
    char* hasMove =(char*) malloc(sizeof(char));
     while(1){
        pickUpKey(keyMove,hasMove);
        if(*hasMove){
            *hasMove = 0;
            switch(*keyMove){
            case KEY_LEFT:
              isTrue = 1;
            break;
            case KEY_RIGHT:
                isTrue = 0;
            break;
            case KEY_SPACE:
            case KEY_ENTER:
                system("cls");
                 Music_StopMusicMenu();
                return isTrue;
            break;
            case KEY_ESC:
                system("cls");
                 Music_StopMusicMenu();
                return 0;
            break;
            }


            MenuView_AskRefresh(menuOption,isTrue);
        }
      usleep(1000); // aguarda um tempo

     }

}
 int MenuController_Run(MenuOptions* menuOption,int optionsLenght){
    int exitLoop = 0;
     Music_PlayMusicMenu();

    MenuView_show(menuOption,optionsLenght);




    int optionSelected = 0;
    char* keyMove =(char*) malloc(sizeof(char));
    char* hasMove =(char*) malloc(sizeof(char));
     while(1){
        *hasMove = 0;
        pickUpKey(keyMove,hasMove);
        if(*hasMove){
            switch(*keyMove){
            case KEY_UP:
            if(optionSelected > 0 ){
                    optionSelected--;
            }

                break;
            case KEY_DOWN:
            if(optionSelected < optionsLenght - 1){
                optionSelected++;
            }
                break;
            case KEY_SPACE:
            case KEY_ENTER:
                system("cls");
                 Music_StopMusicMenu();
                return optionSelected;
            break;
            case KEY_S:
            case KEY_s:

            break;
            case KEY_N:
            case KEY_n:

            break;
            case KEY_ESC:
            break;
            }

        MenuView_refresh(menuOption,optionSelected);
        }

        if(exitLoop == 1){
            break;
        }

      usleep(1000); // aguarda um tempo

     }
 }
