#include <stdio.h>
#include "Controllers/GameController/GameController.h"
#include "Uteis/console/console.h"
#include "View/ScreanView.h"

int main()
{
    /** PARA RODAR A MUSICA DO JOGO DEVE SE ADICIONAR
    --lwinmm
    EM "other links options" nas configurações
    do Compilador
    settings/compiler/link settings/ other link options
    **/


    setWindow(SCREAN_WIDTH,SCREAN_HEIGTH);
    do{
	switch(GameController_Menu()){
        case GAME_START:;
                int exit = 0;
                int level = 1;
                do{
                    switch(GameController_start(level)){
                        case GAME_RESTART:
                        break;
                        case NEXT_LEVEL:
                            level++;
                        break;
                        case GAME_EXIT:
                            return 0;
                        break;
                        case GAME_MENU:
                            exit = 1;
                        break;
                        case GAME_FINISHED:
                            GameController_congratulations();
                            exit = 1;
                        break;



                    };
                }while(!exit);

        break;
        case 1:
        break;
        case 2:
        break;
        case 3:
        break;
        case GAME_EXIT:
            return 0;
        break;
	}
	}while(1);

	return (0);
}
