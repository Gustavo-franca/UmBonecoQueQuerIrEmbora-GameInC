#include "GameController.h"
#include <unistd.h> // usleep

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "../../Uteis/console/console.h"
#include "../../Uteis/pickUpKey/pickUpKey.h"
#include "../Arena/ArenaController.h"
#include "../../Modules/MenuOptions/MenuOptions.h"
#include "../../View/Menu/MenuView.h"
#include "../../Modules/Player/player.h"
#include "../PlayerController/PlayerController.h"
#include "../MenuController/MenuController.h"
#include "../Level/LevelController.h"
#include "../../Modules/Music/music.h"
int exitGame = 0;


int GameController_Pause(){
    //system("cls");

    MenuOptions* menuOption = MenuOptions_Create();
    //declara o texto das opções de pause e as opções
    char option1[40];strcpy(option1,"Continue game");char * ptOption1 = option1;
    char option2[40];strcpy(option2,"Restart game");char * ptOption2 = option2;
    char option3[40];strcpy(option3,"Options");char * ptOption3 = option3;
    char option4[40];strcpy(option4,"Exit game");char * ptOption4 = option4;
     menuOption = MenuOptions_Insert(menuOption,0,ptOption1);
     menuOption = MenuOptions_Insert(menuOption,1,ptOption2);
     menuOption = MenuOptions_Insert(menuOption,2,ptOption3);
     menuOption = MenuOptions_Insert(menuOption,3,ptOption4);

    int optionsLenght = 4;

    //tratar a ação dos ids de pause    MenuView_showWithLabel(menuOption,optionsLenght);

    int optionSelected = MenuController_Run(menuOption,optionsLenght);



       switch(optionSelected){
        case 0:
            return GAME_CONTINUE;
        break;
        case 1:
          //  GameController_start();
            return GAME_RESTART;
        break;
        case 2://options
            return GAME_CONTINUE;
        break;
        case 3:
            if(GameController_exit()== 1){
                return GAME_EXIT;
            }
            return GAME_CONTINUE;
        break;

    }
return 0;

}

void GameController_congratulations(){

      MenuOptions* menuOption = MenuOptions_Create();
  char label[40];strcpy(label,"PARABENS VOCE FINALIZOU O JOGO!");char * ptLabel = label;
      menuOption = MenuOptions_Create();
      menuOption = MenuOptions_Insert(menuOption,0,ptLabel);
    MenuController_RenderInCenter(menuOption,5000);
}
int GameController_exit(){


    MenuOptions* menuOption = MenuOptions_Create();

    char option1[40];strcpy(option1,"Realmente Deseja sair?");char * ptOption1 = option1;


     menuOption = MenuOptions_Insert(menuOption,0,ptOption1);

    return MenuController_Ask(menuOption);

}
int GameController_GameOver(){
    //ArenaController_Pause();
    //system("cls");


      MenuOptions* menuOption = MenuOptions_Create();

    char option1[40];strcpy(option1,"Você Perdeu!Deseja Tentar Novamente?");char * ptOption1 = option1;

     menuOption = MenuOptions_Insert(menuOption,0,ptOption1);

    if(MenuController_Ask(menuOption)){
          return 0;
    };

    char label[40];strcpy(label,"GAME OVER!");char * ptLabel = label;
      menuOption = MenuOptions_Create();
      menuOption = MenuOptions_Insert(menuOption,0,ptLabel);

    MenuController_RenderInCenter(menuOption,3000);
   return 1;
}
int GameController_NextLevel(){



    char option1[60];
    strcpy(option1,"Parabéns você Passou para o Próximo nivel!deseja continuar?");
    char * ptOption1 = option1;

     MenuOptions* menuOption = NULL;
     menuOption = MenuOptions_Insert(menuOption,0,ptOption1);


    if(MenuController_Ask(menuOption)){
          return 1;
    };

    char label[40];strcpy(label,"GAME OVER!");char * ptLabel = label;
      menuOption = NULL;
      menuOption = MenuOptions_Insert(menuOption,0,ptLabel);

    MenuController_RenderInCenter(menuOption,3000);
   return 0;

}

int GameController_play(time_t initial){
    int option = 0;
    while(1){
       switch(LevelController_start(initial)){
        case PAUSE_GAME:
            option = GameController_Pause();
            if(option == GAME_CONTINUE){
                LevelController_resume();
                break;
            }
            return option;
        break;
        case NEXT_LEVEL:
            if(GameController_NextLevel()){
                    return NEXT_LEVEL;
            }
            return GAME_MENU;
        break;
        case GAME_OVER:
            if(GameController_GameOver()){
                return GAME_MENU;
            };
            return GAME_RESTART;
        break;
        }
	}

}

int GameController_start(int level){
   system("cls");

    Player* player = PlayerController_create('p',COLOR_BLUE);
    if(!(LevelController_initialize(level,player))){
        return GAME_FINISHED;
    };
    time_t initial;
    time(&initial);
    return GameController_play(initial);


}



int GameController_Menu(){

    system("cls");
    MenuOptions* menuOption = MenuOptions_Create();


    char option1[40];strcpy(option1,"Start game");char * ptOption1 = option1;
    char option2[40];strcpy(option2,"Continue saved game");char * ptOption2 = option2;
    char option3[40];strcpy(option3,"Options");char * ptOption3 = option3;
    char option4[40];strcpy(option4,"Avatar Store");char * ptOption4 = option4;
    char option5[40];strcpy(option5,"Exit game");char * ptOption5 = option5;

     menuOption = MenuOptions_Insert(menuOption,0,ptOption1);
     menuOption = MenuOptions_Insert(menuOption,1,ptOption2);
     menuOption = MenuOptions_Insert(menuOption,2,ptOption3);
     menuOption = MenuOptions_Insert(menuOption,3,ptOption4);
     menuOption = MenuOptions_Insert(menuOption,4,ptOption5);

    int optionsLenght = 5;


    while(1){
        int optionSelected = MenuController_Run(menuOption,optionsLenght);
        switch(optionSelected){
            case 0:

                return 0;
            break;
            case 1:
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
                if(GameController_exit()){

                    return GAME_EXIT ;
                }
            break;
        }
    }

}


