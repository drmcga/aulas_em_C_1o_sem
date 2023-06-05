/*
 *      ENUNCIADO
 *
 *      Faça um programa que leia duas palavras e verifique se uma delas pode ser obtida por
 *      meio da remocao de letras da outra. A ordem das letras nao pode ser alterada.
 *
 *      Por exemplo:
 *          moda e uma subsequencia em moradia
 *          cereja e uma subsequencia em cerveja
 *
*/
#include <stdio.h>
#include <stdlib.h>


int main(){

    //chamada das variaveis principais das strings
    char string_a[99], string_b[99];
    int tamanho_a=0, tamanho_b=0;

    //explicacao sobre o codigo
    printf("\n Esse codigo permite verificar se uma string esta contida em outra.");
    printf("\nIsso e obtido por meio de remocao de caracteres da segunda string.");
    printf("\nA segunda string e o bloco maior que deve ou nao conter a primeira.\n");

    //loop de inputs
    for (int i=0;i<2;i++){
        printf("\n  Insira agora a %da string:\n--> ",i+1);
        if (!i) gets(string_a);
        else gets(string_b);
    }

    //strlen() das string.
    for (tamanho_a; string_a[tamanho_a]!='\0'; tamanho_a++){}
    for (tamanho_b; string_b[tamanho_b]!='\0'; tamanho_b++){}

    //variaveis auxiliares
    int contagem_a=0;

    //loop de estudos.
    for (int i=0;string_b[i]!='\0';i++){
        if (string_a[contagem_a]==string_b[i]){
            contagem_a++;
        }
    }

    int aux=0;

    if (contagem_a==tamanho_a){
        printf("\nA string: '%s' esta contida em '%s'\n", string_a, string_b);
        
    } else{
        printf("\nA string: '%s' NAO esta contida em '%s'", string_a, string_b);
    }


    return 0;
}
