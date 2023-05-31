/*
 *       ENUNCIADO
 *
 *      Faça um programa que leia do teclado uma string (possivelmente com espaços) de até 80
 *      caracteres e que então salve a string lida em uma nova removendo-se os espaços.
 *      Exemplo de entrada:
 *          Out of the night that covers me
 *      e vetor resultante:
 *          Outofthenightthatcoversme
 *      Refaça o programa de tal forma que não seja utilizado nenhum vetor adicional! Ou seja
 *      devemos deixar a string sem espaços no próprio vetor original da string lida sem o uso de
 *      nenhum outro vetor auxiliar.
 *
 *
*/
#include <stdio.h>
#include <stdlib.h>

int main(){

    //enunciacao das variaveis da string
    char frase[80];
    int espcs=0, rodar=1;
    //anuncio da funcao do codigo
    printf("\nInsira aqui uma string que deseja remover espacos:\n\n\t\t---->>> ");

    //coleta o input
    gets(frase);

    //loop geral da troca:
        //primeiro criamos uma condicao verdade que depende de uma condicao
        //depois, asseguramos de que a condicao pode ser revertida
        //ai entramos em outro loop
            //esse loop verifica slot por slot, e se achar um espaco, inverte as posicoes
            //se inverter, troca o valor da condicional
            //ele percorre a string ate chegar no '\0'.
        //se nao houver inversao, a condicional ta intacta, 0, e pode sair do loop maior
    while (rodar){
        espcs=0;
        for (int i=0;frase[i]!='\0';i++){
            if (frase[i]==' '){                 //espaco encontrado
                frase[i]=frase[i+1];            //troca realizada
                frase[i+1]=' ';                 
                espcs=1;                        //condicional virada
            }
        }
        if (espcs==0) rodar=0;
    }

    
    //printf final
    printf("\nSua string sem espacos:\n\n\t\t---->>> %s",frase);


    return 0;
}
