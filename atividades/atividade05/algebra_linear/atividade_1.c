// Multiplicação de Matrizes //
// Lanay Guimarães de Paiva - 2512130054 //

#include <stdio.h>

void ler_matriz(int N, int matriz[N][N], const char *nome)
{
    printf("Digite os elementos da matriz %s (%d%d). \n", nome, N, N);
    printf("\n");
    printf("Os valores podem ser positivos, negativos ou zero. \n");
    printf("\n");
    // * leitura dos valores da matriz * //
    for (int i = 0; i < N; i++)
    { 
        for (int j = 0; j < N; j++)
        {
            printf("Elemento [%d][%d]: ", i + 1, j + 1);
            printf("\n");
            scanf("%d", &matriz[i][j]);
        }
    }
}

void multiplicar_matrizes(int N, int matrizA[N][N], int matrizB[N][N], int matrizC[N][N]) {
    // * percorre as linhas da matriz A * //
    for (int i = 0; i < N; i++)
    {
        // * percorre as colunas da matriz B * //
        for (int j = 0; j < N; j++)
        {
            matrizC[i][j] = 0;
            // * k percorre as colunas da matriz A e as Linhas da matriz B * //
            for (int k = 0; k < N; k++)
            {
               
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
}

void imprimir_matriz(int N, int matriz[N][N], const char* nome) {

    printf("%s:\n", nome);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }
}


int main() {
    int N;
    printf(" * Multiplicacao de Matrizes * \n");
    printf("\n");
    printf("Digite o tamnaho N da matriz (2, 3, 4): ");
    printf("\n");

    if (scanf("%d", &N) != 1 || (N < 2 || N > 4)) {
        printf("Entrada invalida. Por favor, insira um numero inteiro entre 2 e 4.\n");
        printf("\n");
        return 1;
    }

    // * Declaracao das matrizes escolhidas pelo usuario * //
    int matrizA[N][N];
    int matrizB[N][N];
    int matrizC[N][N];

    // * leitura dos valores das matrizes * //
    ler_matriz(N, matrizA, "A");
    ler_matriz(N, matrizB, "B");

    // * calculo da multiplicacao * //
    multiplicar_matrizes(N, matrizA, matrizB, matrizC);

    // * Impressao das matrizes * //
    printf("\n ==============================\n"); 
    printf("Resultado da multiplicacao das matrizes:\n");


    imprimir_matriz(N, matrizA, "Matriz A");
    printf("\n");
    imprimir_matriz(N, matrizB, "Matriz B");
    printf("\n");
    imprimir_matriz(N, matrizC, "Matriz C (Resultado A x B )");

    return 0;
}
