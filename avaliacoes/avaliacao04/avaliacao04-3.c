// Avaliacao 04 - Questao 03 //
// Lanay Guimaraes de Paiva - 2512130054 //



#include <stdio.h>

void transposta(int m, int n, int A[m][n], int T[n][m]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            T[j][i] = A[i][j]; // troca linha por coluna
        }
    }
}

int main() {
    int A[2][3] = {
        {9, 5, -6},
        {0, -2, 1}
    };
    int T[3][2]; // transposta de A (3x2)

    transposta(2, 3, A, T);

    printf("Matriz Transposta:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%3d ", T[i][j]);
        }
        printf("\n");
    }

    return 0;
}
