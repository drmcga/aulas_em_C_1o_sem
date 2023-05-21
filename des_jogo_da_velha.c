/*
 *       ENUNCIADO
 *
 *      Monte um modelo de jogo da velha com interface de texto.
 *      Use representacao grafica com caracteres que achar melhor.
 *      Permita ao usuario escolher entre um adversario humano ou IA
 *
 *
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//funcao para printar o tabuleiro
void printa_jogo(char matriz[3][3]){
  //topo
    printf("\n      i\\j>1    2    3"); //cabecalho
    printf("\n      v +---++---++---+\n"); //borda
  //meiuca
    for (int i=0;i<3;i++){
        printf("      %d ",i+1); //lateral esq
        for (int j=0;j<3;j++){
            printf("| %c |",matriz[i][j]); //conteudo

        }
        if (i<2) printf("\n\t+---++---++---+\n"); //bordas interiores
    }
    printf("\n\t+---++---++---+\n"); //bordas inferiores
}

//funcao para seres humanos trocarem os valores da matriz
//ela pega o estado atual da matriz e qual o caractere que esta alterando a celula
void edita_matriz(char (*matriz)[3], char obj){
    int i=0, j=0;
    printf("\n  Escolha qual posicao deseja adicionar: [ %c ]\n -FORMATO: < i +' '+ j >\n\t\t\t>>",obj);
  
  //input do usuario para escolher onde colocar.
  //como queria usar numeros naturais apenas, ele vai inputar de 1 a 3.
    scanf("%d %d", &i,&j);
  
  //por conta do uso exclusivo de naturais, precisamos reduzir em 1.
    if (matriz[i-1][j-1]==' ') //verifica-se apenas se esta vazio
        matriz[i-1][j-1]=obj;
    else { 
      //nao e preciso verificar se as extensoes dele, como matriz[6][6] funcionam, 
      //porque dificilmente o lixo de memoria vai ter o valor de ' '.
        printf("\n<<<<< Opcao invalida, escolha outro lugar. >>>>>>\n");
        edita_matriz(matriz, obj);//funcao encadeada
    }
}

//funcao que dita as ordems de um jogo entre humanos.
//dela partem outras funcoes que regem cada momento do jogo.
int jogo_humano(){

  //eu optei por inserir o mapa aqui e no jogo_ia() 
  //porque se fizesse isso pelo main() teria que botar referencias demais nas outras funcoes
    char tab_jogo[3][3]={
                            {' ',' ',' '},
                            {' ',' ',' '},
                            {' ',' ',' '}
                        };

  //print de apresentacao do modo
    printf("\n\tOpcao de jogo humano VS humano selecionada!!!\n\n");

  //print do inicio de jogo
    printa_jogo(tab_jogo);

  //um dos poucos casos que usamos random no arquivo inteiro
  //serve para decicidir quem joga primeiro
  //os chars decidem, repectivamente: de quem e a vez e se deseja continuar apos isso
    int moeda= rand()%2;
    char vez_de, escolha;

  //aqui vem a decisao do primeiro
    if (moeda==1) vez_de='x';
    else if (moeda==0) vez_de='o';

  //print de anuncio
    printf("\n\t<<<<< Jogo inicializado! >>>>>\n\n  O primeiro jogador e o: [ %c ]\n", vez_de);

  //loop oficial do PvP
  //o verificador e uma funcao que retorna 0 1 2, dependendo das condicoes
    while (verificador(tab_jogo)==1){//retornar 1 implica TRUE, alem de um game status=game
        edita_matriz(tab_jogo, vez_de);         //joga-se primeiro
        printa_jogo(tab_jogo);                  //depois mostramos o tabuleiro
        if (verificador(tab_jogo)!=1) break;    //se o estado do verificador mudar de 'game', encerra prematuramente.
        if (vez_de=='x') vez_de='o';            //caso contrario:
        else if (vez_de=='o') vez_de='x';       //swapamos os jogadores, para o proximo round.
    }
  
    printf("\n\tParece que o jogo acabou!");    //anuncio de que saimos do loop.

    if (verificador(tab_jogo)==0){//caso seja vitoria comum, verificador==0
        printf("\n\n\t\tO VENCEDOR DA PARTIDA E: [ %c ]\n\n",vez_de);
      
    }else {//caso seja empate/derrota mutua, verificador==2
        printf("\n\n  . . . Parece que ninguem ganhou dessa vez . . . ");
    }

  //pergunta padrao de bora ou arrega
    printf("\n\t. . . Deseja tentar novamente? . . . \n\t\t  ( S ) ou ( N )\n\t\t\t");
    scanf(" %c", &escolha);

  //para evitar muita complicacao, a escolha leva diretamente para o modo PvP
    if (escolha=='S'||escolha=='s') {
        jogo_humano();
    }else if (escolha=='N'||escolha=='n'){
        return;
      //se nao, saimos dessa funcao, finalmente.
      //isso nos leva de volta a main()
    }


}

//quis encurtar alguns prints.
//isso serve para enunciar qual o slot que a ia escolheu.
void escolhido_ia(int a, int b){
    printf("\n\t . . . A IA escolheu < %d e %d > . . .\n", a+1, b+1);
    return;
}

//as escolhas da ia estao longe de ideais,
//primeiro que tudo foi praticamente hard coded
//segundo que se houver um caso 
/*
 * X O
 * X O
 * _ _
 * Ele vai optar por barrar o X ao inves de ganhar.
 * Nao sei como consertar isso.
*/
void vez_robo(char (*matriz)[3]){
    srand(time(NULL));

    //verificador de possibilidades muito obvias de vitorias
    if(((matriz[0][0]!=' '&&matriz[2][2]!=' ')||(matriz[0][2]!=' '&&matriz[2][0]!=' '))&&(matriz[1][1]==' ')){
        matriz[1][1]='o';//meio
        escolhido_ia(1,1);
        return;
    }else if((matriz[0][0]!=' '&&matriz[1][1]!=' ')&&matriz[2][2]==' '&&(matriz[0][0]==matriz[1][1])){
        matriz[2][2]='o';//canto inf direito
        escolhido_ia(2,2);
        return;
    }else if((matriz[0][2]!=' '&&matriz[1][1]!=' ')&&matriz[2][0]==' '&&(matriz[0][2]==matriz[1][1])){
        matriz[2][0]='o';//canto inf esq
        escolhido_ia(2,0);
        return;
    }else if((matriz[2][2]!=' '&&matriz[1][1]!=' ')&&matriz[0][0]==' '&&(matriz[2][2]==matriz[1][1])){
        matriz[0][0]='o';//canto sup esq
        escolhido_ia(0,0);
        return;
    }else if((matriz[2][0]!=' '&&matriz[1][1]!=' ')&&matriz[0][2]==' '&&(matriz[2][0]==matriz[1][1])){
        matriz[0][2]='o';//canto sup dir
        escolhido_ia(0,2);
        return;
    }

    //verificador de possibilidades menos obvias
    for (int i=0;i<3;i++){

        if (matriz[i][0]!=' '&&matriz[i][2]!=' '&&matriz[i][1]==' '&&(matriz[i][0]==matriz[i][2])){
            matriz[i][1]='o';//meios de linha
            escolhido_ia(i,1);
            return;
        }else if (matriz[0][i]!=' '&&matriz[2][i]!=' '&&matriz[1][i]==' '&&(matriz[0][i]==matriz[2][i])){
            matriz[1][i]='o';//meio de coluna
            escolhido_ia(1,i);
            return;
        }else if(matriz[i][0]!=' '&&matriz[i][1]!=' '&&matriz[i][2]==' '&&(matriz[i][0]==matriz[i][1])){
            matriz[i][2]='o';//cantos direitos
            escolhido_ia(i,2);
            return;
        }else if(matriz[i][1]!=' '&&matriz[i][2]!=' '&&matriz[i][0]==' '&&(matriz[i][1]==matriz[i][2])){
            matriz[i][0]='o';//cantos esquerdos
            escolhido_ia(i,0);
            return;
        }else if(matriz[0][i]!=' '&&matriz[1][i]!=' '&&matriz[2][i]==' '&&(matriz[0][i]==matriz[1][i])){
            matriz[2][i]='o';//cantos inferiores
            escolhido_ia(2,i);
            return;
        }else if(matriz[1][i]!=' '&&matriz[2][i]!=' '&&matriz[0][i]==' '&&(matriz[1][i]==matriz[2][i])){
            matriz[0][i]='o';//cantos superiores
            escolhido_ia(0,i);
            return;
        }


    }

    if (matriz[1][1]==' '){
        matriz[1][1]='o';//meiuca best start
        escolhido_ia(1,1);
        return;
    }

    int dado, moeda=rand()%2;
    //jogadas em casos iniciais, quando meiuca nao esta disponivel
  
  //a moeda decide se usaremos meios ou pontas
  //moeda =1 ponta
    if (moeda==1){
          while (1){
            dado=rand()%4;
            if (dado==0&&matriz[0][0]==' '){
                matriz[0][0]='o';//canto sup esq
                escolhido_ia(0,0);
                return;
            }else if (dado==1&&matriz[0][2]==' '){
                matriz[0][2]='o';//canto sup dir
                escolhido_ia(0,2);
                return;
            }else if (dado==2&&matriz[2][2]==' '){
                matriz[2][2]='o';//canto inf dir
                escolhido_ia(2,2);
                return;
            }else if (dado==3&&matriz[2][0]==' '){
                matriz[2][0]='o';//canto inf esq
                escolhido_ia(2,0);
                return;
            }
        }
      
    }else if(moeda==0){//moeda = 0, meios
     while (1){
            dado=rand()%4;
            if (dado==0&&matriz[0][1]==' '){
                matriz[0][1]='o';//canto sup
                escolhido_ia(0,1);
                return;
            }else if (dado==1&&matriz[1][2]==' '){
                matriz[1][2]='o';//canto dir
                escolhido_ia(1,2);
                return;
            }else if (dado==2&&matriz[2][1]==' '){
                matriz[2][1]='o';//canto inf
                escolhido_ia(2,1);
                return;
            }else if (dado==3&&matriz[1][0]==' '){
                matriz[1][0]='o';//canto esq
                escolhido_ia(1,0);
                return;
            }
        }

    }

}


//funcao que decide a ordem de eventos de uma partida PvE
void jogo_IA(){

    char tab_jogo[3][3]={//mesma regra de tabela
                            {' ',' ',' '},
                            {' ',' ',' '},
                            {' ',' ',' '}
                        };

  //print de apresentecao
    printf("\n\tOpcao de jogo humano VS maquina selecionada!!!\n\n");

  //print de tabuleiro
    printa_jogo(tab_jogo);
  
  //esse int e o que decide o estado de jogo
  //true ->se vencer, quer dizer que o jogador estava no controle
  //false -> se vencer quer dizer que a ia estava no controle
    int jogando=1;
    char escolha;

  
  //aqui somente o jogador pode comecar, por questao de simplicidade e dar mais acao
    printf("\n\t<<<<< Jogo inicializado! >>>>>\n\n  O primeiro jogador e voce!!!");

  //loop oficial de pve
    while (verificador(tab_jogo)==1){     //usa a mesma regra de verificador.
      
        jogando=1;                        //aqui garante que sera o jogador que fara o prox movimento
        edita_matriz(tab_jogo, 'x');      //mesma funcao do pvp, porem so o X realiza movimentos.
        printa_jogo(tab_jogo);            //mostra a acao que acabou de tomar
        if (verificador(tab_jogo)!=1) break;    //caso ganhe, encerra o loop, antes de trocar o "jogando"
        
        printf("\n  A IA esta escolhendo onde deseja adicionar: [ o ]\n\t\t. . .\n\t       Escolhido!\n"); //flavor text, mas tambem anuncia que a sua vez acabou
        
        jogando=0;                        //oficialmente nao esta mais jogando
        vez_robo(tab_jogo);               //entra na funcao de escolha do robo
        printa_jogo(tab_jogo);            //printa o tabuleiro apos o mov dele.

    }
    printf("\n\tParece que o jogo acabou!"); //anuncio do fim

    if (verificador(tab_jogo)==0&&jogando){
        printf("\n\nVOCE VENCEU A PARTIDA\n\n");

    }else if(verificador(tab_jogo)==0&&!jogando){
        printf("\n\n\t    QUE PENA, VOCE PERDEU\n\n");
    }else {
        printf("\n\n  . . . Parece que ninguem ganhou dessa vez . . . ");
    }

    printf("\n\t. . . Deseja tentar novamente? . . . \n\t\t  ( S ) ou ( N )\n\t\t\t");
    scanf(" %c", &escolha);

    if (escolha=='S'||escolha=='s') {
        jogo_IA();
    }else if (escolha=='N'||escolha=='n'){
        return;
    }





}

int verificador(char (*matriz)[3]){

    for (int aux=0;aux<3;aux++){ //verifica em trios
       if (matriz[aux][0]==matriz[aux][1]&&matriz[aux][0]==matriz[aux][2]&&matriz[aux][0]!=' ') return 0; 
      //se horizontal completament igual = vitoria
    }for (int aux=0;aux<3;aux++){
       if (matriz[0][aux]==matriz[1][aux]&&matriz[0][aux]==matriz[2][aux]&&matriz[0][aux]!=' ') return 0;
      //se vertical completamente igual = vitoria
    }
  
  //se diagonais iguais = vitoria
    if (matriz[0][0]==matriz[1][1]&&matriz[0][0]==matriz[2][2]&&matriz[0][0]!=' ') return 0;
    else if (matriz[0][2]==matriz[1][1]&&matriz[0][2]==matriz[2][0]&&matriz[0][2]!=' ') return 0;

  //se todos preenchidos, sem ter tido vitoria ate agora = derrota
    int cont=0;
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if (matriz[i][j]!=' ') cont++;
        }
    }
    if (cont==9) return 2;

  //se nao houve vitoria, nem esta preenchido, segue o barco.
    return 1;

}


//loop principal, so serve para dar ordem aos bois.
int main()
{
  //anuncio do random.
    srand(time(NULL));

  //chamada para a escolha entre PvP e PvE
    char escolha;

    printf("\n\t\tOla bem vindo ao jogo da velha!\n");
    printf(" Para continuar, selecione qual modelo de opoenente deseja enfrentar:\n\t\t(H) Humano\t(M) Maquina");
    printf("\n\t\t\t     ");
    scanf("%c",&escolha);

    if (escolha=='H'||escolha=='h'){
        jogo_humano();
    }else if (escolha=='M'||escolha=='m'){
        jogo_IA();
    }
  
  //print final com artezinha
    printf("\n\n\t\t\t.\n\t\t\t.\n\t\t\t.\n\t\t\t.\n\tObrigado por jogar o jogo da velha!\n\t\t\t.\n\t\t\t.\n");



    return 0;
}
