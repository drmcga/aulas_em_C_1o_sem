/*
 *       ENUNCIADO
 *
 *      Faça um programa que leia duas sequências de números inteiros distintos
 *      e salve cada sequência em um vetor. Suponha que o número máximo de ele-
 *      mentos de uma sequência é 50. Suponha que cada um destes vetores repre-
 *      sente um conjunto contendo os elementos nele armazenados.
 *
 *      O programa deve então salvar em um terceiro vetor o resultado da inter-
 *      seção dos dois primeiros vetores e imprimir o resultado.
 *
 *          Exemplo:
 *              v1: [1, 2, 3, 4, 5]
 *              v2: [2, 5, 7, 1, -9, 18]
 *              Resultado: [1, 2, 5]
 *
*/
#include <stdio.h>
#include <stdlib.h>

int main(){

    //declaracoes de variaveis relacionadas as listas
    int sqcia_a[50], sqcia_b[50],  qnt_a, qnt_b;

    printf("\tEsse programa lhe permite obter as interseccoes entre duas\n");
    printf("\tlistas de numeros inteiros. Para tal, digite os tamanhos\n");
    printf("\tdas duas listas iniciais, no formato: TAM 1 +ESPACO+ TAM 2\n\n\t\t---->");

    scanf("%d %d",&qnt_a,&qnt_b);

    printf("\n Perfeito, vamos entao comecar com a primeira lista,\n");
    for (int i=0;i<qnt_a;i++){
        printf("  Escolha o %do termo da primeira lista: ",i+1);
        scanf("%2d",&sqcia_a[i]);
    }

    printf("\n\n Agora, vamos entao comecar com a segunda lista,\n");
    for (int i=0;i<qnt_b;i++){
        printf("  Escolha o %do termo da primeira lista: ",i+1);
        scanf("%2d",&sqcia_b[i]);
    }

    int sqcia_c[50], qnt_c=0;
    for (int i=0;i<qnt_a;i++){
        for (int j=0;j<qnt_b;j++){
            if (sqcia_a[i]==sqcia_b[j]&&sqcia_c[qnt_c-1]!=sqcia_a[i]){
                sqcia_c[qnt_c]=sqcia_a[i];
                qnt_c++;
            }
        }
    }

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

    printf("\nA interseccao entre as duas:\n [");
    for (int i=0;i<qnt_c;i++){
        printf("%3d, ",sqcia_c[i]);
    }
    printf("\b\b ]");


    return 0;
}
