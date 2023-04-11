/*
ENUNCIADO

        Dada uma sequência de valores do PIB correspondentes a um determinado intervalo de anos,
        o objetivo deste laboratório é determinar o triênio que teve o maior crescimento médio do PIB.

        A entrada consiste de um número inteiro positivo n, que indica o número de anos considerado,
        seguido por n números reais, representando o PIB de cada ano da amostragem.
        Cada número da entrada estará em uma linha distinta.

        A saída deverá conter apenas uma linha, contendo a seguinte frase:
        "a maior media de crescimento foi entre os anos X e Y: Z",
        onde X e Y representam o primeiro e o último ano do triênio (onde o primeiro ano é o ano 0)
        com a maior média de crescimento, e Z deve ser o crescimento médio percentual deste triênio com uma casa decimal.
        Em caso de empate, i.e, mais de um triênio com a mesma média de crescimento, você deverá escolher o triênio mais antigo.

*/


#include <stdio.h>
#include <stdlib.h>

int main(){

    //declaracoes das variaveis, separadas em grupos de semelhanca:
    //Valores de input, Valores transformados dos inputs, Valores resultados dos anteriores, e Ints.
    float ano_atual, ano_anterior, ano_temp;
    float porc_atual, porc_anterior=0, porc_retrasada, porc_temp;
    float valor_trienio, valor_maior;
    int num_valores, trienio_maior;

    //chamamento inicial da quantia de valores
    scanf("%d",&num_valores);

    //scanf para optencao dos primeiros 2 valores, que vao dar a base pra analise
    scanf("%f %f",&ano_anterior,&ano_atual);
    porc_atual= ((  ano_atual   -   ano_anterior    )/   ano_anterior    )*100;

    /*
        BLOCO DE PRINTS PARA TESTE DE MESA

    printf("\n%3.2f %3.2f\t\t", ano_atual,ano_anterior);
    printf("%3.2f %3.2f %3.2f\t\t", porc_atual,porc_anterior,porc_retrasada);
    printf("%3.2f %3.2f\n", valor_trienio, valor_maior);
    */


    //bloco do loop. E um loop simples, dividido em 4 partes:
    for (int i = 2; i< num_valores; i++){

        //1: atualizar as variaveis
        ano_anterior=ano_atual;
        scanf("%f",&ano_atual);


        //2: atualizar as variaveis que dependem dos valores das primeiras
        porc_retrasada  =porc_anterior;
        porc_anterior   =porc_atual;
        porc_atual      = ((  ano_atual   -   ano_anterior    )/   ano_anterior    )*100;


        //3: analisar o cenario com as variaveis atualizadas
        valor_trienio   =(porc_atual +porc_anterior  +porc_retrasada)/3;

        //4: checagem final para verificar se e necessario atualizar o valor do maior trienio registrado.
        if (i==2){
            valor_maior=valor_trienio;
            trienio_maior=i;
        }else if (valor_trienio>valor_maior){
            valor_maior=valor_trienio;
            trienio_maior=i;
        }

        /*
            BLOCO DE PRINTS PARA TESTE DE MESA

        printf("\n%3.2f %3.2f\t\t", ano_atual,ano_anterior);
        printf("%3.2f %3.2f %3.2f\t\t", porc_atual,porc_anterior,porc_retrasada);
        printf("%3.2f %3.2f\n", valor_trienio, valor_maior);
        */
    }

    //Print final exigido pelo exercicio.
    printf("a maior media de crescimento foi entre os anos %d e %d : %3.1f", trienio_maior-2, trienio_maior,  valor_maior );

    return 0;
}


