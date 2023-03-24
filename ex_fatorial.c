/*

ENUNCIADO

    Fazer um programa que lê um valor positivo n e calcula o valor de n!

*/


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int valor_n,valor_base=1;

    printf("Digite um valor inteiro positivo N, para obter o valor de N!\n\t");
    scanf("%d",&valor_n);

    for (int i=1;i<=valor_n;i++){
        valor_base*=i;
    }

    printf("O valor de N! e : %d",valor_base);
    return 0;
}