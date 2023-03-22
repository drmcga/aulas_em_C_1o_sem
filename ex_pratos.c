/*
    ENUNCIADO

    Faça um programa que imprima um menu de 4 pratos na tela e uma quinta opção para sair
    do programa. O programa deve imprimir o prato solicitado. O programa deve terminar
    quando for escolhido a quinta opção.

    utilizando somente condicionais
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char escolha;

    printf("Escolha entre 4 pratos:\n\tMacarrao (M)\t\tPizza (P)\t\tLasagna (L)\t\tCrostini (C)\n\nCaso Contrario, digite (S) para sair.\n\n");

    scanf("%c",&escolha);

    if (escolha=='M'){
        printf("Voce escolheu Macarrao");
    } else if (escolha=='P'){
        printf("Voce escolheu Pizza");
    } else if (escolha=='L'){
        printf("Voce escolheu Lasagna");
    } else if (escolha=='C'){
        printf("Voce escolheu Crostini");
    }  else if (escolha=='S'){
        printf("Voce escolheu sair");
    }   else {
        printf("Voce escolheu algo invalido, tente novamente:\n");

    }

    return 0;
}