#include "../Headers/pilha.h"
#include <stdlib.h>

typedef struct pilha {
    Nodo* ultimo;
    int size;
} Pilha;

Pilha* New_Pilha(){
    Pilha* aux = (Pilha*)malloc(sizeof(Pilha));
    aux->ultimo = NULL;
    aux->size = 0;
    return aux;
}

Nodo* Pilha_Pop(Pilha* pilha){
    if(pilha == NULL)
        return NULL;
    if(pilha->size > 0){
        Nodo* aux = pilha->ultimo;
        pilha->ultimo = Nodo_Get_Prox(aux);
        pilha->size--;
        return aux;
    }
    return NULL;
}

void Pilha_Push(Pilha* pilha, Nodo* nodo){
    Nodo_Add_Prox(pilha->ultimo, nodo);
    pilha->ultimo = nodo;
    pilha->size++;
}

int Pilha_Get_Size(Pilha* pilha){
    if(pilha == NULL)
        return -1;
    return pilha->size;
}
