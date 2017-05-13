#include "../Headers/Interpret.h"
#include <stdio.h>
#include <stdint.h>

typedef struct{
    uint64_t field:48;
}uint48_t;

//-----------------OPERAÇÕES--------------------
long long adicionar(long long a, long long b){
    uint48_t ax, bx;
    ax.field =a;
    bx.field = b;
    return ax.field+bx.field;
}

long long subtrair(long long a, long long b){
    uint48_t ax, bx;
    ax.field =a;
    bx.field = b;
    return ax.field-bx.field;
}

long long dividir(long long a, long long b){
    uint48_t ax, bx;
    ax.field =a;
    bx.field = b;
    return a/b;
}

long long multiplicar(long long a, long long b){
    uint48_t ax, bx;
    ax.field =a;
    bx.field = b;
    return ax.field*bx.field;
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
/*******************************************
*TODO
*   COLOCAR A AVALIACAO DA EXPRESSAO PARA RPN
*   AQUI
*
********************************************/
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
int i = 0;
//Faz a avaliacao do nodo e retorna o valor da avaliacao
long long Evaluate(Nodo* a){
    //Se o nodo for do tipo operacao é avaliado o lado direito e esquerdo
    //e entao é retornado o resultado da operacao
    i++;
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
        long long res = list_of_operations[Nodo_Get_Type(a) - 1](left, right);
        free(a);
        //Checa se o numero a retornar deve ser negativo
        res |= ((res>>47)&1)?0xffff000000000000:0x0;
        return res;
    }else{
        //Se o tipo for Valor então retorna o valor.
        return Nodo_Get_Value(a);
    }
}
