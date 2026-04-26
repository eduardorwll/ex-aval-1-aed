// Esse foi o mais longe que conseguir ir em sala de aula sem consulta
// Resultado do leetcode: 
// Wrong Answer
// 2 / 33 testcases passed

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {
    int totalLinhas = matSize;
    int totalColunas = matColSize[0];
    int *result = (int *)malloc(sizeof(int) * totalLinhas * totalColunas);
    *returnSize = totalLinhas * totalColunas;

    int linhaAtual = 0;
    int colunaAtual = 0;

    int direcao; // 0 = direita 1 = esquerda

    for (int i = 0; i < totalLinhas * totalColunas; i++) {
        result[i] = mat[linhaAtual][colunaAtual];
        
        if(linhaAtual == 0 && colunaAtual == 0){
            colunaAtual++;
            direcao = 1;
        }else{
            if (direcao == 0) {
                if (colunaAtual == totalColunas - 1) {
                    linhaAtual++;
                } else if (linhaAtual == 0) {
                    colunaAtual++;
                } else { 
                    linhaAtual--;
                    colunaAtual++; 
                    direcao = 1;
                }
            } else {
                if (linhaAtual == totalLinhas - 1) {
                    colunaAtual++;
                } else if (colunaAtual == 0) {
                    linhaAtual++;
                } else { 
                    linhaAtual++; 
                    colunaAtual--;
                    direcao = 0; 
                }
            }
        }
    }

    return result;
}
