/*
 *       ENUNCIADO
 *
 *      Escreva um programa que leia duas palavras do teclado e determina se a segunda é um
 *      anagrama da primeira. Uma palavra é um anagrama de outra se todas as letras de uma
 *      ocorrem na outra, em mesmo número, independente da posição. Exemplos: ROMA, MORA,
 *      ORAM, AMOR, RAMO são anagramas entre si.
 *
*/
#include <stdio.h>
#include <stdlib.h>

int main(){

    //enunciacao das variaveis das palavras
    char palavra_a[99], palavra_b[99];

    int cont_a=0, cont_b=0, trava=1;

    int esta_presente=0, ja_foi=0;


    //anuncio da funcao do codigo
    printf("\n Esse codigo permite verificar se duas palavras sao anagramas uma da outra.\n");
    printf("  Anagramas sao palavras que contem as mesmas letras em ordem invertida.\n");
    printf("\t>>Portanto, evite usar palavras de comprimento diferente!!<<\n\n");

    while (trava){
        for (int i=0;i<2;i++){
            printf("\t- Por favor, insira a %da palavra: ",i+1);
            if (!i) gets(palavra_a);
            else gets(palavra_b);
        }

        for (cont_a; palavra_a[cont_a]!='\0'; cont_a++){}
        for (cont_b; palavra_b[cont_b]!='\0'; cont_b++){}

        if (cont_a!=cont_b) {
            printf("\n Escolha palavras que pelo menos tenham o mesmo tamanho.\n\n");
        } else trava=0;
    }

    for (int i=0;i<cont_a;i++){
        for (int j=0;j<cont_a;j++){
            if (!ja_foi&&palavra_a[i]==palavra_b[j]&&palavra_a[i]!=' '){
                esta_presente++;
                ja_foi=1;
                palavra_a[i]=' ';
                palavra_b[j]=' ';
            }
        }
        ja_foi=0;
    }

    if (esta_presente==cont_a) printf("\n \t\tTemos um anagrama!!!\n\n");
    else printf("\n\tParece que nao temos um anagrama. . .\n\n");

    return 0;
}
