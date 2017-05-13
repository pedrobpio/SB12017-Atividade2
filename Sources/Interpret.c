#include "../Headers/Interpret.h"
#include <stdio.h>

long long adicionar(long long a, long long b){
    return a+b;
}

long long subtrair(long long a, long long b){
    return a-b;
}

long long dividir(long long a, long long b){
    return a/b;
}

long long multiplicar(long long a, long long b){
    return a*b;
}

long long numero(Nodo* a){
    return Nodo_Get_Value(a);
}

long long (*list_of_operations[4]) (long long, long long) = {adicionar, subtrair, multiplicar, dividir};

static Pilha* pilha;

long long Interpret(char* expressao){
    pilha = New_Pilha();
    Pilha_Push(pilha, New_Nodo(3,VAL));
    Pilha_Push(pilha, New_Nodo(11,VAL));
    Pilha_Push(pilha, New_Nodo(5,VAL));
    Pilha_Push(pilha, New_Nodo(0,ADD));
    Pilha_Push(pilha, New_Nodo(0,SUB));
    /*Pilha_Push(pilha, New_Nodo(4,VAL));
    Pilha_Push(pilha, New_Nodo(6,VAL));
    Pilha_Push(pilha, New_Nodo(0,SUB));
    Pilha_Push(pilha, New_Nodo(0,DIV));*/

    long long value = Evaluate(Pilha_Pop(pilha));
    free(pilha);
    return value;
}
char* operation = {"+-*/"};
long long Evaluate(Nodo* a){
    //printf("%d\n", Pilha_Get_Size(pilha));
    if(Nodo_Get_Type(a)){

        Nodo* aux = Pilha_Pop(pilha);

        long long right = Evaluate(aux);
        free(aux);

        aux = Pilha_Pop(pilha);
        long long left = Evaluate(aux);
        free(aux);

        long long res = list_of_operations[Nodo_Get_Type(a) - 1](left , right);
        free(a);

        return res;
    }else{
        return Nodo_Get_Value(a);
    }
}
