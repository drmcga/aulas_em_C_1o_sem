/*
 *       ENUNCIADO
 *
 *      Crie um verificador de palindromos para palavras.
 *
*/
#include <stdio.h>
#include <stdlib.h>

int main(){

    //enunciacao das variaveis da string
    char palavra[99], primeira, ultima;

    //variavel auxiliar
    int cont=0, verify=1;

    //anuncio da funcao do codigo
    printf("\n  Insira aqui uma palavra para verificar se e um palindromo:\n\n\t\t---->>> ");

    //coleta o input
    gets(palavra);

    //loop para obter o tamanho da string que independe do strlen()
    for (int i=0;palavra[i]!='\0';i++){
        cont++;
    }

    //loop para verificar as duas letras
    //guardamos a primeira e a ultima letra/caractere
    //depois verificamos o valor, no mesmo loop.
    for (int i=0;i<cont/2;i++){
        //guardar
        primeira=palavra[i];
        ultima=palavra[cont-i-1];

        if(primeira==ultima) {
            continue;
        }else {
            verify=0;
            break;
        }

    }

    //printf final
    if (verify) printf("\n  Sua palavra e um palindromo!");
    else printf("\n  Sua palavra nao e um palindromo!");

    return 0;
}

