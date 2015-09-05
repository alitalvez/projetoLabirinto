/****
*
* Título: Labirinto Beta
*
* Autor: Gabriel Rodrigues dos Santos
*
* Data de Criação: 18/08/2015
* Última modificação: 20/08/2015
*
* Descrição: O programa tem como objetivo achar a saida de um labirinto qualquer
* usando condicionais, if e else, e uma unica função recursiva, a função ChecagemETroca.
* O programa recebe o labirinto e a localização e informa como sair do mesmo.
* O labirinto é composto de elementos booleanos inicialmente, onde "0"(falso) representa uma
* obstrução e "1"(verdade) representa uma passagem livre. Após o programa achar a saida do labirinto,
* ele diz por onde deve-se ir para sair, através de um caminho de algarismos "3".
*
* Entrada: Espera-se que o usuario entre com um arquivo "Labirinto.txt", onde na primeira
* linha é informado a posição inicial no labirinto com coordenadas, x e y, na segunda
* linha é informado a dimensão do labirinto quadrado e na terceira linha em diante
* é informado a matriz do labirinto com os elementos booleanos do labirinto.
*
* Exemplo: Usuario cria um arquivo chamado Labirinto.txt e nele informa
*   Labirinto.txt
*  __________
*  | 5  4   |
*  | 5      |
*  | 11111  |
*  | 10101  |
*  | 10101  |
*  | 10110  |
*  | 00000  |
*  ¨¨¨¨¨¨¨¨¨¨
*
* Saída: O programa processa as informações do usuario e gera uma matriz mostrando
* o caminho de saida. Onde os algarismos "3" na matriz, representa por onde o usuario
* deve passar para sair do labirinto e quando não há nenhuma saida, o programa
* exibe a mensagem "Labirinto Sem Saida!".
*
* Exemplo: Recebido Labirinto.txt o programa retorna
*
*  SaidaLabirinto.txt
*  __________
*  | 11311  |
*  | 10301  |
*  | 10301  |
*  | 10330  |
*  | 00000  |
*  ¨¨¨¨¨¨¨¨¨¨
*
****/

//Chamada de bibliotecas
#include <stdio.h>
#include <stdlib.h>


//Estrutura que armazena o ponto informado pelo usuario
typedef struct
{
        int x; //Ponto na matriz com sentido vertical
        int y; //Ponto na matriz com sentido horizontal
}tPontoLabirinto;


void ChecagemETroca( tPontoLabirinto * , int [ ][ 12 ] );
/****
*
* Título: ChecagemETroca
*
* Autor: Gabriel Rodrigues dos Santos
*
* Data de Criação: 18/08/2015
* Última modificação: 19/08/2015
*
* Descrição: A função ChecagemETroca verifica se existe algum caminho livre ao
* redor da posição atual do ponto e se essa posição existir, então ele se move
* para a nova posição, livre. Se houver alguma bifurcação no caminho o ponto irá
* se mover para um dos lados até encontrar a saida ou um caminho sem saida. Caso
* encontre um caminho sem saida, então o ponto irá retornar até o local da bifurcação
* e ir pelo outro caminho, assim ocorre em qualquer bifurcação.
*
* Parâmetros:
* Entrada: Um ponteiro para o tipo tPontoLabirinto e uma matriz
* de numeros inteiros.
* Saida: Durante a execução modifica valores na matriz, onde o ponto anda,
* ela muda inicialmente para 3, e se achar um caminho sem saida,
* ela retorna por onde veio e muda o caminho para 4.
*
*
* Valor de retorno: Esta função retorna void.
*
****/

int VerificacaoInicial( tPontoLabirinto * , int [ ][ 12 ] );
/****
*
* Título: VerificacaoInicial
*
* Autor: Gabriel Rodrigues dos Santos
*
* Data de Criação: 19/08/2015
* Última modificação: 20/08/2015
*
* Descrição: A função verifica se as coordenadas informas pelo usuario são validas,
* se não é maior que o tamanho da matriz e se não deixou o ponto inicial em cima
* de uma obstrução.
*
* Parâmetros:
* Entrada: Um ponteiro do tipo tPontoLabirinto e uma matriz de numeros inteiros.
* Saida: Nenhuma saida visivel pela interface do usuario.
*
*
* Valor de retorno: Função retorna falso ou verdade.
*
****/

void ImprimeMatriz( int [][ 12 ] );
/****
*
* Título: ImprimeMatriz
*
* Autor: Gabriel Rodrigues dos Santos
*
* Data de Criação: 19/08/2015
* Última modificação: 19/08/2015
*
* Descrição: Imprime na tela uma matriz qualquer de numeros inteiros;
*
* Parâmetros:
* Entrada: Uma matriz de numeros inteiros.
* Saida: Impressão da matriz na tela.
*
* Valor de retorno: Função retorna void.
*
****/

void LimpaTudo( tPontoLabirinto * );
/****
*
* Título: LimpaTudo
*
* Autor: Gabriel Rodrigues dos Santos
*
* Data de Criação: 19/08/2015
* Última modificação: 19/08/2015
*
* Descrição: Serve como destrutor, limpa da memoria as variaveis alocadas.
*
* Parâmetros:
* Entrada: Um ponteiro do tipo tPontoLabirinto.
* Saida: Limpa variavel da memoria.
*
* Valor de retorno: Função retorna void.
*
****/

void LimpaCaminho( int [ ][ 12 ] );
/****
*
* Título: LimpaCaminho
*
* Autor: Gabriel Rodrigues dos Santos
*
* Data de Criação: 20/08/2015
* Última modificação: 20/08/2015
*
* Descrição: Limpa lugares onde existe caminho sem saida, que estão sinalizados
* com 4. Lê a matriz do labrinto procurando por 4 e substitui por 1.
*
* Parâmetros:
* Entrada: Uma matriz de números inteiros.
* Saida: Elementos da matriz com valor 4 mudam para 1.
*
* Valor de retorno: Função retorna void.
*
****/

int criaInterface();
/****
*
* Título: criaInterface
*
* Autor: Gabriel Rodrigues dos Santos
*
* Data de Criação: 27/08/2015
* Última modificação: 28/08/2015
*
* Descrição: Cria o menu interativo com o usuario.
*
*
* Parâmetros: Não recebe nenhum argumento.
*
* Entrada: Não recebe nenhum argumento.
* Saida: Menu com opções para inicio de programa, Instrucoes e saida.
*
* Valor de retorno: Função retorna interação, 1 para inicio, 2 para sobre e 3 para sair.
*
****/

int semSaida = 0; //Variavel Global que armazena falso se o labirinto tiver saida, verdade se sem saida

int main( int argc , char const *argv[] )
{

    int validacao; //Armazena o retorno de verificação da posição inicial

    int opcao; //Armazena a opção selecionada do menu

    int matrizLabirinto[ 12 ][ 12 ] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                       1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1,
                                       0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1,
                                       1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1,
                                       1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0,
                                       1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1,
                                       1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
                                       1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
                                       1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1,
                                       1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1,
                                       1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1,
                                       1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    tPontoLabirinto *posicaoInicial; //Posição inicial informada pelo usuario x e y

    posicaoInicial = malloc( sizeof( tPontoLabirinto ) ); //Alocação do ponto na matriz
    if(posicaoInicial == NULL) //Verificação de memoria para a posicaoInicial
    {
        printf("Memoria insuficiente, programa sera fechado! ERROR\n");
        exit(-1);
    }

    printf( "Bem Vindo ao Busca Saida 3000!\nAutor:Gabriel Rodrigues dos Santos\n" );
    //Print de boas vindas

    do{ //Inicio da criação do menu
        opcao = criaInterface(); //Chamada da função de criação do menu

        switch ( opcao ) { //Seleciona as opções do menu
            case 1: //Caso "Carregar arquivo de labirinto e achar saida"
                system( "cls || clear" ); //Limpa tela no Linux/Windows

                //Atribuição de valores ao ponto
                posicaoInicial->x = 2;
                posicaoInicial->y = 6;
                ////////////////////////

                //validação da localização inicial
                validacao = VerificacaoInicial( posicaoInicial , matrizLabirinto );

                if ( validacao == 1 ) //Se localização for verdade chama as funções de funcionamento
                {
                    ChecagemETroca( posicaoInicial , matrizLabirinto ); //Chamada da função com a matriz informada e a localização

                    if( semSaida == 1 ) //Caso não haja saida do labirinto
                        printf( "Labirinto Sem Saida!\n" );

                        matrizLabirinto[ posicaoInicial->x ][ posicaoInicial->y ] = 3; //Coloca ultimo passo dado para sair do labirinto

                        LimpaCaminho( matrizLabirinto ); //Chama função de limpar caminho sem saida

                        ImprimeMatriz( matrizLabirinto ); //Chama função de impressão

                }

                else
                    printf( "Iniciou no labirinto em cima de uma obstrucao!\n" );
                /*Fim do if validação*/
                break; //Fim do caso 1

            case 2: //Caso "Sobre e Instrucoes"
                system( "cls || clear" ); //Limpa tela no Linux/Windows
                printf( "O Busca Saida 3000 tem como objetivo achar a saida de qualquer labirinto quadrado," );
                printf( "basta entrar com o labirinto e ele mostrara por onde sair.\nVoce vai precisar criar um arquivo de texto chamado 'Labirinto' com as seguintes " );
                printf( "informações:\nNa primeira linha informe a dimensao do labirinto quadrado.\nNa segunda linha informe a posicao x e y inicial " );
                printf( "no labirinto.\nNa terceira linha em diante informe os elementos booleanos do labirinto.\nMas lembre-se, " );
                printf( "0 significa caminho obstruido e 1 caminho livre.\nEm seguida coloque o 'Labirinto.txt' na pasta raiz do programa.\n" );
                printf( "Após o funcionamento do programa sera criado um arquivo 'SaidaLabirinto.txt' mostrando a saida do labrinto.\nDivirta-se\n\n" );
                printf( "\n\nAutor: Gabriel Rodrigues dos Santos.\nData de Criacao: 18/08/2015.\n" );
                printf( "Programa totalmente desenvolvido no editor de textos Atom para Ubuntu Linux.\nVersao: 1.0 Beta\n\n" );
                //Algumas informações sobre como usar o programa e sobre o programa.
                break; //Fim do caso 2

            case 3: //Caso "Sair"
                system( "cls || clear" ); //Limpa tela no Linux/Windows
                exit( -1 );//Sai do programa

            default: //Caso usuario não digite uma opção valida
                system( "cls || clear" ); //Limpa tela no Linux/Windows
                printf( "Digite uma opcao valida!\n" );

            } //Fim do Switch case opcao
    }while( opcao != 3 ); //Fim do Do While opcao

    return 0;

} /*Fim da função main*/

int criaInterface()
{
    int menu;
    printf( "Menu Principal:\n(1) Carregar Arquivo de Labirinto e achar saida.\n(2) Sobre e Instrucoes.\n(3) Sair.\n" );
    printf( "Informe a opcao desejada, 1, 2 ou 3.: " );
    scanf( "%d" , &menu );
    return menu;
}

void LimpaCaminho ( int matriz[ ][ 12 ] )
{
    int i;
    int j;
    for ( i = 0 ; i < 12 ; i++ )
    {
        for ( j = 0 ; j < 12 ; j++ )
            if ( matriz[ i ][ j ] == 4 )
                matriz[ i ][ j ] = 1; //Normaliza os caminhos sem saida
        //Fim do for j
    } //Fim do for i
}

void LimpaTudo( tPontoLabirinto *ponto )
{
    free( ponto ); //Liberando memoria
}

int VerificacaoInicial( tPontoLabirinto *posicaoInicial , int matrizLabirinto[ 12 ][ 12 ] )
{ //Verifica se a posição inicial do labirinto é em cima de uma passagem obstruida e se está fora do tamanho da matriz
    if ( ( matrizLabirinto[ posicaoInicial->x ][ posicaoInicial->y ] == 1 ) && ( posicaoInicial->x > 12 ) && ( posicaoInicial->y > 12 ) )
        return 0; //Se sim, retorna falso
    return 1; //Se não, retorna verdade
}

void ImprimeMatriz( int matriz[ 12 ][ 12 ])
{
    int i;
    int j;
    //Impressão do labirinto resolvido na tela
    for( i = 0 ; i < 12 ; i++ )
    {
        for( j = 0 ; j < 12 ; j++ )
            printf( "%d  " , matriz[ i ][ j ] );
        //Fim do for j
        printf( "\n" );
    }//Fim do for i
}


void ChecagemETroca( tPontoLabirinto *localAtual , int matriz[ 12 ][ 12 ] )
{
    //Se não chegou nas extremidades da matriz ou se não é um labirinto sem saida executa
    if ( ( localAtual->x < 11 ) && ( localAtual->y < 11 ) && ( localAtual->x > 0 ) && ( localAtual->y > 0 ) && ( semSaida == 0 ) )
    {
        if ( matriz[ localAtual->x ][ localAtual->y + 1 ] == 1 ) //Verifica se passagem a direita está livre
        {
            matriz[ localAtual->x ][ localAtual->y ] = 3; //Coloca lugar por onde passou como 3
            localAtual->y++; //Anda para onde achou passagem livre
            ChecagemETroca( localAtual , matriz ); //Chamada Recursiva
        }

        else if ( matriz[ localAtual->x - 1 ][ localAtual->y ] == 1 ) //Verifica se passagem abaixo está livre
        {
            matriz[ localAtual->x ][ localAtual->y ] = 3; //Coloca lugar por onde passou como 3
            localAtual->x--; //Anda para onde achou passagem livre
            ChecagemETroca( localAtual , matriz ); //Chamada Recursiva
        }

        else if( matriz[ localAtual->x ][ localAtual->y - 1 ] == 1 ) //Verifica se passagema esquerda está livre
        {
            matriz[ localAtual->x ][ localAtual->y ] = 3; //Coloca lugar por onde passou como 3
            localAtual->y--; //Anda para onde achou passagem livre
            ChecagemETroca( localAtual , matriz ); //Chamada Recursiva
        }

        else if( matriz[ localAtual->x + 1 ][ localAtual->y ] == 1 ) //Verifica se passagem acima está livre
        {
            matriz[ localAtual->x ][ localAtual->y ] = 3; //Coloca lugar por onde passou como 3
            localAtual->x++; //Anda para onde achou passagem livre
            ChecagemETroca( localAtual , matriz ); //Chamada Recursiva
        }

        else  //Se não tiver nenhuma passagem livre, vai procurar por onde passou pra voltar e muda onde nao tem saida para 4
        {
            if ( matriz[ localAtual->x ][ localAtual->y +  1 ] == 3 ) //Verifica se passou antes pela direita
            {
                matriz[ localAtual->x ][ localAtual->y ] = 4; //Coloca aviso de passagem sem saida
                localAtual->y++; //Volta para posição anterior
                ChecagemETroca( localAtual , matriz ); //Chamada Recursiva
            }

            else if ( matriz[ localAtual->x - 1 ][ localAtual->y ] == 3 ) //Verifica se passou antes por baixo
            {
                matriz[ localAtual->x ][ localAtual->y ] = 4; //Coloca aviso de passagem sem saida
                localAtual->x--; //Volta para posição anterior
                ChecagemETroca( localAtual , matriz ); //Chamada Recursiva
            }

            else if ( matriz[ localAtual->x ][ localAtual->y - 1 ] == 3 ) //Verifica se passou antes pela esquerda
            {
                matriz[ localAtual->x ][ localAtual->y ] = 4; //Coloca aviso de passagem sem saida
                localAtual->y--; //Volta para posição anterior
                ChecagemETroca( localAtual , matriz ); //Chamada Recursiva
            }

            else if ( matriz[ localAtual->x + 1 ][ localAtual->y ] == 3 ) //Verifica se passou antes por cima
            {
                matriz[ localAtual->x ][ localAtual->y ] = 4; //Coloca aviso de passagem sem saida
                localAtual->x++; //Volta para posição anterior
                ChecagemETroca( localAtual , matriz ); //Chamada Recursiva
            }

            else //Se não achar mais nenhuma passagem obstruida nem passagem livre então não tem saida
            {
                semSaida = 1;
                return;
            } //Fim do if matriz[][] == 3

        }//Fim do if matriz[][] == 1
    }

    else //Se já chegou no final ou não tem saida termina programa
        return;
    //Fim do if extremidades ou semSaida
}
