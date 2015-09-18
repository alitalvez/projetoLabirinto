/****
*
* Título: Busca Saida 3000
*
* Autor: Gabriel Rodrigues dos Santos
*
* Data de Criação: 18/08/2015
* Última modificação: 27/09/2015
*
* Descrição: O programa tem como objetivo achar a saida de um labirinto qualquer
* usando condicionais, if e else, e uma unica função recursiva, a função ChecagemETroca.
* O programa recebe o labirinto e a localização e informa como sair do mesmo.
* O labirinto é composto de elementos booleanos inicialmente, onde "0"(falso) representa uma
* obstrução e "1"(verdade) representa uma passagem livre. Após o programa achar a saida do labirinto,
* ele diz por onde deve-se ir para sair, através de um caminho de algarismos "3".
*
* Entrada: Espera-se que o usuario entre com um arquivo "Labirinto.txt", onde na primeira
* linha é informado  a posicao inicial no labirinto com coordenadas, x e y,
* na segunda linha a dimensao do labirinto quadrado e na terceira linha em diante
* é informado a matriz do labirinto com os elementos booleanos do labirinto.
*
* Exemplo: Usuario cria um arquivo chamado Labirinto.txt e nele informa
*   Labirinto.txt
*  __________
*  | 4 4    |
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


void ChecagemETroca( tPontoLabirinto * , int * , const int* );
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
* e ir pelo outro caminho, assim ocorre em qualquer bifurcação e com qualquer quantidade
* de bifurcações, pois o algoritimo procura por locais por onde já passou, '3', e vai modificando
* para '4' até encontrar novamente '1', chegando assim ao ponto inicial da bifurcação.
*
* Parâmetros:
* Entrada: Um ponteiro para o tipo tPontoLabirinto, um ponteiro para uma matriz vetor
* de numeros inteiros e um ponteiro para inteiros que aponta a dimensao da matriz.
*
* Saida: Durante a execução modifica valores na matriz, onde o ponto anda,
* ela muda inicialmente para 3, e se achar um caminho sem saida,
* ela retorna por onde veio e muda o caminho para 4.
*
*
* Valor de retorno: Esta função retorna void.
*
****/

int VerificacaoInicial( tPontoLabirinto * , int * , const int* );
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
* Entrada: Um ponteiro do tipo tPontoLabirinto e um ponteiro para matriz vetor de numeros inteiros
* e um ponteiro para inteiros que aponta a dimensao da matriz.
*
* Saida: Nenhuma saida visivel pela interface do usuario.
*
*
* Valor de retorno: Função retorna falso ou verdade.
*
****/

void ImprimeMatriz( int * , const int* , FILE * );
/****
*
* Título: ImprimeMatriz
*
* Autor: Gabriel Rodrigues dos Santos
*
* Data de Criação: 19/08/2015
* Última modificação: 19/08/2015
*
* Descrição: Imprime em um arquivo a saida do labirinto.
*
* Parâmetros:
* Entrada: Um ponteiro para uma matriz vetor de numeros inteiros e um ponteiro
* para inteiros que aponta a dimensao da matriz e um ponteiro para o arquivo.
*
* Saida: Impressão da matriz na tela.
*
* Valor de retorno: Função retorna void.
*
****/

void LimpaTudo( tPontoLabirinto * , int * , FILE * , FILE * );
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
* Entrada: Um ponteiro do tipo tPontoLabirinto e um ponteiro para uma matriz vetor de inteiros.
* Saida: Limpa variavel da memoria.
*
* Valor de retorno: Função retorna void.
*
****/

void LimpaCaminho( int * , const int* );
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
* Entrada: Um ponteiro para matriz vetor de números inteiros e um ponteiro para
* inteiros que aponta a dimensao da matriz.
*
* Saida: Elementos da matriz com valor 4 mudam para 1.
*
* Valor de retorno: Função retorna void.
*
****/

int CriaInterface( int );
/****
*
* Título: CriaInterface
*
* Autor: Gabriel Rodrigues dos Santos
*
* Data de Criação: 27/08/2015
* Última modificação: 28/08/2015
*
* Descrição: Cria o menu interativo com o usuario.
*
*
* Parâmetros: Recebe um inteiro para saber qual parte do menu criar.
*
* Entrada: Não recebe nenhum argumento.
* Saida: Menu com opções para inicio de programa, Instrucoes e saida.
*
* Valor de retorno: Função retorna interação, 1 para inicio, 2 para sobre e 3 para sair.
*
****/

void LeMatriz ( FILE * , int * , const int * );
/****
*
* Título: LeMatriz
*
* Autor: Gabriel Rodrigues dos Santos
*
* Data de Criação: 04/09/2015
* Última modificação: 14/09/2015
*
* Descrição: Faz a leitura dos valores da matriz booleana indicados pelo usuario.
*
* Parâmetros:
*
* Entrada: Um ponteiro para o arquivo de entrada, um ponteiro para a matriz vetor e
* um ponteiro para a dimensao da matriz vetor.
*
* Saida:
*
*
* Valor de retorno: [descrição do valor retornado pela função]
*
****/


int * AlocaMatriz ( const int * );
/****
*
* Título: AlocaMatriz
*
* Autor: Gabriel Rodrigues dos Santos
*
* Data de Criação: 04/09/2015
* Última modificação: 14/09/2015
*
* Descrição: Aloca uma matriz vetor de numeros inteiros
*
* Parâmetros:
* Entrada: Um inteiro que representa a ordem da matriz a ser alocada.
*
* Saida: Uma matriz vetor de inteiros
*
* Valor de retorno: Função retorna o ponteiro para uma matriz vetor de inteiros
*
****/


tPontoLabirinto * AlocaPonto ( );
/****
*
* Título: AlocaPonto
*
* Autor: Gabriel Rodrigues dos Santos
*
* Data de Criação: 04/09/2015
* Última modificação: 14/09/2015
*
* Descrição: Aloca uma struct do tipo tPontoLabirinto.
*
* Parâmetros:
* Entrada: Void
*
* Saida: Uma struct do tipo tPontoLabirinto
*
* Valor de retorno: Função retorna um ponteiro para uma struct do tipo tPontoLabirinto
*
****/



int semSaida = 0; //Variavel Global que armazena falso se o labirinto tiver saida, verdade se sem saida

int main( int argc , char const *argv[] )
{

    int validacao; //Armazena o retorno de verificação da posição inicial

    int opcao; //Armazena a opção selecionada do menu

    int dimensao; //Armazena a dimensao do labirinto

    int *matrizLabirinto; //Matriz em forma de vetor para armazenar o labirinto

    FILE *entrada; //Ponteiro para leitura do labirinto
    FILE *saida; //Ponteiro para criação do arquivo de saida do labirinto

    tPontoLabirinto *posicaoInicial; //Posição inicial informada pelo usuario x e y

    system( "cls || clear" ); //Limpa tela no Linux/Windows
    printf( "Bem Vindo ao Busca Saida 3000!\nAutor:Gabriel Rodrigues dos Santos\n\n" );
    //Print de boas vindas

    do{ //Inicio da criação do menu

        opcao = CriaInterface( 0 ); //Chamada da função de criação do menu

        switch ( opcao ) { //Seleciona as opções do menu
            case 1: //Caso "Carregar arquivo de labirinto e achar saida"
                system( "cls || clear" ); //Limpa tela no Linux/Windows

                if ( ( entrada = fopen ( "Labirinto.txt" , "r" ) ) == NULL ) //Abertura do labirinto
                {
                    printf ( "Arquivo 'Labirinto.txt' nao foi encontrado ou nao pode ser aberto. Leia as Instrucoes\n" );
                    break;
                }//Fim do if entrada


                posicaoInicial = AlocaPonto ( ); //Aloca ponto

                //Atribuição de valores ao ponto
                fscanf ( entrada , "%d %d\n" , &( posicaoInicial->y ) , &( posicaoInicial->x ) ); //Leitura do ponto na primeira linha do arquivo

                posicaoInicial->x--; /* "Normaliza" os pontos para trabalhar na matriz corretamente */
                posicaoInicial->y--;

                fscanf( entrada , "%d\n" , &dimensao ); //Leitura da dimensao da matriz na segunda linha do arquivo

                matrizLabirinto = AlocaMatriz( &dimensao ); //Chamda para alocação da matriz

                LeMatriz( entrada , matrizLabirinto , &dimensao ); //Chamada de leitura da matriz

                //validação da localização inicial
                validacao = VerificacaoInicial( posicaoInicial , matrizLabirinto , &dimensao );

                if ( validacao == 1 ) //Se localização for verdade chama as funções de funcionamento
                {
                    ChecagemETroca( posicaoInicial , matrizLabirinto , &dimensao ); //Chamada da função de procura do labirinto

                    if ( semSaida == 1 ) //Caso não haja saida do labirinto
                    {
                        printf ( "Labirinto Sem Saida!\n\n" );
                        semSaida = 0;
                        break;
                    }//Fim do if semSaida

                    matrizLabirinto[ posicaoInicial->x * dimensao + posicaoInicial->y ] = 3; //Coloca ultimo passo dado para sair do labirinto

                    LimpaCaminho ( matrizLabirinto , &dimensao ); //Chama função de limpar caminho sem saida


                    if ( ( saida = fopen ( "SaidaLabirinto.txt" , "w" ) ) == NULL ) //Criação do arquivo de saida do labirinto
                    {
                        printf( "Arquivo 'SaidaLabirinto.txt' nao pode ser criado. Verifique se o usuario tem permissao para criar arquivos no local.\n\n" );
                        break;
                    }//Fim do if saida


                    ImprimeMatriz ( matrizLabirinto , &dimensao , saida ); //Chama função de impressão

                    LimpaTudo ( posicaoInicial , matrizLabirinto , entrada , saida ); //Chama funcao de limpeza

                    printf("Saida encontrada com sucesso, procure o arquivo 'SaidaLabirinto.txt' na pasta raiz do programa\n\n");


                }

                else
                    printf( "Iniciou no labirinto em cima de uma obstrucao ou posicao inicial no labirinto maior que a dimensao!\n\n" );
                /*Fim do if validação*/
                break; //Fim do caso 1

            case 2: //Caso "Sobre e Instrucoes"
                    opcao = CriaInterface( 1 ); //Chama funcao para escrever o sobre e já seta para o menu inicial
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


tPontoLabirinto * AlocaPonto ( )
{
    tPontoLabirinto *ponto;

    ponto = malloc( sizeof ( tPontoLabirinto ) ); //Alocação do ponto na matriz

    if( ponto == NULL ) //Verificação de memoria para a posicaoInicial
    {
        printf ( "Memoria insuficiente, programa sera fechado! ERROR\n" );
        exit ( -1 );
    }//Fim do if ponto == NULL

    return ponto;

}

int * AlocaMatriz ( const int *dimensao )
{
    int *matriz;

    matriz = malloc( ( *dimensao * *dimensao ) * sizeof ( int ) ); //Alocação da matriz em formato de vetor

    if( matriz == NULL ) //Verificação de memoria para a matrizLabirinto
    {
        printf ( "Memoria insuficiente, programa sera fechado! ERROR\n" );
        exit ( -1 );
    }//Fim do if matriz == NULL

    return matriz;
}

void LeMatriz(FILE *entrada , int *matriz , const int *dimensao )
{
    //Leitura da matriz
    int i, j;
    for(i = 0; i < *dimensao; i++)
    {
        for(j = 0; j < *dimensao; j++)
            fscanf(entrada , "%d", &matriz[i * *dimensao + j]);
            //Fim do for j
        fscanf(entrada , "\n");
    }//Fim do for i
}


int CriaInterface( int operacao )
{
    char interacao; //Recebe comando enviado pelo usuario

    /*A variavel operacao vai receber qual menu deve imprimir na tela*/

    switch ( operacao )
    {
        case 0:

            printf( "Menu Principal:\n(1) Carregar Arquivo de Labirinto e achar saida.\n(2) Sobre e Instrucoes.\n(3) Sair.\n" );
            printf( "Informe a opcao desejada, 1, 2 ou 3.: " );
            scanf( "%s" , &interacao );
            return atoi( &interacao ); //Converte a interacao para inteiro e retorna o valor dela
            break;
        //Fim do caso 0
        case 1:
            system( "cls || clear" ); //Limpa tela no Linux/Windows
            printf( "O Busca Saida 3000 tem como objetivo achar a saida de qualquer labirinto quadrado," );
            printf( " basta entrar com o labirinto e ele mostrara por onde sair.\nVoce vai precisar criar um arquivo de texto chamado 'Labirinto.txt' com as seguintes " );
            printf( "informações:\nNa primeira linha informe a posicao x e y inicial no labirinto.\nNa segunda linha informe a dimensao do labirinto quadrado." );
            printf( "\nNa terceira linha em diante informe os elementos booleanos do labirinto.\nMas lembre-se, " );
            printf( "0 significa caminho obstruido e 1 caminho livre.\nEm seguida coloque o 'Labirinto.txt' na pasta raiz do programa.\n" );
            printf( "Após o funcionamento do programa sera criado um arquivo 'SaidaLabirinto.txt' mostrando a saida do labrinto, indicada pelo numeral '3'.\n\n" );
            printf( "\n\nAutor: Gabriel Rodrigues dos Santos.\nData de Criacao: 18/08/2015.\n" );
            printf( "Programa totalmente desenvolvido no editor de textos Atom para Ubuntu Linux.\nVersao: 1.0 Beta\n\n" );
            //Algumas informações sobre como usar o programa e sobre o programa.
            return 0;
            break;
        //Fim do caso 1

        default:
            operacao = 0;
            break;
        //Fim do default
    }//Fim do switch op
}

void LimpaCaminho ( int *matriz , const int *dimensao )
{
    int i;
    int j;
    for ( i = 0 ; i < *dimensao ; i++ )
    {
        for ( j = 0 ; j < *dimensao ; j++ )
            if ( matriz [ i * *dimensao + j ] == 4 )
                matriz [ i * *dimensao + j ] = 1; //Normaliza os caminhos sem saida
        //Fim do for j
    } //Fim do for i
}

void LimpaTudo( tPontoLabirinto *ponto , int *matrizLabirinto , FILE *entrada , FILE *saida )
{
    free( ponto ); //Liberando memoria
    free ( matrizLabirinto );
    fclose ( entrada ); //Fechando arquivos
    fclose ( saida );
}

int VerificacaoInicial( tPontoLabirinto *posicaoInicial , int *matrizLabirinto , const int *dimensao )
{
    /////////Verificação de todos os elementos da matriz 0 ou 1
    int i, j;
    for ( i = 0 ; i < *dimensao ; i++ )
    {
        for ( j = 0 ; j < *dimensao ; j++ )
        {
            if ( ( matrizLabirinto[ i * *dimensao + j ] != 0 ) && ( matrizLabirinto[ i * *dimensao + j] != 1 ) )
                return 0;//Se achar algum numero diferente de 0 e 1 retorna falso
        }
    }
    if ( ( matrizLabirinto[ posicaoInicial->x * *dimensao + posicaoInicial->y ] == 0 ) ) //Se estiver em uma passagem obstruida
        return 0; //Se sim retorna falso
    else if ( ( ( posicaoInicial->x + 1 ) > *dimensao ) || ( ( posicaoInicial->y + 1 ) > *dimensao )  ) //Se estiver fora da matriz
        return 0; //Se sim, retorna falso
    else
        return 1; //Se não, retorna verdade
    //Fim do if matrizLabirinto
}

void ImprimeMatriz( int *matriz , const int *dimensao , FILE *saida )
{
    int i;
    int j;
    //Impressão do labirinto resolvido no arquivo
    for( i = 0 ; i < *dimensao ; i++ )
    {
        for( j = 0 ; j < *dimensao ; j++ )
            fprintf( saida , "%d  " , matriz[ i * *dimensao + j ] );
        //Fim do for j
        fprintf( saida , "\n" );
    }//Fim do for i
}


void ChecagemETroca( tPontoLabirinto *localAtual , int *matriz , const int *dimensao )
{
    //Se não chegou nas extremidades da matriz ou se não é um labirinto sem saida executa
    if ( ( localAtual->x < *dimensao - 1 ) && ( localAtual->y < *dimensao - 1 ) && ( localAtual->x > 0 ) && ( localAtual->y > 0 ) && ( semSaida == 0 ) )
    {
        if ( matriz[ localAtual->x * *dimensao + (localAtual->y + 1) ] == 1 ) //Verifica se passagem a direita está livre
        {
            matriz[ localAtual->x * *dimensao + localAtual->y ] = 3; //Coloca lugar por onde passou como 3
            localAtual->y++; //Anda para onde achou passagem livre
            ChecagemETroca( localAtual , matriz , dimensao); //Chamada Recursiva
        }

        else if ( matriz[ (localAtual->x - 1) * *dimensao + localAtual->y ] == 1 ) //Verifica se passagem abaixo está livre
        {
            matriz[ localAtual->x * *dimensao + localAtual->y ] = 3; //Coloca lugar por onde passou como 3
            localAtual->x--; //Anda para onde achou passagem livre
            ChecagemETroca( localAtual , matriz , dimensao); //Chamada Recursiva
        }

        else if( matriz[ localAtual->x * *dimensao + (localAtual->y - 1) ] == 1 ) //Verifica se passagema esquerda está livre
        {
            matriz[ localAtual->x * *dimensao + localAtual->y ] = 3; //Coloca lugar por onde passou como 3
            localAtual->y--; //Anda para onde achou passagem livre
            ChecagemETroca( localAtual , matriz , dimensao); //Chamada Recursiva
        }

        else if( matriz[ (localAtual->x + 1) * *dimensao + localAtual->y ] == 1 ) //Verifica se passagem acima está livre
        {
            matriz[ localAtual->x * *dimensao + localAtual->y ] = 3; //Coloca lugar por onde passou como 3
            localAtual->x++; //Anda para onde achou passagem livre
            ChecagemETroca( localAtual , matriz , dimensao); //Chamada Recursiva
        }

        else  //Se não tiver nenhuma passagem livre, vai procurar por onde passou pra voltar e muda onde nao tem saida para 4
        {
            if ( matriz[ localAtual->x * *dimensao + (localAtual->y +  1) ] == 3 ) //Verifica se passou antes pela direita
            {
                matriz[ localAtual->x * *dimensao + localAtual->y ] = 4; //Coloca aviso de passagem sem saida
                localAtual->y++; //Volta para posição anterior
                ChecagemETroca( localAtual , matriz , dimensao); //Chamada Recursiva
            }

            else if ( matriz[ (localAtual->x - 1) * *dimensao + localAtual->y ] == 3 ) //Verifica se passou antes por baixo
            {
                matriz[ localAtual->x * *dimensao + localAtual->y ] = 4; //Coloca aviso de passagem sem saida
                localAtual->x--; //Volta para posição anterior
                ChecagemETroca( localAtual , matriz , dimensao); //Chamada Recursiva
            }

            else if ( matriz[ localAtual->x * *dimensao + (localAtual->y - 1) ] == 3 ) //Verifica se passou antes pela esquerda
            {
                matriz[ localAtual->x * *dimensao + localAtual->y ] = 4; //Coloca aviso de passagem sem saida
                localAtual->y--; //Volta para posição anterior
                ChecagemETroca( localAtual , matriz , dimensao); //Chamada Recursiva
            }

            else if ( matriz[ (localAtual->x + 1) * *dimensao + localAtual->y ] == 3 ) //Verifica se passou antes por cima
            {
                matriz[ localAtual->x * *dimensao + localAtual->y ] = 4; //Coloca aviso de passagem sem saida
                localAtual->x++; //Volta para posição anterior
                ChecagemETroca( localAtual , matriz , dimensao); //Chamada Recursiva
            }

            else //Se não achar mais nenhuma passagem obstruida nem passagem livre então não tem saida
            {
                semSaida = 1;
                return;
            } //Fim do if matriz[i * *dimensao + j] == 3

        }//Fim do if matriz[i * *dimensao + j] == 1
    }

    else //Se já chegou no final ou não tem saida termina programa
        return;
    //Fim do if extremidades ou semSaida
}
