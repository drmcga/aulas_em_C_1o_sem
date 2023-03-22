/*
    ENUNCIADO

    Faça um programa que lê um número n e que compute e imprima o valor da somatoria de todos os termos de 1 ate n.

    OBS: Não use formulas como a da soma de uma P.A.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int valor_n, base,i;
    base=0;
    printf("Escolha um valor N para realizar a somatoria de todos os termos de 1 ate N\n");
    scanf("%d",&valor_n);
    for (i=1;i<=valor_n;i++){

        base+=i;
        
    }
    printf("\n\nSomatoria: %d",base);

    return 0;
}