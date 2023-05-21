/*
 *       ENUNCIADO
 *
 *      Escreva um programa que leia um vetor de até
 *      50 números reais e calcule a média destes valores
 *
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int quantidade;
    float vetor_a[50], somatoria=0;

    printf("\n\tDigite quantos valores, de 1 a 50,\n\tgostaria de analisar para obter\n\tum media aritimetica.\n\t\t");
    scanf("%d", &quantidade);

    for (int i=0;i<quantidade;i++){
        printf("  Digite agora o %2d numero da lista:   ",i+1);
        scanf("%f",&vetor_a[i]);
        somatoria+=vetor_a[i];
    }

    printf("\nSegue agora uma lista com seus numeros:\n[");
    for (int i=0;i<quantidade;i++){
        printf("%3.2f, ",vetor_a[i]);
        if(i%10==8&&i!=0) printf("\n... ");
    }

    printf("\b\b ]\n\n A media portanto e:\n\n\t\t[ %3.2f ]\n",somatoria/quantidade);


    return 0;
}
