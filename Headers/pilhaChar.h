#include "nodoChar.h"

#ifndef PILHACHAR_H
#define PILHACHAR_H
typedef struct pilhachar PilhaChar;

PilhaChar* New_PilhaChar();
char PilhaChar_Pop(PilhaChar* pilha);
void PilhaChar_Push(PilhaChar* pilha, NodoChar* nodo);
int PilhaChar_Get_Size(PilhaChar* piha);


#endif // PILHA_H
