/*
ENUNCIADO

            Crie um programa que imprima esse desenho ASCII em um tamanho [n] escolhido.

    **              ****
   *  *             ****
   *  *  n=1      **    **
    **            **    **
                  **    **
                  **    **  n=2
                    ****
                    ****

 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    //a unica variavel fora do loop:
    int tamanho_n;
    scanf("%d",&tamanho_n);

    //desenho escrito por extenso.
    char desenho[4][4]={{' ','*','*',' '},
                        {'*',' ',' ','*'},
                        {'*',' ',' ','*'},
                        {' ','*','*',' '}};

    /*repeticao: 
        primeiro sao as linhas, 
        depois e a frequencia de vezes(n) que se repete a linha, 
        depois sao as colunas,
        depois e a frequencia de vezes(n) que se repete cada elemento interno da matriz
    */
    for (int i=0;i<4;i++){
        for (int n=1;n<=tamanho_n;n++){
            for (int j=0;j<4;j++){
                for (int n=1;n<=tamanho_n;n++){
                    printf("%c",desenho[i][j]);
                }
            }
            putchar('\n');
        }
    }

    return 0;
}
