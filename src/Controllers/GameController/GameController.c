#include "GameController.h"
#include <unistd.h> // usleep
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../../Uteis/console/console.h"
#include "../../Uteis/pickUpKey/pickUpKey.h"
#include "../Arena/ArenaController.h"
#include "../../Modules/MenuOptions/MenuOptions.h"
#include "../../View/Menu/MenuView.h"
#include "../../Modules/Player/player.h"
#include "../MenuController/MenuController.h"


int GameController_exit(){
    system("cls");

    MenuOptions* menuOption = MenuOptions_Create();

    char option1[40];strcpy(option1,"Realmente Deseja sair?");char * ptOption1 = option1;


     menuOption = MenuOptions_Insert(menuOption,0,ptOption1);

    return MenuController_Ask(menuOption);
}

int GameController_Pause(){
    system("cls");

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
            ArenaController_Resume();
            return 0;
        break;
        case 1:
            ArenaController_restart();
            return 0;
        break;
        case 2:
            return 0;
        break;
        case 3:
            if(GameController_exit()){
                return 1;
            }
            ArenaController_Resume();
            return 0;
        break;

    }


}


void GameController_NextLevel(){

    gotoxy(0,27);
    printf("Parabéns você Concluio este Nivel!!");
    exit(0);

}

void GameController_start(){
    system("cls");



    Player* player = PlayerController_create('p',COLOR_BLUE);
    ElementList* arena = ArenaController_create(1,player);

    //lissen input of keyboard
    char* keyMove = (char*) malloc(sizeof(char));
    char* hasMove = (char*) malloc(sizeof(char));

    int exitLoop = 0;
    while(1) {
        pickUpKey(keyMove,hasMove);
        if(*hasMove == 1) {
            *hasMove = 0;
            switch(*keyMove) {
                case KEY_UP:;
                case KEY_DOWN: ;
                case KEY_LEFT: ;
                case KEY_RIGHT:;
                    PlayerController_move(arena,player,*keyMove);
                break;
                case KEY_ESC:;
                   exitLoop = GameController_Pause();
                break;
            }
        }
        ArenaController_refresh();
        usleep(50000); // aguarda um tempo,
        if(exitLoop){
            break;
        }

    }





}



void GameController_Menu(){

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
                GameController_start();
            break;
            case 1:
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
                if(GameController_exit()){
                    exit(0);
                }
            break;
        }

    }

}


