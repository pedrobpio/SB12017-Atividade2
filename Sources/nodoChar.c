#include "../Headers/nodoChar.h"
#include <stdint.h>
#include <stdlib.h>

typedef struct nodochar{
    char valor;
    NodoChar* prox;
}NodoChar;

NodoChar* New_NodoChar(char value){
    NodoChar* aux = (NodoChar*)malloc(sizeof(NodoChar));
    aux->valor = value;
    aux->prox = NULL;
    return aux;
}

char NodoChar_Get_Value(Nodo* nodo){
    return nodo->valor;
}


NodoChar* Nodo_Get_Prox(NodoChar* nodo){
    if(nodo == NULL)
        return NULL;
    return nodo->prox;
}

void Nodo_Add_Prox(NodoChar* nodo, NodoChar* prox){
    prox->prox = nodo;
}
