
#include <stdio.h>
#include <stdlib.h>

int main(){

    //variaveis
        //atributos uteis para geracao de novas matrizes
    int atrb_hum=0, atrb_zum=0, linhas, colunas, geracoes;

        //atributos para analise de cada elemento
    int lista_entorno_x[8]={-1,-1,-1,0,0,1,1,1}, lista_entorno_y[8]={-1,0,1,-1,1,-1,0,1};

        //as matrizes em si
    int matriz_total[99][50][50], matriz_ext[52][52];

        //matriz verificadora
    int caso_estudo;


    //apresentacao do codigo
        //dessa vez resolvi colocar uma extensa explicacao dentro do
        //prompt do comando. E diferente de colocar tudo no "//enunciado",
        // na medida em que o leitor do codigo e obrigado a ler

        //Optei por essa formatacao de texto porque pensei
        //na impressao de papel termico de impressoras de mercado.
    printf("  O presente codigo lhe permite analisar geracoes de uma matriz\n");
    printf(" Para tanto, e preciso escolher suas dimensoes, depois o numero\n");
    printf(" de geracoes que gostaria de analisar e por ultimo, e preciso  \n");
    printf(" inserir celular por celula os valores da matriz.            \n\n");

    printf("  Cada elemento da matriz tem um comportamento diferente:      \n");
    printf("    celula 1 -> 2 <se> houver 2 no entorno                     \n");
    printf("    celula 2 -> 0 <se> houver dois ou mais 1's no entorno      \n");
    printf("    celula 2 -> 0 <se> nao houver nenhum 1 no entorno          \n");
    printf("    celula 0 -> 1 <se> houver exatamente dois 1's no entorno   \n");

    printf("  Dito isso, vamos aos inputs:                               \n\n");


    //inputs
        //tamanhos
    printf("Digite linhas e colunas da matriz de 0 a 50 no formato:\n-> L C\n");
    printf("-> ");
    scanf("%d %d", &linhas, &colunas);

        //geracoes
    printf("\nDigite a quantidade de geracoes que quer gerar:              \n");
    printf("-> ");
    scanf("%d", &geracoes);

        //loop de input da matriz em si
    printf("\nDigite celular por celula o valor de cada elemento da matriz:\n");
    for (int i=0;i<linhas;i++){
        for (int j=0;j<colunas;j++){
            printf("Digite LIN(%2d) COL(%2d) ---> ",i+1,j+1);
            scanf("%d",&matriz_total[0][i][j]);
        }
        puts("");
    }


    puts("");


    //loop principal
    for (int atu=0;atu<geracoes;atu++){

        //criacao de uma matriz extendida que tem 1 linha extendida para cada lado
            //primeiro sao feitas cima e baixo
            //as linhas sao construidas pegando os caracteres do canto
            // oposto, os de cima puxam os debaixo e vice versa
        for (int i=0;i<colunas;i++){
            matriz_ext[0][i+1]=matriz_total[atu][linhas-1][i];
            matriz_ext[linhas+1][i+1]=matriz_total[atu][0][i];
        }

            //depois sao feitos os 4 cantos
            //cada canto fica no canto inverso em relacao ao centro
        matriz_ext[0][0]=matriz_total[atu][linhas-1][colunas-1];
        matriz_ext[linhas+1][colunas+1]=matriz_total[atu][0][0];
        matriz_ext[0][colunas+1]=matriz_total[atu][linhas-1][0];
        matriz_ext[linhas+1][0]=matriz_total[atu][0][colunas-1];

            //depois colocamos as laterais
            //elas sao feitas usando o começo e fim de cada linha,
            //jogando o final da original para o começo da parte extendida
        for (int i=0;i<linhas;i++){
            matriz_ext[i+1][colunas+1]=matriz_total[atu][i][0];
            matriz_ext[i+1][0]=matriz_total[atu][i][colunas-1];
        }

            //por ultimo vem o recheio.
         for (int i=0;i<linhas;i++){
            for  (int j=0;j<colunas;j++){
                matriz_ext[i+1][j+1]=matriz_total[atu][i][j];
            }
        }
        //!eu quero otimizar esse metodo.

        //primeiro vem o print do modelo atual.
            //o print acontece toda vez antes de um mudanca
            //entao se voce solicitar 8 geracoes, eu te entrego os 8 prints,
            //mas a matriz mais recente gerada, na verdade equivale a 9a geracao.
        printf("iteracao %d\n",atu);
        for (int i=0;i<linhas;i++){
            for (int j=0;j<colunas;j++){
                    printf("%d", matriz_total[atu][i][j]);
                }
            printf("\n");
        }

        //depois do print, vem a geracao da nova matriz
            //o loop percorre toda a matriz
        for (int i=0;i<linhas;i++){
            for (int j=0;j<colunas;j++){

                //nos certificamos de que esses valores estao zerados.
                atrb_hum=0;
                atrb_zum=0;

                //criamos um loop que roda a celular analisada da vez
                    //esse loop serve para as listas de entorno

                    //cada celula do entorno pode ser escrita em funcao da celula estudada
                    //por exemplo, as de cima possuem o mesmo X reduzido de 1
                    //as da esquerda possuem o mesmo Y acrescido de 1
                    //essas transofrmacoes estao descritas em duas listas
                    // distintas, as listas de entorno X e Y.

                    //cada variacao de canto, equivale a uma unidade dessas listas,
                    // que hora acrescentam ou decrescem dos valores de referencia
                for (int canto=0;canto<8;canto++){

                    //caso estudo e um valor de int comum, que pode ser 0 1 ou 2,
                    //ele so retorna o valor que estava contido no canto estudado, da celula selecionada
                    caso_estudo=matriz_ext[i+lista_entorno_x[canto]+1][j+lista_entorno_y[canto]+1];

                    //um switch case bem simples, que soma nas duas
                    // variaveis contadoras caso encontre algo relevante
                    //eu mantenho o case 0 para o caso de adicao de novas regras
                    switch (caso_estudo) {
                      case 0:
                        break;
                      case 1:
                        atrb_hum++;
                        break;
                      case 2:
                        atrb_zum++;
                        break;
                    }

                }//aqui termina o loop de 0 - 8.


                //com os valores de atrb zumb e hum, ele avalia a celula:
                    //em primeiro lugar ele pega o valor da celula, 0, 1 ou 2
                switch (matriz_total[atu][i][j]){

                    //caso seja 0, so pode haver uma transformacao, para 1
                    //isso acontece quando tem exatamente 2 vizinhos humanos.
                        //se nada acontecer, reproduz um 0 pra proxima geracao.
                    case 0:
                        if (atrb_hum==2) matriz_total[atu+1][i][j]=1;
                        else matriz_total[atu+1][i][j]=0;
                        break;

                    //caso seja 1, ele so pode se tornar 2
                    //ele so se torna 2 se houver atrb zum
                        //se nao houver atb zum, ele reproduz 1 pra prox geracao
                    case 1:
                        if (atrb_zum>0) matriz_total[atu+1][i][j]=2;
                        else matriz_total[atu+1][i][j]=1;
                        break;

                    //em caso de 2, ele so pode se tornar 0
                    //isso acontece quando falta atrb hum pra ele
                        //se nao houver atrb hum, ele se torna 0
                        //caso contrario, reproduz 2
                    case 2:
                        if (atrb_hum==0||atrb_hum>=2) matriz_total[atu+1][i][j]=0;
                        else matriz_total[atu+1][i][j]=2;
                        break;

                }//fim do switch case

            }
        }
        //fim dos loops de celula / celula

    }

    return 0;
}





