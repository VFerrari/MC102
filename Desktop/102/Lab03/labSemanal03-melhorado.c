/*
Programa: labSemanal03-Ric.c
Autor...: Ricardo Mendonça Ferreira - ric@mpcnet.com.br
Data....: 2016.04.25

Este programa recebe como entrada uma imagem coloria com compressão RLE,
e gera como saída uma versão em tons de cinza com um filtro aplicado
(convolução de matrizes).

*/

#include <stdio.h>
#include <stdlib.h>

// Variáveis globais - não podem ser locais devido ao tamanho (causariam estouro de pilha)
unsigned short rgb[3][600][600]; // entrada: matrizes com valores dos planos R, G e B (vermelho, verde e azul)
unsigned short cinza [600][600]; // matriz com valores da imagem de entrada convertidos para tons de cinza
unsigned short transformada[600][600]; // matriz com imagem transformada

int main (int argc, char *argv[]) {

    int divisor;            // entrada: inteiro "D", divisor da filtragem
    int ordem;              // entrada: inteiro "X", ímpar e < 10, ordem da matriz quadrada M
    int filtro[9][9];       // entrada: matriz quadrada M com X**2 números inteiros, em X linhas e X colunas.
    int resX, resY;         // entrada: resolução da imagem em pixels
    int plano;              // número do plano (R=0, G=1, B=2)
    unsigned short leDados; // lê dados enquanto var. == "true"
    int x, y;               // aponta para coluna e linha na matriz
    int qtd, val;           // entrada: valores RLE a descompactar

    // Entrada de dados
    scanf("%d", &divisor);
    scanf("%d", &ordem);

    for (y=0; y < ordem; y++)
        for(x=0; x < ordem; x++)
            scanf("%d", &filtro[y][x]);

	scanf("%d %d", &resX, &resY);

    // Entrada de dados RLE, representando 3 matrizes (dos planos R, G e B)
    plano = 0;
    x = 0;
    y = 0;
    leDados = 1;
    while(leDados) {
        scanf("%d %d", &qtd, &val);
        while(qtd) {
            rgb[plano][y][x] = val;
            x++;
            qtd--;
            if (x >= resX) {
                x = 0;
                y++;
            }
        }
        // Já lemos um plano inteiro? Vamos ao próximo
        if (y >= resY) {
            x = 0;
            y = 0;
            plano++;
        }
        // Já lemos todos os planos? Termine a leitura
        if (plano >= 3)
            leDados = 0;
        // printf("* %d %d %d\n", plano, x, y); // Apenas para debugging
    }

    // Converte matriz de entrada para tons de cinza
    for (y=0; y < resY; y++)
        for(x=0; x < resX; x++)
            cinza[y][x] = (rgb[0][y][x] + rgb[1][y][x] + rgb[2][y][x]) / 3;

    // Aplica filtro na imagem em tons de cinza
    
    // Saída em formato PGM
    puts("P2");
    printf("%d %d\n255\n", resX, resY);
    for (y=0; y < resY; y++) {
        for(x=0; x < resX; x++)
            printf("%d%s", cinza[y][x], x < resX - 1 ? " " : "");
        puts("");
    }
}

// 13:24 - 