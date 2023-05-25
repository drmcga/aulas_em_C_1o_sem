/*
ENUNCIADO

        Escreva um programa em C que escreve na tela toda a tabela ASCII(0..255 chars),
    escrevendo em cada linha o código ASCII e o caractere correspondente.

*/


#include <stdio.h>
#include <stdlib.h>

int main(){
    
    for (int i=0; i<=255; i++){
       printf(" %3d: %c\n",i, i);
    }
    
    return 0;
}

