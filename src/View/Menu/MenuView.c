
#include "MenuView.h"
#include "../../Uteis/console/console.h"
#include <stdio.h>
#include "../ScreanView.h"

#define BASEX 35
#define BASEY 8

int optionSelectPreviously;

void MenuView_AskRefresh(MenuOptions* menuOption, int istrue){
        if(istrue){
            setColor(COLOR_RED);

            gotoxy(SCREAN_WIDTH/2 ,(SCREAN_HEIGTH/2));
            printf("YES");

            setColor(COLOR_WHITE);
            gotoxy(SCREAN_WIDTH/2 + 10 ,(SCREAN_HEIGTH/2) );
            printf("NO");
               gotoxy(SCREAN_WIDTH/2 -1 ,(SCREAN_HEIGTH/2));

        }else{
            setColor(COLOR_WHITE);
            gotoxy(SCREAN_WIDTH/2 ,(SCREAN_HEIGTH/2));
            printf("YES");

            setColor(COLOR_RED);
            gotoxy(SCREAN_WIDTH/2 + 10 ,(SCREAN_HEIGTH/2) );
            printf("NO");
             gotoxy(SCREAN_WIDTH/2 + 9 ,(SCREAN_HEIGTH/2) );

        }

    setColor(COLOR_WHITE);

}
void MenuView_Ask(MenuOptions* menuOption, int Selected){
        system("cls");
        setColor(COLOR_WHITE);
        gotoxy(SCREAN_WIDTH/2 -10 ,(SCREAN_HEIGTH/2)-2 );
        printf("%s", MenuOptions_getLabel(menuOption,0));

        setColor(COLOR_WHITE);
        gotoxy(SCREAN_WIDTH/2 ,(SCREAN_HEIGTH/2));
        printf("YES");

        setColor(COLOR_RED);
        gotoxy(SCREAN_WIDTH/2 + 10 ,(SCREAN_HEIGTH/2) );
        printf("NO");

        gotoxy(SCREAN_WIDTH/2 + 9 ,(SCREAN_HEIGTH/2) );
        setColor(COLOR_WHITE);
}


void  MenuView_ShowOption(MenuOptions* menuOption,int option, int color){
        setColor(color);
        gotoxy(BASEX,BASEY + 2 * option);
        printf("%s", MenuOptions_getLabel(menuOption,option));
        setColor(COLOR_WHITE);
}

void MenuView_show(MenuOptions* menuOption, int optionLength){
    system("cls");
    setColor(COLOR_WHITE);
    gotoxy(2,(2*optionLength)/2+ BASEY -1);
    printf("Navegue com CIMA/BAIXO");
    gotoxy(2,(2*optionLength)/2+ BASEY);
    printf("Selecione com SPACE/ENTER ");


    COORDENATES* cursorPosition = (COORDENATES*) malloc(sizeof(COORDENATES));
    cursorPosition->x = BASEX -1;
    cursorPosition->y= BASEY;


    gotoxy(BASEX,BASEY - 2);
    setColor(COLOR_WHITE);
    for(int i = 1; i != optionLength;i++){
        MenuView_ShowOption(menuOption,i,COLOR_WHITE);
    }
    MenuView_ShowOption(menuOption,0,COLOR_RED);

    gotoxy( cursorPosition->x,cursorPosition->y);

}
void MenuView_refresh(MenuOptions* menuOption, int optionSelected){
     COORDENATES* cursorPosition = (COORDENATES*) malloc(sizeof(COORDENATES));
    cursorPosition->x = BASEX -1;
    cursorPosition->y= BASEY + 2 * optionSelected;

    MenuView_ShowOption(menuOption,optionSelectPreviously, COLOR_WHITE);
    MenuView_ShowOption(menuOption,optionSelected, COLOR_RED);
    optionSelectPreviously = optionSelected;


    gotoxy( cursorPosition->x,cursorPosition->y);
}
