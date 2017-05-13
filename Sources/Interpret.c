#include "../Headers/Interpret.h"
#include <stdio.h>

//-----------------OPERAÇÕES--------------------
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
//-----------------------------------------------


//Ponteiro para cada tipo de operacao
long long (*list_of_operations[4]) (long long, long long) = {adicionar, subtrair, multiplicar, dividir};

static Pilha* pilha;

//Interpreta a expressao passada, transformando-a em notacao Polonesa Reversa e faz a avaliacao da pilha
long long Interpret(char* expressao){
    pilha = New_Pilha();

    Pilha_Push(pilha, New_Nodo(5,VAL));
    Pilha_Push(pilha, New_Nodo(3,VAL));
    Pilha_Push(pilha, New_Nodo(5,ADD));
    Pilha_Push(pilha, New_Nodo(2,VAL));
    Pilha_Push(pilha, New_Nodo(0,MUL));
    Pilha_Push(pilha, New_Nodo(4,VAL));
    Pilha_Push(pilha, New_Nodo(6,VAL));
    Pilha_Push(pilha, New_Nodo(0,SUB));
    Pilha_Push(pilha, New_Nodo(0,DIV));

    long long value = Evaluate(Pilha_Pop(pilha));
    free(pilha);
    return value;
}

//Faz a avaliacao do nodo e retorna o valor da avaliacao
long long Evaluate(Nodo* a){
    //Se o nodo for do tipo operacao é avaliado o lado direito e esquerdo
    //e entao é retornado o resultado da operacao
    if(Nodo_Get_Type(a)){
        Nodo* aux = Pilha_Pop(pilha);
        //Avalia o lado direito
        long long right = Evaluate(aux);
        free(aux);
        //Avalia o lado esquerdo
        aux = Pilha_Pop(pilha);
        long long left = Evaluate(aux);
        free(aux);
        //Executa a operação
        long long res = list_of_operations[Nodo_Get_Type(a) - 1](left , right);
        free(a);
        return res;
    }else{
        //Se o tipo for Valor então retorna o valor.
        return Nodo_Get_Value(a);
    }
}
