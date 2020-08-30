#include <stdio.h>
#include "Controllers/GameController/GameController.h"
#include "Uteis/console/console.h"
#include "View/ScreanView.h"
int main()
{
	setWindow(SCREAN_WIDTH,SCREAN_HEIGTH);


	GameController_Menu();

	return (0);
}
