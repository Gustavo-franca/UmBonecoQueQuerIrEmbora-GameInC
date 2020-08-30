#ifndef MENUOPTIONS_H_INCLUDED
#define MENUOPTIONS_H_INCLUDED




typedef struct _coordenates{
        int x;
        int y;
} COORDENATES;


typedef struct _MenuOptions MenuOptions;

struct _MenuOptions{
    int id;
    char label[40];
    MenuOptions* prox;
};

MenuOptions* MenuOptions_Create();


MenuOptions* MenuOptions_Insert(MenuOptions* menuOptions,int id,char * label);

char* MenuOptions_getLabel(MenuOptions* options, int id);

#endif // MENUOPTIONS_H_INCLUDED

