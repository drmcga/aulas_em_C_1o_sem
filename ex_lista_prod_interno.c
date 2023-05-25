/*
 *       ENUNCIADO
 *
 *      Faça um programa que calcule o produto interno de dois vetores u e v de mesmo tamanho
 *      n lidos do teclado. O programa deve ler primeiramente o valor de n e em seguida deve
 *      ler duas sequencias de mesmo tamanho de números reais e salvar cada sequencia em um
 *      vetor. Suponha que o número maximo de elementos de uma sequencia e 50. O programa
 *      deve entao calcular o produto interno dos vetores lidos.
*/
#include <stdio.h>
#include <stdlib.h>

/*
 *      produto interno e obtido atraves da somatoria das multiplicacoes entre elementos equivalentes
 *      exemplo: V1= [1 2 3 4 5] V2= [2 2 2 2 2] V1xV2= +2 +4 +6 +8 +10 = 30.
 *
*/

int main(){

    //declaracoes da variaveis uteis
    int vetor_u[50], vetor_v[50], tam, somatoria=0;

    //print de apresentacao
    printf("  Esse programa permite encontrar\n o produto interno de dois vetores.\n   Insira o tamanho dos vetores:\n\t-->>");

    //insercao do tamanho dos vetores.
    scanf("%d",&tam);

    for (int id=1;id<=2;id++){
        printf("\n ------>>LISTA %d<<------\n", id);
        for (int i=0;i<tam;i++){
            printf("    elemento '%2d' : ",i+1);
            if (id==1) scanf("%d",&vetor_u[i]);
            else scanf("%d",&vetor_v[i]);
        }
        printf("\n");
    }

    for (int i=0;i<tam;i++){
        somatoria+=vetor_u[i]*vetor_v[i];
    }

    printf("\n  O produto interno dos dois vetores e: << %3d >>\n\n", somatoria);


    return 0;
}
