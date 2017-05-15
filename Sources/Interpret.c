#include "../Headers/Interpret.h"
#include <stdio.h>
#include <stdint.h>

typedef struct{
    uint64_t field:48;
}uint48_t;

//-----------------OPERA��ES--------------------
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


int classifica_Op(char letra, char letra_atual){
    int prioLetra, prioLetra_atual;

  else if(letra == '*' || letra == '/')
    prioLetra = 2;
  else if(letra == '+' || letra == '-')
    prioLetra = 1;
  else if(letra == '(')
    prioLetra = 3;
 
  
  else if(letra_atual == '*' || letra_atual == '/')
    prioLetra_atual = 2;
  else if(letra_atual == '+' || letra_atual == '-')
    prioLetra_atual = 1;
  else if(letra_atual == '(')
    prioLetra_atual = 0;

    return (prioLetra > prioLetra_atual)
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
// transforma de infixa para posfixa (notacao polonesa inversa)
    PilhaChar* pilha_notacao;
    pilha_notacao = New_PilhaChar();
    PilhaChar_Push(pilha_notacao, New_NodoChar('('));
    int k = 0, l = 0; // contadores basicos
    char letra, letra_atual;
    char nova_expressao[256];
    do{
        letra = expressao[k];
        
        if (letra >= '0' && letra <= '9'){
            nova_expressao[l] = letra;
            l++;
        }
        else if (letra == '('){
            PilhaChar_Push(pilha_notacao, New_NodoChar('('));
        }
        else if (letra == ')' || letra == '\0'){
            do{ //enquanto nao encontra o parenteses correspondente
                letra_atual = PilhaChar_Pop(pilha_notacao);
                if (letra_atual !='('){
                    nova_expressao[l] = letra;
                    l++;
                }
            }while(letra != '(');
        }
        else if (letra =='+' || letra =='*' || letra =='-' || letra =='/'){
            for(;;){
                letra_atual = PilhaChar_Pop(pilha_notacao);
                if (classifica_Op(letra, letra_atual)){
                    PilhaChar_Push(pilha_notacao, New_NodoChar(letra_atual));
                    PilhaChar_Push(pilha_notacao, New_NodoChar(letra);
                    break;
                } 
                else{
                    nova_expressao[l] = letra_atual;
                    l++;
                }
            }
        }
    k++;
    }while(letra !='\0');



//*****************************************

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
    //Se o nodo for do tipo operacao � avaliado o lado direito e esquerdo
    //e entao � retornado o resultado da operacao
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
        //Executa a opera��o
        long long res = list_of_operations[Nodo_Get_Type(a) - 1](left, right);
        free(a);
        //Checa se o numero a retornar deve ser negativo
        res |= ((res>>47)&1)?0xffff000000000000:0x0;
        return res;
    }else{
        //Se o tipo for Valor ent�o retorna o valor.
        return Nodo_Get_Value(a);
    }
}
