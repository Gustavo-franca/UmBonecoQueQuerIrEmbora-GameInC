#include "BarView.h"
#include <time.h>
#include <stdio.h>
#include "../../Uteis/console/console.h"



void BarView_render(Player* player,time_t initial){
    int gameTime;
    time_t  atual;
    time(&atual);

    gameTime =  atual - initial;

    gotoxy(0,26);
    printf("                                             ");
    gotoxy(0,26);
    setColor(COLOR_WHITE);
    printf("tempo da partida : %d || Chave %d |Vidas %d\n   ",
      gameTime,
    Player_getKey(Player_getAvatar(player)),
    Player_getLife(Player_getAvatar(player))
    );

}
