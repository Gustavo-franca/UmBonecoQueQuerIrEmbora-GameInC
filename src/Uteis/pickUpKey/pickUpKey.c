#include "pickUpKey.h"
#include <conio.h> // kbhit e getch
void pickUpKey(char * key, char * haskey) {
    if(kbhit()) { // se houve toque no teclado
        *key = getch(); // armazena tecla pressionada
        *haskey = 1;
    }
}
