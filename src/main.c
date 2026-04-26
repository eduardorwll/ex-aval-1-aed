#include <stdio.h>
#include <stdlib.h>

int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {
    int totalLinhas = matSize;
    int totalColunas = matColSize[0];
    int *result = (int *)malloc(sizeof(int) * totalLinhas * totalColunas);
    *returnSize = totalLinhas * totalColunas;

    int linhaAtual = 0;
    int colunaAtual = 0;
    int direcao = 1; // 1 = cima-direita 0 = baixo-esquerda

    for (int i = 0; i < totalLinhas * totalColunas; i++) {
        result[i] = mat[linhaAtual][colunaAtual];
        
        if (direcao == 1) {
            if (colunaAtual == totalColunas - 1) {
                linhaAtual++;
                direcao = 0;
            } else if (linhaAtual == 0) {
                colunaAtual++;
                direcao = 0;
            } else {
                linhaAtual--;
                colunaAtual++;
            }
        } else {
            if (linhaAtual == totalLinhas - 1) {
                colunaAtual++;
                direcao = 1;
            } else if (colunaAtual == 0) {
                linhaAtual++;
                direcao = 1;
            } else {
                linhaAtual++;
                colunaAtual--;
            }
        }
    }

    return result;
}

int main() {
    int returnSize;
    int *result;
    int *colSize = (int *)malloc(sizeof(int));
    *colSize = 3;
    
    int **mat = (int**)malloc(3 * sizeof(int*));
    for (int i = 0; i < 3; i++) {
        mat[i] = (int*)malloc(3 * sizeof(int));
    }
    
    mat[0][0] = 1; mat[0][1] = 2; mat[0][2] = 3;
    mat[1][0] = 4; mat[1][1] = 5; mat[1][2] = 6;
    mat[2][0] = 7; mat[2][1] = 8; mat[2][2] = 9;

    result = findDiagonalOrder(mat, 3, colSize, &returnSize);
    
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    
    free(colSize);
    free(result);
    for (int i = 0; i < 3; i++) {
        free(mat[i]);
    }
    free(mat);
}