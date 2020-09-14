#include "ArenaView.h"

#include <stdio.h>
#include <stdlib.h>
#include "../../Uteis/console/console.h"
#include "../../Modules/Element/element.h"

#include "../ScreanView.h"

ElementList* cache = NULL ;

void createCache(ElementList* copyList){
    cache = ElementList_create();
    cache = ElementList_copyListAndConcat(cache,copyList);
}

void refreshCache(ElementList* copyList){
    cache = ElementList_create(); /// criar muita memoria!!
    cache = ElementList_copyListAndConcat(cache,copyList);
}


int NotRenderizedElement(ElementList* list,Element* element,int positionX,int positionY){
     return (!ElementList_hasThisElementIn(list,element,positionX,positionY));
}
void compareCacheAndClean(ElementList* newList){
        ElementList* elementFind;
    for(elementFind = cache; elementFind != NULL; elementFind = elementFind->prox) {
        if(NotRenderizedElement(newList,elementFind->element,elementFind->positionX,elementFind->positionY)){
            ElementList * aux = elementFind;
            elementFind = elementFind->prox;

          remove_Element(aux->positionX,aux->positionY);
          cache = ElementList_removethisElement(cache,aux->element,aux->positionX,aux->positionY);
            if(elementFind == NULL){
                break;
            }
        }
    }
}
void render_Element(Element* element,int positionX,int positionY){
    setColor(Element_getColor(element));
    gotoxy(positionX,positionY);
    printf("%c",Element_getSymbol(element));
    cache = ElementList_insert(cache,element,positionX,positionY);
}

void remove_Element(int positionX , int positionY){
    gotoxy(positionX,positionY);
    putchar('\0');
    return ;
}

void ArenaView_render(ElementList* arena){
    system("cls");
    ElementList* elementFind;
    for(elementFind = arena; elementFind != NULL; elementFind = elementFind->prox) {
        render_Element(elementFind->element,elementFind->positionX,elementFind->positionY);
    }
    createCache(arena);
    return;
}
void ArenaView_clean(){
    if(cache != NULL){
        do{
          remove_Element(cache->positionX,cache->positionY);
         cache = ElementList_removethisElement(cache,cache->element,cache->positionX,cache->positionY);
        }while(cache != NULL);
    }

    return;
}

void ArenaView_Refresh(ElementList* arena){
    ElementList* elementFind;
    for(elementFind = arena; elementFind != NULL; elementFind = elementFind->prox) {
        if(Element_IsRemoved(elementFind->element) == 1){
                ElementList * aux = elementFind;
                elementFind = elementFind->prox;
                arena = ArenaController_removethisElement(arena,aux->element,aux->positionX,aux->positionY);
                cache = ElementList_removethisElement(cache,aux->element,aux->positionX,aux->positionY);
                if(elementFind == NULL){
                break;
                    }

        }else if(NotRenderizedElement(cache,elementFind->element,elementFind->positionX,elementFind->positionY)){
         render_Element(elementFind->element,elementFind->positionX,elementFind->positionY);
        }
    }
   compareCacheAndClean(arena);
   gotoxy(0,26);
    return;
}
void ArenaView_renderLevel(int level){
       setColor(COLOR_WHITE);
       gotoxy(SCREAN_WIDTH/2 -4,SCREAN_HEIGTH/2);
    printf("LEVEL %d",level);
    Sleep(1000);
    system("cls");
    gotoxy(SCREAN_WIDTH/2 ,SCREAN_HEIGTH/2);
    printf("3",level);
    Sleep(1000);
    gotoxy(SCREAN_WIDTH/2 ,SCREAN_HEIGTH/2);
    printf("2");
    Sleep(1000);
    gotoxy(SCREAN_WIDTH/2 ,SCREAN_HEIGTH/2);
    printf("1");
    Sleep(1000);


}


/*
void Arena_showPlayer(Player* player){
    int positionX = Player_getPositionX(player);
    int positionY = Player_getPositionY(player);
    Element* avatar = (Element*)Player_getAvatar(player);
}*/
