/****
*
* Título: Labirinto Beta
*
* Autor: Gabriel Rodrigues dos Santos
*
* Data de Criação: 18/08/2015
* Última modificação: 19/08/2015
*
* Descrição: O programa tem como objetivo achar a saida de um labirinto qualquer
* usando condicionais, if e else, e uma unica função recursiva, a função checagemEtroca.
* O programa recebe o labirinto e a localização e informa como sair do mesmo.
* O labirinto é composto de elementos booleanos inicialmente, onde "0"(falso) representa uma
* obstrução e "1"(verdade) representa uma passagem livre. Após o programa achar a saida do labirinto,
* ele diz por onde deve-se ir para sair, através de um caminho de algarismos "3".
*
* Entrada: Espera-se que o usuario entre com um arquivo "*.txt", onde na primeira
* linha é informado a posição inicial no labirinto com coordenadas, x e y, na segunda
* linha é informado a dimensão do labirinto quadrado e na terceira linha em diante
* é informado a matriz do labirinto com os elementos booleanos do labirinto.
*
* Saída: O programa processa as informações do usuario e gera uma matriz mostrando
* o caminho de saida. Onde os algarismos "3" na matriz, representa por onde o usuario
* deve passar para sair do labirinto e quando não há nenhuma saida, o programa
* exibe a mensagem "Labirinto Sem Saida!".
*
****/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
        int x;
        int y;
}tpontoLabirinto;


void checagemEtroca(tpontoLabirinto *, int [][12]);

int verificacaoInicial(tpontoLabirinto *, int [][12]);

void imprimeMatriz(int [][12]);

void limpaTudo(tpontoLabirinto *);

int semSaida = 0;

int main()
{
    int validacao;

    int matrizLabirinto[12][12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
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

    tpontoLabirinto *posicaoInicial;

    posicaoInicial = malloc(sizeof(tpontoLabirinto));

    posicaoInicial->x = 4;
    posicaoInicial->y = 6;

    validacao = verificacaoInicial(posicaoInicial, matrizLabirinto);

    if (validacao == 1)
    {
        imprimeMatriz(matrizLabirinto);

        checagemEtroca(posicaoInicial, matrizLabirinto);


        if(semSaida == 1)
            printf("Labirinto Sem Saida!\n");

            matrizLabirinto[posicaoInicial->x][posicaoInicial->y] = 3;

            printf("\n\n\n\n");

            imprimeMatriz(matrizLabirinto);

    }

    else
        printf("Iniciou no labirinto em cima de uma obstrucao!\n");
    return 0;
}

void limpaTudo(tpontoLabirinto *ponto)
{
    free(ponto);
}

int verificacaoInicial(tpontoLabirinto *posicaoInicial, int matrizLabirinto[12][12])
{
    if (matrizLabirinto[posicaoInicial->x][posicaoInicial->y] == 0)
        return 0;
}

void imprimeMatriz(int matriz[12][12])
{
    int i, j;
    for(i = 0; i < 12; i++)
    {
        for(j = 0; j < 12; j++)
            printf("%d  ", matriz[i][j]);
        printf("\n");
    }
}


void checagemEtroca(tpontoLabirinto *localAtual, int matriz[12][12])
{
    //Se não chegou nas extremidades da matriz ou se não é um labirinto sem saida executa
    if ((localAtual->x < 11) && (localAtual->y < 11) && (localAtual->x > 0) && (localAtual->y > 0) && (semSaida == 0))
    {
        if (matriz[localAtual->x][localAtual->y + 1] == 1) //Verifica se passagem a direita está livre
        {
            matriz[localAtual->x][localAtual->y] = 3; //Coloca lugar por onde passou como 3
            localAtual->y++; //Anda para onde achou passagem livre
            checagemEtroca(localAtual, matriz); //Chamada Recursiva
        }

        else if (matriz[localAtual->x - 1][localAtual->y] == 1) //Verifica se passagem abaixo está livre
        {
            matriz[localAtual->x][localAtual->y] = 3; //Coloca lugar por onde passou como 3
            localAtual->x--; //Anda para onde achou passagem livre
            checagemEtroca(localAtual, matriz); //Chamada Recursiva
        }

        else if(matriz[localAtual->x][localAtual->y - 1] == 1) //Verifica se passagema esquerda está livre
        {
            matriz[localAtual->x][localAtual->y] = 3; //Coloca lugar por onde passou como 3
            localAtual->y--; //Anda para onde achou passagem livre
            checagemEtroca(localAtual, matriz); //Chamada Recursiva
        }

        else if(matriz[localAtual->x + 1][localAtual->y] == 1) //Verifica se passagem acima está livre
        {
            matriz[localAtual->x][localAtual->y] = 3; //Coloca lugar por onde passou como 3
            localAtual->x++; //Anda para onde achou passagem livre
            checagemEtroca(localAtual, matriz); //Chamada Recursiva
        }

        else  //Se não tiver nenhuma passagem livre, vai procurar por onde passou pra voltar e muda onde nao tem saida para 4
        {
            if (matriz[localAtual->x][localAtual->y +  1] == 3) //Verifica se passou antes pela direita
            {
                matriz[localAtual->x][localAtual->y] = 4; //Coloca aviso de passagem sem saida
                localAtual->y++; //Volta para posição anterior
                checagemEtroca(localAtual, matriz); //Chamada Recursiva
            }

            else if (matriz[localAtual->x - 1][localAtual->y] == 3) //Verifica se passou antes por baixo
            {
                matriz[localAtual->x][localAtual->y] = 4; //Coloca aviso de passagem sem saida
                localAtual->x--; //Volta para posição anterior
                checagemEtroca(localAtual, matriz); //Chamada Recursiva
            }

            else if (matriz[localAtual->x][localAtual->y - 1] == 3) //Verifica se passou antes pela esquerda
            {
                matriz[localAtual->x][localAtual->y] = 4; //Coloca aviso de passagem sem saida
                localAtual->y--; //Volta para posição anterior
                checagemEtroca(localAtual, matriz); //Chamada Recursiva
            }

            else if (matriz[localAtual->x + 1][localAtual->y] == 3) //Verifica se passou antes por cima
            {
                matriz[localAtual->x][localAtual->y] = 4; //Coloca aviso de passagem sem saida
                localAtual->x++; //Volta para posição anterior
                checagemEtroca(localAtual, matriz); //Chamada Recursiva
            }

            else //Se não achar mais nenhuma passagem obstruida nem passagem livre então não tem saida
            {
                semSaida = 1;
                return;
            } //Fim do If.......

        }//Fim do If.....
    }

    else //Se já chegou no final ou não tem saida termina programa
        return;
    //Fim do IF.....
}
