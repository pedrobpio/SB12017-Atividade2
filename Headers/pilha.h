#include "nodo.h"

#ifndef PILHA_H
#define PILHA_H
typedef struct pilha Pilha;

Pilha* New_Pilha();
Nodo* Pilha_Pop(Pilha* pilha);
void Pilha_Push(Pilha* pilha, Nodo* nodo);
int Pilha_Get_Size(Pilha* piha);


#endif // PILHA_H
