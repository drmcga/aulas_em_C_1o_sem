/*
 *       ENUNCIADO
 *       Escreva um programa que leia uma sequência de números inteiros positivos maiores que
 *       1 e os salva em um vetor. O programa deve ler um número inteiro n que representa o
 *       número de elementos da sequência, depois em seguida os n números e os salvar em um
 *       vetor v. Assuma que o tamanho máximo da sequência é 50.
 *
 *       O programa deve então imprimir um quadrado de n linhas por n colunas onde em cada
 *       posição (i, j) (onde i = 0, . . . ,n−1 e j = 0, . . . ,n−1) deste quadrado deverá ser impresso
 *       1 caso os números v[i] e v[j] sejam coprimos e 0 caso contrário.
 *
 *       Os pares de números v[i] e v[j] são coprimos se não há nenhum divisor d > 1 que seja
 *       comum a ambos. Por exemplo 15 e 8 são coprimos, pois os divisores de 8, que são 2, 4 e 8,
 *       não são divisores de 15. Abaixo temos um exemplo de execução do programa para n = 6
 *       e v = [2, 3, 4, 5, 6, 7].
 *
 *       v[0 ] v[1] v[2] v[3] v[4] v[5]
 *   v[0]   0    1    0    1    0    1
 *   v[1]   1    0    1    1    0    1
 *   v[2]   0    1    0    1    0    1
 *   v[3]   1    1    1    0    1    1
 *   v[4]   0    0    0    1    0    1
 *   v[5]   1    1    1    1    1    0
 *
 *
*/
#include <stdio.h>
#include <stdlib.h>

int main(){

    //variaveis importantes para matriz
        //a qnt e a quantidade de valores da listas
        //lista a e a propria lista, com limite
        //matriz-cpm e a matriz de coprimos relacionada, como no enunciado
    int qnt_n, lista_a[50], matriz_cpm[50][50];

    //variavel auxiliar para verificacao
    int verify=1;

    //prints de apresentacao
    printf("\n Esse programa permite avaliar se numeros sao coprimos entre si.");
    printf("\n Na matriz final, caso o numero tenha 1, seu i e j sao coprimos.\n");

    printf(" Digite a quantidade de valores que gostaria de analisar:\n\n\t\t--->> ");

    //puxar o comprimento da lista
    scanf("%d",&qnt_n);

    //prints e scanfs de valores da lista
    printf("\n\tDigite agora os valores:\n");
    for (int i=0;i<qnt_n;i++){
        printf("Valor n%2do -> ",i+1);
        scanf("%d",&lista_a[i]);

    }

    //loop principal
        //nesse loop nos temos ele rodando em pares,
        //cada par avalia se tem divs em comum entre si
        //caso nao tenha, verify=1, e portanto sao coprimos
    for (int i=0; i<qnt_n;i++){                                 //percorremos as linhas
        for (int j=0; j<qnt_n;j++){                             //percorremos as colunas
            verify=1;
            for (int divs=2; divs<=lista_a[i];divs++){          //verificamos os divisores
                if (lista_a[i]%divs==0&&lista_a[j]%divs==0){    //aqui encontramos um divisor comum!
                    matriz_cpm[i][j]=0;
                    verify=0;
                }
            }
            if (verify==1) {
                matriz_cpm[i][j]=1;
            }
        }
    }


    //prints finais no formato requisitado.



    for (int i=0;i<qnt_n;i++){
        if (i==0){                          //print da primeira linha
            printf("\n      ");
            for (int k=0;k<qnt_n;k++){
                printf("v[%2d] ", k);       //print dos v[]s
            }
            printf("\n");
        }
        printf(" v[%2d]",i);
        for (int j=0;j<qnt_n;j++){
            printf("  %2d  ", matriz_cpm[i][j]);
        }
        printf("\n");
    }

    return 0;
}
