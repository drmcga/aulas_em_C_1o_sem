/*
 *       ENUNCIADO
 *
 *      Escreva um programa que lê uma string de até 50 caracteres, e imprime "Palindromo"caso
 *      a string seja um palindromo e "Nao Palindromo" caso contrário. OBS: Um palindromo
 *      é uma palavra ou frase, que é igual quando lida da esquerda para a direita ou da direita
 *      para a esquerda (assuma que só são usados caracteres minúsculos e sem acentos. Espaços
 *      em brancos devem ser descartados). Exemplo de palindromo: saudavel leva duas.
 *
*/
#include <stdio.h>
#include <stdlib.h>Ama! e ae!? Se a ea ma!

    //exemplos de strings complexas para testar:
        //Luza Rocelina, a namorada do Manuel, leu na moda da Romana: anil e cor azul.
        //Oh nossas luvas avulsas, sonho...
        //Oi, rato otario!
        //O romano acata amores a damas amadas e Roma ataca o namoro.
        //Ole! Maracuja, caju, caramelo!
        //Ama! e ae!? Se a ea ma!
        //O! treco?? certo...

int main(){


    //chamada das variaveis principais das strings
        //sentenca e a string explicita
        //comp_sntc se refere ao comprimento, que so e atribuido depois do strlen manual ali embaixo
    char sentenca[99];
    int comp_sntc=0;


    //explicacao sobre o codigo
    printf("\n     Esse codigo lhe permite verificar se frases inteiras sao palindromos ");
    printf("\nou nao. Por exemplo, 'Roma me tem amor' e um caso de palindromo em frases;");
    printf("\nJa a palavra 'Arara' e um exemplo em palavras.");

    //ordem de input
    printf("\n\n     Insira uma sentenca que deseja verificar se e ou nao palindromo.");
    printf("\nPode ter pontuacao, maiusculas e minusculas. Ele so nao suporta acentuacao.\n\n-->");

    //inputs
    gets(sentenca);

    //strlen() da string.
    for (comp_sntc; sentenca[comp_sntc]!='\0'; comp_sntc++){}

    //loop da limpeza da string
        //nesse loop, removemos espacos e caracteres estranhos
        //primeiro checamos se rodar ainda e valido
        //entao rodamos a string inteira, ate \0
            //se o elemento encontrado nao for uma letra, ou seja, for qualquer um dos outros 100 e tantos caracteres, removemos
            //o processo de remocao se baseia em substituir por espaco e empurrar pra frente
            //como espacos ja sao caracteres estranhos, da a impressao de que estao apenas pulando uma casa pro lado.
            //caso haja trocas, acrescemos no contador espcs, que indica que houve mudanca
        //depois da limpeza de caracteres estranhos, caso seja uma letra maiuscula analisada, minusculamos ela
        //caso tenha acontecido uma mudanca nesse loop, espcs nao sera zero, o que indica que pode ser que ainda haja mudancas para serem feitas
            //recomeca-se o loop.
            //se nao houver mudancas, encerra-se o loop.
    int rodar=1, espcs=0;
    while (rodar){
        espcs=0;
        for (int i=0;sentenca[i]!='\0';i++){
            if (sentenca[i]<65||(sentenca[i]>90&&sentenca[i]<=96)||sentenca[i]>122){
                sentenca[i]=sentenca[i+1];
                sentenca[i+1]=' ';
                espcs=1;

            }
            if (sentenca[i]>=65 &&sentenca[i]<=90) //maiuscula
            sentenca[i]+=32;
        }
        if (espcs==0) rodar=0;
    }

    //resetar o tamanho da string
    comp_sntc=0;
    for (comp_sntc; sentenca[comp_sntc]!='\0'; comp_sntc++){}


    //variavel util para esse loop
    int is_palindromo=1;

    //loop final de analise
    //ele vai do inicio ate a metade da palavra, pra isso precisamos do tamanho atualizado dela.
        //checamos o primeiro e o ultimo caractere de uma string toda minuscula e sem espacos
            //se eles forem iguais, continuamos o estudo
            //caso contrario, encerramos o loop e dizemos que is_palindromo=false.
    for (int i=0;i<comp_sntc/2;i++){

        if(sentenca[i]==sentenca[comp_sntc-i-1]){
            continue;
        }else {
            is_palindromo=0;
            break;
        }
    }

    if (is_palindromo) printf("\n\t\tEncontramos um palindromo!!\n");
    else printf("\n\t\tNao e um palindromo!!\n");

    return 0;
}
