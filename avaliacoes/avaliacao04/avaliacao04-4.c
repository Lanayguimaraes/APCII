// Avaliacao 04 - Questao 04 //
// Lanay Guimaraes de Paiva - 2512130054 //

#include <stdio.h>

void multiplicacao_matrizes(int m, int n, int p, int A[m][n], int B[n][p], int C[m][p]) {
    // Inicializa C com zeros
    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++)
            C[i][j] = 0;

    // Multiplicação de matrizes
    for (int i = 0; i < m; i++) {       // linhas de A
        for (int j = 0; j < p; j++) {   // colunas de B
            for (int k = 0; k < n; k++) { // elementos correspondentes
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[2][2] = {{1,2},{3,4}};
    int B[2][2] = {{5,6},{7,8}};
    int C[2][2];

    multiplicacao_matrizes(2,2,2,A,B,C);

    // Exibe C
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
