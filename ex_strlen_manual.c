/*
    ENUNCIADO

    Implemente strlen(char *s) <-- uma funcao que devolve o tamanho em caracteres de uma string


*/
#include <stdio.h>
#include <stdlib.h>

char strlen(char *s){

    char *ptr=s; //equivalente a escrever: *ptr=&s[0]

    while (*s!='\0')
        s++;
    

    return (int) (s-ptr);
}



int main()
{

    char nome[99];

    printf("Digite um nome para analisar seu tamanho: "); gets(nome);

    printf("O tmanho da string inserida e: %d",strlen(nome));

    return 0;
}
