/*
 *       ENUNCIADO
 *
 *      Escreva um programa que leia um vetor de até
 *      50 números reais e calcule o desvio padrao destes valores
 *
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int quantidade;
    float originais[50], quadrados[50], somatoria=0, media, des_pd;

    printf("\n\tUm desvio padrao e obtido atraves de\n");
    printf("\t1. calcular a media dos fatores\n\t2. calcular o quadrado da distancia entre cada ponto e a meia.\n");
    printf("\t3. somar os valores obtidos anteriormente\n\t4. dividir pelo numero de pontos.\n\t4. calcular a raiz quadrada.\n\n");


    printf("\n\tDigite quantos valores, de 1 a 50,\n\tgostaria de analisar para obter\n\tum desvio padrao.\n\n\t\t");
    scanf("%d", &quantidade);


    for (int i=0;i<quantidade;i++){
        printf("  Digite agora o %2d numero da lista:   ",i+1);
        scanf("%f",&originais[i]);
        somatoria+=originais[i];
    }

    media=somatoria/quantidade;
    somatoria=0;

     for (int i=0;i<quantidade;i++){
        quadrados[i]=(originais[i]-media)*(originais[i]-media);
        somatoria+=quadrados[i];
    }

    des_pd=sqrt(somatoria/quantidade);

    printf("\n\n O desvio padrao portanto e:\n\n\t\t[ %3.2f ]\n",des_pd);


    return 0;
}
