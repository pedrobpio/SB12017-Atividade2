#include "nodo.h"
#include "pilha.h"
#include "nodoChar.h"
#include "pilhaChar.h"
#include <stdio.h>
#include <stdlib.h>

long long Interpret(char*);
long long Evaluate(long long (*operation)(long long, long long), Nodo*, Nodo*);
