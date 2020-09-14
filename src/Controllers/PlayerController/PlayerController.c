#include "PlayerController.h"
#include "../Arena/ArenaController.h"

Player* PlayerController_create(char symbol, int color){
    return Player_create(symbol,color);
}

void PlayerController_move(Player* player,int keyMove){
          // teclado
        int playerPositionX = Player_getPositionX(player);
        int playerPositionY = Player_getPositionY(player);
        switch(keyMove) {
        case KEY_UP:;
            int moveYPlayer_Up = playerPositionY - 1;
            if(ArenaController_MovePlayer(player,playerPositionX,moveYPlayer_Up)){
                Player_SetNewPosition(player,playerPositionX,moveYPlayer_Up);
            }

            break;
        case KEY_DOWN: ;
            int moveYPlayer_Down = playerPositionY + 1;
            if(ArenaController_MovePlayer(player,playerPositionX, moveYPlayer_Down)){
                Player_SetNewPosition(player,playerPositionX,moveYPlayer_Down);
            }

            break;
        case KEY_LEFT: ;
            int moveXPlayer_Left = playerPositionX - 1;
            if(ArenaController_MovePlayer(player,moveXPlayer_Left, playerPositionY )){
                Player_SetNewPosition(player,moveXPlayer_Left,playerPositionY);
            }

            break;
        case KEY_RIGHT:;
            int moveXPlayer_Rigth = playerPositionX + 1;
           if(ArenaController_MovePlayer(player,moveXPlayer_Rigth, playerPositionY )){
                Player_SetNewPosition(player,moveXPlayer_Rigth,playerPositionY);
            }

            break;
        }
    }

