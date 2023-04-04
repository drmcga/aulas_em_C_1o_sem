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
    int valor_primeiro,valor_segundo,valor_terceiro,valor_quarto,valor_quinto,valor_sexto,contador_possibilidades=0;

    //chamar o input
    printf("Este programa imprime as possibilidades de jogos que um jogador superstiticioso pode jogar.\n");
    printf("\no Modelo de impressao e:\n1o\t2o\t3o\t4o\t5o\t6o\n\nSeguem os prints:\n");

    /*
        é um exercicio de analise combinatoria simples.
        Anota-se os valores possiveis de cada casa, e os multiplica individualmente.
        Para a impressao de cada valor, entretanto, vem a pegada.
        E preciso guardar todos eles conforme surgem e os imprimir.
    */

    for (int i=2;i<=60;i+=2){
        for (int j=1;j<=59;j+=2){
            for (int k=2;k<=60;k+=2){
                for (int l=1;l<=59;l+=2){
                    for (int o=2;o<=60;o+=2){
                        for (int p=1;p<=59;p+=2){
                            if(i!=k && i!=o && k!=o &&
                                j!=l && j!=p && l!=p){
                                valor_primeiro  =i;
                                valor_segundo   =j;
                                valor_terceiro  =k;
                                valor_quarto    =l;
                                valor_quinto    =o;
                                valor_sexto     =p;

                                contador_possibilidades++;
/*
                                printf("\n%d\t%d\t%d\t%d\t%d\t%d\tcontador ate agora: %d\n",
                                       valor_primeiro,valor_segundo,valor_terceiro,
                                       valor_quarto,valor_quinto,valor_sexto,
                                       contador_possibilidades);

*/

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


