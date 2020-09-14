#include "MenuOptions.h"
#include <stdlib.h>

MenuOptions* MenuOptions_Create(){
    return NULL;
}

int MenuOptions_HasId(MenuOptions* menuOptions,int id){
    if(menuOptions == NULL){
        return 0;
    }

        MenuOptions* optionFind;
    for(optionFind = menuOptions; optionFind != NULL; optionFind = optionFind->prox) {
            if(optionFind->id == id){
                return 1;
            }
    }
    return 0;
}
MenuOptions* MenuOptions_Insert(MenuOptions* menuOptions,int id,char * label){
    if(MenuOptions_HasId(menuOptions,id)){
        return menuOptions;
    }
    MenuOptions* newMenuOption = (MenuOptions*) malloc(sizeof(MenuOptions));
    newMenuOption->id = id;
    strcpy(newMenuOption->label,label);
    newMenuOption->prox = menuOptions;
    return newMenuOption;
}

MenuOptions* MenuOptions_findByIdAndSelectOption(MenuOptions* optionsList, int id){
    MenuOptions* optionFind;
    for(optionFind = optionsList; optionFind != NULL; optionFind = optionFind->prox) {
            if(optionFind->id == id){
                return optionFind;
            }
    }
}

char* MenuOptions_getLabel(MenuOptions* options, int id){
    MenuOptions* option =  MenuOptions_findByIdAndSelectOption(options,id);
    return &option->label;
}
