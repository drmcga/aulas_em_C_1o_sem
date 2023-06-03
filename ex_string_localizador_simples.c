/*
 *       ENUNCIADO
 *
 *      Faça um programa que leia um texto T (com espaços) e uma palavra p do teclado. Em
 *      seguida o programa deverá imprimir todas as posições onde ocorrem a palavra p em T.
 *
 *      Se por exemplo T = "duas bananas e 4 abacates. Nao havera mais bananas.", e p ="bananas",
 *      então o programa deveria imprimir 5 e 43.
 *
*/
#include <stdio.h>
#include <stdlib.h>

int main(){

    //chamada das variaveis principais das strings
    //vamos usar uma string pro grande e pro pequeno.
    char texto_T[9999], palavra[99];
    int lista_pos[99], tama_texto=0, tama_palavra=0, contador=0, k=0;

    //apresentacao da funcao do codigo
    printf("\n Esse codigo lhe permite encontrar a posicao de uma string pequena,");
    printf("\ndentro de uma string maior. Por exemplo 'a' em 'casa' lhe retorna 1 e 3.");

    //secao de obtencao de inputs
        //maior
    printf("\n\n\t>>Insira a sua STRING MAIOR<<\n\n->");
    gets(texto_T);
        //menor
    printf("\n\n\t>>Insira a sua STRING MENOR<<\n\n->");
    gets(palavra);

    //implementecao de strlen().
    for (tama_texto; texto_T[tama_texto]!='\0'; tama_texto++){}
    for (tama_palavra; palavra[tama_palavra]!='\0'; tama_palavra++){}


    //loop de analises:
    for (int i=0; texto_T[i]!='\0'; i++){                   //percorreremos a string inteira
        contador=0;
        if (texto_T[i]==palavra[0]){                        //encontramos uma inicial interessante, portanto temos coisa acontecendo.
            for (int j=0;palavra[j]!='\0';j++){             //percorremos ao mesmo tempo a string maior e a menor, usando i e j.
                if (palavra[j]==texto_T[i+j]) contador++;
            }
            if (contador==tama_palavra){                    //encontramos uma sequencia dentro da string maior equivalente a string menor
                lista_pos[k]=i;
                k++;
            }
        }
    }

    //prints finais
        //novamente implementando um formato diferente de print em blocos.
        //nesse eu tentei criar uma especie de lista que quebre em tantas repeticoes
        //e cada segmento que quebra vem acompanhado de uma arte em ascii so pra ilustrar a continuidade
        //me orgulho desse formato e da simplicidade do codigo.
    if (k){
    printf("\n--Sao %2d ocorrencias!\n As posicoes da primeira string quem contem sua segunda string sao:\n\t<[ ",k);
    for (int i=0;i<k;i++){
        printf("%4d, ",lista_pos[i]);
        if(i%13==12) printf("\n\t.  ");
    }
    printf("\b\b ]\n\t>\n");
    } else printf("\n--Nao houveram ocorrencias!\n\n");

    return 0;
}
