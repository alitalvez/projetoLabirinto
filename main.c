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

int semSaida = 0;

void checagemEtroca(tpontoLabirinto *, int [][12]);

void verificacaoInicial(tpontoLabirinto *, int [][12]);

void imprimeMatriz(int [][12]);

int main()
{
    int i, j;
    int matrizLabirinto[12][12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                   1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1,
                                   0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1,
                                   1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1,
                                   1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0,
                                   1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1,
                                   1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
                                   1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
                                   1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1,
                                   1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1,
                                   1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1,
                                   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    tpontoLabirinto *posicaoInicial;

    posicaoInicial = malloc(sizeof(tpontoLabirinto));

    posicaoInicial->x = 2;
    posicaoInicial->y = 6;

    imprimeMatriz(matrizLabirinto);

    checagemEtroca(posicaoInicial, matrizLabirinto);


    if(semSaida == 1)
        printf("Labirinto Sem Saida!\n");

    matrizLabirinto[posicaoInicial->x][posicaoInicial->y] = 3;

    printf("\n\n\n\n");

    imprimeMatriz(matrizLabirinto);

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
    if ((localAtual->x < 11) && (localAtual->y < 11) && (localAtual->x > 0) && (localAtual->y > 0) && (semSaida == 0)) //Se não chegou na ponta da matriz ou não tem saida
    {
        if (matriz[localAtual->x][localAtual->y + 1] == 1)
        {
            matriz[localAtual->x][localAtual->y] = 3;
            localAtual->y++; //Anda
            checagemEtroca(localAtual, matriz); //Chamada Recursiva
        }

        else if (matriz[localAtual->x - 1][localAtual->y] == 1)
        {
            matriz[localAtual->x][localAtual->y] = 3;
            localAtual->x--;
            checagemEtroca(localAtual, matriz);
        }

        else if(matriz[localAtual->x][localAtual->y - 1] == 1)
        {
            matriz[localAtual->x][localAtual->y] = 3;
            localAtual->y--;
            checagemEtroca(localAtual, matriz);
        }

        else if(matriz[localAtual->x + 1][localAtual->y] == 1)
        {
            matriz[localAtual->x][localAtual->y] = 3;
            localAtual->x++;
            checagemEtroca(localAtual, matriz);
        }

        else  //Se não tiver nenhum 1, vai procurar por 3 pra voltar e mudar onde nao tem saida para 4
        {
            if (matriz[localAtual->x][localAtual->y +  1] == 3)
            {
                matriz[localAtual->x][localAtual->y] = 4;
                localAtual->y++;
                printf("x: %d y %d  1\n", localAtual->x, localAtual->y);
                checagemEtroca(localAtual, matriz);
            }

            else if (matriz[localAtual->x - 1][localAtual->y] == 3)
            {
                matriz[localAtual->x][localAtual->y] = 4;
                localAtual->x--;
                printf("x: %d y %d  2\n", localAtual->x, localAtual->y);
                checagemEtroca(localAtual, matriz);
            }

            else if (matriz[localAtual->x][localAtual->y - 1] == 3)
            {
                matriz[localAtual->x][localAtual->y] = 4;
                localAtual->y--;
                printf("x: %d y %d  3\n", localAtual->x, localAtual->y);
                checagemEtroca(localAtual, matriz);
            }

            else if (matriz[localAtual->x + 1][localAtual->y] == 3)
            {
                matriz[localAtual->x][localAtual->y] = 4;
                localAtual->x++;
                printf("x: %d y %d  4\n", localAtual->x, localAtual->y);
                checagemEtroca(localAtual, matriz);
            }

            else //Se não achar mais nenhum lugar com 3 nem 1, não tem saida
            {
                semSaida = 1;
                return;
            }
        }
    }

    else
        return;
}
