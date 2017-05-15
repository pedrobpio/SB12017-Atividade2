#include "../Headers/pilhachar.h"
#include <stdlib.h>

typedef struct pilhachar {
    NodoChar* ultimo;
    int size;
} PilhaChar;

PilhaChar* New_PilhaChar(){
    PilhaChar* aux = (PilhaChar*)malloc(sizeof(PilhaChar));
    aux->ultimo = NULL;
    aux->size = 0;
    return aux;
}

char PilhaChar_Pop(PilhaChar* pilha){
    if(pilha == NULL)
        return NULL;
    if(pilha->size > 0){
        NodoChar* aux = pilha->ultimo;
        pilha->ultimo = NodoChar_Get_Prox(aux);
        pilha->size--;
        return aux->valor;
    }
    return NULL;
}

void PilhaChar_Push(PilhaChar* pilha, NodoChar* nodo){
    NodoChar_Add_Prox(pilha->ultimo, nodo);
    pilha->ultimo = nodo;
    pilha->size++;
}

int PilhaChar_Get_Size(PilhaChar* pilha){
    if(pilha == NULL)
        return -1;
    return pilha->size;
}
