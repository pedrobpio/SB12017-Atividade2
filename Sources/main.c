#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Headers/Interpret.h"

typedef struct{
    uint64_t field:48;
}uint48_t;

int main(int argc, char** argv){
    char entrada[256];
    if(argc < 2){
        printf("Insira a expressao a ser calculada: ");
        scanf("%[^\n]", entrada);
    }else
       strcpy(entrada,argv[1]);
    printf("%s = %lld", entrada, Interpret(entrada));
}
