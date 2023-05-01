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

    char vetor[99];

    printf("Digite uma string para analisar seu tamanho: "); gets(vetor);

    printf("O tamanho da string inserida e: %d",strlen(vetor));

    return 0;
}
