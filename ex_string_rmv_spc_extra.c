/*
 *       ENUNCIADO
 *
 *      Faça um programa que leia do teclado uma string (possivelmente com espaços) de até 80
 *      caracteres e que então salve a string lida em uma nova removendo-se os espaços extras
 *      entre as palavras.
 *              Exemplo de entrada:
 *      Out of the night   that covers me
 *      e vetor resultante:
 *              Out of the night that covers me
 *      Refaça o programa de tal forma que não seja utilizado nenhum vetor adicional! Ou seja
 *      devemos deixar a string sem espaços extras no próprio vetor original da string lida sem o
 *      uso de nenhum outro vetor auxiliar.
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
    printf("\nInsira aqui uma string que deseja remover espacos extras:\n\n\t\t---->>> ");

    //coleta o input
    gets(frase);


    //loop geral:
        //esse loop e semelhante ao loop do codigo ex_string_remove_spc.c
        //a diferenca e que ele so age se encontrarmos espacos duplos
        //e ao encontrar espacos duplos, passa a encarar o espaco extra como algo que precisa de expurgo
            //comeca um loop de empurra empurra pra se livrar do espaco extra
            //se o loop inicia, a gente muda espcs pra explicar que ainda tem mudancas para serem feitas
        //se nao tiver mudancas pra fazer e nem houverem sido feitas ate o final do loop, espcs=0, entao saimos do loop geral.
    while (rodar){
        espcs=0;
        for (int i=0;frase[i]!='\0';i++){
            if (frase[i]==' '&&frase[i+1]==' '){        //esse daqui encontra um espaco duplo
                frase[i+1]=frase[i+2];                  //fazemos com que o espaco duplo seja substituido pelo proximo caractere
                frase[i+2]=' ';                         //e jogamos ele pra frente
                espcs=1;
            }
            if (frase[i+1]==' '&&espcs==1){             //ao jogar ele pra frente, a gente libera o modo espcs pro resto do loop,
                frase[i+1]=frase[i+2];                  //ai nesse caso a gente trata o espaco do meio como se fosse um espaco que precisa ser excluido
                frase[i+2]=' ';                         //e ele funciona empurrando o espaco extra pra fora da string 1 casa por vez

            }
        }
        if (espcs==0) rodar=0;
    }

    //printf final
    printf("\nSua string sem espacos extras:\n\n\t\t---->>> %s",frase);


    return 0;
}
