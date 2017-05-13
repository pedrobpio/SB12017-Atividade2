#include "../Headers/Interpret.h"

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

long long Interpret(char* expressao){
    Pilha* pilha = New_Pilha();

    free(pilha);
}

long long Evaluate(long long (*operation)(long long, long long), Nodo* a, Nodo* b){

}

