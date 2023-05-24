/*
 *       ENUNCIADO
 *
 *      Faça um programa que leia duas sequências de números inteiros distintos e salve cada
 *      sequência em um vetor. Suponha que o número máximo de elementos de uma sequência
 *      é 50. Suponha que cada um destes vetores represente um conjunto contendo os elementos
 *      nele armazenados. O programa deve então salvar em um terceiro vetor o resultado da
 *      união dos dois primeiros vetores e imprimir o resultado.
 *          Exemplo:
 *              v1: [1, 2, 3, 4, 5]
 *              v2: [2, 5, 7, 1, -9, 18]
 *              Resultado: [1, 2, 3, 4, 5, 7, -9, 18]
 *
*/
#include <stdio.h>
#include <stdlib.h>

int main(){

    //declaracoes de variaveis relacionadas as listas
    int sqcia_a[50], sqcia_b[50],  qnt_a, qnt_b;
    
    //declaracoes das variaveis auxiliares, para montar a lista final
    int sqcia_c[50], extra_c=0, aux=0;

    //bloco de explicacao
    printf("\tEsse programa lhe permite obter a uniao entre duas\n");
    printf("\tlistas de numeros inteiros. Para tal, digite os tamanhos\n");
    printf("\tdas duas listas iniciais, no formato: TAM 1 +ESPACO+ TAM 2\n\n\t\t---->");

    //bloco de inputs
    scanf("%d %d",&qnt_a,&qnt_b);

    //bloco de montagem da primeira matriz
    //e consequentemente da primeira parte da terceira
    printf("\n Perfeito, vamos entao comecar com a primeira lista,\n");
    for (int i=0;i<qnt_a;i++){
        printf("  Escolha o %do termo da primeira lista: ",i+1);
        scanf("%2d",&sqcia_a[i]);               //1a lista
        sqcia_c[i]=sqcia_a[i];                  //3a lista
    }

    //o segundo bloco e mais complexo  que o primeiro
    //neste, a lista e montada, e fazemos uma conferencia,
    //entre cada numero inserido, e a terceira lista anteriormente estabelecida
    //caso tenhamos um numero novo, ignorando repeticoes 
    //dentro de cada bloco, ele e somado pra 3a lista.
    printf("\n\n Agora, vamos entao comecar com a segunda lista,\n");
    for (int i=0;i<qnt_b;i++){
        printf("  Escolha o %do termo da primeira lista: ",i+1);
        scanf("%2d",&sqcia_b[i]);              //2a lista
        aux=0;
        for (int j=0;j<qnt_a;j++){
            if(sqcia_b[i]==sqcia_a[j]) aux++;
        }
        if (aux==0) {
            sqcia_c[qnt_a+extra_c]=sqcia_b[i];  //+1 para 3a lista
            extra_c++;                              
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

    printf("\nA uniao entre as duas:\n [");
    for (int i=0;i<qnt_a+extra_c;i++){
        printf("%3d, ",sqcia_c[i]);
    }
    printf("\b\b ]\n\n");


    return 0;
}
