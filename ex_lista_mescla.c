/*
 *       ENUNCIADO
 *
 *      Faça um programa que leia duas sequências de números inteiros ordenados e salve cada
 *      sequência em um vetor. Suponha que o número máximo de elementos de uma sequência é
 *      50. Escreva um programa para intercalar os valores dos dois vetores em um terceiro vetor,
 *      em ordem crescente.
 *          Exemplo:
 *              v1 = [1, 3, 5, 5, 7, 9, 10]
 *              v2 = [2, 2, 4, 6, 8, 8, 10]
 *              v3 = [1, 2, 2, 3, 4, 5, 5, 6, 7, 8, 8, 9, 10, 10]
 *
*/
#include <stdio.h>
#include <stdlib.h>

int main(){

    //declaracoes de variaveis relacionadas as listas
    int sqcia_a[50], sqcia_b[50], sqcia_c[100],  qnt_a, qnt_b;




    //bloco de explicacao
    printf("\tEsse programa lhe permite obter a mescla entre duas\n");
    printf("\tlistas de numeros inteiros. Para tal, digite os tamanhos\n");
    printf("\tdas duas listas iniciais, no formato: TAM 1 +ESPACO+ TAM 2\n\n\t\t---->");

    //bloco de inputs
    scanf("%d %d",&qnt_a,&qnt_b);



    //bloco de montagem da primeira matriz
    printf("\n Perfeito, vamos entao comecar com a primeira lista,\n");
    for (int i=0;i<qnt_a;i++){
        printf("  Escolha o %do termo da primeira lista: ",i+1);
        scanf("%2d",&sqcia_a[i]);               //1a lista

    }



    printf("\n\n Agora, vamos entao comecar com a segunda lista,\n");
    for (int i=0;i<qnt_b;i++){
        printf("  Escolha o %do termo da primeira lista: ",i+1);
        scanf("%2d",&sqcia_b[i]);              //2a lista

    }

    //variaveis auxiliares
    int m=0, n=0;

    //bloco da lista de mesclagem:
    for (int i=0;i<qnt_a+qnt_b;i++){
        if (i%2==0){
            sqcia_c[i]=sqcia_a[m];
            m++;
        }else {
            sqcia_c[i]=sqcia_b[n];
            n++;
        }

    }

    //prints finais
    printf("\nA lista a:\n [");
    for (int i=0;i<qnt_a;i++){
        printf("%3d, ",sqcia_a[i]);
    }
    printf("\b\b ]");

    printf("\nA lista b:\n [");
    for (int i=0;i<qnt_b;i++){
        printf("%3d, ",sqcia_b[i]);
    }
    printf("\b\b ]");

    printf("\nA mesclagem entre as duas:\n [");
    for (int i=0;i<qnt_a+qnt_b;i++){
        printf("%3d, ",sqcia_c[i]);
    }
    printf("\b\b ]\n\n");


    return 0;
}
