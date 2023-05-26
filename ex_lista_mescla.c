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

    //declaracao de variaveis auxiliares
    //o temp e pra realizar troca entre fatores fora de ordem
    //o cont e para verificar se esta havendo uma troca entre os fatores
    int temp, cont=0;

    //esse for e para enunciar o vetor c, clonando o vetor a, em seguida o vetor b.
    for (int i=0;i<qnt_a+qnt_b;i++){
        if (i<qnt_a) sqcia_c[i]=sqcia_a[i];
        else sqcia_c[i]=sqcia_b[i-qnt_a];
    }

    //o while e para ser eterno, salvo por um unico if
    //ele rege as trocas, portanto nao tem como saber quantas vezes devemos rodar as trocas
    //dentro dele vem o loop que percorre o vetor c, fazendo basicamente 1 troca por vez.
    //por exemplo, se encontra 9 1 2 3, ele vai entregar em 1 loop: 1 2 3 9.
    //porem se encontrar 9 8 1 2, ele vai entregar 8 1 2 9
    //isso ocorre porque o 9 vai avancando junto com o i, e sendo jogado para frente ate encontrar um numero maior, ou encerrar
    while(cont!=-1){
        cont=0;                                 //condicao para recomecar o loop, se ela se manter, encerramos o loop
        for (int i=1;i<qnt_a+qnt_b;i++){        //percorrer o vetor
            if (sqcia_c[i]<sqcia_c[i-1]) {      //se um numero for menor que seu antecessor >> nao ordenado, precisa mudar
                temp=sqcia_c[i];
                sqcia_c[i]=sqcia_c[i-1];
                sqcia_c[i-1]=temp;
                cont++;                         //se houve mudanca precisa registrar nessa variavel
            }
        }
        
        if (cont==0) cont=-1;                   //se nao houve mudanca, a variavel nao sera alterada, e vai satisfazer essa condicao.
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

    printf("\nA mesclagem ordenada entre as duas:\n [");
    for (int i=0;i<qnt_a+qnt_b;i++){
        printf("%3d, ",sqcia_c[i]);
    }
    printf("\b\b ]\n\n");


    return 0;
}
