/*
ENUNCIADO

            Um jogador da Mega-Sena é supersticioso, e só faz jogos em que o primeiro número do
    jogo é par, o segundo é ímpar, o terceiro é par, o quarto é ímpar, o quinto é par e o sexto é
    ímpar. Faça um programa que imprima todas as possibilidades de jogos que este jogador
    supersticioso pode jogar.

*/


#include <stdio.h>
#include <stdlib.h>

int main()
{

    //declarar as variaveis
    int contador_possibilidades=0;
    char escolha;

    //chamar o input
    printf("Este programa imprime as possibilidades de jogos que um jogador superstiticioso pode jogar.\n");
    printf("\no Modelo de impressao e:\n1o\t2o\t3o\t4o\t5o\t6o\n\nSeguem os prints:\n\t\tDeseja ver todas as variacoes?\t(S)\tou\t(N)");

    //escolha para pular a prova-real
    scanf("%c",&escolha);

    
    /*
        e um exercicio de analise combinatoria simples.
        Anota-se os valores possiveis de cada casa, e os multiplica individualmente, criando lacos..
        Para a impressao de cada valor, entretanto, e preciso se certificar de que nao haja repeticoes.


        As possibilidades segundo analise combinatoria sao:

        30 * 30 * 29 * 29 * 28 * 28
        ---------------------------     =  16 483 600 possibilidades.
           3 * 2 * 1 * 3 * 2 * 1
    */





    for (int i=2;i<=60;i+=6){
        for (int j=1;j<=59;j+=6){
            for (int k=2;k<=60;k+=4){
                for (int l=1;l<=59;l+=4){
                    for (int o=2;o<=60;o+=2){
                        for (int p=1;p<=59;p+=2){
                            if(i!=k && i!=o && k!=o &&
                            j!=l && j!=p && l!=p){
                                
                                //soma-se ao total de possibilidades
                                contador_possibilidades++;
                                
                                //print opcional para visualizacao
                                if (escolha=='S'){
                                    printf("\n%d\t%d\t%d\t%d\t%d\t%d\tcontador ate agora: %d\n",
                                           i, j, k, l, o, p,
                                           contador_possibilidades);
                                }


                            }
                        }
                    }
                }
            }
        }
    }

    printf("%d",contador_possibilidades);




    return 0;
}
