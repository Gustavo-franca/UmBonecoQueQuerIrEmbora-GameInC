#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "../console/console.h"

struct lista {
    int x,y; // identificador do objeto
    char simbolo; // simbolo do elemento
    struct lista* prox; // ponteiro para o proximo elemento
};

Lista* lst_cria() {
    return NULL;
}

Lista* lst_insere(Lista* l, int x, int y, char simbolo) {
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->x = x;
    novo->y = y;
    novo->simbolo = simbolo;
    novo->prox = l;
    return novo;
}

void lst_imprime(Lista* l) {
    Lista* p;
    for(p = l; p != NULL; p = p->prox) {
        gotoxy(p->x, p->y);
        printf("%c", p->simbolo);
    }
}

int lst_temElemento(Lista* l, int x, int y) {
    // Antes de inserir um novo elemento, verifique se
    // ja existe algum elemento na posicao desejada.
    // Esta funcao deve ser implementada.
    // Nao e necessario implementa-la para executar este projeto.
    return 0;
}

Lista* lst_retira(Lista* l, int x, int y) {
    Lista* ant = NULL;
    Lista* atual = l;
    while(atual != NULL && (atual->x != x || atual->y != y)) {
        ant = atual;
        atual = atual->prox;
    }
    if(atual == NULL)
        return l;

    if(ant == NULL)
        l = atual->prox;
    else
        ant->prox = atual->prox;

    free(atual); // libera memoria do elemento atual
    return l;
}
